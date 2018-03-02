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
//
// ====================================================================
//
// Module: slp_schedule.h
//
// Description:
//
// ====================================================================


#ifndef lwopt_slp_schedule_INCLUDED
#define lwopt_slp_schedule_INCLUDED





namespace slp {

  struct lt_stmt_pack
  {
    bool operator()(const Statement_Pack* p1, const Statement_Pack* p2) const
    {
      return *p1<*p2;
    }
  };

  class Scheduler
    {
    public:
      Scheduler(std::vector<Statement*>&,
		std::list<Statement_Pack*>&,
		Dependence_Matrix&);
      ~Scheduler();

      void schedule_main();

      std::list<Statement_ID>::iterator begin();
      std::list<Statement_ID>::iterator end();
      bool is_packed(Statement_ID);
      Statement_Pack* get_pack(Statement_ID);
      void print();

    private:

      int schedule_all(const Statement_ID, Statement_ID&);
      void which_pack();
      void schedule_stmt(Statement_ID);
      void unpack(Statement_ID);

      bool is_scheduled(Statement_ID);
      bool free_to_schedule(Statement_ID);

      // mapping from a statement to the Statement_pack it belongs to
      std::vector<Statement_Pack*> packed_in;
      // the schedule of Statement_ID's
      std::list<Statement_ID> scheduled_stmtIDs;
      // true for a scheduled statement
      std::vector<bool> scheduled;

      int num_stmts;
      std::vector<Statement*>& stmts;
      std::list<Statement_Pack*>& stmt_packs;
      Dependence_Matrix& deps;
    };

}
#endif /* lwopt_slp_schedule_INCLUDED */
