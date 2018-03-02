/* Generated automatically by the program `genrecog' from the target
   machine description file.  */

#include "config.h"
#include "system.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"
#include "insn-config.h"
#include "recog.h"
#include "real.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "toplev.h"
#include "reload.h"



/* `recog' contains a decision tree that recognizes whether the rtx
   X0 is a valid instruction.

   recog returns -1 if the rtx is not valid.  If the rtx is valid, recog
   returns a nonnegative number which is the insn code number for the
   pattern that matched.  This is the same as the order in the machine
   description of the entry that matched.  This number can be used as an
   index into `insn_data' and other tables.

   The third argument to recog is an optional pointer to an int.  If
   present, recog will accept a pattern if it matches except for missing
   CLOBBER expressions at the end.  In that case, the value pointed to by
   the optional pointer will be set to the number of CLOBBERs that need
   to be added (it should be initialized to zero by the caller).  If it
   is set nonzero, the caller should allocate a PARALLEL of the
   appropriate size, copy the initial entries, and call add_clobbers
   (found in insn-emit.c) to fill in the CLOBBERs.


   The function split_insns returns 0 if the rtl could not
   be split or the split rtl as an INSN list if it can be.

   The function peephole2_insns returns 0 if the rtl could not
   be matched. If there was a match, the new rtl is returned in an INSN list,
   and LAST_INSN will point to the last recognized insn in the old sequence.
*/


extern rtx gen_split_761 PARAMS ((rtx *));
extern rtx gen_split_762 PARAMS ((rtx *));
extern rtx gen_split_763 PARAMS ((rtx *));
extern rtx gen_split_764 PARAMS ((rtx *));
extern rtx gen_split_766 PARAMS ((rtx *));
extern rtx gen_split_767 PARAMS ((rtx *));
extern rtx gen_split_769 PARAMS ((rtx *));
extern rtx gen_split_770 PARAMS ((rtx *));
extern rtx gen_split_772 PARAMS ((rtx *));
extern rtx gen_split_773 PARAMS ((rtx *));
extern rtx gen_split_775 PARAMS ((rtx *));
extern rtx gen_split_776 PARAMS ((rtx *));
extern rtx gen_split_778 PARAMS ((rtx *));
extern rtx gen_split_779 PARAMS ((rtx *));
extern rtx gen_split_781 PARAMS ((rtx *));
extern rtx gen_split_782 PARAMS ((rtx *));
extern rtx gen_split_786 PARAMS ((rtx *));
extern rtx gen_split_787 PARAMS ((rtx *));
extern rtx gen_split_789 PARAMS ((rtx *));
extern rtx gen_split_790 PARAMS ((rtx *));
extern rtx gen_split_794 PARAMS ((rtx *));
extern rtx gen_split_795 PARAMS ((rtx *));
extern rtx gen_split_797 PARAMS ((rtx *));
extern rtx gen_split_798 PARAMS ((rtx *));
extern rtx gen_split_800 PARAMS ((rtx *));
extern rtx gen_split_801 PARAMS ((rtx *));
extern rtx gen_split_802 PARAMS ((rtx *));
extern rtx gen_split_803 PARAMS ((rtx *));
extern rtx gen_split_804 PARAMS ((rtx *));
extern rtx gen_split_805 PARAMS ((rtx *));
extern rtx gen_split_806 PARAMS ((rtx *));
extern rtx gen_split_809 PARAMS ((rtx *));
extern rtx gen_split_811 PARAMS ((rtx *));
extern rtx gen_split_814 PARAMS ((rtx *));
extern rtx gen_split_815 PARAMS ((rtx *));
extern rtx gen_split_817 PARAMS ((rtx *));
extern rtx gen_split_818 PARAMS ((rtx *));
extern rtx gen_split_819 PARAMS ((rtx *));
extern rtx gen_split_820 PARAMS ((rtx *));
extern rtx gen_split_822 PARAMS ((rtx *));
extern rtx gen_split_823 PARAMS ((rtx *));
extern rtx gen_split_824 PARAMS ((rtx *));
extern rtx gen_split_825 PARAMS ((rtx *));
extern rtx gen_split_830 PARAMS ((rtx *));
extern rtx gen_split_831 PARAMS ((rtx *));
extern rtx gen_split_835 PARAMS ((rtx *));
extern rtx gen_split_836 PARAMS ((rtx *));
extern rtx gen_split_837 PARAMS ((rtx *));
extern rtx gen_split_838 PARAMS ((rtx *));
extern rtx gen_split_839 PARAMS ((rtx *));
extern rtx gen_split_840 PARAMS ((rtx *));
extern rtx gen_split_841 PARAMS ((rtx *));
extern rtx gen_split_844 PARAMS ((rtx *));
extern rtx gen_split_845 PARAMS ((rtx *));
extern rtx gen_split_846 PARAMS ((rtx *));
extern rtx gen_split_847 PARAMS ((rtx *));
extern rtx gen_split_848 PARAMS ((rtx *));
extern rtx gen_split_849 PARAMS ((rtx *));
extern rtx gen_split_850 PARAMS ((rtx *));
extern rtx gen_split_851 PARAMS ((rtx *));
extern rtx gen_split_852 PARAMS ((rtx *));
extern rtx gen_split_853 PARAMS ((rtx *));
extern rtx gen_split_854 PARAMS ((rtx *));
extern rtx gen_split_857 PARAMS ((rtx *));
extern rtx gen_split_858 PARAMS ((rtx *));
extern rtx gen_split_859 PARAMS ((rtx *));
extern rtx gen_split_860 PARAMS ((rtx *));
extern rtx gen_split_861 PARAMS ((rtx *));
extern rtx gen_split_862 PARAMS ((rtx *));
extern rtx gen_split_863 PARAMS ((rtx *));
extern rtx gen_split_864 PARAMS ((rtx *));
extern rtx gen_split_865 PARAMS ((rtx *));
extern rtx gen_split_866 PARAMS ((rtx *));
extern rtx gen_split_868 PARAMS ((rtx *));
extern rtx gen_split_869 PARAMS ((rtx *));
extern rtx gen_split_870 PARAMS ((rtx *));
extern rtx gen_split_871 PARAMS ((rtx *));
extern rtx gen_split_872 PARAMS ((rtx *));
extern rtx gen_split_873 PARAMS ((rtx *));
extern rtx gen_split_875 PARAMS ((rtx *));
extern rtx gen_split_876 PARAMS ((rtx *));
extern rtx gen_split_877 PARAMS ((rtx *));
extern rtx gen_split_878 PARAMS ((rtx *));
extern rtx gen_split_879 PARAMS ((rtx *));
extern rtx gen_split_880 PARAMS ((rtx *));
extern rtx gen_split_881 PARAMS ((rtx *));
extern rtx gen_split_882 PARAMS ((rtx *));
extern rtx gen_split_883 PARAMS ((rtx *));
extern rtx gen_split_884 PARAMS ((rtx *));
extern rtx gen_split_886 PARAMS ((rtx *));
extern rtx gen_split_887 PARAMS ((rtx *));
extern rtx gen_split_888 PARAMS ((rtx *));
extern rtx gen_split_889 PARAMS ((rtx *));
extern rtx gen_split_899 PARAMS ((rtx *));
extern rtx gen_split_903 PARAMS ((rtx *));
extern rtx gen_split_906 PARAMS ((rtx *));
extern rtx gen_split_908 PARAMS ((rtx *));
extern rtx gen_split_910 PARAMS ((rtx *));
extern rtx gen_split_911 PARAMS ((rtx *));
extern rtx gen_split_912 PARAMS ((rtx *));
extern rtx gen_split_914 PARAMS ((rtx *));
extern rtx gen_split_917 PARAMS ((rtx *));
extern rtx gen_split_919 PARAMS ((rtx *));
extern rtx gen_split_923 PARAMS ((rtx *));
extern rtx gen_split_924 PARAMS ((rtx *));
extern rtx gen_split_925 PARAMS ((rtx *));
extern rtx gen_split_926 PARAMS ((rtx *));
extern rtx gen_split_927 PARAMS ((rtx *));
extern rtx gen_split_928 PARAMS ((rtx *));
extern rtx gen_split_929 PARAMS ((rtx *));
extern rtx gen_split_931 PARAMS ((rtx *));
extern rtx gen_split_932 PARAMS ((rtx *));
extern rtx gen_split_934 PARAMS ((rtx *));
extern rtx gen_split_935 PARAMS ((rtx *));
extern rtx gen_split_938 PARAMS ((rtx *));
extern rtx gen_split_939 PARAMS ((rtx *));
extern rtx gen_split_940 PARAMS ((rtx *));
extern rtx gen_split_941 PARAMS ((rtx *));
extern rtx gen_split_942 PARAMS ((rtx *));
extern rtx gen_split_943 PARAMS ((rtx *));
extern rtx gen_split_944 PARAMS ((rtx *));
extern rtx gen_split_945 PARAMS ((rtx *));
extern rtx gen_split_946 PARAMS ((rtx *));
extern rtx gen_split_947 PARAMS ((rtx *));
extern rtx gen_split_948 PARAMS ((rtx *));
extern rtx gen_split_949 PARAMS ((rtx *));
extern rtx gen_split_951 PARAMS ((rtx *));
extern rtx gen_split_952 PARAMS ((rtx *));
extern rtx gen_split_953 PARAMS ((rtx *));
extern rtx gen_split_954 PARAMS ((rtx *));
extern rtx gen_split_955 PARAMS ((rtx *));
extern rtx gen_split_956 PARAMS ((rtx *));
extern rtx gen_split_958 PARAMS ((rtx *));
extern rtx gen_split_959 PARAMS ((rtx *));
extern rtx gen_split_961 PARAMS ((rtx *));
extern rtx gen_split_962 PARAMS ((rtx *));
extern rtx gen_split_963 PARAMS ((rtx *));
extern rtx gen_split_964 PARAMS ((rtx *));
extern rtx gen_split_965 PARAMS ((rtx *));
extern rtx gen_split_966 PARAMS ((rtx *));
extern rtx gen_split_967 PARAMS ((rtx *));
extern rtx gen_split_970 PARAMS ((rtx *));
extern rtx gen_split_971 PARAMS ((rtx *));
extern rtx gen_split_972 PARAMS ((rtx *));
extern rtx gen_split_973 PARAMS ((rtx *));
extern rtx gen_split_974 PARAMS ((rtx *));
extern rtx gen_split_975 PARAMS ((rtx *));
extern rtx gen_split_976 PARAMS ((rtx *));
extern rtx gen_split_978 PARAMS ((rtx *));
extern rtx gen_split_980 PARAMS ((rtx *));
extern rtx gen_split_981 PARAMS ((rtx *));
extern rtx gen_split_986 PARAMS ((rtx *));
extern rtx gen_split_988 PARAMS ((rtx *));
extern rtx gen_split_989 PARAMS ((rtx *));
extern rtx gen_split_990 PARAMS ((rtx *));
extern rtx gen_split_992 PARAMS ((rtx *));
extern rtx gen_split_993 PARAMS ((rtx *));
extern rtx gen_split_994 PARAMS ((rtx *));
extern rtx gen_split_995 PARAMS ((rtx *));
extern rtx gen_split_996 PARAMS ((rtx *));
extern rtx gen_split_997 PARAMS ((rtx *));
extern rtx gen_split_998 PARAMS ((rtx *));
extern rtx gen_split_1000 PARAMS ((rtx *));
extern rtx gen_split_1001 PARAMS ((rtx *));
extern rtx gen_split_1002 PARAMS ((rtx *));
extern rtx gen_split_1003 PARAMS ((rtx *));
extern rtx gen_split_1004 PARAMS ((rtx *));
extern rtx gen_split_1005 PARAMS ((rtx *));
extern rtx gen_split_1067 PARAMS ((rtx *));
extern rtx gen_split_1068 PARAMS ((rtx *));
extern rtx gen_split_1069 PARAMS ((rtx *));
extern rtx gen_split_1070 PARAMS ((rtx *));
extern rtx gen_split_1071 PARAMS ((rtx *));
extern rtx gen_split_1074 PARAMS ((rtx *));
extern rtx gen_split_1075 PARAMS ((rtx *));
extern rtx gen_split_1076 PARAMS ((rtx *));
extern rtx gen_split_1077 PARAMS ((rtx *));
extern rtx gen_split_1078 PARAMS ((rtx *));
extern rtx gen_split_1079 PARAMS ((rtx *));
extern rtx gen_split_1080 PARAMS ((rtx *));
extern rtx gen_split_1081 PARAMS ((rtx *));
extern rtx gen_split_1082 PARAMS ((rtx *));
extern rtx gen_split_1083 PARAMS ((rtx *));
extern rtx gen_split_1084 PARAMS ((rtx *));
extern rtx gen_split_1085 PARAMS ((rtx *));
extern rtx gen_split_1086 PARAMS ((rtx *));
extern rtx gen_split_1087 PARAMS ((rtx *));
extern rtx gen_split_1088 PARAMS ((rtx *));
extern rtx gen_split_1089 PARAMS ((rtx *));
extern rtx gen_split_1090 PARAMS ((rtx *));
extern rtx gen_split_1091 PARAMS ((rtx *));
extern rtx gen_split_1092 PARAMS ((rtx *));
extern rtx gen_split_1093 PARAMS ((rtx *));
extern rtx gen_split_1094 PARAMS ((rtx *));
extern rtx gen_split_1095 PARAMS ((rtx *));
extern rtx gen_split_1096 PARAMS ((rtx *));
extern rtx gen_split_1097 PARAMS ((rtx *));
extern rtx gen_split_1098 PARAMS ((rtx *));
extern rtx gen_split_1099 PARAMS ((rtx *));
extern rtx gen_split_1100 PARAMS ((rtx *));
extern rtx gen_split_1101 PARAMS ((rtx *));
extern rtx gen_split_1102 PARAMS ((rtx *));
extern rtx gen_split_1103 PARAMS ((rtx *));
extern rtx gen_split_1104 PARAMS ((rtx *));
extern rtx gen_split_1105 PARAMS ((rtx *));
extern rtx gen_split_1106 PARAMS ((rtx *));
extern rtx gen_split_1107 PARAMS ((rtx *));
extern rtx gen_split_1108 PARAMS ((rtx *));
extern rtx gen_split_1109 PARAMS ((rtx *));
extern rtx gen_split_1110 PARAMS ((rtx *));
extern rtx gen_split_1111 PARAMS ((rtx *));
extern rtx gen_split_1112 PARAMS ((rtx *));
extern rtx gen_split_1113 PARAMS ((rtx *));
extern rtx gen_split_1114 PARAMS ((rtx *));
extern rtx gen_split_1115 PARAMS ((rtx *));
extern rtx gen_split_1116 PARAMS ((rtx *));
extern rtx gen_split_1117 PARAMS ((rtx *));
extern rtx gen_split_1118 PARAMS ((rtx *));
extern rtx gen_split_1119 PARAMS ((rtx *));
extern rtx gen_split_1120 PARAMS ((rtx *));
extern rtx gen_split_1121 PARAMS ((rtx *));
extern rtx gen_split_1122 PARAMS ((rtx *));
extern rtx gen_split_1130 PARAMS ((rtx *));
extern rtx gen_split_1131 PARAMS ((rtx *));
extern rtx gen_split_1132 PARAMS ((rtx *));
extern rtx gen_split_1133 PARAMS ((rtx *));
extern rtx gen_split_1139 PARAMS ((rtx *));



static int recog_1 PARAMS ((rtx, rtx, int *));
static int
recog_1 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L3;
    case SIGN_EXTEND:
      goto L35;
    case ZERO_EXTRACT:
      goto L1487;
    case UNSPEC:
      goto L11906;
    case FIX:
      goto L2613;
    case PLUS:
      goto L2631;
    case MINUS:
      goto L2637;
    case NEG:
      goto L2643;
    case MULT:
      goto L2659;
    case ASHIFT:
      goto L2779;
    case LSHIFTRT:
      goto L2794;
    case ASHIFTRT:
      goto L2809;
    case NOT:
      goto L2858;
    case ABS:
      goto L2935;
    case FFS:
      goto L2987;
    case TRUNCATE:
      goto L2998;
    case DIV:
      goto L3018;
    case UDIV:
      goto L3061;
    case ROTATE:
      goto L3067;
    case AND:
      goto L3104;
    case IOR:
    case XOR:
      goto L11898;
    default:
      goto L11899;
   }
 L11898: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x1, DImode))
    {
      operands[3] = x1;
      goto L3561;
    }
 L11899: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x1, DImode))
    {
      operands[3] = x1;
      goto L3596;
    }
  if (scc_comparison_operator (x1, DImode))
    {
      operands[1] = x1;
      goto L5391;
    }
 L11901: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case EQ:
      goto L5457;
    case LEU:
      goto L5905;
    case GEU:
      goto L6306;
    case GT:
      goto L6449;
    case GTU:
      goto L6665;
    default:
     break;
   }
  goto ret0;

 L3: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L11907;
    case HImode:
      goto L11908;
    case SImode:
      goto L11909;
    default:
      break;
    }
  goto ret0;

 L11907: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4;
    }
 L11910: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L3152;
  goto ret0;

 L4: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 0;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L11910;

 L3152: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ROTATE)
    goto L3153;
  goto ret0;

 L3153: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3154;
    }
  goto ret0;

 L3154: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3155;
    }
  goto ret0;

 L3155: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 261;
    }
  goto ret0;

 L11908: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L68;
    }
 L11911: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L3199;
  goto ret0;

 L68: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 6;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L11911;

 L3199: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ROTATE)
    goto L3200;
  goto ret0;

 L3200: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3201;
    }
  goto ret0;

 L3201: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3202;
    }
  goto ret0;

 L3202: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 264;
    }
  goto ret0;

 L11909: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L132;
    }
 L11912: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L3246;
  goto ret0;

 L132: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 12;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L11912;

 L3246: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ROTATE)
    goto L3247;
  goto ret0;

 L3247: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3248;
    }
  goto ret0;

 L3248: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3249;
    }
  goto ret0;

 L3249: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 267;
    }
  goto ret0;

 L35: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L11913;
    case HImode:
      goto L11914;
    case SImode:
      goto L11915;
    default:
      break;
    }
  goto ret0;

 L11913: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L36;
    }
  goto ret0;

 L36: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 3;
    }
  goto ret0;

 L11914: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L100;
    }
  goto ret0;

 L100: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 9;
    }
  goto ret0;

 L11915: ATTRIBUTE_UNUSED_LABEL
  if (lwa_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L164;
    }
  goto ret0;

 L164: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 15;
    }
  goto ret0;

 L1487: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1488;
    }
  goto ret0;

 L1488: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1489;
    }
  goto ret0;

 L1489: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const_int_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1490;
    }
  goto ret0;

 L1490: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 114;
    }
  goto ret0;

 L11906: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 10)
    goto L2578;
  goto ret0;

 L2578: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == FIX)
    goto L2579;
  goto ret0;

 L2579: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2580;
    }
  goto ret0;

 L2580: ATTRIBUTE_UNUSED_LABEL
  if (((TARGET_POWER2 || TARGET_POWERPC) && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 211;
    }
  goto ret0;

 L2613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L11916;
    case TFmode:
      goto L11917;
    default:
      break;
    }
  goto ret0;

 L11916: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2614;
    }
  goto ret0;

 L2614: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 215;
    }
  goto ret0;

 L11917: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L3811;
    }
  goto ret0;

 L3811: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_POWERPC64
   && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_LONG_DOUBLE_128)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 318;
    }
  goto ret0;

 L2631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L11919;
  goto ret0;

 L11919: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case LSHIFTRT:
      goto L5648;
    case GT:
      goto L6508;
    case GTU:
      goto L6706;
    case SUBREG:
    case REG:
      goto L11918;
    default:
      goto ret0;
   }
 L11918: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2632;
    }
  goto ret0;

 L5648: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == NEG)
    goto L5649;
  goto ret0;

 L5649: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ABS)
    goto L5650;
  goto ret0;

 L5650: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L5651;
    }
  goto ret0;

 L5651: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 63LL)
    goto L5652;
  goto ret0;

 L5652: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L5653;
    }
  goto ret0;

 L5653: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 429;
    }
  goto ret0;

 L6508: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L6509;
    }
  goto ret0;

 L6509: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6510;
  goto ret0;

 L6510: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L6511;
    }
  goto ret0;

 L6511: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 488;
    }
  goto ret0;

 L6706: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L6707;
    }
  goto ret0;

 L6707: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L6708;
    }
  goto ret0;

 L6708: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L6709;
    }
  goto ret0;

 L6709: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 504;
    }
  goto ret0;

 L2632: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2633;
    }
 L2822: ATTRIBUTE_UNUSED_LABEL
  if (add_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2823;
    }
  goto ret0;

 L2633: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 217;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L2822;

 L2823: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 232;
    }
  goto ret0;

 L2637: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2638;
    }
  goto ret0;

 L2638: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2639;
    }
  goto ret0;

 L2639: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 218;
    }
 L2892: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 238;
    }
  goto ret0;

 L2643: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L11923;
  goto ret0;

 L11923: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L2950;
    case GT:
      goto L6647;
    case GTU:
      goto L6799;
    case SUBREG:
    case REG:
      goto L11922;
    default:
      goto ret0;
   }
 L11922: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2644;
    }
  goto ret0;

 L2950: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2951;
    }
  goto ret0;

 L2951: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 242;
    }
  goto ret0;

 L6647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L6648;
    }
  goto ret0;

 L6648: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_POWERPC64))
    {
      return 497;
    }
  goto ret0;

 L6799: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L6800;
    }
  goto ret0;

 L6800: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L6801;
    }
  goto ret0;

 L6801: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 510;
    }
  goto ret0;

 L2644: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 219;
    }
 L2956: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 243;
    }
  goto ret0;

 L2659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L11926;
  goto ret0;

 L11926: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L2660;
    case ZERO_EXTEND:
      goto L2687;
    case SUBREG:
    case REG:
      goto L11928;
    default:
      goto ret0;
   }
 L11928: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2993;
    }
  goto ret0;

 L2660: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2661;
    }
  goto ret0;

 L2661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L2662;
  goto ret0;

 L2662: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2663;
    }
  goto ret0;

 L2663: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 220;
    }
 L2671: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWER && ! TARGET_POWERPC64))
    {
      return 221;
    }
  goto ret0;

 L2687: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2688;
    }
  goto ret0;

 L2688: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2689;
  goto ret0;

 L2689: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2690;
    }
  goto ret0;

 L2690: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 222;
    }
 L2698: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWER && ! TARGET_POWERPC64))
    {
      return 223;
    }
  goto ret0;

 L2993: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2994;
    }
  goto ret0;

 L2994: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 247;
    }
  goto ret0;

 L2779: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2780;
    }
  goto ret0;

 L2780: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2781;
    }
  goto ret0;

 L2781: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 228;
    }
 L3294: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 270;
    }
  goto ret0;

 L2794: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L11930;
  goto ret0;

 L11930: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NEG)
    goto L5605;
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2795;
    }
  goto ret0;

 L5605: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ABS)
    goto L5606;
  goto ret0;

 L5606: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5607;
    }
  goto ret0;

 L5607: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 63LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 427;
    }
  goto ret0;

 L2795: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2796;
    }
  goto ret0;

 L2796: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 229;
    }
 L3425: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 279;
    }
  goto ret0;

 L2809: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2810;
    }
  goto ret0;

 L2810: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2811;
    }
 L3461: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3462;
    }
  goto ret0;

 L2811: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 230;
    }
 L2817: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT && !TARGET_POWER))
    {
      return 231;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3461;

 L3462: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 282;
    }
  goto ret0;

 L2858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2859;
    }
  goto ret0;

 L2859: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 235;
    }
  goto ret0;

 L2935: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2936;
    }
  goto ret0;

 L2936: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 241;
    }
  goto ret0;

 L2987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2988;
    }
  goto ret0;

 L2988: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 246;
    }
  goto ret0;

 L2998: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L2999;
  goto ret0;

 L2999: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == MULT)
    goto L3000;
  goto ret0;

 L3000: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == TImode)
    goto L11931;
  goto ret0;

 L11931: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L3001;
    case ZERO_EXTEND:
      goto L3011;
    default:
     break;
   }
  goto ret0;

 L3001: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3002;
    }
  goto ret0;

 L3002: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L3003;
  goto ret0;

 L3003: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3004;
    }
  goto ret0;

 L3004: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 64LL
      && (TARGET_POWERPC64))
    {
      return 248;
    }
  goto ret0;

 L3011: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3012;
    }
  goto ret0;

 L3012: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L3013;
  goto ret0;

 L3013: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3014;
    }
  goto ret0;

 L3014: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 64LL
      && (TARGET_POWERPC64))
    {
      return 249;
    }
  goto ret0;

 L3018: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3056;
    }
  goto ret0;

 L3056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3057;
    }
  if (exact_log2_cint_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3020;
    }
  goto ret0;

 L3057: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 253;
    }
  goto ret0;

 L3020: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 250;
    }
  goto ret0;

 L3061: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3062;
    }
  goto ret0;

 L3062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3063;
    }
  goto ret0;

 L3063: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 254;
    }
  goto ret0;

 L3067: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3068;
    }
  goto ret0;

 L3068: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3069;
    }
  goto ret0;

 L3069: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 255;
    }
  goto ret0;

 L3104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L11933;
  goto L11899;

 L11933: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ROTATE:
      goto L3105;
    case ASHIFT:
      goto L3330;
    case SUBREG:
    case REG:
      goto L11935;
    default:
      goto L11899;
   }
 L11935: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3507;
    }
  goto L11899;

 L3105: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3106;
    }
  goto L11899;

 L3106: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3107;
    }
  goto L11899;

 L3107: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (mask64_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3108;
    }
  goto L11899;

 L3108: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 258;
    }
  x1 = XEXP (x0, 1);
  goto L11899;

 L3330: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3331;
    }
  goto L11899;

 L3331: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3332;
    }
  goto L11899;

 L3332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L11936;
  goto L11899;

 L11936: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3333;
    }
 L11937: ATTRIBUTE_UNUSED_LABEL
  if (mask64_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3380;
    }
  goto L11899;

 L3333: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && includes_rldic_lshift_p (operands[2], operands[3])))
    {
      return 273;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L11937;

 L3380: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && includes_rldicr_lshift_p (operands[2], operands[3])))
    {
      return 276;
    }
  x1 = XEXP (x0, 1);
  goto L11899;

 L3507: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (and64_2_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3508;
    }
  goto L11899;

 L3508: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 285;
    }
  x1 = XEXP (x0, 1);
  goto L11899;

 L3561: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3562;
    }
  goto L11899;

 L3562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (logical_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3563;
    }
  goto L11899;

 L3563: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 288;
    }
  x1 = XEXP (x0, 1);
  goto L11899;

 L3596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NOT)
    goto L3597;
  goto ret0;

 L3597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3598;
    }
  goto ret0;

 L3598: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L11939;
  goto ret0;

 L11939: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L3638;
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3599;
    }
  goto ret0;

 L3638: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3639;
    }
  goto ret0;

 L3639: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 294;
    }
  goto ret0;

 L3599: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 291;
    }
  goto ret0;

 L5391: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (cc_reg_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L5392;
    }
  goto L11901;

 L5392: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64))
    {
      return 414;
    }
  goto L11901;

 L5457: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5458;
    }
  goto ret0;

 L5458: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L5459;
    }
  goto ret0;

 L5459: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 419;
    }
  goto ret0;

 L5905: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5906;
    }
  goto ret0;

 L5906: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L5907;
    }
  goto ret0;

 L5907: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 441;
    }
  goto ret0;

 L6306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L6307;
    }
  goto ret0;

 L6307: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_neg_short_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L6308;
    }
  goto ret0;

 L6308: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 471;
    }
  goto ret0;

 L6449: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L6450;
    }
  goto ret0;

 L6450: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64))
    {
      return 482;
    }
  goto ret0;

 L6665: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L6666;
    }
  goto ret0;

 L6666: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L6667;
    }
  goto ret0;

 L6667: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 500;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_2 PARAMS ((rtx, rtx, int *));
static int
recog_2 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L19;
    case SIGN_EXTEND:
      goto L51;
    case PLUS:
      goto L2839;
    case NOT:
      goto L2874;
    case MINUS:
      goto L2908;
    case NEG:
      goto L2971;
    case DIV:
      goto L3036;
    case ROTATE:
      goto L3085;
    case AND:
      goto L3126;
    case ASHIFT:
      goto L3310;
    case LSHIFTRT:
      goto L3441;
    case ASHIFTRT:
      goto L3478;
    case IOR:
    case XOR:
      goto L11985;
    default:
      goto L11986;
   }
 L11985: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L3579;
    }
 L11986: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x2, DImode))
    {
      operands[4] = x2;
      goto L3616;
    }
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5331;
    }
  goto ret0;

 L19: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L11989;
    case HImode:
      goto L11990;
    case SImode:
      goto L11991;
    default:
      break;
    }
  goto ret0;

 L11989: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L20;
    }
 L11992: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L3174;
  goto ret0;

 L20: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 1;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L11992;

 L3174: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ROTATE)
    goto L3175;
  goto ret0;

 L3175: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3176;
    }
  goto ret0;

 L3176: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3177;
    }
  goto ret0;

 L3177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 262;
    }
  goto ret0;

 L11990: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L84;
    }
 L11993: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L3221;
  goto ret0;

 L84: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 7;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L11993;

 L3221: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ROTATE)
    goto L3222;
  goto ret0;

 L3222: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3223;
    }
  goto ret0;

 L3223: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3224;
    }
  goto ret0;

 L3224: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 265;
    }
  goto ret0;

 L11991: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L148;
    }
 L11994: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L3268;
  goto ret0;

 L148: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 13;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L11994;

 L3268: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ROTATE)
    goto L3269;
  goto ret0;

 L3269: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3270;
    }
  goto ret0;

 L3270: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3271;
    }
  goto ret0;

 L3271: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 268;
    }
  goto ret0;

 L51: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L11995;
    case HImode:
      goto L11996;
    case SImode:
      goto L11997;
    default:
      break;
    }
  goto ret0;

 L11995: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L52;
    }
  goto ret0;

 L52: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 4;
    }
  goto ret0;

 L11996: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L116;
    }
  goto ret0;

 L116: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 10;
    }
  goto ret0;

 L11997: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L180;
    }
  goto ret0;

 L180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 16;
    }
  goto ret0;

 L2839: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L11999;
  goto ret0;

 L11999: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case LSHIFTRT:
      goto L5702;
    case GT:
      goto L6552;
    case GTU:
      goto L6750;
    case SUBREG:
    case REG:
      goto L11998;
    default:
      goto ret0;
   }
 L11998: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2840;
    }
  goto ret0;

 L5702: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == NEG)
    goto L5703;
  goto ret0;

 L5703: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ABS)
    goto L5704;
  goto ret0;

 L5704: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L5705;
    }
  goto ret0;

 L5705: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 63LL)
    goto L5706;
  goto ret0;

 L5706: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L5707;
    }
  goto ret0;

 L5707: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 431;
    }
  goto ret0;

 L6552: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6553;
    }
  goto ret0;

 L6553: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6554;
  goto ret0;

 L6554: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L6555;
    }
  goto ret0;

 L6555: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 490;
    }
  goto ret0;

 L6750: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6751;
    }
  goto ret0;

 L6751: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L6752;
    }
  goto ret0;

 L6752: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L6753;
    }
  goto ret0;

 L6753: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 506;
    }
  goto ret0;

 L2840: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2841;
    }
  goto ret0;

 L2841: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 233;
    }
  goto ret0;

 L2874: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2875;
    }
  goto ret0;

 L2875: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 236;
    }
  goto ret0;

 L2908: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2909;
    }
  goto ret0;

 L2909: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2910;
    }
  goto ret0;

 L2910: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 239;
    }
  goto ret0;

 L2971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2972;
    }
  goto ret0;

 L2972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 244;
    }
  goto ret0;

 L3036: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3037;
    }
  goto ret0;

 L3037: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (exact_log2_cint_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3038;
    }
  goto ret0;

 L3038: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 251;
    }
  goto ret0;

 L3085: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3086;
    }
  goto ret0;

 L3086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3087;
    }
  goto ret0;

 L3087: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 256;
    }
  goto ret0;

 L3126: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L12002;
  goto L11986;

 L12002: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ROTATE:
      goto L3127;
    case ASHIFT:
      goto L3352;
    case SUBREG:
    case REG:
      goto L12004;
    default:
      goto L11986;
   }
 L12004: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3527;
    }
  goto L11986;

 L3127: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3128;
    }
  goto L11986;

 L3128: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3129;
    }
  goto L11986;

 L3129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (mask64_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L3130;
    }
  goto L11986;

 L3130: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 259;
    }
  x2 = XEXP (x1, 0);
  goto L11986;

 L3352: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3353;
    }
  goto L11986;

 L3353: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3354;
    }
  goto L11986;

 L3354: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L12005;
  goto L11986;

 L12005: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L3355;
    }
 L12006: ATTRIBUTE_UNUSED_LABEL
  if (mask64_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L3402;
    }
  goto L11986;

 L3355: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64 && includes_rldic_lshift_p (operands[2], operands[3]))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 274;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L12006;

 L3402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64 && includes_rldicr_lshift_p (operands[2], operands[3]))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 277;
    }
  x2 = XEXP (x1, 0);
  goto L11986;

 L3527: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (and64_2_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3528;
    }
  goto L11986;

 L3528: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 286;
    }
  x2 = XEXP (x1, 0);
  goto L11986;

 L3310: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3311;
    }
  goto ret0;

 L3311: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3312;
    }
  goto ret0;

 L3312: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 271;
    }
  goto ret0;

 L3441: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3442;
    }
  goto ret0;

 L3442: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3443;
    }
  goto ret0;

 L3443: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 280;
    }
  goto ret0;

 L3478: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3479;
    }
  goto ret0;

 L3479: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3480;
    }
  goto ret0;

 L3480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 283;
    }
  goto ret0;

 L3579: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3580;
    }
  goto L11986;

 L3580: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3581;
    }
  goto L11986;

 L3581: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 289;
    }
  x2 = XEXP (x1, 0);
  goto L11986;

 L3616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == NOT)
    goto L3617;
  goto ret0;

 L3617: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3618;
    }
  goto ret0;

 L3618: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode)
    goto L12008;
  goto ret0;

 L12008: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L3660;
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3619;
    }
  goto ret0;

 L3660: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3661;
    }
  goto ret0;

 L3661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 295;
    }
  goto ret0;

 L3619: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 292;
    }
  goto ret0;

 L5331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L5332;
    }
  goto ret0;

 L5332: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 405;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_3 PARAMS ((rtx, rtx, int *));
static int
recog_3 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L209;
    case SIGN_EXTEND:
      goto L241;
    case PLUS:
      goto L396;
    case NOT:
      goto L430;
    case MINUS:
      goto L470;
    case IF_THEN_ELSE:
      goto L547;
    case NEG:
      goto L635;
    case MULT:
      goto L690;
    case DIV:
      goto L825;
    case AND:
      goto L1027;
    case ZERO_EXTRACT:
      goto L1465;
    case ROTATE:
      goto L1545;
    case ASHIFT:
      goto L1734;
    case LSHIFTRT:
      goto L1882;
    case ASHIFTRT:
      goto L2149;
    case IOR:
    case XOR:
      goto L11968;
    default:
      goto L11969;
   }
 L11968: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L1165;
    }
 L11969: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x2, SImode))
    {
      operands[4] = x2;
      goto L1201;
    }
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5326;
    }
  goto ret0;

 L209: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L12009;
    case HImode:
      goto L12010;
    default:
      break;
    }
  goto ret0;

 L12009: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L210;
    }
 L12011: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L1630;
  goto ret0;

 L210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 19;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12011;

 L1630: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12013;
  goto ret0;

 L12013: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L1631;
    case LSHIFTRT:
      goto L2019;
    default:
     break;
   }
  goto ret0;

 L1631: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1632;
    }
  goto ret0;

 L1632: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1633;
    }
  goto ret0;

 L1633: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 124;
    }
  goto ret0;

 L2019: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L2020;
    }
  goto ret0;

 L2020: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2021;
    }
  goto ret0;

 L2021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (includes_rshift_p (operands[2], GEN_INT (255)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 148;
    }
  goto ret0;

 L12010: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L334;
    }
 L12012: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L1675;
  goto ret0;

 L334: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 31;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12012;

 L1675: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12015;
  goto ret0;

 L12015: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L1676;
    case LSHIFTRT:
      goto L2066;
    default:
     break;
   }
  goto ret0;

 L1676: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1677;
    }
  goto ret0;

 L1677: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1678;
    }
  goto ret0;

 L1678: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 127;
    }
  goto ret0;

 L2066: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L2067;
    }
  goto ret0;

 L2067: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2068;
    }
  goto ret0;

 L2068: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (includes_rshift_p (operands[2], GEN_INT (65535)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 151;
    }
  goto ret0;

 L241: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case QImode:
      goto L12017;
    case HImode:
      goto L12018;
    default:
      break;
    }
  goto ret0;

 L12017: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L242;
    }
  goto ret0;

 L242: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 22;
    }
  goto ret0;

 L12018: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L364;
    }
  goto ret0;

 L364: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 34;
    }
  goto ret0;

 L396: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L12020;
  goto ret0;

 L12020: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case EQ:
      goto L5544;
    case LSHIFTRT:
      goto L5676;
    case LE:
      goto L5868;
    case LEU:
      goto L5973;
    case LT:
      goto L6098;
    case LTU:
      goto L6171;
    case GE:
      goto L6269;
    case GEU:
      goto L6361;
    case GT:
      goto L6530;
    case GTU:
      goto L6728;
    case SUBREG:
    case REG:
      goto L12019;
    default:
      goto ret0;
   }
 L12019: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L397;
    }
  goto ret0;

 L5544: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5545;
    }
  goto ret0;

 L5545: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5546;
    }
  goto ret0;

 L5546: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L5547;
    }
  goto ret0;

 L5547: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 423;
    }
  goto ret0;

 L5676: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NEG)
    goto L5677;
  goto ret0;

 L5677: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == ABS)
    goto L5678;
  goto ret0;

 L5678: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L5679;
    }
  goto ret0;

 L5679: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 31LL)
    goto L5680;
  goto ret0;

 L5680: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5681;
    }
  goto ret0;

 L5681: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 430;
    }
  goto ret0;

 L5868: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5869;
    }
  goto ret0;

 L5869: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5870;
    }
  goto ret0;

 L5870: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L5871;
    }
  goto ret0;

 L5871: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 437;
    }
  goto ret0;

 L5973: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5974;
    }
  goto ret0;

 L5974: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5975;
    }
  goto ret0;

 L5975: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L5976;
    }
  goto ret0;

 L5976: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 446;
    }
  goto ret0;

 L6098: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6099;
    }
  goto ret0;

 L6099: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6100;
    }
  goto ret0;

 L6100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6101;
    }
  goto ret0;

 L6101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 455;
    }
  goto ret0;

 L6171: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6172;
    }
  goto ret0;

 L6172: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_neg_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6173;
    }
  goto ret0;

 L6173: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6174;
    }
  goto ret0;

 L6174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 461;
    }
  goto ret0;

 L6269: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6270;
    }
  goto ret0;

 L6270: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6271;
    }
  goto ret0;

 L6271: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6272;
    }
  goto ret0;

 L6272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 467;
    }
  goto ret0;

 L6361: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6362;
    }
  goto ret0;

 L6362: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_neg_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6363;
    }
  goto ret0;

 L6363: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6364;
    }
  goto ret0;

 L6364: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 475;
    }
  goto ret0;

 L6530: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6531;
    }
  goto ret0;

 L6531: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6532;
 L6617: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6618;
    }
  goto ret0;

 L6532: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6533;
    }
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L6617;

 L6533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 489;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L6617;

 L6618: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6619;
    }
  goto ret0;

 L6619: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 494;
    }
  goto ret0;

 L6728: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6729;
    }
  goto ret0;

 L6729: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6730;
    }
  goto ret0;

 L6730: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6731;
    }
  goto ret0;

 L6731: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 505;
    }
  goto ret0;

 L397: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L398;
    }
  goto ret0;

 L398: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 37;
    }
  goto ret0;

 L430: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L431;
    }
  goto ret0;

 L431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 40;
    }
  goto ret0;

 L470: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L471;
    }
  goto ret0;

 L471: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L472;
    }
  goto ret0;

 L472: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12030;
  goto ret0;

 L12030: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L12032;
  goto ret0;

 L12032: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 44;
    }
 L12033: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 45;
    }
  goto ret0;

 L547: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == GT)
    goto L548;
  goto ret0;

 L548: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L549;
    }
  goto ret0;

 L549: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L550;
    }
  goto ret0;

 L550: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L551;
  goto ret0;

 L551: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MINUS)
    goto L552;
  goto ret0;

 L552: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L553;
  goto ret0;

 L553: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[1]))
    goto L554;
  goto ret0;

 L554: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 49;
    }
  goto ret0;

 L635: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L636;
    }
  goto ret0;

 L636: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 56;
    }
  goto ret0;

 L690: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L691;
    }
  goto ret0;

 L691: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L692;
    }
  goto ret0;

 L692: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12034;
  goto ret0;

 L12034: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L12036;
  goto ret0;

 L12036: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 61;
    }
 L12037: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 62;
    }
  goto ret0;

 L825: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L826;
    }
  goto ret0;

 L826: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (exact_log2_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L827;
    }
  goto ret0;

 L827: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 71;
    }
  goto ret0;

 L1027: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L12039;
  goto L11969;

 L12039: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ROTATE:
      goto L1585;
    case ASHIFT:
      goto L1823;
    case LSHIFTRT:
      goto L1971;
    case NEG:
      goto L6029;
    case SUBREG:
    case REG:
      goto L12038;
    default:
      goto L11969;
   }
 L12038: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1028;
    }
  goto L11969;

 L1585: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1586;
    }
  goto L11969;

 L1586: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1587;
    }
  goto L11969;

 L1587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (mask_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1588;
    }
  goto L11969;

 L1588: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 121;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L1823: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1824;
    }
  goto L11969;

 L1824: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1825;
    }
  goto L11969;

 L1825: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (mask_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1826;
    }
  goto L11969;

 L1826: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (includes_lshift_p (operands[2], operands[3]))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 136;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L1971: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1972;
    }
  goto L11969;

 L1972: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1973;
    }
  goto L11969;

 L1973: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (mask_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1974;
    }
  goto L11969;

 L1974: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (includes_rshift_p (operands[2], operands[3]))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 145;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L6029: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12043;
  goto L11969;

 L12043: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case LEU:
      goto L6030;
    case GEU:
      goto L6418;
    default:
     break;
   }
  goto L11969;

 L6030: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6031;
    }
  goto L11969;

 L6031: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6032;
    }
  goto L11969;

 L6032: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6033;
    }
  goto L11969;

 L6033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 450;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L6418: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6419;
    }
  goto L11969;

 L6419: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6420;
    }
  goto L11969;

 L6420: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6421;
    }
  goto L11969;

 L6421: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 479;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L1028: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (and_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1029;
    }
  goto L11969;

 L1029: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12045;
  x2 = XEXP (x1, 0);
  goto L11969;

 L12045: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L12047;
  x2 = XEXP (x1, 0);
  goto L11969;

 L12047: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 81;
    }
 L12048: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 82;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L1465: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1466;
    }
  goto ret0;

 L1466: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1467;
    }
  goto ret0;

 L1467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1468;
    }
  goto ret0;

 L1468: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 112;
    }
  goto ret0;

 L1545: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1546;
    }
  goto ret0;

 L1546: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1547;
    }
  goto ret0;

 L1547: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 118;
    }
  goto ret0;

 L1734: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1735;
    }
  goto ret0;

 L1735: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1736;
    }
  goto ret0;

 L1736: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12049;
  goto ret0;

 L12049: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L12051;
  goto ret0;

 L12051: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 131;
    }
 L12052: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 132;
    }
  goto ret0;

 L1882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1883;
    }
  goto ret0;

 L1883: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1884;
    }
  goto ret0;

 L1884: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12053;
  goto ret0;

 L12053: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L12055;
  goto ret0;

 L12055: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 140;
    }
 L12056: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 141;
    }
  goto ret0;

 L2149: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2150;
    }
  goto ret0;

 L2150: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2151;
    }
  goto ret0;

 L2151: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12057;
  goto ret0;

 L12057: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L12059;
  goto ret0;

 L12059: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 158;
    }
 L12060: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 159;
    }
  goto ret0;

 L1165: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1166;
    }
  goto L11969;

 L1166: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1167;
    }
  goto L11969;

 L1167: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 89;
    }
  x2 = XEXP (x1, 0);
  goto L11969;

 L1201: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NOT)
    goto L1202;
  goto ret0;

 L1202: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1203;
    }
  goto ret0;

 L1203: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L12062;
  goto ret0;

 L12062: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L1244;
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1204;
    }
  goto ret0;

 L1244: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1245;
    }
  goto ret0;

 L1245: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 95;
    }
  goto ret0;

 L1204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 92;
    }
  goto ret0;

 L5326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      return 404;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_4 PARAMS ((rtx, rtx, int *));
static int
recog_4 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L195;
    case SIGN_EXTEND:
      goto L225;
    case PLUS:
      goto L379;
    case NOT:
      goto L415;
    case MINUS:
      goto L446;
    case IF_THEN_ELSE:
      goto L520;
    case ABS:
      goto L581;
    case NEG:
      goto L599;
    case FFS:
      goto L651;
    case MULT:
      goto L664;
    case UDIV:
      goto L776;
    case DIV:
      goto L797;
    case AND:
      goto L1007;
    case IOR:
      goto L1262;
    case ZERO_EXTRACT:
      goto L1447;
    case ROTATE:
      goto L1529;
    case ASHIFT:
      goto L1708;
    case LSHIFTRT:
      goto L1856;
    case ASHIFTRT:
      goto L2123;
    default:
     break;
   }
 L12087: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x1, SImode))
    {
      operands[3] = x1;
      goto L1148;
    }
 L12088: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x1, SImode))
    {
      operands[3] = x1;
      goto L1182;
    }
  goto ret0;

 L195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L12095;
    case HImode:
      goto L12096;
    default:
      break;
    }
  goto ret0;

 L12095: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, QImode))
    {
      operands[1] = x2;
      return 18;
    }
 L12097: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L1610;
  goto ret0;

 L1610: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L12099;
  goto ret0;

 L12099: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ROTATE:
      goto L1611;
    case LSHIFTRT:
      goto L1997;
    default:
     break;
   }
  goto ret0;

 L1611: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1612;
    }
  goto ret0;

 L1612: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      return 123;
    }
  goto ret0;

 L1997: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1998;
    }
  goto ret0;

 L1998: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1999;
    }
  goto ret0;

 L1999: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], GEN_INT (255))))
    {
      return 147;
    }
  goto ret0;

 L12096: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, HImode))
    {
      operands[1] = x2;
      return 30;
    }
 L12098: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L1655;
  goto ret0;

 L1655: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L12101;
  goto ret0;

 L12101: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ROTATE:
      goto L1656;
    case LSHIFTRT:
      goto L2044;
    default:
     break;
   }
  goto ret0;

 L1656: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1657;
    }
  goto ret0;

 L1657: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      return 126;
    }
  goto ret0;

 L2044: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2045;
    }
  goto ret0;

 L2045: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2046;
    }
  goto ret0;

 L2046: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], GEN_INT (65535))))
    {
      return 150;
    }
  goto ret0;

 L225: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case QImode:
      goto L12103;
    case HImode:
      goto L12104;
    default:
      break;
    }
  goto ret0;

 L12103: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L226;
    }
  goto ret0;

 L226: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC))
    {
      return 21;
    }
  goto ret0;

 L12104: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, HImode))
    {
      operands[1] = x2;
      return 33;
    }
  goto ret0;

 L379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L380;
    }
  goto ret0;

 L380: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (add_operand (x2, SImode))
    {
      operands[2] = x2;
      return 36;
    }
  goto ret0;

 L415: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      return 39;
    }
  goto ret0;

 L446: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L447;
    }
  goto ret0;

 L447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L448;
    }
  goto ret0;

 L448: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC))
    {
      return 42;
    }
 L454: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC))
    {
      return 43;
    }
  goto ret0;

 L520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == GT)
    goto L521;
  goto ret0;

 L521: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L522;
    }
  goto ret0;

 L522: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L523;
    }
  goto ret0;

 L523: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL)
    goto L524;
  goto ret0;

 L524: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L525;
  goto ret0;

 L525: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L526;
  goto ret0;

 L526: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWER))
    {
      return 48;
    }
  goto ret0;

 L581: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L582;
    }
  goto ret0;

 L582: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 51;
    }
 L595: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_ISEL)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 52;
    }
  goto ret0;

 L599: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12105;
  goto ret0;

 L12105: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == ABS)
    goto L600;
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      return 55;
    }
  goto ret0;

 L600: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L601;
    }
  goto ret0;

 L601: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 53;
    }
 L616: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 54;
    }
  goto ret0;

 L651: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      return 58;
    }
  goto ret0;

 L664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L665;
    }
  goto ret0;

 L665: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L666;
    }
  goto ret0;

 L666: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 59;
    }
 L672: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 60;
    }
  goto ret0;

 L776: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L777;
    }
  goto ret0;

 L777: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L778;
    }
  goto ret0;

 L778: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 66;
    }
 L784: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWER))
    {
      return 67;
    }
  goto ret0;

 L797: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L798;
    }
  goto ret0;

 L798: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L799;
    }
  if (exact_log2_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      return 70;
    }
  goto ret0;

 L799: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 68;
    }
 L805: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWER))
    {
      return 69;
    }
  goto ret0;

 L1007: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12108;
  goto L12088;

 L12108: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ROTATE:
      goto L1565;
    case ASHIFT:
      goto L1801;
    case LSHIFTRT:
      goto L1949;
    case SUBREG:
    case REG:
      goto L12107;
    default:
      goto L12088;
   }
 L12107: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1008;
    }
  goto L12088;

 L1565: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1566;
    }
  goto L12088;

 L1566: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1567;
    }
  goto L12088;

 L1567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (mask_operand (x2, SImode))
    {
      operands[3] = x2;
      return 120;
    }
  goto L12088;

 L1801: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1802;
    }
  goto L12088;

 L1802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1803;
    }
  goto L12088;

 L1803: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (mask_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1804;
    }
  goto L12088;

 L1804: ATTRIBUTE_UNUSED_LABEL
  if ((includes_lshift_p (operands[2], operands[3])))
    {
      return 135;
    }
  x1 = XEXP (x0, 1);
  goto L12088;

 L1949: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1950;
    }
  goto L12088;

 L1950: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1951;
    }
  goto L12088;

 L1951: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (mask_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1952;
    }
  goto L12088;

 L1952: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], operands[3])))
    {
      return 144;
    }
  x1 = XEXP (x0, 1);
  goto L12088;

 L1008: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (and_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1009;
    }
 L1112: ATTRIBUTE_UNUSED_LABEL
  if (mask_operand_wrap (x2, SImode))
    {
      operands[2] = x2;
      goto L1113;
    }
  goto L12088;

 L1009: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 80;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1112;

 L1113: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 85;
    }
  x1 = XEXP (x0, 1);
  goto L12088;

 L1262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1263;
  goto L12087;

 L1263: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L12111;
  goto L12087;

 L12111: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L1264;
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1285;
    }
 L12113: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1296;
    }
  goto L12087;

 L1264: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1265;
    }
  goto L12087;

 L1265: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1266;
    }
  goto L12087;

 L1266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1267;
  goto L12087;

 L1267: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L1268;
 L1278: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1279;
    }
  goto L12087;

 L1268: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1269;
    }
  x3 = XEXP (x2, 0);
  goto L1278;

 L1269: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 97;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L1278;

 L1279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER))
    {
      return 98;
    }
  goto L12087;

 L1285: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1286;
    }
  x3 = XEXP (x2, 0);
  goto L12113;

 L1286: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1287;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12113;

 L1287: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NOT)
    goto L1288;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12113;

 L1288: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L1289;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12113;

 L1289: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1290;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12113;

 L1290: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 99;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12113;

 L1296: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1297;
    }
  goto L12087;

 L1297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1298;
  goto L12087;

 L1298: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NOT)
    goto L1299;
  goto L12087;

 L1299: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L1300;
  goto L12087;

 L1300: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1301;
    }
  goto L12087;

 L1301: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 100;
    }
  x1 = XEXP (x0, 1);
  goto L12087;

 L1447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1448;
    }
  goto ret0;

 L1448: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1449;
    }
  goto ret0;

 L1449: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const_int_operand (x2, SImode))
    {
      operands[3] = x2;
      return 111;
    }
  goto ret0;

 L1529: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1530;
    }
  goto ret0;

 L1530: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      return 117;
    }
  goto ret0;

 L1708: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1709;
    }
  goto ret0;

 L1709: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1710;
    }
  goto ret0;

 L1710: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 129;
    }
 L1716: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 130;
    }
  goto ret0;

 L1856: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1857;
    }
  goto ret0;

 L1857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1858;
    }
  goto ret0;

 L1858: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 138;
    }
 L1864: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 139;
    }
  goto ret0;

 L2123: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2124;
    }
  goto ret0;

 L2124: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2125;
    }
  goto ret0;

 L2125: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 156;
    }
 L2131: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 157;
    }
  goto ret0;

 L1148: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1149;
    }
  goto L12088;

 L1149: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (logical_operand (x2, SImode))
    {
      operands[2] = x2;
      return 88;
    }
  goto L12088;

 L1182: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NOT)
    goto L1183;
  goto ret0;

 L1183: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1184;
    }
  goto ret0;

 L1184: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12115;
  goto ret0;

 L12115: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L1223;
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      return 91;
    }
  goto ret0;

 L1223: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      return 94;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_5 PARAMS ((rtx, rtx, int *));
static int
recog_5 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L4811;
    case PLUS:
      goto L4825;
    case ASHIFT:
      goto L5409;
    case NEG:
      goto L5568;
    case LSHIFTRT:
      goto L5586;
    case AND:
      goto L6004;
    case UNSPEC:
      goto L12161;
    case EQ:
    case NE:
    case LE:
    case LT:
    case GE:
    case GT:
    case LEU:
    case LTU:
    case GEU:
    case GTU:
    case UNORDERED:
    case ORDERED:
    case UNGE:
    case UNLE:
      goto L12146;
    default:
      goto L12148;
   }
 L12146: ATTRIBUTE_UNUSED_LABEL
  if (scc_comparison_operator (x1, SImode))
    {
      operands[1] = x1;
      goto L5386;
    }
 L12148: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case EQ:
      goto L5442;
    case LE:
      goto L5810;
    case LEU:
      goto L5899;
    case LT:
      goto L6056;
    case LTU:
      goto L6129;
    case GE:
      goto L6211;
    case GEU:
      goto L6300;
    case GT:
      goto L6444;
    case GTU:
      goto L6659;
    default:
     break;
   }
  goto ret0;

 L4811: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4812;
  goto ret0;

 L4812: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4813;
    }
  goto ret0;

 L4813: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MINUS)
    goto L4814;
  goto ret0;

 L4814: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (immediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4815;
    }
  goto ret0;

 L4815: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (immediate_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L4816;
    }
  goto ret0;

 L4816: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ELF && DEFAULT_ABI != ABI_AIX && flag_pic == 2))
    {
      return 374;
    }
  goto ret0;

 L4825: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12163;
  goto ret0;

 L12163: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case EQ:
      goto L5522;
    case LSHIFTRT:
      goto L5625;
    case LE:
      goto L5846;
    case LEU:
      goto L5951;
    case LT:
      goto L6076;
    case LTU:
      goto L6149;
    case GE:
      goto L6247;
    case GEU:
      goto L6339;
    case GT:
      goto L6500;
    case GTU:
      goto L6698;
    case SUBREG:
    case REG:
      goto L12162;
    default:
      goto ret0;
   }
 L12162: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4826;
    }
  goto ret0;

 L5522: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5523;
    }
  goto ret0;

 L5523: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5524;
    }
  goto ret0;

 L5524: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5525;
    }
  goto ret0;

 L5525: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 422;
    }
  goto ret0;

 L5625: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NEG)
    goto L5626;
  goto ret0;

 L5626: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == ABS)
    goto L5627;
  goto ret0;

 L5627: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5628;
    }
  goto ret0;

 L5628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 31LL)
    goto L5629;
  goto ret0;

 L5629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5630;
    }
  goto ret0;

 L5630: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 428;
    }
  goto ret0;

 L5846: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5847;
    }
  goto ret0;

 L5847: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5848;
    }
  goto ret0;

 L5848: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5849;
    }
  goto ret0;

 L5849: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 436;
    }
  goto ret0;

 L5951: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5952;
    }
  goto ret0;

 L5952: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5953;
    }
  goto ret0;

 L5953: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5954;
    }
  goto ret0;

 L5954: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 445;
    }
  goto ret0;

 L6076: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6077;
    }
  goto ret0;

 L6077: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6078;
    }
  goto ret0;

 L6078: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6079;
    }
  goto ret0;

 L6079: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 454;
    }
  goto ret0;

 L6149: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6150;
    }
  goto ret0;

 L6150: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_neg_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6151;
    }
  goto ret0;

 L6151: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6152;
    }
  goto ret0;

 L6152: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 460;
    }
  goto ret0;

 L6247: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6248;
    }
  goto ret0;

 L6248: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6249;
    }
  goto ret0;

 L6249: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6250;
    }
  goto ret0;

 L6250: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 466;
    }
  goto ret0;

 L6339: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6340;
    }
  goto ret0;

 L6340: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_neg_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6341;
    }
  goto ret0;

 L6341: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6342;
    }
  goto ret0;

 L6342: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 474;
    }
  goto ret0;

 L6500: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6501;
    }
  goto ret0;

 L6501: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6502;
 L6595: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6596;
    }
  goto ret0;

 L6502: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6503;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6595;

 L6503: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 487;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6595;

 L6596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6597;
    }
  goto ret0;

 L6597: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 493;
    }
  goto ret0;

 L6698: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6699;
    }
  goto ret0;

 L6699: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6700;
    }
  goto ret0;

 L6700: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6701;
    }
  goto ret0;

 L6701: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 503;
    }
  goto ret0;

 L4826: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 16)
    goto L4827;
  goto ret0;

 L4827: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (immediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L4828;
    }
  goto ret0;

 L4828: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L4829;
    }
  goto ret0;

 L4829: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_DARWIN))
    {
      return 376;
    }
  goto ret0;

 L5409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scc_comparison_operator (x2, SImode))
    {
      operands[1] = x2;
      goto L5410;
    }
  goto ret0;

 L5410: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (cc_reg_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L5411;
    }
  goto ret0;

 L5411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5412;
  goto ret0;

 L5412: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[3] = x2;
      return 416;
    }
  goto ret0;

 L5568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12173;
  goto ret0;

 L12173: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case EQ:
      goto L5569;
    case LE:
      goto L5893;
    case LEU:
      goto L5998;
    case LT:
      goto L6123;
    case LTU:
      goto L6196;
    case GE:
      goto L6294;
    case GEU:
      goto L6386;
    case GT:
      goto L6641;
    case GTU:
      goto L6792;
    default:
     break;
   }
  goto ret0;

 L5569: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5570;
    }
  goto ret0;

 L5570: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5571;
    }
  goto ret0;

 L5571: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 425;
    }
  goto ret0;

 L5893: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5894;
    }
  goto ret0;

 L5894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5895;
    }
  goto ret0;

 L5895: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 439;
    }
  goto ret0;

 L5998: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5999;
    }
  goto ret0;

 L5999: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6000;
    }
  goto ret0;

 L6000: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 448;
    }
  goto ret0;

 L6123: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6124;
    }
  goto ret0;

 L6124: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6125;
    }
  goto ret0;

 L6125: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 457;
    }
  goto ret0;

 L6196: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6197;
    }
  goto ret0;

 L6197: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_neg_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6198;
    }
  goto ret0;

 L6198: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 463;
    }
  goto ret0;

 L6294: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6295;
    }
  goto ret0;

 L6295: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6296;
    }
  goto ret0;

 L6296: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 469;
    }
  goto ret0;

 L6386: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6387;
    }
  goto ret0;

 L6387: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6388;
    }
  goto ret0;

 L6388: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 477;
    }
  goto ret0;

 L6641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6642;
    }
  goto ret0;

 L6642: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (! TARGET_POWERPC64))
    {
      return 496;
    }
 L6654: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6655;
    }
  goto ret0;

 L6655: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 498;
    }
  goto ret0;

 L6792: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6793;
    }
  goto ret0;

 L6793: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6794;
    }
  goto ret0;

 L6794: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 509;
    }
  goto ret0;

 L5586: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NEG)
    goto L5587;
  goto ret0;

 L5587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ABS)
    goto L5588;
  goto ret0;

 L5588: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5589;
    }
  goto ret0;

 L5589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 31LL
      && (! TARGET_POWER && ! TARGET_POWERPC64 && !TARGET_ISEL)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 426;
    }
  goto ret0;

 L6004: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NEG)
    goto L6005;
  goto ret0;

 L6005: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L12182;
  goto ret0;

 L12182: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case LEU:
      goto L6006;
    case GEU:
      goto L6394;
    default:
     break;
   }
  goto ret0;

 L6006: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6007;
    }
  goto ret0;

 L6007: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6008;
    }
  goto ret0;

 L6008: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6009;
    }
  goto ret0;

 L6009: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 449;
    }
  goto ret0;

 L6394: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6395;
    }
  goto ret0;

 L6395: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_neg_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6396;
    }
  goto ret0;

 L6396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6397;
    }
  goto ret0;

 L6397: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 478;
    }
  goto ret0;

 L12161: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 8
      && XINT (x1, 1) == 19)
    goto L7341;
  goto ret0;

 L7341: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 68)
    goto L7342;
  goto ret0;

 L7342: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 69)
    goto L7343;
  goto ret0;

 L7343: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 70)
    goto L7344;
  goto ret0;

 L7344: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 3);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 71)
    goto L7345;
  goto ret0;

 L7345: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 4);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 72)
    goto L7346;
  goto ret0;

 L7346: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 5);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 73)
    goto L7347;
  goto ret0;

 L7347: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 6);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 74)
    goto L7348;
  goto ret0;

 L7348: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 7);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 75)
    {
      return 541;
    }
  goto ret0;

 L5386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (cc_reg_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L5387;
    }
  goto L12148;

 L5387: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL)
    {
      return 413;
    }
  goto L12148;

 L5442: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5443;
    }
  goto ret0;

 L5443: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_cint_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5444;
    }
  goto ret0;

 L5444: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 418;
    }
  goto ret0;

 L5810: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5811;
    }
  goto ret0;

 L5811: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5812;
    }
  goto ret0;

 L5812: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 434;
    }
  goto ret0;

 L5899: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5900;
    }
  goto ret0;

 L5900: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5901;
    }
  goto ret0;

 L5901: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 440;
    }
  goto ret0;

 L6056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6057;
    }
  goto ret0;

 L6057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6058;
    }
  goto ret0;

 L6058: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 452;
    }
  goto ret0;

 L6129: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6130;
    }
  goto ret0;

 L6130: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_neg_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6131;
    }
  goto ret0;

 L6131: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 458;
    }
  goto ret0;

 L6211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6212;
    }
  goto ret0;

 L6212: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6213;
    }
  goto ret0;

 L6213: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 464;
    }
  goto ret0;

 L6300: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6301;
    }
  goto ret0;

 L6301: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_neg_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6302;
    }
  goto ret0;

 L6302: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 470;
    }
  goto ret0;

 L6444: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6445;
    }
  goto ret0;

 L6445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (! TARGET_POWERPC64))
    {
      return 481;
    }
 L6481: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6482;
    }
  goto ret0;

 L6482: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 485;
    }
  goto ret0;

 L6659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6660;
    }
  goto ret0;

 L6660: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6661;
    }
  goto ret0;

 L6661: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 499;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_6 PARAMS ((rtx, rtx, int *));
static int
recog_6 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_CODE (x1))
    {
    case ZERO_EXTRACT:
      goto L1396;
    case REG:
      goto L12063;
    default:
     break;
   }
 L11826: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L194;
    }
 L11828: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 3)
    goto L880;
 L11837: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L2715;
    }
 L11838: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L3694;
    }
 L11849: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L4792;
    }
 L11850: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L4810;
    }
  goto ret0;

 L1396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1397;
    }
  goto ret0;

 L1397: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12065;
  goto ret0;

 L12065: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 1LL)
    goto L2090;
 L12064: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1398;
    }
  goto ret0;

 L2090: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2091;
    }
  x2 = XEXP (x1, 1);
  goto L12064;

 L2091: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12066;
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L12066: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ASHIFTRT:
      goto L2092;
    case LSHIFTRT:
      goto L2100;
    case ZERO_EXTRACT:
      goto L2108;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2092: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2093;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 31LL
      && (TARGET_POWER))
    {
      return 153;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2100: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2101;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 31LL
      && (TARGET_POWER))
    {
      return 154;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2108: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2109;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2109: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL)
    goto L2110;
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L2110: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWER))
    {
      return 155;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 1);
  goto L12064;

 L1398: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1399;
    }
  goto ret0;

 L1399: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12070;
  goto ret0;

 L12070: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ASHIFT:
      goto L1406;
    case ASHIFTRT:
      goto L1415;
    case LSHIFTRT:
      goto L1424;
    case ZERO_EXTRACT:
      goto L1433;
    case SUBREG:
    case REG:
      goto L12069;
    default:
      goto ret0;
   }
 L12069: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, SImode))
    {
      operands[3] = x1;
      return 105;
    }
  goto ret0;

 L1406: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1407;
    }
  goto ret0;

 L1407: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1408;
    }
  goto ret0;

 L1408: ATTRIBUTE_UNUSED_LABEL
  if (((32 - (INTVAL (operands[4]) & 31)) >= INTVAL (operands[1])))
    {
      return 106;
    }
  goto ret0;

 L1415: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1416;
    }
  goto ret0;

 L1416: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1417;
    }
  goto ret0;

 L1417: ATTRIBUTE_UNUSED_LABEL
  if (((32 - (INTVAL (operands[4]) & 31)) >= INTVAL (operands[1])))
    {
      return 107;
    }
  goto ret0;

 L1424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1425;
    }
  goto ret0;

 L1425: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1426;
    }
  goto ret0;

 L1426: ATTRIBUTE_UNUSED_LABEL
  if (((32 - (INTVAL (operands[4]) & 31)) >= INTVAL (operands[1])))
    {
      return 108;
    }
  goto ret0;

 L1433: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1434;
    }
  goto ret0;

 L1434: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1435;
    }
  goto ret0;

 L1435: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const_int_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L1436;
    }
  goto ret0;

 L1436: ATTRIBUTE_UNUSED_LABEL
  if ((INTVAL (operands[4]) >= INTVAL (operands[1])))
    {
      return 109;
    }
  goto ret0;

 L12063: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 0) == 110)
    goto L8721;
  goto L11826;

 L8721: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == UNSPEC_VOLATILE
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 186)
    goto L8722;
  x1 = XEXP (x0, 0);
  goto L11826;

 L8722: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[0] = x2;
      goto L8723;
    }
  x1 = XEXP (x0, 0);
  goto L11826;

 L8723: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 733;
    }
  x1 = XEXP (x0, 0);
  goto L11826;

 L194: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12074;
  x1 = XEXP (x0, 0);
  goto L11828;

 L12074: ATTRIBUTE_UNUSED_LABEL
  tem = recog_4 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L11828;

 L880: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12116;
  x1 = XEXP (x0, 0);
  goto L11837;

 L12116: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case TRUNCATE:
      goto L881;
    case DIV:
      goto L975;
    case UDIV:
      goto L994;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11837;

 L881: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L882;
  x1 = XEXP (x0, 0);
  goto L11837;

 L882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == MULT)
    goto L883;
  x1 = XEXP (x0, 0);
  goto L11837;

 L883: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L884;
  x1 = XEXP (x0, 0);
  goto L11837;

 L884: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 3)
    goto L885;
  x1 = XEXP (x0, 0);
  goto L11837;

 L885: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L886;
  x1 = XEXP (x0, 0);
  goto L11837;

 L886: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 4)
    goto L887;
  x1 = XEXP (x0, 0);
  goto L11837;

 L887: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 32LL
      && (! TARGET_POWER && ! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 74;
    }
  x1 = XEXP (x0, 0);
  goto L11837;

 L975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L976;
  x1 = XEXP (x0, 0);
  goto L11837;

 L976: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 4
      && (! TARGET_POWER && ! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 78;
    }
  x1 = XEXP (x0, 0);
  goto L11837;

 L994: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L995;
  x1 = XEXP (x0, 0);
  goto L11837;

 L995: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 4
      && (! TARGET_POWER && ! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 4;
      return 79;
    }
  x1 = XEXP (x0, 0);
  goto L11837;

 L2715: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12119;
  x1 = XEXP (x0, 0);
  goto L11838;

 L12119: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case TRUNCATE:
      goto L2716;
    case HIGH:
      goto L3678;
    case LO_SUM:
      goto L3683;
    case UNSPEC:
      goto L12124;
    case FIX:
      goto L3823;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2716: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L2717;
  x1 = XEXP (x0, 0);
  goto L11838;

 L2717: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == MULT)
    goto L2718;
  x1 = XEXP (x0, 0);
  goto L11838;

 L2718: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L12125;
  x1 = XEXP (x0, 0);
  goto L11838;

 L12125: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L2719;
    case ZERO_EXTEND:
      goto L2753;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2719: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L2720;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2720: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L2721;
  x1 = XEXP (x0, 0);
  goto L11838;

 L2721: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2722;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L12127;
  x1 = XEXP (x0, 0);
  goto L11838;

 L12127: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x3, 0) == 32LL)
    goto L12129;
  x1 = XEXP (x0, 0);
  goto L11838;

 L12129: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 224;
    }
 L12130: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWER))
    {
      return 225;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2753: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L2754;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2754: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L2755;
  x1 = XEXP (x0, 0);
  goto L11838;

 L2755: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2756;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L2756: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L12131;
  x1 = XEXP (x0, 0);
  goto L11838;

 L12131: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x3, 0) == 32LL)
    goto L12133;
  x1 = XEXP (x0, 0);
  goto L11838;

 L12133: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 226;
    }
 L12134: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWER))
    {
      return 227;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3678: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[1] = x2;
  goto L3679;

 L3679: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ELF && ! TARGET_64BIT))
    {
      return 297;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3683: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3684;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3684: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  goto L3685;

 L3685: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ELF && ! TARGET_64BIT))
    {
      return 298;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L12124: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 8)
    goto L3689;
  x1 = XEXP (x0, 0);
  goto L11838;

 L3689: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (got_no_const_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3690;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3690: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3691;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3691: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_V4 && flag_pic == 1))
    {
      return 299;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3823: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L3824;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3824: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 319;
    }
  x1 = XEXP (x0, 0);
  goto L11838;

 L3694: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L3695;
    }
  x1 = XEXP (x0, 0);
  goto L11849;

 L3695: ATTRIBUTE_UNUSED_LABEL
  if ((gpc_reg_operand (operands[0], SImode)
   || gpc_reg_operand (operands[1], SImode)))
    {
      return 300;
    }
  x1 = XEXP (x0, 0);
  goto L11849;

 L4792: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12135;
  x1 = XEXP (x0, 0);
  goto L11850;

 L12135: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L12138;
  x1 = XEXP (x0, 0);
  goto L11850;

 L12138: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L12141;
  x1 = XEXP (x0, 0);
  goto L11850;

 L12141: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 7LL:
      goto L4793;
    case 15LL:
      goto L4820;
    case 214LL:
      goto L7497;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L11850;

 L4793: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (DEFAULT_ABI == ABI_V4 && flag_pic == 1 && TARGET_32BIT))
    {
      return 371;
    }
  x1 = XEXP (x0, 0);
  goto L11850;

 L4820: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4821;
    }
  x1 = XEXP (x0, 0);
  goto L11850;

 L4821: ATTRIBUTE_UNUSED_LABEL
  if (((DEFAULT_ABI == ABI_DARWIN) && flag_pic))
    {
      return 375;
    }
  x1 = XEXP (x0, 0);
  goto L11850;

 L7497: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 109
      && (TARGET_ALTIVEC))
    {
      return 568;
    }
  x1 = XEXP (x0, 0);
  goto L11850;

 L4810: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12144;
  goto ret0;

 L12144: ATTRIBUTE_UNUSED_LABEL
  return recog_5 (x0, insn, pnum_clobbers);
 ret0:
  return -1;
}

static int recog_7 PARAMS ((rtx, rtx, int *));
static int
recog_7 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case FLOAT_TRUNCATE:
      goto L2220;
    case UNSPEC:
      goto L12221;
    case NEG:
      goto L2230;
    case ABS:
      goto L2235;
    case PLUS:
      goto L2246;
    case MINUS:
      goto L2258;
    case MULT:
      goto L2270;
    case DIV:
      goto L2282;
    case SQRT:
      goto L2396;
    case IF_THEN_ELSE:
      goto L2406;
    case FLOAT:
      goto L2626;
    default:
     break;
   }
  goto ret0;

 L2220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L12222;
    case TFmode:
      goto L12223;
    default:
      break;
    }
  goto ret0;

 L12222: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2221;
    }
  goto ret0;

 L2221: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 163;
    }
  goto ret0;

 L12223: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L3772;
    }
  goto ret0;

 L3772: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT
   && TARGET_FPRS && TARGET_LONG_DOUBLE_128)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 315;
    }
  goto ret0;

 L12221: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 0)
    goto L2225;
  goto ret0;

 L2225: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2226;
    }
  goto ret0;

 L2226: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 164;
    }
  goto ret0;

 L2230: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L12225;
  goto ret0;

 L12225: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L2241;
    case PLUS:
      goto L2327;
    case MINUS:
      goto L2363;
    case SUBREG:
    case REG:
      goto L12224;
    default:
      goto ret0;
   }
 L12224: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2231;
    }
  goto ret0;

 L2241: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L2242;
    }
  goto ret0;

 L2242: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 167;
    }
  goto ret0;

 L2327: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == MULT)
    goto L2328;
  goto ret0;

 L2328: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L2329;
    }
  goto ret0;

 L2329: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L2330;
    }
  goto ret0;

 L2330: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L2331;
    }
  goto ret0;

 L2331: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (SFmode)))
    {
      return 180;
    }
 L2349: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 182;
    }
  goto ret0;

 L2363: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == MULT)
    goto L2364;
  goto ret0;

 L2364: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L2365;
    }
  goto ret0;

 L2365: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L2366;
    }
  goto ret0;

 L2366: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L2367;
    }
  goto ret0;

 L2367: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (SFmode)))
    {
      return 184;
    }
 L2384: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 186;
    }
  goto ret0;

 L2231: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 165;
    }
  goto ret0;

 L2235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2236;
    }
  goto ret0;

 L2236: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 166;
    }
  goto ret0;

 L2246: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L12229;
  goto ret0;

 L12229: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L2295;
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2247;
    }
  goto ret0;

 L2295: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L2296;
    }
  goto ret0;

 L2296: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L2297;
    }
  goto ret0;

 L2297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2298;
    }
  goto ret0;

 L2298: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 176;
    }
 L2306: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 177;
    }
  goto ret0;

 L2247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2248;
    }
  goto ret0;

 L2248: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 168;
    }
 L2254: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 169;
    }
  goto ret0;

 L2258: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L12231;
  goto ret0;

 L12231: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L2311;
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2259;
    }
 L12232: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2372;
    }
  goto ret0;

 L2311: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode)
    goto L12234;
  goto ret0;

 L12234: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L2337;
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L2312;
    }
  goto ret0;

 L2337: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L2338;
    }
  goto ret0;

 L2338: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L2339;
    }
  goto ret0;

 L2339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2340;
    }
  goto ret0;

 L2340: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && ! HONOR_SIGNED_ZEROS (SFmode)))
    {
      return 181;
    }
 L2358: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && ! HONOR_SIGNED_ZEROS (SFmode)))
    {
      return 183;
    }
  goto ret0;

 L2312: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L2313;
    }
  goto ret0;

 L2313: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2314;
    }
  goto ret0;

 L2314: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 178;
    }
 L2322: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 179;
    }
  goto ret0;

 L2259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2260;
    }
  x2 = XEXP (x1, 0);
  goto L12232;

 L2260: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 170;
    }
 L2266: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 171;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L12232;

 L2372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == MULT)
    goto L2373;
  goto ret0;

 L2373: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L2374;
    }
  goto ret0;

 L2374: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L2375;
    }
  goto ret0;

 L2375: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && ! HONOR_SIGNED_ZEROS (SFmode)))
    {
      return 185;
    }
 L2392: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && ! HONOR_SIGNED_ZEROS (SFmode)))
    {
      return 187;
    }
  goto ret0;

 L2270: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2271;
    }
  goto ret0;

 L2271: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2272;
    }
  goto ret0;

 L2272: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 172;
    }
 L2278: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 173;
    }
  goto ret0;

 L2282: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2283;
    }
  goto ret0;

 L2283: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2284;
    }
  goto ret0;

 L2284: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 174;
    }
 L2290: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 175;
    }
  goto ret0;

 L2396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2397;
    }
  goto ret0;

 L2397: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PPC_GPOPT && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 188;
    }
 L2402: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER2 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 189;
    }
  goto ret0;

 L2406: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == GE)
    goto L2407;
  goto ret0;

 L2407: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SFmode:
      goto L12235;
    case DFmode:
      goto L12236;
    default:
      break;
    }
  goto ret0;

 L12235: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L2408;
    }
  goto ret0;

 L2408: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (zero_fp_constant (x3, SFmode))
    {
      operands[4] = x3;
      goto L2409;
    }
  goto ret0;

 L2409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2410;
    }
  goto ret0;

 L2410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2411;
    }
  goto ret0;

 L2411: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PPC_GFXOPT && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 190;
    }
  goto ret0;

 L12236: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2417;
    }
  goto ret0;

 L2417: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (zero_fp_constant (x3, DFmode))
    {
      operands[4] = x3;
      goto L2418;
    }
  goto ret0;

 L2418: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L2419;
    }
  goto ret0;

 L2419: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L2420;
    }
  goto ret0;

 L2420: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PPC_GFXOPT && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 191;
    }
  goto ret0;

 L2626: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2627;
    }
  goto ret0;

 L2627: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 216;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_8 PARAMS ((rtx, rtx, int *));
static int
recog_8 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L12342;
    case 3:
      goto L12352;
    case 1:
      goto L12370;
    default:
      break;
    }
  goto ret0;

 L12342: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 35LL:
      goto L7547;
    case 48LL:
      goto L7650;
    case 49LL:
      goto L7656;
    case 50LL:
      goto L7662;
    case 53LL:
      goto L7680;
    case 54LL:
      goto L7686;
    case 55LL:
      goto L7692;
    case 60LL:
      goto L7722;
    case 61LL:
      goto L7728;
    case 62LL:
      goto L7734;
    case 85LL:
      goto L8035;
    case 86LL:
      goto L8041;
    case 89LL:
      goto L8059;
    case 90LL:
      goto L8065;
    case 106LL:
      goto L8194;
    case 109LL:
      goto L8212;
    case 110LL:
      goto L8224;
    case 111LL:
      goto L8230;
    case 114LL:
      goto L8248;
    case 117LL:
      goto L8266;
    case 118LL:
      goto L8272;
    case 119LL:
      goto L8278;
    case 124LL:
      goto L8308;
    case 138LL:
      goto L8442;
    default:
      break;
    }
  goto ret0;

 L7547: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7548;
    }
  goto ret0;

 L7548: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7549;
    }
  goto ret0;

 L7549: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 578;
    }
  goto ret0;

 L7650: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7651;
    }
  goto ret0;

 L7651: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7652;
    }
  goto ret0;

 L7652: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 591;
    }
  goto ret0;

 L7656: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7657;
    }
  goto ret0;

 L7657: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7658;
    }
  goto ret0;

 L7658: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 592;
    }
  goto ret0;

 L7662: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L7663;
    }
  goto ret0;

 L7663: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L7664;
    }
  goto ret0;

 L7664: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 593;
    }
  goto ret0;

 L7680: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7681;
    }
  goto ret0;

 L7681: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7682;
    }
  goto ret0;

 L7682: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 596;
    }
  goto ret0;

 L7686: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L7687;
    }
  goto ret0;

 L7687: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L7688;
    }
  goto ret0;

 L7688: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 597;
    }
  goto ret0;

 L7692: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L7693;
    }
  goto ret0;

 L7693: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L7694;
    }
  goto ret0;

 L7694: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 598;
    }
  goto ret0;

 L7722: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7723;
    }
  goto ret0;

 L7723: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7724;
    }
  goto ret0;

 L7724: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 603;
    }
  goto ret0;

 L7728: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7729;
    }
  goto ret0;

 L7729: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7730;
    }
  goto ret0;

 L7730: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 604;
    }
  goto ret0;

 L7734: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L7735;
    }
  goto ret0;

 L7735: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L7736;
    }
  goto ret0;

 L7736: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 605;
    }
  goto ret0;

 L8035: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8036;
    }
  goto ret0;

 L8036: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8037;
    }
  goto ret0;

 L8037: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 639;
    }
  goto ret0;

 L8041: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8042;
    }
  goto ret0;

 L8042: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8043;
    }
  goto ret0;

 L8043: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 640;
    }
  goto ret0;

 L8059: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8060;
    }
  goto ret0;

 L8060: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8061;
    }
  goto ret0;

 L8061: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 643;
    }
  goto ret0;

 L8065: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8066;
    }
  goto ret0;

 L8066: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8067;
    }
  goto ret0;

 L8067: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 644;
    }
  goto ret0;

 L8194: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8195;
    }
  goto ret0;

 L8195: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8196;
    }
  goto ret0;

 L8196: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 660;
    }
  goto ret0;

 L8212: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8213;
    }
  goto ret0;

 L8213: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8214;
    }
  goto ret0;

 L8214: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 663;
    }
  goto ret0;

 L8224: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8225;
    }
  goto ret0;

 L8225: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8226;
    }
  goto ret0;

 L8226: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 665;
    }
  goto ret0;

 L8230: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8231;
    }
  goto ret0;

 L8231: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8232;
    }
  goto ret0;

 L8232: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 666;
    }
  goto ret0;

 L8248: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8249;
    }
  goto ret0;

 L8249: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8250;
    }
  goto ret0;

 L8250: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 669;
    }
  goto ret0;

 L8266: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8267;
    }
  goto ret0;

 L8267: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8268;
    }
  goto ret0;

 L8268: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 672;
    }
  goto ret0;

 L8272: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8273;
    }
  goto ret0;

 L8273: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8274;
    }
  goto ret0;

 L8274: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 673;
    }
  goto ret0;

 L8278: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8279;
    }
  goto ret0;

 L8279: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8280;
    }
  goto ret0;

 L8280: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 674;
    }
  goto ret0;

 L8308: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8309;
    }
  goto ret0;

 L8309: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8310;
    }
  goto ret0;

 L8310: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 679;
    }
  goto ret0;

 L8442: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8443;
    }
  goto ret0;

 L8443: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L8444;
    }
  goto ret0;

 L8444: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 694;
    }
  goto ret0;

 L12352: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 65LL:
      goto L7756;
    case 66LL:
      goto L7763;
    case 67LL:
      goto L7770;
    case 68LL:
      goto L7777;
    case 144LL:
      goto L8473;
    case 159LL:
      goto L8568;
    case 163LL:
      goto L8596;
    default:
      break;
    }
  goto ret0;

 L7756: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7757;
    }
  goto ret0;

 L7757: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7758;
    }
  goto ret0;

 L7758: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L7759;
    }
  goto ret0;

 L7759: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 608;
    }
  goto ret0;

 L7763: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7764;
    }
  goto ret0;

 L7764: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7765;
    }
  goto ret0;

 L7765: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L7766;
    }
  goto ret0;

 L7766: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 609;
    }
  goto ret0;

 L7770: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7771;
    }
  goto ret0;

 L7771: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7772;
    }
  goto ret0;

 L7772: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L7773;
    }
  goto ret0;

 L7773: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 610;
    }
  goto ret0;

 L7777: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7778;
    }
  goto ret0;

 L7778: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7779;
    }
  goto ret0;

 L7779: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L7780;
    }
  goto ret0;

 L7780: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 611;
    }
  goto ret0;

 L8473: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8474;
    }
  goto ret0;

 L8474: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8475;
    }
  goto ret0;

 L8475: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8476;
    }
  goto ret0;

 L8476: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 700;
    }
  goto ret0;

 L8568: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8569;
    }
  goto ret0;

 L8569: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8570;
    }
  goto ret0;

 L8570: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L8571;
    }
  goto ret0;

 L8571: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 715;
    }
  goto ret0;

 L8596: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8597;
    }
  goto ret0;

 L8597: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8598;
    }
  goto ret0;

 L8598: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (immediate_operand (x2, QImode))
    {
      operands[3] = x2;
      goto L8599;
    }
  goto ret0;

 L8599: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 719;
    }
  goto ret0;

 L12370: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 141LL:
      goto L8458;
    case 168LL:
      goto L8629;
    case 169LL:
      goto L8634;
    case 171LL:
      goto L8644;
    case 172LL:
      goto L8649;
    case 212LL:
      goto L8968;
    default:
      break;
    }
  goto ret0;

 L8458: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (immediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L8459;
    }
  goto ret0;

 L8459: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 697;
    }
  goto ret0;

 L8629: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8630;
    }
  goto ret0;

 L8630: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 724;
    }
  goto ret0;

 L8634: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8635;
    }
  goto ret0;

 L8635: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 725;
    }
  goto ret0;

 L8644: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8645;
    }
  goto ret0;

 L8645: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 727;
    }
  goto ret0;

 L8649: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8650;
    }
  goto ret0;

 L8650: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 728;
    }
  goto ret0;

 L8968: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8969;
    }
  goto ret0;

 L8969: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 759;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_9 PARAMS ((rtx, rtx, int *));
static int
recog_9 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L7529;
    case UNSPEC:
      goto L12416;
    case UMAX:
      goto L7818;
    case SMAX:
      goto L7824;
    case VEC_MERGE:
      goto L7901;
    case UMIN:
      goto L7993;
    case SMIN:
      goto L7999;
    case MINUS:
      goto L8290;
    case UNSPEC_VOLATILE:
      goto L12439;
    case ABS:
      goto L8893;
    default:
     break;
   }
  goto ret0;

 L7529: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7530;
    }
  goto ret0;

 L7530: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7531;
    }
  goto ret0;

 L7531: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 575;
    }
  goto ret0;

 L12416: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L12441;
    case 3:
      goto L12446;
    case 1:
      goto L12458;
    default:
      break;
    }
  goto ret0;

 L12441: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 46LL:
      goto L7638;
    case 47LL:
      goto L7644;
    case 52LL:
      goto L7674;
    case 58LL:
      goto L7710;
    case 59LL:
      goto L7716;
    case 83LL:
      goto L8023;
    case 84LL:
      goto L8029;
    case 87LL:
      goto L8047;
    case 88LL:
      goto L8053;
    case 94LL:
      goto L8090;
    case 95LL:
      goto L8096;
    case 105LL:
      goto L8188;
    case 108LL:
      goto L8206;
    case 113LL:
      goto L8242;
    case 116LL:
      goto L8260;
    case 137LL:
      goto L8436;
    default:
      break;
    }
  goto ret0;

 L7638: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7639;
    }
  goto ret0;

 L7639: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7640;
    }
  goto ret0;

 L7640: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 589;
    }
  goto ret0;

 L7644: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7645;
    }
  goto ret0;

 L7645: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7646;
    }
  goto ret0;

 L7646: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 590;
    }
  goto ret0;

 L7674: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7675;
    }
  goto ret0;

 L7675: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7676;
    }
  goto ret0;

 L7676: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 595;
    }
  goto ret0;

 L7710: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7711;
    }
  goto ret0;

 L7711: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7712;
    }
  goto ret0;

 L7712: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 601;
    }
  goto ret0;

 L7716: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7717;
    }
  goto ret0;

 L7717: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7718;
    }
  goto ret0;

 L7718: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 602;
    }
  goto ret0;

 L8023: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8024;
    }
  goto ret0;

 L8024: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8025;
    }
  goto ret0;

 L8025: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 637;
    }
  goto ret0;

 L8029: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8030;
    }
  goto ret0;

 L8030: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8031;
    }
  goto ret0;

 L8031: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 638;
    }
  goto ret0;

 L8047: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8048;
    }
  goto ret0;

 L8048: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8049;
    }
  goto ret0;

 L8049: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 641;
    }
  goto ret0;

 L8053: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8054;
    }
  goto ret0;

 L8054: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8055;
    }
  goto ret0;

 L8055: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 642;
    }
  goto ret0;

 L8090: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8091;
    }
  goto ret0;

 L8091: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8092;
    }
  goto ret0;

 L8092: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 648;
    }
  goto ret0;

 L8096: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8097;
    }
  goto ret0;

 L8097: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8098;
    }
  goto ret0;

 L8098: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 649;
    }
  goto ret0;

 L8188: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8189;
    }
  goto ret0;

 L8189: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8190;
    }
  goto ret0;

 L8190: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 659;
    }
  goto ret0;

 L8206: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8207;
    }
  goto ret0;

 L8207: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8208;
    }
  goto ret0;

 L8208: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 662;
    }
  goto ret0;

 L8242: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8243;
    }
  goto ret0;

 L8243: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8244;
    }
  goto ret0;

 L8244: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 668;
    }
  goto ret0;

 L8260: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8261;
    }
  goto ret0;

 L8261: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8262;
    }
  goto ret0;

 L8262: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 671;
    }
  goto ret0;

 L8436: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8437;
    }
  goto ret0;

 L8437: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L8438;
    }
  goto ret0;

 L8438: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 693;
    }
  goto ret0;

 L12446: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 73LL:
      goto L7870;
    case 146LL:
      goto L8487;
    case 161LL:
      goto L8582;
    case 165LL:
      goto L8610;
    default:
      break;
    }
  goto ret0;

 L7870: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7871;
    }
  goto ret0;

 L7871: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7872;
    }
  goto ret0;

 L7872: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V8HImode))
    {
      operands[3] = x2;
      goto L7873;
    }
  goto ret0;

 L7873: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 623;
    }
  goto ret0;

 L8487: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8488;
    }
  goto ret0;

 L8488: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8489;
    }
  goto ret0;

 L8489: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8490;
    }
  goto ret0;

 L8490: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 702;
    }
  goto ret0;

 L8582: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8583;
    }
  goto ret0;

 L8583: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8584;
    }
  goto ret0;

 L8584: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V8HImode))
    {
      operands[3] = x2;
      goto L8585;
    }
  goto ret0;

 L8585: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 717;
    }
  goto ret0;

 L8610: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8611;
    }
  goto ret0;

 L8611: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8612;
    }
  goto ret0;

 L8612: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (immediate_operand (x2, QImode))
    {
      operands[3] = x2;
      goto L8613;
    }
  goto ret0;

 L8613: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 721;
    }
  goto ret0;

 L12458: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 140LL:
      goto L8453;
    case 167LL:
      goto L8624;
    case 170LL:
      goto L8639;
    case 211LL:
      goto L8953;
    default:
      break;
    }
  goto ret0;

 L8453: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (immediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L8454;
    }
  goto ret0;

 L8454: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 696;
    }
  goto ret0;

 L8624: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8625;
    }
  goto ret0;

 L8625: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 723;
    }
  goto ret0;

 L8639: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8640;
    }
  goto ret0;

 L8640: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 726;
    }
  goto ret0;

 L8953: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8954;
    }
  goto ret0;

 L8954: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 758;
    }
  goto ret0;

 L7818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7819;
    }
  goto ret0;

 L7819: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7820;
    }
  goto ret0;

 L7820: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 616;
    }
  goto ret0;

 L7824: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7825;
    }
  goto ret0;

 L7825: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7826;
    }
  goto ret0;

 L7826: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 617;
    }
  goto ret0;

 L7901: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L7902;
  goto ret0;

 L7902: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V8HImode)
    goto L12465;
  goto ret0;

 L12465: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7903;
    }
 L12466: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7955;
    }
  goto ret0;

 L7903: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L7904;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7904: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L7905;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7905: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L7906;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7906: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L7907;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7907: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L7908;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7908: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7909;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7909: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7910;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7910: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L7911;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7911: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L7912;
  x3 = XEXP (x2, 0);
  goto L12466;

 L7912: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7913;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12466;

 L7913: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 15LL
      && (TARGET_ALTIVEC))
    {
      return 625;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12466;

 L7955: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L7956;
  goto ret0;

 L7956: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7957;
  goto ret0;

 L7957: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7958;
  goto ret0;

 L7958: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L7959;
  goto ret0;

 L7959: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L7960;
  goto ret0;

 L7960: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L7961;
  goto ret0;

 L7961: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L7962;
  goto ret0;

 L7962: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L7963;
  goto ret0;

 L7963: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L7964;
  goto ret0;

 L7964: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7965;
    }
  goto ret0;

 L7965: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 15LL
      && (TARGET_ALTIVEC))
    {
      return 628;
    }
  goto ret0;

 L7993: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L7994;
    }
  goto ret0;

 L7994: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L7995;
    }
  goto ret0;

 L7995: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 632;
    }
  goto ret0;

 L7999: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8000;
    }
  goto ret0;

 L8000: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8001;
    }
  goto ret0;

 L8001: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 633;
    }
  goto ret0;

 L8290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8291;
    }
  goto ret0;

 L8291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8292;
    }
  goto ret0;

 L8292: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 676;
    }
  goto ret0;

 L12439: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 187)
    goto L8727;
  goto ret0;

 L8727: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110
      && (TARGET_ALTIVEC))
    {
      return 734;
    }
  goto ret0;

 L8893: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8894;
    }
  goto ret0;

 L8894: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 754;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_10 PARAMS ((rtx, rtx, int *));
static int
recog_10 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L7523;
    case UNSPEC:
      goto L12493;
    case UMAX:
      goto L7806;
    case SMAX:
      goto L7812;
    case VEC_MERGE:
      goto L7877;
    case UMIN:
      goto L7981;
    case SMIN:
      goto L7987;
    case MINUS:
      goto L8284;
    case ABS:
      goto L8878;
    default:
     break;
   }
  goto ret0;

 L7523: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7524;
    }
  goto ret0;

 L7524: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7525;
    }
  goto ret0;

 L7525: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 574;
    }
  goto ret0;

 L12493: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L12511;
    case 1:
      goto L12522;
    case 3:
      goto L12523;
    default:
      break;
    }
  goto ret0;

 L12511: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 44LL:
      goto L7626;
    case 45LL:
      goto L7632;
    case 51LL:
      goto L7668;
    case 56LL:
      goto L7698;
    case 57LL:
      goto L7704;
    case 93LL:
      goto L8084;
    case 104LL:
      goto L8182;
    case 107LL:
      goto L8200;
    case 112LL:
      goto L8236;
    case 115LL:
      goto L8254;
    case 136LL:
      goto L8430;
    case 194LL:
      goto L8756;
    case 195LL:
      goto L8762;
    default:
      break;
    }
  goto ret0;

 L7626: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7627;
    }
  goto ret0;

 L7627: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7628;
    }
  goto ret0;

 L7628: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 587;
    }
  goto ret0;

 L7632: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7633;
    }
  goto ret0;

 L7633: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7634;
    }
  goto ret0;

 L7634: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 588;
    }
  goto ret0;

 L7668: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7669;
    }
  goto ret0;

 L7669: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7670;
    }
  goto ret0;

 L7670: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 594;
    }
  goto ret0;

 L7698: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7699;
    }
  goto ret0;

 L7699: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7700;
    }
  goto ret0;

 L7700: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 599;
    }
  goto ret0;

 L7704: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7705;
    }
  goto ret0;

 L7705: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7706;
    }
  goto ret0;

 L7706: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 600;
    }
  goto ret0;

 L8084: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8085;
    }
  goto ret0;

 L8085: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8086;
    }
  goto ret0;

 L8086: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 647;
    }
  goto ret0;

 L8182: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8183;
    }
  goto ret0;

 L8183: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8184;
    }
  goto ret0;

 L8184: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 658;
    }
  goto ret0;

 L8200: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8201;
    }
  goto ret0;

 L8201: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8202;
    }
  goto ret0;

 L8202: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 661;
    }
  goto ret0;

 L8236: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8237;
    }
  goto ret0;

 L8237: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8238;
    }
  goto ret0;

 L8238: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 667;
    }
  goto ret0;

 L8254: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8255;
    }
  goto ret0;

 L8255: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8256;
    }
  goto ret0;

 L8256: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 670;
    }
  goto ret0;

 L8430: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8431;
    }
  goto ret0;

 L8431: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L8432;
    }
  goto ret0;

 L8432: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 692;
    }
  goto ret0;

 L8756: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L8757;
    }
  goto ret0;

 L8757: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L8758;
    }
  goto ret0;

 L8758: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 741;
    }
  goto ret0;

 L8762: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L8763;
    }
  goto ret0;

 L8763: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L8764;
    }
  goto ret0;

 L8764: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 742;
    }
  goto ret0;

 L12522: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 139LL:
      goto L8448;
    case 210LL:
      goto L8938;
    default:
      break;
    }
  goto ret0;

 L8448: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (immediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L8449;
    }
  goto ret0;

 L8449: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 695;
    }
  goto ret0;

 L8938: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8939;
    }
  goto ret0;

 L8939: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 757;
    }
  goto ret0;

 L12523: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 147LL:
      goto L8494;
    case 162LL:
      goto L8589;
    case 166LL:
      goto L8617;
    default:
      break;
    }
  goto ret0;

 L8494: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8495;
    }
  goto ret0;

 L8495: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8496;
    }
  goto ret0;

 L8496: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8497;
    }
  goto ret0;

 L8497: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 703;
    }
  goto ret0;

 L8589: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8590;
    }
  goto ret0;

 L8590: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8591;
    }
  goto ret0;

 L8591: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8592;
    }
  goto ret0;

 L8592: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 718;
    }
  goto ret0;

 L8617: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8618;
    }
  goto ret0;

 L8618: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8619;
    }
  goto ret0;

 L8619: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (immediate_operand (x2, QImode))
    {
      operands[3] = x2;
      goto L8620;
    }
  goto ret0;

 L8620: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 722;
    }
  goto ret0;

 L7806: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7807;
    }
  goto ret0;

 L7807: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7808;
    }
  goto ret0;

 L7808: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 614;
    }
  goto ret0;

 L7812: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7813;
    }
  goto ret0;

 L7813: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7814;
    }
  goto ret0;

 L7814: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 615;
    }
  goto ret0;

 L7877: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V16QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L7878;
  goto ret0;

 L7878: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V16QImode)
    goto L12529;
  goto ret0;

 L12529: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L7879;
    }
 L12530: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L7931;
    }
  goto ret0;

 L7879: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 16)
    goto L7880;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7880: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L7881;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7881: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 9LL)
    goto L7882;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7882: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 10LL)
    goto L7883;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7883: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 11LL)
    goto L7884;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7884: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L7885;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7885: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 13LL)
    goto L7886;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7886: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 14LL)
    goto L7887;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7887: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 15LL)
    goto L7888;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7888: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7889;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7889: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7890;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7890: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L7891;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7891: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L7892;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7892: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L7893;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7893: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L7894;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7894: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L7895;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7895: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L7896;
  x3 = XEXP (x2, 0);
  goto L12530;

 L7896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7897;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12530;

 L7897: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 255LL
      && (TARGET_ALTIVEC))
    {
      return 624;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12530;

 L7931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 16)
    goto L7932;
  goto ret0;

 L7932: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7933;
  goto ret0;

 L7933: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7934;
  goto ret0;

 L7934: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L7935;
  goto ret0;

 L7935: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L7936;
  goto ret0;

 L7936: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L7937;
  goto ret0;

 L7937: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L7938;
  goto ret0;

 L7938: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L7939;
  goto ret0;

 L7939: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L7940;
  goto ret0;

 L7940: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L7941;
  goto ret0;

 L7941: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 9LL)
    goto L7942;
  goto ret0;

 L7942: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 10LL)
    goto L7943;
  goto ret0;

 L7943: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 11LL)
    goto L7944;
  goto ret0;

 L7944: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L7945;
  goto ret0;

 L7945: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 13LL)
    goto L7946;
  goto ret0;

 L7946: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 14LL)
    goto L7947;
  goto ret0;

 L7947: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 15LL)
    goto L7948;
  goto ret0;

 L7948: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7949;
    }
  goto ret0;

 L7949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 255LL
      && (TARGET_ALTIVEC))
    {
      return 627;
    }
  goto ret0;

 L7981: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7982;
    }
  goto ret0;

 L7982: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7983;
    }
  goto ret0;

 L7983: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 630;
    }
  goto ret0;

 L7987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L7988;
    }
  goto ret0;

 L7988: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L7989;
    }
  goto ret0;

 L7989: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 631;
    }
  goto ret0;

 L8284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8285;
    }
  goto ret0;

 L8285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8286;
    }
  goto ret0;

 L8286: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 675;
    }
  goto ret0;

 L8878: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8879;
    }
  goto ret0;

 L8879: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 753;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_11 PARAMS ((rtx, rtx, int *));
static int
recog_11 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  if (altivec_register_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L7460;
    }
  if (memory_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L7476;
    }
 L11866: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L7492;
    }
 L11868: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L7510;
    }
 L11874: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L7540;
    }
  goto ret0;

 L7460: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L7461;
    }
  x1 = XEXP (x0, 0);
  goto L11866;

 L7461: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 559;
    }
  x1 = XEXP (x0, 0);
  goto L11866;

 L7476: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (altivec_register_operand (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L7477;
    }
  x1 = XEXP (x0, 0);
  goto L11866;

 L7477: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 563;
    }
  x1 = XEXP (x0, 0);
  goto L11866;

 L7492: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L7493;
    }
  x1 = XEXP (x0, 0);
  goto L11868;

 L7493: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 567;
    }
  x1 = XEXP (x0, 0);
  goto L11868;

 L7510: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (zero_constant (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L7511;
    }
  x1 = XEXP (x0, 0);
  goto L11874;

 L7511: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 571;
    }
  x1 = XEXP (x0, 0);
  goto L11874;

 L7540: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SFmode)
    goto L12531;
  goto ret0;

 L12531: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L7541;
    case MINUS:
      goto L7748;
    case SMAX:
      goto L7842;
    case SMIN:
      goto L8017;
    case UNSPEC:
      goto L12551;
    case FIX:
      goto L8468;
    case ABS:
      goto L8923;
    default:
     break;
   }
  goto ret0;

 L7541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SFmode)
    goto L12566;
  goto ret0;

 L12566: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L7741;
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L7542;
    }
  goto ret0;

 L7741: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L7742;
    }
  goto ret0;

 L7742: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L7743;
    }
  goto ret0;

 L7743: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[3] = x2;
      goto L7744;
    }
  goto ret0;

 L7744: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 606;
    }
  goto ret0;

 L7542: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L7543;
    }
  goto ret0;

 L7543: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 577;
    }
  goto ret0;

 L7748: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SFmode)
    goto L12567;
  goto ret0;

 L12567: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L7749;
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8303;
    }
  goto ret0;

 L7749: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L7750;
    }
  goto ret0;

 L7750: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L7751;
    }
  goto ret0;

 L7751: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[3] = x2;
      goto L7752;
    }
  goto ret0;

 L7752: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 607;
    }
  goto ret0;

 L8303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8304;
    }
  goto ret0;

 L8304: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 678;
    }
  goto ret0;

 L7842: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L7843;
    }
  goto ret0;

 L7843: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L7844;
    }
  goto ret0;

 L7844: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 620;
    }
  goto ret0;

 L8017: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8018;
    }
  goto ret0;

 L8018: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8019;
    }
  goto ret0;

 L8019: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 636;
    }
  goto ret0;

 L12551: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L12569;
    case 1:
      goto L12570;
    case 3:
      goto L12571;
    default:
      break;
    }
  goto ret0;

 L12569: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 109LL:
      goto L8218;
    case 151LL:
      goto L8516;
    case 152LL:
      goto L8522;
    default:
      break;
    }
  goto ret0;

 L8218: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8219;
    }
  goto ret0;

 L8219: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8220;
    }
  goto ret0;

 L8220: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 664;
    }
  goto ret0;

 L8516: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8517;
    }
  goto ret0;

 L8517: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L8518;
    }
  goto ret0;

 L8518: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 707;
    }
  goto ret0;

 L8522: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8523;
    }
  goto ret0;

 L8523: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L8524;
    }
  goto ret0;

 L8524: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 708;
    }
  goto ret0;

 L12570: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 142LL:
      goto L8463;
    case 148LL:
      goto L8501;
    case 149LL:
      goto L8506;
    case 150LL:
      goto L8511;
    case 155LL:
      goto L8548;
    case 156LL:
      goto L8553;
    case 157LL:
      goto L8558;
    case 158LL:
      goto L8563;
    default:
      break;
    }
  goto ret0;

 L8463: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (immediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L8464;
    }
  goto ret0;

 L8464: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 698;
    }
  goto ret0;

 L8501: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8502;
    }
  goto ret0;

 L8502: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 704;
    }
  goto ret0;

 L8506: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8507;
    }
  goto ret0;

 L8507: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 705;
    }
  goto ret0;

 L8511: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8512;
    }
  goto ret0;

 L8512: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 706;
    }
  goto ret0;

 L8548: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8549;
    }
  goto ret0;

 L8549: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 711;
    }
  goto ret0;

 L8553: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8554;
    }
  goto ret0;

 L8554: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 712;
    }
  goto ret0;

 L8558: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8559;
    }
  goto ret0;

 L8559: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 713;
    }
  goto ret0;

 L8563: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8564;
    }
  goto ret0;

 L8564: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 714;
    }
  goto ret0;

 L12571: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 145LL:
      goto L8480;
    case 160LL:
      goto L8575;
    case 164LL:
      goto L8603;
    default:
      break;
    }
  goto ret0;

 L8480: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8481;
    }
  goto ret0;

 L8481: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8482;
    }
  goto ret0;

 L8482: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8483;
    }
  goto ret0;

 L8483: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 701;
    }
  goto ret0;

 L8575: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8576;
    }
  goto ret0;

 L8576: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8577;
    }
  goto ret0;

 L8577: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (register_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L8578;
    }
  goto ret0;

 L8578: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 716;
    }
  goto ret0;

 L8603: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8604;
    }
  goto ret0;

 L8604: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8605;
    }
  goto ret0;

 L8605: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (immediate_operand (x2, QImode))
    {
      operands[3] = x2;
      goto L8606;
    }
  goto ret0;

 L8606: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 720;
    }
  goto ret0;

 L8468: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8469;
    }
  goto ret0;

 L8469: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 699;
    }
  goto ret0;

 L8923: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8924;
    }
  goto ret0;

 L8924: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 756;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_12 PARAMS ((rtx, rtx, int *));
static int
recog_12 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case DImode:
      goto L11829;
    case CCmode:
      goto L11875;
    case SImode:
      goto L11831;
    case HImode:
      goto L11827;
    case DFmode:
      goto L11834;
    case SFmode:
      goto L11835;
    case QImode:
      goto L11840;
    case TFmode:
      goto L11844;
    case TImode:
      goto L11847;
    case CCUNSmode:
      goto L11851;
    case CCFPmode:
      goto L11852;
    case CCEQmode:
      goto L11853;
    case BLKmode:
      goto L11854;
    case V4SImode:
      goto L11855;
    case V8HImode:
      goto L11856;
    case V16QImode:
      goto L11857;
    case V4SFmode:
      goto L11858;
    default:
      break;
    }
 L6803: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == PC)
    goto L6882;
  goto ret0;

 L11829: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case REG:
      goto L11877;
    case ZERO_EXTRACT:
      goto L1439;
    default:
     break;
   }
 L11824: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L2;
    }
 L11846: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L3843;
    }
  goto L6803;

 L11877: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 0) == 3)
    goto L902;
  goto L11824;

 L902: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == MULT)
    goto L903;
  x1 = XEXP (x0, 0);
  goto L11824;

 L903: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L904;
  x1 = XEXP (x0, 0);
  goto L11824;

 L904: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L905;
  x1 = XEXP (x0, 0);
  goto L11824;

 L905: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L906;
  x1 = XEXP (x0, 0);
  goto L11824;

 L906: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4
      && (! TARGET_POWER && ! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 75;
    }
  x1 = XEXP (x0, 0);
  goto L11824;

 L1439: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1440;
    }
  goto L6803;

 L1440: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1441;
    }
  goto L6803;

 L1441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1442;
    }
  goto L6803;

 L1442: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (gpc_reg_operand (x1, DImode))
    {
      operands[3] = x1;
      goto L1443;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L1443: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 110;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L2: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L11878;
  x1 = XEXP (x0, 0);
  goto L11846;

 L11878: ATTRIBUTE_UNUSED_LABEL
  tem = recog_1 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L11846;

 L3843: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L3844;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3844: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64
   && (gpc_reg_operand (operands[0], DImode)
       || gpc_reg_operand (operands[1], DImode))))
    {
      return 323;
    }
 L3848: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64
   && (gpc_reg_operand (operands[0], DImode)
       || gpc_reg_operand (operands[1], DImode))))
    {
      return 324;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11875: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 74)
    goto L8663;
 L11825: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x1, CCmode))
    {
      operands[0] = x1;
      goto L17;
    }
 L11830: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x1, CCmode))
    {
      operands[2] = x1;
      goto L1127;
    }
 L11833: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, CCmode))
    {
      operands[0] = x1;
      goto L1505;
    }
 L11841: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, CCmode))
    {
      operands[0] = x1;
      goto L3715;
    }
  goto L6803;

 L8663: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCmode)
    goto L11940;
  x1 = XEXP (x0, 0);
  goto L11825;

 L11940: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L11943;
  x1 = XEXP (x0, 0);
  goto L11825;

 L11943: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 3)
    goto L11946;
  x1 = XEXP (x0, 0);
  goto L11825;

 L11946: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 173LL:
      goto L8664;
    case 174LL:
      goto L8681;
    case 175LL:
      goto L8698;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8664: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8665;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8665: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8666;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8666: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (any_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L8667;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8667: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 729;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8681: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8682;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8682: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8683;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8683: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (any_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L8684;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8684: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 730;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8698: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case V8HImode:
      goto L11949;
    case V16QImode:
      goto L11950;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L11949: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L8699;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8699: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8700;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8700: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (any_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L8701;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8701: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 731;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L11950: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L8716;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8716: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8717;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8717: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (any_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L8718;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L8718: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 732;
    }
  x1 = XEXP (x0, 0);
  goto L11825;

 L17: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCmode)
    goto L11951;
  x1 = XEXP (x0, 0);
  goto L11830;

 L11951: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case COMPARE:
      goto L18;
    case UNSPEC:
      goto L11953;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11830;

 L18: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L11954;
    case SImode:
      goto L11956;
    case HImode:
      goto L11958;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L11954: ATTRIBUTE_UNUSED_LABEL
  tem = recog_2 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L11830;

 L11956: ATTRIBUTE_UNUSED_LABEL
  tem = recog_3 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L11830;

 L11958: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L271;
    case SIGN_EXTEND:
      goto L303;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11830;

 L271: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L272;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 25;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L303: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L304;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L304: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 28;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L11953: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 20)
    goto L7385;
  x1 = XEXP (x0, 0);
  goto L11830;

 L7385: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7386;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L7386: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L7387;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L7387: ATTRIBUTE_UNUSED_LABEL
  if ((GET_CODE (operands[0]) == REG 
   && CR_REGNO_P (REGNO (operands[0]))
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) == 1 << (75 - REGNO (operands[0]))))
    {
      return 547;
    }
  x1 = XEXP (x0, 0);
  goto L11830;

 L1127: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCmode
      && GET_CODE (x1) == COMPARE)
    goto L1128;
  x1 = XEXP (x0, 0);
  goto L11833;

 L1128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1129;
  x1 = XEXP (x0, 0);
  goto L11833;

 L1129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L1130;
    }
  x1 = XEXP (x0, 0);
  goto L11833;

 L1130: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (mask_operand_wrap (x3, SImode))
    {
      operands[1] = x3;
      goto L1131;
    }
  x1 = XEXP (x0, 0);
  goto L11833;

 L1131: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 86;
    }
  x1 = XEXP (x0, 0);
  goto L11833;

 L1505: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCmode
      && GET_CODE (x1) == COMPARE)
    goto L1506;
  x1 = XEXP (x0, 0);
  goto L11841;

 L1506: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1507;
  x1 = XEXP (x0, 0);
  goto L11841;

 L1507: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1508;
    }
  x1 = XEXP (x0, 0);
  goto L11841;

 L1508: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1509;
    }
  x1 = XEXP (x0, 0);
  goto L11841;

 L1509: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1510;
    }
  x1 = XEXP (x0, 0);
  goto L11841;

 L1510: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 115;
    }
  x1 = XEXP (x0, 0);
  goto L11841;

 L3715: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonimmediate_operand (x1, CCmode))
    {
      operands[1] = x1;
      goto L3716;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3716: ATTRIBUTE_UNUSED_LABEL
  if ((register_operand (operands[0], CCmode)
   || register_operand (operands[1], CCmode)))
    {
      return 304;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11831: ATTRIBUTE_UNUSED_LABEL
  tem = recog_6 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L6803;

 L11827: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L256;
    }
 L11839: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L3707;
    }
  goto L6803;

 L256: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L12184;
  x1 = XEXP (x0, 0);
  goto L11839;

 L12184: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L257;
    case SIGN_EXTEND:
      goto L287;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11839;

 L257: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (reg_or_mem_operand (x2, QImode))
    {
      operands[1] = x2;
      return 24;
    }
  x1 = XEXP (x0, 0);
  goto L11839;

 L287: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L288;
    }
  x1 = XEXP (x0, 0);
  goto L11839;

 L288: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC))
    {
      return 27;
    }
  x1 = XEXP (x0, 0);
  goto L11839;

 L3707: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L3708;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3708: ATTRIBUTE_UNUSED_LABEL
  if ((gpc_reg_operand (operands[0], HImode)
   || gpc_reg_operand (operands[1], HImode)))
    {
      return 302;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11834: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L2214;
    }
 L11843: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L3727;
    }
  goto L6803;

 L2214: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L12186;
  x1 = XEXP (x0, 0);
  goto L11843;

 L12186: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_EXTEND:
      goto L2215;
    case NEG:
      goto L2424;
    case ABS:
      goto L2429;
    case PLUS:
      goto L2440;
    case MINUS:
      goto L2446;
    case MULT:
      goto L2452;
    case DIV:
      goto L2458;
    case SQRT:
      goto L2515;
    case IF_THEN_ELSE:
      goto L2520;
    case FLOAT:
      goto L2584;
    case FLOAT_TRUNCATE:
      goto L3758;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L2216;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2216: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 162;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L12198;
  x1 = XEXP (x0, 0);
  goto L11843;

 L12198: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L2435;
    case PLUS:
      goto L2481;
    case MINUS:
      goto L2499;
    case SUBREG:
    case REG:
      goto L12197;
    default:
      x1 = XEXP (x0, 0);
      goto L11843;
   }
 L12197: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2425;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2435: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2436;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2436: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 194;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2481: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode
      && GET_CODE (x3) == MULT)
    goto L2482;
  x1 = XEXP (x0, 0);
  goto L11843;

 L2482: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L2483;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2483: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L2484;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2484: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L2485;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2485: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (DFmode)))
    {
      return 201;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2499: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode
      && GET_CODE (x3) == MULT)
    goto L2500;
  x1 = XEXP (x0, 0);
  goto L11843;

 L2500: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L2501;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2501: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L2502;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2502: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L2503;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2503: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (DFmode)))
    {
      return 203;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2425: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 192;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2429: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2430;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2430: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 193;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2440: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L12202;
  x1 = XEXP (x0, 0);
  goto L11843;

 L12202: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L2465;
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2441;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2465: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2466;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2466: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L2467;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2467: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2468;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2468: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 199;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2442;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2442: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 195;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2446: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L12204;
  x1 = XEXP (x0, 0);
  goto L11843;

 L12204: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L2473;
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2447;
    }
 L12205: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2508;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2473: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode)
    goto L12207;
  x1 = XEXP (x0, 0);
  goto L11843;

 L12207: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L2491;
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2474;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2491: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L2492;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2492: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L2493;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2493: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2494;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2494: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD
   && ! HONOR_SIGNED_ZEROS (DFmode)))
    {
      return 202;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2474: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L2475;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2476;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2476: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD))
    {
      return 200;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2448;
    }
  x2 = XEXP (x1, 0);
  goto L12205;

 L2448: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 196;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L12205;

 L2508: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == MULT)
    goto L2509;
  x1 = XEXP (x0, 0);
  goto L11843;

 L2509: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2510;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2510: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L2511;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2511: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_FUSED_MADD 
   && ! HONOR_SIGNED_ZEROS (DFmode)))
    {
      return 204;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2452: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2453;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2453: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2454;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2454: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 197;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2458: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2459;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2460;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2460: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 198;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L2516;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2516: ATTRIBUTE_UNUSED_LABEL
  if (((TARGET_PPC_GPOPT || TARGET_POWER2) && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 205;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == GE)
    goto L2521;
  x1 = XEXP (x0, 0);
  goto L11843;

 L2521: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L12208;
    case SFmode:
      goto L12209;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L12208: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2522;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2522: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (zero_fp_constant (x3, DFmode))
    {
      operands[4] = x3;
      goto L2523;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2523: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2524;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2524: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2525;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2525: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PPC_GFXOPT && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 206;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L12209: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L2531;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2531: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (zero_fp_constant (x3, SFmode))
    {
      operands[4] = x3;
      goto L2532;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2532: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2533;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2534;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2534: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PPC_GFXOPT))
    {
      return 207;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2585;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L2585: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 212;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L3758: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L3759;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L3759: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 314;
    }
  x1 = XEXP (x0, 0);
  goto L11843;

 L3727: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L3728;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3728: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS
   && (gpc_reg_operand (operands[0], DFmode)
       || gpc_reg_operand (operands[1], DFmode))))
    {
      return 307;
    }
 L3732: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && (TARGET_SOFT_FLOAT || !TARGET_FPRS)
   && (gpc_reg_operand (operands[0], DFmode)
       || gpc_reg_operand (operands[1], DFmode))))
    {
      return 308;
    }
 L3736: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS
   && (gpc_reg_operand (operands[0], DFmode)
       || gpc_reg_operand (operands[1], DFmode))))
    {
      return 309;
    }
 L3740: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && (TARGET_SOFT_FLOAT || !TARGET_FPRS)
   && (gpc_reg_operand (operands[0], DFmode)
       || gpc_reg_operand (operands[1], DFmode))))
    {
      return 310;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11835: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L2219;
    }
 L11842: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L3719;
    }
  goto L6803;

 L2219: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L12210;
  x1 = XEXP (x0, 0);
  goto L11842;

 L12210: ATTRIBUTE_UNUSED_LABEL
  tem = recog_7 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L11842;

 L3719: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L3720;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3720: ATTRIBUTE_UNUSED_LABEL
  if (((gpc_reg_operand (operands[0], SFmode)
   || gpc_reg_operand (operands[1], SFmode))
   && (TARGET_HARD_FLOAT && TARGET_FPRS)))
    {
      return 305;
    }
 L3724: ATTRIBUTE_UNUSED_LABEL
  if (((gpc_reg_operand (operands[0], SFmode)
   || gpc_reg_operand (operands[1], SFmode))
   && (TARGET_SOFT_FLOAT || !TARGET_FPRS)))
    {
      return 306;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11840: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L3711;
    }
  goto L6803;

 L3711: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L3712;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3712: ATTRIBUTE_UNUSED_LABEL
  if ((gpc_reg_operand (operands[0], QImode)
   || gpc_reg_operand (operands[1], QImode)))
    {
      return 303;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11844: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L3743;
    }
 L11845: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L3747;
    }
  goto L6803;

 L3743: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, TFmode))
    {
      operands[1] = x1;
      goto L3744;
    }
  x1 = XEXP (x0, 0);
  goto L11845;

 L3744: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128
   && (gpc_reg_operand (operands[0], TFmode)
       || gpc_reg_operand (operands[1], TFmode))))
    {
      return 311;
    }
  x1 = XEXP (x0, 0);
  goto L11845;

 L3747: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TFmode)
    goto L12237;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12237: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_EXTEND:
      goto L3748;
    case FLOAT:
      goto L3784;
    case NEG:
      goto L3828;
    case ABS:
      goto L3833;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3748: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L12241;
    case SFmode:
      goto L12242;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12241: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L3749;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3749: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 312;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12242: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L3754;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3754: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 313;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3784: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L12243;
    case SImode:
      goto L12244;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12243: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3785;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3785: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_POWERPC64
   && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_LONG_DOUBLE_128)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 316;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12244: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3798;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3798: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 317;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3828: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TFmode)
    goto L12246;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12246: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == ABS)
    goto L3839;
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L3829;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3839: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L3840;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3840: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 322;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3829: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 320;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3833: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L3834;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3834: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 321;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11847: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L3867;
    }
 L11848: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L3875;
    }
  goto L6803;

 L3867: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (reg_or_mem_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L3868;
    }
  x1 = XEXP (x0, 0);
  goto L11848;

 L3868: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER && ! TARGET_POWERPC64
   && (gpc_reg_operand (operands[0], TImode) || gpc_reg_operand (operands[1], TImode)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 326;
    }
 L3872: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER && ! TARGET_POWERPC64
   && (gpc_reg_operand (operands[0], TImode) || gpc_reg_operand (operands[1], TImode))))
    {
      return 327;
    }
  x1 = XEXP (x0, 0);
  goto L11848;

 L3875: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L3876;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L3876: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && (gpc_reg_operand (operands[0], TImode)
   || gpc_reg_operand (operands[1], TImode))))
    {
      return 328;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11851: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x1, CCUNSmode))
    {
      operands[0] = x1;
      goto L5335;
    }
  goto L6803;

 L5335: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCUNSmode
      && GET_CODE (x1) == COMPARE)
    goto L5336;
  x1 = XEXP (x0, 0);
  goto L6803;

 L5336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L12247;
    case DImode:
      goto L12248;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12247: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5337;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_u_short_operand (x2, SImode))
    {
      operands[2] = x2;
      return 406;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12248: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5342;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_u_short_operand (x2, DImode))
    {
      operands[2] = x2;
      return 407;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11852: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x1, CCFPmode))
    {
      operands[0] = x1;
      goto L5367;
    }
  goto L6803;

 L5367: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPmode
      && GET_CODE (x1) == COMPARE)
    goto L5368;
  x1 = XEXP (x0, 0);
  goto L6803;

 L5368: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L12249;
    case DFmode:
      goto L12250;
    case TFmode:
      goto L12251;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12249: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L5369;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5369: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L5370;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5370: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 410;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12250: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L5375;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5375: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L5376;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5376: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 411;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12251: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L5381;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5381: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L5382;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L5382: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 412;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11853: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x1, CCEQmode))
    {
      operands[0] = x1;
      goto L6838;
    }
  goto L6803;

 L6838: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCEQmode
      && GET_CODE (x1) == COMPARE)
    goto L6839;
  x1 = XEXP (x0, 0);
  goto L6803;

 L6839: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12252;
 L6869: ATTRIBUTE_UNUSED_LABEL
  if (branch_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L6870;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12252: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x2, SImode))
    {
      operands[1] = x2;
      goto L6840;
    }
 L12253: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x2, SImode))
    {
      operands[1] = x2;
      goto L6851;
    }
  if (branch_positive_comparison_operator (x2, SImode))
    {
      operands[1] = x2;
      goto L6863;
    }
  goto L6869;

 L6840: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (branch_positive_comparison_operator (x3, SImode))
    {
      operands[2] = x3;
      goto L6841;
    }
  goto L12253;

 L6841: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (cc_reg_operand (x4, VOIDmode))
    {
      operands[3] = x4;
      goto L6842;
    }
  goto L12253;

 L6842: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6843;
  goto L12253;

 L6843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (branch_positive_comparison_operator (x3, SImode))
    {
      operands[4] = x3;
      goto L6844;
    }
  goto L12253;

 L6844: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (cc_reg_operand (x4, VOIDmode))
    {
      operands[5] = x4;
      goto L6845;
    }
  goto L12253;

 L6845: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6846;
  goto L12253;

 L6846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL)
    {
      return 515;
    }
  x2 = XEXP (x1, 0);
  goto L12253;

 L6851: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NOT)
    goto L6852;
  goto L6869;

 L6852: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (branch_positive_comparison_operator (x4, SImode))
    {
      operands[2] = x4;
      goto L6853;
    }
  goto L6869;

 L6853: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (cc_reg_operand (x5, VOIDmode))
    {
      operands[3] = x5;
      goto L6854;
    }
  goto L6869;

 L6854: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L6855;
  goto L6869;

 L6855: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (branch_positive_comparison_operator (x3, SImode))
    {
      operands[4] = x3;
      goto L6856;
    }
  goto L6869;

 L6856: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (cc_reg_operand (x4, VOIDmode))
    {
      operands[5] = x4;
      goto L6857;
    }
  goto L6869;

 L6857: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6858;
  goto L6869;

 L6858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == -1LL)
    {
      return 516;
    }
  x2 = XEXP (x1, 0);
  goto L6869;

 L6863: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (cc_reg_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L6864;
    }
  goto L6869;

 L6864: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6865;
  goto L6869;

 L6865: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL)
    {
      return 517;
    }
  x2 = XEXP (x1, 0);
  goto L6869;

 L6870: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (cc_reg_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L6871;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L6871: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6872;
  x1 = XEXP (x0, 0);
  goto L6803;

 L6872: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (branch_comparison_operator (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L6873;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L6873: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (cc_reg_operand (x3, VOIDmode))
    {
      operands[4] = x3;
      goto L6874;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L6874: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    {
      return 518;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11854: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, BLKmode))
    {
      operands[0] = x1;
      goto L7374;
    }
  goto L6803;

 L7374: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == BLKmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 5)
    goto L7375;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7375: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, operands[0]))
    {
      return 545;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11855: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L7448;
    }
  if (memory_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L7464;
    }
 L11863: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L7480;
    }
 L11867: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L7506;
    }
 L11873: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L7534;
    }
  goto L6803;

 L7448: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, V4SImode))
    {
      operands[1] = x1;
      goto L7449;
    }
  x1 = XEXP (x0, 0);
  goto L11863;

 L7449: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 556;
    }
  x1 = XEXP (x0, 0);
  goto L11863;

 L7464: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (altivec_register_operand (x1, V4SImode))
    {
      operands[1] = x1;
      goto L7465;
    }
  x1 = XEXP (x0, 0);
  goto L11863;

 L7465: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 560;
    }
  x1 = XEXP (x0, 0);
  goto L11863;

 L7480: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, V4SImode))
    {
      operands[1] = x1;
      goto L7481;
    }
  x1 = XEXP (x0, 0);
  goto L11867;

 L7481: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 564;
    }
  x1 = XEXP (x0, 0);
  goto L11867;

 L7506: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (zero_constant (x1, V4SImode))
    {
      operands[1] = x1;
      goto L7507;
    }
  x1 = XEXP (x0, 0);
  goto L11873;

 L7507: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 570;
    }
  x1 = XEXP (x0, 0);
  goto L11873;

 L7534: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SImode)
    goto L12255;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12255: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L7535;
    case UNSPEC:
      goto L12305;
    case AND:
      goto L7613;
    case UMAX:
      goto L7830;
    case SMAX:
      goto L7836;
    case VEC_MERGE:
      goto L7917;
    case UMIN:
      goto L8005;
    case SMIN:
      goto L8011;
    case NOT:
      goto L8071;
    case IOR:
      goto L8078;
    case MINUS:
      goto L8296;
    case XOR:
      goto L8424;
    case MEM:
      goto L8808;
    case ABS:
      goto L8908;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7535: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7536;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7536: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7537;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7537: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 576;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L12305: ATTRIBUTE_UNUSED_LABEL
  tem = recog_8 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7614;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7614: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode)
    goto L12380;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12380: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L7621;
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7615;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7621: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L7622;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7622: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 586;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7615: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 585;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7830: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7831;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7831: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7832;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7832: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 618;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7836: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7837;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7837: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7838;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7838: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 619;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L7918;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V4SImode)
    goto L12381;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12381: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L7919;
    }
 L12382: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L7971;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7919: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L7920;
  x3 = XEXP (x2, 0);
  goto L12382;

 L7920: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L7921;
  x3 = XEXP (x2, 0);
  goto L12382;

 L7921: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L7922;
  x3 = XEXP (x2, 0);
  goto L12382;

 L7922: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7923;
  x3 = XEXP (x2, 0);
  goto L12382;

 L7923: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7924;
  x3 = XEXP (x2, 0);
  goto L12382;

 L7924: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L7925;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12382;

 L7925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 12LL
      && (TARGET_ALTIVEC))
    {
      return 626;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L12382;

 L7971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L7972;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7972: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7973;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7973: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7974;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7974: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L7975;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7975: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L7976;
  x1 = XEXP (x0, 0);
  goto L6803;

 L7976: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L7977;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L7977: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 12LL
      && (TARGET_ALTIVEC))
    {
      return 629;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8005: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8006;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8006: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8007;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8007: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 634;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8012;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8012: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8013;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8013: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 635;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8071: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == IOR)
    goto L8072;
  x1 = XEXP (x0, 0);
  goto L6803;

 L8072: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8073;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8073: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8074;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8074: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 645;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8078: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8079;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8079: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8080;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8080: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 646;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8297;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8298;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8298: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 677;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8425;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8425: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8426;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8426: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 691;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8808: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L8809;
  x1 = XEXP (x0, 0);
  goto L6803;

 L8809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L8810;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8810: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L8811;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8811: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 747;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8908: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L8909;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L8909: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 755;
    }
  x1 = XEXP (x0, 0);
  goto L6803;

 L11856: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L7452;
    }
  if (memory_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L7468;
    }
 L11864: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L7484;
    }
 L11869: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L7514;
    }
 L11872: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L7528;
    }
  goto L6803;

 L7452: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, V8HImode))
    {
      operands[1] = x1;
      goto L7453;
    }
  x1 = XEXP (x0, 0);
  goto L11864;

 L7453: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 557;
    }
  x1 = XEXP (x0, 0);
  goto L11864;

 L7468: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (altivec_register_operand (x1, V8HImode))
    {
      operands[1] = x1;
      goto L7469;
    }
  x1 = XEXP (x0, 0);
  goto L11864;

 L7469: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 561;
    }
  x1 = XEXP (x0, 0);
  goto L11864;

 L7484: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, V8HImode))
    {
      operands[1] = x1;
      goto L7485;
    }
  x1 = XEXP (x0, 0);
  goto L11869;

 L7485: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 565;
    }
  x1 = XEXP (x0, 0);
  goto L11869;

 L7514: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (zero_constant (x1, V8HImode))
    {
      operands[1] = x1;
      goto L7515;
    }
  x1 = XEXP (x0, 0);
  goto L11872;

 L7515: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 572;
    }
  x1 = XEXP (x0, 0);
  goto L11872;

 L7528: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V8HImode)
    goto L12383;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12383: ATTRIBUTE_UNUSED_LABEL
  tem = recog_9 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L6803;

 L11857: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L7456;
    }
  if (memory_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L7472;
    }
 L11865: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L7488;
    }
 L11870: ATTRIBUTE_UNUSED_LABEL
  if (altivec_register_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L7518;
    }
 L11871: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L7522;
    }
  goto L6803;

 L7456: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (memory_operand (x1, V16QImode))
    {
      operands[1] = x1;
      goto L7457;
    }
  x1 = XEXP (x0, 0);
  goto L11865;

 L7457: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 558;
    }
  x1 = XEXP (x0, 0);
  goto L11865;

 L7472: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (altivec_register_operand (x1, V16QImode))
    {
      operands[1] = x1;
      goto L7473;
    }
  x1 = XEXP (x0, 0);
  goto L11865;

 L7473: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 562;
    }
  x1 = XEXP (x0, 0);
  goto L11865;

 L7488: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (input_operand (x1, V16QImode))
    {
      operands[1] = x1;
      goto L7489;
    }
  x1 = XEXP (x0, 0);
  goto L11870;

 L7489: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 566;
    }
  x1 = XEXP (x0, 0);
  goto L11870;

 L7518: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (zero_constant (x1, V16QImode))
    {
      operands[1] = x1;
      goto L7519;
    }
  x1 = XEXP (x0, 0);
  goto L11871;

 L7519: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 573;
    }
  x1 = XEXP (x0, 0);
  goto L11871;

 L7522: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V16QImode)
    goto L12467;
  x1 = XEXP (x0, 0);
  goto L6803;

 L12467: ATTRIBUTE_UNUSED_LABEL
  tem = recog_10 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L6803;

 L11858: ATTRIBUTE_UNUSED_LABEL
  tem = recog_11 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L6803;

 L6882: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L12583;
    case DImode:
      goto L12584;
    default:
      break;
    }
 L6804: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case IF_THEN_ELSE:
      goto L6805;
    case LABEL_REF:
      goto L6878;
    default:
     break;
   }
  goto ret0;

 L12583: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L6883;
    }
  goto L6804;

 L6883: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT))
    {
      return 521;
    }
  x1 = XEXP (x0, 1);
  goto L6804;

 L12584: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L6887;
    }
  goto L6804;

 L6887: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 522;
    }
  x1 = XEXP (x0, 1);
  goto L6804;

 L6805: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (branch_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L6806;
    }
 L6814: ATTRIBUTE_UNUSED_LABEL
  if (branch_comparison_operator (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L6815;
    }
  goto ret0;

 L6806: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (cc_reg_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L6807;
    }
  goto L6814;

 L6807: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6808;
  goto L6814;

 L6808: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L6809;
    case PC:
      goto L6826;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L6814;

 L6809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  goto L6810;

 L6810: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    {
      return 511;
    }
  x2 = XEXP (x1, 0);
  goto L6814;

 L6826: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6827;
  x2 = XEXP (x1, 0);
  goto L6814;

 L6827: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  return 513;

 L6815: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (cc_reg_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L6816;
    }
  goto ret0;

 L6816: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6817;
  goto ret0;

 L6817: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case RETURN:
      goto L6818;
    case PC:
      goto L6835;
    default:
     break;
   }
  goto ret0;

 L6818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && (direct_return ()))
    {
      return 512;
    }
  goto ret0;

 L6835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == RETURN
      && (direct_return ()))
    {
      return 514;
    }
  goto ret0;

 L6878: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  return 519;
 ret0:
  return -1;
}

static int recog_13 PARAMS ((rtx, rtx, int *));
static int
recog_13 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L10;
    case SIGN_EXTEND:
      goto L42;
    case PLUS:
      goto L2829;
    case NOT:
      goto L2865;
    case MINUS:
      goto L2898;
    case NEG:
      goto L2962;
    case DIV:
      goto L3026;
    case ROTATE:
      goto L3075;
    case AND:
      goto L3114;
    case ASHIFT:
      goto L3300;
    case LSHIFTRT:
      goto L3431;
    case ASHIFTRT:
      goto L3468;
    case IOR:
    case XOR:
      goto L12642;
    default:
      goto L12643;
   }
 L12642: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x3, DImode))
    {
      operands[4] = x3;
      goto L3569;
    }
 L12643: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x3, DImode))
    {
      operands[4] = x3;
      goto L3605;
    }
  goto ret0;

 L10: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12644;
    case HImode:
      goto L12645;
    case SImode:
      goto L12646;
    default:
      break;
    }
  goto ret0;

 L12644: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L11;
    }
 L12647: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L3162;
  goto ret0;

 L11: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L12;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12647;

 L12: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L13;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12647;

 L13: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L14;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12647;

 L14: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 1;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12647;

 L3162: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L3163;
  goto ret0;

 L3163: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L3164;
    }
  goto ret0;

 L3164: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L3165;
    }
  goto ret0;

 L3165: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3166;
  goto ret0;

 L3166: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3167;
  goto ret0;

 L3167: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3168;
    }
  goto ret0;

 L3168: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 262;
    }
  goto ret0;

 L12645: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L75;
    }
 L12648: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L3209;
  goto ret0;

 L75: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L76;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12648;

 L76: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L77;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12648;

 L77: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L78;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12648;

 L78: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 7;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12648;

 L3209: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L3210;
  goto ret0;

 L3210: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L3211;
    }
  goto ret0;

 L3211: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L3212;
    }
  goto ret0;

 L3212: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3213;
  goto ret0;

 L3213: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3214;
  goto ret0;

 L3214: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3215;
    }
  goto ret0;

 L3215: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 265;
    }
  goto ret0;

 L12646: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L139;
    }
 L12649: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L3256;
  goto ret0;

 L139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L140;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12649;

 L140: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L141;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12649;

 L141: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L142;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12649;

 L142: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 13;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12649;

 L3256: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L3257;
  goto ret0;

 L3257: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L3258;
    }
  goto ret0;

 L3258: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L3259;
    }
  goto ret0;

 L3259: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3260;
  goto ret0;

 L3260: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3261;
  goto ret0;

 L3261: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3262;
    }
  goto ret0;

 L3262: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 268;
    }
  goto ret0;

 L42: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12650;
    case HImode:
      goto L12651;
    case SImode:
      goto L12652;
    default:
      break;
    }
  goto ret0;

 L12650: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L43;
    }
  goto ret0;

 L43: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L44;
  goto ret0;

 L44: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L45;
  goto ret0;

 L45: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L46;
    }
  goto ret0;

 L46: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 4;
    }
  goto ret0;

 L12651: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L107;
    }
  goto ret0;

 L107: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L108;
  goto ret0;

 L108: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L109;
  goto ret0;

 L109: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L110;
    }
  goto ret0;

 L110: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 10;
    }
  goto ret0;

 L12652: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L171;
    }
  goto ret0;

 L171: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L172;
  goto ret0;

 L172: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L173;
  goto ret0;

 L173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L174;
    }
  goto ret0;

 L174: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 16;
    }
  goto ret0;

 L2829: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2830;
    }
  goto ret0;

 L2830: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2831;
    }
  goto ret0;

 L2831: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2832;
  goto ret0;

 L2832: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2833;
  goto ret0;

 L2833: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2834;
    }
  goto ret0;

 L2834: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 233;
    }
  goto ret0;

 L2865: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2866;
    }
  goto ret0;

 L2866: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2867;
  goto ret0;

 L2867: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2868;
  goto ret0;

 L2868: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2869;
    }
  goto ret0;

 L2869: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 236;
    }
  goto ret0;

 L2898: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2899;
    }
  goto ret0;

 L2899: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2900;
    }
  goto ret0;

 L2900: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2901;
  goto ret0;

 L2901: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2902;
  goto ret0;

 L2902: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2903;
    }
  goto ret0;

 L2903: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 239;
    }
  goto ret0;

 L2962: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2963;
    }
  goto ret0;

 L2963: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2964;
  goto ret0;

 L2964: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2965;
  goto ret0;

 L2965: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2966;
    }
  goto ret0;

 L2966: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 244;
    }
  goto ret0;

 L3026: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3027;
    }
  goto ret0;

 L3027: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (exact_log2_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3028;
    }
  goto ret0;

 L3028: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3029;
  goto ret0;

 L3029: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3030;
  goto ret0;

 L3030: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3031;
    }
  goto ret0;

 L3031: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 251;
    }
  goto ret0;

 L3075: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3076;
    }
  goto ret0;

 L3076: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3077;
    }
  goto ret0;

 L3077: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3078;
  goto ret0;

 L3078: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3079;
  goto ret0;

 L3079: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3080;
    }
  goto ret0;

 L3080: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 256;
    }
  goto ret0;

 L3114: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L12653;
  goto L12643;

 L12653: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L3115;
    case ASHIFT:
      goto L3340;
    default:
     break;
   }
  goto L12643;

 L3115: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3116;
    }
  goto L12643;

 L3116: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3117;
    }
  goto L12643;

 L3117: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask64_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L3118;
    }
  goto L12643;

 L3118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3119;
  x3 = XEXP (x2, 0);
  goto L12643;

 L3119: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3120;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3120: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L3121;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3121: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 259;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3340: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3341;
    }
  goto L12643;

 L3341: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L3342;
    }
  goto L12643;

 L3342: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L12655;
  goto L12643;

 L12655: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L3343;
    }
 L12656: ATTRIBUTE_UNUSED_LABEL
  if (mask64_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L3390;
    }
  goto L12643;

 L3343: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3344;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12656;

 L3344: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3345;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12656;

 L3345: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L3346;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12656;

 L3346: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && includes_rldic_lshift_p (operands[2], operands[3])))
    {
      return 274;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12656;

 L3390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3391;
  x3 = XEXP (x2, 0);
  goto L12643;

 L3391: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3392;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3392: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L3393;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3393: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && includes_rldicr_lshift_p (operands[2], operands[3])))
    {
      return 277;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3300: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3301;
    }
  goto ret0;

 L3301: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3302;
    }
  goto ret0;

 L3302: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3303;
  goto ret0;

 L3303: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3304;
  goto ret0;

 L3304: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3305;
    }
  goto ret0;

 L3305: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 271;
    }
  goto ret0;

 L3431: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3432;
    }
  goto ret0;

 L3432: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3433;
    }
  goto ret0;

 L3433: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3434;
  goto ret0;

 L3434: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3435;
  goto ret0;

 L3435: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3436;
    }
  goto ret0;

 L3436: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 280;
    }
  goto ret0;

 L3468: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3469;
    }
  goto ret0;

 L3469: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3470;
    }
  goto ret0;

 L3470: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3471;
  goto ret0;

 L3471: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3472;
  goto ret0;

 L3472: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3473;
    }
  goto ret0;

 L3473: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 283;
    }
  goto ret0;

 L3569: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3570;
    }
  goto L12643;

 L3570: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3571;
    }
  goto L12643;

 L3571: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3572;
  x3 = XEXP (x2, 0);
  goto L12643;

 L3572: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3573;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3573: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3574;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3574: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 289;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12643;

 L3605: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == NOT)
    goto L3606;
  goto ret0;

 L3606: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3607;
    }
  goto ret0;

 L3607: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode)
    goto L12658;
  goto ret0;

 L12658: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L3648;
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3608;
    }
  goto ret0;

 L3648: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3649;
    }
  goto ret0;

 L3649: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3650;
  goto ret0;

 L3650: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3651;
  goto ret0;

 L3651: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3652;
    }
  goto ret0;

 L3652: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 295;
    }
  goto ret0;

 L3608: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3609;
  goto ret0;

 L3609: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3610;
  goto ret0;

 L3610: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3611;
    }
  goto ret0;

 L3611: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 292;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_14 PARAMS ((rtx, rtx, int *));
static int
recog_14 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L201;
    case SIGN_EXTEND:
      goto L232;
    case PLUS:
      goto L386;
    case NOT:
      goto L421;
    case MINUS:
      goto L460;
    case IF_THEN_ELSE:
      goto L532;
    case NEG:
      goto L626;
    case MULT:
      goto L698;
    case DIV:
      goto L816;
    case ZERO_EXTRACT:
      goto L1455;
    case ROTATE:
      goto L1536;
    case AND:
      goto L1573;
    case ASHIFT:
      goto L1742;
    case LSHIFTRT:
      goto L1890;
    case ASHIFTRT:
      goto L2157;
    case IOR:
    case XOR:
      goto L12624;
    default:
      goto L12625;
   }
 L12624: ATTRIBUTE_UNUSED_LABEL
  if (boolean_or_operator (x3, SImode))
    {
      operands[4] = x3;
      goto L1155;
    }
 L12625: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x3, SImode))
    {
      operands[4] = x3;
      goto L1190;
    }
  goto ret0;

 L201: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12659;
    case HImode:
      goto L12660;
    default:
      break;
    }
  goto ret0;

 L12659: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L202;
    }
 L12661: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L1619;
  goto ret0;

 L202: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L203;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12661;

 L203: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L204;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12661;

 L204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      return 19;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12661;

 L1619: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12663;
  goto ret0;

 L12663: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ROTATE:
      goto L1620;
    case LSHIFTRT:
      goto L2007;
    default:
     break;
   }
  goto ret0;

 L1620: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L1621;
    }
  goto ret0;

 L1621: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L1622;
    }
  goto ret0;

 L1622: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1623;
  goto ret0;

 L1623: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1624;
  goto ret0;

 L1624: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      return 124;
    }
  goto ret0;

 L2007: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2008;
    }
  goto ret0;

 L2008: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2009;
    }
  goto ret0;

 L2009: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2010;
  goto ret0;

 L2010: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2011;
  goto ret0;

 L2011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2012;
    }
  goto ret0;

 L2012: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], GEN_INT (255))))
    {
      return 148;
    }
  goto ret0;

 L12660: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L326;
    }
 L12662: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L1664;
  goto ret0;

 L326: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L327;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12662;

 L327: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L328;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12662;

 L328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      return 31;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12662;

 L1664: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12665;
  goto ret0;

 L12665: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ROTATE:
      goto L1665;
    case LSHIFTRT:
      goto L2054;
    default:
     break;
   }
  goto ret0;

 L1665: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L1666;
    }
  goto ret0;

 L1666: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L1667;
    }
  goto ret0;

 L1667: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1668;
  goto ret0;

 L1668: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1669;
  goto ret0;

 L1669: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      return 127;
    }
  goto ret0;

 L2054: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2055;
    }
  goto ret0;

 L2055: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2056;
    }
  goto ret0;

 L2056: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2057;
  goto ret0;

 L2057: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2058;
  goto ret0;

 L2058: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2059;
    }
  goto ret0;

 L2059: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], GEN_INT (65535))))
    {
      return 151;
    }
  goto ret0;

 L232: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12667;
    case HImode:
      goto L12668;
    default:
      break;
    }
  goto ret0;

 L12667: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L233;
    }
  goto ret0;

 L233: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L234;
  goto ret0;

 L234: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L235;
  goto ret0;

 L235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L236;
    }
  goto ret0;

 L236: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC))
    {
      return 22;
    }
  goto ret0;

 L12668: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L356;
    }
  goto ret0;

 L356: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L357;
  goto ret0;

 L357: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L358;
  goto ret0;

 L358: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      return 34;
    }
  goto ret0;

 L386: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L387;
    }
  goto ret0;

 L387: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L388;
    }
  goto ret0;

 L388: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L389;
  goto ret0;

 L389: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L390;
  goto ret0;

 L390: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L391;
    }
  goto ret0;

 L391: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 37;
    }
  goto ret0;

 L421: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L422;
    }
  goto ret0;

 L422: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L423;
  goto ret0;

 L423: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L424;
  goto ret0;

 L424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L425;
    }
  goto ret0;

 L425: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 40;
    }
  goto ret0;

 L460: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L461;
    }
  goto ret0;

 L461: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L462;
    }
  goto ret0;

 L462: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L463;
  goto ret0;

 L463: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L464;
  goto ret0;

 L464: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L465;
    }
  goto ret0;

 L465: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC))
    {
      return 44;
    }
 L483: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && ! TARGET_POWERPC64))
    {
      return 45;
    }
  goto ret0;

 L532: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == GT)
    goto L533;
  goto ret0;

 L533: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L534;
    }
  goto ret0;

 L534: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L535;
    }
  goto ret0;

 L535: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L536;
  goto ret0;

 L536: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == MINUS)
    goto L537;
  goto ret0;

 L537: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L538;
  goto ret0;

 L538: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[1]))
    goto L539;
  goto ret0;

 L539: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L540;
  goto ret0;

 L540: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L541;
  goto ret0;

 L541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L542;
    }
  goto ret0;

 L542: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 49;
    }
  goto ret0;

 L626: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L627;
    }
  goto ret0;

 L627: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L628;
  goto ret0;

 L628: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L629;
  goto ret0;

 L629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L630;
    }
  goto ret0;

 L630: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 56;
    }
  goto ret0;

 L698: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L699;
    }
  goto ret0;

 L699: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L700;
    }
  goto ret0;

 L700: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L701;
  goto ret0;

 L701: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L702;
  goto ret0;

 L702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L703;
    }
  goto ret0;

 L703: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 62;
    }
  goto ret0;

 L816: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L817;
    }
  goto ret0;

 L817: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (exact_log2_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L818;
    }
  goto ret0;

 L818: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L819;
  goto ret0;

 L819: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L820;
  goto ret0;

 L820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      return 71;
    }
  goto ret0;

 L1455: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1456;
    }
  goto ret0;

 L1456: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1457;
    }
  goto ret0;

 L1457: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1458;
    }
  goto ret0;

 L1458: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1459;
  goto ret0;

 L1459: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1460;
  goto ret0;

 L1460: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      return 112;
    }
  goto ret0;

 L1536: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1537;
    }
  goto ret0;

 L1537: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1538;
    }
  goto ret0;

 L1538: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1539;
  goto ret0;

 L1539: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1540;
  goto ret0;

 L1540: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      return 118;
    }
  goto ret0;

 L1573: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12669;
  goto L12625;

 L12669: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L1574;
    case ASHIFT:
      goto L1811;
    case LSHIFTRT:
      goto L1959;
    default:
     break;
   }
  goto L12625;

 L1574: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1575;
    }
  goto L12625;

 L1575: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1576;
    }
  goto L12625;

 L1576: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1577;
    }
  goto L12625;

 L1577: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1578;
  x3 = XEXP (x2, 0);
  goto L12625;

 L1578: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1579;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1579: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      return 121;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1811: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1812;
    }
  goto L12625;

 L1812: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1813;
    }
  goto L12625;

 L1813: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1814;
    }
  goto L12625;

 L1814: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1815;
  x3 = XEXP (x2, 0);
  goto L12625;

 L1815: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1816;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1816: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1817;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1817: ATTRIBUTE_UNUSED_LABEL
  if ((includes_lshift_p (operands[2], operands[3])))
    {
      return 136;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1959: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1960;
    }
  goto L12625;

 L1960: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1961;
    }
  goto L12625;

 L1961: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1962;
    }
  goto L12625;

 L1962: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1963;
  x3 = XEXP (x2, 0);
  goto L12625;

 L1963: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1964;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1964: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1965;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1965: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], operands[3])))
    {
      return 145;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1742: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1743;
    }
  goto ret0;

 L1743: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1744;
    }
  goto ret0;

 L1744: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1745;
  goto ret0;

 L1745: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1746;
  goto ret0;

 L1746: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1747;
    }
  goto ret0;

 L1747: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64))
    {
      return 132;
    }
  goto ret0;

 L1890: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1891;
    }
  goto ret0;

 L1891: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1892;
    }
  goto ret0;

 L1892: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1893;
  goto ret0;

 L1893: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1894;
  goto ret0;

 L1894: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1895;
    }
  goto ret0;

 L1895: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64))
    {
      return 141;
    }
  goto ret0;

 L2157: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2158;
    }
  goto ret0;

 L2158: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2159;
    }
  goto ret0;

 L2159: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2160;
  goto ret0;

 L2160: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2161;
  goto ret0;

 L2161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2162;
    }
  goto ret0;

 L2162: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 159;
    }
  goto ret0;

 L1155: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1156;
    }
  goto L12625;

 L1156: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1157;
    }
  goto L12625;

 L1157: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1158;
  x3 = XEXP (x2, 0);
  goto L12625;

 L1158: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1159;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1159: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1160;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1160: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 89;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12625;

 L1190: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NOT)
    goto L1191;
  goto ret0;

 L1191: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1192;
    }
  goto ret0;

 L1192: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode)
    goto L12673;
  goto ret0;

 L12673: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L1232;
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1193;
    }
  goto ret0;

 L1232: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1233;
    }
  goto ret0;

 L1233: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1234;
  goto ret0;

 L1234: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1235;
  goto ret0;

 L1235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1236;
    }
  goto ret0;

 L1236: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 95;
    }
  goto ret0;

 L1193: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1194;
  goto ret0;

 L1194: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1195;
  goto ret0;

 L1195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1196;
    }
  goto ret0;

 L1196: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 92;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_15 PARAMS ((rtx, rtx, int *));
static int
recog_15 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L12674;
    case SImode:
      goto L12676;
    case HImode:
      goto L12678;
    default:
      break;
    }
  goto ret0;

 L12674: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L26;
    case SIGN_EXTEND:
      goto L58;
    case NOT:
      goto L2881;
    case NEG:
      goto L2978;
    case SUBREG:
    case REG:
      goto L12686;
    default:
      goto ret0;
   }
 L12686: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3854;
    }
  goto ret0;

 L26: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12687;
    case HImode:
      goto L12688;
    case SImode:
      goto L12689;
    default:
      break;
    }
  goto ret0;

 L12687: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L27;
    }
  goto ret0;

 L27: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L28;
  goto ret0;

 L28: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L29;
  goto ret0;

 L29: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L30;
    }
  goto ret0;

 L30: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L31;
  goto ret0;

 L31: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 2;
    }
  goto ret0;

 L12688: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L91;
    }
  goto ret0;

 L91: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L92;
  goto ret0;

 L92: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L93;
  goto ret0;

 L93: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L94;
    }
  goto ret0;

 L94: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L95;
  goto ret0;

 L95: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 8;
    }
  goto ret0;

 L12689: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L155;
    }
  goto ret0;

 L155: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L156;
  goto ret0;

 L156: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L157;
  goto ret0;

 L157: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L158;
    }
  goto ret0;

 L158: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L159;
  goto ret0;

 L159: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 14;
    }
  goto ret0;

 L58: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12690;
    case HImode:
      goto L12691;
    case SImode:
      goto L12692;
    default:
      break;
    }
  goto ret0;

 L12690: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L59;
    }
  goto ret0;

 L59: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L60;
  goto ret0;

 L60: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L61;
  goto ret0;

 L61: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L62;
    }
  goto ret0;

 L62: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L63;
  goto ret0;

 L63: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 5;
    }
  goto ret0;

 L12691: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L123;
    }
  goto ret0;

 L123: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L124;
  goto ret0;

 L124: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L125;
  goto ret0;

 L125: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L126;
    }
  goto ret0;

 L126: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L127;
  goto ret0;

 L127: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 11;
    }
  goto ret0;

 L12692: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L187;
    }
  goto ret0;

 L187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L188;
  goto ret0;

 L188: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L189;
  goto ret0;

 L189: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L190;
    }
  goto ret0;

 L190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L191;
  goto ret0;

 L191: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 17;
    }
  goto ret0;

 L2881: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2882;
    }
  goto ret0;

 L2882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2883;
  goto ret0;

 L2883: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2884;
  goto ret0;

 L2884: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2885;
    }
  goto ret0;

 L2885: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NOT)
    goto L2886;
  goto ret0;

 L2886: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 237;
    }
  goto ret0;

 L2978: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2979;
    }
  goto ret0;

 L2979: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2980;
  goto ret0;

 L2980: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2981;
  goto ret0;

 L2981: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2982;
    }
  goto ret0;

 L2982: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NEG)
    goto L2983;
  goto ret0;

 L2983: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64))
    {
      return 245;
    }
  goto ret0;

 L3854: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3855;
  goto ret0;

 L3855: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3856;
  goto ret0;

 L3856: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3857;
    }
  goto ret0;

 L3857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1])
      && (TARGET_POWERPC64))
    {
      return 325;
    }
  goto ret0;

 L12676: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L216;
    case SIGN_EXTEND:
      goto L248;
    case NOT:
      goto L437;
    case NEG:
      goto L642;
    case AND:
      goto L1119;
    case SUBREG:
    case REG:
      goto L12685;
    default:
      goto ret0;
   }
 L12685: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3701;
    }
  goto ret0;

 L216: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12693;
    case HImode:
      goto L12694;
    default:
      break;
    }
  goto ret0;

 L12693: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L217;
    }
  goto ret0;

 L217: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L218;
  goto ret0;

 L218: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L219;
  goto ret0;

 L219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L220;
    }
  goto ret0;

 L220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L221;
  goto ret0;

 L221: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      return 20;
    }
  goto ret0;

 L12694: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L341;
    }
  goto ret0;

 L341: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L342;
  goto ret0;

 L342: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L343;
  goto ret0;

 L343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L344;
    }
  goto ret0;

 L344: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L345;
  goto ret0;

 L345: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      return 32;
    }
  goto ret0;

 L248: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12695;
    case HImode:
      goto L12696;
    default:
      break;
    }
  goto ret0;

 L12695: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L249;
    }
  goto ret0;

 L249: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L250;
  goto ret0;

 L250: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L251;
  goto ret0;

 L251: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L252;
    }
  goto ret0;

 L252: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L253;
  goto ret0;

 L253: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC))
    {
      return 23;
    }
  goto ret0;

 L12696: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L371;
    }
  goto ret0;

 L371: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L372;
  goto ret0;

 L372: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L373;
  goto ret0;

 L373: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L374;
    }
  goto ret0;

 L374: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L375;
  goto ret0;

 L375: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      return 35;
    }
  goto ret0;

 L437: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L438;
    }
  goto ret0;

 L438: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L439;
  goto ret0;

 L439: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L440;
  goto ret0;

 L440: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L441;
    }
  goto ret0;

 L441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NOT)
    goto L442;
  goto ret0;

 L442: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (! TARGET_POWERPC64))
    {
      return 41;
    }
  goto ret0;

 L642: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L643;
    }
  goto ret0;

 L643: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L644;
  goto ret0;

 L644: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L645;
  goto ret0;

 L645: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L646;
    }
  goto ret0;

 L646: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NEG)
    goto L647;
  goto ret0;

 L647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (! TARGET_POWERPC64))
    {
      return 57;
    }
  goto ret0;

 L1119: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[0] = x4;
      goto L1120;
    }
  goto ret0;

 L1120: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand_wrap (x4, SImode))
    {
      operands[1] = x4;
      goto L1121;
    }
  goto ret0;

 L1121: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1122;
  goto ret0;

 L1122: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1123;
  goto ret0;

 L1123: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1124;
    }
  goto ret0;

 L1124: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 86;
    }
  goto ret0;

 L3701: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3702;
  goto ret0;

 L3702: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3703;
  goto ret0;

 L3703: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L3704;
    }
  goto ret0;

 L3704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1])
      && (! TARGET_POWERPC64))
    {
      return 301;
    }
  goto ret0;

 L12678: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L278;
    case SIGN_EXTEND:
      goto L310;
    default:
     break;
   }
  goto ret0;

 L278: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L279;
    }
  goto ret0;

 L279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L280;
  goto ret0;

 L280: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L281;
  goto ret0;

 L281: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L282;
    }
  goto ret0;

 L282: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L283;
  goto ret0;

 L283: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      return 26;
    }
  goto ret0;

 L310: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L311;
    }
  goto ret0;

 L311: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L312;
  goto ret0;

 L312: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L313;
  goto ret0;

 L313: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L314;
    }
  goto ret0;

 L314: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L315;
  goto ret0;

 L315: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC))
    {
      return 29;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_16 PARAMS ((rtx, rtx, int *));
static int
recog_16 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L404;
    case MINUS:
      goto L496;
    case IF_THEN_ELSE:
      goto L560;
    case MULT:
      goto L732;
    case DIV:
      goto L833;
    case AND:
      goto L1071;
    case ROTATE:
      goto L1553;
    case ZERO_EXTEND:
      goto L1639;
    case ASHIFT:
      goto L1776;
    case LSHIFTRT:
      goto L1924;
    case ASHIFTRT:
      goto L2191;
    default:
     break;
   }
 L12703: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x3, SImode))
    {
      operands[4] = x3;
      goto L1173;
    }
  goto ret0;

 L404: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L405;
    }
  goto ret0;

 L405: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L406;
    }
  goto ret0;

 L406: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L407;
  goto ret0;

 L407: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L408;
  goto ret0;

 L408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L409;
    }
  goto ret0;

 L409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L410;
  goto ret0;

 L410: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L411;
  goto ret0;

 L411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64))
    {
      return 38;
    }
  goto ret0;

 L496: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L497;
    }
  goto ret0;

 L497: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L498;
    }
  goto ret0;

 L498: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L499;
  goto ret0;

 L499: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L500;
  goto ret0;

 L500: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L501;
    }
  goto ret0;

 L501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L502;
  goto ret0;

 L502: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L503;
  goto ret0;

 L503: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC))
    {
      return 46;
    }
 L516: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC && ! TARGET_POWERPC64))
    {
      return 47;
    }
  goto ret0;

 L560: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == GT)
    goto L561;
  goto ret0;

 L561: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L562;
    }
  goto ret0;

 L562: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L563;
    }
  goto ret0;

 L563: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L564;
  goto ret0;

 L564: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == MINUS)
    goto L565;
  goto ret0;

 L565: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L566;
  goto ret0;

 L566: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[1]))
    goto L567;
  goto ret0;

 L567: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L568;
  goto ret0;

 L568: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L569;
  goto ret0;

 L569: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L570;
    }
  goto ret0;

 L570: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IF_THEN_ELSE)
    goto L571;
  goto ret0;

 L571: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == GT)
    goto L572;
  goto ret0;

 L572: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L573;
  goto ret0;

 L573: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L574;
  goto ret0;

 L574: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L575;
  goto ret0;

 L575: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MINUS)
    goto L576;
  goto ret0;

 L576: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L577;
  goto ret0;

 L577: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[1])
      && (TARGET_POWER))
    {
      return 50;
    }
  goto ret0;

 L732: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L733;
    }
  goto ret0;

 L733: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L734;
    }
  goto ret0;

 L734: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L735;
  goto ret0;

 L735: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L736;
  goto ret0;

 L736: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L737;
    }
  goto ret0;

 L737: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MULT)
    goto L738;
  goto ret0;

 L738: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L739;
  goto ret0;

 L739: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 63;
    }
 L752: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWER))
    {
      return 64;
    }
  goto ret0;

 L833: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L834;
    }
  goto ret0;

 L834: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (exact_log2_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L835;
    }
  goto ret0;

 L835: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L836;
  goto ret0;

 L836: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L837;
  goto ret0;

 L837: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L838;
    }
  goto ret0;

 L838: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == DIV)
    goto L839;
  goto ret0;

 L839: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L840;
  goto ret0;

 L840: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    {
      return 72;
    }
  goto ret0;

 L1071: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1072;
    }
  goto L12703;

 L1072: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (and_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1073;
    }
 L1138: ATTRIBUTE_UNUSED_LABEL
  if (mask_operand_wrap (x4, SImode))
    {
      operands[2] = x4;
      goto L1139;
    }
  goto L12703;

 L1073: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1074;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L1138;

 L1074: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1075;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L1138;

 L1075: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1076;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L1138;

 L1076: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1077;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L1138;

 L1077: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1078;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L1138;

 L1078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 83;
    }
 L1107: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 84;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L1138;

 L1139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1140;
  x3 = XEXP (x2, 0);
  goto L12703;

 L1140: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1141;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12703;

 L1141: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1142;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12703;

 L1142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12703;

 L1143: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1144;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12703;

 L1144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 87;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12703;

 L1553: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1554;
    }
  goto ret0;

 L1554: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1555;
    }
  goto ret0;

 L1555: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1556;
  goto ret0;

 L1556: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1557;
  goto ret0;

 L1557: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1558;
    }
  goto ret0;

 L1558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ROTATE)
    goto L1559;
  goto ret0;

 L1559: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1560;
  goto ret0;

 L1560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    {
      return 119;
    }
  goto ret0;

 L1639: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12719;
    case HImode:
      goto L12720;
    default:
      break;
    }
  goto ret0;

 L12719: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L1640;
  goto ret0;

 L1640: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12721;
  goto ret0;

 L12721: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ROTATE:
      goto L1641;
    case LSHIFTRT:
      goto L2029;
    default:
     break;
   }
  goto ret0;

 L1641: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L1642;
    }
  goto ret0;

 L1642: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L1643;
    }
  goto ret0;

 L1643: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1644;
  goto ret0;

 L1644: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1645;
  goto ret0;

 L1645: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1646;
    }
  goto ret0;

 L1646: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L1647;
  goto ret0;

 L1647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L1648;
  goto ret0;

 L1648: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == ROTATE)
    goto L1649;
  goto ret0;

 L1649: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L1650;
  goto ret0;

 L1650: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    {
      return 125;
    }
  goto ret0;

 L2029: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2030;
    }
  goto ret0;

 L2030: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2031;
    }
  goto ret0;

 L2031: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2032;
  goto ret0;

 L2032: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2033;
  goto ret0;

 L2033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2034;
    }
  goto ret0;

 L2034: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2035;
  goto ret0;

 L2035: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L2036;
  goto ret0;

 L2036: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L2037;
  goto ret0;

 L2037: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L2038;
  goto ret0;

 L2038: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2])
      && (includes_rshift_p (operands[2], GEN_INT (255))))
    {
      return 149;
    }
  goto ret0;

 L12720: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L1685;
  goto ret0;

 L1685: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12723;
  goto ret0;

 L12723: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ROTATE:
      goto L1686;
    case LSHIFTRT:
      goto L2076;
    default:
     break;
   }
  goto ret0;

 L1686: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L1687;
    }
  goto ret0;

 L1687: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L1688;
    }
  goto ret0;

 L1688: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1689;
  goto ret0;

 L1689: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1690;
  goto ret0;

 L1690: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1691;
    }
  goto ret0;

 L1691: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L1692;
  goto ret0;

 L1692: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L1693;
  goto ret0;

 L1693: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == ROTATE)
    goto L1694;
  goto ret0;

 L1694: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L1695;
  goto ret0;

 L1695: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    {
      return 128;
    }
  goto ret0;

 L2076: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2077;
    }
  goto ret0;

 L2077: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2078;
    }
  goto ret0;

 L2078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2079;
  goto ret0;

 L2079: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2080;
  goto ret0;

 L2080: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2081;
    }
  goto ret0;

 L2081: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2082;
  goto ret0;

 L2082: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L2083;
  goto ret0;

 L2083: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L2084;
  goto ret0;

 L2084: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L2085;
  goto ret0;

 L2085: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2])
      && (includes_rshift_p (operands[2], GEN_INT (65535))))
    {
      return 152;
    }
  goto ret0;

 L1776: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1777;
    }
  goto ret0;

 L1777: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1778;
    }
  goto ret0;

 L1778: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1779;
  goto ret0;

 L1779: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1780;
  goto ret0;

 L1780: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1781;
    }
  goto ret0;

 L1781: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L1782;
  goto ret0;

 L1782: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1783;
  goto ret0;

 L1783: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 133;
    }
 L1796: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWER && ! TARGET_POWERPC64))
    {
      return 134;
    }
  goto ret0;

 L1924: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1925;
    }
  goto ret0;

 L1925: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1926;
    }
  goto ret0;

 L1926: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1927;
  goto ret0;

 L1927: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1928;
  goto ret0;

 L1928: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1929;
    }
  goto ret0;

 L1929: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L1930;
  goto ret0;

 L1930: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1931;
  goto ret0;

 L1931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 142;
    }
 L1944: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWER && ! TARGET_POWERPC64))
    {
      return 143;
    }
  goto ret0;

 L2191: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2192;
    }
  goto ret0;

 L2192: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2193;
    }
  goto ret0;

 L2193: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2194;
  goto ret0;

 L2194: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2195;
  goto ret0;

 L2195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2196;
    }
  goto ret0;

 L2196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L2197;
  goto ret0;

 L2197: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2198;
  goto ret0;

 L2198: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 160;
    }
 L2211: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWER))
    {
      return 161;
    }
  goto ret0;

 L1173: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12726;
  goto ret0;

 L12726: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L1211;
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1174;
    }
  goto ret0;

 L1211: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1212;
    }
  goto ret0;

 L1212: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode)
    goto L12728;
  goto ret0;

 L12728: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L1254;
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1213;
    }
  goto ret0;

 L1254: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1255;
    }
  goto ret0;

 L1255: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1256;
  goto ret0;

 L1256: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1257;
  goto ret0;

 L1257: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1258;
    }
  goto ret0;

 L1258: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[4])
      && (! TARGET_POWERPC64))
    {
      return 96;
    }
  goto ret0;

 L1213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1214;
  goto ret0;

 L1214: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1215;
  goto ret0;

 L1215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1216;
    }
  goto ret0;

 L1216: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[4])
      && (! TARGET_POWERPC64))
    {
      return 93;
    }
  goto ret0;

 L1174: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1175;
    }
  goto ret0;

 L1175: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1176;
  goto ret0;

 L1176: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1177;
  goto ret0;

 L1177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1178;
    }
  goto ret0;

 L1178: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[4])
      && (! TARGET_POWERPC64))
    {
      return 90;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_17 PARAMS ((rtx, rtx, int *));
static int
recog_17 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L2847;
    case MINUS:
      goto L2916;
    case DIV:
      goto L3044;
    case ROTATE:
      goto L3093;
    case ZERO_EXTEND:
      goto L3183;
    case ASHIFT:
      goto L3318;
    case LSHIFTRT:
      goto L3449;
    case ASHIFTRT:
      goto L3486;
    case AND:
      goto L3550;
    default:
     break;
   }
 L12718: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x3, DImode))
    {
      operands[4] = x3;
      goto L3587;
    }
  goto ret0;

 L2847: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2848;
    }
  goto ret0;

 L2848: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2849;
    }
  goto ret0;

 L2849: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2850;
  goto ret0;

 L2850: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2851;
  goto ret0;

 L2851: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2852;
    }
  goto ret0;

 L2852: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L2853;
  goto ret0;

 L2853: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2854;
  goto ret0;

 L2854: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 234;
    }
  goto ret0;

 L2916: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2917;
    }
  goto ret0;

 L2917: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2918;
    }
  goto ret0;

 L2918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2919;
  goto ret0;

 L2919: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2920;
  goto ret0;

 L2920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2921;
    }
  goto ret0;

 L2921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MINUS)
    goto L2922;
  goto ret0;

 L2922: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2923;
  goto ret0;

 L2923: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 240;
    }
  goto ret0;

 L3044: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3045;
    }
  goto ret0;

 L3045: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (exact_log2_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3046;
    }
  goto ret0;

 L3046: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3047;
  goto ret0;

 L3047: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3048;
  goto ret0;

 L3048: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3049;
    }
  goto ret0;

 L3049: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == DIV)
    goto L3050;
  goto ret0;

 L3050: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3051;
  goto ret0;

 L3051: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 252;
    }
  goto ret0;

 L3093: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3094;
    }
  goto ret0;

 L3094: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3095;
    }
  goto ret0;

 L3095: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3096;
  goto ret0;

 L3096: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3097;
  goto ret0;

 L3097: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3098;
    }
  goto ret0;

 L3098: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ROTATE)
    goto L3099;
  goto ret0;

 L3099: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3100;
  goto ret0;

 L3100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 257;
    }
  goto ret0;

 L3183: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L12729;
    case HImode:
      goto L12730;
    case SImode:
      goto L12731;
    default:
      break;
    }
  goto ret0;

 L12729: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L3184;
  goto ret0;

 L3184: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L3185;
  goto ret0;

 L3185: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L3186;
    }
  goto ret0;

 L3186: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L3187;
    }
  goto ret0;

 L3187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3188;
  goto ret0;

 L3188: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3189;
  goto ret0;

 L3189: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3190;
    }
  goto ret0;

 L3190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3191;
  goto ret0;

 L3191: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L3192;
  goto ret0;

 L3192: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ROTATE)
    goto L3193;
  goto ret0;

 L3193: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L3194;
  goto ret0;

 L3194: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2])
      && (TARGET_POWERPC64))
    {
      return 263;
    }
  goto ret0;

 L12730: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L3231;
  goto ret0;

 L3231: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L3232;
  goto ret0;

 L3232: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L3233;
    }
  goto ret0;

 L3233: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L3234;
    }
  goto ret0;

 L3234: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3235;
  goto ret0;

 L3235: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3236;
  goto ret0;

 L3236: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3237;
    }
  goto ret0;

 L3237: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3238;
  goto ret0;

 L3238: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L3239;
  goto ret0;

 L3239: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ROTATE)
    goto L3240;
  goto ret0;

 L3240: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L3241;
  goto ret0;

 L3241: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2])
      && (TARGET_POWERPC64))
    {
      return 266;
    }
  goto ret0;

 L12731: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L3278;
  goto ret0;

 L3278: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L3279;
  goto ret0;

 L3279: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L3280;
    }
  goto ret0;

 L3280: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L3281;
    }
  goto ret0;

 L3281: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3282;
  goto ret0;

 L3282: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3283;
  goto ret0;

 L3283: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3284;
    }
  goto ret0;

 L3284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3285;
  goto ret0;

 L3285: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L3286;
  goto ret0;

 L3286: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ROTATE)
    goto L3287;
  goto ret0;

 L3287: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L3288;
  goto ret0;

 L3288: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2])
      && (TARGET_POWERPC64))
    {
      return 269;
    }
  goto ret0;

 L3318: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3319;
    }
  goto ret0;

 L3319: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3320;
    }
  goto ret0;

 L3320: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3321;
  goto ret0;

 L3321: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3322;
  goto ret0;

 L3322: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3323;
    }
  goto ret0;

 L3323: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ASHIFT)
    goto L3324;
  goto ret0;

 L3324: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3325;
  goto ret0;

 L3325: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 272;
    }
  goto ret0;

 L3449: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3450;
    }
  goto ret0;

 L3450: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3451;
    }
  goto ret0;

 L3451: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3452;
  goto ret0;

 L3452: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3453;
  goto ret0;

 L3453: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3454;
    }
  goto ret0;

 L3454: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L3455;
  goto ret0;

 L3455: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3456;
  goto ret0;

 L3456: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 281;
    }
  goto ret0;

 L3486: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3487;
    }
  goto ret0;

 L3487: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3488;
    }
  goto ret0;

 L3488: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3489;
  goto ret0;

 L3489: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3490;
  goto ret0;

 L3490: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3491;
    }
  goto ret0;

 L3491: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L3492;
  goto ret0;

 L3492: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3493;
  goto ret0;

 L3493: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 284;
    }
  goto ret0;

 L3550: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3551;
    }
  goto L12718;

 L3551: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (and64_2_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3552;
    }
  goto L12718;

 L3552: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3553;
  x3 = XEXP (x2, 0);
  goto L12718;

 L3553: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3554;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12718;

 L3554: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3555;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12718;

 L3555: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == AND)
    goto L3556;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12718;

 L3556: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3557;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12718;

 L3557: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 287;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L12718;

 L3587: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L12733;
  goto ret0;

 L12733: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L3626;
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3588;
    }
  goto ret0;

 L3626: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3627;
    }
  goto ret0;

 L3627: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode)
    goto L12735;
  goto ret0;

 L12735: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L3670;
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3628;
    }
  goto ret0;

 L3670: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3671;
    }
  goto ret0;

 L3671: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3672;
  goto ret0;

 L3672: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3673;
  goto ret0;

 L3673: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3674;
    }
  goto ret0;

 L3674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[4])
      && (TARGET_POWERPC64))
    {
      return 296;
    }
  goto ret0;

 L3628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3629;
  goto ret0;

 L3629: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3630;
  goto ret0;

 L3630: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3631;
    }
  goto ret0;

 L3631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[4])
      && (TARGET_POWERPC64))
    {
      return 293;
    }
  goto ret0;

 L3588: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3589;
    }
  goto ret0;

 L3589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3590;
  goto ret0;

 L3590: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3591;
  goto ret0;

 L3591: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3592;
    }
  goto ret0;

 L3592: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[4])
      && (TARGET_POWERPC64))
    {
      return 290;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_18 PARAMS ((rtx, rtx, int *));
static int
recog_18 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case IOR:
      goto L1307;
    case ZERO_EXTRACT:
      goto L1474;
    case AND:
      goto L1594;
    default:
     break;
   }
  goto ret0;

 L1307: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == AND)
    goto L1308;
  goto ret0;

 L1308: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12740;
  goto ret0;

 L12740: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x5) == NOT)
    goto L1309;
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1355;
    }
 L12742: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x5, SImode))
    {
      operands[3] = x5;
      goto L1378;
    }
  goto ret0;

 L1309: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L1310;
    }
  goto ret0;

 L1310: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1311;
    }
  goto ret0;

 L1311: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == AND)
    goto L1312;
  goto ret0;

 L1312: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L1313;
 L1335: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x5, SImode))
    {
      operands[3] = x5;
      goto L1336;
    }
  goto ret0;

 L1313: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[3] = x5;
      goto L1314;
    }
  x5 = XEXP (x4, 0);
  goto L1335;

 L1314: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1315;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1315: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1316;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1316: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1317;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1317: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IOR)
    goto L1318;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1318: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1319;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1319: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NOT)
    goto L1320;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1320: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L1321;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1321: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[1]))
    goto L1322;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1322: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1323;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1323: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L1324;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1324: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[3])
      && (TARGET_POWER))
    {
      return 101;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  goto L1335;

 L1336: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    goto L1337;
  goto ret0;

 L1337: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1338;
  goto ret0;

 L1338: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1339;
  goto ret0;

 L1339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1340;
    }
  goto ret0;

 L1340: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IOR)
    goto L1341;
  goto ret0;

 L1341: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1342;
  goto ret0;

 L1342: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NOT)
    goto L1343;
  goto ret0;

 L1343: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L1344;
  goto ret0;

 L1344: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[1]))
    goto L1345;
  goto ret0;

 L1345: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1346;
  goto ret0;

 L1346: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[3]))
    goto L1347;
  goto ret0;

 L1347: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_POWER))
    {
      return 102;
    }
  goto ret0;

 L1355: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[3] = x5;
      goto L1356;
    }
  x5 = XEXP (x4, 0);
  goto L12742;

 L1356: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == AND)
    goto L1357;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1357: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == NOT)
    goto L1358;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1358: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[2]))
    goto L1359;
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1359: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1360;
    }
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1360: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1361;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1361: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1362;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1363;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1363: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IOR)
    goto L1364;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1364: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1365;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1365: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L1366;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1366: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[3]))
    goto L1367;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1367: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1368;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1368: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NOT)
    goto L1369;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1369: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L1370;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1370: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[1])
      && (TARGET_POWER))
    {
      return 103;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  goto L12742;

 L1378: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1379;
    }
  goto ret0;

 L1379: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == AND)
    goto L1380;
  goto ret0;

 L1380: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == NOT)
    goto L1381;
  goto ret0;

 L1381: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[2]))
    goto L1382;
  goto ret0;

 L1382: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1383;
    }
  goto ret0;

 L1383: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1384;
  goto ret0;

 L1384: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1385;
  goto ret0;

 L1385: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1386;
    }
  goto ret0;

 L1386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IOR)
    goto L1387;
  goto ret0;

 L1387: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1388;
  goto ret0;

 L1388: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[3]))
    goto L1389;
  goto ret0;

 L1389: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L1390;
  goto ret0;

 L1390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L1391;
  goto ret0;

 L1391: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NOT)
    goto L1392;
  goto ret0;

 L1392: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L1393;
  goto ret0;

 L1393: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[1])
      && (TARGET_POWER))
    {
      return 104;
    }
  goto ret0;

 L1474: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1475;
    }
  goto ret0;

 L1475: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1476;
    }
  goto ret0;

 L1476: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1477;
    }
  goto ret0;

 L1477: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1478;
  goto ret0;

 L1478: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1479;
  goto ret0;

 L1479: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1480;
    }
  goto ret0;

 L1480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1481;
  goto ret0;

 L1481: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1482;
  goto ret0;

 L1482: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L1483;
  goto ret0;

 L1483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[3]))
    {
      return 113;
    }
  goto ret0;

 L1594: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12743;
  goto ret0;

 L12743: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L1595;
    case ASHIFT:
      goto L1833;
    case LSHIFTRT:
      goto L1981;
    default:
     break;
   }
  goto ret0;

 L1595: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1596;
    }
  goto ret0;

 L1596: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1597;
    }
  goto ret0;

 L1597: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1598;
    }
  goto ret0;

 L1598: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1599;
  goto ret0;

 L1599: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1600;
  goto ret0;

 L1600: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1601;
    }
  goto ret0;

 L1601: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1602;
  goto ret0;

 L1602: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ROTATE)
    goto L1603;
  goto ret0;

 L1603: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1604;
  goto ret0;

 L1604: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L1605;
  goto ret0;

 L1605: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3]))
    {
      return 122;
    }
  goto ret0;

 L1833: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1834;
    }
  goto ret0;

 L1834: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1835;
    }
  goto ret0;

 L1835: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1836;
    }
  goto ret0;

 L1836: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1837;
  goto ret0;

 L1837: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1838;
  goto ret0;

 L1838: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1839;
    }
  goto ret0;

 L1839: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1840;
  goto ret0;

 L1840: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ASHIFT)
    goto L1841;
  goto ret0;

 L1841: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1842;
  goto ret0;

 L1842: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L1843;
  goto ret0;

 L1843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (includes_lshift_p (operands[2], operands[3])))
    {
      return 137;
    }
  goto ret0;

 L1981: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1982;
    }
  goto ret0;

 L1982: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1983;
    }
  goto ret0;

 L1983: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1984;
    }
  goto ret0;

 L1984: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1985;
  goto ret0;

 L1985: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1986;
  goto ret0;

 L1986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1987;
    }
  goto ret0;

 L1987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1988;
  goto ret0;

 L1988: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L1989;
  goto ret0;

 L1989: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1990;
  goto ret0;

 L1990: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L1991;
  goto ret0;

 L1991: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (includes_rshift_p (operands[2], operands[3])))
    {
      return 146;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_19 PARAMS ((rtx, rtx, int *));
static int
recog_19 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == MEM)
    goto L4608;
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L586;
    }
 L12589: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L867;
 L12595: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2702;
    }
 L12600: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4596;
    }
 L12610: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4797;
    }
  goto ret0;

 L4608: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4609;
  goto ret0;

 L4609: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4610;
    }
  goto ret0;

 L4610: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4611;
    }
  goto ret0;

 L4611: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4612;
    }
  goto ret0;

 L4612: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4613;
  goto ret0;

 L4613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4614;
    }
  goto ret0;

 L4614: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4615;
  goto ret0;

 L4615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4616;
  goto ret0;

 L4616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 355;
    }
  goto ret0;

 L586: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12750;
  x2 = XEXP (x1, 0);
  goto L12589;

 L12750: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L587;
    case NEG:
      goto L606;
    case MULT:
      goto L656;
    case DIV:
      goto L757;
    case UDIV:
      goto L768;
    case AND:
      goto L1000;
    case ASHIFT:
      goto L1700;
    case LSHIFTRT:
      goto L1848;
    case ASHIFTRT:
      goto L2115;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12589;

 L587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L588;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L588: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L589;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L590;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L590: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_ISEL))
    {
      return 52;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L606: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ABS)
    goto L607;
  x2 = XEXP (x1, 0);
  goto L12589;

 L607: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L608;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L608: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L609;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L609: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L610;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L610: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER))
    {
      return 54;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L656: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L657;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L657: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L658;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L658: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L659;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L660;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L660: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 59;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L757: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L758;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L758: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L759;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L759: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L760;
    case CLOBBER:
      goto L792;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L760: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L761;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L761: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L762;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L762: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L763;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L763: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER))
    {
      return 65;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L792: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L793;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L793: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER))
    {
      return 68;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L768: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12759;
    case DImode:
      goto L12760;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L12759: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L769;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L769: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L770;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L770: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L771;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L771: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L772;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L772: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER))
    {
      return 66;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L12760: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == PLUS)
    goto L846;
  x2 = XEXP (x1, 0);
  goto L12589;

 L846: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ASHIFT)
    goto L847;
  x2 = XEXP (x1, 0);
  goto L12589;

 L847: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L848;
  x2 = XEXP (x1, 0);
  goto L12589;

 L848: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L849;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L849: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L850;
  x2 = XEXP (x1, 0);
  goto L12589;

 L850: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L851;
  x2 = XEXP (x1, 0);
  goto L12589;

 L851: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[4] = x5;
      goto L852;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L852: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L853;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L853: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L854;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L854: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L855;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L855: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L856;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L856: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L857;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L857: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ASHIFT)
    goto L858;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L858: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L859;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L859: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[1]))
    goto L860;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L860: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L861;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L861: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L862;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L862: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[4]))
    goto L863;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L863: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWER))
    {
      return 73;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1000: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1001;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L1001: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (and_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1002;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L1002: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1003;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1003: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      return 80;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1700: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1701;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L1701: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1702;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L1702: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1703;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1703: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1704;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1704: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 129;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1848: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1849;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L1849: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1850;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L1850: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1851;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1851: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1852;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L1852: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 138;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L2115: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2116;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L2116: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2117;
    }
  x2 = XEXP (x1, 0);
  goto L12589;

 L2117: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2118;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L2118: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2119;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L2119: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 156;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12589;

 L867: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12761;
  x2 = XEXP (x1, 0);
  goto L12595;

 L12761: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case TRUNCATE:
      goto L868;
    case DIV:
      goto L926;
    case UDIV:
      goto L956;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12595;

 L868: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L869;
  x2 = XEXP (x1, 0);
  goto L12595;

 L869: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L870;
  x2 = XEXP (x1, 0);
  goto L12595;

 L870: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L871;
  x2 = XEXP (x1, 0);
  goto L12595;

 L871: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == SImode
      && GET_CODE (x6) == REG
      && XINT (x6, 0) == 3)
    goto L872;
  x2 = XEXP (x1, 0);
  goto L12595;

 L872: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L873;
  x2 = XEXP (x1, 0);
  goto L12595;

 L873: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == SImode
      && GET_CODE (x6) == REG
      && XINT (x6, 0) == 4)
    goto L874;
  x2 = XEXP (x1, 0);
  goto L12595;

 L874: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L875;
  x2 = XEXP (x1, 0);
  goto L12595;

 L875: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L876;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L876: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L877;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L877: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC))
    {
      return 74;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L926: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L927;
  x2 = XEXP (x1, 0);
  goto L12595;

 L927: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L928;
  x2 = XEXP (x1, 0);
  goto L12595;

 L928: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L929;
    case CLOBBER:
      goto L970;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L929: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 4)
    goto L930;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L930: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L931;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L932;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L932: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4
      && (! TARGET_POWER && ! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 76;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L970: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L971;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L971: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC))
    {
      return 78;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L957;
  x2 = XEXP (x1, 0);
  goto L12595;

 L957: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L958;
  x2 = XEXP (x1, 0);
  goto L12595;

 L958: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L959;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L959: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 4)
    goto L960;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L961;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L961: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L962;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L962: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4
      && (! TARGET_POWER && ! TARGET_POWERPC)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 4;
      return 77;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12595;

 L2702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12764;
  x2 = XEXP (x1, 0);
  goto L12600;

 L12764: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case TRUNCATE:
      goto L2703;
    case FIX:
      goto L3816;
    case UNSPEC:
      goto L12767;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12600;

 L2703: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L2704;
  x2 = XEXP (x1, 0);
  goto L12600;

 L2704: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L2705;
  x2 = XEXP (x1, 0);
  goto L12600;

 L2705: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L12768;
  x2 = XEXP (x1, 0);
  goto L12600;

 L12768: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case SIGN_EXTEND:
      goto L2706;
    case ZERO_EXTEND:
      goto L2740;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12600;

 L2706: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2707;
    }
  x2 = XEXP (x1, 0);
  goto L12600;

 L2707: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L2708;
  x2 = XEXP (x1, 0);
  goto L12600;

 L2708: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2709;
    }
  x2 = XEXP (x1, 0);
  goto L12600;

 L2709: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L2710;
  x2 = XEXP (x1, 0);
  goto L12600;

 L2710: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2711;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L2711: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2712;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L2712: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 224;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L2740: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2741;
    }
  x2 = XEXP (x1, 0);
  goto L12600;

 L2741: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L2742;
  x2 = XEXP (x1, 0);
  goto L12600;

 L2742: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2743;
    }
  x2 = XEXP (x1, 0);
  goto L12600;

 L2743: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L2744;
  x2 = XEXP (x1, 0);
  goto L12600;

 L2744: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2745;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L2745: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2746;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L2746: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER))
    {
      return 226;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L3816: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L3817;
    }
  x2 = XEXP (x1, 0);
  goto L12600;

 L3817: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3818;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L3818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3819;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L3819: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 319;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L12767: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 7)
    goto L4780;
  x2 = XEXP (x1, 0);
  goto L12600;

 L4780: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4781;
  x2 = XEXP (x1, 0);
  goto L12600;

 L4781: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4782;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L4782: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2
      && (DEFAULT_ABI == ABI_AIX && TARGET_32BIT))
    {
      return 369;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12600;

 L4596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12770;
  x2 = XEXP (x1, 0);
  goto L12610;

 L12770: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L4597;
    case ZERO_EXTEND:
      goto L4633;
    case SIGN_EXTEND:
      goto L4646;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4598;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4598: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4599;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4599: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4600;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4600: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4601;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4601: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4602;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4602: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4603;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4603: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4604;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    {
      return 354;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4633: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case HImode:
      goto L12773;
    case QImode:
      goto L12774;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L12773: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == MEM)
    goto L4634;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4634: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L4635;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4635: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L4636;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4636: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L4637;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4637: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4638;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4638: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4639;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4639: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4640;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4640: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4641;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 357;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L12774: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == MEM)
    goto L4684;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4684: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L4685;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4685: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L4686;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4686: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L4687;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4687: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4688;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4688: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4689;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4689: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4690;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4690: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4691;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4691: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 361;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == MEM)
    goto L4647;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4647: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L4648;
  x2 = XEXP (x1, 0);
  goto L12610;

 L4648: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L4649;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4649: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L4650;
    }
  x2 = XEXP (x1, 0);
  goto L12610;

 L4650: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4651;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4651: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4652;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4652: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4653;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4653: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4654;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4654: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 358;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12610;

 L4797: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4798;
    }
  goto ret0;

 L4798: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC)
    goto L12775;
  goto ret0;

 L12775: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L12777;
    case 2:
      goto L12778;
    default:
      break;
    }
  goto ret0;

 L12777: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 7)
    goto L4799;
  goto ret0;

 L4799: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, operands[1])
      && (TARGET_ELF && DEFAULT_ABI != ABI_AIX && flag_pic == 2))
    {
      return 372;
    }
  goto ret0;

 L12778: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 6)
    goto L4805;
  goto ret0;

 L4805: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L4806;
  goto ret0;

 L4806: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L4807;
    }
  goto ret0;

 L4807: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ELF && DEFAULT_ABI != ABI_AIX && flag_pic == 2))
    {
      return 373;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_20 PARAMS ((rtx, rtx, int *));
static int
recog_20 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case CCmode:
      goto L12585;
    case SImode:
      goto L12601;
    case SFmode:
      goto L12607;
    case DImode:
      goto L12599;
    case TFmode:
      goto L12596;
    case TImode:
      goto L12597;
    case HImode:
      goto L12603;
    case QImode:
      goto L12605;
    case DFmode:
      goto L12609;
    default:
      break;
    }
  goto ret0;

 L12585: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[0] = x2;
      goto L8;
    }
 L12586: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[2] = x2;
      goto L24;
    }
 L12587: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L402;
    }
 L12590: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L1305;
    }
 L12591: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, CCmode))
    {
      operands[0] = x2;
      goto L1494;
    }
 L12592: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L1514;
    }
  goto ret0;

 L8: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L9;
  x2 = XEXP (x1, 0);
  goto L12586;

 L9: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L12611;
    case SImode:
      goto L12613;
    case HImode:
      goto L12615;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12586;

 L12611: ATTRIBUTE_UNUSED_LABEL
  tem = recog_13 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12586;

 L12613: ATTRIBUTE_UNUSED_LABEL
  tem = recog_14 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12586;

 L12615: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L263;
    case SIGN_EXTEND:
      goto L294;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12586;

 L263: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L264;
    }
  x2 = XEXP (x1, 0);
  goto L12586;

 L264: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L265;
  x2 = XEXP (x1, 0);
  goto L12586;

 L265: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L266;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12586;

 L266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[2] = x2;
      return 25;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12586;

 L294: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L295;
    }
  x2 = XEXP (x1, 0);
  goto L12586;

 L295: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L296;
  x2 = XEXP (x1, 0);
  goto L12586;

 L296: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L297;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12586;

 L297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L298;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12586;

 L298: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC))
    {
      return 28;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12586;

 L24: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L25;
  x2 = XEXP (x1, 0);
  goto L12587;

 L25: ATTRIBUTE_UNUSED_LABEL
  tem = recog_15 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12587;

 L402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L403;
  x2 = XEXP (x1, 0);
  goto L12590;

 L403: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12697;
    case DImode:
      goto L12709;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12590;

 L12697: ATTRIBUTE_UNUSED_LABEL
  tem = recog_16 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12590;

 L12709: ATTRIBUTE_UNUSED_LABEL
  tem = recog_17 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12590;

 L1305: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L1306;
  x2 = XEXP (x1, 0);
  goto L12591;

 L1306: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12736;
    case DImode:
      goto L12739;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L12736: ATTRIBUTE_UNUSED_LABEL
  tem = recog_18 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12591;

 L12739: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == AND)
    goto L3136;
  x2 = XEXP (x1, 0);
  goto L12591;

 L3136: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L12746;
  x2 = XEXP (x1, 0);
  goto L12591;

 L12746: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L3137;
    case ASHIFT:
      goto L3362;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3137: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3138;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3138: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L3139;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3139: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask64_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L3140;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3140: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3141;
  x2 = XEXP (x1, 0);
  goto L12591;

 L3141: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3142;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3143;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3143: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == AND)
    goto L3144;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ROTATE)
    goto L3145;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3145: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3146;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3146: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L3147;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3147: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWERPC64))
    {
      return 260;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3362: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L3363;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3363: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L3364;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3364: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L12748;
  x2 = XEXP (x1, 0);
  goto L12591;

 L12748: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L3365;
    }
 L12749: ATTRIBUTE_UNUSED_LABEL
  if (mask64_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L3412;
    }
  x2 = XEXP (x1, 0);
  goto L12591;

 L3365: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3366;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3366: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3367;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3367: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3368;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3368: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == AND)
    goto L3369;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3369: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ASHIFT)
    goto L3370;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3370: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3371;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3371: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L3372;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3372: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWERPC64 && includes_rldic_lshift_p (operands[2], operands[3])))
    {
      return 275;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L12749;

 L3412: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3413;
  x2 = XEXP (x1, 0);
  goto L12591;

 L3413: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3414;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3414: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3415;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3415: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == AND)
    goto L3416;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3416: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ASHIFT)
    goto L3417;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3417: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3418;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3418: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L3419;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L3419: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWERPC64 && includes_rldicr_lshift_p (operands[2], operands[3])))
    {
      return 278;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12591;

 L1494: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L1495;
  x2 = XEXP (x1, 0);
  goto L12592;

 L1495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L1496;
  x2 = XEXP (x1, 0);
  goto L12592;

 L1496: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L1497;
    }
  x2 = XEXP (x1, 0);
  goto L12592;

 L1497: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1498;
    }
  x2 = XEXP (x1, 0);
  goto L12592;

 L1498: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1499;
    }
  x2 = XEXP (x1, 0);
  goto L12592;

 L1499: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1500;
  x2 = XEXP (x1, 0);
  goto L12592;

 L1500: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1501;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12592;

 L1501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L1502;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12592;

 L1502: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 115;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12592;

 L1514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L1515;
  goto ret0;

 L1515: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L1516;
  goto ret0;

 L1516: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L1517;
    }
  goto ret0;

 L1517: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1518;
    }
  goto ret0;

 L1518: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1519;
    }
  goto ret0;

 L1519: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1520;
  goto ret0;

 L1520: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1521;
  goto ret0;

 L1521: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1522;
    }
  goto ret0;

 L1522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1523;
  goto ret0;

 L1523: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1524;
  goto ret0;

 L1524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L1525;
  goto ret0;

 L1525: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWERPC64))
    {
      return 116;
    }
  goto ret0;

 L12601: ATTRIBUTE_UNUSED_LABEL
  return recog_19 (x0, insn, pnum_clobbers);

 L12607: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4719;
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L2618;
    }
 L12606: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L4707;
    }
  goto ret0;

 L4719: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4720;
  goto ret0;

 L4720: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4721;
    }
  goto ret0;

 L4721: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4722;
    }
  goto ret0;

 L4722: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L4723;
    }
  goto ret0;

 L4723: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4724;
  goto ret0;

 L4724: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4725;
    }
  goto ret0;

 L4725: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4726;
  goto ret0;

 L4726: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4727;
  goto ret0;

 L4727: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_UPDATE))
    {
      return 364;
    }
 L4751: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && ((TARGET_SOFT_FLOAT || !TARGET_FPRS) && TARGET_UPDATE))
    {
      return 366;
    }
  goto ret0;

 L2618: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L12779;
  x2 = XEXP (x1, 0);
  goto L12606;

 L12779: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L2619;
    case FLOAT_TRUNCATE:
      goto L3764;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12606;

 L2619: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2620;
    }
  x2 = XEXP (x1, 0);
  goto L12606;

 L2620: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2621;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12606;

 L2621: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L2622;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12606;

 L2622: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 216;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12606;

 L3764: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L3765;
    }
  x2 = XEXP (x1, 0);
  goto L12606;

 L3765: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3766;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12606;

 L3766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3767;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12606;

 L3767: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT
   && TARGET_FPRS && TARGET_LONG_DOUBLE_128))
    {
      return 315;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12606;

 L4707: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == MEM)
    goto L4708;
  goto ret0;

 L4708: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4709;
  goto ret0;

 L4709: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4710;
    }
  goto ret0;

 L4710: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4711;
    }
  goto ret0;

 L4711: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4712;
  goto ret0;

 L4712: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4713;
    }
  goto ret0;

 L4713: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4714;
  goto ret0;

 L4714: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4715;
  goto ret0;

 L4715: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_UPDATE))
    {
      return 363;
    }
 L4739: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[2])
      && ((TARGET_SOFT_FLOAT || !TARGET_FPRS) && TARGET_UPDATE))
    {
      return 365;
    }
  goto ret0;

 L12599: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4584;
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2648;
    }
 L12598: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L4559;
    }
  goto ret0;

 L4584: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L4585;
  goto ret0;

 L4585: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4586;
    }
  goto ret0;

 L4586: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_aligned_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L4587;
    }
  goto ret0;

 L4587: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L4588;
    }
  goto ret0;

 L4588: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4589;
  goto ret0;

 L4589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4590;
    }
  goto ret0;

 L4590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L4591;
  goto ret0;

 L4591: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4592;
  goto ret0;

 L4592: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64 && TARGET_UPDATE))
    {
      return 353;
    }
  goto ret0;

 L2648: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L12781;
  x2 = XEXP (x1, 0);
  goto L12598;

 L12781: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L2649;
    case ASHIFT:
      goto L2771;
    case LSHIFTRT:
      goto L2786;
    case ASHIFTRT:
      goto L2801;
    case ABS:
      goto L2928;
    case NEG:
      goto L2941;
    case AND:
      goto L3498;
    case FIX:
      goto L3803;
    case UNSPEC:
      goto L12790;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2649: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L12791;
  x2 = XEXP (x1, 0);
  goto L12598;

 L12791: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L2650;
    case ZERO_EXTEND:
      goto L2677;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2650: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2651;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2651: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L2652;
  x2 = XEXP (x1, 0);
  goto L12598;

 L2652: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2653;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2653: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2654;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2654: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2655;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2655: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 220;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2677: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2678;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2678: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L2679;
  x2 = XEXP (x1, 0);
  goto L12598;

 L2679: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2680;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2680: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2681;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2681: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2682;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2682: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && TARGET_POWER))
    {
      return 222;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2771: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2772;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2772: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2773;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2773: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2774;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2774: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2775;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2775: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 228;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2786: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2787;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2787: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2788;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2788: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2789;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2789: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2790;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2790: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 229;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2801: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2802;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2803;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2803: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2804;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2804: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2805;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2805: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 230;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2928: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2929;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2929: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2930;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2930: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2931;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2931: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 241;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2941: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ABS)
    goto L2942;
  x2 = XEXP (x1, 0);
  goto L12598;

 L2942: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2943;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L2943: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2944;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2944: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2945;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L2945: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 242;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L3498: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3499;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L3499: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (and64_2_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3500;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L3500: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3501;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L3501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L3502;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L3502: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 285;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L3803: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L3804;
    }
  x2 = XEXP (x1, 0);
  goto L12598;

 L3804: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3805;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L3805: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3806;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L3806: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_POWERPC64
   && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_LONG_DOUBLE_128))
    {
      return 318;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L12790: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 7)
    goto L4787;
  x2 = XEXP (x1, 0);
  goto L12598;

 L4787: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4788;
  x2 = XEXP (x1, 0);
  goto L12598;

 L4788: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4789;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L4789: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2
      && (DEFAULT_ABI == ABI_AIX && TARGET_64BIT))
    {
      return 370;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12598;

 L4559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L12793;
  goto ret0;

 L12793: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L4560;
    case SIGN_EXTEND:
      goto L4572;
    default:
     break;
   }
  goto ret0;

 L4560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L4561;
  goto ret0;

 L4561: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4562;
    }
  goto ret0;

 L4562: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_aligned_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L4563;
    }
  goto ret0;

 L4563: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4564;
  goto ret0;

 L4564: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4565;
    }
  goto ret0;

 L4565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L4566;
  goto ret0;

 L4566: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4567;
  goto ret0;

 L4567: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64 && TARGET_UPDATE))
    {
      return 351;
    }
  goto ret0;

 L4572: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L4573;
  goto ret0;

 L4573: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == PLUS)
    goto L4574;
  goto ret0;

 L4574: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L4575;
    }
  goto ret0;

 L4575: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L4576;
    }
  goto ret0;

 L4576: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4577;
  goto ret0;

 L4577: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4578;
    }
  goto ret0;

 L4578: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L4579;
  goto ret0;

 L4579: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4580;
  goto ret0;

 L4580: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 352;
    }
  goto ret0;

 L12596: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, TFmode))
    {
      operands[0] = x2;
      goto L3776;
    }
  goto ret0;

 L3776: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TFmode
      && GET_CODE (x2) == FLOAT)
    goto L3777;
  goto ret0;

 L3777: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L12795;
    case SImode:
      goto L12796;
    default:
      break;
    }
  goto ret0;

 L12795: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3778;
    }
  goto ret0;

 L3778: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3779;
  goto ret0;

 L3779: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3780;
    }
  goto ret0;

 L3780: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_POWERPC64
   && TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_LONG_DOUBLE_128))
    {
      return 316;
    }
  goto ret0;

 L12796: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3791;
    }
  goto ret0;

 L3791: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3792;
  goto ret0;

 L3792: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L3793;
    }
  goto ret0;

 L3793: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX && TARGET_HARD_FLOAT && TARGET_FPRS
   && TARGET_LONG_DOUBLE_128))
    {
      return 317;
    }
  goto ret0;

 L12597: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_mem_operand (x2, TImode))
    {
      operands[0] = x2;
      goto L3861;
    }
  goto ret0;

 L3861: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_mem_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L3862;
    }
  goto ret0;

 L3862: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3863;
  goto ret0;

 L3863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3864;
    }
  goto ret0;

 L3864: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER && ! TARGET_POWERPC64
   && (gpc_reg_operand (operands[0], TImode) || gpc_reg_operand (operands[1], TImode))))
    {
      return 326;
    }
  goto ret0;

 L12603: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4658;
  if (gpc_reg_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L4620;
    }
  goto ret0;

 L4658: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4659;
  goto ret0;

 L4659: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4660;
    }
  goto ret0;

 L4660: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4661;
    }
  goto ret0;

 L4661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L4662;
    }
  goto ret0;

 L4662: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4663;
  goto ret0;

 L4663: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4664;
    }
  goto ret0;

 L4664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4665;
  goto ret0;

 L4665: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4666;
  goto ret0;

 L4666: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 359;
    }
  goto ret0;

 L4620: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MEM)
    goto L4621;
  goto ret0;

 L4621: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4622;
  goto ret0;

 L4622: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4623;
    }
  goto ret0;

 L4623: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4624;
    }
  goto ret0;

 L4624: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4625;
  goto ret0;

 L4625: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4626;
    }
  goto ret0;

 L4626: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4627;
  goto ret0;

 L4627: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4628;
  goto ret0;

 L4628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 356;
    }
  goto ret0;

 L12605: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4695;
  if (gpc_reg_operand (x2, QImode))
    {
      operands[3] = x2;
      goto L4670;
    }
  goto ret0;

 L4695: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4696;
  goto ret0;

 L4696: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4697;
    }
  goto ret0;

 L4697: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4698;
    }
  goto ret0;

 L4698: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, QImode))
    {
      operands[3] = x2;
      goto L4699;
    }
  goto ret0;

 L4699: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4700;
  goto ret0;

 L4700: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4701;
    }
  goto ret0;

 L4701: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4702;
  goto ret0;

 L4702: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4703;
  goto ret0;

 L4703: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 362;
    }
  goto ret0;

 L4670: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MEM)
    goto L4671;
  goto ret0;

 L4671: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4672;
  goto ret0;

 L4672: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4673;
    }
  goto ret0;

 L4673: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4674;
    }
  goto ret0;

 L4674: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4675;
  goto ret0;

 L4675: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4676;
    }
  goto ret0;

 L4676: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4677;
  goto ret0;

 L4677: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4678;
  goto ret0;

 L4678: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_UPDATE))
    {
      return 360;
    }
  goto ret0;

 L12609: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4767;
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L4755;
    }
  goto ret0;

 L4767: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4768;
  goto ret0;

 L4768: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4769;
    }
  goto ret0;

 L4769: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4770;
    }
  goto ret0;

 L4770: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L4771;
    }
  goto ret0;

 L4771: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4772;
  goto ret0;

 L4772: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4773;
    }
  goto ret0;

 L4773: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4774;
  goto ret0;

 L4774: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4775;
  goto ret0;

 L4775: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_UPDATE))
    {
      return 368;
    }
  goto ret0;

 L4755: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == MEM)
    goto L4756;
  goto ret0;

 L4756: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4757;
  goto ret0;

 L4757: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4758;
    }
  goto ret0;

 L4758: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4759;
    }
  goto ret0;

 L4759: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4760;
  goto ret0;

 L4760: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4761;
    }
  goto ret0;

 L4761: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L4762;
  goto ret0;

 L4762: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4763;
  goto ret0;

 L4763: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_HARD_FLOAT && TARGET_FPRS && TARGET_UPDATE))
    {
      return 367;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_21 PARAMS ((rtx, rtx, int *));
static int
recog_21 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (cc_reg_operand (x2, CCmode))
    {
      operands[0] = x2;
      goto L676;
    }
 L12800: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L714;
    }
  goto ret0;

 L676: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L677;
  x2 = XEXP (x1, 0);
  goto L12800;

 L677: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12804;
    case DImode:
      goto L12809;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L12804: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case MULT:
      goto L678;
    case AND:
      goto L1015;
    case ASHIFT:
      goto L1722;
    case LSHIFTRT:
      goto L1870;
    case ASHIFTRT:
      goto L2137;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12800;

 L678: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L679;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L679: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L680;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L680: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L681;
  x2 = XEXP (x1, 0);
  goto L12800;

 L681: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L682;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L682: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L683;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L683: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L684;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L684: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L685;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L685: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 61;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1015: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1016;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L1016: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (and_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1017;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L1017: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1018;
  x2 = XEXP (x1, 0);
  goto L12800;

 L1018: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1019;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1019: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1020;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1020: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1021;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L1022;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1022: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 81;
    }
 L1042: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 82;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1722: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1723;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L1723: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1724;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L1724: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1725;
  x2 = XEXP (x1, 0);
  goto L12800;

 L1725: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1726;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1726: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1727;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1727: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1728;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1728: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1729;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1729: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 131;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1870: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1871;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L1871: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1872;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L1872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1873;
  x2 = XEXP (x1, 0);
  goto L12800;

 L1873: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1874;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1874: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L1875;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1875: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1876;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1876: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1877;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L1877: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 140;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L2137: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2138;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L2138: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2139;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L2139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2140;
  x2 = XEXP (x1, 0);
  goto L12800;

 L2140: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2141;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L2141: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2142;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L2142: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L2143: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L2144;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L2144: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 158;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L12809: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == AND)
    goto L3514;
  x2 = XEXP (x1, 0);
  goto L12800;

 L3514: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3515;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L3515: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (and64_2_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3516;
    }
  x2 = XEXP (x1, 0);
  goto L12800;

 L3516: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3517;
  x2 = XEXP (x1, 0);
  goto L12800;

 L3517: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3518;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L3518: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L3519;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L3519: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3520;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L3520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L3521;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L3521: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 286;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12800;

 L714: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L715;
  goto ret0;

 L715: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12810;
    case DImode:
      goto L12815;
    default:
      break;
    }
  goto ret0;

 L12810: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case MULT:
      goto L716;
    case AND:
      goto L1055;
    case ASHIFT:
      goto L1760;
    case LSHIFTRT:
      goto L1908;
    case ASHIFTRT:
      goto L2175;
    default:
     break;
   }
  goto ret0;

 L716: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L717;
    }
  goto ret0;

 L717: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L718;
    }
  goto ret0;

 L718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L719;
  goto ret0;

 L719: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L720;
  goto ret0;

 L720: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L721;
    }
  goto ret0;

 L721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MULT)
    goto L722;
  goto ret0;

 L722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L723;
  goto ret0;

 L723: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L724;
  goto ret0;

 L724: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L725;
  goto ret0;

 L725: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L726;
    }
  goto ret0;

 L726: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 63;
    }
  goto ret0;

 L1055: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1056;
    }
  goto ret0;

 L1056: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (and_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1057;
    }
  goto ret0;

 L1057: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1058;
  goto ret0;

 L1058: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1059;
  goto ret0;

 L1059: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1060;
    }
  goto ret0;

 L1060: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L1061;
  goto ret0;

 L1061: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1062;
  goto ret0;

 L1062: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L1063;
  goto ret0;

 L1063: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1064;
  goto ret0;

 L1064: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L1065;
    }
  goto ret0;

 L1065: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 83;
    }
 L1094: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 84;
    }
  goto ret0;

 L1760: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1761;
    }
  goto ret0;

 L1761: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1762;
    }
  goto ret0;

 L1762: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1763;
  goto ret0;

 L1763: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1764;
  goto ret0;

 L1764: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1765;
    }
  goto ret0;

 L1765: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L1766;
  goto ret0;

 L1766: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1767;
  goto ret0;

 L1767: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L1768;
  goto ret0;

 L1768: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1769;
  goto ret0;

 L1769: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1770;
    }
  goto ret0;

 L1770: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 133;
    }
  goto ret0;

 L1908: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1909;
    }
  goto ret0;

 L1909: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1910;
    }
  goto ret0;

 L1910: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1911;
  goto ret0;

 L1911: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1912;
  goto ret0;

 L1912: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1913;
    }
  goto ret0;

 L1913: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L1914;
  goto ret0;

 L1914: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1915;
  goto ret0;

 L1915: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L1916;
  goto ret0;

 L1916: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L1917;
  goto ret0;

 L1917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L1918;
    }
  goto ret0;

 L1918: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 142;
    }
  goto ret0;

 L2175: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2176;
    }
  goto ret0;

 L2176: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2177;
    }
  goto ret0;

 L2177: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2178;
  goto ret0;

 L2178: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2179;
  goto ret0;

 L2179: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2180;
    }
  goto ret0;

 L2180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L2181;
  goto ret0;

 L2181: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2182;
  goto ret0;

 L2182: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2183;
  goto ret0;

 L2183: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2184;
  goto ret0;

 L2184: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L2185;
    }
  goto ret0;

 L2185: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 160;
    }
  goto ret0;

 L12815: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == AND)
    goto L3534;
  goto ret0;

 L3534: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3535;
    }
  goto ret0;

 L3535: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (and64_2_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3536;
    }
  goto ret0;

 L3536: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3537;
  goto ret0;

 L3537: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3538;
  goto ret0;

 L3538: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3539;
    }
  goto ret0;

 L3539: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == AND)
    goto L3540;
  goto ret0;

 L3540: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3541;
  goto ret0;

 L3541: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L3542;
  goto ret0;

 L3542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L3543;
  goto ret0;

 L3543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L3544;
    }
  goto ret0;

 L3544: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 287;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_22 PARAMS ((rtx, rtx, int *));
static int
recog_22 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (cc_reg_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L5463;
    }
 L12849: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[0] = x2;
      goto L5657;
    }
  goto ret0;

 L5463: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L5464;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5464: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12863;
    case DImode:
      goto L12864;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L12863: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case EQ:
      goto L5465;
    case PLUS:
      goto L5713;
    case LE:
      goto L5818;
    case GE:
      goto L6219;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5465: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5466;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5466: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5467;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5468;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5468: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5469;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5469: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5470;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == EQ)
    goto L5471;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5471: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5472;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5472: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L5473;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5473: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5474;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5474: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5475;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5475: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 420;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5713: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L5714;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5714: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == NEG)
    goto L5715;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5715: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == SImode
      && GET_CODE (x6) == ABS)
    goto L5716;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5716: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L5717;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5717: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 31LL)
    goto L5718;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5718: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5719;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5719: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5720;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5720: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5721;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5722;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5722: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5723;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5723: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L5724;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5724: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NEG)
    goto L5725;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5725: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == ABS)
    goto L5726;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5726: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[1]))
    goto L5727;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5727: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 31LL)
    goto L5728;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5728: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L5729;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5729: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5730;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5730: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5731;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5731: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 432;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5818: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5819;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5819: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5820;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5820: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5821;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5821: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5822;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5822: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5823;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5823: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LE)
    goto L5824;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5824: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5825;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5825: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L5826;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5826: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5827;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5827: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5828;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5828: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 435;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6219: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6220;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L6220: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6221;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L6221: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6222;
  x2 = XEXP (x1, 0);
  goto L12849;

 L6222: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6223;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6223: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6224;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6224: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == GE)
    goto L6225;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6225: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6226;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6226: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L6227;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6227: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6228;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6228: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6229;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L6229: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 465;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L12864: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case EQ:
      goto L5494;
    case PLUS:
      goto L5758;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5494: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5495;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5495: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5496;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5496: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5497;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5497: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5498;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5498: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5499;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5499: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == EQ)
    goto L5500;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5500: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5501;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5501: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L5502;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5502: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5503;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5503: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L5504;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5504: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 421;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5758: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L5759;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5759: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == NEG)
    goto L5760;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5760: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == ABS)
    goto L5761;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5761: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, DImode))
    {
      operands[1] = x7;
      goto L5762;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5762: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 63LL)
    goto L5763;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5763: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5764;
    }
  x2 = XEXP (x1, 0);
  goto L12849;

 L5764: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5765;
  x2 = XEXP (x1, 0);
  goto L12849;

 L5765: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5766;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5767;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5767: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L5768;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5768: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L5769;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5769: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == NEG)
    goto L5770;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5770: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ABS)
    goto L5771;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5771: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[1]))
    goto L5772;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5772: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 63LL)
    goto L5773;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5773: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L5774;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5774: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5775;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L5776;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5776: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 433;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12849;

 L5657: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L5658;
  goto ret0;

 L5658: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L5659;
  goto ret0;

 L5659: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L5660;
  goto ret0;

 L5660: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == NEG)
    goto L5661;
  goto ret0;

 L5661: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == SImode
      && GET_CODE (x6) == ABS)
    goto L5662;
  goto ret0;

 L5662: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L5663;
    }
  goto ret0;

 L5663: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 31LL)
    goto L5664;
  goto ret0;

 L5664: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5665;
    }
  goto ret0;

 L5665: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5666;
  goto ret0;

 L5666: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5667;
  goto ret0;

 L5667: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5668;
    }
  goto ret0;

 L5668: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5669;
  goto ret0;

 L5669: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5670;
    }
  goto ret0;

 L5670: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 430;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_23 PARAMS ((rtx, rtx, int *));
static int
recog_23 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  goto L4869;
 L5462: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x2))
    {
    case CCmode:
      goto L12848;
    case V16QImode:
      goto L12850;
    case V8HImode:
      goto L12851;
    case V4SImode:
      goto L12852;
    case V4SFmode:
      goto L12853;
    default:
      break;
    }
  goto ret0;

 L4869: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L4870;
  x2 = XEXP (x1, 0);
  goto L5462;

 L4870: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L4871;
  x2 = XEXP (x1, 0);
  goto L5462;

 L4871: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L12854;
    case DImode:
      goto L12855;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L5462;

 L12854: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SYMBOL_REF)
    goto L12859;
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5172;
    }
  x2 = XEXP (x1, 0);
  goto L5462;

 L12859: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4872;
    }
 L12860: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5055;
    }
  x2 = XEXP (x1, 0);
  goto L5462;

 L4872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L4873;

 L4873: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4874;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12860;

 L4874: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4875;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12860;

 L4875: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4876;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12860;

 L4876: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4877;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12860;

 L4877: ATTRIBUTE_UNUSED_LABEL
  if (((INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 379;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12860;

 L5055: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5056;

 L5056: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5057;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5058;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5058: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5059;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5059: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5060;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5060: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 386;
    }
 L5199: ATTRIBUTE_UNUSED_LABEL
  if (((DEFAULT_ABI == ABI_AIX_NODESC
    || DEFAULT_ABI == ABI_V4
    || DEFAULT_ABI == ABI_DARWIN)
   && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 392;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5172: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5173;

 L5173: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5174;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5175;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5175: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5176;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5176: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5177;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5177: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX_NODESC
   || DEFAULT_ABI == ABI_V4
   || DEFAULT_ABI == ABI_DARWIN))
    {
      return 391;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L12855: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SYMBOL_REF)
    goto L12861;
  x2 = XEXP (x1, 0);
  goto L5462;

 L12861: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4894;
    }
 L12862: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5114;
    }
  x2 = XEXP (x1, 0);
  goto L5462;

 L4894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L4895;

 L4895: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4896;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12862;

 L4896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4897;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12862;

 L4897: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4898;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12862;

 L4898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4899;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12862;

 L4899: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 380;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12862;

 L5114: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5115;

 L5115: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5116;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5116: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5117;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5117: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5118;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5118: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5119;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L5119: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT 
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 388;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5462;

 L12848: ATTRIBUTE_UNUSED_LABEL
  return recog_22 (x0, insn, pnum_clobbers);

 L12850: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V16QImode))
    {
      operands[0] = x2;
      goto L8868;
    }
  goto ret0;

 L8868: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V16QImode)
    goto L12869;
  goto ret0;

 L12869: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L8869;
    case UNSPEC:
      goto L12871;
    default:
     break;
   }
  goto ret0;

 L8869: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8870;
    }
  goto ret0;

 L8870: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8871;
  goto ret0;

 L8871: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8872;
    }
  goto ret0;

 L8872: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8873;
  goto ret0;

 L8873: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8874;
    }
  goto ret0;

 L8874: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 753;
    }
  goto ret0;

 L12871: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 210)
    goto L8929;
  goto ret0;

 L8929: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8930;
    }
  goto ret0;

 L8930: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8931;
  goto ret0;

 L8931: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8932;
    }
  goto ret0;

 L8932: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8933;
  goto ret0;

 L8933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V16QImode))
    {
      operands[3] = x2;
      goto L8934;
    }
  goto ret0;

 L8934: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 757;
    }
  goto ret0;

 L12851: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V8HImode))
    {
      operands[0] = x2;
      goto L8883;
    }
  goto ret0;

 L8883: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8HImode)
    goto L12872;
  goto ret0;

 L12872: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L8884;
    case UNSPEC:
      goto L12874;
    default:
     break;
   }
  goto ret0;

 L8884: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8885;
    }
  goto ret0;

 L8885: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8886;
  goto ret0;

 L8886: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8887;
    }
  goto ret0;

 L8887: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8888;
  goto ret0;

 L8888: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V8HImode))
    {
      operands[3] = x2;
      goto L8889;
    }
  goto ret0;

 L8889: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 754;
    }
  goto ret0;

 L12874: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 211)
    goto L8944;
  goto ret0;

 L8944: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8945;
    }
  goto ret0;

 L8945: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8946;
  goto ret0;

 L8946: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8947;
    }
  goto ret0;

 L8947: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8948;
  goto ret0;

 L8948: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V8HImode))
    {
      operands[3] = x2;
      goto L8949;
    }
  goto ret0;

 L8949: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 758;
    }
  goto ret0;

 L12852: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4SImode))
    {
      operands[0] = x2;
      goto L8898;
    }
  goto ret0;

 L8898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode)
    goto L12875;
  goto ret0;

 L12875: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ABS:
      goto L8899;
    case UNSPEC:
      goto L12877;
    default:
     break;
   }
  goto ret0;

 L8899: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8900;
    }
  goto ret0;

 L8900: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8901;
  goto ret0;

 L8901: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8902;
    }
  goto ret0;

 L8902: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8903;
  goto ret0;

 L8903: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L8904;
    }
  goto ret0;

 L8904: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 755;
    }
  goto ret0;

 L12877: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 212)
    goto L8959;
  goto ret0;

 L8959: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8960;
    }
  goto ret0;

 L8960: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8961;
  goto ret0;

 L8961: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8962;
    }
  goto ret0;

 L8962: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8963;
  goto ret0;

 L8963: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SImode))
    {
      operands[3] = x2;
      goto L8964;
    }
  goto ret0;

 L8964: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 759;
    }
  goto ret0;

 L12853: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4SFmode))
    {
      operands[0] = x2;
      goto L8913;
    }
  goto ret0;

 L8913: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SFmode
      && GET_CODE (x2) == ABS)
    goto L8914;
  goto ret0;

 L8914: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8915;
    }
  goto ret0;

 L8915: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8916;
  goto ret0;

 L8916: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8917;
    }
  goto ret0;

 L8917: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L8918;
  goto ret0;

 L8918: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SFmode))
    {
      operands[3] = x2;
      goto L8919;
    }
  goto ret0;

 L8919: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 756;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_24 PARAMS ((rtx, rtx, int *));
static int
recog_24 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case ASHIFT:
      goto L5418;
    case PLUS:
      goto L5531;
    case AND:
      goto L6015;
    case EQ:
    case NE:
    case LE:
    case LT:
    case GE:
    case GT:
    case LEU:
    case LTU:
    case GEU:
    case GTU:
    case UNORDERED:
    case ORDERED:
    case UNGE:
    case UNLE:
      goto L12921;
    default:
      goto ret0;
   }
 L12921: ATTRIBUTE_UNUSED_LABEL
  if (scc_comparison_operator (x3, SImode))
    {
      operands[1] = x3;
      goto L5398;
    }
  goto ret0;

 L5418: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (scc_comparison_operator (x4, SImode))
    {
      operands[1] = x4;
      goto L5419;
    }
  goto ret0;

 L5419: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (cc_reg_operand (x5, VOIDmode))
    {
      operands[2] = x5;
      goto L5420;
    }
  goto ret0;

 L5420: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L5421;
  goto ret0;

 L5421: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5422;
    }
  goto ret0;

 L5422: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5423;
  goto ret0;

 L5423: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5424;
  goto ret0;

 L5424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5425;
    }
  goto ret0;

 L5425: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L5426;
  goto ret0;

 L5426: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      operands[1] = x3;
      goto L5427;
    }
  goto ret0;

 L5427: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L5428;
  goto ret0;

 L5428: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L5429;
  goto ret0;

 L5429: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3]))
    {
      return 417;
    }
  goto ret0;

 L5531: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12926;
  goto ret0;

 L12926: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case EQ:
      goto L5532;
    case LE:
      goto L5856;
    case LEU:
      goto L5961;
    case LT:
      goto L6086;
    case LTU:
      goto L6159;
    case GE:
      goto L6257;
    case GEU:
      goto L6349;
    case GT:
      goto L6518;
    case GTU:
      goto L6716;
    default:
     break;
   }
  goto ret0;

 L5532: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5533;
    }
  goto ret0;

 L5533: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L5534;
    }
  goto ret0;

 L5534: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5535;
    }
  goto ret0;

 L5535: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5536;
  goto ret0;

 L5536: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5537;
  goto ret0;

 L5537: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5538;
    }
  goto ret0;

 L5538: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 423;
    }
  goto ret0;

 L5856: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5857;
    }
  goto ret0;

 L5857: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L5858;
    }
  goto ret0;

 L5858: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5859;
    }
  goto ret0;

 L5859: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5860;
  goto ret0;

 L5860: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5861;
  goto ret0;

 L5861: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5862;
    }
  goto ret0;

 L5862: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 437;
    }
  goto ret0;

 L5961: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5962;
    }
  goto ret0;

 L5962: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L5963;
    }
  goto ret0;

 L5963: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5964;
    }
  goto ret0;

 L5964: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5965;
  goto ret0;

 L5965: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5966;
  goto ret0;

 L5966: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5967;
    }
  goto ret0;

 L5967: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 446;
    }
  goto ret0;

 L6086: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6087;
    }
  goto ret0;

 L6087: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6088;
    }
  goto ret0;

 L6088: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6089;
    }
  goto ret0;

 L6089: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6090;
  goto ret0;

 L6090: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6091;
  goto ret0;

 L6091: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6092;
    }
  goto ret0;

 L6092: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 455;
    }
  goto ret0;

 L6159: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6160;
    }
  goto ret0;

 L6160: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6161;
    }
  goto ret0;

 L6161: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6162;
    }
  goto ret0;

 L6162: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6163;
  goto ret0;

 L6163: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6164;
  goto ret0;

 L6164: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6165;
    }
  goto ret0;

 L6165: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 461;
    }
  goto ret0;

 L6257: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6258;
    }
  goto ret0;

 L6258: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6259;
    }
  goto ret0;

 L6259: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6260;
    }
  goto ret0;

 L6260: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6261;
  goto ret0;

 L6261: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6262;
  goto ret0;

 L6262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6263;
    }
  goto ret0;

 L6263: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 467;
    }
  goto ret0;

 L6349: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6350;
    }
  goto ret0;

 L6350: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6351;
    }
  goto ret0;

 L6351: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6352;
    }
  goto ret0;

 L6352: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6353;
  goto ret0;

 L6353: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6354;
  goto ret0;

 L6354: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6355;
    }
  goto ret0;

 L6355: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 475;
    }
  goto ret0;

 L6518: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6519;
    }
  goto ret0;

 L6519: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L6520;
 L6605: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6606;
    }
  goto ret0;

 L6520: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6521;
    }
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L6605;

 L6521: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6522;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L6605;

 L6522: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6523;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L6605;

 L6523: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6524;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L6605;

 L6524: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 489;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L6605;

 L6606: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6607;
    }
  goto ret0;

 L6607: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6608;
  goto ret0;

 L6608: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6609;
  goto ret0;

 L6609: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6610;
    }
  goto ret0;

 L6610: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 494;
    }
  goto ret0;

 L6716: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6717;
    }
  goto ret0;

 L6717: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6718;
    }
  goto ret0;

 L6718: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6719;
    }
  goto ret0;

 L6719: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6720;
  goto ret0;

 L6720: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6721;
  goto ret0;

 L6721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6722;
    }
  goto ret0;

 L6722: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 505;
    }
  goto ret0;

 L6015: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NEG)
    goto L6016;
  goto ret0;

 L6016: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12935;
  goto ret0;

 L12935: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case LEU:
      goto L6017;
    case GEU:
      goto L6405;
    default:
     break;
   }
  goto ret0;

 L6017: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L6018;
    }
  goto ret0;

 L6018: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_short_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L6019;
    }
  goto ret0;

 L6019: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6020;
    }
  goto ret0;

 L6020: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6021;
  goto ret0;

 L6021: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6022;
  goto ret0;

 L6022: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6023;
    }
  goto ret0;

 L6023: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 450;
    }
  goto ret0;

 L6405: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L6406;
    }
  goto ret0;

 L6406: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_neg_short_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L6407;
    }
  goto ret0;

 L6407: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6408;
    }
  goto ret0;

 L6408: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6409;
  goto ret0;

 L6409: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6410;
  goto ret0;

 L6410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6411;
    }
  goto ret0;

 L6411: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 479;
    }
  goto ret0;

 L5398: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (cc_reg_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L5399;
    }
  goto ret0;

 L5399: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L5400;
  goto ret0;

 L5400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5401;
  goto ret0;

 L5401: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5402;
  goto ret0;

 L5402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5403;
    }
  goto ret0;

 L5403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    {
      operands[1] = x2;
      goto L5404;
    }
  goto ret0;

 L5404: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L5405;
  goto ret0;

 L5405: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (! TARGET_POWERPC64))
    {
      return 415;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_25 PARAMS ((rtx, rtx, int *));
static int
recog_25 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12947;
  goto ret0;

 L12947: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case EQ:
      goto L5554;
    case LSHIFTRT:
      goto L5738;
    case LE:
      goto L5878;
    case LEU:
      goto L5983;
    case LT:
      goto L6108;
    case LTU:
      goto L6181;
    case GE:
      goto L6279;
    case GEU:
      goto L6371;
    default:
     break;
   }
  goto ret0;

 L5554: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5555;
    }
  goto ret0;

 L5555: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L5556;
    }
  goto ret0;

 L5556: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5557;
    }
  goto ret0;

 L5557: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5558;
  goto ret0;

 L5558: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5559;
  goto ret0;

 L5559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5560;
    }
  goto ret0;

 L5560: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5561;
  goto ret0;

 L5561: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == EQ)
    goto L5562;
  goto ret0;

 L5562: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5563;
  goto ret0;

 L5563: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L5564;
  goto ret0;

 L5564: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 424;
    }
  goto ret0;

 L5738: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == NEG)
    goto L5739;
  goto ret0;

 L5739: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == SImode
      && GET_CODE (x6) == ABS)
    goto L5740;
  goto ret0;

 L5740: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L5741;
    }
  goto ret0;

 L5741: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 31LL)
    goto L5742;
  goto ret0;

 L5742: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5743;
    }
  goto ret0;

 L5743: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5744;
  goto ret0;

 L5744: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5745;
  goto ret0;

 L5745: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5746;
    }
  goto ret0;

 L5746: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5747;
  goto ret0;

 L5747: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L5748;
  goto ret0;

 L5748: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NEG)
    goto L5749;
  goto ret0;

 L5749: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == ABS)
    goto L5750;
  goto ret0;

 L5750: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[1]))
    goto L5751;
  goto ret0;

 L5751: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 31LL)
    goto L5752;
  goto ret0;

 L5752: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 432;
    }
  goto ret0;

 L5878: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5879;
    }
  goto ret0;

 L5879: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L5880;
    }
  goto ret0;

 L5880: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5881;
    }
  goto ret0;

 L5881: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5882;
  goto ret0;

 L5882: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5883;
  goto ret0;

 L5883: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5884;
    }
  goto ret0;

 L5884: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5885;
  goto ret0;

 L5885: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LE)
    goto L5886;
  goto ret0;

 L5886: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5887;
  goto ret0;

 L5887: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L5888;
  goto ret0;

 L5888: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWER))
    {
      return 438;
    }
  goto ret0;

 L5983: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5984;
    }
  goto ret0;

 L5984: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L5985;
    }
  goto ret0;

 L5985: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L5986;
    }
  goto ret0;

 L5986: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5987;
  goto ret0;

 L5987: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5988;
  goto ret0;

 L5988: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5989;
    }
  goto ret0;

 L5989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5990;
  goto ret0;

 L5990: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LEU)
    goto L5991;
  goto ret0;

 L5991: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5992;
  goto ret0;

 L5992: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L5993;
  goto ret0;

 L5993: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 447;
    }
  goto ret0;

 L6108: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6109;
    }
  goto ret0;

 L6109: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6110;
    }
  goto ret0;

 L6110: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6111;
    }
  goto ret0;

 L6111: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6112;
  goto ret0;

 L6112: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6113;
  goto ret0;

 L6113: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6114;
    }
  goto ret0;

 L6114: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6115;
  goto ret0;

 L6115: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LT)
    goto L6116;
  goto ret0;

 L6116: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6117;
  goto ret0;

 L6117: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6118;
  goto ret0;

 L6118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWER))
    {
      return 456;
    }
  goto ret0;

 L6181: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6182;
    }
  goto ret0;

 L6182: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6183;
    }
  goto ret0;

 L6183: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6184;
    }
  goto ret0;

 L6184: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6185;
  goto ret0;

 L6185: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6186;
  goto ret0;

 L6186: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6187;
    }
  goto ret0;

 L6187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6188;
  goto ret0;

 L6188: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LTU)
    goto L6189;
  goto ret0;

 L6189: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6190;
  goto ret0;

 L6190: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6191;
  goto ret0;

 L6191: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 462;
    }
  goto ret0;

 L6279: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6280;
    }
  goto ret0;

 L6280: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6281;
    }
  goto ret0;

 L6281: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6282;
    }
  goto ret0;

 L6282: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6283;
  goto ret0;

 L6283: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6284;
  goto ret0;

 L6284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6285;
    }
  goto ret0;

 L6285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6286;
  goto ret0;

 L6286: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == GE)
    goto L6287;
  goto ret0;

 L6287: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6288;
  goto ret0;

 L6288: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6289;
  goto ret0;

 L6289: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWER))
    {
      return 468;
    }
  goto ret0;

 L6371: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6372;
    }
  goto ret0;

 L6372: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6373;
    }
  goto ret0;

 L6373: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6374;
    }
  goto ret0;

 L6374: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6375;
  goto ret0;

 L6375: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6376;
  goto ret0;

 L6376: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6377;
    }
  goto ret0;

 L6377: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6378;
  goto ret0;

 L6378: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == GEU)
    goto L6379;
  goto ret0;

 L6379: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6380;
  goto ret0;

 L6380: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6381;
  goto ret0;

 L6381: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 476;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_26 PARAMS ((rtx, rtx, int *));
static int
recog_26 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 74)
    goto L8654;
 L12882: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L5346;
    }
 L12884: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[0] = x2;
      goto L5396;
    }
 L12887: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L5479;
    }
 L12888: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L5924;
    }
 L12889: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[2] = x2;
      goto L6454;
    }
 L12890: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L6486;
    }
 L12891: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCmode))
    {
      operands[4] = x2;
      goto L6623;
    }
  goto ret0;

 L8654: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode)
    goto L12908;
  x2 = XEXP (x1, 0);
  goto L12882;

 L12908: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC)
    goto L12911;
  x2 = XEXP (x1, 0);
  goto L12882;

 L12911: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 3)
    goto L12914;
  x2 = XEXP (x1, 0);
  goto L12882;

 L12914: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 173LL:
      goto L8655;
    case 174LL:
      goto L8672;
    case 175LL:
      goto L8689;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8655: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8656;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8656: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8657;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8657: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (any_operand (x3, VOIDmode))
    {
      operands[3] = x3;
      goto L8658;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8658: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8659;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SImode))
    {
      operands[0] = x2;
      goto L8660;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8660: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 729;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8672: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8673;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8673: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8674;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8674: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (any_operand (x3, VOIDmode))
    {
      operands[3] = x3;
      goto L8675;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8675: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8676;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8676: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V4SFmode))
    {
      operands[0] = x2;
      goto L8677;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8677: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 730;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8689: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  switch (GET_MODE (x3))
    {
    case V8HImode:
      goto L12917;
    case V16QImode:
      goto L12918;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L12917: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8690;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8690: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8691;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8691: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (any_operand (x3, VOIDmode))
    {
      operands[3] = x3;
      goto L8692;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8692: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8693;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8693: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V8HImode))
    {
      operands[0] = x2;
      goto L8694;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8694: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 731;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L12918: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8707;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8707: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L8708;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8708: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (any_operand (x3, VOIDmode))
    {
      operands[3] = x3;
      goto L8709;
    }
  x2 = XEXP (x1, 0);
  goto L12882;

 L8709: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8710;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8710: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, V16QImode))
    {
      operands[0] = x2;
      goto L8711;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L8711: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 732;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12882;

 L5346: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L5347;
  x2 = XEXP (x1, 0);
  goto L12884;

 L5347: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12919;
    case DImode:
      goto L12920;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12884;

 L12919: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5348;
    }
  x2 = XEXP (x1, 0);
  goto L12884;

 L5348: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (short_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5349;
    }
  x2 = XEXP (x1, 0);
  goto L12884;

 L5349: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5350;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5350: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5351;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5351: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5352;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5352: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5353;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5353: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (short_cint_operand (x3, SImode))
    {
      operands[4] = x3;
      return 408;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L12920: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == LEU)
    goto L5913;
  x2 = XEXP (x1, 0);
  goto L12884;

 L5913: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5914;
    }
  x2 = XEXP (x1, 0);
  goto L12884;

 L5914: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5915;
    }
  x2 = XEXP (x1, 0);
  goto L12884;

 L5915: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5916;
  x2 = XEXP (x1, 0);
  goto L12884;

 L5916: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5917;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5918;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5918: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LEU)
    goto L5919;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5919: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5920;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5920: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 442;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12884;

 L5396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L5397;
  x2 = XEXP (x1, 0);
  goto L12887;

 L5397: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12922;
    case DImode:
      goto L12924;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L12922: ATTRIBUTE_UNUSED_LABEL
  tem = recog_24 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12887;

 L12924: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == PLUS)
    goto L5687;
  x2 = XEXP (x1, 0);
  goto L12887;

 L5687: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L12937;
  x2 = XEXP (x1, 0);
  goto L12887;

 L12937: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case LSHIFTRT:
      goto L5688;
    case GT:
      goto L6540;
    case GTU:
      goto L6738;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12887;

 L5688: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == NEG)
    goto L5689;
  x2 = XEXP (x1, 0);
  goto L12887;

 L5689: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == ABS)
    goto L5690;
  x2 = XEXP (x1, 0);
  goto L12887;

 L5690: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, DImode))
    {
      operands[1] = x7;
      goto L5691;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L5691: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 63LL)
    goto L5692;
  x2 = XEXP (x1, 0);
  goto L12887;

 L5692: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5693;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L5693: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5694;
  x2 = XEXP (x1, 0);
  goto L12887;

 L5694: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5695;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L5695: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L5696;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L5696: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 431;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L6540: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L6541;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L6541: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L6542;
  x2 = XEXP (x1, 0);
  goto L12887;

 L6542: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L6543;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L6543: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6544;
  x2 = XEXP (x1, 0);
  goto L12887;

 L6544: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6545;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L6545: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L6546;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L6546: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 490;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L6738: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L6739;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L6739: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L6740;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L6740: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L6741;
    }
  x2 = XEXP (x1, 0);
  goto L12887;

 L6741: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6742;
  x2 = XEXP (x1, 0);
  goto L12887;

 L6742: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6743;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L6743: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L6744;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L6744: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 506;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12887;

 L5479: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L5480;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5480: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12940;
    case DImode:
      goto L12941;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L12940: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case EQ:
      goto L5481;
    case PLUS:
      goto L5553;
    case LE:
      goto L5834;
    case AND:
      goto L6039;
    case GE:
      goto L6235;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5481: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5482;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5482: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5483;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5484;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5484: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5485;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5486;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == EQ)
    goto L5487;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5488;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5488: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 420;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5553: ATTRIBUTE_UNUSED_LABEL
  tem = recog_25 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5834: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5835;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5835: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5836;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5836: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5837;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5837: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5838;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5838: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5839;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5839: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LE)
    goto L5840;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5840: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5841;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5841: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 435;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6039: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NEG)
    goto L6040;
  x2 = XEXP (x1, 0);
  goto L12888;

 L6040: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L12955;
  x2 = XEXP (x1, 0);
  goto L12888;

 L12955: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case LEU:
      goto L6041;
    case GEU:
      goto L6429;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6041: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L6042;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6042: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_short_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L6043;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6043: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6044;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6044: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6045;
  x2 = XEXP (x1, 0);
  goto L12888;

 L6045: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6046;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6046: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6047;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6047: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L6048;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6048: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NEG)
    goto L6049;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6049: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LEU)
    goto L6050;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6050: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L6051;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6051: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    goto L6052;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6052: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 451;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6429: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L6430;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6430: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_neg_short_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L6431;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6431: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6432;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6432: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6433;
  x2 = XEXP (x1, 0);
  goto L12888;

 L6433: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6434;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6434: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6435;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6435: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L6436;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6436: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NEG)
    goto L6437;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6437: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == GEU)
    goto L6438;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6438: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L6439;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6439: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    goto L6440;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6440: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 480;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6235: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6236;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6236: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6237;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L6237: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6238;
  x2 = XEXP (x1, 0);
  goto L12888;

 L6238: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6239;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6239: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6240;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == GE)
    goto L6241;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6241: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6242;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L6242: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 465;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L12941: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case EQ:
      goto L5510;
    case PLUS:
      goto L5782;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5510: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5511;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5511: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5512;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5512: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5513;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5513: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5514;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5515;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == EQ)
    goto L5516;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5516: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5517;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5517: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 421;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5782: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L5783;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5783: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == NEG)
    goto L5784;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5784: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == ABS)
    goto L5785;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5785: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, DImode))
    {
      operands[1] = x7;
      goto L5786;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5786: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 63LL)
    goto L5787;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5787: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5788;
    }
  x2 = XEXP (x1, 0);
  goto L12888;

 L5788: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5789;
  x2 = XEXP (x1, 0);
  goto L12888;

 L5789: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5790;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5790: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5791;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5791: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L5792;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5792: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L5793;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5793: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == NEG)
    goto L5794;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5794: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ABS)
    goto L5795;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5795: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[1]))
    goto L5796;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5796: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 63LL)
    goto L5797;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5797: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 433;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12888;

 L5924: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L5925;
  x2 = XEXP (x1, 0);
  goto L12889;

 L5925: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12957;
    case DImode:
      goto L12958;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L12957: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case LEU:
      goto L5926;
    case LT:
      goto L6064;
    case LTU:
      goto L6137;
    case GEU:
      goto L6314;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12889;

 L5926: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5927;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L5927: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L5928;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L5928: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5929;
  x2 = XEXP (x1, 0);
  goto L12889;

 L5929: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5930;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5930: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5931;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5931: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LEU)
    goto L5932;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5932: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5933;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5933: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64))
    {
      return 443;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6064: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6065;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6065: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6066;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6066: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6067;
  x2 = XEXP (x1, 0);
  goto L12889;

 L6067: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6068;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6068: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6069;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6069: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LT)
    goto L6070;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6071;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6071: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER))
    {
      return 453;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6137: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6138;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6138: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_neg_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6139;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6139: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6140;
  x2 = XEXP (x1, 0);
  goto L12889;

 L6140: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6141;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6141: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6142;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LTU)
    goto L6143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6143: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6144;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64))
    {
      return 459;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6314: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6315;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6315: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_neg_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6316;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6316: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6317;
  x2 = XEXP (x1, 0);
  goto L12889;

 L6317: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6318;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6318: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6319;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6319: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == GEU)
    goto L6320;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6320: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6321;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6321: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64))
    {
      return 472;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L12958: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case LEU:
      goto L5939;
    case GEU:
      goto L6327;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12889;

 L5939: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5940;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L5940: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L5941;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L5941: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5942;
  x2 = XEXP (x1, 0);
  goto L12889;

 L5942: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5943;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5943: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5944;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5944: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LEU)
    goto L5945;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5945: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5946;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L5946: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 444;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6327: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6328;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6328: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_neg_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L6329;
    }
  x2 = XEXP (x1, 0);
  goto L12889;

 L6329: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6330;
  x2 = XEXP (x1, 0);
  goto L12889;

 L6330: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6331;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6332;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == GEU)
    goto L6333;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6333: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6334;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6334: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 473;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12889;

 L6454: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L6455;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6455: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12963;
    case DImode:
      goto L12964;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12890;

 L12963: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == GT)
    goto L6456;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6456: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6457;
    }
  x2 = XEXP (x1, 0);
  goto L12890;

 L6457: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6458;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6458: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6459;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6459: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6460;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6460: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6461;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6461: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == GT)
    goto L6462;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6462: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6463;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6463: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (! TARGET_POWERPC64))
    {
      return 483;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L12964: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == GT)
    goto L6469;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6469: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6470;
    }
  x2 = XEXP (x1, 0);
  goto L12890;

 L6470: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6471;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6471: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6472;
  x2 = XEXP (x1, 0);
  goto L12890;

 L6472: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6473;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6473: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6474;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6474: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == GT)
    goto L6475;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6475: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6476;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6476: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_POWERPC64))
    {
      return 484;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12890;

 L6486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L6487;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12965;
    case DImode:
      goto L12967;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L12965: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case GT:
      goto L6488;
    case PLUS:
      goto L6561;
    case GTU:
      goto L6673;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6488: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6489;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6489: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6490;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6490: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6491;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6491: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6492;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6492: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6493;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6493: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == GT)
    goto L6494;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6494: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6495;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWER))
    {
      return 486;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6561: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == GT)
    goto L6562;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6562: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6563;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6563: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L6564;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6564: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6565;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6565: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6566;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6566: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6567;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6568;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6569;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6569: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == GT)
    goto L6570;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6570: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6571;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6571: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6572;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6572: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64))
    {
      return 491;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6673: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6674;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6674: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L6675;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6676;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6676: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6677;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6677: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6678;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6678: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == GTU)
    goto L6679;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6679: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6680;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6680: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (! TARGET_POWERPC64))
    {
      return 501;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L12967: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L6578;
    case GTU:
      goto L6686;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6578: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == GT)
    goto L6579;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6579: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L6580;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6580: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L6581;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6581: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L6582;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6582: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6583;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6583: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6584;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6585;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6585: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L6586;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6586: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == GT)
    goto L6587;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6587: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6588;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6588: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6589;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 492;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6686: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6687;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6687: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L6688;
    }
  x2 = XEXP (x1, 0);
  goto L12891;

 L6688: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6689;
  x2 = XEXP (x1, 0);
  goto L12891;

 L6689: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6690;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6690: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6691;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6691: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == GTU)
    goto L6692;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6692: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6693;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6693: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_POWERPC64))
    {
      return 502;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12891;

 L6623: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == COMPARE)
    goto L6624;
  goto ret0;

 L6624: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12970;
    case DImode:
      goto L12971;
    default:
      break;
    }
  goto ret0;

 L12970: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == PLUS)
    goto L6625;
  goto ret0;

 L6625: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L12972;
  goto ret0;

 L12972: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case GT:
      goto L6626;
    case GTU:
      goto L6760;
    default:
     break;
   }
  goto ret0;

 L6626: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6627;
    }
  goto ret0;

 L6627: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6628;
    }
  goto ret0;

 L6628: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6629;
    }
  goto ret0;

 L6629: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6630;
  goto ret0;

 L6630: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6631;
  goto ret0;

 L6631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6632;
    }
  goto ret0;

 L6632: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6633;
  goto ret0;

 L6633: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == GT)
    goto L6634;
  goto ret0;

 L6634: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6635;
  goto ret0;

 L6635: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6636;
  goto ret0;

 L6636: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWER))
    {
      return 495;
    }
  goto ret0;

 L6760: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L6761;
    }
  goto ret0;

 L6761: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L6762;
    }
  goto ret0;

 L6762: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6763;
    }
  goto ret0;

 L6763: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6764;
  goto ret0;

 L6764: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6765;
  goto ret0;

 L6765: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6766;
    }
  goto ret0;

 L6766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6767;
  goto ret0;

 L6767: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == GTU)
    goto L6768;
  goto ret0;

 L6768: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6769;
  goto ret0;

 L6769: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6770;
  goto ret0;

 L6770: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (! TARGET_POWERPC64))
    {
      return 507;
    }
  goto ret0;

 L12971: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == PLUS)
    goto L6776;
  goto ret0;

 L6776: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == GTU)
    goto L6777;
  goto ret0;

 L6777: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L6778;
    }
  goto ret0;

 L6778: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L6779;
    }
  goto ret0;

 L6779: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L6780;
    }
  goto ret0;

 L6780: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6781;
  goto ret0;

 L6781: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6782;
  goto ret0;

 L6782: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6783;
    }
  goto ret0;

 L6783: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L6784;
  goto ret0;

 L6784: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == GTU)
    goto L6785;
  goto ret0;

 L6785: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L6786;
  goto ret0;

 L6786: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2]))
    goto L6787;
  goto ret0;

 L6787: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_POWERPC64))
    {
      return 508;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_27 PARAMS ((rtx, rtx, int *));
static int
recog_27 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case UNSPEC:
      goto L13058;
    case MEM:
      goto L8789;
    default:
     break;
   }
  goto ret0;

 L13058: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L13071;
    case 3:
      goto L13073;
    default:
      break;
    }
  goto ret0;

 L13071: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 40LL:
      goto L7594;
    case 41LL:
      goto L7604;
    case 129LL:
      goto L8355;
    case 130LL:
      goto L8365;
    case 131LL:
      goto L8375;
    case 132LL:
      goto L8385;
    case 133LL:
      goto L8395;
    case 134LL:
      goto L8405;
    case 135LL:
      goto L8415;
    case 153LL:
      goto L8529;
    case 154LL:
      goto L8539;
    default:
      break;
    }
  goto ret0;

 L7594: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L7595;
    }
  goto ret0;

 L7595: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L7596;
    }
  goto ret0;

 L7596: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7597;
  goto ret0;

 L7597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7598;
  goto ret0;

 L7598: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7599;
  goto ret0;

 L7599: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 583;
    }
  goto ret0;

 L7604: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L7605;
    }
  goto ret0;

 L7605: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L7606;
    }
  goto ret0;

 L7606: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7607;
  goto ret0;

 L7607: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7608;
  goto ret0;

 L7608: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7609;
  goto ret0;

 L7609: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 584;
    }
  goto ret0;

 L8355: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8356;
    }
  goto ret0;

 L8356: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8357;
    }
  goto ret0;

 L8357: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8358;
  goto ret0;

 L8358: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8359;
  goto ret0;

 L8359: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8360;
  goto ret0;

 L8360: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 684;
    }
  goto ret0;

 L8365: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8366;
    }
  goto ret0;

 L8366: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8367;
    }
  goto ret0;

 L8367: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8368;
  goto ret0;

 L8368: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8369;
  goto ret0;

 L8369: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8370;
  goto ret0;

 L8370: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 685;
    }
  goto ret0;

 L8375: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8376;
    }
  goto ret0;

 L8376: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8377;
    }
  goto ret0;

 L8377: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8378;
  goto ret0;

 L8378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8379;
  goto ret0;

 L8379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8380;
  goto ret0;

 L8380: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 686;
    }
  goto ret0;

 L8385: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8386;
    }
  goto ret0;

 L8386: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8387;
    }
  goto ret0;

 L8387: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8388;
  goto ret0;

 L8388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8389;
  goto ret0;

 L8389: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8390;
  goto ret0;

 L8390: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 687;
    }
  goto ret0;

 L8395: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8396;
    }
  goto ret0;

 L8396: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8397;
    }
  goto ret0;

 L8397: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8398;
  goto ret0;

 L8398: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8399;
  goto ret0;

 L8399: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8400;
  goto ret0;

 L8400: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 688;
    }
  goto ret0;

 L8405: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8406;
    }
  goto ret0;

 L8406: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8407;
    }
  goto ret0;

 L8407: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8408;
  goto ret0;

 L8408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8409;
  goto ret0;

 L8409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8410;
  goto ret0;

 L8410: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 689;
    }
  goto ret0;

 L8415: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8416;
    }
  goto ret0;

 L8416: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8417;
    }
  goto ret0;

 L8417: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8418;
  goto ret0;

 L8418: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8419;
  goto ret0;

 L8419: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8420;
  goto ret0;

 L8420: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 690;
    }
  goto ret0;

 L8529: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8530;
    }
  goto ret0;

 L8530: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (immediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L8531;
    }
  goto ret0;

 L8531: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8532;
  goto ret0;

 L8532: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8533;
  goto ret0;

 L8533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8534;
  goto ret0;

 L8534: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 709;
    }
  goto ret0;

 L8539: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8540;
    }
  goto ret0;

 L8540: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (immediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L8541;
    }
  goto ret0;

 L8541: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8542;
  goto ret0;

 L8542: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8543;
  goto ret0;

 L8543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8544;
  goto ret0;

 L8544: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 710;
    }
  goto ret0;

 L13073: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 69LL:
      goto L7785;
    case 70LL:
      goto L7796;
    default:
      break;
    }
  goto ret0;

 L7785: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7786;
    }
  goto ret0;

 L7786: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7787;
    }
  goto ret0;

 L7787: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V4SImode))
    {
      operands[3] = x3;
      goto L7788;
    }
  goto ret0;

 L7788: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7789;
  goto ret0;

 L7789: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7790;
  goto ret0;

 L7790: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7791;
  goto ret0;

 L7791: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 612;
    }
  goto ret0;

 L7796: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7797;
    }
  goto ret0;

 L7797: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7798;
    }
  goto ret0;

 L7798: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V4SImode))
    {
      operands[3] = x3;
      goto L7799;
    }
  goto ret0;

 L7799: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7800;
  goto ret0;

 L7800: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7801;
  goto ret0;

 L7801: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7802;
  goto ret0;

 L7802: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 613;
    }
  goto ret0;

 L8789: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L13084;
  goto ret0;

 L13084: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case AND:
      goto L8790;
    case PLUS:
      goto L8801;
    default:
     break;
   }
  goto ret0;

 L8790: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L8791;
  goto ret0;

 L8791: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L8792;
    }
  goto ret0;

 L8792: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L8793;
    }
  goto ret0;

 L8793: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == -4LL)
    goto L8794;
  goto ret0;

 L8794: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 198)
    goto L8795;
  goto ret0;

 L8795: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 745;
    }
  goto ret0;

 L8801: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L8802;
    }
  goto ret0;

 L8802: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L8803;
    }
  goto ret0;

 L8803: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 213)
    goto L8804;
  goto ret0;

 L8804: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 746;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_28 PARAMS ((rtx, rtx, int *));
static int
recog_28 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case NE:
      goto L6930;
    case GE:
      goto L7070;
    case EQ:
      goto L7210;
    default:
     break;
   }
  goto ret0;

 L6930: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13088;
    case DImode:
      goto L13089;
    default:
      break;
    }
  goto ret0;

 L13088: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6931;
    }
  goto ret0;

 L6931: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L6932;
  goto ret0;

 L6932: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L6933;
    case PC:
      goto L6968;
    default:
     break;
   }
  goto ret0;

 L6933: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L6934;

 L6934: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L6935;
  goto ret0;

 L6935: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6936;
  goto ret0;

 L6936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6937;
    }
  goto ret0;

 L6937: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6938;
  goto ret0;

 L6938: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6939;
  goto ret0;

 L6939: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 526;
    }
  goto ret0;

 L6968: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L6969;
  goto ret0;

 L6969: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L6970;

 L6970: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6971;
  goto ret0;

 L6971: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6972;
    }
  goto ret0;

 L6972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6973;
  goto ret0;

 L6973: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6974;
  goto ret0;

 L6974: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 527;
    }
  goto ret0;

 L13089: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L7001;
    }
  goto ret0;

 L7001: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7002;
  goto ret0;

 L7002: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7003;
    case PC:
      goto L7038;
    default:
     break;
   }
  goto ret0;

 L7003: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7004;

 L7004: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7005;
  goto ret0;

 L7005: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7006;
  goto ret0;

 L7006: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7007;
    }
  goto ret0;

 L7007: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7008;
  goto ret0;

 L7008: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7009;
  goto ret0;

 L7009: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 528;
    }
  goto ret0;

 L7038: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7039;
  goto ret0;

 L7039: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7040;

 L7040: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7041;
  goto ret0;

 L7041: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7042;
    }
  goto ret0;

 L7042: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7043;
  goto ret0;

 L7043: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7044;
  goto ret0;

 L7044: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 529;
    }
  goto ret0;

 L7070: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13090;
    case DImode:
      goto L13091;
    default:
      break;
    }
  goto ret0;

 L13090: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L7071;
    }
  goto ret0;

 L7071: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7072;
  goto ret0;

 L7072: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7073;
    case PC:
      goto L7108;
    default:
     break;
   }
  goto ret0;

 L7073: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7074;

 L7074: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7075;
  goto ret0;

 L7075: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7076;
  goto ret0;

 L7076: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7077;
    }
  goto ret0;

 L7077: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7078;
  goto ret0;

 L7078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7079;
  goto ret0;

 L7079: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (! TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 530;
    }
  goto ret0;

 L7108: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7109;
  goto ret0;

 L7109: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7110;

 L7110: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7111;
  goto ret0;

 L7111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7112;
    }
  goto ret0;

 L7112: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7113;
  goto ret0;

 L7113: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7114;
  goto ret0;

 L7114: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (! TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 531;
    }
  goto ret0;

 L13091: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L7141;
    }
  goto ret0;

 L7141: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7142;
  goto ret0;

 L7142: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7143;
    case PC:
      goto L7178;
    default:
     break;
   }
  goto ret0;

 L7143: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7144;

 L7144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7145;
  goto ret0;

 L7145: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7146;
  goto ret0;

 L7146: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7147;
    }
  goto ret0;

 L7147: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7148;
  goto ret0;

 L7148: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7149;
  goto ret0;

 L7149: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 532;
    }
  goto ret0;

 L7178: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7179;
  goto ret0;

 L7179: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7180;

 L7180: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7181;
  goto ret0;

 L7181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7182;
    }
  goto ret0;

 L7182: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7183;
  goto ret0;

 L7183: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7184;
  goto ret0;

 L7184: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 533;
    }
  goto ret0;

 L7210: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13092;
    case DImode:
      goto L13093;
    default:
      break;
    }
  goto ret0;

 L13092: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L7211;
    }
  goto ret0;

 L7211: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7212;
  goto ret0;

 L7212: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7213;
    case PC:
      goto L7248;
    default:
     break;
   }
  goto ret0;

 L7213: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7214;

 L7214: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7215;
  goto ret0;

 L7215: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7216;
  goto ret0;

 L7216: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7217;
    }
  goto ret0;

 L7217: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7218;
  goto ret0;

 L7218: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7219;
  goto ret0;

 L7219: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 534;
    }
  goto ret0;

 L7248: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7249;
  goto ret0;

 L7249: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7250;

 L7250: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7251;
  goto ret0;

 L7251: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7252;
    }
  goto ret0;

 L7252: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7253;
  goto ret0;

 L7253: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7254;
  goto ret0;

 L7254: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (! TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 535;
    }
  goto ret0;

 L13093: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L7281;
    }
  goto ret0;

 L7281: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7282;
  goto ret0;

 L7282: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7283;
    case PC:
      goto L7318;
    default:
     break;
   }
  goto ret0;

 L7283: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7284;

 L7284: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7285;
  goto ret0;

 L7285: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7286;
  goto ret0;

 L7286: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7287;
    }
  goto ret0;

 L7287: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7288;
  goto ret0;

 L7288: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7289;
  goto ret0;

 L7289: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 536;
    }
  goto ret0;

 L7318: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7319;
  goto ret0;

 L7319: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7320;

 L7320: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7321;
  goto ret0;

 L7321: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7322;
    }
  goto ret0;

 L7322: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7323;
  goto ret0;

 L7323: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7324;
  goto ret0;

 L7324: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (TARGET_POWERPC64)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 537;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_29 PARAMS ((rtx, rtx, int *));
static int
recog_29 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  goto L4881;
 L5345: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x2))
    {
    case CCmode:
      goto L12895;
    case CCUNSmode:
      goto L12883;
    case SImode:
      goto L12885;
    case DImode:
      goto L12886;
    case V16QImode:
      goto L12897;
    case V8HImode:
      goto L12898;
    case V4SImode:
      goto L12896;
    default:
      break;
    }
 L6890: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PC)
    goto L6891;
  goto ret0;

 L4881: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L4882;
  x2 = XEXP (x1, 0);
  goto L5345;

 L4882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L4883;
  x2 = XEXP (x1, 0);
  goto L5345;

 L4883: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L12899;
    case DImode:
      goto L12900;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L5345;

 L12899: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SYMBOL_REF)
    goto L12904;
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5184;
    }
  x2 = XEXP (x1, 0);
  goto L5345;

 L12904: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4884;
    }
 L12905: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5067;
    }
  x2 = XEXP (x1, 0);
  goto L5345;

 L4884: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L4885;

 L4885: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4886;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12905;

 L4886: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4887;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12905;

 L4887: ATTRIBUTE_UNUSED_LABEL
  if (((INTVAL (operands[3]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 379;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12905;

 L5067: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5068;

 L5068: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5069;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5069: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5070;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5070: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[3]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 386;
    }
 L5209: ATTRIBUTE_UNUSED_LABEL
  if (((DEFAULT_ABI == ABI_AIX_NODESC
    || DEFAULT_ABI == ABI_V4
    || DEFAULT_ABI == ABI_DARWIN)
   && (INTVAL (operands[3]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 392;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5184: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5185;

 L5185: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5186;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5186: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5187;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5187: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX_NODESC
   || DEFAULT_ABI == ABI_V4
   || DEFAULT_ABI == ABI_DARWIN)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 391;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L12900: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SYMBOL_REF)
    goto L12906;
  x2 = XEXP (x1, 0);
  goto L5345;

 L12906: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4906;
    }
 L12907: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5126;
    }
  x2 = XEXP (x1, 0);
  goto L5345;

 L4906: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L4907;

 L4907: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4908;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12907;

 L4908: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4909;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12907;

 L4909: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (INTVAL (operands[3]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 380;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L12907;

 L5126: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5127;

 L5127: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5128;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5129;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L5129: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT 
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[3]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 388;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5345;

 L12895: ATTRIBUTE_UNUSED_LABEL
  tem = recog_26 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L6890;

 L12883: ATTRIBUTE_UNUSED_LABEL
  if (cc_reg_operand (x2, CCUNSmode))
    {
      operands[3] = x2;
      goto L5357;
    }
  goto L6890;

 L5357: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCUNSmode
      && GET_CODE (x2) == COMPARE)
    goto L5358;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5358: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5359;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5359: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (u_short_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5360;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5360: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5361;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5362;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L5363;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5363: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5364;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5364: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (short_cint_operand (x3, SImode))
    {
      operands[4] = x3;
      return 409;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L12885: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5433;
    }
  goto L6890;

 L5433: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12974;
  x2 = XEXP (x1, 0);
  goto L6890;

 L12974: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case EQ:
      goto L5434;
    case LSHIFTRT:
      goto L5576;
    case PLUS:
      goto L5612;
    case LE:
      goto L5802;
    case GE:
      goto L6203;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5434: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5435;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5435: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5436;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5436: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5437;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5438;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5438: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 418;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5576: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NEG)
    goto L5577;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5577: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == ABS)
    goto L5578;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5578: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L5579;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5579: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 31LL)
    goto L5580;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5580: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5581;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5581: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5582;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5582: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64 && !TARGET_ISEL))
    {
      return 426;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5612: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L5613;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5613: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == NEG)
    goto L5614;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5614: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == ABS)
    goto L5615;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5615: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L5616;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5616: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 31LL)
    goto L5617;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5617: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5618;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5618: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5619;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5619: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5620;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5620: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 428;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5803;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5803: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L5804;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5804: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5805;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5805: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5806;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5806: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 434;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L6203: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6204;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L6204: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_short_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6205;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L6205: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6206;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L6206: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6207;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L6207: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER))
    {
      return 464;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L12886: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5448;
    }
  goto L6890;

 L5448: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L12979;
  x2 = XEXP (x1, 0);
  goto L6890;

 L12979: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case EQ:
      goto L5449;
    case LSHIFTRT:
      goto L5594;
    case PLUS:
      goto L5635;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5449: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L5450;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5450: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (reg_or_cint_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L5451;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5451: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5452;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5452: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L5453;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5453: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 419;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5594: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == NEG)
    goto L5595;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5595: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ABS)
    goto L5596;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5596: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L5597;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 63LL)
    goto L5598;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5598: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5599;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5599: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L5600;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5600: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 427;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5635: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L5636;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5636: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == NEG)
    goto L5637;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5637: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ABS)
    goto L5638;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5638: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L5639;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5639: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 63LL)
    goto L5640;
  x2 = XEXP (x1, 0);
  goto L6890;

 L5640: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L5641;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L5641: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5642;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5642: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L5643;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L5643: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 429;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L12897: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L8837;
  if (register_operand (x2, V16QImode))
    {
      operands[0] = x2;
      goto L7553;
    }
  goto L6890;

 L8837: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L8838;
  goto L6890;

 L8838: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[0] = x4;
      goto L8839;
    }
  goto L6890;

 L8839: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L8840;
    }
  goto L6890;

 L8840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L8841;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8841: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 203)
    goto L8842;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8842: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 750;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7553: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V16QImode)
    goto L12982;
  x2 = XEXP (x1, 0);
  goto L6890;

 L12982: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case UNSPEC:
      goto L12991;
    case MEM:
      goto L8769;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L6890;

 L12991: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 2)
    goto L12999;
  x2 = XEXP (x1, 0);
  goto L6890;

 L12999: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 36LL:
      goto L7554;
    case 37LL:
      goto L7564;
    case 96LL:
      goto L8103;
    case 97LL:
      goto L8113;
    case 100LL:
      goto L8143;
    case 101LL:
      goto L8153;
    case 125LL:
      goto L8315;
    case 126LL:
      goto L8325;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7554: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L7555;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7555: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L7556;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7556: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7557;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7557: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7558;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7559;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7559: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 579;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7564: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L7565;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7565: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L7566;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7566: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7567;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7568;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7569;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7569: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 580;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8103: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8104;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8104: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8105;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8105: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8106;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8106: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8107;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8107: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8108;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8108: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 650;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8113: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8114;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8114: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8115;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8115: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8116;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8116: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8117;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8118;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8118: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 651;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8143: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8144;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8144: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8145;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8145: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8146;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8146: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8147;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8147: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8148;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8148: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 654;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8153: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8154;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8154: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8155;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8155: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8156;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8156: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8157;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8157: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8158;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8158: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 655;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8315: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8316;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8316: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L8317;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8317: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8318;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8318: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8319;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8319: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8320;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8320: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 680;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8325: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L8326;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8326: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L8327;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8327: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8328;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8329;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8329: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8330;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8330: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 681;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8769: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L8770;
  x2 = XEXP (x1, 0);
  goto L6890;

 L8770: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L8771;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8771: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L8772;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8772: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 196)
    goto L8773;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8773: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 743;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L12898: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L8846;
  if (register_operand (x2, V8HImode))
    {
      operands[0] = x2;
      goto L7573;
    }
  goto L6890;

 L8846: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L8847;
  goto L6890;

 L8847: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L8848;
  goto L6890;

 L8848: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[0] = x5;
      goto L8849;
    }
  goto L6890;

 L8849: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L8850;
    }
  goto L6890;

 L8850: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == -2LL)
    goto L8851;
  goto L6890;

 L8851: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L8852;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8852: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 204)
    goto L8853;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8853: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 751;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7573: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8HImode)
    goto L13007;
  x2 = XEXP (x1, 0);
  goto L6890;

 L13007: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case UNSPEC:
      goto L13018;
    case MEM:
      goto L8778;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L6890;

 L13018: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L13028;
    case 3:
      goto L13030;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L13028: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 38LL:
      goto L7574;
    case 39LL:
      goto L7584;
    case 98LL:
      goto L8123;
    case 99LL:
      goto L8133;
    case 102LL:
      goto L8163;
    case 103LL:
      goto L8173;
    case 127LL:
      goto L8335;
    case 128LL:
      goto L8345;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7574: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7575;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7575: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7576;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7576: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7577;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7577: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7578;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7578: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7579;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7579: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 581;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7584: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7585;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7585: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7586;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7586: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7587;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7587: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7588;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7588: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7589;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7589: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 582;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8123: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8124;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8124: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8125;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8125: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8126;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8126: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8127;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8127: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8128;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8128: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 652;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8133: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8134;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8134: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8135;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8135: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8136;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8136: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8137;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8137: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8138;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8138: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 653;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8163: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8164;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8164: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8165;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8165: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8166;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8166: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8167;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8167: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8168;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8168: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 656;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8173: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L8174;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8174: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L8175;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8175: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8176;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8176: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8177;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8178;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8178: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 657;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8335: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8336;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8336: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8337;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8337: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8338;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8338: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8339;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8340;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8340: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 682;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8345: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L8346;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8346: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L8347;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8347: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8348;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8348: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L8349;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8349: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L8350;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8350: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 683;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L13030: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 71LL:
      goto L7849;
    case 72LL:
      goto L7860;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7849: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7850;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7850: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7851;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7851: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V8HImode))
    {
      operands[3] = x3;
      goto L7852;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7852: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7853;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7853: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7854;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7854: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7855;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7855: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 621;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7860: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L7861;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7861: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L7862;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7862: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (register_operand (x3, V8HImode))
    {
      operands[3] = x3;
      goto L7863;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L7863: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7864;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7864: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 110)
    goto L7865;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7865: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 213)
    goto L7866;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7866: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 622;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8778: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L8779;
  x2 = XEXP (x1, 0);
  goto L6890;

 L8779: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L8780;
  x2 = XEXP (x1, 0);
  goto L6890;

 L8780: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L8781;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8781: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (register_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L8782;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8782: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == -2LL)
    goto L8783;
  x2 = XEXP (x1, 0);
  goto L6890;

 L8783: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 197)
    goto L8784;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8784: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 744;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L12896: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L8815;
  if (register_operand (x2, V4SImode))
    {
      operands[0] = x2;
      goto L7593;
    }
  goto L6890;

 L8815: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L8816;
  goto L6890;

 L8816: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L8817;
  goto L6890;

 L8817: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, SImode))
    {
      operands[0] = x5;
      goto L8818;
    }
  goto L6890;

 L8818: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L8819;
    }
  goto L6890;

 L8819: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L13038;
  goto L6890;

 L13038: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case -16LL:
        goto L8820;
      case -4LL:
        goto L8862;
      default:
        break;
      }
  goto L6890;

 L8820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8821;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8821: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC)
    goto L13040;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L13040: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13042;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L13042: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 201LL:
      goto L8822;
    case 202LL:
      goto L8833;
    default:
      break;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8822: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 748;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8833: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 749;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8862: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L8863;
    }
  x2 = XEXP (x1, 0);
  goto L6890;

 L8863: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 205)
    goto L8864;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L8864: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 752;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6890;

 L7593: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode)
    goto L13044;
  x2 = XEXP (x1, 0);
  goto L6890;

 L13044: ATTRIBUTE_UNUSED_LABEL
  tem = recog_27 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L6890;

 L6891: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13086;
    case DImode:
      goto L13087;
    default:
      break;
    }
 L6928: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L6929;
  goto ret0;

 L13086: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6892;
    }
  goto L6928;

 L6892: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L6893;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6928;

 L6893: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6894;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6928;

 L6894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L6895;

 L6895: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT))
    {
      return 523;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6928;

 L13087: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6900;
    }
  goto L6928;

 L6900: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L6901;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6928;

 L6901: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6902;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6928;

 L6902: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L6903;

 L6903: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 524;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6928;

 L6929: ATTRIBUTE_UNUSED_LABEL
  return recog_28 (x0, insn, pnum_clobbers);
 ret0:
  return -1;
}

static int recog_30 PARAMS ((rtx, rtx, int *));
static int
recog_30 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case NE:
      goto L6910;
    case GE:
      goto L7050;
    case EQ:
      goto L7190;
    default:
     break;
   }
  goto ret0;

 L6910: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13115;
    case DImode:
      goto L13116;
    default:
      break;
    }
  goto ret0;

 L13115: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6911;
    }
  goto ret0;

 L6911: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L6912;
  goto ret0;

 L6912: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L6913;
    case PC:
      goto L6948;
    default:
     break;
   }
  goto ret0;

 L6913: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L6914;

 L6914: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L6915;
  goto ret0;

 L6915: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6916;
  goto ret0;

 L6916: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6917;
    }
  goto ret0;

 L6917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6918;
  goto ret0;

 L6918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6919;
  goto ret0;

 L6919: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L6920;
  goto ret0;

 L6920: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6921;
  goto ret0;

 L6921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L6922;
    }
  goto ret0;

 L6922: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L6923;
  goto ret0;

 L6923: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6924;
    }
  goto ret0;

 L6924: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 526;
    }
  goto ret0;

 L6948: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L6949;
  goto ret0;

 L6949: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L6950;

 L6950: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6951;
  goto ret0;

 L6951: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6952;
    }
  goto ret0;

 L6952: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6953;
  goto ret0;

 L6953: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6954;
  goto ret0;

 L6954: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L6955;
  goto ret0;

 L6955: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6956;
  goto ret0;

 L6956: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L6957;
    }
  goto ret0;

 L6957: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L6958;
  goto ret0;

 L6958: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L6959;
    }
  goto ret0;

 L6959: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 527;
    }
  goto ret0;

 L13116: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6981;
    }
  goto ret0;

 L6981: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L6982;
  goto ret0;

 L6982: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L6983;
    case PC:
      goto L7018;
    default:
     break;
   }
  goto ret0;

 L6983: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L6984;

 L6984: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L6985;
  goto ret0;

 L6985: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6986;
  goto ret0;

 L6986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L6987;
    }
  goto ret0;

 L6987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L6988;
  goto ret0;

 L6988: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6989;
  goto ret0;

 L6989: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L6990;
  goto ret0;

 L6990: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6991;
  goto ret0;

 L6991: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L6992;
    }
  goto ret0;

 L6992: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L6993;
  goto ret0;

 L6993: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L6994;
    }
  goto ret0;

 L6994: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 528;
    }
  goto ret0;

 L7018: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7019;
  goto ret0;

 L7019: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7020;

 L7020: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7021;
  goto ret0;

 L7021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7022;
    }
  goto ret0;

 L7022: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7023;
  goto ret0;

 L7023: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7024;
  goto ret0;

 L7024: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7025;
  goto ret0;

 L7025: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7026;
  goto ret0;

 L7026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7027;
    }
  goto ret0;

 L7027: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7028;
  goto ret0;

 L7028: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L7029;
    }
  goto ret0;

 L7029: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 529;
    }
  goto ret0;

 L7050: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13117;
    case DImode:
      goto L13118;
    default:
      break;
    }
  goto ret0;

 L13117: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L7051;
    }
  goto ret0;

 L7051: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7052;
  goto ret0;

 L7052: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7053;
    case PC:
      goto L7088;
    default:
     break;
   }
  goto ret0;

 L7053: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7054;

 L7054: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7055;
  goto ret0;

 L7055: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7056;
  goto ret0;

 L7056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7057;
    }
  goto ret0;

 L7057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7058;
  goto ret0;

 L7058: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7059;
  goto ret0;

 L7059: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7060;
  goto ret0;

 L7060: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7061;
  goto ret0;

 L7061: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7062;
    }
  goto ret0;

 L7062: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7063;
  goto ret0;

 L7063: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L7064;
    }
  goto ret0;

 L7064: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0)))
    {
      return 530;
    }
  goto ret0;

 L7088: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7089;
  goto ret0;

 L7089: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7090;

 L7090: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7091;
  goto ret0;

 L7091: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7092;
    }
  goto ret0;

 L7092: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7093;
  goto ret0;

 L7093: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7094;
  goto ret0;

 L7094: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7095;
  goto ret0;

 L7095: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7096;
  goto ret0;

 L7096: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7097;
    }
  goto ret0;

 L7097: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7098;
  goto ret0;

 L7098: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L7099;
    }
  goto ret0;

 L7099: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0)))
    {
      return 531;
    }
  goto ret0;

 L13118: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L7121;
    }
  goto ret0;

 L7121: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7122;
  goto ret0;

 L7122: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7123;
    case PC:
      goto L7158;
    default:
     break;
   }
  goto ret0;

 L7123: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7124;

 L7124: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7125;
  goto ret0;

 L7125: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7126;
  goto ret0;

 L7126: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7127;
    }
  goto ret0;

 L7127: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7128;
  goto ret0;

 L7128: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7129;
  goto ret0;

 L7129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7130;
  goto ret0;

 L7130: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7131;
  goto ret0;

 L7131: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7132;
    }
  goto ret0;

 L7132: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7133;
  goto ret0;

 L7133: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L7134;
    }
  goto ret0;

 L7134: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0)))
    {
      return 532;
    }
  goto ret0;

 L7158: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7159;
  goto ret0;

 L7159: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7160;

 L7160: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7161;
  goto ret0;

 L7161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7162;
    }
  goto ret0;

 L7162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7163;
  goto ret0;

 L7163: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7164;
  goto ret0;

 L7164: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7165;
  goto ret0;

 L7165: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7166;
  goto ret0;

 L7166: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7167;
    }
  goto ret0;

 L7167: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7168;
  goto ret0;

 L7168: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L7169;
    }
  goto ret0;

 L7169: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && find_reg_note (insn, REG_NONNEG, 0)))
    {
      return 533;
    }
  goto ret0;

 L7190: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13119;
    case DImode:
      goto L13120;
    default:
      break;
    }
  goto ret0;

 L13119: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L7191;
    }
  goto ret0;

 L7191: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7192;
  goto ret0;

 L7192: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7193;
    case PC:
      goto L7228;
    default:
     break;
   }
  goto ret0;

 L7193: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7194;

 L7194: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7195;
  goto ret0;

 L7195: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7196;
  goto ret0;

 L7196: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7197;
    }
  goto ret0;

 L7197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7198;
  goto ret0;

 L7198: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7199;
  goto ret0;

 L7199: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7200;
  goto ret0;

 L7200: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7201;
  goto ret0;

 L7201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7202;
    }
  goto ret0;

 L7202: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7203;
  goto ret0;

 L7203: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L7204;
    }
  goto ret0;

 L7204: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 534;
    }
  goto ret0;

 L7228: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7229;
  goto ret0;

 L7229: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7230;

 L7230: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7231;
  goto ret0;

 L7231: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7232;
    }
  goto ret0;

 L7232: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7233;
  goto ret0;

 L7233: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7234;
  goto ret0;

 L7234: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7235;
  goto ret0;

 L7235: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7236;
  goto ret0;

 L7236: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7237;
    }
  goto ret0;

 L7237: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7238;
  goto ret0;

 L7238: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L7239;
    }
  goto ret0;

 L7239: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64))
    {
      return 535;
    }
  goto ret0;

 L13120: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L7261;
    }
  goto ret0;

 L7261: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L7262;
  goto ret0;

 L7262: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L7263;
    case PC:
      goto L7298;
    default:
     break;
   }
  goto ret0;

 L7263: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7264;

 L7264: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L7265;
  goto ret0;

 L7265: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7266;
  goto ret0;

 L7266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7267;
    }
  goto ret0;

 L7267: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7268;
  goto ret0;

 L7268: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7269;
  goto ret0;

 L7269: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7270;
  goto ret0;

 L7270: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7271;
  goto ret0;

 L7271: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7272;
    }
  goto ret0;

 L7272: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7273;
  goto ret0;

 L7273: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L7274;
    }
  goto ret0;

 L7274: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 536;
    }
  goto ret0;

 L7298: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L7299;
  goto ret0;

 L7299: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L7300;

 L7300: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7301;
  goto ret0;

 L7301: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7302;
    }
  goto ret0;

 L7302: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7303;
  goto ret0;

 L7303: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7304;
  goto ret0;

 L7304: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7305;
  goto ret0;

 L7305: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7306;
  goto ret0;

 L7306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[3] = x2;
      goto L7307;
    }
  goto ret0;

 L7307: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L7308;
  goto ret0;

 L7308: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L7309;
    }
  goto ret0;

 L7309: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64))
    {
      return 537;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_31 PARAMS ((rtx, rtx, int *));
static int
recog_31 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L5034;
    case CALL:
      goto L5212;
    default:
     break;
   }
  goto ret0;

 L5034: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  goto L5035;
 L6907: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PC)
    goto L6908;
  goto ret0;

 L5035: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L5036;
  x2 = XEXP (x1, 0);
  goto L6907;

 L5036: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L5037;
  x2 = XEXP (x1, 0);
  goto L6907;

 L5037: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13105;
    case DImode:
      goto L13106;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L6907;

 L13105: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SYMBOL_REF)
    goto L13109;
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5038;
    }
  x2 = XEXP (x1, 0);
  goto L6907;

 L13109: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5236;
    }
 L13110: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5280;
    }
  x2 = XEXP (x1, 0);
  goto L6907;

 L5236: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5237;

 L5237: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5238;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13110;

 L5238: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5239;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13110;

 L5239: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5240;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13110;

 L5240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5241;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13110;

 L5241: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && ((INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 395;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13110;

 L5280: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5281;

 L5281: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5282;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5282: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5283;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5283: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5284;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5285;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5285: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN)
    goto L13111;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L13111: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 399;
    }
 L13112: ATTRIBUTE_UNUSED_LABEL
  if (((DEFAULT_ABI == ABI_DARWIN
       || DEFAULT_ABI == ABI_V4
       || DEFAULT_ABI == ABI_AIX_NODESC)
   && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 402;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5038: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5039;

 L5039: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5040;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5040: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5041;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5041: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5042;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5042: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L5043;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5043: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L5044;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5044: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5045;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5045: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L5046;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5046: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L5047;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5047: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L5048;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5048: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL
      && (TARGET_32BIT && DEFAULT_ABI == ABI_AIX)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 385;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L13106: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SYMBOL_REF)
    goto L13113;
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5097;
    }
  x2 = XEXP (x1, 0);
  goto L6907;

 L13113: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5248;
    }
 L13114: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5292;
    }
  x2 = XEXP (x1, 0);
  goto L6907;

 L5248: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5249;

 L5249: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5250;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13114;

 L5250: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5251;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13114;

 L5251: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5252;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13114;

 L5252: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5253;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13114;

 L5253: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && (TARGET_64BIT && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 396;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13114;

 L5292: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5293;

 L5293: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5294;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5294: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5295;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5295: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5296;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L5297;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5297: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && (TARGET_64BIT 
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[3]) & CALL_LONG) == 0))
    {
      return 400;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5097: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5098;

 L5098: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5099;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5099: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5100;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5100: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5101;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L5102;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5102: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L5103;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5103: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5104;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MEM)
    goto L5105;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5105: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L5106;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5106: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L5107;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L5107: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 40LL
      && (TARGET_64BIT && DEFAULT_ABI == ABI_AIX)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 387;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L6907;

 L6908: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L6909;
  goto ret0;

 L6909: ATTRIBUTE_UNUSED_LABEL
  return recog_30 (x0, insn, pnum_clobbers);

 L5212: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L5213;
  goto ret0;

 L5213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L13121;
    case DImode:
      goto L13122;
    default:
      break;
    }
  goto ret0;

 L13121: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SYMBOL_REF)
    goto L13125;
  goto ret0;

 L13125: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L5214;
    }
 L13126: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L5258;
    }
  goto ret0;

 L5214: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5215;

 L5215: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5216;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13126;

 L5216: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5217;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13126;

 L5217: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5218;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13126;

 L5218: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5219;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13126;

 L5219: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && ((INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 393;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13126;

 L5258: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5259;

 L5259: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5260;
  goto ret0;

 L5260: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5261;
    }
 L5304: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L5305;
    }
  goto ret0;

 L5261: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5262;
  x1 = XVECEXP (x0, 0, 1);
  x2 = XEXP (x1, 0);
  goto L5304;

 L5262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5263;
    }
  x1 = XVECEXP (x0, 0, 1);
  x2 = XEXP (x1, 0);
  goto L5304;

 L5263: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && (TARGET_32BIT
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 397;
    }
  x1 = XVECEXP (x0, 0, 1);
  x2 = XEXP (x1, 0);
  goto L5304;

 L5305: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5306;
  goto ret0;

 L5306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5307;
    }
  goto ret0;

 L5307: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && ((DEFAULT_ABI == ABI_DARWIN
     || DEFAULT_ABI == ABI_V4
     || DEFAULT_ABI == ABI_AIX_NODESC)
   && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 401;
    }
  goto ret0;

 L13122: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == SYMBOL_REF)
    goto L13127;
  goto ret0;

 L13127: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L5224;
    }
 L13128: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L5268;
    }
  goto ret0;

 L5224: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5225;

 L5225: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5226;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13128;

 L5226: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5227;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13128;

 L5227: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5228;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13128;

 L5228: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5229;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13128;

 L5229: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && (TARGET_64BIT && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 394;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13128;

 L5268: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5269;

 L5269: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5270;
  goto ret0;

 L5270: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5271;
    }
  goto ret0;

 L5271: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5272;
  goto ret0;

 L5272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5273;
    }
  goto ret0;

 L5273: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == RETURN
      && (TARGET_64BIT 
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 398;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_32 PARAMS ((rtx, rtx, int *));
static int
recog_32 (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;

  switch (XVECLEN (x0, 0))
    {
    case 2:
      goto L6;
    case 3:
      goto L674;
    case 4:
      goto L908;
    case 6:
      goto L934;
    case 5:
      goto L978;
    case 12:
      goto L4085;
    case 10:
      goto L4211;
    case 8:
      goto L4325;
    default:
      break;
    }
 L11794: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 8
      && load_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L3878;
    }
 L11795: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 7
      && load_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L3925;
    }
 L11796: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 6
      && load_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L3966;
    }
 L11797: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 5
      && load_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L4001;
    }
 L11798: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 4
      && load_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L4030;
    }
 L11799: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 3
      && load_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L4053;
    }
 L11800: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 2
      && store_multiple_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L4070;
    }
 L11804: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 3:
      goto L4867;
    case 2:
      goto L4879;
    case 5:
      goto L5013;
    case 4:
      goto L5033;
    default:
      break;
    }
 L11811: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 1
      && stmw_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L7350;
    }
 L11812: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 3
      && any_operand (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L7355;
    }
 L11813: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 1
      && mtcrf_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L7377;
    }
 L11814: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 1
      && lmw_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L7389;
    }
 L11815: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 4
      && any_operand (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L7404;
    }
 L11817: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) >= 1
      && vrsave_operation (x0, VOIDmode))
    {
      operands[0] = x0;
      goto L7499;
    }
  goto ret0;

 L6: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L7;
    case CALL:
      goto L4842;
    default:
     break;
   }
  goto L11800;

 L7: ATTRIBUTE_UNUSED_LABEL
  tem = recog_20 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L11800;

 L4842: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4843;
  goto L11800;

 L4843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12797;
    case DImode:
      goto L12798;
    default:
      break;
    }
  goto L11800;

 L12797: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4844;
    }
  goto L11800;

 L4844: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4845;

 L4845: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4846;
  goto L11800;

 L4846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4847;
    }
  goto L11800;

 L4847: ATTRIBUTE_UNUSED_LABEL
  if (((INTVAL (operands[2]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 377;
    }
  goto L11800;

 L12798: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4862;
    }
  goto L11800;

 L4862: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4863;

 L4863: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4864;
  goto L11800;

 L4864: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4865;
    }
  goto L11800;

 L4865: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (INTVAL (operands[2]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 378;
    }
  goto L11800;

 L674: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L675;
    case CALL:
      goto L4832;
    default:
     break;
   }
  goto L11799;

 L675: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case CCmode:
      goto L12799;
    case DImode:
      goto L12801;
    case SImode:
      goto L12802;
    case BLKmode:
      goto L12803;
    default:
      break;
    }
  goto L11799;

 L12799: ATTRIBUTE_UNUSED_LABEL
  tem = recog_21 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L11799;

 L12801: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L891;
  goto L11799;

 L891: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MULT)
    goto L892;
  goto L11799;

 L892: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L893;
  goto L11799;

 L893: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 3)
    goto L894;
  goto L11799;

 L894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L895;
  goto L11799;

 L895: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 4)
    goto L896;
  goto L11799;

 L896: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L897;
  goto L11799;

 L897: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L898;
    }
  goto L11799;

 L898: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L899;
  goto L11799;

 L899: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 0
      && (! TARGET_POWER && ! TARGET_POWERPC))
    {
      return 75;
    }
  goto L11799;

 L12802: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2568;
    }
  goto L11799;

 L2568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == FIX)
    goto L2569;
  goto L11799;

 L2569: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L2570;
    }
  goto L11799;

 L2570: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2571;
  goto L11799;

 L2571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2572;
    }
  goto L11799;

 L2572: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2573;
  goto L11799;

 L2573: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2574;
    }
  goto L11799;

 L2574: ATTRIBUTE_UNUSED_LABEL
  if (((TARGET_POWER2 || TARGET_POWERPC) && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 210;
    }
  goto L11799;

 L12803: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4444;
  goto L11799;

 L4444: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12816;
    case DImode:
      goto L12817;
    default:
      break;
    }
  goto L11799;

 L12816: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4445;
    }
  goto L11799;

 L4445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4446;
  goto L11799;

 L4446: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4447;
    }
  goto L11799;

 L4447: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4448;
  goto L11799;

 L4448: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4449;
    }
  goto L11799;

 L4449: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4450;
  goto L11799;

 L4450: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4451;
    }
  goto L11799;

 L4451: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER && ! TARGET_POWERPC64
   && INTVAL (operands[2]) > 4 && INTVAL (operands[2]) <= 8)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 346;
    }
 L4477: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER && ! TARGET_POWERPC64
   && INTVAL (operands[2]) > 4 && INTVAL (operands[2]) <= 8)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 347;
    }
 L4503: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && INTVAL (operands[2]) > 0 && INTVAL (operands[2]) <= 4)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 348;
    }
 L4529: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && INTVAL (operands[2]) > 0 && INTVAL (operands[2]) <= 4)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 349;
    }
  goto L11799;

 L12817: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4549;
    }
  goto L11799;

 L4549: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4550;
  goto L11799;

 L4550: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4551;
    }
  goto L11799;

 L4551: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4552;
  goto L11799;

 L4552: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4553;
    }
  goto L11799;

 L4553: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4554;
  goto L11799;

 L4554: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4555;
    }
  goto L11799;

 L4555: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && INTVAL (operands[2]) > 0 && INTVAL (operands[2]) <= 4)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 350;
    }
  goto L11799;

 L4832: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4833;
  goto L11799;

 L4833: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12818;
    case DImode:
      goto L12819;
    default:
      break;
    }
  goto L11799;

 L12818: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4834;
    }
  goto L11799;

 L4834: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4835;

 L4835: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4836;
  goto L11799;

 L4836: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4837;
    }
  goto L11799;

 L4837: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4838;
  goto L11799;

 L4838: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4839;
    }
  goto L11799;

 L4839: ATTRIBUTE_UNUSED_LABEL
  if (((INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 377;
    }
  goto L11799;

 L12819: ATTRIBUTE_UNUSED_LABEL
  if (current_file_function_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4852;
    }
  goto L11799;

 L4852: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4853;

 L4853: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4854;
  goto L11799;

 L4854: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4855;
    }
  goto L11799;

 L4855: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4856;
  goto L11799;

 L4856: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4857;
    }
  goto L11799;

 L4857: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 378;
    }
  goto L11799;

 L908: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L909;
    case CALL:
      goto L4930;
    default:
     break;
   }
  goto L11798;

 L909: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L12820;
    case DFmode:
      goto L12821;
    case BLKmode:
      goto L12822;
    default:
      break;
    }
  goto L11798;

 L12820: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L910;
  goto L11798;

 L910: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == DIV)
    goto L911;
  goto L11798;

 L911: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L912;
  goto L11798;

 L912: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L913;
  goto L11798;

 L913: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L914;
  goto L11798;

 L914: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 4)
    goto L915;
  goto L11798;

 L915: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L916;
  goto L11798;

 L916: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L917;
  goto L11798;

 L917: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L918;
  goto L11798;

 L918: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L919;
  goto L11798;

 L919: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L920;
    }
  goto L11798;

 L920: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L921;
  goto L11798;

 L921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 0
      && (! TARGET_POWER && ! TARGET_POWERPC))
    {
      return 76;
    }
  goto L11798;

 L12821: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L2589;
    }
  goto L11798;

 L2589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L12823;
  goto L11798;

 L12823: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L2590;
    case UNSIGNED_FLOAT:
      goto L2602;
    default:
     break;
   }
  goto L11798;

 L2590: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2591;
    }
  goto L11798;

 L2591: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2592;
  goto L11798;

 L2592: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2593;
    }
  goto L11798;

 L2593: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2594;
  goto L11798;

 L2594: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2595;
    }
  goto L11798;

 L2595: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L2596;
  goto L11798;

 L2596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L2597;
    }
  goto L11798;

 L2597: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 213;
    }
  goto L11798;

 L2602: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2603;
    }
  goto L11798;

 L2603: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2604;
  goto L11798;

 L2604: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2605;
    }
  goto L11798;

 L2605: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2606;
  goto L11798;

 L2606: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2607;
    }
  goto L11798;

 L2607: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L2608;
  goto L11798;

 L2608: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L2609;
    }
  goto L11798;

 L2609: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 214;
    }
  goto L11798;

 L12822: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4116;
  goto L11798;

 L4116: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12825;
    case DImode:
      goto L12826;
    default:
      break;
    }
  goto L11798;

 L12825: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4117;
    }
  goto L11798;

 L4117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4118;
  goto L11798;

 L4118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4119;
    }
  goto L11798;

 L4119: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4120;
  goto L11798;

 L4120: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4121;
    }
  goto L11798;

 L4121: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4122;
  goto L11798;

 L4122: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4123;
    }
  goto L11798;

 L4123: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4124;
  goto L11798;

 L4124: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4125;
    }
  goto L11798;

 L4125: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && ((INTVAL (operands[2]) > 24 && INTVAL (operands[2]) < 32)
       || INTVAL (operands[2]) == 0)
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 12)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 12)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 8;
      return 337;
    }
 L4167: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && ((INTVAL (operands[2]) > 24 && INTVAL (operands[2]) < 32)
       || INTVAL (operands[2]) == 0)
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 12)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 12)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 8;
      return 338;
    }
 L4247: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && INTVAL (operands[2]) > 16 && INTVAL (operands[2]) <= 24
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 10)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 10)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 6;
      return 340;
    }
 L4285: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && INTVAL (operands[2]) > 16 && INTVAL (operands[2]) <= 32
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 10)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 10)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 6;
      return 341;
    }
 L4357: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && INTVAL (operands[2]) > 8 && INTVAL (operands[2]) <= 16
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 8)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 8)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 4;
      return 343;
    }
 L4391: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && INTVAL (operands[2]) > 8 && INTVAL (operands[2]) <= 16
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 8)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 8)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 4;
      return 344;
    }
  goto L11798;

 L12826: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4201;
    }
  goto L11798;

 L4201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4202;
  goto L11798;

 L4202: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4203;
    }
  goto L11798;

 L4203: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4204;
  goto L11798;

 L4204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4205;
    }
  goto L11798;

 L4205: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4206;
  goto L11798;

 L4206: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4207;
    }
  goto L11798;

 L4207: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4208;
  goto L11798;

 L4208: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4209;
    }
  goto L11798;

 L4209: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && ((INTVAL (operands[2]) > 24 && INTVAL (operands[2]) < 32)
       || INTVAL (operands[2]) == 0)
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 12)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 12)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 8;
      return 339;
    }
 L4323: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && INTVAL (operands[2]) > 16 && INTVAL (operands[2]) <= 32
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 10)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 10)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 6;
      return 342;
    }
 L4425: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && INTVAL (operands[2]) > 8 && INTVAL (operands[2]) <= 16
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 8)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 8)
   && REGNO (operands[4]) == 5)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 4;
      return 345;
    }
  goto L11798;

 L4930: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4931;
  goto L11798;

 L4931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12827;
    case DImode:
      goto L12828;
    default:
      break;
    }
  goto L11798;

 L12827: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4932;
    }
  goto L11798;

 L4932: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4933;

 L4933: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4934;
  goto L11798;

 L4934: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4935;
  goto L11798;

 L4935: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4936;
  goto L11798;

 L4936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L4937;
  goto L11798;

 L4937: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L4938;
  goto L11798;

 L4938: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4939;
  goto L11798;

 L4939: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4940;
  goto L11798;

 L4940: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4941;
  goto L11798;

 L4941: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L4942;
  goto L11798;

 L4942: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL
      && (TARGET_32BIT && DEFAULT_ABI == ABI_AIX)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 381;
    }
  goto L11798;

 L12828: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4983;
    }
  goto L11798;

 L4983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4984;

 L4984: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4985;
  goto L11798;

 L4985: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4986;
  goto L11798;

 L4986: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4987;
  goto L11798;

 L4987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L4988;
  goto L11798;

 L4988: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L4989;
  goto L11798;

 L4989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4990;
  goto L11798;

 L4990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MEM)
    goto L4991;
  goto L11798;

 L4991: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L4992;
  goto L11798;

 L4992: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L4993;
  goto L11798;

 L4993: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 40LL
      && (TARGET_64BIT && DEFAULT_ABI == ABI_AIX)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 383;
    }
  goto L11798;

 L934: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L935;
  goto L11796;

 L935: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L12829;
    case DFmode:
      goto L12830;
    default:
      break;
    }
  goto L11796;

 L12829: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L936;
  goto L11796;

 L936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UDIV)
    goto L937;
  goto L11796;

 L937: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L938;
  goto L11796;

 L938: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L939;
  goto L11796;

 L939: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L940;
  goto L11796;

 L940: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 4)
    goto L941;
  goto L11796;

 L941: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L942;
  goto L11796;

 L942: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L943;
  goto L11796;

 L943: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L944;
  goto L11796;

 L944: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L945;
  goto L11796;

 L945: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L946;
    }
  goto L11796;

 L946: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L947;
  goto L11796;

 L947: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 0)
    goto L948;
  goto L11796;

 L948: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L949;
  goto L11796;

 L949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[1] = x2;
      goto L950;
    }
  goto L11796;

 L950: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L951;
  goto L11796;

 L951: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 69
      && (! TARGET_POWER && ! TARGET_POWERPC))
    {
      return 77;
    }
  goto L11796;

 L12830: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L2538;
    }
  goto L11796;

 L2538: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == FLOAT)
    goto L2539;
  goto L11796;

 L2539: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2540;
    }
  goto L11796;

 L2540: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L2541;
  goto L11796;

 L2541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2542;
    }
  goto L11796;

 L2542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L2543;
  goto L11796;

 L2543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2544;
    }
  goto L11796;

 L2544: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L2545;
  goto L11796;

 L2545: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[4] = x2;
      goto L2546;
    }
  goto L11796;

 L2546: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L2547;
  goto L11796;

 L2547: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[5] = x2;
      goto L2548;
    }
  goto L11796;

 L2548: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L2549;
  goto L11796;

 L2549: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L2550;
    }
  goto L11796;

 L2550: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 208;
    }
  goto L11796;

 L978: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L979;
    case CALL:
      goto L4912;
    default:
     break;
   }
  goto L11797;

 L979: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L12831;
    case DFmode:
      goto L12832;
    case BLKmode:
      goto L12833;
    default:
      break;
    }
  goto L11797;

 L12831: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 3)
    goto L980;
  goto L11797;

 L980: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UDIV)
    goto L981;
  goto L11797;

 L981: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 3)
    goto L982;
  goto L11797;

 L982: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 4)
    goto L983;
  goto L11797;

 L983: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L984;
  goto L11797;

 L984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L985;
    }
  goto L11797;

 L985: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L986;
  goto L11797;

 L986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 0)
    goto L987;
  goto L11797;

 L987: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L988;
  goto L11797;

 L988: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, CCmode))
    {
      operands[1] = x2;
      goto L989;
    }
  goto L11797;

 L989: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L990;
  goto L11797;

 L990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 69
      && (! TARGET_POWER && ! TARGET_POWERPC))
    {
      return 79;
    }
  goto L11797;

 L12832: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L2554;
    }
  goto L11797;

 L2554: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == UNSIGNED_FLOAT)
    goto L2555;
  goto L11797;

 L2555: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2556;
    }
  goto L11797;

 L2556: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L2557;
  goto L11797;

 L2557: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2558;
    }
  goto L11797;

 L2558: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L2559;
  goto L11797;

 L2559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L2560;
    }
  goto L11797;

 L2560: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L2561;
  goto L11797;

 L2561: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[4] = x2;
      goto L2562;
    }
  goto L11797;

 L2562: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L2563;
  goto L11797;

 L2563: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[5] = x2;
      goto L2564;
    }
  goto L11797;

 L2564: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && TARGET_HARD_FLOAT && TARGET_FPRS))
    {
      return 209;
    }
  goto L11797;

 L12833: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4429;
  goto L11797;

 L4429: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12834;
    case DImode:
      goto L12835;
    default:
      break;
    }
  goto L11797;

 L12834: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4430;
    }
  goto L11797;

 L4430: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4431;
  goto L11797;

 L4431: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4432;
    }
  goto L11797;

 L4432: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4433;
  goto L11797;

 L4433: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4434;
    }
  goto L11797;

 L4434: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4435;
  goto L11797;

 L4435: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4436;
    }
  goto L11797;

 L4436: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4437;
  goto L11797;

 L4437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L12836;
    case SImode:
      goto L12837;
    default:
      break;
    }
  goto L11797;

 L12836: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L4438;
    }
  goto L11797;

 L4438: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4439;
  goto L11797;

 L4439: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4440;
    }
  goto L11797;

 L4440: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER && ! TARGET_POWERPC64
   && INTVAL (operands[2]) > 4 && INTVAL (operands[2]) <= 8))
    {
      return 346;
    }
 L4466: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER && ! TARGET_POWERPC64
   && INTVAL (operands[2]) > 4 && INTVAL (operands[2]) <= 8))
    {
      return 347;
    }
  goto L11797;

 L12837: ATTRIBUTE_UNUSED_LABEL
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4490;
    }
  goto L11797;

 L4490: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4491;
  goto L11797;

 L4491: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4492;
    }
  goto L11797;

 L4492: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && INTVAL (operands[2]) > 0 && INTVAL (operands[2]) <= 4))
    {
      return 348;
    }
 L4518: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && INTVAL (operands[2]) > 0 && INTVAL (operands[2]) <= 4))
    {
      return 349;
    }
  goto L11797;

 L12835: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4534;
    }
  goto L11797;

 L4534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4535;
  goto L11797;

 L4535: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4536;
    }
  goto L11797;

 L4536: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4537;
  goto L11797;

 L4537: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4538;
    }
  goto L11797;

 L4538: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4539;
  goto L11797;

 L4539: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4540;
    }
  goto L11797;

 L4540: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4541;
  goto L11797;

 L4541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4542;
    }
  goto L11797;

 L4542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4543;
  goto L11797;

 L4543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4544;
    }
  goto L11797;

 L4544: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && INTVAL (operands[2]) > 0 && INTVAL (operands[2]) <= 4))
    {
      return 350;
    }
  goto L11797;

 L4912: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4913;
  goto L11797;

 L4913: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12838;
    case DImode:
      goto L12839;
    default:
      break;
    }
  goto L11797;

 L12838: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4914;
    }
  goto L11797;

 L4914: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4915;

 L4915: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4916;
  goto L11797;

 L4916: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4917;
  goto L11797;

 L4917: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4918;
  goto L11797;

 L4918: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L4919;
  goto L11797;

 L4919: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L4920;
  goto L11797;

 L4920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4921;
  goto L11797;

 L4921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4922;
  goto L11797;

 L4922: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4923;
  goto L11797;

 L4923: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L4924;
  goto L11797;

 L4924: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL)
    goto L4925;
  goto L11797;

 L4925: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4926;
  goto L11797;

 L4926: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4927;
    }
  goto L11797;

 L4927: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT && DEFAULT_ABI == ABI_AIX))
    {
      return 381;
    }
  goto L11797;

 L12839: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4965;
    }
  goto L11797;

 L4965: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4966;

 L4966: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4967;
  goto L11797;

 L4967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4968;
  goto L11797;

 L4968: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4969;
  goto L11797;

 L4969: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L4970;
  goto L11797;

 L4970: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L4971;
  goto L11797;

 L4971: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L4972;
  goto L11797;

 L4972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MEM)
    goto L4973;
  goto L11797;

 L4973: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L4974;
  goto L11797;

 L4974: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L4975;
  goto L11797;

 L4975: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 40LL)
    goto L4976;
  goto L11797;

 L4976: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4977;
  goto L11797;

 L4977: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4978;
    }
  goto L11797;

 L4978: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && DEFAULT_ABI == ABI_AIX))
    {
      return 383;
    }
  goto L11797;

 L4085: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4086;
  goto L11794;

 L4086: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4087;
  goto L11794;

 L4087: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12840;
    case DImode:
      goto L12841;
    default:
      break;
    }
  goto L11794;

 L12840: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4088;
    }
  goto L11794;

 L4088: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4089;
  goto L11794;

 L4089: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4090;
    }
  goto L11794;

 L4090: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4091;
  goto L11794;

 L4091: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4092;
    }
  goto L11794;

 L4092: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4093;
  goto L11794;

 L4093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4094;
    }
  goto L11794;

 L4094: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4095;
  goto L11794;

 L4095: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4096;
    }
  goto L11794;

 L4096: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4097;
  goto L11794;

 L4097: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L4098;
  goto L11794;

 L4098: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L4099;
  goto L11794;

 L4099: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4100;
  goto L11794;

 L4100: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == CLOBBER)
    goto L4101;
  goto L11794;

 L4101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 8)
    goto L4102;
  goto L11794;

 L4102: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == CLOBBER)
    goto L4103;
  goto L11794;

 L4103: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 9)
    goto L4104;
  goto L11794;

 L4104: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 8);
  if (GET_CODE (x1) == CLOBBER)
    goto L4105;
  goto L11794;

 L4105: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 10)
    goto L4106;
  goto L11794;

 L4106: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 9);
  if (GET_CODE (x1) == CLOBBER)
    goto L4107;
  goto L11794;

 L4107: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L4108;
  goto L11794;

 L4108: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 10);
  if (GET_CODE (x1) == CLOBBER)
    goto L4109;
  goto L11794;

 L4109: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 12)
    goto L4110;
  goto L11794;

 L4110: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 11);
  if (GET_CODE (x1) == CLOBBER)
    goto L4111;
  goto L11794;

 L4111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4112;
    }
  goto L11794;

 L4112: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && ((INTVAL (operands[2]) > 24 && INTVAL (operands[2]) < 32)
       || INTVAL (operands[2]) == 0)
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 12)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 12)
   && REGNO (operands[4]) == 5))
    {
      return 337;
    }
 L4154: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && ((INTVAL (operands[2]) > 24 && INTVAL (operands[2]) < 32)
       || INTVAL (operands[2]) == 0)
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 12)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 12)
   && REGNO (operands[4]) == 5))
    {
      return 338;
    }
  goto L11794;

 L12841: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4172;
    }
  goto L11794;

 L4172: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4173;
  goto L11794;

 L4173: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4174;
    }
  goto L11794;

 L4174: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4175;
  goto L11794;

 L4175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4176;
    }
  goto L11794;

 L4176: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4177;
  goto L11794;

 L4177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4178;
    }
  goto L11794;

 L4178: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4179;
  goto L11794;

 L4179: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4180;
    }
  goto L11794;

 L4180: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4181;
  goto L11794;

 L4181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L4182;
  goto L11794;

 L4182: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L4183;
  goto L11794;

 L4183: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4184;
  goto L11794;

 L4184: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == CLOBBER)
    goto L4185;
  goto L11794;

 L4185: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 8)
    goto L4186;
  goto L11794;

 L4186: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == CLOBBER)
    goto L4187;
  goto L11794;

 L4187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 9)
    goto L4188;
  goto L11794;

 L4188: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 8);
  if (GET_CODE (x1) == CLOBBER)
    goto L4189;
  goto L11794;

 L4189: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 10)
    goto L4190;
  goto L11794;

 L4190: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 9);
  if (GET_CODE (x1) == CLOBBER)
    goto L4191;
  goto L11794;

 L4191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L4192;
  goto L11794;

 L4192: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 10);
  if (GET_CODE (x1) == CLOBBER)
    goto L4193;
  goto L11794;

 L4193: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 12)
    goto L4194;
  goto L11794;

 L4194: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 11);
  if (GET_CODE (x1) == CLOBBER)
    goto L4195;
  goto L11794;

 L4195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4196;
    }
  goto L11794;

 L4196: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && ((INTVAL (operands[2]) > 24 && INTVAL (operands[2]) < 32)
       || INTVAL (operands[2]) == 0)
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 12)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 12)
   && REGNO (operands[4]) == 5))
    {
      return 339;
    }
  goto L11794;

 L4211: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4212;
  goto L11794;

 L4212: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4213;
  goto L11794;

 L4213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12842;
    case DImode:
      goto L12843;
    default:
      break;
    }
  goto L11794;

 L12842: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4214;
    }
  goto L11794;

 L4214: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4215;
  goto L11794;

 L4215: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4216;
    }
  goto L11794;

 L4216: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4217;
  goto L11794;

 L4217: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4218;
    }
  goto L11794;

 L4218: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4219;
  goto L11794;

 L4219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4220;
    }
  goto L11794;

 L4220: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4221;
  goto L11794;

 L4221: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4222;
    }
  goto L11794;

 L4222: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4223;
  goto L11794;

 L4223: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L4224;
  goto L11794;

 L4224: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L4225;
  goto L11794;

 L4225: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4226;
  goto L11794;

 L4226: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == CLOBBER)
    goto L4227;
  goto L11794;

 L4227: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 8)
    goto L4228;
  goto L11794;

 L4228: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == CLOBBER)
    goto L4229;
  goto L11794;

 L4229: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 9)
    goto L4230;
  goto L11794;

 L4230: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 8);
  if (GET_CODE (x1) == CLOBBER)
    goto L4231;
  goto L11794;

 L4231: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 10)
    goto L4232;
  goto L11794;

 L4232: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 9);
  if (GET_CODE (x1) == CLOBBER)
    goto L4233;
  goto L11794;

 L4233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4234;
    }
  goto L11794;

 L4234: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && INTVAL (operands[2]) > 16 && INTVAL (operands[2]) <= 24
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 10)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 10)
   && REGNO (operands[4]) == 5))
    {
      return 340;
    }
 L4272: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && INTVAL (operands[2]) > 16 && INTVAL (operands[2]) <= 32
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 10)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 10)
   && REGNO (operands[4]) == 5))
    {
      return 341;
    }
  goto L11794;

 L12843: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4290;
    }
  goto L11794;

 L4290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4291;
  goto L11794;

 L4291: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4292;
    }
  goto L11794;

 L4292: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4293;
  goto L11794;

 L4293: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4294;
    }
  goto L11794;

 L4294: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4295;
  goto L11794;

 L4295: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4296;
    }
  goto L11794;

 L4296: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4297;
  goto L11794;

 L4297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4298;
    }
  goto L11794;

 L4298: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4299;
  goto L11794;

 L4299: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L4300;
  goto L11794;

 L4300: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L4301;
  goto L11794;

 L4301: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4302;
  goto L11794;

 L4302: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == CLOBBER)
    goto L4303;
  goto L11794;

 L4303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 8)
    goto L4304;
  goto L11794;

 L4304: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == CLOBBER)
    goto L4305;
  goto L11794;

 L4305: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 9)
    goto L4306;
  goto L11794;

 L4306: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 8);
  if (GET_CODE (x1) == CLOBBER)
    goto L4307;
  goto L11794;

 L4307: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 10)
    goto L4308;
  goto L11794;

 L4308: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 9);
  if (GET_CODE (x1) == CLOBBER)
    goto L4309;
  goto L11794;

 L4309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4310;
    }
  goto L11794;

 L4310: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && INTVAL (operands[2]) > 16 && INTVAL (operands[2]) <= 32
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 10)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 10)
   && REGNO (operands[4]) == 5))
    {
      return 342;
    }
  goto L11794;

 L4325: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4326;
  goto L11794;

 L4326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4327;
  goto L11794;

 L4327: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12844;
    case DImode:
      goto L12845;
    default:
      break;
    }
  goto L11794;

 L12844: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4328;
    }
  goto L11794;

 L4328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4329;
  goto L11794;

 L4329: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4330;
    }
  goto L11794;

 L4330: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4331;
  goto L11794;

 L4331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4332;
    }
  goto L11794;

 L4332: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4333;
  goto L11794;

 L4333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4334;
    }
  goto L11794;

 L4334: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4335;
  goto L11794;

 L4335: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4336;
    }
  goto L11794;

 L4336: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4337;
  goto L11794;

 L4337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L4338;
  goto L11794;

 L4338: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L4339;
  goto L11794;

 L4339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4340;
  goto L11794;

 L4340: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == CLOBBER)
    goto L4341;
  goto L11794;

 L4341: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 8)
    goto L4342;
  goto L11794;

 L4342: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == CLOBBER)
    goto L4343;
  goto L11794;

 L4343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4344;
    }
  goto L11794;

 L4344: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER
   && INTVAL (operands[2]) > 8 && INTVAL (operands[2]) <= 16
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 8)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 8)
   && REGNO (operands[4]) == 5))
    {
      return 343;
    }
 L4378: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER
   && INTVAL (operands[2]) > 8 && INTVAL (operands[2]) <= 16
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 8)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 8)
   && REGNO (operands[4]) == 5))
    {
      return 344;
    }
  goto L11794;

 L12845: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4396;
    }
  goto L11794;

 L4396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L4397;
  goto L11794;

 L4397: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4398;
    }
  goto L11794;

 L4398: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4399;
  goto L11794;

 L4399: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4400;
    }
  goto L11794;

 L4400: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L4401;
  goto L11794;

 L4401: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4402;
    }
  goto L11794;

 L4402: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER)
    goto L4403;
  goto L11794;

 L4403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4404;
    }
  goto L11794;

 L4404: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L4405;
  goto L11794;

 L4405: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L4406;
  goto L11794;

 L4406: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == CLOBBER)
    goto L4407;
  goto L11794;

 L4407: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L4408;
  goto L11794;

 L4408: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == CLOBBER)
    goto L4409;
  goto L11794;

 L4409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 8)
    goto L4410;
  goto L11794;

 L4410: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == CLOBBER)
    goto L4411;
  goto L11794;

 L4411: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4412;
    }
  goto L11794;

 L4412: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWERPC64
   && INTVAL (operands[2]) > 8 && INTVAL (operands[2]) <= 16
   && (REGNO (operands[0]) < 5 || REGNO (operands[0]) > 8)
   && (REGNO (operands[1]) < 5 || REGNO (operands[1]) > 8)
   && REGNO (operands[4]) == 5))
    {
      return 345;
    }
  goto L11794;

 L3878: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L3879;
  goto L11795;

 L3879: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3880;
    }
  goto L11795;

 L3880: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3881;
  goto L11795;

 L3881: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3882;
    }
  goto L11795;

 L3882: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3883;
  goto L11795;

 L3883: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L3884;
    }
  goto L11795;

 L3884: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3885;
  goto L11795;

 L3885: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3886;
  goto L11795;

 L3886: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3887;
  goto L11795;

 L3887: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L3888;
  goto L11795;

 L3888: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L3889;
  goto L11795;

 L3889: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L3890;
    }
  goto L11795;

 L3890: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3891;
  goto L11795;

 L3891: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3892;
  goto L11795;

 L3892: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3893;
  goto L11795;

 L3893: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3894;
  goto L11795;

 L3894: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L3895;
  goto L11795;

 L3895: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L3896;
    }
  goto L11795;

 L3896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3897;
  goto L11795;

 L3897: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3898;
  goto L11795;

 L3898: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3899;
  goto L11795;

 L3899: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L3900;
  goto L11795;

 L3900: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == SET)
    goto L3901;
  goto L11795;

 L3901: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L3902;
    }
  goto L11795;

 L3902: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3903;
  goto L11795;

 L3903: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3904;
  goto L11795;

 L3904: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3905;
  goto L11795;

 L3905: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 16LL)
    goto L3906;
  goto L11795;

 L3906: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == SET)
    goto L3907;
  goto L11795;

 L3907: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[7] = x2;
      goto L3908;
    }
  goto L11795;

 L3908: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3909;
  goto L11795;

 L3909: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3910;
  goto L11795;

 L3910: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3911;
  goto L11795;

 L3911: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL)
    goto L3912;
  goto L11795;

 L3912: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == SET)
    goto L3913;
  goto L11795;

 L3913: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[8] = x2;
      goto L3914;
    }
  goto L11795;

 L3914: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3915;
  goto L11795;

 L3915: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3916;
  goto L11795;

 L3916: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3917;
  goto L11795;

 L3917: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 24LL)
    goto L3918;
  goto L11795;

 L3918: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == SET)
    goto L3919;
  goto L11795;

 L3919: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[9] = x2;
      goto L3920;
    }
  goto L11795;

 L3920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3921;
  goto L11795;

 L3921: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3922;
  goto L11795;

 L3922: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3923;
  goto L11795;

 L3923: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 28LL
      && (TARGET_STRING && XVECLEN (operands[0], 0) == 8))
    {
      return 329;
    }
  goto L11795;

 L3925: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L3926;
  goto L11796;

 L3926: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3927;
    }
  goto L11796;

 L3927: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3928;
  goto L11796;

 L3928: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3929;
    }
  goto L11796;

 L3929: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3930;
  goto L11796;

 L3930: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L3931;
    }
  goto L11796;

 L3931: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3932;
  goto L11796;

 L3932: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3933;
  goto L11796;

 L3933: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3934;
  goto L11796;

 L3934: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L3935;
  goto L11796;

 L3935: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L3936;
  goto L11796;

 L3936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L3937;
    }
  goto L11796;

 L3937: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3938;
  goto L11796;

 L3938: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3939;
  goto L11796;

 L3939: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3940;
  goto L11796;

 L3940: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3941;
  goto L11796;

 L3941: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L3942;
  goto L11796;

 L3942: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L3943;
    }
  goto L11796;

 L3943: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3944;
  goto L11796;

 L3944: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3945;
  goto L11796;

 L3945: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3946;
  goto L11796;

 L3946: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L3947;
  goto L11796;

 L3947: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == SET)
    goto L3948;
  goto L11796;

 L3948: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L3949;
    }
  goto L11796;

 L3949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3950;
  goto L11796;

 L3950: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3951;
  goto L11796;

 L3951: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3952;
  goto L11796;

 L3952: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 16LL)
    goto L3953;
  goto L11796;

 L3953: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == SET)
    goto L3954;
  goto L11796;

 L3954: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[7] = x2;
      goto L3955;
    }
  goto L11796;

 L3955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3956;
  goto L11796;

 L3956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3957;
  goto L11796;

 L3957: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3958;
  goto L11796;

 L3958: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL)
    goto L3959;
  goto L11796;

 L3959: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == SET)
    goto L3960;
  goto L11796;

 L3960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[8] = x2;
      goto L3961;
    }
  goto L11796;

 L3961: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3962;
  goto L11796;

 L3962: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3963;
  goto L11796;

 L3963: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3964;
  goto L11796;

 L3964: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 24LL
      && (TARGET_STRING && XVECLEN (operands[0], 0) == 7))
    {
      return 330;
    }
  goto L11796;

 L3966: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L3967;
  goto L11797;

 L3967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3968;
    }
  goto L11797;

 L3968: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3969;
  goto L11797;

 L3969: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3970;
    }
  goto L11797;

 L3970: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3971;
  goto L11797;

 L3971: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L3972;
    }
  goto L11797;

 L3972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3973;
  goto L11797;

 L3973: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3974;
  goto L11797;

 L3974: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3975;
  goto L11797;

 L3975: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L3976;
  goto L11797;

 L3976: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L3977;
  goto L11797;

 L3977: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L3978;
    }
  goto L11797;

 L3978: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3979;
  goto L11797;

 L3979: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3980;
  goto L11797;

 L3980: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3981;
  goto L11797;

 L3981: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3982;
  goto L11797;

 L3982: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L3983;
  goto L11797;

 L3983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L3984;
    }
  goto L11797;

 L3984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3985;
  goto L11797;

 L3985: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3986;
  goto L11797;

 L3986: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3987;
  goto L11797;

 L3987: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L3988;
  goto L11797;

 L3988: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == SET)
    goto L3989;
  goto L11797;

 L3989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L3990;
    }
  goto L11797;

 L3990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3991;
  goto L11797;

 L3991: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3992;
  goto L11797;

 L3992: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3993;
  goto L11797;

 L3993: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 16LL)
    goto L3994;
  goto L11797;

 L3994: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == SET)
    goto L3995;
  goto L11797;

 L3995: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[7] = x2;
      goto L3996;
    }
  goto L11797;

 L3996: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L3997;
  goto L11797;

 L3997: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L3998;
  goto L11797;

 L3998: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3999;
  goto L11797;

 L3999: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL
      && (TARGET_STRING && XVECLEN (operands[0], 0) == 6))
    {
      return 331;
    }
  goto L11797;

 L4001: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4002;
  goto L11798;

 L4002: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4003;
    }
  goto L11798;

 L4003: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4004;
  goto L11798;

 L4004: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4005;
    }
  goto L11798;

 L4005: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4006;
  goto L11798;

 L4006: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4007;
    }
  goto L11798;

 L4007: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4008;
  goto L11798;

 L4008: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4009;
  goto L11798;

 L4009: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4010;
  goto L11798;

 L4010: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L4011;
  goto L11798;

 L4011: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L4012;
  goto L11798;

 L4012: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4013;
    }
  goto L11798;

 L4013: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4014;
  goto L11798;

 L4014: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4015;
  goto L11798;

 L4015: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4016;
  goto L11798;

 L4016: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L4017;
  goto L11798;

 L4017: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L4018;
  goto L11798;

 L4018: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4019;
    }
  goto L11798;

 L4019: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4020;
  goto L11798;

 L4020: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4021;
  goto L11798;

 L4021: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4022;
  goto L11798;

 L4022: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L4023;
  goto L11798;

 L4023: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == SET)
    goto L4024;
  goto L11798;

 L4024: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[6] = x2;
      goto L4025;
    }
  goto L11798;

 L4025: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4026;
  goto L11798;

 L4026: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4027;
  goto L11798;

 L4027: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4028;
  goto L11798;

 L4028: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 16LL
      && (TARGET_STRING && XVECLEN (operands[0], 0) == 5))
    {
      return 332;
    }
  goto L11798;

 L4030: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4031;
  goto L11799;

 L4031: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4032;
    }
  goto L11799;

 L4032: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4033;
  goto L11799;

 L4033: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4034;
    }
  goto L11799;

 L4034: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4035;
  goto L11799;

 L4035: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4036;
    }
  goto L11799;

 L4036: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4037;
  goto L11799;

 L4037: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4038;
  goto L11799;

 L4038: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4039;
  goto L11799;

 L4039: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L4040;
  goto L11799;

 L4040: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L4041;
  goto L11799;

 L4041: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4042;
    }
  goto L11799;

 L4042: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4043;
  goto L11799;

 L4043: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4044;
  goto L11799;

 L4044: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4045;
  goto L11799;

 L4045: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L4046;
  goto L11799;

 L4046: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L4047;
  goto L11799;

 L4047: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[5] = x2;
      goto L4048;
    }
  goto L11799;

 L4048: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4049;
  goto L11799;

 L4049: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4050;
  goto L11799;

 L4050: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4051;
  goto L11799;

 L4051: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL
      && (TARGET_STRING && XVECLEN (operands[0], 0) == 4))
    {
      return 333;
    }
  goto L11799;

 L4053: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4054;
  goto L11800;

 L4054: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4055;
    }
  goto L11800;

 L4055: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4056;
  goto L11800;

 L4056: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4057;
    }
  goto L11800;

 L4057: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4058;
  goto L11800;

 L4058: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4059;
    }
  goto L11800;

 L4059: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4060;
  goto L11800;

 L4060: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4061;
  goto L11800;

 L4061: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4062;
  goto L11800;

 L4062: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L4063;
  goto L11800;

 L4063: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L4064;
  goto L11800;

 L4064: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L4065;
    }
  goto L11800;

 L4065: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4066;
  goto L11800;

 L4066: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L4067;
  goto L11800;

 L4067: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4068;
  goto L11800;

 L4068: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL
      && (TARGET_STRING && XVECLEN (operands[0], 0) == 3))
    {
      return 334;
    }
  goto L11800;

 L4070: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L4071;
  goto L11804;

 L4071: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12846;
  goto L11804;

 L12846: ATTRIBUTE_UNUSED_LABEL
  if (indirect_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4072;
    }
 L12847: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L4079;
  goto L11804;

 L4072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4073;
    }
  x2 = XEXP (x1, 0);
  goto L12847;

 L4073: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4074;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12847;

 L4074: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4075;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12847;

 L4075: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && TARGET_POWER))
    {
      return 335;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L12847;

 L4079: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4080;
    }
  goto L11804;

 L4080: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4081;
    }
  goto L11804;

 L4081: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4082;
  goto L11804;

 L4082: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4083;
    }
  goto L11804;

 L4083: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_STRING && ! TARGET_POWER))
    {
      return 336;
    }
  goto L11804;

 L4867: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L4868;
    case CALL:
      goto L4945;
    default:
     break;
   }
  goto L11811;

 L4868: ATTRIBUTE_UNUSED_LABEL
  tem = recog_23 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L11811;

 L4945: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4946;
  goto L11811;

 L4946: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L12878;
    case DImode:
      goto L12879;
    default:
      break;
    }
  goto L11811;

 L12878: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4947;
    }
  if (register_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L5134;
    }
  goto L11811;

 L4947: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4948;

 L4948: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4949;
  goto L11811;

 L4949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4950;
    }
  goto L11811;

 L4950: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4951;
  goto L11811;

 L4951: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4952;
    }
  goto L11811;

 L4952: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 382;
    }
 L5157: ATTRIBUTE_UNUSED_LABEL
  if (((DEFAULT_ABI == ABI_AIX_NODESC
    || DEFAULT_ABI == ABI_V4
    || DEFAULT_ABI == ABI_DARWIN)
   && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 390;
    }
  goto L11811;

 L5134: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5135;

 L5135: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5136;
  goto L11811;

 L5136: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5137;
    }
  goto L11811;

 L5137: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5138;
  goto L11811;

 L5138: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5139;
    }
  goto L11811;

 L5139: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX_NODESC
   || DEFAULT_ABI == ABI_V4
   || DEFAULT_ABI == ABI_DARWIN))
    {
      return 389;
    }
  goto L11811;

 L12879: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L4998;
    }
  goto L11811;

 L4998: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4999;

 L4999: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5000;
  goto L11811;

 L5000: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5001;
    }
  goto L11811;

 L5001: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5002;
  goto L11811;

 L5002: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5003;
    }
  goto L11811;

 L5003: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT 
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[2]) & CALL_LONG) == 0))
    {
      return 384;
    }
  goto L11811;

 L4879: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L4880;
    case CALL:
      goto L4955;
    case RETURN:
      goto L7395;
    case UNSPEC_VOLATILE:
      goto L12881;
    default:
     break;
   }
  goto L11811;

 L4880: ATTRIBUTE_UNUSED_LABEL
  tem = recog_29 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L11811;

 L4955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L4956;
  goto L11811;

 L4956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L13094;
    case DImode:
      goto L13095;
    default:
      break;
    }
  goto L11811;

 L13094: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L4957;
    }
  if (register_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L5144;
    }
  goto L11811;

 L4957: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L4958;

 L4958: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4959;
  goto L11811;

 L4959: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4960;
    }
  goto L11811;

 L4960: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[2]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 382;
    }
 L5165: ATTRIBUTE_UNUSED_LABEL
  if (((DEFAULT_ABI == ABI_AIX_NODESC
    || DEFAULT_ABI == ABI_V4
    || DEFAULT_ABI == ABI_DARWIN)
   && (INTVAL (operands[2]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 390;
    }
  goto L11811;

 L5144: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5145;

 L5145: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5146;
  goto L11811;

 L5146: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5147;
    }
  goto L11811;

 L5147: ATTRIBUTE_UNUSED_LABEL
  if ((DEFAULT_ABI == ABI_AIX_NODESC
   || DEFAULT_ABI == ABI_V4
   || DEFAULT_ABI == ABI_DARWIN)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 389;
    }
  goto L11811;

 L13095: ATTRIBUTE_UNUSED_LABEL
  if (symbol_ref_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L5008;
    }
  goto L11811;

 L5008: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[1] = x2;
  goto L5009;

 L5009: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5010;
  goto L11811;

 L5010: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L5011;
    }
  goto L11811;

 L5011: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT 
   && DEFAULT_ABI == ABI_AIX
   && (INTVAL (operands[2]) & CALL_LONG) == 0)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 384;
    }
  goto L11811;

 L7395: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L7396;
  goto L11811;

 L7396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13097;
    case DImode:
      goto L13098;
    default:
      break;
    }
  goto L11811;

 L13097: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L7397;
    }
  goto L11811;

 L7397: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT))
    {
      return 549;
    }
  goto L11811;

 L13098: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L7402;
    }
  goto L11811;

 L7402: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 550;
    }
  goto L11811;

 L12881: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 9)
    goto L7425;
  goto L11811;

 L7425: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13099;
    case DImode:
      goto L13100;
    default:
      break;
    }
  goto L11811;

 L13099: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L7426;
    }
  goto L11811;

 L7426: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7427;
  goto L11811;

 L7427: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7428;
    }
  goto L11811;

 L7428: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT))
    {
      return 553;
    }
  goto L11811;

 L13100: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L7435;
    }
  goto L11811;

 L7435: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7436;
  goto L11811;

 L7436: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L7437;
    }
  goto L11811;

 L7437: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 554;
    }
  goto L11811;

 L5013: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L5014;
  goto L11811;

 L5014: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  goto L5015;

 L5015: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L5016;
  goto L11811;

 L5016: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MEM)
    goto L5017;
  goto L11811;

 L5017: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13101;
    case DImode:
      goto L13102;
    default:
      break;
    }
  goto L11811;

 L13101: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5018;
    }
  goto L11811;

 L5018: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5019;

 L5019: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5020;
  goto L11811;

 L5020: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5021;
  goto L11811;

 L5021: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5022;
  goto L11811;

 L5022: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L5023;
  goto L11811;

 L5023: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L5024;
  goto L11811;

 L5024: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5025;
  goto L11811;

 L5025: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L5026;
  goto L11811;

 L5026: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L5027;
  goto L11811;

 L5027: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L5028;
  goto L11811;

 L5028: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 20LL)
    goto L5029;
  goto L11811;

 L5029: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L5030;
  goto L11811;

 L5030: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5031;
    }
  goto L11811;

 L5031: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT && DEFAULT_ABI == ABI_AIX))
    {
      return 385;
    }
  goto L11811;

 L13102: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5077;
    }
  goto L11811;

 L5077: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L5078;

 L5078: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L5079;
  goto L11811;

 L5079: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5080;
  goto L11811;

 L5080: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L5081;
  goto L11811;

 L5081: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 11)
    goto L5082;
  goto L11811;

 L5082: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L5083;
  goto L11811;

 L5083: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 2)
    goto L5084;
  goto L11811;

 L5084: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MEM)
    goto L5085;
  goto L11811;

 L5085: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L5086;
  goto L11811;

 L5086: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 1)
    goto L5087;
  goto L11811;

 L5087: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 40LL)
    goto L5088;
  goto L11811;

 L5088: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER)
    goto L5089;
  goto L11811;

 L5089: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5090;
    }
  goto L11811;

 L5090: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && DEFAULT_ABI == ABI_AIX))
    {
      return 387;
    }
  goto L11811;

 L5033: ATTRIBUTE_UNUSED_LABEL
  tem = recog_31 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L11811;

 L7350: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L7351;
  goto L11812;

 L7351: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7352;
    }
  goto L11812;

 L7352: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7353;
    }
  goto L11812;

 L7353: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MULTIPLE))
    {
      return 542;
    }
  goto L11812;

 L7355: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == CLOBBER)
    goto L7356;
  goto L11813;

 L7356: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13129;
    case DImode:
      goto L13130;
    default:
      break;
    }
  goto L11813;

 L13129: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7357;
    }
  goto L11813;

 L7357: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L7358;
  goto L11813;

 L7358: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (call_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7359;
    }
  goto L11813;

 L7359: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L7360;
  goto L11813;

 L7360: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7361;
    }
  goto L11813;

 L7361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[4] = x2;
      goto L7362;
    }
  goto L11813;

 L7362: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT))
    {
      return 543;
    }
  goto L11813;

 L13130: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L7366;
    }
  goto L11813;

 L7366: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L7367;
  goto L11813;

 L7367: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (call_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7368;
    }
  goto L11813;

 L7368: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == SET)
    goto L7369;
  goto L11813;

 L7369: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7370;
    }
  goto L11813;

 L7370: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[4] = x2;
      goto L7371;
    }
  goto L11813;

 L7371: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 544;
    }
  goto L11813;

 L7377: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L7378;
  goto L11814;

 L7378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (cc_reg_operand (x2, CCmode))
    {
      operands[1] = x2;
      goto L7379;
    }
  goto L11814;

 L7379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 20)
    goto L7380;
  goto L11814;

 L7380: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (gpc_reg_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L7381;
    }
  goto L11814;

 L7381: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (immediate_operand (x3, VOIDmode))
    {
      operands[3] = x3;
      return 546;
    }
  goto L11814;

 L7389: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L7390;
  goto L11815;

 L7390: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7391;
    }
  goto L11815;

 L7391: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (memory_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7392;
    }
  goto L11815;

 L7392: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MULTIPLE))
    {
      return 548;
    }
  goto L11815;

 L7404: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == RETURN)
    goto L7405;
  goto L11817;

 L7405: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L7406;
  goto L11817;

 L7406: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13131;
    case DImode:
      goto L13132;
    default:
      break;
    }
  goto L11817;

 L13131: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7407;
    }
  goto L11817;

 L7407: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7408;
  goto L11817;

 L7408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (call_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7409;
    }
  goto L11817;

 L7409: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L7410;
  goto L11817;

 L7410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7411;
    }
  goto L11817;

 L7411: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (memory_operand (x2, DFmode))
    {
      operands[4] = x2;
      goto L7412;
    }
  goto L11817;

 L7412: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT))
    {
      return 551;
    }
  goto L11817;

 L13132: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L7417;
    }
  goto L11817;

 L7417: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7418;
  goto L11817;

 L7418: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (call_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7419;
    }
  goto L11817;

 L7419: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == SET)
    goto L7420;
  goto L11817;

 L7420: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7421;
    }
  goto L11817;

 L7421: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (memory_operand (x2, DFmode))
    {
      operands[4] = x2;
      goto L7422;
    }
  goto L11817;

 L7422: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 552;
    }
  goto L11817;

 L7499: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET)
    goto L7500;
  goto ret0;

 L7500: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 109)
    goto L7501;
  goto ret0;

 L7501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC_VOLATILE
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 30)
    goto L7502;
  goto ret0;

 L7502: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L7503;
    }
  goto ret0;

 L7503: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 109
      && (TARGET_ALTIVEC))
    {
      return 569;
    }
  goto ret0;
 ret0:
  return -1;
}

int recog PARAMS ((rtx, rtx, int *));
int
recog (x0, insn, pnum_clobbers)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
     int *pnum_clobbers ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  int tem ATTRIBUTE_UNUSED;
  recog_data.insn = NULL_RTX;

  switch (GET_CODE (x0))
    {
    case SET:
      goto L1;
    case PARALLEL:
      goto L11789;
    case UNSPEC_VOLATILE:
      goto L11808;
    case RETURN:
      goto L11809;
    case CONST_INT:
      goto L11810;
    case TRAP_IF:
      goto L7326;
    case PREFETCH:
      goto L7442;
    case UNSPEC:
      goto L11818;
    default:
     break;
   }
  goto ret0;

 L1: ATTRIBUTE_UNUSED_LABEL
  return recog_12 (x0, insn, pnum_clobbers);

 L11789: ATTRIBUTE_UNUSED_LABEL
  return recog_32 (x0, insn, pnum_clobbers);

 L11808: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x0, 0) == 1)
    goto L13133;
  goto ret0;

 L13133: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case 0LL:
      goto L5321;
    case 9LL:
      goto L7430;
    default:
      break;
    }
  goto ret0;

 L5321: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL)
    {
      return 403;
    }
  goto ret0;

 L7430: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L13135;
    case DImode:
      goto L13136;
    default:
      break;
    }
  goto ret0;

 L13135: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L7431;
    }
  goto ret0;

 L7431: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_32BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 553;
    }
  goto ret0;

 L13136: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L7440;
    }
  goto ret0;

 L7440: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 554;
    }
  goto ret0;

 L11809: ATTRIBUTE_UNUSED_LABEL
  if ((direct_return ()))
    {
      return 520;
    }
  goto ret0;

 L11810: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x0, 0) == 0LL)
    {
      return 525;
    }
  goto ret0;

 L7326: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 1LL)
    goto L7327;
  if (trap_comparison_operator (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L7330;
    }
  goto ret0;

 L7327: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL)
    {
      return 538;
    }
  goto ret0;

 L7330: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13137;
    case DImode:
      goto L13138;
    default:
      break;
    }
  goto ret0;

 L13137: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7331;
    }
  goto ret0;

 L7331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7332;
    }
  goto ret0;

 L7332: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL)
    {
      return 539;
    }
  goto ret0;

 L13138: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L7336;
    }
  goto ret0;

 L7336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (reg_or_short_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7337;
    }
  goto ret0;

 L7337: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL
      && (TARGET_POWERPC64))
    {
      return 540;
    }
  goto ret0;

 L7442: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 0);
  if (address_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L7443;
    }
  goto ret0;

 L7443: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const_int_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L7444;
    }
  goto ret0;

 L7444: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 2);
  if (const_int_operand (x1, SImode))
    {
      operands[2] = x1;
      goto L7445;
    }
  goto ret0;

 L7445: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC))
    {
      return 555;
    }
  goto ret0;

 L11818: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x0, 0))
    {
    case 1:
      goto L13139;
    case 3:
      goto L13141;
    default:
      break;
    }
  goto ret0;

 L13139: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case 188LL:
      goto L8729;
    case 189LL:
      goto L8731;
    default:
      break;
    }
  goto ret0;

 L8729: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL
      && (TARGET_ALTIVEC))
    {
      return 735;
    }
  goto ret0;

 L8731: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (immediate_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L8732;
    }
  goto ret0;

 L8732: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 736;
    }
  goto ret0;

 L13141: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x0, 1))
    {
    case 190LL:
      goto L8734;
    case 191LL:
      goto L8739;
    case 192LL:
      goto L8744;
    case 193LL:
      goto L8749;
    default:
      break;
    }
  goto ret0;

 L8734: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L8735;
    }
  goto ret0;

 L8735: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (register_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L8736;
    }
  goto ret0;

 L8736: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (immediate_operand (x1, QImode))
    {
      operands[2] = x1;
      goto L8737;
    }
  goto ret0;

 L8737: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 737;
    }
  goto ret0;

 L8739: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L8740;
    }
  goto ret0;

 L8740: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (register_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L8741;
    }
  goto ret0;

 L8741: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (immediate_operand (x1, QImode))
    {
      operands[2] = x1;
      goto L8742;
    }
  goto ret0;

 L8742: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 738;
    }
  goto ret0;

 L8744: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L8745;
    }
  goto ret0;

 L8745: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (register_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L8746;
    }
  goto ret0;

 L8746: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (immediate_operand (x1, QImode))
    {
      operands[2] = x1;
      goto L8747;
    }
  goto ret0;

 L8747: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 739;
    }
  goto ret0;

 L8749: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 0);
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L8750;
    }
  goto ret0;

 L8750: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (register_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L8751;
    }
  goto ret0;

 L8751: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (immediate_operand (x1, QImode))
    {
      operands[2] = x1;
      goto L8752;
    }
  goto ret0;

 L8752: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ALTIVEC))
    {
      return 740;
    }
  goto ret0;
 ret0:
  return -1;
}

static rtx split_1 PARAMS ((rtx, rtx));
static rtx
split_1 (x0, insn)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L8975;
    case SIGN_EXTEND:
      goto L8996;
    case PLUS:
      goto L10248;
    case NOT:
      goto L10278;
    case MINUS:
      goto L10299;
    case NEG:
      goto L10340;
    case DIV:
      goto L10361;
    case ROTATE:
      goto L10385;
    case AND:
      goto L10409;
    case ASHIFT:
      goto L10529;
    case LSHIFTRT:
      goto L10613;
    case ASHIFTRT:
      goto L10637;
    default:
     break;
   }
 L13193: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x3, DImode))
    {
      operands[4] = x3;
      goto L10728;
    }
  goto ret0;

 L8975: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L13195;
    case HImode:
      goto L13196;
    case SImode:
      goto L13197;
    default:
      break;
    }
  goto ret0;

 L13195: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L8976;
    }
 L13198: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L10440;
  goto ret0;

 L8976: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L8977;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13198;

 L8977: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8978;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13198;

 L8978: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L8979;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13198;

 L8979: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_761 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13198;

 L10440: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L10441;
  goto ret0;

 L10441: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L10442;
    }
  goto ret0;

 L10442: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L10443;
    }
  goto ret0;

 L10443: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10444;
  goto ret0;

 L10444: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10445;
  goto ret0;

 L10445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10446;
    }
  goto ret0;

 L10446: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_944 (operands);
    }
  goto ret0;

 L13196: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L9018;
    }
 L13199: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L10470;
  goto ret0;

 L9018: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9019;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13199;

 L9019: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9020;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13199;

 L9020: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9021;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13199;

 L9021: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_766 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13199;

 L10470: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L10471;
  goto ret0;

 L10471: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L10472;
    }
  goto ret0;

 L10472: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L10473;
    }
  goto ret0;

 L10473: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10474;
  goto ret0;

 L10474: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10475;
  goto ret0;

 L10475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10476;
    }
  goto ret0;

 L10476: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_946 (operands);
    }
  goto ret0;

 L13197: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9060;
    }
 L13200: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L10500;
  goto ret0;

 L9060: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9061;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13200;

 L9061: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9062;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13200;

 L9062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9063;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13200;

 L9063: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_772 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13200;

 L10500: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ROTATE)
    goto L10501;
  goto ret0;

 L10501: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L10502;
    }
  goto ret0;

 L10502: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L10503;
    }
  goto ret0;

 L10503: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10504;
  goto ret0;

 L10504: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10505;
  goto ret0;

 L10505: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10506;
    }
  goto ret0;

 L10506: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_948 (operands);
    }
  goto ret0;

 L8996: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L13201;
    case HImode:
      goto L13202;
    case SImode:
      goto L13203;
    default:
      break;
    }
  goto ret0;

 L13201: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L8997;
    }
  goto ret0;

 L8997: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L8998;
  goto ret0;

 L8998: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L8999;
  goto ret0;

 L8999: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9000;
    }
  goto ret0;

 L9000: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_763 (operands);
    }
  goto ret0;

 L13202: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L9039;
    }
  goto ret0;

 L9039: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9040;
  goto ret0;

 L9040: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9041;
  goto ret0;

 L9041: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9042;
    }
  goto ret0;

 L9042: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_769 (operands);
    }
  goto ret0;

 L13203: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9081;
    }
  goto ret0;

 L9081: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9082;
  goto ret0;

 L9082: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9083;
  goto ret0;

 L9083: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9084;
    }
  goto ret0;

 L9084: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_775 (operands);
    }
  goto ret0;

 L10248: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L13205;
  goto ret0;

 L13205: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case LSHIFTRT:
      goto L11070;
    case GT:
      goto L11541;
    case GTU:
      goto L11657;
    case SUBREG:
    case REG:
      goto L13204;
    default:
      goto ret0;
   }
 L13204: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10249;
    }
  goto ret0;

 L11070: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == NEG)
    goto L11071;
  goto ret0;

 L11071: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == ABS)
    goto L11072;
  goto ret0;

 L11072: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (gpc_reg_operand (x7, DImode))
    {
      operands[1] = x7;
      goto L11073;
    }
  goto ret0;

 L11073: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 63LL)
    goto L11074;
  goto ret0;

 L11074: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L11075;
    }
  goto ret0;

 L11075: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11076;
  goto ret0;

 L11076: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11077;
  goto ret0;

 L11077: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L11078;
    }
  goto ret0;

 L11078: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1080 (operands);
    }
  goto ret0;

 L11541: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L11542;
    }
  goto ret0;

 L11542: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L11543;
  goto ret0;

 L11543: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L11544;
    }
  goto ret0;

 L11544: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11545;
  goto ret0;

 L11545: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11546;
  goto ret0;

 L11546: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L11547;
    }
  goto ret0;

 L11547: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1111 (operands);
    }
  goto ret0;

 L11657: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L11658;
    }
  goto ret0;

 L11658: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L11659;
    }
  goto ret0;

 L11659: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L11660;
    }
  goto ret0;

 L11660: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11661;
  goto ret0;

 L11661: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11662;
  goto ret0;

 L11662: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L11663;
    }
  goto ret0;

 L11663: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1119 (operands);
    }
  goto ret0;

 L10249: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L10250;
    }
  goto ret0;

 L10250: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10251;
  goto ret0;

 L10251: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10252;
  goto ret0;

 L10252: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10253;
    }
  goto ret0;

 L10253: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_923 (operands);
    }
  goto ret0;

 L10278: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10279;
    }
  goto ret0;

 L10279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10280;
  goto ret0;

 L10280: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10281;
  goto ret0;

 L10281: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L10282;
    }
  goto ret0;

 L10282: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_926 (operands);
    }
  goto ret0;

 L10299: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10300;
    }
  goto ret0;

 L10300: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L10301;
    }
  goto ret0;

 L10301: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10302;
  goto ret0;

 L10302: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10303;
  goto ret0;

 L10303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10304;
    }
  goto ret0;

 L10304: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_928 (operands);
    }
  goto ret0;

 L10340: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10341;
    }
  goto ret0;

 L10341: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10342;
  goto ret0;

 L10342: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10343;
  goto ret0;

 L10343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L10344;
    }
  goto ret0;

 L10344: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_934 (operands);
    }
  goto ret0;

 L10361: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10362;
    }
  goto ret0;

 L10362: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (exact_log2_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L10363;
    }
  goto ret0;

 L10363: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10364;
  goto ret0;

 L10364: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10365;
  goto ret0;

 L10365: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10366;
    }
  goto ret0;

 L10366: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_938 (operands);
    }
  goto ret0;

 L10385: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10386;
    }
  goto ret0;

 L10386: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L10387;
    }
  goto ret0;

 L10387: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10388;
  goto ret0;

 L10388: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10389;
  goto ret0;

 L10389: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10390;
    }
  goto ret0;

 L10390: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_940 (operands);
    }
  goto ret0;

 L10409: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L13208;
  goto L13193;

 L13208: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L10410;
    case ASHIFT:
      goto L10554;
    default:
     break;
   }
  goto L13193;

 L10410: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L10411;
    }
  goto L13193;

 L10411: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L10412;
    }
  goto L13193;

 L10412: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask64_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L10413;
    }
  goto L13193;

 L10413: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10414;
  x3 = XEXP (x2, 0);
  goto L13193;

 L10414: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10415;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13193;

 L10415: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L10416;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13193;

 L10416: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_942 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13193;

 L10554: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L10555;
    }
  goto L13193;

 L10555: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L10556;
    }
  goto L13193;

 L10556: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L13210;
  goto L13193;

 L13210: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L10557;
    }
 L13211: ATTRIBUTE_UNUSED_LABEL
  if (mask64_operand (x4, DImode))
    {
      operands[3] = x4;
      goto L10587;
    }
  goto L13193;

 L10557: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10558;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L13211;

 L10558: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10559;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L13211;

 L10559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L10560;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L13211;

 L10560: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed
   && includes_rldic_lshift_p (operands[2], operands[3])))
    {
      return gen_split_953 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L13211;

 L10587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10588;
  x3 = XEXP (x2, 0);
  goto L13193;

 L10588: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10589;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13193;

 L10589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L10590;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13193;

 L10590: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed
   && includes_rldicr_lshift_p (operands[2], operands[3])))
    {
      return gen_split_955 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13193;

 L10529: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10530;
    }
  goto ret0;

 L10530: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10531;
    }
  goto ret0;

 L10531: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10532;
  goto ret0;

 L10532: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10533;
  goto ret0;

 L10533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10534;
    }
  goto ret0;

 L10534: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_951 (operands);
    }
  goto ret0;

 L10613: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10614;
    }
  goto ret0;

 L10614: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10615;
    }
  goto ret0;

 L10615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10616;
  goto ret0;

 L10616: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10617;
  goto ret0;

 L10617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10618;
    }
  goto ret0;

 L10618: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_958 (operands);
    }
  goto ret0;

 L10637: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10638;
    }
  goto ret0;

 L10638: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10639;
    }
  goto ret0;

 L10639: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10640;
  goto ret0;

 L10640: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10641;
  goto ret0;

 L10641: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10642;
    }
  goto ret0;

 L10642: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_961 (operands);
    }
  goto ret0;

 L10728: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L13213;
  goto ret0;

 L13213: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L10757;
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10729;
    }
  goto ret0;

 L10757: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L10758;
    }
  goto ret0;

 L10758: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode)
    goto L13215;
  goto ret0;

 L13215: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L10783;
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L10759;
    }
  goto ret0;

 L10783: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L10784;
    }
  goto ret0;

 L10784: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10785;
  goto ret0;

 L10785: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10786;
  goto ret0;

 L10786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10787;
    }
  goto ret0;

 L10787: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_975 (operands);
    }
  goto ret0;

 L10759: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10760;
  goto ret0;

 L10760: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10761;
  goto ret0;

 L10761: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10762;
    }
  goto ret0;

 L10762: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_973 (operands);
    }
  goto ret0;

 L10729: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L10730;
    }
  goto ret0;

 L10730: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10731;
  goto ret0;

 L10731: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10732;
  goto ret0;

 L10732: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L10733;
    }
  goto ret0;

 L10733: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_970 (operands);
    }
  goto ret0;
 ret0:
  return 0;
}

static rtx split_2 PARAMS ((rtx, rtx));
static rtx
split_2 (x0, insn)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L9101;
    case SIGN_EXTEND:
      goto L9122;
    case PLUS:
      goto L9227;
    case NOT:
      goto L9256;
    case MINUS:
      goto L9277;
    case IF_THEN_ELSE:
      goto L9319;
    case NEG:
      goto L9375;
    case MULT:
      goto L9409;
    case DIV:
      goto L9449;
    case ZERO_EXTRACT:
      goto L9730;
    case ROTATE:
      goto L9757;
    case AND:
      goto L9781;
    case ASHIFT:
      goto L9884;
    case LSHIFTRT:
      goto L9967;
    case ASHIFTRT:
      goto L10110;
    default:
     break;
   }
 L13176: ATTRIBUTE_UNUSED_LABEL
  if (boolean_operator (x3, SImode))
    {
      operands[4] = x3;
      goto L9561;
    }
  if (scc_comparison_operator (x3, SImode))
    {
      operands[1] = x3;
      goto L10949;
    }
  goto ret0;

 L9101: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L13216;
    case HImode:
      goto L13217;
    default:
      break;
    }
  goto ret0;

 L13216: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L9102;
    }
 L13218: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L9812;
  goto ret0;

 L9102: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9103;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13218;

 L9103: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9104;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13218;

 L9104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L9105;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13218;

 L9105: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_778 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13218;

 L9812: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L13220;
  goto ret0;

 L13220: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ROTATE:
      goto L9813;
    case LSHIFTRT:
      goto L10039;
    default:
     break;
   }
  goto ret0;

 L9813: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L9814;
    }
  goto ret0;

 L9814: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L9815;
    }
  goto ret0;

 L9815: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9816;
  goto ret0;

 L9816: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9817;
  goto ret0;

 L9817: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9818;
    }
  goto ret0;

 L9818: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_863 (operands);
    }
  goto ret0;

 L10039: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L10040;
    }
  goto ret0;

 L10040: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L10041;
    }
  goto ret0;

 L10041: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10042;
  goto ret0;

 L10042: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10043;
  goto ret0;

 L10043: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L10044;
    }
  goto ret0;

 L10044: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], GEN_INT (255)) && reload_completed))
    {
      return gen_split_881 (operands);
    }
  goto ret0;

 L13217: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L9186;
    }
 L13219: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == SUBREG
      && XINT (x4, 1) == 0)
    goto L9842;
  goto ret0;

 L9186: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9187;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13219;

 L9187: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9188;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13219;

 L9188: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L9189;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13219;

 L9189: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_794 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13219;

 L9842: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L13222;
  goto ret0;

 L13222: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ROTATE:
      goto L9843;
    case LSHIFTRT:
      goto L10069;
    default:
     break;
   }
  goto ret0;

 L9843: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L9844;
    }
  goto ret0;

 L9844: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_cint_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L9845;
    }
  goto ret0;

 L9845: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9846;
  goto ret0;

 L9846: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9847;
  goto ret0;

 L9847: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9848;
    }
  goto ret0;

 L9848: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_865 (operands);
    }
  goto ret0;

 L10069: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L10070;
    }
  goto ret0;

 L10070: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (const_int_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L10071;
    }
  goto ret0;

 L10071: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10072;
  goto ret0;

 L10072: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10073;
  goto ret0;

 L10073: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L10074;
    }
  goto ret0;

 L10074: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], GEN_INT (65535)) && reload_completed))
    {
      return gen_split_883 (operands);
    }
  goto ret0;

 L9122: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L13224;
    case HImode:
      goto L13225;
    default:
      break;
    }
  goto ret0;

 L13224: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L9123;
    }
  goto ret0;

 L9123: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9124;
  goto ret0;

 L9124: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9125;
  goto ret0;

 L9125: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L9126;
    }
  goto ret0;

 L9126: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWERPC && reload_completed))
    {
      return gen_split_781 (operands);
    }
  goto ret0;

 L13225: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L9207;
    }
  goto ret0;

 L9207: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9208;
  goto ret0;

 L9208: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9209;
  goto ret0;

 L9209: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L9210;
    }
  goto ret0;

 L9210: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_797 (operands);
    }
  goto ret0;

 L9227: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L13227;
  goto ret0;

 L13227: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case EQ:
      goto L11023;
    case LE:
      goto L11149;
    case LEU:
      goto L11205;
    case LT:
      goto L11281;
    case LTU:
      goto L11324;
    case GE:
      goto L11370;
    case GEU:
      goto L11426;
    case GT:
      goto L11528;
    case GTU:
      goto L11644;
    case SUBREG:
    case REG:
      goto L13226;
    default:
      goto ret0;
   }
 L13226: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9228;
    }
  goto ret0;

 L11023: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11024;
    }
  goto ret0;

 L11024: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11025;
    }
  goto ret0;

 L11025: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11026;
    }
  goto ret0;

 L11026: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11027;
  goto ret0;

 L11027: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11028;
  goto ret0;

 L11028: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11029;
    }
  goto ret0;

 L11029: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1077 (operands);
    }
  goto ret0;

 L11149: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11150;
    }
  goto ret0;

 L11150: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11151;
    }
  goto ret0;

 L11151: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11152;
    }
  goto ret0;

 L11152: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11153;
  goto ret0;

 L11153: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11154;
  goto ret0;

 L11154: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11155;
    }
  goto ret0;

 L11155: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER && reload_completed))
    {
      return gen_split_1084 (operands);
    }
  goto ret0;

 L11205: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11206;
    }
  goto ret0;

 L11206: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11207;
    }
  goto ret0;

 L11207: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11208;
    }
  goto ret0;

 L11208: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11209;
  goto ret0;

 L11209: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11210;
  goto ret0;

 L11210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11211;
    }
  goto ret0;

 L11211: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1088 (operands);
    }
  goto ret0;

 L11281: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11282;
    }
  goto ret0;

 L11282: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11283;
    }
  goto ret0;

 L11283: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11284;
    }
  goto ret0;

 L11284: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11285;
  goto ret0;

 L11285: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11286;
  goto ret0;

 L11286: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11287;
    }
  goto ret0;

 L11287: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER && reload_completed))
    {
      return gen_split_1093 (operands);
    }
  goto ret0;

 L11324: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11325;
    }
  goto ret0;

 L11325: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11326;
    }
  goto ret0;

 L11326: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11327;
    }
  goto ret0;

 L11327: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11328;
  goto ret0;

 L11328: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11329;
  goto ret0;

 L11329: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11330;
    }
  goto ret0;

 L11330: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1096 (operands);
    }
  goto ret0;

 L11370: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11371;
    }
  goto ret0;

 L11371: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11372;
    }
  goto ret0;

 L11372: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11373;
    }
  goto ret0;

 L11373: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11374;
  goto ret0;

 L11374: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11375;
  goto ret0;

 L11375: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11376;
    }
  goto ret0;

 L11376: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER && reload_completed))
    {
      return gen_split_1099 (operands);
    }
  goto ret0;

 L11426: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11427;
    }
  goto ret0;

 L11427: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_neg_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11428;
    }
  goto ret0;

 L11428: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11429;
    }
  goto ret0;

 L11429: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11430;
  goto ret0;

 L11430: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11431;
  goto ret0;

 L11431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11432;
    }
  goto ret0;

 L11432: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1103 (operands);
    }
  goto ret0;

 L11528: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11529;
    }
  goto ret0;

 L11529: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L11530;
 L11589: ATTRIBUTE_UNUSED_LABEL
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11590;
    }
  goto ret0;

 L11530: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L11531;
    }
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L11589;

 L11531: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11532;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L11589;

 L11532: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11533;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L11589;

 L11533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L11534;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L11589;

 L11534: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1110 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 1);
  goto L11589;

 L11590: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11591;
    }
  goto ret0;

 L11591: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11592;
  goto ret0;

 L11592: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11593;
  goto ret0;

 L11593: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11594;
    }
  goto ret0;

 L11594: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER && reload_completed))
    {
      return gen_split_1114 (operands);
    }
  goto ret0;

 L11644: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L11645;
    }
  goto ret0;

 L11645: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L11646;
    }
  goto ret0;

 L11646: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11647;
    }
  goto ret0;

 L11647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11648;
  goto ret0;

 L11648: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11649;
  goto ret0;

 L11649: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11650;
    }
  goto ret0;

 L11650: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1118 (operands);
    }
  goto ret0;

 L9228: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_short_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9229;
    }
  goto ret0;

 L9229: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9230;
  goto ret0;

 L9230: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9231;
  goto ret0;

 L9231: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9232;
    }
  goto ret0;

 L9232: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_800 (operands);
    }
  goto ret0;

 L9256: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9257;
    }
  goto ret0;

 L9257: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9258;
  goto ret0;

 L9258: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9259;
  goto ret0;

 L9259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L9260;
    }
  goto ret0;

 L9260: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_803 (operands);
    }
  goto ret0;

 L9277: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9278;
    }
  goto ret0;

 L9278: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9279;
    }
  goto ret0;

 L9279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9280;
  goto ret0;

 L9280: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9281;
  goto ret0;

 L9281: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9282;
    }
  goto ret0;

 L9282: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_805 (operands);
    }
  goto ret0;

 L9319: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == GT)
    goto L9320;
  goto ret0;

 L9320: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L9321;
    }
  goto ret0;

 L9321: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_short_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L9322;
    }
  goto ret0;

 L9322: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9323;
  goto ret0;

 L9323: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == MINUS)
    goto L9324;
  goto ret0;

 L9324: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L9325;
  goto ret0;

 L9325: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[1]))
    goto L9326;
  goto ret0;

 L9326: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9327;
  goto ret0;

 L9327: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9328;
  goto ret0;

 L9328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9329;
    }
  goto ret0;

 L9329: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_POWER && reload_completed))
    {
      return gen_split_814 (operands);
    }
  goto ret0;

 L9375: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9376;
    }
  goto ret0;

 L9376: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9377;
  goto ret0;

 L9377: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9378;
  goto ret0;

 L9378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L9379;
    }
  goto ret0;

 L9379: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_819 (operands);
    }
  goto ret0;

 L9409: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9410;
    }
  goto ret0;

 L9410: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9411;
    }
  goto ret0;

 L9411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9412;
  goto ret0;

 L9412: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9413;
  goto ret0;

 L9413: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9414;
    }
  goto ret0;

 L9414: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && reload_completed))
    {
      return gen_split_823 (operands);
    }
  goto ret0;

 L9449: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9450;
    }
  goto ret0;

 L9450: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (exact_log2_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9451;
    }
  goto ret0;

 L9451: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9452;
  goto ret0;

 L9452: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9453;
  goto ret0;

 L9453: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9454;
    }
  goto ret0;

 L9454: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_830 (operands);
    }
  goto ret0;

 L9730: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9731;
    }
  goto ret0;

 L9731: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9732;
    }
  goto ret0;

 L9732: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L9733;
    }
  goto ret0;

 L9733: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9734;
  goto ret0;

 L9734: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9735;
  goto ret0;

 L9735: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L9736;
    }
  goto ret0;

 L9736: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_857 (operands);
    }
  goto ret0;

 L9757: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9758;
    }
  goto ret0;

 L9758: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9759;
    }
  goto ret0;

 L9759: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9760;
  goto ret0;

 L9760: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9761;
  goto ret0;

 L9761: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9762;
    }
  goto ret0;

 L9762: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_859 (operands);
    }
  goto ret0;

 L9781: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L13236;
  goto L13176;

 L13236: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ROTATE:
      goto L9782;
    case ASHIFT:
      goto L9925;
    case LSHIFTRT:
      goto L10008;
    case NEG:
      goto L11235;
    default:
     break;
   }
  goto L13176;

 L9782: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L9783;
    }
  goto L13176;

 L9783: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (reg_or_cint_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L9784;
    }
  goto L13176;

 L9784: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L9785;
    }
  goto L13176;

 L9785: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9786;
  x3 = XEXP (x2, 0);
  goto L13176;

 L9786: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9787;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L9787: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L9788;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L9788: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed))
    {
      return gen_split_861 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L9925: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L9926;
    }
  goto L13176;

 L9926: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L9927;
    }
  goto L13176;

 L9927: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L9928;
    }
  goto L13176;

 L9928: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9929;
  x3 = XEXP (x2, 0);
  goto L13176;

 L9929: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9930;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L9930: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L9931;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L9931: ATTRIBUTE_UNUSED_LABEL
  if ((includes_lshift_p (operands[2], operands[3]) && reload_completed))
    {
      return gen_split_872 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L10008: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L10009;
    }
  goto L13176;

 L10009: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const_int_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L10010;
    }
  goto L13176;

 L10010: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (mask_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L10011;
    }
  goto L13176;

 L10011: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10012;
  x3 = XEXP (x2, 0);
  goto L13176;

 L10012: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10013;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L10013: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L10014;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L10014: ATTRIBUTE_UNUSED_LABEL
  if ((includes_rshift_p (operands[2], operands[3]) && reload_completed))
    {
      return gen_split_879 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L11235: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode)
    goto L13240;
  goto L13176;

 L13240: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case LEU:
      goto L11236;
    case GEU:
      goto L11457;
    default:
     break;
   }
  goto L13176;

 L11236: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L11237;
    }
  goto L13176;

 L11237: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_short_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L11238;
    }
  goto L13176;

 L11238: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11239;
    }
  goto L13176;

 L11239: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11240;
  x3 = XEXP (x2, 0);
  goto L13176;

 L11240: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11241;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L11241: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11242;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L11242: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1090 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L11457: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (gpc_reg_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L11458;
    }
  goto L13176;

 L11458: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (reg_or_neg_short_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L11459;
    }
  goto L13176;

 L11459: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L11460;
    }
  goto L13176;

 L11460: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L11461;
  x3 = XEXP (x2, 0);
  goto L13176;

 L11461: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L11462;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L11462: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L11463;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L11463: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1105 (operands);
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13176;

 L9884: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L13242;
  goto ret0;

 L13242: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9885;
    }
  if (scc_comparison_operator (x4, SImode))
    {
      operands[1] = x4;
      goto L10963;
    }
  goto ret0;

 L9885: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9886;
    }
  goto ret0;

 L9886: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9887;
  goto ret0;

 L9887: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9888;
  goto ret0;

 L9888: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9889;
    }
  goto ret0;

 L9889: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_869 (operands);
    }
  goto ret0;

 L10963: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (cc_reg_operand (x5, VOIDmode))
    {
      operands[2] = x5;
      goto L10964;
    }
  goto ret0;

 L10964: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L10965;
  goto ret0;

 L10965: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L10966;
    }
  goto ret0;

 L10966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10967;
  goto ret0;

 L10967: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L10968;
  goto ret0;

 L10968: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L10969;
    }
  goto ret0;

 L10969: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L10970;
  goto ret0;

 L10970: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      operands[1] = x3;
      goto L10971;
    }
  goto ret0;

 L10971: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L10972;
  goto ret0;

 L10972: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10973;
  goto ret0;

 L10973: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (reload_completed))
    {
      return gen_split_1071 (operands);
    }
  goto ret0;

 L9967: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9968;
    }
  goto ret0;

 L9968: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9969;
    }
  goto ret0;

 L9969: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9970;
  goto ret0;

 L9970: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9971;
  goto ret0;

 L9971: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9972;
    }
  goto ret0;

 L9972: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && ! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_876 (operands);
    }
  goto ret0;

 L10110: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L10111;
    }
  goto ret0;

 L10111: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (reg_or_cint_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10112;
    }
  goto ret0;

 L10112: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10113;
  goto ret0;

 L10113: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L10114;
  goto ret0;

 L10114: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L10115;
    }
  goto ret0;

 L10115: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWER && reload_completed))
    {
      return gen_split_887 (operands);
    }
  goto ret0;

 L9561: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L13245;
  goto ret0;

 L13245: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L9589;
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9562;
    }
  goto ret0;

 L9589: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L9590;
    }
  goto ret0;

 L9590: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode)
    goto L13247;
  goto ret0;

 L13247: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == NOT)
    goto L9615;
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9591;
    }
  goto ret0;

 L9615: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (gpc_reg_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L9616;
    }
  goto ret0;

 L9616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9617;
  goto ret0;

 L9617: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9618;
  goto ret0;

 L9618: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9619;
    }
  goto ret0;

 L9619: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_849 (operands);
    }
  goto ret0;

 L9591: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9592;
  goto ret0;

 L9592: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9593;
  goto ret0;

 L9593: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9594;
    }
  goto ret0;

 L9594: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_847 (operands);
    }
  goto ret0;

 L9562: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (gpc_reg_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9563;
    }
  goto ret0;

 L9563: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9564;
  goto ret0;

 L9564: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L9565;
  goto ret0;

 L9565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L9566;
    }
  goto ret0;

 L9566: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_844 (operands);
    }
  goto ret0;

 L10949: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (cc_reg_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L10950;
    }
  goto ret0;

 L10950: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10951;
  goto ret0;

 L10951: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10952;
  goto ret0;

 L10952: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L10953;
  goto ret0;

 L10953: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L10954;
    }
  goto ret0;

 L10954: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    {
      operands[1] = x2;
      goto L10955;
    }
  goto ret0;

 L10955: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L10956;
  goto ret0;

 L10956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (! TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_1070 (operands);
    }
  goto ret0;
 ret0:
  return 0;
}

static rtx split_3 PARAMS ((rtx, rtx));
static rtx
split_3 (x0, insn)
     rtx x0 ATTRIBUTE_UNUSED;
     rtx insn ATTRIBUTE_UNUSED;
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x1 ATTRIBUTE_UNUSED;
  rtx x2 ATTRIBUTE_UNUSED;
  rtx x3 ATTRIBUTE_UNUSED;
  rtx x4 ATTRIBUTE_UNUSED;
  rtx x5 ATTRIBUTE_UNUSED;
  rtx x6 ATTRIBUTE_UNUSED;
  rtx x7 ATTRIBUTE_UNUSED;
  rtx tem ATTRIBUTE_UNUSED;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L13248;
    case SImode:
      goto L13250;
    case HImode:
      goto L13252;
    default:
      break;
    }
  goto ret0;

 L13248: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L8985;
    case SIGN_EXTEND:
      goto L9006;
    case NOT:
      goto L10288;
    case NEG:
      goto L10350;
    case GT:
      goto L11501;
    case SUBREG:
    case REG:
      goto L13259;
    default:
      goto ret0;
   }
 L13259: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L10909;
    }
  goto ret0;

 L8985: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L13262;
    case HImode:
      goto L13263;
    case SImode:
      goto L13264;
    default:
      break;
    }
  goto ret0;

 L13262: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L8986;
    }
  goto ret0;

 L8986: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L8987;
  goto ret0;

 L8987: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8988;
  goto ret0;

 L8988: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L8989;
    }
  goto ret0;

 L8989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L8990;
  goto ret0;

 L8990: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_762 (operands);
    }
  goto ret0;

 L13263: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L9028;
    }
  goto ret0;

 L9028: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9029;
  goto ret0;

 L9029: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L9030;
  goto ret0;

 L9030: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L9031;
    }
  goto ret0;

 L9031: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L9032;
  goto ret0;

 L9032: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_767 (operands);
    }
  goto ret0;

 L13264: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9070;
    }
  goto ret0;

 L9070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9071;
  goto ret0;

 L9071: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L9072;
  goto ret0;

 L9072: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L9073;
    }
  goto ret0;

 L9073: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L9074;
  goto ret0;

 L9074: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_773 (operands);
    }
  goto ret0;

 L9006: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case QImode:
      goto L13265;
    case HImode:
      goto L13266;
    case SImode:
      goto L13267;
    default:
      break;
    }
  goto ret0;

 L13265: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L9007;
    }
  goto ret0;

 L9007: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9008;
  goto ret0;

 L9008: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L9009;
  goto ret0;

 L9009: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L9010;
    }
  goto ret0;

 L9010: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L9011;
  goto ret0;

 L9011: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_764 (operands);
    }
  goto ret0;

 L13266: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L9049;
    }
  goto ret0;

 L9049: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9050;
  goto ret0;

 L9050: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L9051;
  goto ret0;

 L9051: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L9052;
    }
  goto ret0;

 L9052: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L9053;
  goto ret0;

 L9053: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_770 (operands);
    }
  goto ret0;

 L13267: ATTRIBUTE_UNUSED_LABEL
  if (gpc_reg_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L9091;
    }
  goto ret0;

 L9091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9092;
  goto ret0;

 L9092: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L9093;
  goto ret0;

 L9093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L9094;
    }
  goto ret0;

 L9094: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L9095;
  goto ret0;

 L9095: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_776 (operands);
    }
  goto ret0;

 L10288: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10289;
    }
  goto ret0;

 L10289: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10290;
  goto ret0;

 L10290: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L10291;
  goto ret0;

 L10291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L10292;
    }
  goto ret0;

 L10292: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NOT)
    goto L10293;
  goto ret0;

 L10293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_POWERPC64 && reload_completed))
    {
      return gen_split_927 (operands);
    }
  goto ret0;

 L10350: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (gpc_reg_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L10351;
    }
  goto ret0;

 L10351: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10352;
  goto ret0;

 L10352: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L10353;
  goto ret0;

 L10353: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (gpc_reg_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L10354;
    }
  goto ret0;

 L10354: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NEG)
    goto L10355;
  goto ret0;

 L10355: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
    {
    }
