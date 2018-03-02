// ====================================================================
//
// Copyright (C) 2010, Hewlett-Packard Development Company, L.P.
// All Rights Reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it would be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// Further, this software is distributed without any warranty that it
// is free of the rightful claim of any third person regarding
// infringement  or the like.  Any license provided herein, whether
// implied or otherwise, applies only to this software file.  Patent
// licenses, if any, provided herein do not apply to combinations of
// this program with other software, or any other product whatsoever.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
//
// ====================================================================
// Module: slp_schedule.cxx
//
// Description:
// After scalar statements are packed, a new schedule of packed or 
// individual statements is determined in Scheduler. At this scheduling,
// scalar statements that are placed in the same statement pack are 
// scheduled together as if they are a vector statement. 
// 'schedule_main()' calls 'schedule_all()' until all statements are
// scheduled. 'schedule_all()' goes through all statements that are not
// scheduled yet and try to schedule as many statements as it can. If
// none of the remaining statements can be scheduled, there is a 
// circular dependence and the first unscheduled statement pack is
// unpacked. This circular dependence may not happen in practice 
// because of the transitive closure property of the dependence matrix.
// 
// ====================================================================

#include "slp.h"

using namespace slp;

Scheduler::Scheduler(std::vector<Statement*>& s,
		     std::list<Statement_Pack*>& packs,
		     Dependence_Matrix& d) :
  packed_in(s.size()), scheduled(s.size()), num_stmts(s.size()), 
  stmts(s), stmt_packs(packs), deps(d)
{
  // which pack does a statement belong to?
  which_pack();
}





Scheduler::~Scheduler()
{
}




// --------------------------------------------------------------------
// high-level routines
// --------------------------------------------------------------------

// record the pack which a statement belongs in
void Scheduler::which_pack()
{
  std::list<Statement_Pack*>::iterator i = stmt_packs.begin();
  for (; i!= stmt_packs.end(); i++){
    Statement_Pack* spack = *i;
    for (int j=0; j<spack->size(); j++){
      Statement_ID id = spack->i_th(j);
      packed_in[id] = spack;
    }
  }
}








// schedule main
void Scheduler::schedule_main()
{
  Statement_ID first_unscheduled = 0;
  Statement_ID prev_first_unscheduled;
  while(true){
    prev_first_unscheduled = first_unscheduled;
   int num_scheduled = schedule_all(prev_first_unscheduled, first_unscheduled);
   // done if none remains to be scheduled
   if (first_unscheduled == -1) break; 

    // Try again if some statements are scheduled
    if (num_scheduled > 0) {
      continue;
    }

    // If none is scheduled but there are statements to be scheduled,
    // unpack the first pack that remains to be scheduled.
    if (first_unscheduled != -1){
      Is_True(is_packed(first_unscheduled), ("Scheduler::schedule: first unscheduled statement must be packed."));
      unpack(first_unscheduled);
      continue;
    }
  }
}








// schedule as much as possible
// - returns the number of newly scheduled statements
// - at return, 'first_unscheduled' contains -1 if none remains 
//   to be scheduled
int Scheduler::schedule_all(const Statement_ID prev_first_unscheduled, 
			    Statement_ID& first_unscheduled)
{
  first_unscheduled = -1;
  int num_scheduled=0;
  for (Statement_ID i=prev_first_unscheduled; i<num_stmts; i++){
    if (is_scheduled(i)) continue;
    if (first_unscheduled == -1) first_unscheduled = i;
    if (free_to_schedule(i)){
      schedule_stmt(i);
      num_scheduled++;
      if (first_unscheduled == i) first_unscheduled = -1;
    }
  }

  return num_scheduled;
}








// schedule a statement into a Statement_ID list
void Scheduler::schedule_stmt(Statement_ID i)
{
  // if 'i' is packed, it represents all in the same pack are scheduled
  scheduled_stmtIDs.push_back(i);
  scheduled[i] = true;
  if (!is_packed(i)) return;

  Statement_Pack* spack = packed_in[i];
  for (int j=0; j<spack->size(); j++){
    scheduled[spack->i_th(j)] = true;
  }
}








// remove the pack where the given statement belongs
void Scheduler::unpack(Statement_ID i)
{
  Statement_Pack* spack = packed_in[i];
  for (int j=0; j<spack->size(); j++){
    packed_in[spack->i_th(j)] = NULL;
  }
}







// --------------------------------------------------------------------
// low-level routines
// --------------------------------------------------------------------

// true if the given statement is packed
bool Scheduler::is_packed(Statement_ID i)
{
  if (packed_in[i] == NULL) return false;

  // A pack of one statement can be generated as a consequence of 
  // 'SLP_Main::chop_packs()'. We will just consider such packs as 
  // scalar statements. 

  // Also, we can enforce 'only full packs' here.
  Statement_Pack* pack = packed_in[i];
  if (pack->size() <= 1) return false;
  return true;
}



// Statement_Pack in which the given statement is packed
Statement_Pack* Scheduler::get_pack(Statement_ID i)
{
  return packed_in[i];
}



// true if 'i' is scheduled already
bool Scheduler::is_scheduled(Statement_ID i)
{
  return scheduled[i];
}



// true if all earlier instructions on which 'i' is dependent are scheduled
bool Scheduler::free_to_schedule(Statement_ID j)
{
  if (!is_packed(j)) {
    for (int i=0; i<j; i++)
      if (deps.is_dependent(i, j) && !is_scheduled(i)) 
	return false;
    return true;
  }

  Statement_Pack* spack = packed_in[j];
  for (int k=0; k<spack->size(); k++){
    Statement_ID id = spack->i_th(k);
    for (int i=0; i<id; i++)
      if (deps.is_dependent(i, id) && !is_scheduled(i)) 
	return false;
  }
  
  return true;
}







// --------------------------------------------------------------------
// public routines
// --------------------------------------------------------------------
std::list<Statement_ID>::iterator Scheduler::begin()
{ 
  return scheduled_stmtIDs.begin();
}




std::list<Statement_ID>::iterator Scheduler::end()
{ 
  return scheduled_stmtIDs.end();
}




void Scheduler::print()
{
  fprintf(TFile, "\n---------- Schedule ----------\n");
  std::list<Statement_ID>::iterator i = scheduled_stmtIDs.begin();
  for (; i != scheduled_stmtIDs.end(); i++){
    Statement_ID id = *i;
    if (is_packed(id)) {
      Statement_Pack* pack = packed_in[id];
      Is_True(pack != NULL, ("Scheduler::print: NULL Statement_Pack*"));
      pack->print();
    }
    else fprintf(TFile, "( %d )", id);
    fprintf(TFile, "\n");
  }
}









