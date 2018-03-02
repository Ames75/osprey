/*
 * Copyright 2003, 2004 PathScale, Inc.  All Rights Reserved.
 */

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


extern rtx gen_peephole2_1054 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1055 PARAMS ((rtx, rtx *));
extern rtx gen_split_1056 PARAMS ((rtx *));
extern rtx gen_split_1057 PARAMS ((rtx *));
extern rtx gen_split_1058 PARAMS ((rtx *));
extern rtx gen_peephole2_1059 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1060 PARAMS ((rtx, rtx *));
extern rtx gen_split_1061 PARAMS ((rtx *));
extern rtx gen_split_1063 PARAMS ((rtx *));
extern rtx gen_split_1064 PARAMS ((rtx *));
extern rtx gen_split_1065 PARAMS ((rtx *));
extern rtx gen_split_1067 PARAMS ((rtx *));
extern rtx gen_split_1068 PARAMS ((rtx *));
extern rtx gen_split_1069 PARAMS ((rtx *));
extern rtx gen_split_1070 PARAMS ((rtx *));
extern rtx gen_split_1073 PARAMS ((rtx *));
extern rtx gen_split_1074 PARAMS ((rtx *));
extern rtx gen_split_1075 PARAMS ((rtx *));
extern rtx gen_split_1076 PARAMS ((rtx *));
extern rtx gen_split_1077 PARAMS ((rtx *));
extern rtx gen_split_1078 PARAMS ((rtx *));
extern rtx gen_split_1080 PARAMS ((rtx *));
extern rtx gen_split_1082 PARAMS ((rtx *));
extern rtx gen_split_1083 PARAMS ((rtx *));
extern rtx gen_split_1084 PARAMS ((rtx *));
extern rtx gen_split_1086 PARAMS ((rtx *));
extern rtx gen_split_1087 PARAMS ((rtx *));
extern rtx gen_split_1088 PARAMS ((rtx *));
extern rtx gen_split_1090 PARAMS ((rtx *));
extern rtx gen_split_1091 PARAMS ((rtx *));
extern rtx gen_split_1092 PARAMS ((rtx *));
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
extern rtx gen_split_1111 PARAMS ((rtx *));
extern rtx gen_split_1112 PARAMS ((rtx *));
extern rtx gen_split_1113 PARAMS ((rtx *));
extern rtx gen_split_1115 PARAMS ((rtx *));
extern rtx gen_split_1116 PARAMS ((rtx *));
extern rtx gen_split_1118 PARAMS ((rtx *));
extern rtx gen_split_1119 PARAMS ((rtx *));
extern rtx gen_split_1121 PARAMS ((rtx *));
extern rtx gen_split_1122 PARAMS ((rtx *));
extern rtx gen_split_1124 PARAMS ((rtx *));
extern rtx gen_split_1125 PARAMS ((rtx *));
extern rtx gen_split_1130 PARAMS ((rtx *));
extern rtx gen_split_1131 PARAMS ((rtx *));
extern rtx gen_split_1132 PARAMS ((rtx *));
extern rtx gen_split_1137 PARAMS ((rtx *));
extern rtx gen_split_1138 PARAMS ((rtx *));
extern rtx gen_split_1139 PARAMS ((rtx *));
extern rtx gen_split_1144 PARAMS ((rtx *));
extern rtx gen_split_1145 PARAMS ((rtx *));
extern rtx gen_split_1146 PARAMS ((rtx *));
extern rtx gen_split_1151 PARAMS ((rtx *));
extern rtx gen_split_1153 PARAMS ((rtx *));
extern rtx gen_split_1155 PARAMS ((rtx *));
extern rtx gen_split_1156 PARAMS ((rtx *));
extern rtx gen_split_1157 PARAMS ((rtx *));
extern rtx gen_split_1158 PARAMS ((rtx *));
extern rtx gen_split_1159 PARAMS ((rtx *));
extern rtx gen_split_1160 PARAMS ((rtx *));
extern rtx gen_split_1161 PARAMS ((rtx *));
extern rtx gen_split_1162 PARAMS ((rtx *));
extern rtx gen_split_1163 PARAMS ((rtx *));
extern rtx gen_split_1171 PARAMS ((rtx *));
extern rtx gen_split_1202 PARAMS ((rtx *));
extern rtx gen_split_1204 PARAMS ((rtx *));
extern rtx gen_split_1205 PARAMS ((rtx *));
extern rtx gen_split_1206 PARAMS ((rtx *));
extern rtx gen_split_1211 PARAMS ((rtx *));
extern rtx gen_split_1212 PARAMS ((rtx *));
extern rtx gen_split_1213 PARAMS ((rtx *));
extern rtx gen_split_1216 PARAMS ((rtx *));
extern rtx gen_split_1217 PARAMS ((rtx *));
extern rtx gen_split_1218 PARAMS ((rtx *));
extern rtx gen_split_1221 PARAMS ((rtx *));
extern rtx gen_split_1222 PARAMS ((rtx *));
extern rtx gen_split_1227 PARAMS ((rtx *));
extern rtx gen_split_1228 PARAMS ((rtx *));
extern rtx gen_split_1234 PARAMS ((rtx *));
extern rtx gen_split_1235 PARAMS ((rtx *));
extern rtx gen_split_1237 PARAMS ((rtx *));
extern rtx gen_split_1242 PARAMS ((rtx *));
extern rtx gen_split_1243 PARAMS ((rtx *));
extern rtx gen_split_1244 PARAMS ((rtx *));
extern rtx gen_split_1245 PARAMS ((rtx *));
extern rtx gen_split_1246 PARAMS ((rtx *));
extern rtx gen_split_1247 PARAMS ((rtx *));
extern rtx gen_split_1249 PARAMS ((rtx *));
extern rtx gen_split_1250 PARAMS ((rtx *));
extern rtx gen_split_1251 PARAMS ((rtx *));
extern rtx gen_split_1252 PARAMS ((rtx *));
extern rtx gen_split_1253 PARAMS ((rtx *));
extern rtx gen_split_1254 PARAMS ((rtx *));
extern rtx gen_split_1257 PARAMS ((rtx *));
extern rtx gen_split_1258 PARAMS ((rtx *));
extern rtx gen_split_1259 PARAMS ((rtx *));
extern rtx gen_split_1260 PARAMS ((rtx *));
extern rtx gen_split_1262 PARAMS ((rtx *));
extern rtx gen_split_1263 PARAMS ((rtx *));
extern rtx gen_split_1264 PARAMS ((rtx *));
extern rtx gen_split_1265 PARAMS ((rtx *));
extern rtx gen_split_1266 PARAMS ((rtx *));
extern rtx gen_split_1267 PARAMS ((rtx *));
extern rtx gen_split_1269 PARAMS ((rtx *));
extern rtx gen_split_1270 PARAMS ((rtx *));
extern rtx gen_split_1271 PARAMS ((rtx *));
extern rtx gen_split_1272 PARAMS ((rtx *));
extern rtx gen_split_1273 PARAMS ((rtx *));
extern rtx gen_split_1276 PARAMS ((rtx *));
extern rtx gen_split_1277 PARAMS ((rtx *));
extern rtx gen_split_1278 PARAMS ((rtx *));
extern rtx gen_split_1279 PARAMS ((rtx *));
extern rtx gen_split_1281 PARAMS ((rtx *));
extern rtx gen_split_1283 PARAMS ((rtx *));
extern rtx gen_split_1284 PARAMS ((rtx *));
extern rtx gen_split_1286 PARAMS ((rtx *));
extern rtx gen_split_1288 PARAMS ((rtx *));
extern rtx gen_split_1290 PARAMS ((rtx *));
extern rtx gen_split_1291 PARAMS ((rtx *));
extern rtx gen_split_1292 PARAMS ((rtx *));
extern rtx gen_split_1296 PARAMS ((rtx *));
extern rtx gen_split_1297 PARAMS ((rtx *));
extern rtx gen_split_1298 PARAMS ((rtx *));
extern rtx gen_split_1302 PARAMS ((rtx *));
extern rtx gen_split_1303 PARAMS ((rtx *));
extern rtx gen_split_1309 PARAMS ((rtx *));
extern rtx gen_split_1310 PARAMS ((rtx *));
extern rtx gen_split_1343 PARAMS ((rtx *));
extern rtx gen_split_1344 PARAMS ((rtx *));
extern rtx gen_split_1345 PARAMS ((rtx *));
extern rtx gen_split_1346 PARAMS ((rtx *));
extern rtx gen_split_1365 PARAMS ((rtx *));
extern rtx gen_split_1366 PARAMS ((rtx *));
extern rtx gen_split_1367 PARAMS ((rtx *));
extern rtx gen_split_1368 PARAMS ((rtx *));
extern rtx gen_split_1372 PARAMS ((rtx *));
extern rtx gen_split_1373 PARAMS ((rtx *));
extern rtx gen_peephole2_1374 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1375 PARAMS ((rtx, rtx *));
extern rtx gen_split_1386 PARAMS ((rtx *));
extern rtx gen_split_1387 PARAMS ((rtx *));
extern rtx gen_split_1393 PARAMS ((rtx *));
extern rtx gen_split_1394 PARAMS ((rtx *));
extern rtx gen_split_1395 PARAMS ((rtx *));
extern rtx gen_peephole2_1420 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1421 PARAMS ((rtx, rtx *));
extern rtx gen_split_1427 PARAMS ((rtx *));
extern rtx gen_split_1431 PARAMS ((rtx *));
extern rtx gen_split_1432 PARAMS ((rtx *));
extern rtx gen_split_1434 PARAMS ((rtx *));
extern rtx gen_split_1435 PARAMS ((rtx *));
extern rtx gen_split_1437 PARAMS ((rtx *));
extern rtx gen_split_1438 PARAMS ((rtx *));
extern rtx gen_split_1440 PARAMS ((rtx *));
extern rtx gen_split_1441 PARAMS ((rtx *));
extern rtx gen_split_1443 PARAMS ((rtx *));
extern rtx gen_split_1444 PARAMS ((rtx *));
extern rtx gen_split_1445 PARAMS ((rtx *));
extern rtx gen_split_1449 PARAMS ((rtx *));
extern rtx gen_split_1450 PARAMS ((rtx *));
extern rtx gen_split_1451 PARAMS ((rtx *));
extern rtx gen_split_1452 PARAMS ((rtx *));
extern rtx gen_split_1453 PARAMS ((rtx *));
extern rtx gen_split_1454 PARAMS ((rtx *));
extern rtx gen_peephole2_1455 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1456 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1457 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1458 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1459 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1460 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1461 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1462 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1463 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1464 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1465 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1466 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1467 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1468 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1469 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1470 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1471 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1472 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1473 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1474 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1475 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1476 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1477 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1478 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1479 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1480 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1481 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1482 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1483 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1484 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1485 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1486 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1487 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1488 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1489 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1490 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1491 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1492 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1493 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1494 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1495 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1496 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1497 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1498 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1499 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1500 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1501 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1502 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1503 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1504 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1505 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1506 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1507 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1508 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1509 PARAMS ((rtx, rtx *));
extern rtx gen_peephole2_1510 PARAMS ((rtx, rtx *));
extern rtx gen_split_1523 PARAMS ((rtx *));
extern rtx gen_split_1524 PARAMS ((rtx *));
extern rtx gen_split_1525 PARAMS ((rtx *));
extern rtx gen_split_1526 PARAMS ((rtx *));
extern rtx gen_split_1527 PARAMS ((rtx *));
extern rtx gen_split_1528 PARAMS ((rtx *));
extern rtx gen_split_1529 PARAMS ((rtx *));
extern rtx gen_split_1530 PARAMS ((rtx *));
extern rtx gen_split_1531 PARAMS ((rtx *));
extern rtx gen_split_1532 PARAMS ((rtx *));
extern rtx gen_split_1533 PARAMS ((rtx *));
extern rtx gen_split_1534 PARAMS ((rtx *));
extern rtx gen_split_1535 PARAMS ((rtx *));
extern rtx gen_split_1536 PARAMS ((rtx *));



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

  x1 = XEXP (x0, 0);
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L12870;
    case REG:
      goto L12871;
    default:
     break;
   }
 L12749: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L139;
    }
 L12759: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L1042;
    }
 L12760: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L347;
  if (register_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L352;
    }
 L12786: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L1069;
    }
  goto ret0;

 L12870: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, HImode))
    {
      operands[0] = x1;
      goto L335;
    }
  goto L12759;

 L335: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L336;
    }
 L339: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_no_elim_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L340;
    }
  x1 = XEXP (x0, 0);
  goto L12759;

 L336: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 48;
    }
  x1 = XEXP (x0, 1);
  goto L339;

 L340: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 49;
    }
  x1 = XEXP (x0, 0);
  goto L12759;

 L12871: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 0) == 18)
    goto L1073;
  goto L12749;

 L1073: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 28)
    goto L1074;
  x1 = XEXP (x0, 0);
  goto L12749;

 L1074: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (memory_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1075;
    }
  x1 = XEXP (x0, 0);
  goto L12749;

 L1075: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 160;
    }
  x1 = XEXP (x0, 0);
  goto L12749;

 L139: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 24)
    goto L140;
  x1 = XEXP (x0, 0);
  goto L12759;

 L140: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case CCFPmode:
      goto L12872;
    case CCFPUmode:
      goto L12873;
    default:
      break;
    }
 L212: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 18
      && (TARGET_80387))
    {
      return 29;
    }
  x1 = XEXP (x0, 0);
  goto L12759;

 L12872: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == COMPARE)
    goto L154;
  goto L212;

 L154: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SFmode:
      goto L12874;
    case DFmode:
      goto L12875;
    case XFmode:
      goto L12876;
    case TFmode:
      goto L12877;
    default:
      break;
    }
 L141: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L142;
    }
  goto L212;

 L12874: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L155;
    }
  goto L141;

 L155: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L156;
    }
  x3 = XEXP (x2, 0);
  goto L141;

 L156: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 20;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 0);
  goto L141;

 L12875: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L168;
    }
  goto L141;

 L168: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L169;
    }
  x3 = XEXP (x2, 0);
  goto L141;

 L169: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 22;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 0);
  goto L141;

 L12876: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, XFmode))
    {
      operands[1] = x3;
      goto L187;
    }
  goto L141;

 L187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, XFmode))
    {
      operands[2] = x3;
      goto L188;
    }
  x3 = XEXP (x2, 0);
  goto L141;

 L188: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 25;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 0);
  goto L141;

 L12877: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L194;
    }
  goto L141;

 L194: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, TFmode))
    {
      operands[2] = x3;
      goto L195;
    }
  x3 = XEXP (x2, 0);
  goto L141;

 L195: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 26;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 0);
  goto L141;

 L142: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const0_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L143;
    }
  goto L212;

 L143: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])))
    {
      return 18;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L212;

 L12873: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == COMPARE)
    goto L206;
  goto L212;

 L206: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L207;
    }
  goto L212;

 L207: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L208;
    }
  goto L212;

 L208: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])))
    {
      return 28;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L212;

 L1042: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L12878;
 L343: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L344;
    }
  x1 = XEXP (x0, 0);
  goto L12760;

 L12878: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FIX:
      goto L1043;
    case PLUS:
      goto L1563;
    case MINUS:
      goto L2044;
    case AND:
      goto L2982;
    case IOR:
      goto L3351;
    case XOR:
      goto L3734;
    case NEG:
      goto L4106;
    case NOT:
      goto L4565;
    case ASHIFT:
      goto L4744;
    case ASHIFTRT:
      goto L5093;
    case LSHIFTRT:
      goto L5431;
    case ROTATE:
      goto L5659;
    case ROTATERT:
      goto L5835;
    default:
     break;
   }
  goto L343;

 L1043: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1044;
    }
  goto L343;

 L1044: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && FLOAT_MODE_P (GET_MODE (operands[1]))
   && !reload_completed && !reload_in_progress
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
    {
      return 156;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L1563: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1564;
    }
  goto L343;

 L1564: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L1565;
    }
  goto L343;

 L1565: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 209;
    }
 L1579: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 210;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L2044: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2045;
    }
  goto L343;

 L2045: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L2046;
    }
  goto L343;

 L2046: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (MINUS, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 238;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L2982: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2983;
    }
  goto L343;

 L2983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L2984;
    }
  goto L343;

 L2984: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (AND, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 292;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L3351: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L3352;
    }
  goto L343;

 L3352: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L3353;
    }
  goto L343;

 L3353: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (IOR, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 313;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L3734: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L3735;
    }
  goto L343;

 L3735: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L3736;
    }
  goto L343;

 L3736: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (XOR, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 335;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L4106: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L4107;
    }
  goto L343;

 L4107: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NEG, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 356;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L4565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L4566;
    }
  goto L343;

 L4566: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NOT, HImode, operands)))
    {
      return 404;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L4744: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L4745;
    }
  goto L343;

 L4745: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4746;
    }
  goto L343;

 L4746: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 417;
    }
 L4760: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 418;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L5093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L5094;
    }
  goto L343;

 L5094: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5095;
    }
 L5108: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5109;
    }
  goto L343;

 L5095: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 441;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5108;

 L5109: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 442;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L5431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L5432;
    }
  goto L343;

 L5432: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5433;
    }
 L5446: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5447;
    }
  goto L343;

 L5433: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 465;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5446;

 L5447: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 466;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L5659: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L5660;
    }
  goto L343;

 L5660: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5661;
    }
 L5674: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5675;
    }
  goto L343;

 L5661: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATE, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 481;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5674;

 L5675: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATE, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 482;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L5835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L5836;
    }
  goto L343;

 L5836: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5837;
    }
 L5850: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5851;
    }
  goto L343;

 L5837: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATERT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 493;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5850;

 L5851: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATERT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 494;
    }
  x1 = XEXP (x0, 1);
  goto L343;

 L344: ATTRIBUTE_UNUSED_LABEL
  if ((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
    {
      return 50;
    }
  x1 = XEXP (x0, 0);
  goto L12760;

 L347: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L348;
    }
  goto L12786;

 L348: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L349;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L349: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 0)))
    {
      return 51;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L352: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode)
    goto L12891;
  x1 = XEXP (x0, 0);
  goto L12786;

 L12891: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L353;
    case SIGN_EXTRACT:
      goto L431;
    case ZERO_EXTEND:
      goto L698;
    case SIGN_EXTEND:
      goto L816;
    case MULT:
      goto L2180;
    case IF_THEN_ELSE:
      goto L7522;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12786;

 L353: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L354;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L354: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 1)))
    {
      return 52;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L432;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L432: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L433;
  x1 = XEXP (x0, 0);
  goto L12786;

 L433: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    {
      return 64;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L698: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L699;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L699: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ZERO_EXTEND_WITH_AND && !optimize_size)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 108;
    }
 L711: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 109;
    }
 L716: ATTRIBUTE_UNUSED_LABEL
  if (((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size) && reload_completed))
    {
      return 110;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L816: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 124;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == HImode)
    goto L12898;
  x1 = XEXP (x0, 0);
  goto L12786;

 L12898: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L2211;
    case SIGN_EXTEND:
      goto L2229;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L12897;
    default:
      x1 = XEXP (x0, 0);
      goto L12786;
   }
 L12897: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2181;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2211: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L2212;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2212: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2213;
  x1 = XEXP (x0, 0);
  goto L12786;

 L2213: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2214;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2214: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_QIMODE_MATH
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 250;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2229: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L2230;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2230: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L2231;
  x1 = XEXP (x0, 0);
  goto L12786;

 L2231: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2232;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2232: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_QIMODE_MATH
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 251;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L2182;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L2182: ATTRIBUTE_UNUSED_LABEL
  if ((GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 248;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L7522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7523;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L7523: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7524;
  x1 = XEXP (x0, 0);
  goto L12786;

 L7524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7525;
  x1 = XEXP (x0, 0);
  goto L12786;

 L7525: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L7526;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L7526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L7527;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L7527: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_CMOVE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 640;
    }
  x1 = XEXP (x0, 0);
  goto L12786;

 L1069: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == HImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 26)
    goto L1070;
  goto ret0;

 L1070: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 18
      && (TARGET_80387))
    {
      return 159;
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
  if (GET_MODE (x1) == SImode)
    goto L12919;
 L1283: ATTRIBUTE_UNUSED_LABEL
  if (no_seg_address_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L1284;
    }
 L1287: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x1) == SImode)
    goto L12931;
  goto ret0;

 L12919: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L324;
    case SIGN_EXTRACT:
      goto L425;
    case ZERO_EXTRACT:
      goto L459;
    case ZERO_EXTEND:
      goto L681;
    case SIGN_EXTEND:
      goto L806;
    case FIX:
      goto L1033;
    case TRUNCATE:
      goto L2348;
    case UNSPEC:
      goto L12934;
    case IF_THEN_ELSE:
      goto L7505;
    default:
     break;
   }
  goto L1283;

 L324: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L325;
    }
  goto L1283;

 L325: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 1)))
    {
      return 46;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L425: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L426;
    }
  goto L1283;

 L426: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L427;
  goto L1283;

 L427: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    {
      return 63;
    }
  goto L1283;

 L459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L460;
    }
  goto L1283;

 L460: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L461;
  goto L1283;

 L461: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    {
      return 69;
    }
  goto L1283;

 L681: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L12938;
    case QImode:
      goto L12940;
    default:
      break;
    }
  goto L1283;

 L12938: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L682;
    }
 L12939: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L687;
    }
  goto L1283;

 L682: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ZERO_EXTEND_WITH_AND && !optimize_size)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 106;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L12939;

 L687: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size))
    {
      return 107;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L12940: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L728;
    }
  goto L1283;

 L728: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ZERO_EXTEND_WITH_AND && !optimize_size)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 111;
    }
 L740: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 112;
    }
 L745: ATTRIBUTE_UNUSED_LABEL
  if (((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size) && reload_completed))
    {
      return 113;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L806: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L12941;
    case QImode:
      goto L12942;
    default:
      break;
    }
  goto L1283;

 L12941: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      return 122;
    }
  goto L1283;

 L12942: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      return 125;
    }
  goto L1283;

 L1033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L12943;
    case DFmode:
      goto L12944;
    default:
      break;
    }
  goto L1283;

 L12943: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L1034;
    }
  goto L1283;

 L1034: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 154;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L12944: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1039;
    }
  goto L1283;

 L1039: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 155;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L2348: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L2349;
  goto L1283;

 L2349: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == MULT)
    goto L2350;
  goto L1283;

 L2350: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L12945;
  goto L1283;

 L12945: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTEND:
      goto L2351;
    case SIGN_EXTEND:
      goto L2428;
    default:
     break;
   }
  goto L1283;

 L2351: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L2352;
    }
  goto L1283;

 L2352: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L2353;
  goto L1283;

 L2353: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2354;
    }
  goto L1283;

 L2354: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 32LL
      && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 257;
    }
  goto L1283;

 L2428: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L2429;
    }
  goto L1283;

 L2429: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L2430;
  goto L1283;

 L2430: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L2431;
    }
  goto L1283;

 L2431: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 32LL
      && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 260;
    }
  goto L1283;

 L12934: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L12947;
    case 3:
      goto L12948;
    case 2:
      goto L12949;
    default:
      break;
    }
  goto L1283;

 L12947: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 12LL:
      goto L6322;
    case 15LL:
      goto L6489;
    default:
      break;
    }
  goto L1283;

 L6322: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 531;
    }
  goto L1283;

 L6489: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (!TARGET_64BIT))
    {
      return 544;
    }
  goto L1283;

 L12948: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 16)
    goto L6381;
  goto L1283;

 L6381: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6382;
    }
  goto L1283;

 L6382: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (tls_symbolic_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6383;
    }
  goto L1283;

 L6383: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (call_insn_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L6384;
    }
  goto L1283;

 L6384: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_GNU_TLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 537;
    }
 L6404: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_SUN_TLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 538;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L12949: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 17)
    goto L6430;
  goto L1283;

 L6430: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6431;
    }
  goto L1283;

 L6431: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (call_insn_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6432;
    }
  goto L1283;

 L6432: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_GNU_TLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 540;
    }
 L6450: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_SUN_TLS)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 541;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L7505: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LTU)
    goto L7506;
 L7513: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7514;
    }
  goto L1283;

 L7506: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CCmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7507;
  goto L7513;

 L7507: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7508;
  goto L7513;

 L7508: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == -1LL)
    goto L7509;
  x2 = XEXP (x1, 0);
  goto L7513;

 L7509: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 638;
    }
  x2 = XEXP (x1, 0);
  goto L7513;

 L7514: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7515;
  goto L1283;

 L7515: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7516;
  goto L1283;

 L7516: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7517;
    }
  goto L1283;

 L7517: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L7518;
    }
  goto L1283;

 L7518: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_CMOVE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 639;
    }
  x1 = XEXP (x0, 1);
  goto L1283;

 L1284: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 186;
    }
  x1 = XEXP (x0, 1);
  goto L1287;

 L12931: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SUBREG:
      goto L12951;
    case MULT:
      goto L2150;
    case PLUS:
      goto L6479;
    default:
     break;
   }
  goto ret0;

 L12951: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L1288;
  goto ret0;

 L1288: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (no_seg_address_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1289;
    }
  goto ret0;

 L1289: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 187;
    }
  goto ret0;

 L2150: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2151;
    }
  goto ret0;

 L2151: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2152;
    }
  goto ret0;

 L2152: ATTRIBUTE_UNUSED_LABEL
  if ((GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 246;
    }
  goto ret0;

 L6479: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12952;
  goto ret0;

 L12952: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == UNSPEC)
    goto L12954;
  goto ret0;

 L12954: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x2, 0))
    {
    case 2:
      goto L12956;
    case 1:
      goto L12957;
    default:
      break;
    }
  goto ret0;

 L12956: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 17)
    goto L6480;
  goto ret0;

 L6480: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6481;
    }
  goto ret0;

 L6481: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (call_insn_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6482;
    }
  goto ret0;

 L6482: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == CONST)
    goto L6483;
  goto ret0;

 L6483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == UNSPEC
      && XVECLEN (x3, 0) == 1
      && XINT (x3, 1) == 6)
    goto L6484;
  goto ret0;

 L6484: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (tls_symbolic_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L6485;
    }
  goto ret0;

 L6485: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 543;
    }
  goto ret0;

 L12957: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 15)
    goto L6507;
  goto ret0;

 L6507: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6508;
  goto ret0;

 L6508: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L6509;
    }
  goto ret0;

 L6509: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 546;
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

  x1 = XEXP (x0, 0);
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L12904;
    case ZERO_EXTRACT:
      goto L478;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L12754;
    default:
      goto L12755;
   }
 L12754: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L300;
    }
 L12755: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1005;
    }
 L12756: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L318;
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L323;
    }
 L12798: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 19)
    goto L6872;
 L12791: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L1442;
    }
  goto ret0;

 L12904: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L256;
    }
  goto L12755;

 L256: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L257;
    }
 L260: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_no_elim_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L261;
    }
  x1 = XEXP (x0, 0);
  goto L12755;

 L257: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 37;
    }
  x1 = XEXP (x0, 1);
  goto L260;

 L261: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 38;
    }
  x1 = XEXP (x0, 0);
  goto L12755;

 L478: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L479;
    }
  goto ret0;

 L479: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L480;
  goto ret0;

 L480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L495;
  goto ret0;

 L495: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12905;
 L481: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L482;
    }
 L488: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L489;
    }
  goto ret0;

 L12905: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L496;
    case PLUS:
      goto L1770;
    case IOR:
      goto L3480;
    case XOR:
      goto L3818;
    default:
     break;
   }
  goto L481;

 L496: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12909;
  goto L481;

 L12909: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case LSHIFTRT:
      goto L497;
    case ZERO_EXTRACT:
      goto L3076;
    default:
     break;
   }
  goto L481;

 L497: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L498;
    }
  goto L481;

 L498: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L499;
  goto L481;

 L499: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 255LL)
    {
      return 74;
    }
  goto L481;

 L3076: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L3077;
    }
  goto L481;

 L3077: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3078;
  goto L481;

 L3078: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3128;
  goto L481;

 L3128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12911;
 L3079: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L3080;
    }
  goto L481;

 L12911: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L3129;
    case ZERO_EXTRACT:
      goto L3187;
    default:
     break;
   }
  goto L3079;

 L3129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3130;
    }
 L3157: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3158;
    }
  goto L3079;

 L3130: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 300;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L3157;

 L3158: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 301;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3079;

 L3187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3188;
    }
  goto L3079;

 L3188: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3189;
  goto L3079;

 L3189: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 302;
    }
  goto L3079;

 L3080: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 298;
    }
  x1 = XEXP (x0, 1);
  goto L481;

 L1770: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1771;
  goto L481;

 L1771: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1772;
    }
  goto L481;

 L1772: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L1773;
  goto L481;

 L1773: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L1829;
  goto L481;

 L1829: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L1830;
  if (general_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1775;
    }
 L1800: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1801;
    }
  goto L481;

 L1830: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L1831;
    }
  goto L481;

 L1831: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L1832;
  goto L481;

 L1832: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 224;
    }
  goto L481;

 L1775: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 222;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1800;

 L1801: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 223;
    }
  x1 = XEXP (x0, 1);
  goto L481;

 L3480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L3481;
  goto L481;

 L3481: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L3482;
    }
  goto L481;

 L3482: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3483;
  goto L481;

 L3483: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3511;
  goto L481;

 L3511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12913;
 L3484: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L3485;
    }
  goto L481;

 L12913: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L3512;
    case ZERO_EXTRACT:
      goto L3570;
    default:
     break;
   }
  goto L3484;

 L3512: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3513;
    }
 L3540: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3541;
    }
  goto L3484;

 L3513: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 322;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L3540;

 L3541: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 323;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3484;

 L3570: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3571;
    }
  goto L3484;

 L3571: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3572;
  goto L3484;

 L3572: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && ((!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 324;
    }
  goto L3484;

 L3485: ATTRIBUTE_UNUSED_LABEL
  if (((!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 321;
    }
  x1 = XEXP (x0, 1);
  goto L481;

 L3818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L3819;
  goto L481;

 L3819: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L3820;
    }
  goto L481;

 L3820: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3821;
  goto L481;

 L3821: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3849;
  goto L481;

 L3849: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L12915;
 L3822: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, VOIDmode))
    {
      operands[2] = x2;
      goto L3823;
    }
  goto L481;

 L12915: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L3850;
    case ZERO_EXTRACT:
      goto L3908;
    default:
     break;
   }
  goto L3822;

 L3850: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3851;
    }
 L3878: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3879;
    }
  goto L3822;

 L3851: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 341;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L3878;

 L3879: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 342;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L3822;

 L3908: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3909;
    }
  goto L3822;

 L3909: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3910;
  goto L3822;

 L3910: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && ((!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 343;
    }
  goto L3822;

 L3823: ATTRIBUTE_UNUSED_LABEL
  if (((!TARGET_PARTIAL_REG_STALL || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 340;
    }
  x1 = XEXP (x0, 1);
  goto L481;

 L482: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 72;
    }
  x1 = XEXP (x0, 1);
  goto L488;

 L489: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 73;
    }
  goto ret0;

 L300: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const0_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L301;
    }
 L310: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L311;
    }
  x1 = XEXP (x0, 0);
  goto L12755;

 L301: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed && (!TARGET_USE_MOV0 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 42;
    }
  x1 = XEXP (x0, 1);
  goto L310;

 L311: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) == -1
   && (TARGET_PENTIUM || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 43;
    }
  x1 = XEXP (x0, 0);
  goto L12755;

 L1005: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12917;
 L314: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L315;
    }
  x1 = XEXP (x0, 0);
  goto L12756;

 L12917: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FIX:
      goto L1006;
    case PLUS:
      goto L1228;
    default:
     break;
   }
  goto L314;

 L1006: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L1007;
    }
  goto L314;

 L1007: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && FLOAT_MODE_P (GET_MODE (operands[1]))
   && !reload_completed && !reload_in_progress
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
    {
      return 151;
    }
  x1 = XEXP (x0, 1);
  goto L314;

 L1228: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1229;
  goto L314;

 L1229: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LTU)
    goto L1230;
  goto L314;

 L1230: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == CCmode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L1231;
  goto L314;

 L1231: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L1232;
  goto L314;

 L1232: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1233;
    }
  goto L314;

 L1233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1234;
    }
  goto L314;

 L1234: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (PLUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 182;
    }
  x1 = XEXP (x0, 1);
  goto L314;

 L315: ATTRIBUTE_UNUSED_LABEL
  if ((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
    {
      return 44;
    }
  x1 = XEXP (x0, 0);
  goto L12756;

 L318: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L319;
    }
  goto L12791;

 L319: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_operand (x1, SImode))
    {
      operands[1] = x1;
      goto L320;
    }
  x1 = XEXP (x0, 0);
  goto L12791;

 L320: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 0)))
    {
      return 45;
    }
  x1 = XEXP (x0, 0);
  goto L12791;

 L323: ATTRIBUTE_UNUSED_LABEL
  tem = recog_2 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L12798;

 L6872: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL)
    {
      return 605;
    }
  x1 = XEXP (x0, 0);
  goto L12791;

 L1442: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L12958;
  goto ret0;

 L12958: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L1443;
    case MINUS:
      goto L1922;
    case AND:
      goto L2925;
    case IOR:
      goto L3246;
    case XOR:
      goto L3629;
    case NEG:
      goto L4045;
    case NOT:
      goto L4531;
    case ASHIFT:
      goto L4687;
    case ASHIFTRT:
      goto L4949;
    case LSHIFTRT:
      goto L5317;
    case ROTATE:
      goto L5599;
    case ROTATERT:
      goto L5775;
    default:
     break;
   }
  goto ret0;

 L1443: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1444;
    }
  goto ret0;

 L1444: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1445;
    }
  goto ret0;

 L1445: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (PLUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 201;
    }
  goto ret0;

 L1922: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1923;
    }
  goto ret0;

 L1923: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1924;
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1966;
    }
  goto ret0;

 L1924: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LTU)
    goto L1925;
  goto ret0;

 L1925: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == CCmode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L1926;
  goto ret0;

 L1926: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L1927;
  goto ret0;

 L1927: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1928;
    }
  goto ret0;

 L1928: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (MINUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 230;
    }
  goto ret0;

 L1966: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (MINUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 232;
    }
  goto ret0;

 L2925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2926;
    }
  goto ret0;

 L2926: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L2927;
    }
  goto ret0;

 L2927: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (AND, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 288;
    }
  goto ret0;

 L3246: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L12971;
  goto ret0;

 L12971: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFT:
      goto L4669;
    case ASHIFTRT:
      goto L4931;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L12970;
    default:
      goto ret0;
   }
 L12970: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3247;
    }
  goto ret0;

 L4669: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4670;
  goto ret0;

 L4670: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4671;
    }
  goto ret0;

 L4671: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L4672;
  goto ret0;

 L4672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4673;
    }
  goto ret0;

 L4673: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MINUS)
    goto L4674;
  goto ret0;

 L4674: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L4675;
  goto ret0;

 L4675: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 412;
    }
  goto ret0;

 L4931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L4932;
  goto ret0;

 L4932: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4933;
    }
  goto ret0;

 L4933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L4934;
  goto ret0;

 L4934: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4935;
    }
  goto ret0;

 L4935: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MINUS)
    goto L4936;
  goto ret0;

 L4936: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L4937;
  goto ret0;

 L4937: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 430;
    }
  goto ret0;

 L3247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3248;
    }
  goto ret0;

 L3248: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (IOR, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 306;
    }
  goto ret0;

 L3629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L3630;
    }
  goto ret0;

 L3630: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L3631;
    }
  goto ret0;

 L3631: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (XOR, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 328;
    }
  goto ret0;

 L4045: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4046;
    }
  goto ret0;

 L4046: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NEG, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 352;
    }
  goto ret0;

 L4531: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4532;
    }
  goto ret0;

 L4532: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NOT, SImode, operands)))
    {
      return 400;
    }
  goto ret0;

 L4687: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4688;
    }
  goto ret0;

 L4688: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4689;
    }
  goto ret0;

 L4689: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 413;
    }
  goto ret0;

 L4949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L4950;
    }
  goto ret0;

 L4950: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L12973;
 L5010: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5011;
    }
  goto ret0;

 L12973: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L4951;
    }
 L12974: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4981;
    }
  goto L5010;

 L4951: ATTRIBUTE_UNUSED_LABEL
  if ((INTVAL (operands[2]) == 31 && (TARGET_USE_CLTD || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 431;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L12974;

 L4981: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 433;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5010;

 L5011: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 435;
    }
  goto ret0;

 L5317: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5318;
    }
  goto ret0;

 L5318: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5319;
    }
 L5348: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5349;
    }
  goto ret0;

 L5319: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 457;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5348;

 L5349: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 459;
    }
  goto ret0;

 L5599: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5600;
    }
  goto ret0;

 L5600: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5601;
    }
 L5630: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5631;
    }
  goto ret0;

 L5601: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATE, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 477;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5630;

 L5631: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATE, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 479;
    }
  goto ret0;

 L5775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L5776;
    }
  goto ret0;

 L5776: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5777;
    }
 L5806: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5807;
    }
  goto ret0;

 L5777: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATERT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 489;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5806;

 L5807: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATERT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 491;
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

  x1 = XEXP (x0, 0);
  if (push_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L388;
    }
 L12763: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L436;
    }
 L12765: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L448;
  if (register_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L442;
    }
 L12766: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L464;
    }
 L12767: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, QImode))
    {
      operands[0] = x1;
      goto L471;
    }
  goto ret0;

 L388: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_no_elim_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L389;
    }
  x1 = XEXP (x0, 0);
  goto L12763;

 L389: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 57;
    }
 L393: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 58;
    }
  x1 = XEXP (x0, 0);
  goto L12763;

 L436: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode
      && GET_CODE (x1) == SIGN_EXTRACT)
    goto L437;
  if (general_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L397;
    }
  x1 = XEXP (x0, 0);
  goto L12765;

 L437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L438;
    }
  x1 = XEXP (x0, 0);
  goto L12765;

 L438: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L439;
  x1 = XEXP (x0, 0);
  goto L12765;

 L439: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL
      && (!TARGET_64BIT))
    {
      return 65;
    }
  x1 = XEXP (x0, 0);
  goto L12765;

 L397: ATTRIBUTE_UNUSED_LABEL
  if ((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
    {
      return 59;
    }
  x1 = XEXP (x0, 0);
  goto L12765;

 L448: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L449;
    }
  goto L12766;

 L449: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L450;
    }
  x1 = XEXP (x0, 0);
  goto L12766;

 L450: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 0)))
    {
      return 67;
    }
  x1 = XEXP (x0, 0);
  goto L12766;

 L442: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L12975;
  x1 = XEXP (x0, 0);
  goto L12766;

 L12975: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SIGN_EXTRACT:
      goto L443;
    case MEM:
      goto L454;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12766;

 L443: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ext_register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L444;
    }
  x1 = XEXP (x0, 0);
  goto L12766;

 L444: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL)
    goto L445;
  x1 = XEXP (x0, 0);
  goto L12766;

 L445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 8LL
      && (TARGET_64BIT))
    {
      return 66;
    }
  x1 = XEXP (x0, 0);
  goto L12766;

 L454: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L455;
    }
  x1 = XEXP (x0, 0);
  goto L12766;

 L455: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 1)))
    {
      return 68;
    }
  x1 = XEXP (x0, 0);
  goto L12766;

 L464: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L12977;
  x1 = XEXP (x0, 0);
  goto L12767;

 L12977: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SUBREG:
      goto L12991;
    case PLUS:
      goto L1654;
    case MINUS:
      goto L2082;
    case AND:
      goto L3009;
    case IOR:
      goto L3396;
    case XOR:
      goto L3779;
    case NEG:
      goto L4129;
    case NOT:
      goto L4581;
    case ASHIFT:
      goto L4785;
    case ASHIFTRT:
      goto L5147;
    case LSHIFTRT:
      goto L5485;
    case ROTATE:
      goto L5703;
    case ROTATERT:
      goto L5863;
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
    case UNLE:
    case UNLT:
    case UNGE:
    case UNGT:
    case LTGT:
    case UNEQ:
      goto L12990;
    default:
      x1 = XEXP (x0, 0);
      goto L12767;
   }
 L12990: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x1, QImode))
    {
      operands[1] = x1;
      goto L5915;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L12991: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L465;
  x1 = XEXP (x0, 0);
  goto L12767;

 L465: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L466;
  x1 = XEXP (x0, 0);
  goto L12767;

 L466: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L467;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L468;
  x1 = XEXP (x0, 0);
  goto L12767;

 L468: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && (!TARGET_64BIT))
    {
      return 70;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L1654: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1655;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L1655: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1656;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L1656: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 215;
    }
 L1670: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 216;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L2082: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L2083;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L2083: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L2084;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L2084: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (MINUS, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 241;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3009: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L3010;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3010: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L3011;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3011: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (AND, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 294;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L3397;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3397: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L3398;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3398: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (IOR, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 316;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3779: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L3780;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3780: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L3781;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L3781: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (XOR, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 338;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4129: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4130;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4130: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NEG, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 358;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4581: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4582;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4582: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NOT, QImode, operands)))
    {
      return 406;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4785: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L4786;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4787;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L4787: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 420;
    }
 L4801: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 421;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5147: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5148;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5148: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5149;
    }
 L5178: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5179;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5149: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 445;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5178;

 L5179: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 447;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5486;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5486: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5487;
    }
 L5516: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5517;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5487: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (LSHIFTRT, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 469;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5516;

 L5517: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (LSHIFTRT, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 471;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5703: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5704;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5705;
    }
 L5734: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5735;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5705: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATE, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 484;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5734;

 L5735: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATE, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 486;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5864;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5864: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5865;
    }
 L5894: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5895;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5865: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATERT, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 495;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5894;

 L5895: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ROTATERT, QImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 497;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L5915: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5916;
  x1 = XEXP (x0, 0);
  goto L12767;

 L5916: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL)
    {
      return 499;
    }
  x1 = XEXP (x0, 0);
  goto L12767;

 L471: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L12992;
  goto ret0;

 L12992: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case SUBREG:
      goto L12996;
    case MULT:
      goto L2194;
    case DIV:
      goto L2470;
    case UDIV:
      goto L2484;
    default:
     break;
   }
  goto ret0;

 L12996: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L472;
  goto ret0;

 L472: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L473;
  goto ret0;

 L473: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L474;
    }
  goto ret0;

 L474: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L475;
  goto ret0;

 L475: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && (TARGET_64BIT))
    {
      return 71;
    }
  goto ret0;

 L2194: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L2195;
    }
  goto ret0;

 L2195: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L2196;
    }
  goto ret0;

 L2196: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_QIMODE_MATH
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 249;
    }
  goto ret0;

 L2470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2471;
    }
  goto ret0;

 L2471: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L2472;
    }
  goto ret0;

 L2472: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_QIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 262;
    }
  goto ret0;

 L2484: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L2485;
    }
  goto ret0;

 L2485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L2486;
    }
  goto ret0;

 L2486: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_QIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 263;
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
      goto L574;
    case ZERO_EXTEND:
      goto L766;
    case SIGN_EXTEND:
      goto L791;
    case FIX:
      goto L996;
    case TRUNCATE:
      goto L2323;
    case IOR:
      goto L3277;
    case XOR:
      goto L3660;
    case LSHIFTRT:
      goto L4061;
    default:
     break;
   }
  goto ret0;

 L574: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L575;
    }
  goto ret0;

 L575: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 1)))
    {
      return 85;
    }
  goto ret0;

 L766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L13011;
    case QImode:
      goto L13012;
    case SImode:
      goto L13013;
    default:
      break;
    }
  goto ret0;

 L13011: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L767;
    }
  goto ret0;

 L767: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 116;
    }
  goto ret0;

 L13012: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L772;
    }
  goto ret0;

 L772: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 117;
    }
  goto ret0;

 L13013: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L811;
    case PLUS:
      goto L1252;
    case SUBREG:
      goto L13023;
    case MINUS:
      goto L1946;
    case MULT:
      goto L2166;
    case TRUNCATE:
      goto L2375;
    case AND:
      goto L2941;
    case IOR:
      goto L3262;
    case XOR:
      goto L3645;
    case NOT:
      goto L4537;
    default:
     break;
   }
  goto ret0;

 L811: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case HImode:
      goto L13024;
    case QImode:
      goto L13025;
    default:
      break;
    }
  goto ret0;

 L13024: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L812;
    }
  goto ret0;

 L812: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 123;
    }
  goto ret0;

 L13025: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L826;
    }
  goto ret0;

 L826: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 126;
    }
  goto ret0;

 L1252: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L13026;
  goto ret0;

 L13026: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1253;
    case MULT:
      goto L1330;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13028;
    default:
      goto ret0;
   }
 L13028: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1460;
    }
  goto ret0;

 L1253: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L13029;
  goto ret0;

 L13029: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case LTU:
      goto L1254;
    case MULT:
      goto L1350;
    case SUBREG:
    case REG:
      goto L13030;
    default:
      goto ret0;
   }
 L13030: ATTRIBUTE_UNUSED_LABEL
  if (index_register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1314;
    }
  goto ret0;

 L1254: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == CCmode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1255;
  goto ret0;

 L1255: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L1256;
  goto ret0;

 L1256: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1257;
    }
  goto ret0;

 L1257: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1258;
    }
  goto ret0;

 L1258: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 183;
    }
  goto ret0;

 L1350: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (index_register_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1351;
    }
  goto ret0;

 L1351: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (const248_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1352;
    }
  goto ret0;

 L1352: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[3] = x4;
      goto L1353;
    }
  goto ret0;

 L1353: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L1354;
    }
  goto ret0;

 L1354: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 195;
    }
  goto ret0;

 L1314: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1315;
    }
  goto ret0;

 L1315: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1316;
    }
  goto ret0;

 L1316: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 191;
    }
  goto ret0;

 L1330: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (index_register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1331;
    }
  goto ret0;

 L1331: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const248_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1332;
    }
  goto ret0;

 L1332: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L1333;
    }
  goto ret0;

 L1333: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 193;
    }
  goto ret0;

 L1460: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1461;
    }
  goto ret0;

 L1461: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 202;
    }
  goto ret0;

 L13023: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 1) == 0)
    goto L1294;
  goto ret0;

 L1294: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (no_seg_address_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1295;
    }
  goto ret0;

 L1295: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 188;
    }
  goto ret0;

 L1946: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1947;
    }
  goto ret0;

 L1947: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L1948;
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1982;
    }
  goto ret0;

 L1948: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LTU)
    goto L1949;
  goto ret0;

 L1949: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == CCmode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1950;
  goto ret0;

 L1950: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L1951;
  goto ret0;

 L1951: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1952;
    }
  goto ret0;

 L1952: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 231;
    }
  goto ret0;

 L1982: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 233;
    }
  goto ret0;

 L2166: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2167;
    }
  goto ret0;

 L2167: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2168;
    }
  goto ret0;

 L2168: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 247;
    }
  goto ret0;

 L2375: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L2376;
  goto ret0;

 L2376: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L2377;
  goto ret0;

 L2377: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L13032;
  goto ret0;

 L13032: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ZERO_EXTEND:
      goto L2378;
    case SIGN_EXTEND:
      goto L2455;
    default:
     break;
   }
  goto ret0;

 L2378: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2379;
    }
  goto ret0;

 L2379: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L2380;
  goto ret0;

 L2380: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2381;
    }
  goto ret0;

 L2381: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 258;
    }
  goto ret0;

 L2455: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2456;
    }
  goto ret0;

 L2456: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L2457;
  goto ret0;

 L2457: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2458;
    }
  goto ret0;

 L2458: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 261;
    }
  goto ret0;

 L2941: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2942;
    }
  goto ret0;

 L2942: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2943;
    }
  goto ret0;

 L2943: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (AND, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 289;
    }
  goto ret0;

 L3262: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3263;
    }
  goto ret0;

 L3263: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3264;
    }
  goto ret0;

 L3264: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (IOR, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 307;
    }
  goto ret0;

 L3645: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3646;
    }
  goto ret0;

 L3646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3647;
    }
  goto ret0;

 L3647: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 329;
    }
  goto ret0;

 L4537: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4538;
    }
  goto ret0;

 L4538: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_unary_operator_ok (NOT, SImode, operands)))
    {
      return 401;
    }
  goto ret0;

 L791: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13034;
    case HImode:
      goto L13035;
    case QImode:
      goto L13036;
    default:
      break;
    }
  goto ret0;

 L13034: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L792;
    }
  goto ret0;

 L792: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 119;
    }
  goto ret0;

 L13035: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L797;
    }
  goto ret0;

 L797: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 120;
    }
  goto ret0;

 L13036: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L802;
    }
  goto ret0;

 L802: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 121;
    }
  goto ret0;

 L996: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L13037;
    case DFmode:
      goto L13038;
    default:
      break;
    }
  goto ret0;

 L13037: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L997;
    }
  goto ret0;

 L997: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_SSE))
    {
      return 149;
    }
  goto ret0;

 L13038: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L1002;
    }
  goto ret0;

 L1002: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_SSE2))
    {
      return 150;
    }
  goto ret0;

 L2323: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L2324;
  goto ret0;

 L2324: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == MULT)
    goto L2325;
  goto ret0;

 L2325: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == TImode)
    goto L13039;
  goto ret0;

 L13039: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case ZERO_EXTEND:
      goto L2326;
    case SIGN_EXTEND:
      goto L2403;
    default:
     break;
   }
  goto ret0;

 L2326: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L2327;
    }
  goto ret0;

 L2327: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L2328;
  goto ret0;

 L2328: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L2329;
    }
  goto ret0;

 L2329: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 64LL
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 256;
    }
  goto ret0;

 L2403: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L2404;
    }
  goto ret0;

 L2404: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L2405;
  goto ret0;

 L2405: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, DImode))
    {
      operands[2] = x5;
      goto L2406;
    }
  goto ret0;

 L2406: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 64LL
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 259;
    }
  goto ret0;

 L3277: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3278;
  goto ret0;

 L3278: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3279;
    }
  goto ret0;

 L3279: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_zext_immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3280;
    }
  goto ret0;

 L3280: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 308;
    }
  goto ret0;

 L3660: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3661;
  goto ret0;

 L3661: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3662;
    }
  goto ret0;

 L3662: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_zext_immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3663;
    }
  goto ret0;

 L3663: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 330;
    }
  goto ret0;

 L4061: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NEG)
    goto L4062;
  goto ret0;

 L4062: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ASHIFT)
    goto L4063;
  goto ret0;

 L4063: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4064;
    }
  goto ret0;

 L4064: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L4065;
  goto ret0;

 L4065: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 32LL
      && (TARGET_64BIT && ix86_unary_operator_ok (NEG, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 353;
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
  if (push_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L502;
    }
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L546;
    }
 L12771: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L755;
    }
 L12772: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L568;
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L573;
    }
 L12790: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L1365;
    }
 L12797: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L4633;
    }
  goto ret0;

 L502: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L503;
    }
  x1 = XEXP (x0, 0);
  goto L12771;

 L503: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 75;
    }
 L507: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 76;
    }
  x1 = XEXP (x0, 0);
  goto L12771;

 L546: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const0_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L547;
    }
 L556: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L557;
    }
  x1 = XEXP (x0, 0);
  goto L12771;

 L547: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (!TARGET_USE_MOV0 || optimize_size)
   && reload_completed)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 80;
    }
  x1 = XEXP (x0, 1);
  goto L556;

 L557: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (TARGET_PENTIUM || optimize_size)
   && reload_completed
   && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) == -1)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 81;
    }
  x1 = XEXP (x0, 0);
  goto L12771;

 L755: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L12997;
 L560: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L561;
    }
  x1 = XEXP (x0, 0);
  goto L12772;

 L12997: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L756;
    case SIGN_EXTEND:
      goto L786;
    case FIX:
      goto L943;
    case PLUS:
      goto L1177;
    default:
     break;
   }
  goto L560;

 L756: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L757;
    }
  goto L560;

 L757: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 114;
    }
 L762: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 115;
    }
  x1 = XEXP (x0, 1);
  goto L560;

 L786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L787;
    }
  goto L560;

 L787: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 118;
    }
  x1 = XEXP (x0, 1);
  goto L560;

 L943: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L944;
    }
  goto L560;

 L944: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && FLOAT_MODE_P (GET_MODE (operands[1]))
   && !reload_completed && !reload_in_progress
   && (!SSE_FLOAT_MODE_P (GET_MODE (operands[1])) || !TARGET_64BIT)))
    {
      return 146;
    }
  x1 = XEXP (x0, 1);
  goto L560;

 L1177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L13002;
  goto L560;

 L13002: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L1196;
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1178;
    }
  goto L560;

 L1196: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LTU)
    goto L1197;
  goto L560;

 L1197: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == CCmode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L1198;
  goto L560;

 L1198: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L1199;
  goto L560;

 L1199: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1200;
    }
  goto L560;

 L1200: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1201;
    }
  goto L560;

 L1201: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 180;
    }
  x1 = XEXP (x0, 1);
  goto L560;

 L1178: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1179;
    }
  goto L560;

 L1179: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 179;
    }
  x1 = XEXP (x0, 1);
  goto L560;

 L561: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 82;
    }
 L565: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 83;
    }
  x1 = XEXP (x0, 0);
  goto L12772;

 L568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (x86_64_movabs_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L569;
    }
  goto L12790;

 L569: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L570;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L570: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_check_movabs (insn, 0)))
    {
      return 84;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L573: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L13003;
 L1298: ATTRIBUTE_UNUSED_LABEL
  if (no_seg_address_operand (x1, DImode))
    {
      operands[1] = x1;
      goto L1299;
    }
 L2135: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == MULT)
    goto L2136;
  x1 = XEXP (x0, 0);
  goto L12790;

 L13003: ATTRIBUTE_UNUSED_LABEL
  tem = recog_5 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1298;

 L1299: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 189;
    }
  x1 = XEXP (x0, 1);
  goto L2135;

 L2136: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L13042;
  x1 = XEXP (x0, 0);
  goto L12790;

 L13042: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L2265;
    case SIGN_EXTEND:
      goto L2301;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13041;
    default:
      x1 = XEXP (x0, 0);
      goto L12790;
   }
 L13041: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2137;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2265: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2266;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2267;
  x1 = XEXP (x0, 0);
  goto L12790;

 L2267: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2268;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2268: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 253;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2301: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2302;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2302: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L2303;
  x1 = XEXP (x0, 0);
  goto L12790;

 L2303: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2304;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2304: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 255;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2137: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2138;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L2138: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 245;
    }
  x1 = XEXP (x0, 0);
  goto L12790;

 L1365: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L13044;
  x1 = XEXP (x0, 0);
  goto L12797;

 L13044: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L1366;
    case MINUS:
      goto L1844;
    case AND:
      goto L2898;
    case IOR:
      goto L3201;
    case XOR:
      goto L3584;
    case NEG:
      goto L4010;
    case NOT:
      goto L4515;
    case ASHIFT:
      goto L4605;
    case ASHIFTRT:
      goto L4826;
    case LSHIFTRT:
      goto L5233;
    case ROTATE:
      goto L5571;
    case ROTATERT:
      goto L5747;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1367;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1367: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1368;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1368: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 196;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1844: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1863;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L1864;
  if (general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1846;
    }
 L1881: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1882;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1864: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LTU)
    goto L1865;
  x1 = XEXP (x0, 0);
  goto L12797;

 L1865: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == CCmode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L1866;
  x1 = XEXP (x0, 0);
  goto L12797;

 L1866: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L1867;
  x1 = XEXP (x0, 0);
  goto L12797;

 L1867: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1868;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1868: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (MINUS, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 226;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L1846: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && ix86_binary_operator_ok (MINUS, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 225;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L1881;

 L1882: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (MINUS, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 227;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L2898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2899;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L2899: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_szext_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L2900;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L2900: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (AND, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 286;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L3201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3202;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L3202: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3203;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L3203: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_binary_operator_ok (IOR, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 303;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L3584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L3585;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L3585: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_general_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L3586;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L3586: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_binary_operator_ok (XOR, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 325;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4010: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (general_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4011;
    }
 L4022: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4023;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4011: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && ix86_unary_operator_ok (NEG, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 349;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L4022;

 L4023: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_unary_operator_ok (NEG, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 350;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4516;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4516: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_unary_operator_ok (NOT, DImode, operands)))
    {
      return 398;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4605: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4606;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4606: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4607;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4607: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 408;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4826: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4827;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4827: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L13056;
 L4855: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4856;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L13056: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L4828;
    }
 L13057: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4842;
    }
  goto L4855;

 L4828: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && INTVAL (operands[2]) == 63 && (TARGET_USE_CLTD || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 423;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L13057;

 L4842: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 424;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L4855;

 L4856: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 425;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5233: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5234;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5234: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5235;
    }
 L5248: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5249;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5235: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 451;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5248;

 L5249: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 452;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5572;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5572: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5573;
    }
 L5586: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5587;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5573: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 475;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5586;

 L5587: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 476;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5747: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5748;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5748: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5749;
    }
 L5762: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5763;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L5749: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 487;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5762;

 L5763: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 488;
    }
  x1 = XEXP (x0, 0);
  goto L12797;

 L4633: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L13058;
  goto ret0;

 L13058: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case ASHIFT:
      goto L4634;
    case ZERO_EXTEND:
      goto L4702;
    case ASHIFTRT:
      goto L4896;
    case LSHIFTRT:
      goto L5289;
    case UNSPEC:
      goto L13065;
    case PLUS:
      goto L6522;
    case IF_THEN_ELSE:
      goto L7477;
    default:
     break;
   }
  goto ret0;

 L4634: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4635;
    }
  goto ret0;

 L4635: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4636;
    }
  goto ret0;

 L4636: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_CMOVE)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 410;
    }
 L4650: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 411;
    }
  goto ret0;

 L4702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode)
    goto L13066;
  goto ret0;

 L13066: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFT:
      goto L4703;
    case ASHIFTRT:
      goto L4965;
    case LSHIFTRT:
      goto L5363;
    case ROTATE:
      goto L5615;
    case ROTATERT:
      goto L5791;
    default:
     break;
   }
  goto ret0;

 L4703: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4704;
    }
  goto ret0;

 L4704: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4705;
    }
  goto ret0;

 L4705: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 414;
    }
  goto ret0;

 L4965: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4966;
    }
  goto ret0;

 L4966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L13071;
 L5026: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5027;
    }
  goto ret0;

 L13071: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L4967;
    }
 L13072: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4997;
    }
  goto L5026;

 L4967: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (TARGET_USE_CLTD || optimize_size)
   && INTVAL (operands[2]) == 31
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 432;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L13072;

 L4997: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 434;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5026;

 L5027: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 436;
    }
  goto ret0;

 L5363: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5364;
    }
  goto ret0;

 L5364: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5365;
    }
  goto ret0;

 L5365: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 460;
    }
  goto ret0;

 L5615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5616;
    }
  goto ret0;

 L5616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5617;
    }
 L5646: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5647;
    }
  goto ret0;

 L5617: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 478;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5646;

 L5647: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 480;
    }
  goto ret0;

 L5791: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5792;
    }
  goto ret0;

 L5792: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5793;
    }
 L5822: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5823;
    }
  goto ret0;

 L5793: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 490;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5822;

 L5823: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 492;
    }
  goto ret0;

 L4896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L4897;
    }
  goto ret0;

 L4897: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L4898;
    }
  goto ret0;

 L4898: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_CMOVE)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 428;
    }
 L4912: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 429;
    }
  goto ret0;

 L5289: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L13074;
  goto ret0;

 L13074: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == ZERO_EXTEND)
    goto L5333;
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5290;
    }
  goto ret0;

 L5333: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5334;
    }
  goto ret0;

 L5334: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5335;
    }
  goto ret0;

 L5335: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 458;
    }
  goto ret0;

 L5290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L5291;
    }
  goto ret0;

 L5291: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_CMOVE)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 455;
    }
 L5305: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 456;
    }
  goto ret0;

 L13065: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 15)
    goto L6493;
  goto ret0;

 L6493: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT))
    {
      return 545;
    }
  goto ret0;

 L6522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 15)
    goto L6523;
  goto ret0;

 L6523: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6524;
  goto ret0;

 L6524: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L6525;
    }
  goto ret0;

 L6525: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 547;
    }
  goto ret0;

 L7477: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LTU)
    goto L7478;
 L7485: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7486;
    }
  goto ret0;

 L7478: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CCmode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7479;
  goto L7485;

 L7479: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7480;
  goto L7485;

 L7480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == -1LL)
    goto L7481;
  x2 = XEXP (x1, 0);
  goto L7485;

 L7481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 636;
    }
  x2 = XEXP (x1, 0);
  goto L7485;

 L7486: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7487;
  goto ret0;

 L7487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7488;
  goto ret0;

 L7488: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L7489;
    }
  goto ret0;

 L7489: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L7490;
    }
  goto ret0;

 L7490: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_CMOVE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 637;
    }
  goto ret0;
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
    case NEG:
      goto L4280;
    case ABS:
      goto L4465;
    case SQRT:
      goto L6751;
    case UNSPEC:
      goto L13096;
    case IF_THEN_ELSE:
      goto L7587;
    case EQ:
    case LT:
    case LE:
    case UNORDERED:
    case NE:
    case UNGE:
    case UNGT:
    case ORDERED:
    case UNEQ:
    case UNLT:
    case UNLE:
    case LTGT:
    case GE:
    case GT:
      goto L13090;
    case PLUS:
    case MINUS:
    case MULT:
    case DIV:
      goto L13091;
    default:
      goto ret0;
   }
 L13090: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x1, SFmode))
    {
      operands[1] = x1;
      goto L5926;
    }
 L13091: ATTRIBUTE_UNUSED_LABEL
  if (binary_fp_operator (x1, SFmode))
    {
      operands[3] = x1;
      goto L6529;
    }
  goto ret0;

 L4280: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4281;
    }
  goto ret0;

 L4281: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && reload_completed))
    {
      return 370;
    }
  goto ret0;

 L4465: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4466;
    }
  goto ret0;

 L4466: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && reload_completed))
    {
      return 389;
    }
  goto ret0;

 L6751: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L13098;
  goto ret0;

 L13098: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L6752;
    }
 L13099: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L6762;
    }
  goto ret0;

 L6752: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387
   && (TARGET_SSE_MATH && TARGET_MIX_SSE_I387)))
    {
      return 582;
    }
 L6757: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE_MATH && (!TARGET_80387 || !TARGET_MIX_SSE_I387)))
    {
      return 583;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L13099;

 L6762: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387
   && !TARGET_SSE_MATH))
    {
      return 584;
    }
  goto ret0;

 L13096: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13100;
  goto ret0;

 L13100: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 21LL:
      goto L6826;
    case 22LL:
      goto L6852;
    default:
      break;
    }
  goto ret0;

 L6826: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L6827;
    }
  goto ret0;

 L6827: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 596;
    }
  goto ret0;

 L6852: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L6853;
    }
  goto ret0;

 L6853: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 601;
    }
  goto ret0;

 L7587: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case LT:
      goto L7588;
    case GT:
      goto L7680;
    default:
     break;
   }
 L7531: ATTRIBUTE_UNUSED_LABEL
  if (fcmov_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7532;
    }
 L7795: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7796;
    }
 L7817: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == EQ)
    goto L7818;
 L7888: ATTRIBUTE_UNUSED_LABEL
  if (fcmov_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7889;
    }
  goto ret0;

 L7588: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode)
    goto L13102;
  goto L7531;

 L13102: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7589;
    }
 L13103: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7608;
    }
 L13104: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7616;
    }
  goto L7531;

 L7589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7590;
    }
  x3 = XEXP (x2, 0);
  goto L13103;

 L7590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7591;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13103;

 L7591: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE && TARGET_IEEE_FP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 646;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13103;

 L7608: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7609;
    }
  x3 = XEXP (x2, 0);
  goto L13104;

 L7609: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7610;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13104;

 L7610: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 647;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13104;

 L7616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7617;
    }
  goto L7531;

 L7617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7618;
  x2 = XEXP (x1, 0);
  goto L7531;

 L7618: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE && reload_completed))
    {
      return 648;
    }
  x2 = XEXP (x1, 0);
  goto L7531;

 L7680: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode)
    goto L13105;
  goto L7531;

 L13105: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7681;
    }
 L13106: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7700;
    }
 L13107: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7708;
    }
  goto L7531;

 L7681: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7682;
    }
  x3 = XEXP (x2, 0);
  goto L13106;

 L7682: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7683;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13106;

 L7683: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE && TARGET_IEEE_FP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 652;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13106;

 L7700: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7701;
    }
  x3 = XEXP (x2, 0);
  goto L13107;

 L7701: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7702;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13107;

 L7702: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 653;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13107;

 L7708: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7709;
    }
  goto L7531;

 L7709: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7710;
  x2 = XEXP (x1, 0);
  goto L7531;

 L7710: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE && reload_completed))
    {
      return 654;
    }
  x2 = XEXP (x1, 0);
  goto L7531;

 L7532: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7533;
  goto L7795;

 L7533: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7534;
  goto L7795;

 L7534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7535;
    }
  x2 = XEXP (x1, 0);
  goto L7795;

 L7535: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L7536;
    }
  x2 = XEXP (x1, 0);
  goto L7795;

 L7536: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_CMOVE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 641;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7795;

 L7796: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode)
    goto L13108;
  goto L7817;

 L13108: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[4] = x3;
      goto L7797;
    }
 L13109: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[4] = x3;
      goto L7872;
    }
  goto L7817;

 L7797: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[5] = x3;
      goto L7798;
    }
  x3 = XEXP (x2, 0);
  goto L13109;

 L7798: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7799;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13109;

 L7799: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L7800;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13109;

 L7800: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)
   && (!TARGET_IEEE_FP
       || (GET_CODE (operands[1]) != EQ && GET_CODE (operands[1]) != NE)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 660;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13109;

 L7872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[5] = x3;
      goto L7873;
    }
  goto L7817;

 L7873: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7874;
    }
  if (const0_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7883;
    }
  x2 = XEXP (x1, 0);
  goto L7817;

 L7874: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const0_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L7875;
    }
  x2 = XEXP (x1, 0);
  goto L7817;

 L7875: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 664;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7817;

 L7883: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L7884;
    }
  x2 = XEXP (x1, 0);
  goto L7817;

 L7884: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 665;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7817;

 L7818: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L7819;
    }
  goto L7888;

 L7819: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[4] = x3;
      goto L7820;
    }
  goto L7888;

 L7820: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L7821;
    }
  x2 = XEXP (x1, 0);
  goto L7888;

 L7821: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7822;
    }
  x2 = XEXP (x1, 0);
  goto L7888;

 L7822: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 661;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7888;

 L7889: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[4] = x3;
      goto L7890;
    }
  goto ret0;

 L7890: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SFmode))
    {
      operands[5] = x3;
      goto L7891;
    }
  goto ret0;

 L7891: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7892;
    }
  if (const0_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L7901;
    }
  goto ret0;

 L7892: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const0_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L7893;
    }
  goto ret0;

 L7893: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 666;
    }
  goto ret0;

 L7901: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L7902;
    }
  goto ret0;

 L7902: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 667;
    }
  goto ret0;

 L5926: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L5927;
    }
  goto ret0;

 L5927: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[3] = x2;
      goto L5928;
    }
  goto ret0;

 L5928: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE && reload_completed))
    {
      return 501;
    }
  goto ret0;

 L6529: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L13112;
  goto ret0;

 L13112: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT)
    goto L6596;
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L6530;
    }
 L13111: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L6590;
    }
  goto ret0;

 L6596: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6597;
    }
  goto ret0;

 L6597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L6598;
    }
  goto ret0;

 L6598: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_USE_FIOP && !TARGET_SSE_MATH))
    {
      return 559;
    }
  goto ret0;

 L6530: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L6531;
    }
  x2 = XEXP (x1, 0);
  goto L13111;

 L6531: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !TARGET_SSE_MATH
   && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 548;
    }
 L6537: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_SSE_MATH && TARGET_MIX_SSE_I387
   && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 549;
    }
 L6543: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE_MATH && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 550;
    }
 L6579: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !TARGET_SSE_MATH
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 556;
    }
 L6585: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_SSE_MATH && TARGET_MIX_SSE_I387
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 557;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L13111;

 L6590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L13114;
  goto ret0;

 L13114: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT)
    goto L6604;
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L6591;
    }
  goto ret0;

 L6604: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6605;
    }
  goto ret0;

 L6605: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_USE_FIOP && !TARGET_SSE_MATH))
    {
      return 560;
    }
  goto ret0;

 L6591: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE_MATH
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'))
    {
      return 558;
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
  switch (GET_CODE (x1))
    {
    case NEG:
      goto L4285;
    case ABS:
      goto L4470;
    case SQRT:
      goto L6766;
    case UNSPEC:
      goto L13135;
    case IF_THEN_ELSE:
      goto L7633;
    case EQ:
    case LT:
    case LE:
    case UNORDERED:
    case NE:
    case UNGE:
    case UNGT:
    case ORDERED:
    case UNEQ:
    case UNLT:
    case UNLE:
    case LTGT:
    case GE:
    case GT:
      goto L13129;
    case PLUS:
    case MINUS:
    case MULT:
    case DIV:
      goto L13130;
    default:
      goto ret0;
   }
 L13129: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x1, DFmode))
    {
      operands[1] = x1;
      goto L5932;
    }
 L13130: ATTRIBUTE_UNUSED_LABEL
  if (binary_fp_operator (x1, DFmode))
    {
      operands[3] = x1;
      goto L6547;
    }
  goto ret0;

 L4285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13138;
  goto ret0;

 L13138: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L4291;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L4286;
    }
  goto ret0;

 L4291: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4292;
    }
  goto ret0;

 L4292: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 372;
    }
  goto ret0;

 L4286: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && reload_completed))
    {
      return 371;
    }
  goto ret0;

 L4470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13140;
  goto ret0;

 L13140: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L4476;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L4471;
    }
  goto ret0;

 L4476: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4477;
    }
  goto ret0;

 L4477: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 391;
    }
  goto ret0;

 L4471: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && reload_completed))
    {
      return 390;
    }
  goto ret0;

 L6766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13143;
  goto ret0;

 L13143: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L6782;
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L6767;
    }
 L13142: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L6777;
    }
  goto ret0;

 L6782: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6783;
    }
  goto ret0;

 L6783: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387
   && !(TARGET_SSE2 && TARGET_SSE_MATH)))
    {
      return 588;
    }
  goto ret0;

 L6767: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387
   && (TARGET_SSE2 && TARGET_SSE_MATH && TARGET_MIX_SSE_I387)))
    {
      return 585;
    }
 L6772: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && TARGET_SSE_MATH && (!TARGET_80387 || !TARGET_MIX_SSE_I387)))
    {
      return 586;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L13142;

 L6777: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387
   && (!TARGET_SSE2 || !TARGET_SSE_MATH)))
    {
      return 587;
    }
  goto ret0;

 L13135: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13144;
  goto ret0;

 L13144: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 21LL:
      goto L6821;
    case 22LL:
      goto L6847;
    default:
      break;
    }
  goto ret0;

 L6821: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13147;
  goto ret0;

 L13147: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L6832;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L6822;
    }
  goto ret0;

 L6832: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6833;
    }
  goto ret0;

 L6833: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 597;
    }
  goto ret0;

 L6822: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 595;
    }
  goto ret0;

 L6847: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13149;
  goto ret0;

 L13149: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L6858;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L6848;
    }
  goto ret0;

 L6858: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6859;
    }
  goto ret0;

 L6859: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 602;
    }
  goto ret0;

 L6848: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 600;
    }
  goto ret0;

 L7633: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case LT:
      goto L7634;
    case GT:
      goto L7726;
    default:
     break;
   }
 L7540: ATTRIBUTE_UNUSED_LABEL
  if (fcmov_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7541;
    }
 L7839: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7840;
    }
 L7861: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == EQ)
    goto L7862;
 L7924: ATTRIBUTE_UNUSED_LABEL
  if (fcmov_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7925;
    }
  goto ret0;

 L7634: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode)
    goto L13150;
  goto L7540;

 L13150: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7635;
    }
 L13151: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7654;
    }
 L13152: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7662;
    }
  goto L7540;

 L7635: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7636;
    }
  x3 = XEXP (x2, 0);
  goto L13151;

 L7636: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7637;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13151;

 L7637: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE2 && TARGET_IEEE_FP && TARGET_SSE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 649;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13151;

 L7654: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7655;
    }
  x3 = XEXP (x2, 0);
  goto L13152;

 L7655: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7656;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13152;

 L7656: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE2 && TARGET_SSE_MATH && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 650;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13152;

 L7662: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7663;
    }
  goto L7540;

 L7663: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7664;
  x2 = XEXP (x1, 0);
  goto L7540;

 L7664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE2 && TARGET_SSE_MATH && reload_completed))
    {
      return 651;
    }
  x2 = XEXP (x1, 0);
  goto L7540;

 L7726: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode)
    goto L13153;
  goto L7540;

 L13153: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7727;
    }
 L13154: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7746;
    }
 L13155: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7754;
    }
  goto L7540;

 L7727: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7728;
    }
  x3 = XEXP (x2, 0);
  goto L13154;

 L7728: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7729;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13154;

 L7729: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE2 && TARGET_SSE_MATH && TARGET_IEEE_FP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 655;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13154;

 L7746: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7747;
    }
  x3 = XEXP (x2, 0);
  goto L13155;

 L7747: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7748;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13155;

 L7748: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE2 && TARGET_SSE_MATH && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 656;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13155;

 L7754: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7755;
    }
  goto L7540;

 L7755: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L7756;
  x2 = XEXP (x1, 0);
  goto L7540;

 L7756: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (rtx_equal_p (x2, operands[2])
      && (TARGET_SSE2 && TARGET_SSE_MATH && reload_completed))
    {
      return 657;
    }
  x2 = XEXP (x1, 0);
  goto L7540;

 L7541: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7542;
  goto L7839;

 L7542: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7543;
  goto L7839;

 L7543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7544;
    }
  x2 = XEXP (x1, 0);
  goto L7839;

 L7544: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7545;
    }
  x2 = XEXP (x1, 0);
  goto L7839;

 L7545: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_CMOVE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 642;
    }
 L7554: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_CMOVE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 643;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7839;

 L7840: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode)
    goto L13156;
  goto L7861;

 L13156: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[4] = x3;
      goto L7841;
    }
 L13157: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[4] = x3;
      goto L7908;
    }
  goto L7861;

 L7841: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[5] = x3;
      goto L7842;
    }
  x3 = XEXP (x2, 0);
  goto L13157;

 L7842: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7843;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13157;

 L7843: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7844;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13157;

 L7844: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)
   && (!TARGET_IEEE_FP
       || (GET_CODE (operands[1]) != EQ && GET_CODE (operands[1]) != NE)))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 662;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13157;

 L7908: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[5] = x3;
      goto L7909;
    }
  goto L7861;

 L7909: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7910;
    }
  if (const0_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7919;
    }
  x2 = XEXP (x1, 0);
  goto L7861;

 L7910: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const0_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7911;
    }
  x2 = XEXP (x1, 0);
  goto L7861;

 L7911: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 668;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7861;

 L7919: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7920;
    }
  x2 = XEXP (x1, 0);
  goto L7861;

 L7920: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 669;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7861;

 L7862: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L7863;
    }
  goto L7924;

 L7863: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[4] = x3;
      goto L7864;
    }
  goto L7924;

 L7864: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L7865;
    }
  x2 = XEXP (x1, 0);
  goto L7924;

 L7865: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7866;
    }
  x2 = XEXP (x1, 0);
  goto L7924;

 L7866: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 663;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L7924;

 L7925: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[4] = x3;
      goto L7926;
    }
  goto ret0;

 L7926: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DFmode))
    {
      operands[5] = x3;
      goto L7927;
    }
  goto ret0;

 L7927: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7928;
    }
  if (const0_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L7937;
    }
  goto ret0;

 L7928: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (const0_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7929;
    }
  goto ret0;

 L7929: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 670;
    }
  goto ret0;

 L7937: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L7938;
    }
  goto ret0;

 L7938: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 671;
    }
  goto ret0;

 L5932: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L5933;
    }
  goto ret0;

 L5933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[3] = x2;
      goto L5934;
    }
  goto ret0;

 L5934: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && reload_completed))
    {
      return 502;
    }
  goto ret0;

 L6547: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13160;
  goto ret0;

 L13160: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L6628;
    case FLOAT_EXTEND:
      goto L6642;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13158;
    default:
      goto L13159;
   }
 L13158: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L6548;
    }
 L13159: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L6622;
    }
  goto ret0;

 L6628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6629;
    }
  goto ret0;

 L6629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L6630;
    }
  goto ret0;

 L6630: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_USE_FIOP && !(TARGET_SSE2 && TARGET_SSE_MATH)))
    {
      return 564;
    }
  goto ret0;

 L6642: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6643;
    }
  goto ret0;

 L6643: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L6644;
    }
  goto ret0;

 L6644: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE2 || !TARGET_SSE_MATH)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 566;
    }
  goto ret0;

 L6548: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L6549;
    }
  x2 = XEXP (x1, 0);
  goto L13159;

 L6549: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE2 || !TARGET_SSE_MATH)
   && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 551;
    }
 L6555: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_SSE_MATH && TARGET_SSE2 && TARGET_MIX_SSE_I387
   && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 552;
    }
 L6561: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && TARGET_SSE_MATH
   && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 553;
    }
 L6611: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE2 || !TARGET_SSE_MATH)
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 561;
    }
 L6617: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_SSE2 && TARGET_SSE_MATH && TARGET_MIX_SSE_I387
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 562;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L13159;

 L6622: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L13163;
  goto ret0;

 L13163: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L6636;
    case FLOAT_EXTEND:
      goto L6650;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13162;
    default:
      goto ret0;
   }
 L13162: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L6623;
    }
  goto ret0;

 L6636: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6637;
    }
  goto ret0;

 L6637: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_USE_FIOP && !(TARGET_SSE2 && TARGET_SSE_MATH)))
    {
      return 565;
    }
  goto ret0;

 L6650: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L6651;
    }
  goto ret0;

 L6651: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !(TARGET_SSE2 && TARGET_SSE_MATH)))
    {
      return 567;
    }
  goto ret0;

 L6623: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && TARGET_SSE_MATH
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'))
    {
      return 563;
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

  x1 = XEXP (x0, 0);
  if (push_operand (x1, XFmode))
    {
      operands[0] = x1;
      goto L627;
    }
 L12780: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, XFmode))
    {
      operands[0] = x1;
      goto L839;
    }
 L12788: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, XFmode))
    {
      operands[0] = x1;
      goto L1138;
    }
  goto ret0;

 L627: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, XFmode))
    {
      operands[1] = x1;
      goto L628;
    }
  x1 = XEXP (x0, 0);
  goto L12780;

 L628: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && optimize_size))
    {
      return 96;
    }
 L636: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && !optimize_size))
    {
      return 98;
    }
  x1 = XEXP (x0, 0);
  goto L12780;

 L839: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == XFmode)
    goto L13165;
 L643: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, XFmode))
    {
      operands[1] = x1;
      goto L644;
    }
  x1 = XEXP (x0, 0);
  goto L12788;

 L13165: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_EXTEND:
      goto L840;
    case NEG:
      goto L4263;
    case ABS:
      goto L4448;
    default:
     break;
   }
  goto L643;

 L840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L13168;
    case DFmode:
      goto L13169;
    default:
      break;
    }
  goto L643;

 L13168: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L841;
    }
  goto L643;

 L841: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 129;
    }
  x1 = XEXP (x0, 1);
  goto L643;

 L13169: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L851;
    }
  goto L643;

 L851: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 131;
    }
  x1 = XEXP (x0, 1);
  goto L643;

 L4263: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L4264;
    }
  goto L643;

 L4264: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (NEG, XFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 368;
    }
  x1 = XEXP (x0, 1);
  goto L643;

 L4448: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L4449;
    }
  goto L643;

 L4449: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (ABS, XFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 387;
    }
  x1 = XEXP (x0, 1);
  goto L643;

 L644: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && optimize_size
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && (reload_in_progress || reload_completed
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], XFmode))))
    {
      return 100;
    }
 L652: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT
   && !optimize_size
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && (reload_in_progress || reload_completed
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], XFmode))))
    {
      return 102;
    }
  x1 = XEXP (x0, 0);
  goto L12788;

 L1138: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == XFmode)
    goto L13170;
  goto ret0;

 L13170: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT:
      goto L1139;
    case NEG:
      goto L4296;
    case ABS:
      goto L4481;
    case SQRT:
      goto L6787;
    case UNSPEC:
      goto L13178;
    case IF_THEN_ELSE:
      goto L7558;
    case PLUS:
    case MINUS:
    case MULT:
    case DIV:
      goto L13173;
    default:
      goto ret0;
   }
 L13173: ATTRIBUTE_UNUSED_LABEL
  if (binary_fp_operator (x1, XFmode))
    {
      operands[3] = x1;
      goto L6565;
    }
  goto ret0;

 L1139: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L13180;
    case SImode:
      goto L13181;
    case DImode:
      goto L13182;
    default:
      break;
    }
  goto ret0;

 L13180: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1140;
    }
  goto ret0;

 L1140: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 173;
    }
  goto ret0;

 L13181: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1150;
    }
  goto ret0;

 L1150: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 175;
    }
  goto ret0;

 L13182: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1160;
    }
  goto ret0;

 L1160: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 177;
    }
  goto ret0;

 L4296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == XFmode)
    goto L13184;
  goto ret0;

 L13184: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L4302;
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L4297;
    }
  goto ret0;

 L4302: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13185;
    case SFmode:
      goto L13186;
    default:
      break;
    }
  goto ret0;

 L13185: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4303;
    }
  goto ret0;

 L4303: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 374;
    }
  goto ret0;

 L13186: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4309;
    }
  goto ret0;

 L4309: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 375;
    }
  goto ret0;

 L4297: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && reload_completed))
    {
      return 373;
    }
  goto ret0;

 L4481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == XFmode)
    goto L13188;
  goto ret0;

 L13188: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L4487;
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L4482;
    }
  goto ret0;

 L4487: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13189;
    case SFmode:
      goto L13190;
    default:
      break;
    }
  goto ret0;

 L13189: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4488;
    }
  goto ret0;

 L4488: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 393;
    }
  goto ret0;

 L13190: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4494;
    }
  goto ret0;

 L4494: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 394;
    }
  goto ret0;

 L4482: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && reload_completed))
    {
      return 392;
    }
  goto ret0;

 L6787: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == XFmode)
    goto L13192;
  goto ret0;

 L13192: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L6798;
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L6788;
    }
  goto ret0;

 L6798: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13193;
    case SFmode:
      goto L13194;
    default:
      break;
    }
  goto ret0;

 L13193: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L6799;
    }
  goto ret0;

 L6799: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && !TARGET_NO_FANCY_MATH_387))
    {
      return 591;
    }
  goto ret0;

 L13194: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6811;
    }
  goto ret0;

 L6811: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && !TARGET_NO_FANCY_MATH_387))
    {
      return 593;
    }
  goto ret0;

 L6788: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && !TARGET_NO_FANCY_MATH_387 
   && (TARGET_IEEE_FP || flag_unsafe_math_optimizations) ))
    {
      return 589;
    }
  goto ret0;

 L13178: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13195;
  goto ret0;

 L13195: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 21LL:
      goto L6837;
    case 22LL:
      goto L6863;
    default:
      break;
    }
  goto ret0;

 L6837: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L6838;
    }
  goto ret0;

 L6838: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && !TARGET_NO_FANCY_MATH_387
   && flag_unsafe_math_optimizations))
    {
      return 598;
    }
  goto ret0;

 L6863: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L6864;
    }
  goto ret0;

 L6864: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && ! TARGET_NO_FANCY_MATH_387 && TARGET_80387
   && flag_unsafe_math_optimizations))
    {
      return 603;
    }
  goto ret0;

 L7558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (fcmov_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7559;
    }
  goto ret0;

 L7559: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7560;
  goto ret0;

 L7560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7561;
  goto ret0;

 L7561: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      operands[2] = x2;
      goto L7562;
    }
  goto ret0;

 L7562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, XFmode))
    {
      operands[3] = x2;
      goto L7563;
    }
  goto ret0;

 L7563: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_CMOVE))
    {
      return 644;
    }
  goto ret0;

 L6565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == XFmode)
    goto L13198;
  goto ret0;

 L13198: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L6668;
    case FLOAT_EXTEND:
      goto L6696;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13197;
    default:
      goto ret0;
   }
 L13197: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L6566;
    }
  goto ret0;

 L6668: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6669;
    }
  goto ret0;

 L6669: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      operands[2] = x2;
      goto L6670;
    }
  goto ret0;

 L6670: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && TARGET_USE_FIOP))
    {
      return 570;
    }
  goto ret0;

 L6696: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SFmode:
      goto L13200;
    case DFmode:
      goto L13201;
    default:
      break;
    }
  goto ret0;

 L13200: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6697;
    }
  goto ret0;

 L6697: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      operands[2] = x2;
      goto L6698;
    }
  goto ret0;

 L6698: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 574;
    }
  goto ret0;

 L13201: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L6725;
    }
  goto ret0;

 L6725: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      operands[2] = x2;
      goto L6726;
    }
  goto ret0;

 L6726: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 578;
    }
  goto ret0;

 L6566: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == XFmode)
    goto L13203;
  goto ret0;

 L13203: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L6683;
    case FLOAT_EXTEND:
      goto L6711;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13202;
    default:
      goto ret0;
   }
 L13202: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      operands[2] = x2;
      goto L6567;
    }
  goto ret0;

 L6683: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6684;
    }
  goto ret0;

 L6684: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387 && TARGET_USE_FIOP))
    {
      return 572;
    }
  goto ret0;

 L6711: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SFmode:
      goto L13205;
    case DFmode:
      goto L13206;
    default:
      break;
    }
  goto ret0;

 L13205: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L6712;
    }
  goto ret0;

 L6712: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 576;
    }
  goto ret0;

 L13206: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L6740;
    }
  goto ret0;

 L6740: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 580;
    }
  goto ret0;

 L6567: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'))
    {
      return 554;
    }
 L6657: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'))
    {
      return 568;
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

  x1 = XEXP (x0, 0);
  if (push_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L631;
    }
 L12781: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L844;
    }
 L12789: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, TFmode))
    {
      operands[0] = x1;
      goto L1143;
    }
  goto ret0;

 L631: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, TFmode))
    {
      operands[1] = x1;
      goto L632;
    }
  x1 = XEXP (x0, 0);
  goto L12781;

 L632: ATTRIBUTE_UNUSED_LABEL
  if ((optimize_size))
    {
      return 97;
    }
 L640: ATTRIBUTE_UNUSED_LABEL
  if ((!optimize_size))
    {
      return 99;
    }
  x1 = XEXP (x0, 0);
  goto L12781;

 L844: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TFmode)
    goto L13207;
 L647: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, TFmode))
    {
      operands[1] = x1;
      goto L648;
    }
  x1 = XEXP (x0, 0);
  goto L12789;

 L13207: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_EXTEND:
      goto L845;
    case NEG:
      goto L4275;
    case ABS:
      goto L4460;
    default:
     break;
   }
  goto L647;

 L845: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L13210;
    case DFmode:
      goto L13211;
    default:
      break;
    }
  goto L647;

 L13210: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L846;
    }
  goto L647;

 L846: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 130;
    }
  x1 = XEXP (x0, 1);
  goto L647;

 L13211: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L856;
    }
  goto L647;

 L856: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 132;
    }
  x1 = XEXP (x0, 1);
  goto L647;

 L4275: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L4276;
    }
  goto L647;

 L4276: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && ix86_unary_operator_ok (NEG, TFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 369;
    }
  x1 = XEXP (x0, 1);
  goto L647;

 L4460: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L4461;
    }
  goto L647;

 L4461: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && ix86_unary_operator_ok (ABS, TFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 388;
    }
  x1 = XEXP (x0, 1);
  goto L647;

 L648: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && optimize_size
   && (reload_in_progress || reload_completed
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || memory_operand (operands[0], TFmode))))
    {
      return 101;
    }
 L656: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && !optimize_size
   && (reload_in_progress || reload_completed
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || memory_operand (operands[0], TFmode))))
    {
      return 103;
    }
  x1 = XEXP (x0, 0);
  goto L12789;

 L1143: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TFmode)
    goto L13212;
  goto ret0;

 L13212: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT:
      goto L1144;
    case NEG:
      goto L4313;
    case ABS:
      goto L4498;
    case SQRT:
      goto L6792;
    case UNSPEC:
      goto L13220;
    case IF_THEN_ELSE:
      goto L7567;
    case PLUS:
    case MINUS:
    case MULT:
    case DIV:
      goto L13215;
    default:
      goto ret0;
   }
 L13215: ATTRIBUTE_UNUSED_LABEL
  if (binary_fp_operator (x1, TFmode))
    {
      operands[3] = x1;
      goto L6571;
    }
  goto ret0;

 L1144: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L13222;
    case SImode:
      goto L13223;
    case DImode:
      goto L13224;
    default:
      break;
    }
  goto ret0;

 L13222: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1145;
    }
  goto ret0;

 L1145: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 174;
    }
  goto ret0;

 L13223: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1155;
    }
  goto ret0;

 L1155: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 176;
    }
  goto ret0;

 L13224: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1165;
    }
  goto ret0;

 L1165: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 178;
    }
  goto ret0;

 L4313: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TFmode)
    goto L13226;
  goto ret0;

 L13226: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L4319;
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L4314;
    }
  goto ret0;

 L4319: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13227;
    case SFmode:
      goto L13228;
    default:
      break;
    }
  goto ret0;

 L13227: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4320;
    }
  goto ret0;

 L4320: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 377;
    }
  goto ret0;

 L13228: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4326;
    }
  goto ret0;

 L4326: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 378;
    }
  goto ret0;

 L4314: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && reload_completed))
    {
      return 376;
    }
  goto ret0;

 L4498: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TFmode)
    goto L13230;
  goto ret0;

 L13230: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L4504;
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L4499;
    }
  goto ret0;

 L4504: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13231;
    case SFmode:
      goto L13232;
    default:
      break;
    }
  goto ret0;

 L13231: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4505;
    }
  goto ret0;

 L4505: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 396;
    }
  goto ret0;

 L13232: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4511;
    }
  goto ret0;

 L4511: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 397;
    }
  goto ret0;

 L4499: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && reload_completed))
    {
      return 395;
    }
  goto ret0;

 L6792: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TFmode)
    goto L13234;
  goto ret0;

 L13234: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == FLOAT_EXTEND)
    goto L6804;
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L6793;
    }
  goto ret0;

 L6804: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13235;
    case SFmode:
      goto L13236;
    default:
      break;
    }
  goto ret0;

 L13235: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L6805;
    }
  goto ret0;

 L6805: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387))
    {
      return 592;
    }
  goto ret0;

 L13236: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6817;
    }
  goto ret0;

 L6817: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387))
    {
      return 594;
    }
  goto ret0;

 L6793: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && (TARGET_IEEE_FP || flag_unsafe_math_optimizations) ))
    {
      return 590;
    }
  goto ret0;

 L13220: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13237;
  goto ret0;

 L13237: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 21LL:
      goto L6842;
    case 22LL:
      goto L6868;
    default:
      break;
    }
  goto ret0;

 L6842: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L6843;
    }
  goto ret0;

 L6843: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 599;
    }
  goto ret0;

 L6868: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L6869;
    }
  goto ret0;

 L6869: ATTRIBUTE_UNUSED_LABEL
  if ((! TARGET_NO_FANCY_MATH_387 && TARGET_80387 
   && flag_unsafe_math_optimizations))
    {
      return 604;
    }
  goto ret0;

 L7567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (fcmov_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L7568;
    }
  goto ret0;

 L7568: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L7569;
  goto ret0;

 L7569: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7570;
  goto ret0;

 L7570: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L7571;
    }
  goto ret0;

 L7571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (register_operand (x2, TFmode))
    {
      operands[3] = x2;
      goto L7572;
    }
  goto ret0;

 L7572: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_CMOVE))
    {
      return 645;
    }
  goto ret0;

 L6571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TFmode)
    goto L13240;
  goto ret0;

 L13240: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L6675;
    case FLOAT_EXTEND:
      goto L6703;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13239;
    default:
      goto ret0;
   }
 L13239: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L6572;
    }
  goto ret0;

 L6675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6676;
    }
  goto ret0;

 L6676: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L6677;
    }
  goto ret0;

 L6677: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_USE_FIOP))
    {
      return 571;
    }
  goto ret0;

 L6703: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SFmode:
      goto L13242;
    case DFmode:
      goto L13243;
    default:
      break;
    }
  goto ret0;

 L13242: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L6704;
    }
  goto ret0;

 L6704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L6705;
    }
  goto ret0;

 L6705: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 575;
    }
  goto ret0;

 L13243: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L6732;
    }
  goto ret0;

 L6732: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L6733;
    }
  goto ret0;

 L6733: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 579;
    }
  goto ret0;

 L6572: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TFmode)
    goto L13245;
  goto ret0;

 L13245: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT:
      goto L6690;
    case FLOAT_EXTEND:
      goto L6718;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13244;
    default:
      goto ret0;
   }
 L13244: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TFmode))
    {
      operands[2] = x2;
      goto L6573;
    }
  goto ret0;

 L6690: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6691;
    }
  goto ret0;

 L6691: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_USE_FIOP))
    {
      return 573;
    }
  goto ret0;

 L6718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SFmode:
      goto L13247;
    case DFmode:
      goto L13248;
    default:
      break;
    }
  goto ret0;

 L13247: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L6719;
    }
  goto ret0;

 L6719: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 577;
    }
  goto ret0;

 L13248: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L6747;
    }
  goto ret0;

 L6747: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 581;
    }
  goto ret0;

 L6573: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && GET_RTX_CLASS (GET_CODE (operands[3])) == 'c'))
    {
      return 555;
    }
 L6663: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && GET_RTX_CLASS (GET_CODE (operands[3])) != 'c'))
    {
      return 569;
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

  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L13278;
    case SImode:
      goto L13279;
    case HImode:
      goto L13282;
    case QImode:
      goto L13285;
    default:
      break;
    }
  goto ret0;

 L13278: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1429;
    case AND:
      goto L2802;
    case ZERO_EXTRACT:
      goto L2883;
    case IOR:
      goto L3232;
    case XOR:
      goto L3615;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13277;
    default:
      goto ret0;
   }
 L13277: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1412;
    }
  goto ret0;

 L1429: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1430;
    }
  goto ret0;

 L1430: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1431;
    }
  goto ret0;

 L1431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT
   && ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 200;
    }
  goto ret0;

 L2802: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L2803;
    }
  goto ret0;

 L2803: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_szext_nonmemory_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2804;
    }
  goto ret0;

 L2804: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 276;
    }
  goto ret0;

 L2883: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2884;
    }
  goto ret0;

 L2884: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2885;
    }
  goto ret0;

 L2885: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (const_int_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2886;
    }
  goto ret0;

 L2886: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   /* The code below cannot deal with constants outside HOST_WIDE_INT.  */
   && INTVAL (operands[1]) + INTVAL (operands[2]) < HOST_BITS_PER_WIDE_INT
   /* Ensure that resulting mask is zero or sign extended operand.  */
   && (INTVAL (operands[1]) + INTVAL (operands[2]) <= 32
       || (INTVAL (operands[1]) + INTVAL (operands[2]) == 64
	   && INTVAL (operands[1]) > 32))
   && (GET_MODE (operands[0]) == SImode
       || GET_MODE (operands[0]) == DImode
       || GET_MODE (operands[0]) == HImode
       || GET_MODE (operands[0]) == QImode)))
    {
      return 285;
    }
  goto ret0;

 L3232: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3233;
    }
  goto ret0;

 L3233: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3234;
    }
  goto ret0;

 L3234: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 305;
    }
  goto ret0;

 L3615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3616;
    }
  goto ret0;

 L3616: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3617;
    }
  goto ret0;

 L3617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, DImode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 327;
    }
  goto ret0;

 L1412: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_immediate_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L1413;
    }
  goto ret0;

 L1413: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   &&  ix86_match_ccmode (insn, CCGCmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 199;
    }
  goto ret0;

 L13279: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L1503;
    case PLUS:
      goto L1549;
    case AND:
      goto L2809;
    case ZERO_EXTRACT:
      goto L2875;
    case IOR:
      goto L3337;
    case XOR:
      goto L3720;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13280;
    default:
      goto ret0;
   }
 L13280: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1532;
    }
  goto ret0;

 L1503: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1504;
    }
  goto ret0;

 L1504: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1505;
    }
  goto ret0;

 L1505: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 205;
    }
  goto ret0;

 L1549: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1550;
    }
  goto ret0;

 L1550: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1551;
    }
  goto ret0;

 L1551: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 208;
    }
  goto ret0;

 L2809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L13303;
  goto ret0;

 L13303: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == ZERO_EXTRACT)
    goto L2831;
  if (nonimmediate_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L2810;
    }
  goto ret0;

 L2831: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[0] = x4;
      goto L2832;
    }
  goto ret0;

 L2832: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L2833;
  goto ret0;

 L2833: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L2844;
  goto ret0;

 L2844: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L13304;
 L2834: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L2835;
    }
  goto ret0;

 L13304: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2845;
    case ZERO_EXTRACT:
      goto L2867;
    default:
     break;
   }
  goto L2834;

 L2845: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L13306;
  goto L2834;

 L13306: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L2846;
    }
 L13307: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L2857;
    }
  goto L2834;

 L2846: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 281;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L13307;

 L2857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 282;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L2834;

 L2867: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L2868;
    }
  goto L2834;

 L2868: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L2869;
  goto L2834;

 L2869: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L2870;
  goto L2834;

 L2870: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)))
    {
      return 283;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L2834;

 L2835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)))
    {
      return 280;
    }
  goto ret0;

 L2810: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2811;
    }
  goto ret0;

 L2811: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)))
    {
      return 277;
    }
  goto ret0;

 L2875: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L2876;
    }
  goto ret0;

 L2876: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2877;
    }
  goto ret0;

 L2877: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2878;
    }
  goto ret0;

 L2878: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_MODE (operands[0]) == SImode
       || (TARGET_64BIT && GET_MODE (operands[0]) == DImode)
       || GET_MODE (operands[0]) == HImode
       || GET_MODE (operands[0]) == QImode)))
    {
      return 284;
    }
  goto ret0;

 L3337: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3338;
    }
  goto ret0;

 L3338: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3339;
    }
  goto ret0;

 L3339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 312;
    }
  goto ret0;

 L3720: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3721;
    }
  goto ret0;

 L3721: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3722;
    }
  goto ret0;

 L3722: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 334;
    }
  goto ret0;

 L1532: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L1533;
    }
  goto ret0;

 L1533: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffffffff) != 0x80000000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 207;
    }
  goto ret0;

 L13282: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L1607;
    case PLUS:
      goto L1640;
    case AND:
      goto L2816;
    case IOR:
      goto L3382;
    case XOR:
      goto L3765;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13283;
    default:
      goto ret0;
   }
 L13283: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1623;
    }
  goto ret0;

 L1607: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L1608;
    }
  goto ret0;

 L1608: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1609;
    }
  goto ret0;

 L1609: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 212;
    }
  goto ret0;

 L1640: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L1641;
    }
  goto ret0;

 L1641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L1642;
    }
  goto ret0;

 L1642: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 214;
    }
  goto ret0;

 L2816: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[0] = x3;
      goto L2817;
    }
  goto ret0;

 L2817: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2818;
    }
  goto ret0;

 L2818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)))
    {
      return 278;
    }
  goto ret0;

 L3382: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L3383;
    }
  goto ret0;

 L3383: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L3384;
    }
  goto ret0;

 L3384: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 315;
    }
  goto ret0;

 L3765: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L3766;
    }
  goto ret0;

 L3766: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L3767;
    }
  goto ret0;

 L3767: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 337;
    }
  goto ret0;

 L1623: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L1624;
    }
  goto ret0;

 L1624: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffff) != 0x8000)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 213;
    }
  goto ret0;

 L13285: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L1714;
    case PLUS:
      goto L1747;
    case AND:
      goto L2823;
    case IOR:
      goto L3457;
    case XOR:
      goto L3953;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13286;
    default:
      goto ret0;
   }
 L13286: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1730;
    }
  goto ret0;

 L1714: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1715;
    }
  goto ret0;

 L1715: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1716;
    }
  goto ret0;

 L1716: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 219;
    }
  goto ret0;

 L1747: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L1748;
    }
  goto ret0;

 L1748: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1749;
    }
  goto ret0;

 L1749: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 221;
    }
  goto ret0;

 L2823: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[0] = x3;
      goto L2824;
    }
  goto ret0;

 L2824: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L2825;
    }
  goto ret0;

 L2825: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)))
    {
      return 279;
    }
  goto ret0;

 L3457: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3458;
    }
  goto ret0;

 L3458: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3459;
    }
  goto ret0;

 L3459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 320;
    }
  goto ret0;

 L3953: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3954;
    }
  goto ret0;

 L3954: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3955;
    }
  goto ret0;

 L3955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 346;
    }
  goto ret0;

 L1730: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L1731;
    }
  goto ret0;

 L1731: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xff) != 0x80)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 220;
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

  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case VEC_DUPLICATE:
      goto L8261;
    case PLUS:
      goto L8293;
    case MINUS:
      goto L8307;
    case MULT:
      goto L8321;
    case DIV:
      goto L8335;
    case UNSPEC:
      goto L13357;
    case SQRT:
      goto L8372;
    case VEC_SELECT:
      goto L8607;
    case SMAX:
      goto L8649;
    case SMIN:
      goto L8663;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13345;
    default:
      goto ret0;
   }
 L13345: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8225;
    }
  goto ret0;

 L8261: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (memory_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L8262;
    }
  goto ret0;

 L8262: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8263;
    }
  goto ret0;

 L8263: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 727;
    }
  goto ret0;

 L8293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8294;
    }
  goto ret0;

 L8294: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8295;
    }
  goto ret0;

 L8295: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L8296;
  goto ret0;

 L8296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 732;
    }
  goto ret0;

 L8307: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8308;
    }
  goto ret0;

 L8308: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8309;
    }
  goto ret0;

 L8309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L8310;
  goto ret0;

 L8310: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 734;
    }
  goto ret0;

 L8321: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8322;
    }
  goto ret0;

 L8322: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8323;
    }
  goto ret0;

 L8323: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L8324;
  goto ret0;

 L8324: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 736;
    }
  goto ret0;

 L8335: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8336;
    }
  goto ret0;

 L8336: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8337;
    }
  goto ret0;

 L8337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L8338;
  goto ret0;

 L8338: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 738;
    }
  goto ret0;

 L13357: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1)
    goto L13359;
  goto ret0;

 L13359: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x2, 1))
    {
    case 42LL:
      goto L8348;
    case 43LL:
      goto L8360;
    default:
      break;
    }
  goto ret0;

 L8348: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8349;
    }
  goto ret0;

 L8349: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8350;
    }
  goto ret0;

 L8350: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 740;
    }
  goto ret0;

 L8360: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8361;
    }
  goto ret0;

 L8361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8362;
    }
  goto ret0;

 L8362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 742;
    }
  goto ret0;

 L8372: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8373;
    }
  goto ret0;

 L8373: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8374;
    }
  goto ret0;

 L8374: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 744;
    }
  goto ret0;

 L8607: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8608;
    }
  goto ret0;

 L8608: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L8609;
  goto ret0;

 L8609: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13361;
  goto ret0;

 L13361: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 2LL:
        goto L8610;
      case 0LL:
        goto L8628;
      default:
        break;
      }
  goto ret0;

 L8610: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L8611;
  goto ret0;

 L8611: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L8612;
  goto ret0;

 L8612: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8613;
  goto ret0;

 L8613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8614;
  goto ret0;

 L8614: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8615;
    }
  goto ret0;

 L8615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L8616;
  goto ret0;

 L8616: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L8617;
  goto ret0;

 L8617: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L8618;
  goto ret0;

 L8618: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8619;
  goto ret0;

 L8619: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L8620;
  goto ret0;

 L8620: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 5LL
      && (TARGET_SSE))
    {
      return 777;
    }
  goto ret0;

 L8628: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L8629;
  goto ret0;

 L8629: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8630;
  goto ret0;

 L8630: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L8631;
  goto ret0;

 L8631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8632;
  goto ret0;

 L8632: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8633;
    }
  goto ret0;

 L8633: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L8634;
  goto ret0;

 L8634: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L8635;
  goto ret0;

 L8635: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L8636;
  goto ret0;

 L8636: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L8637;
  goto ret0;

 L8637: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8638;
  goto ret0;

 L8638: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 5LL
      && (TARGET_SSE))
    {
      return 778;
    }
  goto ret0;

 L8649: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8650;
    }
  goto ret0;

 L8650: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8651;
    }
  goto ret0;

 L8651: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L8652;
  goto ret0;

 L8652: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 780;
    }
  goto ret0;

 L8663: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8664;
    }
  goto ret0;

 L8664: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8665;
    }
  goto ret0;

 L8665: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L8666;
  goto ret0;

 L8666: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 782;
    }
  goto ret0;

 L8225: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SFmode)
    goto L13363;
  goto ret0;

 L13363: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case VEC_SELECT:
      goto L8226;
    case VEC_DUPLICATE:
      goto L8672;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13364;
    default:
      goto ret0;
   }
 L13364: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8269;
    }
  goto ret0;

 L8226: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8227;
    }
  goto ret0;

 L8227: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L8228;
  goto ret0;

 L8228: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L8229;
  goto ret0;

 L8229: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L8230;
  goto ret0;

 L8230: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L8231;
  goto ret0;

 L8231: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8232;
  goto ret0;

 L8232: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT)
    goto L13366;
  goto ret0;

 L13366: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x2, 0) == XWINT (x2, 0))
    switch ((int) XWINT (x2, 0))
      {
      case 3LL:
        goto L13368;
      case 12LL:
        goto L13369;
      default:
        break;
      }
  goto ret0;

 L13368: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 723;
    }
  goto ret0;

 L13369: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 724;
    }
  goto ret0;

 L8672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case V2SFmode:
      goto L13370;
    case SFmode:
      goto L13371;
    default:
      break;
    }
  goto ret0;

 L13370: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == FLOAT)
    goto L8673;
  goto ret0;

 L8673: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V2SImode))
    {
      operands[2] = x4;
      goto L8674;
    }
  goto ret0;

 L8674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 12LL
      && (TARGET_SSE))
    {
      return 783;
    }
  goto ret0;

 L13371: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == FLOAT)
    goto L8697;
  goto ret0;

 L8697: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13372;
    case DImode:
      goto L13373;
    default:
      break;
    }
  goto ret0;

 L13372: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L8698;
    }
  goto ret0;

 L8698: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 14LL
      && (TARGET_SSE))
    {
      return 786;
    }
  goto ret0;

 L13373: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L8706;
    }
  goto ret0;

 L8706: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 14LL
      && (TARGET_SSE && TARGET_64BIT))
    {
      return 787;
    }
  goto ret0;

 L8269: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 728;
    }
  goto ret0;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L8738;
    case SS_PLUS:
      goto L8763;
    case US_PLUS:
      goto L8775;
    case MINUS:
      goto L8787;
    case SS_MINUS:
      goto L8812;
    case US_MINUS:
      goto L8824;
    case ASHIFTRT:
      goto L8924;
    case EQ:
      goto L8983;
    case GT:
      goto L9001;
    case UMAX:
      goto L9019;
    case UMIN:
      goto L9031;
    case VEC_CONCAT:
      goto L9093;
    case VEC_MERGE:
      goto L9117;
    default:
     break;
   }
  goto ret0;

 L8738: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8739;
    }
  goto ret0;

 L8739: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8740;
    }
  goto ret0;

 L8740: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 792;
    }
  goto ret0;

 L8763: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8764;
    }
  goto ret0;

 L8764: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8765;
    }
  goto ret0;

 L8765: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 796;
    }
  goto ret0;

 L8775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8776;
    }
  goto ret0;

 L8776: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8777;
    }
  goto ret0;

 L8777: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 798;
    }
  goto ret0;

 L8787: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8788;
    }
  goto ret0;

 L8788: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8789;
    }
  goto ret0;

 L8789: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 800;
    }
  goto ret0;

 L8812: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8813;
    }
  goto ret0;

 L8813: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8814;
    }
  goto ret0;

 L8814: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 804;
    }
  goto ret0;

 L8824: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8825;
    }
  goto ret0;

 L8825: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8826;
    }
  goto ret0;

 L8826: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 806;
    }
  goto ret0;

 L8924: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8QImode
      && GET_CODE (x2) == PLUS)
    goto L8925;
  goto ret0;

 L8925: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V8QImode
      && GET_CODE (x3) == PLUS)
    goto L8926;
  goto ret0;

 L8926: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V8QImode))
    {
      operands[1] = x4;
      goto L8927;
    }
  goto ret0;

 L8927: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, V8QImode))
    {
      operands[2] = x4;
      goto L8928;
    }
  goto ret0;

 L8928: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V8QImode
      && GET_CODE (x3) == CONST_VECTOR
      && XVECLEN (x3, 0) == 8)
    goto L8929;
  goto ret0;

 L8929: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8930;
  goto ret0;

 L8930: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8931;
  goto ret0;

 L8931: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8932;
  goto ret0;

 L8932: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8933;
  goto ret0;

 L8933: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8934;
  goto ret0;

 L8934: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8935;
  goto ret0;

 L8935: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8936;
  goto ret0;

 L8936: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8937;
  goto ret0;

 L8937: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE || TARGET_3DNOW_A))
    {
      return 817;
    }
  goto ret0;

 L8983: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8984;
    }
  goto ret0;

 L8984: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8985;
    }
  goto ret0;

 L8985: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 823;
    }
  goto ret0;

 L9001: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L9002;
    }
  goto ret0;

 L9002: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L9003;
    }
  goto ret0;

 L9003: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 826;
    }
  goto ret0;

 L9019: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L9020;
    }
  goto ret0;

 L9020: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L9021;
    }
  goto ret0;

 L9021: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 829;
    }
  goto ret0;

 L9031: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L9032;
    }
  goto ret0;

 L9032: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L9033;
    }
  goto ret0;

 L9033: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 831;
    }
  goto ret0;

 L9093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4QImode)
    goto L13403;
  goto ret0;

 L13403: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SS_TRUNCATE:
      goto L9094;
    case US_TRUNCATE:
      goto L9110;
    default:
     break;
   }
  goto ret0;

 L9094: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[1] = x3;
      goto L9095;
    }
  goto ret0;

 L9095: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4QImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L9096;
  goto ret0;

 L9096: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[2] = x3;
      goto L9097;
    }
  goto ret0;

 L9097: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 841;
    }
  goto ret0;

 L9110: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[1] = x3;
      goto L9111;
    }
  goto ret0;

 L9111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4QImode
      && GET_CODE (x2) == US_TRUNCATE)
    goto L9112;
  goto ret0;

 L9112: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[2] = x3;
      goto L9113;
    }
  goto ret0;

 L9113: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 843;
    }
  goto ret0;

 L9117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9118;
  goto ret0;

 L9118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8QImode))
    {
      operands[1] = x3;
      goto L9119;
    }
  goto ret0;

 L9119: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L9120;
  goto ret0;

 L9120: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13405;
  goto ret0;

 L13405: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 4LL:
        goto L9121;
      case 0LL:
        goto L9175;
      default:
        break;
      }
  goto ret0;

 L9121: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9122;
  goto ret0;

 L9122: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L9123;
  goto ret0;

 L9123: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9124;
  goto ret0;

 L9124: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L9125;
  goto ret0;

 L9125: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9126;
  goto ret0;

 L9126: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L9127;
  goto ret0;

 L9127: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9128;
  goto ret0;

 L9128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9129;
  goto ret0;

 L9129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8QImode))
    {
      operands[2] = x3;
      goto L9130;
    }
  goto ret0;

 L9130: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L9131;
  goto ret0;

 L9131: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9132;
  goto ret0;

 L9132: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L9133;
  goto ret0;

 L9133: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9134;
  goto ret0;

 L9134: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L9135;
  goto ret0;

 L9135: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9136;
  goto ret0;

 L9136: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L9137;
  goto ret0;

 L9137: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9138;
  goto ret0;

 L9138: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L9139;
  goto ret0;

 L9139: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 85LL
      && (TARGET_MMX))
    {
      return 844;
    }
  goto ret0;

 L9175: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L9176;
  goto ret0;

 L9176: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9177;
  goto ret0;

 L9177: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L9178;
  goto ret0;

 L9178: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9179;
  goto ret0;

 L9179: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L9180;
  goto ret0;

 L9180: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9181;
  goto ret0;

 L9181: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L9182;
  goto ret0;

 L9182: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9183;
  goto ret0;

 L9183: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8QImode))
    {
      operands[2] = x3;
      goto L9184;
    }
  goto ret0;

 L9184: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L9185;
  goto ret0;

 L9185: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L9186;
  goto ret0;

 L9186: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9187;
  goto ret0;

 L9187: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L9188;
  goto ret0;

 L9188: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9189;
  goto ret0;

 L9189: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L9190;
  goto ret0;

 L9190: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9191;
  goto ret0;

 L9191: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L9192;
  goto ret0;

 L9192: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9193;
  goto ret0;

 L9193: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 85LL
      && (TARGET_MMX))
    {
      return 847;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L8744;
    case SS_PLUS:
      goto L8769;
    case US_PLUS:
      goto L8781;
    case MINUS:
      goto L8793;
    case SS_MINUS:
      goto L8818;
    case US_MINUS:
      goto L8830;
    case MULT:
      goto L8836;
    case TRUNCATE:
      goto L8842;
    case ASHIFTRT:
      goto L8941;
    case VEC_MERGE:
      goto L8960;
    case UNSPEC:
      goto L13425;
    case EQ:
      goto L8989;
    case GT:
      goto L9007;
    case SMAX:
      goto L9025;
    case SMIN:
      goto L9037;
    case LSHIFTRT:
      goto L9055;
    case ASHIFT:
      goto L9074;
    case VEC_CONCAT:
      goto L9101;
    default:
     break;
   }
  goto ret0;

 L8744: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8745;
    }
  goto ret0;

 L8745: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8746;
    }
  goto ret0;

 L8746: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 793;
    }
  goto ret0;

 L8769: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8770;
    }
  goto ret0;

 L8770: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8771;
    }
  goto ret0;

 L8771: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 797;
    }
  goto ret0;

 L8781: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8782;
    }
  goto ret0;

 L8782: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8783;
    }
  goto ret0;

 L8783: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 799;
    }
  goto ret0;

 L8793: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8794;
    }
  goto ret0;

 L8794: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8795;
    }
  goto ret0;

 L8795: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 801;
    }
  goto ret0;

 L8818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8819;
    }
  goto ret0;

 L8819: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8820;
    }
  goto ret0;

 L8820: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 805;
    }
  goto ret0;

 L8830: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8831;
    }
  goto ret0;

 L8831: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8832;
    }
  goto ret0;

 L8832: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 807;
    }
  goto ret0;

 L8836: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8837;
    }
  goto ret0;

 L8837: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8838;
    }
  goto ret0;

 L8838: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 808;
    }
  goto ret0;

 L8842: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L8843;
  goto ret0;

 L8843: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V4SImode
      && GET_CODE (x3) == MULT)
    goto L8844;
  goto ret0;

 L8844: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V4SImode)
    goto L13426;
  goto ret0;

 L13426: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L8845;
    case ZERO_EXTEND:
      goto L8855;
    default:
     break;
   }
  goto ret0;

 L8845: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, V4HImode))
    {
      operands[1] = x5;
      goto L8846;
    }
  goto ret0;

 L8846: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == V4SImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L8847;
  goto ret0;

 L8847: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V4HImode))
    {
      operands[2] = x5;
      goto L8848;
    }
  goto ret0;

 L8848: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 16LL
      && (TARGET_MMX))
    {
      return 809;
    }
  goto ret0;

 L8855: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, V4HImode))
    {
      operands[1] = x5;
      goto L8856;
    }
  goto ret0;

 L8856: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == V4SImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L8857;
  goto ret0;

 L8857: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V4HImode))
    {
      operands[2] = x5;
      goto L8858;
    }
  goto ret0;

 L8858: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 16LL
      && (TARGET_SSE || TARGET_3DNOW_A))
    {
      return 810;
    }
  goto ret0;

 L8941: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4HImode)
    goto L13428;
  goto ret0;

 L13428: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L8942;
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L9044;
    }
  goto ret0;

 L8942: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V4HImode
      && GET_CODE (x3) == PLUS)
    goto L8943;
  goto ret0;

 L8943: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V4HImode))
    {
      operands[1] = x4;
      goto L8944;
    }
  goto ret0;

 L8944: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, V4HImode))
    {
      operands[2] = x4;
      goto L8945;
    }
  goto ret0;

 L8945: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V4HImode
      && GET_CODE (x3) == CONST_VECTOR
      && XVECLEN (x3, 0) == 4)
    goto L8946;
  goto ret0;

 L8946: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8947;
  goto ret0;

 L8947: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8948;
  goto ret0;

 L8948: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8949;
  goto ret0;

 L8949: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L8950;
  goto ret0;

 L8950: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE || TARGET_3DNOW_A))
    {
      return 818;
    }
  goto ret0;

 L9044: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9045;
    }
  goto ret0;

 L9045: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 833;
    }
  goto ret0;

 L8960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4HImode)
    goto L13431;
  goto ret0;

 L13431: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L9144;
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8961;
    }
  goto ret0;

 L9144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[1] = x3;
      goto L9145;
    }
  goto ret0;

 L9145: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L9146;
  goto ret0;

 L9146: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13432;
  goto ret0;

 L13432: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 0LL:
        goto L9147;
      case 2LL:
        goto L9201;
      default:
        break;
      }
  goto ret0;

 L9147: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9148;
  goto ret0;

 L9148: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9149;
  goto ret0;

 L9149: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9150;
  goto ret0;

 L9150: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9151;
  goto ret0;

 L9151: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[2] = x3;
      goto L9152;
    }
  goto ret0;

 L9152: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L9153;
  goto ret0;

 L9153: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9154;
  goto ret0;

 L9154: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9155;
  goto ret0;

 L9155: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9156;
  goto ret0;

 L9156: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9157;
  goto ret0;

 L9157: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 5LL
      && (TARGET_MMX))
    {
      return 845;
    }
  goto ret0;

 L9201: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9202;
  goto ret0;

 L9202: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9203;
  goto ret0;

 L9203: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9204;
  goto ret0;

 L9204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9205;
  goto ret0;

 L9205: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[2] = x3;
      goto L9206;
    }
  goto ret0;

 L9206: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L9207;
  goto ret0;

 L9207: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9208;
  goto ret0;

 L9208: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L9209;
  goto ret0;

 L9209: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9210;
  goto ret0;

 L9210: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L9211;
  goto ret0;

 L9211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 5LL
      && (TARGET_MMX))
    {
      return 848;
    }
  goto ret0;

 L8961: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4HImode
      && GET_CODE (x2) == VEC_DUPLICATE)
    goto L8962;
  goto ret0;

 L8962: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == TRUNCATE)
    goto L8963;
  goto ret0;

 L8963: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L8964;
    }
  goto ret0;

 L8964: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L8965;
    }
  goto ret0;

 L8965: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 820;
    }
  goto ret0;

 L13425: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 41)
    goto L8977;
  goto ret0;

 L8977: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8978;
    }
  goto ret0;

 L8978: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L8979;
    }
  goto ret0;

 L8979: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 822;
    }
  goto ret0;

 L8989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L8990;
    }
  goto ret0;

 L8990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L8991;
    }
  goto ret0;

 L8991: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 824;
    }
  goto ret0;

 L9007: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L9008;
    }
  goto ret0;

 L9008: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L9009;
    }
  goto ret0;

 L9009: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 827;
    }
  goto ret0;

 L9025: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L9026;
    }
  goto ret0;

 L9026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L9027;
    }
  goto ret0;

 L9027: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 830;
    }
  goto ret0;

 L9037: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L9038;
    }
  goto ret0;

 L9038: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4HImode))
    {
      operands[2] = x2;
      goto L9039;
    }
  goto ret0;

 L9039: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 832;
    }
  goto ret0;

 L9055: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L9056;
    }
  goto ret0;

 L9056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9057;
    }
  goto ret0;

 L9057: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 835;
    }
  goto ret0;

 L9074: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4HImode))
    {
      operands[1] = x2;
      goto L9075;
    }
  goto ret0;

 L9075: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9076;
    }
  goto ret0;

 L9076: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 838;
    }
  goto ret0;

 L9101: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2HImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L9102;
  goto ret0;

 L9102: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SImode))
    {
      operands[1] = x3;
      goto L9103;
    }
  goto ret0;

 L9103: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2HImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L9104;
  goto ret0;

 L9104: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SImode))
    {
      operands[2] = x3;
      goto L9105;
    }
  goto ret0;

 L9105: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 842;
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

  x1 = XEXP (x0, 0);
  switch (GET_CODE (x1))
    {
    case MEM:
      goto L13450;
    case SUBREG:
      goto L13451;
    default:
     break;
   }
 L12823: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L8171;
    }
 L12831: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L8493;
    }
  goto ret0;

 L13450: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L8127;
    }
  goto L12823;

 L8127: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (nonmemory_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L8128;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8128: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 702;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L13451: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L8377;
  goto L12823;

 L8377: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case V4SFmode:
      goto L13452;
    case SFmode:
      goto L13453;
    case V2DFmode:
      goto L13454;
    case DFmode:
      goto L13455;
    default:
      break;
    }
  goto L12823;

 L13452: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4SFmode))
    {
      operands[0] = x2;
      goto L8378;
    }
  goto L12823;

 L8378: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode)
    goto L13456;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13456: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L8379;
    case IOR:
      goto L8409;
    case XOR:
      goto L8423;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L13460;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13460: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8394;
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8380;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8394: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L8395;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8395: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8396;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8396: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 747;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8380: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8381;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8381: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 745;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8409: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8410;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8410: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8411;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8411: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 749;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8423: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8424;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8425;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8425: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 751;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L13453: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L8385;
    }
  goto L12823;

 L8385: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode)
    goto L13461;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13461: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L8386;
    case IOR:
      goto L8416;
    case XOR:
      goto L8430;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L13465;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13465: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8402;
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8387;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8402: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L8403;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8404;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8404: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 748;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8387: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8388;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8388: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 746;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8416: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8417;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8417: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8418;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8418: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 750;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8430: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8431;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8431: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8432;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8432: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 752;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L13454: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2DFmode))
    {
      operands[0] = x2;
      goto L8436;
    }
  goto L12823;

 L8436: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode)
    goto L13466;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13466: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L8437;
    case IOR:
      goto L8467;
    case XOR:
      goto L8481;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L13470;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13470: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8452;
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8438;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8452: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L8453;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8453: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8454;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8454: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 755;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8438: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8439;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8439: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 753;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8467: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8468;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8468: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8469;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8469: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 757;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8482;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8482: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8483;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8483: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 759;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L13455: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L8443;
    }
  goto L12823;

 L8443: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode)
    goto L13471;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13471: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L8444;
    case IOR:
      goto L8474;
    case XOR:
      goto L8488;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8444: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L13475;
  x1 = XEXP (x0, 0);
  goto L12823;

 L13475: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8460;
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8445;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8460: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L8461;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8461: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8462;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8462: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 756;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8446;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8446: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 754;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8474: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8475;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8475: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8476;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8476: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 758;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8488: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8489;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8489: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8490;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8490: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 760;
    }
  x1 = XEXP (x0, 0);
  goto L12823;

 L8171: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L8172;
    }
 L8175: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, TImode))
    {
      operands[1] = x1;
      goto L8176;
    }
  x1 = XEXP (x0, 0);
  goto L12831;

 L8172: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE && !TARGET_64BIT
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 713;
    }
  x1 = XEXP (x0, 1);
  goto L8175;

 L8176: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 714;
    }
  x1 = XEXP (x0, 0);
  goto L12831;

 L8493: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode)
    goto L13476;
  goto ret0;

 L13476: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L8494;
    case IOR:
      goto L8520;
    case XOR:
      goto L8532;
    default:
     break;
   }
  goto ret0;

 L8494: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L13480;
  goto ret0;

 L13480: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8507;
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8495;
    }
  goto ret0;

 L8507: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L8508;
    }
  goto ret0;

 L8508: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8509;
    }
  goto ret0;

 L8509: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 763;
    }
  goto ret0;

 L8495: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8496;
    }
  goto ret0;

 L8496: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 761;
    }
  goto ret0;

 L8520: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8521;
    }
  goto ret0;

 L8521: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8522;
    }
  goto ret0;

 L8522: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 765;
    }
  goto ret0;

 L8532: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[1] = x2;
      goto L8533;
    }
  goto ret0;

 L8533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L8534;
    }
  goto ret0;

 L8534: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 767;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L9296;
    case MINUS:
      goto L9302;
    case SMAX:
      goto L9332;
    case SMIN:
      goto L9338;
    case MULT:
      goto L9344;
    case VEC_CONCAT:
      goto L9399;
    case FLOAT:
      goto L9462;
    case UNSPEC:
      goto L13522;
    case VEC_SELECT:
      goto L9540;
    default:
     break;
   }
  goto ret0;

 L9296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9297;
    }
  goto ret0;

 L9297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9298;
    }
  goto ret0;

 L9298: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 855;
    }
  goto ret0;

 L9302: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode)
    goto L13527;
  goto ret0;

 L13527: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9303;
    }
 L13528: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9309;
    }
  goto ret0;

 L9303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9304;
    }
  x2 = XEXP (x1, 0);
  goto L13528;

 L9304: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 856;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L13528;

 L9309: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9310;
    }
  goto ret0;

 L9310: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 857;
    }
  goto ret0;

 L9332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9333;
    }
  goto ret0;

 L9333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9334;
    }
  goto ret0;

 L9334: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 861;
    }
  goto ret0;

 L9338: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9339;
    }
  goto ret0;

 L9339: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9340;
    }
  goto ret0;

 L9340: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 862;
    }
  goto ret0;

 L9344: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9345;
    }
  goto ret0;

 L9345: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9346;
    }
  goto ret0;

 L9346: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 863;
    }
  goto ret0;

 L9399: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode)
    goto L13529;
  goto ret0;

 L13529: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L9400;
    case MINUS:
      goto L9421;
    default:
     break;
   }
  goto ret0;

 L9400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9401;
  goto ret0;

 L9401: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2SFmode))
    {
      operands[1] = x4;
      goto L9402;
    }
  goto ret0;

 L9402: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9403;
  goto ret0;

 L9403: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L9404;
  goto ret0;

 L9404: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9405;
  goto ret0;

 L9405: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L9406;
  goto ret0;

 L9406: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9407;
  goto ret0;

 L9407: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 1LL)
    goto L9408;
  goto ret0;

 L9408: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == PLUS)
    goto L9409;
  goto ret0;

 L9409: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9410;
  goto ret0;

 L9410: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V2SFmode))
    {
      operands[2] = x4;
      goto L9411;
    }
  goto ret0;

 L9411: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9412;
  goto ret0;

 L9412: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L9413;
  goto ret0;

 L9413: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9414;
  goto ret0;

 L9414: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L9415;
  goto ret0;

 L9415: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9416;
  goto ret0;

 L9416: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 1LL
      && (TARGET_3DNOW))
    {
      return 867;
    }
  goto ret0;

 L9421: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9422;
  goto ret0;

 L9422: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2SFmode))
    {
      operands[1] = x4;
      goto L9423;
    }
  goto ret0;

 L9423: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9424;
  goto ret0;

 L9424: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L9425;
  goto ret0;

 L9425: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9426;
  goto ret0;

 L9426: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L9427;
  goto ret0;

 L9427: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9428;
  goto ret0;

 L9428: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 1LL)
    goto L9429;
  goto ret0;

 L9429: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L13531;
  goto ret0;

 L13531: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MINUS:
      goto L9430;
    case PLUS:
      goto L9451;
    default:
     break;
   }
  goto ret0;

 L9430: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9431;
  goto ret0;

 L9431: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V2SFmode))
    {
      operands[2] = x4;
      goto L9432;
    }
  goto ret0;

 L9432: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9433;
  goto ret0;

 L9433: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L9434;
  goto ret0;

 L9434: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9435;
  goto ret0;

 L9435: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L9436;
  goto ret0;

 L9436: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9437;
  goto ret0;

 L9437: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 1LL
      && (TARGET_3DNOW_A))
    {
      return 868;
    }
  goto ret0;

 L9451: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9452;
  goto ret0;

 L9452: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V2SFmode))
    {
      operands[2] = x4;
      goto L9453;
    }
  goto ret0;

 L9453: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9454;
  goto ret0;

 L9454: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L9455;
  goto ret0;

 L9455: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9456;
  goto ret0;

 L9456: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[2]))
    goto L9457;
  goto ret0;

 L9457: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L9458;
  goto ret0;

 L9458: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 1LL
      && (TARGET_3DNOW_A))
    {
      return 869;
    }
  goto ret0;

 L9462: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SImode)
    goto L13533;
  goto ret0;

 L13533: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_CONCAT)
    goto L9463;
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9479;
    }
  goto ret0;

 L9463: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L9464;
  goto ret0;

 L9464: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == HImode
      && GET_CODE (x4) == TRUNCATE)
    goto L9465;
  goto ret0;

 L9465: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == VEC_SELECT)
    goto L9466;
  goto ret0;

 L9466: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, V2SImode))
    {
      operands[1] = x6;
      goto L9467;
    }
  goto ret0;

 L9467: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_CODE (x6) == PARALLEL
      && XVECLEN (x6, 0) == 1)
    goto L9468;
  goto ret0;

 L9468: ATTRIBUTE_UNUSED_LABEL
  x7 = XVECEXP (x6, 0, 0);
  if (GET_CODE (x7) == CONST_INT
      && XWINT (x7, 0) == 0LL)
    goto L9469;
  goto ret0;

 L9469: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L9470;
  goto ret0;

 L9470: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == HImode
      && GET_CODE (x4) == TRUNCATE)
    goto L9471;
  goto ret0;

 L9471: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == VEC_SELECT)
    goto L9472;
  goto ret0;

 L9472: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (rtx_equal_p (x6, operands[1]))
    goto L9473;
  goto ret0;

 L9473: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_CODE (x6) == PARALLEL
      && XVECLEN (x6, 0) == 1)
    goto L9474;
  goto ret0;

 L9474: ATTRIBUTE_UNUSED_LABEL
  x7 = XVECEXP (x6, 0, 0);
  if (GET_CODE (x7) == CONST_INT
      && XWINT (x7, 0) == 1LL
      && (TARGET_3DNOW_A))
    {
      return 870;
    }
  goto ret0;

 L9479: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 871;
    }
  goto ret0;

 L13522: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L13535;
    case 2:
      goto L13536;
    default:
      break;
    }
  goto ret0;

 L13535: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 50LL:
      goto L9489;
    case 53LL:
      goto L9506;
    default:
      break;
    }
  goto ret0;

 L9489: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9490;
    }
  goto ret0;

 L9490: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 873;
    }
  goto ret0;

 L9506: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9507;
    }
  goto ret0;

 L9507: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 876;
    }
  goto ret0;

 L13536: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 51LL:
      goto L9494;
    case 52LL:
      goto L9500;
    case 54LL:
      goto L9511;
    default:
      break;
    }
  goto ret0;

 L9494: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9495;
    }
  goto ret0;

 L9495: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9496;
    }
  goto ret0;

 L9496: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 874;
    }
  goto ret0;

 L9500: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9501;
    }
  goto ret0;

 L9501: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9502;
    }
  goto ret0;

 L9502: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 875;
    }
  goto ret0;

 L9511: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9512;
    }
  goto ret0;

 L9512: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9513;
    }
  goto ret0;

 L9513: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 877;
    }
  goto ret0;

 L9540: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9541;
    }
  goto ret0;

 L9541: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 2)
    goto L9542;
  goto ret0;

 L9542: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 1LL)
    goto L9543;
  goto ret0;

 L9543: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_3DNOW_A))
    {
      return 880;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L9565;
    case VEC_MERGE:
      goto L9571;
    case MINUS:
      goto L9579;
    case MULT:
      goto L9593;
    case DIV:
      goto L9607;
    case SMAX:
      goto L9621;
    case SMIN:
      goto L9635;
    case SQRT:
      goto L9649;
    case FLOAT:
      goto L9769;
    case FLOAT_EXTEND:
      goto L9881;
    case VEC_CONCAT:
      goto L10342;
    default:
     break;
   }
  goto ret0;

 L9565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9566;
    }
  goto ret0;

 L9566: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9567;
    }
  goto ret0;

 L9567: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 885;
    }
  goto ret0;

 L9571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2DFmode)
    goto L13561;
  goto ret0;

 L13561: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L9572;
    case MINUS:
      goto L9586;
    case MULT:
      goto L9600;
    case DIV:
      goto L9614;
    case SMAX:
      goto L9628;
    case SMIN:
      goto L9642;
    case SQRT:
      goto L9655;
    case VEC_DUPLICATE:
      goto L10660;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13568;
    default:
      goto ret0;
   }
 L13568: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9837;
    }
  goto ret0;

 L9572: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9573;
    }
  goto ret0;

 L9573: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9574;
    }
  goto ret0;

 L9574: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L9575;
  goto ret0;

 L9575: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 886;
    }
  goto ret0;

 L9586: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9587;
    }
  goto ret0;

 L9587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9588;
    }
  goto ret0;

 L9588: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L9589;
  goto ret0;

 L9589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 888;
    }
  goto ret0;

 L9600: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9601;
    }
  goto ret0;

 L9601: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9602;
    }
  goto ret0;

 L9602: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L9603;
  goto ret0;

 L9603: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 890;
    }
  goto ret0;

 L9614: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9615;
    }
  goto ret0;

 L9615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9616;
    }
  goto ret0;

 L9616: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L9617;
  goto ret0;

 L9617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 892;
    }
  goto ret0;

 L9628: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9629;
    }
  goto ret0;

 L9629: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9630;
    }
  goto ret0;

 L9630: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L9631;
  goto ret0;

 L9631: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 894;
    }
  goto ret0;

 L9642: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9643;
    }
  goto ret0;

 L9643: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9644;
    }
  goto ret0;

 L9644: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[1]))
    goto L9645;
  goto ret0;

 L9645: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 896;
    }
  goto ret0;

 L9655: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9656;
    }
  goto ret0;

 L9656: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9657;
    }
  goto ret0;

 L9657: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 898;
    }
  goto ret0;

 L10660: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (memory_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L10661;
    }
  goto ret0;

 L10661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10662;
    }
  goto ret0;

 L10662: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 1016;
    }
  goto ret0;

 L9837: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DFmode)
    goto L13570;
  goto ret0;

 L13570: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case VEC_DUPLICATE:
      goto L9838;
    case FLOAT_EXTEND:
      goto L9862;
    default:
     break;
   }
  goto ret0;

 L9838: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DFmode
      && GET_CODE (x3) == FLOAT)
    goto L9839;
  goto ret0;

 L9839: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  switch (GET_MODE (x4))
    {
    case SImode:
      goto L13572;
    case DImode:
      goto L13573;
    default:
      break;
    }
  goto ret0;

 L13572: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L9840;
    }
  goto ret0;

 L9840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 2LL
      && (TARGET_SSE2))
    {
      return 925;
    }
  goto ret0;

 L13573: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L9848;
    }
  goto ret0;

 L9848: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 2LL
      && (TARGET_SSE2 && TARGET_64BIT))
    {
      return 926;
    }
  goto ret0;

 L9862: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SFmode
      && GET_CODE (x3) == VEC_SELECT)
    goto L9863;
  goto ret0;

 L9863: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V4SFmode))
    {
      operands[2] = x4;
      goto L9864;
    }
  goto ret0;

 L9864: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 2)
    goto L9865;
  goto ret0;

 L9865: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L9866;
  goto ret0;

 L9866: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 1LL)
    goto L9867;
  goto ret0;

 L9867: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 2LL
      && (TARGET_SSE2))
    {
      return 928;
    }
  goto ret0;

 L9579: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9580;
    }
  goto ret0;

 L9580: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9581;
    }
  goto ret0;

 L9581: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 887;
    }
  goto ret0;

 L9593: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9594;
    }
  goto ret0;

 L9594: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9595;
    }
  goto ret0;

 L9595: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 889;
    }
  goto ret0;

 L9607: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9608;
    }
  goto ret0;

 L9608: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9609;
    }
  goto ret0;

 L9609: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 891;
    }
  goto ret0;

 L9621: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9622;
    }
  goto ret0;

 L9622: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9623;
    }
  goto ret0;

 L9623: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 893;
    }
  goto ret0;

 L9635: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9636;
    }
  goto ret0;

 L9636: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9637;
    }
  goto ret0;

 L9637: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 895;
    }
  goto ret0;

 L9649: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9650;
    }
  goto ret0;

 L9650: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 897;
    }
  goto ret0;

 L9769: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SImode)
    goto L13574;
  goto ret0;

 L13574: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L9770;
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9804;
    }
  goto ret0;

 L9770: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L9771;
    }
  goto ret0;

 L9771: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L9772;
  goto ret0;

 L9772: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9773;
  goto ret0;

 L9773: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 915;
    }
  goto ret0;

 L9804: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 920;
    }
  goto ret0;

 L9881: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9882;
  goto ret0;

 L9882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L9883;
    }
  goto ret0;

 L9883: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L9884;
  goto ret0;

 L9884: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9885;
  goto ret0;

 L9885: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 930;
    }
  goto ret0;

 L10342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10343;
  goto ret0;

 L10343: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L10344;
    }
  goto ret0;

 L10344: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L10345;
  goto ret0;

 L10345: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13576;
  goto ret0;

 L13576: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 1LL:
        goto L10346;
      case 0LL:
        goto L10357;
      default:
        break;
      }
  goto ret0;

 L10346: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10347;
  goto ret0;

 L10347: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L10348;
    }
  goto ret0;

 L10348: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L10349;
  goto ret0;

 L10349: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 990;
    }
  goto ret0;

 L10357: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10358;
  goto ret0;

 L10358: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L10359;
    }
  goto ret0;

 L10359: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L10360;
  goto ret0;

 L10360: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 991;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L9889;
    case SS_PLUS:
      goto L9913;
    case US_PLUS:
      goto L9925;
    case MINUS:
      goto L9937;
    case SS_MINUS:
      goto L9961;
    case US_MINUS:
      goto L9973;
    case ASHIFTRT:
      goto L10079;
    case EQ:
      goto L10162;
    case GT:
      goto L10180;
    case UMAX:
      goto L10198;
    case UMIN:
      goto L10210;
    case VEC_CONCAT:
      goto L10364;
    case VEC_MERGE:
      goto L10388;
    default:
     break;
   }
  goto ret0;

 L9889: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9890;
    }
  goto ret0;

 L9890: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9891;
    }
  goto ret0;

 L9891: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 931;
    }
  goto ret0;

 L9913: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9914;
    }
  goto ret0;

 L9914: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9915;
    }
  goto ret0;

 L9915: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 935;
    }
  goto ret0;

 L9925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9926;
    }
  goto ret0;

 L9926: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9927;
    }
  goto ret0;

 L9927: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 937;
    }
  goto ret0;

 L9937: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9938;
    }
  goto ret0;

 L9938: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9939;
    }
  goto ret0;

 L9939: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 939;
    }
  goto ret0;

 L9961: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9962;
    }
  goto ret0;

 L9962: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9963;
    }
  goto ret0;

 L9963: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 943;
    }
  goto ret0;

 L9973: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9974;
    }
  goto ret0;

 L9974: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9975;
    }
  goto ret0;

 L9975: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 945;
    }
  goto ret0;

 L10079: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V16QImode
      && GET_CODE (x2) == PLUS)
    goto L10080;
  goto ret0;

 L10080: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V16QImode
      && GET_CODE (x3) == PLUS)
    goto L10081;
  goto ret0;

 L10081: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V16QImode))
    {
      operands[1] = x4;
      goto L10082;
    }
  goto ret0;

 L10082: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, V16QImode))
    {
      operands[2] = x4;
      goto L10083;
    }
  goto ret0;

 L10083: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V16QImode
      && GET_CODE (x3) == CONST_VECTOR
      && XVECLEN (x3, 0) == 16)
    goto L10084;
  goto ret0;

 L10084: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10085;
  goto ret0;

 L10085: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10086;
  goto ret0;

 L10086: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10087;
  goto ret0;

 L10087: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10088;
  goto ret0;

 L10088: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10089;
  goto ret0;

 L10089: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10090;
  goto ret0;

 L10090: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10091;
  goto ret0;

 L10091: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10092;
  goto ret0;

 L10092: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10093;
  goto ret0;

 L10093: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10094;
  goto ret0;

 L10094: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10095;
  goto ret0;

 L10095: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10096;
  goto ret0;

 L10096: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10097;
  goto ret0;

 L10097: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10098;
  goto ret0;

 L10098: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10099;
  goto ret0;

 L10099: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10100;
  goto ret0;

 L10100: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 954;
    }
  goto ret0;

 L10162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10163;
    }
  goto ret0;

 L10163: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L10164;
    }
  goto ret0;

 L10164: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 962;
    }
  goto ret0;

 L10180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10181;
    }
  goto ret0;

 L10181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L10182;
    }
  goto ret0;

 L10182: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 965;
    }
  goto ret0;

 L10198: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10199;
    }
  goto ret0;

 L10199: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L10200;
    }
  goto ret0;

 L10200: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 968;
    }
  goto ret0;

 L10210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10211;
    }
  goto ret0;

 L10211: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L10212;
    }
  goto ret0;

 L10212: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 970;
    }
  goto ret0;

 L10364: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8QImode)
    goto L13638;
  goto ret0;

 L13638: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case SS_TRUNCATE:
      goto L10365;
    case US_TRUNCATE:
      goto L10381;
    default:
     break;
   }
  goto ret0;

 L10365: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L10366;
    }
  goto ret0;

 L10366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8QImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L10367;
  goto ret0;

 L10367: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L10368;
    }
  goto ret0;

 L10368: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 992;
    }
  goto ret0;

 L10381: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L10382;
    }
  goto ret0;

 L10382: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8QImode
      && GET_CODE (x2) == US_TRUNCATE)
    goto L10383;
  goto ret0;

 L10383: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L10384;
    }
  goto ret0;

 L10384: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 994;
    }
  goto ret0;

 L10388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V16QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10389;
  goto ret0;

 L10389: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[1] = x3;
      goto L10390;
    }
  goto ret0;

 L10390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 16)
    goto L10391;
  goto ret0;

 L10391: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13640;
  goto ret0;

 L13640: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 8LL:
        goto L10392;
      case 0LL:
        goto L10478;
      default:
        break;
      }
  goto ret0;

 L10392: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10393;
  goto ret0;

 L10393: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 9LL)
    goto L10394;
  goto ret0;

 L10394: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10395;
  goto ret0;

 L10395: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 10LL)
    goto L10396;
  goto ret0;

 L10396: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10397;
  goto ret0;

 L10397: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 11LL)
    goto L10398;
  goto ret0;

 L10398: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10399;
  goto ret0;

 L10399: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L10400;
  goto ret0;

 L10400: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10401;
  goto ret0;

 L10401: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 13LL)
    goto L10402;
  goto ret0;

 L10402: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10403;
  goto ret0;

 L10403: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 14LL)
    goto L10404;
  goto ret0;

 L10404: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10405;
  goto ret0;

 L10405: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 15LL)
    goto L10406;
  goto ret0;

 L10406: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10407;
  goto ret0;

 L10407: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V16QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10408;
  goto ret0;

 L10408: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L10409;
    }
  goto ret0;

 L10409: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 16)
    goto L10410;
  goto ret0;

 L10410: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10411;
  goto ret0;

 L10411: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L10412;
  goto ret0;

 L10412: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10413;
  goto ret0;

 L10413: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 9LL)
    goto L10414;
  goto ret0;

 L10414: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10415;
  goto ret0;

 L10415: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 10LL)
    goto L10416;
  goto ret0;

 L10416: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10417;
  goto ret0;

 L10417: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 11LL)
    goto L10418;
  goto ret0;

 L10418: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10419;
  goto ret0;

 L10419: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L10420;
  goto ret0;

 L10420: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10421;
  goto ret0;

 L10421: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 13LL)
    goto L10422;
  goto ret0;

 L10422: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10423;
  goto ret0;

 L10423: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 14LL)
    goto L10424;
  goto ret0;

 L10424: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10425;
  goto ret0;

 L10425: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 15LL)
    goto L10426;
  goto ret0;

 L10426: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 21845LL
      && (TARGET_SSE2))
    {
      return 995;
    }
  goto ret0;

 L10478: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L10479;
  goto ret0;

 L10479: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10480;
  goto ret0;

 L10480: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 9LL)
    goto L10481;
  goto ret0;

 L10481: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10482;
  goto ret0;

 L10482: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 10LL)
    goto L10483;
  goto ret0;

 L10483: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10484;
  goto ret0;

 L10484: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 11LL)
    goto L10485;
  goto ret0;

 L10485: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10486;
  goto ret0;

 L10486: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L10487;
  goto ret0;

 L10487: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10488;
  goto ret0;

 L10488: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 13LL)
    goto L10489;
  goto ret0;

 L10489: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10490;
  goto ret0;

 L10490: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 14LL)
    goto L10491;
  goto ret0;

 L10491: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10492;
  goto ret0;

 L10492: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 15LL)
    goto L10493;
  goto ret0;

 L10493: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V16QImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10494;
  goto ret0;

 L10494: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V16QImode))
    {
      operands[2] = x3;
      goto L10495;
    }
  goto ret0;

 L10495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 16)
    goto L10496;
  goto ret0;

 L10496: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L10497;
  goto ret0;

 L10497: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10498;
  goto ret0;

 L10498: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 9LL)
    goto L10499;
  goto ret0;

 L10499: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10500;
  goto ret0;

 L10500: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 10LL)
    goto L10501;
  goto ret0;

 L10501: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10502;
  goto ret0;

 L10502: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 11LL)
    goto L10503;
  goto ret0;

 L10503: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10504;
  goto ret0;

 L10504: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 8);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 12LL)
    goto L10505;
  goto ret0;

 L10505: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 9);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10506;
  goto ret0;

 L10506: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 10);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 13LL)
    goto L10507;
  goto ret0;

 L10507: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 11);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10508;
  goto ret0;

 L10508: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 12);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 14LL)
    goto L10509;
  goto ret0;

 L10509: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 13);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10510;
  goto ret0;

 L10510: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 14);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 15LL)
    goto L10511;
  goto ret0;

 L10511: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 15);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10512;
  goto ret0;

 L10512: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 21845LL
      && (TARGET_SSE2))
    {
      return 998;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case FIX:
      goto L9759;
    case UNSPEC:
      goto L13664;
    case VEC_CONCAT:
      goto L9777;
    case PLUS:
      goto L9901;
    case MINUS:
      goto L9949;
    case EQ:
      goto L10174;
    case GT:
      goto L10192;
    case ASHIFTRT:
      goto L10228;
    case LSHIFTRT:
      goto L10240;
    case ASHIFT:
      goto L10258;
    case VEC_MERGE:
      goto L10456;
    default:
     break;
   }
  goto ret0;

 L9759: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L9760;
    }
  goto ret0;

 L9760: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 913;
    }
  goto ret0;

 L13664: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L13666;
    case 2:
      goto L13667;
    default:
      break;
    }
  goto ret0;

 L13666: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 30)
    goto L9764;
  goto ret0;

 L9764: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L9765;
    }
  goto ret0;

 L9765: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 914;
    }
  goto ret0;

 L13667: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 41)
    goto L10144;
  goto ret0;

 L10144: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10145;
    }
  goto ret0;

 L10145: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L10146;
    }
  goto ret0;

 L10146: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 959;
    }
  goto ret0;

 L9777: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SImode)
    goto L13668;
  goto ret0;

 L13668: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FIX:
      goto L9778;
    case UNSPEC:
      goto L13670;
    default:
     break;
   }
  goto ret0;

 L9778: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9779;
    }
  goto ret0;

 L9779: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SImode
      && GET_CODE (x2) == CONST_VECTOR
      && XVECLEN (x2, 0) == 2)
    goto L9780;
  goto ret0;

 L9780: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9781;
  goto ret0;

 L9781: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 916;
    }
  goto ret0;

 L13670: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 30)
    goto L9786;
  goto ret0;

 L9786: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9787;
    }
  goto ret0;

 L9787: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SImode
      && GET_CODE (x2) == CONST_VECTOR
      && XVECLEN (x2, 0) == 2)
    goto L9788;
  goto ret0;

 L9788: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L9789;
  goto ret0;

 L9789: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 917;
    }
  goto ret0;

 L9901: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode)
    goto L13672;
  goto ret0;

 L13672: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L10040;
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L9902;
    }
  goto ret0;

 L10040: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V4SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L10041;
  goto ret0;

 L10041: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V4HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L10042;
  goto ret0;

 L10042: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, V8HImode))
    {
      operands[1] = x5;
      goto L10043;
    }
  goto ret0;

 L10043: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 4)
    goto L10044;
  goto ret0;

 L10044: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 0LL)
    goto L10045;
  goto ret0;

 L10045: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 2LL)
    goto L10046;
  goto ret0;

 L10046: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 2);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 4LL)
    goto L10047;
  goto ret0;

 L10047: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 3);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 6LL)
    goto L10048;
  goto ret0;

 L10048: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V4SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L10049;
  goto ret0;

 L10049: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V4HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L10050;
  goto ret0;

 L10050: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V8HImode))
    {
      operands[2] = x5;
      goto L10051;
    }
  goto ret0;

 L10051: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 4)
    goto L10052;
  goto ret0;

 L10052: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 0LL)
    goto L10053;
  goto ret0;

 L10053: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 2LL)
    goto L10054;
  goto ret0;

 L10054: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 2);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 4LL)
    goto L10055;
  goto ret0;

 L10055: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 3);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 6LL)
    goto L10056;
  goto ret0;

 L10056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == MULT)
    goto L10057;
  goto ret0;

 L10057: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V4SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L10058;
  goto ret0;

 L10058: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V4HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L10059;
  goto ret0;

 L10059: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L10060;
  goto ret0;

 L10060: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 4)
    goto L10061;
  goto ret0;

 L10061: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 1LL)
    goto L10062;
  goto ret0;

 L10062: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 3LL)
    goto L10063;
  goto ret0;

 L10063: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 2);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 5LL)
    goto L10064;
  goto ret0;

 L10064: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 3);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 7LL)
    goto L10065;
  goto ret0;

 L10065: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V4SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L10066;
  goto ret0;

 L10066: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V4HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L10067;
  goto ret0;

 L10067: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L10068;
  goto ret0;

 L10068: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 4)
    goto L10069;
  goto ret0;

 L10069: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 1LL)
    goto L10070;
  goto ret0;

 L10070: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 3LL)
    goto L10071;
  goto ret0;

 L10071: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 2);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 5LL)
    goto L10072;
  goto ret0;

 L10072: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 3);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 7LL
      && (TARGET_SSE2))
    {
      return 952;
    }
  goto ret0;

 L9902: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L9903;
    }
  goto ret0;

 L9903: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 933;
    }
  goto ret0;

 L9949: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L9950;
    }
  goto ret0;

 L9950: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L9951;
    }
  goto ret0;

 L9951: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 941;
    }
  goto ret0;

 L10174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10175;
    }
  goto ret0;

 L10175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L10176;
    }
  goto ret0;

 L10176: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 964;
    }
  goto ret0;

 L10192: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10193;
    }
  goto ret0;

 L10193: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SImode))
    {
      operands[2] = x2;
      goto L10194;
    }
  goto ret0;

 L10194: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 967;
    }
  goto ret0;

 L10228: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10229;
    }
  goto ret0;

 L10229: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10230;
    }
 L10278: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10279;
  goto ret0;

 L10230: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 973;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10278;

 L10279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10280;
    }
  goto ret0;

 L10280: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 981;
    }
  goto ret0;

 L10240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10241;
    }
  goto ret0;

 L10241: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10242;
    }
 L10292: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10293;
  goto ret0;

 L10242: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 975;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10292;

 L10293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10294;
    }
  goto ret0;

 L10294: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 983;
    }
  goto ret0;

 L10258: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10259;
    }
  goto ret0;

 L10259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10260;
    }
 L10313: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10314;
  goto ret0;

 L10260: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 978;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10313;

 L10314: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10315;
    }
  goto ret0;

 L10315: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 986;
    }
  goto ret0;

 L10456: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode)
    goto L13673;
  goto ret0;

 L13673: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case VEC_SELECT:
      goto L10457;
    case VEC_DUPLICATE:
      goto L10631;
    default:
     break;
   }
  goto ret0;

 L10457: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L10458;
    }
  goto ret0;

 L10458: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L10459;
  goto ret0;

 L10459: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13675;
  goto ret0;

 L13675: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 2LL:
        goto L10460;
      case 0LL:
        goto L10546;
      default:
        break;
      }
  goto ret0;

 L10460: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10461;
  goto ret0;

 L10461: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10462;
  goto ret0;

 L10462: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10463;
  goto ret0;

 L10463: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10464;
  goto ret0;

 L10464: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L10465;
    }
  goto ret0;

 L10465: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L10466;
  goto ret0;

 L10466: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10467;
  goto ret0;

 L10467: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10468;
  goto ret0;

 L10468: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10469;
  goto ret0;

 L10469: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10470;
  goto ret0;

 L10470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 5LL
      && (TARGET_SSE2))
    {
      return 997;
    }
  goto ret0;

 L10546: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10547;
  goto ret0;

 L10547: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10548;
  goto ret0;

 L10548: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10549;
  goto ret0;

 L10549: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10550;
  goto ret0;

 L10550: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L10551;
    }
  goto ret0;

 L10551: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 4)
    goto L10552;
  goto ret0;

 L10552: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10553;
  goto ret0;

 L10553: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10554;
  goto ret0;

 L10554: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10555;
  goto ret0;

 L10555: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10556;
  goto ret0;

 L10556: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 5LL
      && (TARGET_SSE2))
    {
      return 1000;
    }
  goto ret0;

 L10631: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L10632;
    }
  goto ret0;

 L10632: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == CONST_VECTOR
      && XVECLEN (x2, 0) == 4)
    goto L10633;
  goto ret0;

 L10633: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10634;
  goto ret0;

 L10634: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10635;
  goto ret0;

 L10635: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10636;
  goto ret0;

 L10636: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L10637;
  goto ret0;

 L10637: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 1012;
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

  x1 = XEXP (x0, 1);
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L9895;
    case SS_PLUS:
      goto L9919;
    case US_PLUS:
      goto L9931;
    case MINUS:
      goto L9943;
    case SS_MINUS:
      goto L9967;
    case US_MINUS:
      goto L9979;
    case MULT:
      goto L9985;
    case TRUNCATE:
      goto L9991;
    case ASHIFTRT:
      goto L10104;
    case VEC_MERGE:
      goto L10127;
    case UNSPEC:
      goto L13704;
    case EQ:
      goto L10168;
    case GT:
      goto L10186;
    case SMAX:
      goto L10204;
    case SMIN:
      goto L10216;
    case LSHIFTRT:
      goto L10234;
    case ASHIFT:
      goto L10252;
    case VEC_CONCAT:
      goto L10372;
    default:
     break;
   }
  goto ret0;

 L9895: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9896;
    }
  goto ret0;

 L9896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9897;
    }
  goto ret0;

 L9897: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 932;
    }
  goto ret0;

 L9919: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9920;
    }
  goto ret0;

 L9920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9921;
    }
  goto ret0;

 L9921: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 936;
    }
  goto ret0;

 L9931: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9932;
    }
  goto ret0;

 L9932: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9933;
    }
  goto ret0;

 L9933: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 938;
    }
  goto ret0;

 L9943: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9944;
    }
  goto ret0;

 L9944: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9945;
    }
  goto ret0;

 L9945: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 940;
    }
  goto ret0;

 L9967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9968;
    }
  goto ret0;

 L9968: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9969;
    }
  goto ret0;

 L9969: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 944;
    }
  goto ret0;

 L9979: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9980;
    }
  goto ret0;

 L9980: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9981;
    }
  goto ret0;

 L9981: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 946;
    }
  goto ret0;

 L9985: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L9986;
    }
  goto ret0;

 L9986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L9987;
    }
  goto ret0;

 L9987: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 947;
    }
  goto ret0;

 L9991: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L9992;
  goto ret0;

 L9992: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V8SImode
      && GET_CODE (x3) == MULT)
    goto L9993;
  goto ret0;

 L9993: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V8SImode)
    goto L13706;
  goto ret0;

 L13706: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x4))
    {
    case SIGN_EXTEND:
      goto L9994;
    case ZERO_EXTEND:
      goto L10004;
    default:
     break;
   }
  goto ret0;

 L9994: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, V8HImode))
    {
      operands[1] = x5;
      goto L9995;
    }
  goto ret0;

 L9995: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == V8SImode
      && GET_CODE (x4) == SIGN_EXTEND)
    goto L9996;
  goto ret0;

 L9996: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V8HImode))
    {
      operands[2] = x5;
      goto L9997;
    }
  goto ret0;

 L9997: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 16LL
      && (TARGET_SSE2))
    {
      return 948;
    }
  goto ret0;

 L10004: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, V8HImode))
    {
      operands[1] = x5;
      goto L10005;
    }
  goto ret0;

 L10005: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == V8SImode
      && GET_CODE (x4) == ZERO_EXTEND)
    goto L10006;
  goto ret0;

 L10006: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V8HImode))
    {
      operands[2] = x5;
      goto L10007;
    }
  goto ret0;

 L10007: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 16LL
      && (TARGET_SSE2))
    {
      return 949;
    }
  goto ret0;

 L10104: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8HImode)
    goto L13708;
  goto ret0;

 L13708: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PLUS)
    goto L10105;
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10223;
    }
  goto ret0;

 L10105: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V8HImode
      && GET_CODE (x3) == PLUS)
    goto L10106;
  goto ret0;

 L10106: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V8HImode))
    {
      operands[1] = x4;
      goto L10107;
    }
  goto ret0;

 L10107: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, V8HImode))
    {
      operands[2] = x4;
      goto L10108;
    }
  goto ret0;

 L10108: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V8HImode
      && GET_CODE (x3) == CONST_VECTOR
      && XVECLEN (x3, 0) == 8)
    goto L10109;
  goto ret0;

 L10109: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10110;
  goto ret0;

 L10110: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10111;
  goto ret0;

 L10111: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10112;
  goto ret0;

 L10112: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10113;
  goto ret0;

 L10113: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10114;
  goto ret0;

 L10114: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10115;
  goto ret0;

 L10115: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10116;
  goto ret0;

 L10116: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10117;
  goto ret0;

 L10117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 955;
    }
  goto ret0;

 L10223: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10224;
    }
 L10271: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10272;
  goto ret0;

 L10224: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 972;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10271;

 L10272: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10273;
    }
  goto ret0;

 L10273: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 980;
    }
  goto ret0;

 L10127: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V8HImode)
    goto L13711;
  goto ret0;

 L13711: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L10431;
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10128;
    }
  goto ret0;

 L10431: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L10432;
    }
  goto ret0;

 L10432: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L10433;
  goto ret0;

 L10433: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT)
    goto L13712;
  goto ret0;

 L13712: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x4, 0) == XWINT (x4, 0))
    switch ((int) XWINT (x4, 0))
      {
      case 4LL:
        goto L10434;
      case 0LL:
        goto L10520;
      default:
        break;
      }
  goto ret0;

 L10434: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10435;
  goto ret0;

 L10435: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10436;
  goto ret0;

 L10436: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10437;
  goto ret0;

 L10437: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10438;
  goto ret0;

 L10438: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10439;
  goto ret0;

 L10439: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10440;
  goto ret0;

 L10440: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10441;
  goto ret0;

 L10441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10442;
  goto ret0;

 L10442: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L10443;
    }
  goto ret0;

 L10443: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L10444;
  goto ret0;

 L10444: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10445;
  goto ret0;

 L10445: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10446;
  goto ret0;

 L10446: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10447;
  goto ret0;

 L10447: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10448;
  goto ret0;

 L10448: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10449;
  goto ret0;

 L10449: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10450;
  goto ret0;

 L10450: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10451;
  goto ret0;

 L10451: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10452;
  goto ret0;

 L10452: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 85LL
      && (TARGET_SSE2))
    {
      return 996;
    }
  goto ret0;

 L10520: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10521;
  goto ret0;

 L10521: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10522;
  goto ret0;

 L10522: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10523;
  goto ret0;

 L10523: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10524;
  goto ret0;

 L10524: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10525;
  goto ret0;

 L10525: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10526;
  goto ret0;

 L10526: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10527;
  goto ret0;

 L10527: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10528;
  goto ret0;

 L10528: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[2] = x3;
      goto L10529;
    }
  goto ret0;

 L10529: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 8)
    goto L10530;
  goto ret0;

 L10530: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 4LL)
    goto L10531;
  goto ret0;

 L10531: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10532;
  goto ret0;

 L10532: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 5LL)
    goto L10533;
  goto ret0;

 L10533: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 3);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10534;
  goto ret0;

 L10534: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 4);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 6LL)
    goto L10535;
  goto ret0;

 L10535: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 5);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 2LL)
    goto L10536;
  goto ret0;

 L10536: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 6);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 7LL)
    goto L10537;
  goto ret0;

 L10537: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 7);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 3LL)
    goto L10538;
  goto ret0;

 L10538: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 85LL
      && (TARGET_SSE2))
    {
      return 999;
    }
  goto ret0;

 L10128: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V8HImode
      && GET_CODE (x2) == VEC_DUPLICATE)
    goto L10129;
  goto ret0;

 L10129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == TRUNCATE)
    goto L10130;
  goto ret0;

 L10130: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10131;
    }
  goto ret0;

 L10131: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L10132;
    }
  goto ret0;

 L10132: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 957;
    }
  goto ret0;

 L13704: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2)
    goto L13714;
  goto ret0;

 L13714: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 55LL:
      goto L10150;
    case 56LL:
      goto L10156;
    default:
      break;
    }
  goto ret0;

 L10150: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10151;
    }
  goto ret0;

 L10151: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L10152;
    }
  goto ret0;

 L10152: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 960;
    }
  goto ret0;

 L10156: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10157;
    }
  goto ret0;

 L10157: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (immediate_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L10158;
    }
  goto ret0;

 L10158: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 961;
    }
  goto ret0;

 L10168: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10169;
    }
  goto ret0;

 L10169: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L10170;
    }
  goto ret0;

 L10170: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 963;
    }
  goto ret0;

 L10186: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10187;
    }
  goto ret0;

 L10187: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L10188;
    }
  goto ret0;

 L10188: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 966;
    }
  goto ret0;

 L10204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10205;
    }
  goto ret0;

 L10205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L10206;
    }
  goto ret0;

 L10206: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 969;
    }
  goto ret0;

 L10216: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10217;
    }
  goto ret0;

 L10217: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V8HImode))
    {
      operands[2] = x2;
      goto L10218;
    }
  goto ret0;

 L10218: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 971;
    }
  goto ret0;

 L10234: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10235;
    }
  goto ret0;

 L10235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10236;
    }
 L10285: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10286;
  goto ret0;

 L10236: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 974;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10285;

 L10286: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10287;
    }
  goto ret0;

 L10287: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 982;
    }
  goto ret0;

 L10252: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V8HImode))
    {
      operands[1] = x2;
      goto L10253;
    }
  goto ret0;

 L10253: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10254;
    }
 L10306: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10307;
  goto ret0;

 L10254: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 977;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10306;

 L10307: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10308;
    }
  goto ret0;

 L10308: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 985;
    }
  goto ret0;

 L10372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4HImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L10373;
  goto ret0;

 L10373: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[1] = x3;
      goto L10374;
    }
  goto ret0;

 L10374: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4HImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L10375;
  goto ret0;

 L10375: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SImode))
    {
      operands[2] = x3;
      goto L10376;
    }
  goto ret0;

 L10376: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 993;
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

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case HImode:
      goto L12758;
    case CCFPmode:
      goto L12750;
    case CCFPUmode:
      goto L12751;
    case CCmode:
      goto L12752;
    case SImode:
      goto L12753;
    case QImode:
      goto L12762;
    case DImode:
      goto L12769;
    case SFmode:
      goto L12774;
    case DFmode:
      goto L12776;
    case XFmode:
      goto L12778;
    case TFmode:
      goto L12779;
    case TImode:
      goto L12792;
    default:
      break;
    }
 L1: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L2;
 L219: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x1))
    {
    case CCFPmode:
      goto L12799;
    case CCFPUmode:
      goto L12800;
    default:
      break;
    }
 L370: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case STRICT_LOW_PART:
      goto L371;
    case REG:
      goto L12801;
    case PC:
      goto L6206;
    default:
     break;
   }
 L1301: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, VOIDmode))
    {
      operands[0] = x1;
      goto L1302;
    }
 L8010: ATTRIBUTE_UNUSED_LABEL
  operands[0] = x1;
  goto L8011;
 L8046: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x1))
    {
    case V4SFmode:
      goto L12802;
    case V4SImode:
      goto L12803;
    case V2DImode:
      goto L12804;
    case V8QImode:
      goto L12825;
    case V4HImode:
      goto L12806;
    case V2SImode:
      goto L12807;
    case V2SFmode:
      goto L12808;
    case V2DFmode:
      goto L12809;
    case V8HImode:
      goto L12810;
    case V16QImode:
      goto L12811;
    case TImode:
      goto L12822;
    case SImode:
      goto L12824;
    case DImode:
      goto L12827;
    case SFmode:
      goto L12829;
    case CCFPmode:
      goto L12835;
    case CCFPUmode:
      goto L12836;
    default:
      break;
    }
 L9267: ATTRIBUTE_UNUSED_LABEL
  operands[0] = x1;
  goto L9268;
 L9294: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x1))
    {
    case V2SFmode:
      goto L12842;
    case V2SImode:
      goto L12843;
    case V8QImode:
      goto L12844;
    case V4HImode:
      goto L12845;
    case V2DFmode:
      goto L12846;
    case V2DImode:
      goto L12847;
    case CCFPmode:
      goto L12848;
    case CCFPUmode:
      goto L12849;
    case SImode:
      goto L12850;
    case V16QImode:
      goto L12851;
    case V4SFmode:
      goto L12855;
    case V4SImode:
      goto L12856;
    case DImode:
      goto L12857;
    case V8HImode:
      goto L12859;
    case TImode:
      goto L12860;
    case DFmode:
      goto L12866;
    default:
      break;
    }
 L10686: ATTRIBUTE_UNUSED_LABEL
  operands[0] = x1;
  goto L10687;
 L10703: ATTRIBUTE_UNUSED_LABEL
  switch (GET_MODE (x1))
    {
    case V4SFmode:
      goto L12867;
    case V2DFmode:
      goto L12868;
    case V16QImode:
      goto L12869;
    default:
      break;
    }
  goto ret0;

 L12758: ATTRIBUTE_UNUSED_LABEL
  tem = recog_1 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1;

 L12750: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 18)
    goto L146;
  goto L1;

 L146: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPmode
      && GET_CODE (x1) == COMPARE)
    goto L147;
  x1 = XEXP (x0, 0);
  goto L1;

 L147: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SFmode:
      goto L12900;
    case DFmode:
      goto L12901;
    case XFmode:
      goto L12902;
    case TFmode:
      goto L12903;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12900: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L148;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L148: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L149;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L149: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 19;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12901: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L161;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L162;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L162: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 21;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12902: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      operands[0] = x2;
      goto L174;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L175;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L175: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 23;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12903: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TFmode))
    {
      operands[0] = x2;
      goto L180;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L181;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L181: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 24;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12751: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 18)
    goto L198;
  goto L1;

 L198: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPUmode
      && GET_CODE (x1) == COMPARE)
    goto L199;
  x1 = XEXP (x0, 0);
  goto L1;

 L199: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L200;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L200: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L201;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L201: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])))
    {
      return 27;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12752: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L215;
  goto L1;

 L215: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 25)
    goto L216;
  x1 = XEXP (x0, 0);
  goto L1;

 L216: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L217;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L217: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 30;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L12753: ATTRIBUTE_UNUSED_LABEL
  tem = recog_3 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1;

 L12762: ATTRIBUTE_UNUSED_LABEL
  tem = recog_4 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1;

 L12769: ATTRIBUTE_UNUSED_LABEL
  tem = recog_6 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1;

 L12774: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L585;
    }
 L12775: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L875;
    }
 L12783: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L880;
    }
 L12784: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L885;
    }
 L12793: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L4180;
    }
 L12795: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L4279;
    }
  goto L1;

 L585: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L586;
    }
 L589: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_no_elim_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L590;
    }
  x1 = XEXP (x0, 0);
  goto L12775;

 L586: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 87;
    }
  x1 = XEXP (x0, 1);
  goto L589;

 L590: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 88;
    }
  x1 = XEXP (x0, 0);
  goto L12775;

 L875: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode
      && GET_CODE (x1) == FLOAT_TRUNCATE)
    goto L876;
  if (general_operand (x1, SFmode))
    {
      operands[1] = x1;
      goto L594;
    }
  x1 = XEXP (x0, 0);
  goto L12783;

 L876: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L877;
    }
  x1 = XEXP (x0, 0);
  goto L12783;

 L877: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 135;
    }
  x1 = XEXP (x0, 0);
  goto L12783;

 L594: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], SFmode))))
    {
      return 89;
    }
  x1 = XEXP (x0, 0);
  goto L12783;

 L880: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L13075;
  x1 = XEXP (x0, 0);
  goto L12784;

 L13075: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_TRUNCATE:
      goto L881;
    case NEG:
      goto L4152;
    case ABS:
      goto L4337;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12784;

 L881: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      goto L13078;
    case XFmode:
      goto L13079;
    case TFmode:
      goto L13080;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L13078: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L882;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L882: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 136;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L13079: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L900;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L900: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 139;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L13080: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L913;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L913: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 141;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L4152: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4153;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L4153: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NEG, SFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 360;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L4337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4338;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L4338: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (ABS, SFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 379;
    }
  x1 = XEXP (x0, 0);
  goto L12784;

 L885: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L13081;
  x1 = XEXP (x0, 0);
  goto L12793;

 L13081: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_TRUNCATE:
      goto L886;
    case FLOAT:
      goto L1079;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12793;

 L886: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L887;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L887: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_80387 && TARGET_SSE2))
    {
      return 137;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L1079: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L13083;
    case SImode:
      goto L13084;
    case DImode:
      goto L13085;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L13083: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1080;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L1080: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !TARGET_SSE))
    {
      return 161;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L13084: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1085;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L1085: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE || TARGET_MIX_SSE_I387)))
    {
      return 162;
    }
 L1090: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 163;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L13085: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1095;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L1095: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE || !TARGET_64BIT || TARGET_MIX_SSE_I387)))
    {
      return 164;
    }
 L1100: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_80387 && (!TARGET_SSE || TARGET_MIX_SSE_I387)))
    {
      return 165;
    }
 L1105: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_SSE))
    {
      return 166;
    }
  x1 = XEXP (x0, 0);
  goto L12793;

 L4180: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L13086;
  x1 = XEXP (x0, 0);
  goto L12795;

 L13086: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case NEG:
      goto L4181;
    case ABS:
      goto L4366;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12795;

 L4181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4182;
    }
  x1 = XEXP (x0, 0);
  goto L12795;

 L4182: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !TARGET_SSE
   && ix86_unary_operator_ok (NEG, SFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 362;
    }
  x1 = XEXP (x0, 0);
  goto L12795;

 L4366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L4367;
    }
  x1 = XEXP (x0, 0);
  goto L12795;

 L4367: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && ix86_unary_operator_ok (ABS, SFmode, operands) && !TARGET_SSE)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 381;
    }
  x1 = XEXP (x0, 0);
  goto L12795;

 L4279: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode)
    goto L13088;
  x1 = XEXP (x0, 0);
  goto L1;

 L13088: ATTRIBUTE_UNUSED_LABEL
  tem = recog_7 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L1;

 L12776: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L604;
    }
 L12777: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L829;
    }
 L12782: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L834;
    }
 L12785: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L924;
    }
 L12794: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L4238;
    }
 L12796: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L4284;
    }
  goto L1;

 L604: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_no_elim_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L605;
    }
  x1 = XEXP (x0, 0);
  goto L12777;

 L605: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && !TARGET_INTEGER_DFMODE_MOVES))
    {
      return 91;
    }
 L609: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT || TARGET_INTEGER_DFMODE_MOVES))
    {
      return 92;
    }
  x1 = XEXP (x0, 0);
  goto L12777;

 L829: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode
      && GET_CODE (x1) == FLOAT_EXTEND)
    goto L830;
  if (general_operand (x1, DFmode))
    {
      operands[1] = x1;
      goto L613;
    }
  x1 = XEXP (x0, 0);
  goto L12782;

 L830: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L831;
    }
  x1 = XEXP (x0, 0);
  goto L12782;

 L831: ATTRIBUTE_UNUSED_LABEL
  if (((TARGET_80387 || TARGET_SSE2)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 127;
    }
  x1 = XEXP (x0, 0);
  goto L12782;

 L613: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && (optimize_size || !TARGET_INTEGER_DFMODE_MOVES)
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], DFmode))))
    {
      return 93;
    }
 L617: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && !optimize_size && TARGET_INTEGER_DFMODE_MOVES
   && (reload_in_progress || reload_completed
       || (ix86_cmodel == CM_MEDIUM || ix86_cmodel == CM_LARGE)
       || GET_CODE (operands[1]) != CONST_DOUBLE
       || memory_operand (operands[0], DFmode))))
    {
      return 94;
    }
  x1 = XEXP (x0, 0);
  goto L12782;

 L834: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L13115;
  x1 = XEXP (x0, 0);
  goto L12785;

 L13115: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_EXTEND:
      goto L835;
    case FLOAT:
      goto L1109;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12785;

 L835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L836;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L836: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_80387 && TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 128;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L1109: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L13117;
    case SImode:
      goto L13118;
    case DImode:
      goto L13119;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L13117: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L1110;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L1110: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !TARGET_SSE2))
    {
      return 167;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L13118: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L1115;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L1115: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE2 || TARGET_MIX_SSE_I387)))
    {
      return 168;
    }
 L1120: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 169;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L13119: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1125;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L1125: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && (!TARGET_SSE2 || !TARGET_64BIT)))
    {
      return 170;
    }
 L1130: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_80387 && (!TARGET_SSE2 || TARGET_MIX_SSE_I387)))
    {
      return 171;
    }
 L1135: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 172;
    }
  x1 = XEXP (x0, 0);
  goto L12785;

 L924: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L13120;
  x1 = XEXP (x0, 0);
  goto L12794;

 L13120: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT_TRUNCATE:
      goto L925;
    case NEG:
      goto L4193;
    case ABS:
      goto L4378;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12794;

 L925: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case XFmode:
      goto L13123;
    case TFmode:
      goto L13124;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L13123: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L926;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L926: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 143;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L13124: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L939;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L939: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 145;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L4193: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L4194;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L4194: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (NEG, DFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 363;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L4378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L4379;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L4379: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_unary_operator_ok (ABS, DFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 382;
    }
  x1 = XEXP (x0, 0);
  goto L12794;

 L4238: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L13125;
  x1 = XEXP (x0, 0);
  goto L12796;

 L13125: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case NEG:
      goto L4239;
    case ABS:
      goto L4424;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12796;

 L4239: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L4240;
    }
  x1 = XEXP (x0, 0);
  goto L12796;

 L4240: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (NEG, DFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 366;
    }
 L4252: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (NEG, DFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 367;
    }
  x1 = XEXP (x0, 0);
  goto L12796;

 L4424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L4425;
    }
  x1 = XEXP (x0, 0);
  goto L12796;

 L4425: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (ABS, DFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 385;
    }
 L4437: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (ABS, DFmode, operands))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 386;
    }
  x1 = XEXP (x0, 0);
  goto L12796;

 L4284: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode)
    goto L13127;
  x1 = XEXP (x0, 0);
  goto L1;

 L13127: ATTRIBUTE_UNUSED_LABEL
  tem = recog_8 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L1;

 L12778: ATTRIBUTE_UNUSED_LABEL
  tem = recog_9 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1;

 L12779: ATTRIBUTE_UNUSED_LABEL
  tem = recog_10 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L1;

 L12792: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L2245;
    }
  goto L1;

 L2245: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode
      && GET_CODE (x1) == MULT)
    goto L2246;
  x1 = XEXP (x0, 0);
  goto L1;

 L2246: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == TImode)
    goto L13249;
  x1 = XEXP (x0, 0);
  goto L1;

 L13249: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L2247;
    case SIGN_EXTEND:
      goto L2283;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L1;

 L2247: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2248;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2248: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2249;
  x1 = XEXP (x0, 0);
  goto L1;

 L2249: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2250;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2250: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 252;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2283: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2284;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2284: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SIGN_EXTEND)
    goto L2285;
  x1 = XEXP (x0, 0);
  goto L1;

 L2285: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2286;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2286: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 254;
    }
  x1 = XEXP (x0, 0);
  goto L1;

 L2: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == COMPARE)
    goto L3;
  x1 = XEXP (x0, 0);
  goto L219;

 L3: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      goto L13252;
    case SImode:
      goto L13254;
    case HImode:
      goto L13256;
    case QImode:
      goto L13258;
    default:
      break;
    }
 L79: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L80;
    }
 L88: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == QImode)
    goto L13261;
  x1 = XEXP (x0, 0);
  goto L219;

 L13252: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MINUS:
      goto L10;
    case NEG:
      goto L1396;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13251;
    default:
      x1 = XEXP (x0, 0);
      goto L219;
   }
 L13251: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L10: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[0] = x3;
      goto L11;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L11: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L12;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L12: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 1;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L1396: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1397;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L1397: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (x86_64_general_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L1398;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L1398: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 198;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L4: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L5;
    }
 L17: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_general_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L18;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L5: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 0;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L17;

 L18: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 2;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L13254: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MINUS)
    goto L29;
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L23;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L29: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[0] = x3;
      goto L30;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L30: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L31;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L31: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 4;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L23: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L24;
    }
 L36: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L37;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L24: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)))
    {
      return 3;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L36;

 L37: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
    && ix86_match_ccmode (insn, CCmode)))
    {
      return 5;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L13256: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MINUS)
    goto L48;
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L42;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L48: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[0] = x3;
      goto L49;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L49: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L50;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L50: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 7;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L42: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L43;
    }
 L55: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L56;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L43: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)))
    {
      return 6;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L55;

 L56: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
   && ix86_match_ccmode (insn, CCmode)))
    {
      return 8;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L13258: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MINUS)
    goto L73;
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L61;
    }
 L13259: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L98;
  goto L79;

 L73: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[0] = x3;
      goto L74;
    }
  goto L79;

 L74: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L75;
    }
  goto L79;

 L75: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (ix86_match_ccmode (insn, CCGOCmode)))
    {
      return 11;
    }
  x2 = XEXP (x1, 0);
  goto L79;

 L61: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L62;
    }
 L67: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L68;
    }
  x2 = XEXP (x1, 0);
  goto L13259;

 L62: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)))
    {
      return 9;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L67;

 L68: ATTRIBUTE_UNUSED_LABEL
  if (((GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)
    && ix86_match_ccmode (insn, CCmode)))
    {
      return 10;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L13259;

 L98: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L99;
  goto L79;

 L99: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[0] = x4;
      goto L100;
    }
  goto L79;

 L100: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L101;
  goto L79;

 L101: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L102;
  goto L79;

 L102: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L103;
    }
  x2 = XEXP (x1, 0);
  goto L79;

 L103: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)))
    {
      return 14;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  goto L79;

 L80: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L81;
  x2 = XEXP (x1, 0);
  goto L88;

 L81: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L82;
  x2 = XEXP (x1, 0);
  goto L88;

 L82: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L83;
    }
  x2 = XEXP (x1, 0);
  goto L88;

 L83: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L84;
  x2 = XEXP (x1, 0);
  goto L88;

 L84: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL
      && (!TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 12;
    }
  x2 = XEXP (x1, 0);
  goto L88;

 L13261: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L89;
    }
 L13262: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L108;
  x1 = XEXP (x0, 0);
  goto L219;

 L89: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L90;
  x2 = XEXP (x1, 0);
  goto L13262;

 L90: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L91;
  x2 = XEXP (x1, 0);
  goto L13262;

 L91: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L92;
    }
  x2 = XEXP (x1, 0);
  goto L13262;

 L92: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L93;
  x2 = XEXP (x1, 0);
  goto L13262;

 L93: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 13;
    }
  x2 = XEXP (x1, 0);
  goto L13262;

 L108: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L109;
  x1 = XEXP (x0, 0);
  goto L219;

 L109: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[0] = x4;
      goto L110;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L110: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L111;
  x1 = XEXP (x0, 0);
  goto L219;

 L111: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L112;
  x1 = XEXP (x0, 0);
  goto L219;

 L112: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L113;
    }
 L122: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L123;
    }
 L132: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L133;
  x1 = XEXP (x0, 0);
  goto L219;

 L113: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 15;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L122;

 L123: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && ix86_match_ccmode (insn, CCmode)))
    {
      return 16;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L132;

 L133: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L134;
  x1 = XEXP (x0, 0);
  goto L219;

 L134: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L135;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L135: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L136;
  x1 = XEXP (x0, 0);
  goto L219;

 L136: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL
      && (ix86_match_ccmode (insn, CCmode)))
    {
      return 17;
    }
  x1 = XEXP (x0, 0);
  goto L219;

 L12799: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L220;
  goto L370;

 L220: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPmode
      && GET_CODE (x1) == COMPARE)
    goto L221;
  x1 = XEXP (x0, 0);
  goto L370;

 L221: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L222;
    }
  x1 = XEXP (x0, 0);
  goto L370;

 L222: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L223;
    }
 L228: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L229;
    }
  x1 = XEXP (x0, 0);
  goto L370;

 L223: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_CMOVE
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[0])))
    {
      return 31;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L228;

 L229: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[0])))
    {
      return 32;
    }
 L235: ATTRIBUTE_UNUSED_LABEL
  if ((SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[0])))
    {
      return 33;
    }
  x1 = XEXP (x0, 0);
  goto L370;

 L12800: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L238;
  goto L370;

 L238: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPUmode
      && GET_CODE (x1) == COMPARE)
    goto L239;
  x1 = XEXP (x0, 0);
  goto L370;

 L239: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L240;
    }
  x1 = XEXP (x0, 0);
  goto L370;

 L240: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L241;
    }
 L246: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L247;
    }
  x1 = XEXP (x0, 0);
  goto L370;

 L241: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_CMOVE
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])))
    {
      return 34;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L246;

 L247: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])))
    {
      return 35;
    }
 L253: ATTRIBUTE_UNUSED_LABEL
  if ((SSE_FLOAT_MODE_P (GET_MODE (operands[0]))
   && GET_MODE (operands[0]) == GET_MODE (operands[1])))
    {
      return 36;
    }
  x1 = XEXP (x0, 0);
  goto L370;

 L371: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      goto L13263;
    case QImode:
      goto L13265;
    default:
      break;
    }
  goto L8010;

 L13263: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L372;
    }
 L13264: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L384;
    }
  goto L8010;

 L372: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (general_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L373;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L13264;

 L373: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 55;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L13264;

 L384: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const0_operand (x1, HImode))
    {
      operands[1] = x1;
      goto L385;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L385: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed
   && ((!TARGET_USE_MOV0 && !TARGET_PARTIAL_REG_STALL) || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 56;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L13265: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1683;
    }
 L13266: ATTRIBUTE_UNUSED_LABEL
  if (q_regs_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L420;
    }
  goto L8010;

 L1683: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == QImode)
    goto L13267;
 L408: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L409;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L13266;

 L13267: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L1684;
    case MINUS:
      goto L2098;
    case AND:
      goto L3025;
    case IOR:
      goto L3412;
    case XOR:
      goto L3795;
    case ASHIFTRT:
      goto L5163;
    case LSHIFTRT:
      goto L5501;
    case ROTATE:
      goto L5689;
    case ROTATERT:
      goto L5879;
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
    case UNLE:
    case UNLT:
    case UNGE:
    case UNGT:
    case LTGT:
    case UNEQ:
      goto L13276;
    default:
      goto L408;
   }
 L13276: ATTRIBUTE_UNUSED_LABEL
  if (ix86_comparison_operator (x1, QImode))
    {
      operands[1] = x1;
      goto L5921;
    }
  goto L408;

 L1684: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L1685;
  goto L408;

 L1685: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L1686;
    }
  goto L408;

 L1686: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 217;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L2098: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L2099;
  goto L408;

 L2099: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L2100;
    }
  goto L408;

 L2100: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 242;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L3025: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L3026;
  goto L408;

 L3026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L3027;
    }
  goto L408;

 L3027: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 295;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L3412: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L3413;
  goto L408;

 L3413: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L3414;
    }
  goto L408;

 L3414: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 317;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L3795: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L3796;
  goto L408;

 L3796: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L3797;
    }
  goto L408;

 L3797: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 339;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L5163: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L5164;
  goto L408;

 L5164: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5165;
    }
 L5194: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5195;
    }
  goto L408;

 L5165: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_binary_operator_ok (ASHIFTRT, QImode, operands)
   && (! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 446;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5194;

 L5195: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 448;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L5501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L5502;
  goto L408;

 L5502: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5503;
    }
 L5532: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5533;
    }
  goto L408;

 L5503: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 470;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5532;

 L5533: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 472;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L5689: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L5690;
  goto L408;

 L5690: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5691;
    }
 L5720: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5721;
    }
  goto L408;

 L5691: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 483;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5720;

 L5721: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 485;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L5879: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[0]))
    goto L5880;
  goto L408;

 L5880: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_1_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5881;
    }
 L5910: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L5911;
    }
  goto L408;

 L5881: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 496;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L5910;

 L5911: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 498;
    }
  x1 = XEXP (x0, 1);
  goto L408;

 L5921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L5922;
  goto L408;

 L5922: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL)
    {
      return 500;
    }
  goto L408;

 L409: ATTRIBUTE_UNUSED_LABEL
  if (((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 61;
    }
  x1 = XEXP (x0, 0);
  x2 = XEXP (x1, 0);
  goto L13266;

 L420: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (const0_operand (x1, QImode))
    {
      operands[1] = x1;
      goto L421;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L421: ATTRIBUTE_UNUSED_LABEL
  if ((reload_completed && (!TARGET_USE_MOV0 || optimize_size))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 62;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L12801: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 0) == 17)
    goto L1410;
  goto L1301;

 L1410: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == COMPARE)
    goto L1411;
  x1 = XEXP (x0, 0);
  goto L1301;

 L1411: ATTRIBUTE_UNUSED_LABEL
  tem = recog_11 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L1301;

 L6206: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case SImode:
      goto L13308;
    case DImode:
      goto L13309;
    default:
      break;
    }
 L5937: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case IF_THEN_ELSE:
      goto L5938;
    case LABEL_REF:
      goto L6203;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L8010;

 L13308: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L6207;
    }
  goto L5937;

 L6207: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 516;
    }
  x1 = XEXP (x0, 1);
  goto L5937;

 L13309: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L6211;
    }
  goto L5937;

 L6211: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 517;
    }
  x1 = XEXP (x0, 1);
  goto L5937;

 L5938: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (ix86_comparison_operator (x2, VOIDmode))
    {
      operands[1] = x2;
      goto L5939;
    }
 L5970: ATTRIBUTE_UNUSED_LABEL
  if (comparison_operator (x2, VOIDmode))
    {
      operands[0] = x2;
      goto L5971;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L5939: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == REG
      && XINT (x3, 0) == 17)
    goto L5940;
  goto L5970;

 L5940: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5941;
  goto L5970;

 L5941: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L5942;
    case PC:
      goto L5951;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5970;

 L5942: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  goto L5943;

 L5943: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    {
      return 503;
    }
  x2 = XEXP (x1, 0);
  goto L5970;

 L5951: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L5952;
  x2 = XEXP (x1, 0);
  goto L5970;

 L5952: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  return 504;

 L5971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L5972;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L5972: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L5973;
    }
 L5995: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L5996;
    }
 L6169: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L6170;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L5973: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L5974;
    case PC:
      goto L6043;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5995;

 L5974: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[3] = x3;
  goto L5975;

 L5975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && (TARGET_CMOVE && TARGET_80387
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 505;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5995;

 L6043: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6044;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5995;

 L6044: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[3] = x3;
  goto L6045;

 L6045: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_CMOVE && TARGET_80387
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 508;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L5995;

 L5996: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L5997;
    case PC:
      goto L6067;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6169;

 L5997: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[3] = x3;
  goto L5998;

 L5998: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC)
    goto L13310;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6169;

 L13310: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 506;
    }
 L13311: ATTRIBUTE_UNUSED_LABEL
  if ((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 507;
    }
 L13312: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && (GET_MODE (operands[1]) == SFmode || GET_MODE (operands[1]) == DFmode)
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && !ix86_use_fcomi_compare (GET_CODE (operands[0]))
   && SELECT_CC_MODE (GET_CODE (operands[0]),
		      operands[1], operands[2]) == CCFPmode
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 511;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6169;

 L6067: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6068;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6169;

 L6068: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[3] = x3;
  goto L6069;

 L6069: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 509;
    }
 L6093: ATTRIBUTE_UNUSED_LABEL
  if ((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 510;
    }
 L6146: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && (GET_MODE (operands[1]) == SFmode || GET_MODE (operands[1]) == DFmode)
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && !ix86_use_fcomi_compare (GET_CODE (operands[0]))
   && SELECT_CC_MODE (GET_CODE (operands[0]),
		      operands[1], operands[2]) == CCFPmode
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 512;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 1);
  goto L6169;

 L6170: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case LABEL_REF:
      goto L6171;
    case PC:
      goto L6197;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L8010;

 L6171: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[3] = x3;
  goto L6172;

 L6172: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == PC
      && (TARGET_80387
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 513;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L6197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6198;
  x1 = XEXP (x0, 0);
  goto L8010;

 L6198: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[3] = x3;
  goto L6199;

 L6199: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0])))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 3;
      return 514;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L6203: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  return 515;

 L1302: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == PLUS)
    goto L1303;
  x1 = XEXP (x0, 0);
  goto L8010;

 L1303: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1338;
    case MULT:
      goto L1321;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1338: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == MULT)
    goto L1339;
  if (index_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1305;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1339: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (index_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L1340;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1340: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const248_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L1341;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1341: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      operands[3] = x3;
      goto L1342;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      operands[4] = x2;
      goto L1343;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1343: ATTRIBUTE_UNUSED_LABEL
  if (((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[3])))
    {
      return 194;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1305: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L1306;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1306: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (immediate_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L1307;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1307: ATTRIBUTE_UNUSED_LABEL
  if (((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && GET_MODE (operands[0]) == GET_MODE (operands[2])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode)))
    {
      return 190;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1321: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (index_register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1322;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1322: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const248_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L1323;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1323: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, VOIDmode))
    {
      operands[3] = x2;
      goto L1324;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L1324: ATTRIBUTE_UNUSED_LABEL
  if (((GET_MODE (operands[0]) == QImode || GET_MODE (operands[0]) == HImode
    || (TARGET_64BIT && GET_MODE (operands[0]) == SImode))
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)
   && GET_MODE (operands[0]) == GET_MODE (operands[1])
   && (GET_MODE (operands[0]) == GET_MODE (operands[3])
       || GET_MODE (operands[3]) == VOIDmode)))
    {
      return 192;
    }
  x1 = XEXP (x0, 0);
  goto L8010;

 L8011: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == CALL)
    goto L8012;
  x1 = XEXP (x0, 0);
  goto L8046;

 L8012: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == MEM)
    goto L8013;
  x1 = XEXP (x0, 0);
  goto L8046;

 L8013: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L13313;
    case DImode:
      goto L13314;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L8046;

 L13313: ATTRIBUTE_UNUSED_LABEL
  if (constant_call_address_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L8014;
    }
 L13315: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L8028;
    }
  x1 = XEXP (x0, 0);
  goto L8046;

 L8014: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  goto L8015;

 L8015: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 676;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13315;

 L8028: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  goto L8029;

 L8029: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 678;
    }
  x1 = XEXP (x0, 0);
  goto L8046;

 L13314: ATTRIBUTE_UNUSED_LABEL
  if (constant_call_address_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8021;
    }
 L13316: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8035;
    }
  x1 = XEXP (x0, 0);
  goto L8046;

 L8021: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const_int_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L8022;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13316;

 L8022: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 677;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13316;

 L8035: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  goto L8036;

 L8036: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 679;
    }
  x1 = XEXP (x0, 0);
  goto L8046;

 L12802: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L8047;
    }
 L12816: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L8103;
    }
 L12826: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L8213;
    }
 L12828: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L8223;
    }
  goto L9267;

 L8047: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SFmode)
    goto L13318;
  x1 = XEXP (x0, 0);
  goto L12816;

 L13318: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case UNSPEC:
      goto L13321;
    case VEC_MERGE:
      goto L8248;
    case CONST_VECTOR:
    case SUBREG:
    case REG:
    case MEM:
      goto L13317;
    default:
      x1 = XEXP (x0, 0);
      goto L12816;
   }
 L13317: ATTRIBUTE_UNUSED_LABEL
  if (vector_move_operand (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L8048;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L13321: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13323;
  x1 = XEXP (x0, 0);
  goto L12816;

 L13323: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 38LL:
      goto L8180;
    case 39LL:
      goto L8185;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8180: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8181;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8181: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 715;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8185: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8186;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8186: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 716;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8248: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8249;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8249: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8250;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8250: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT)
    goto L13325;
  x1 = XEXP (x0, 0);
  goto L12816;

 L13325: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x2, 0) == XWINT (x2, 0))
    switch ((int) XWINT (x2, 0))
      {
      case 12LL:
        goto L13327;
      case 3LL:
        goto L13328;
      default:
        break;
      }
  x1 = XEXP (x0, 0);
  goto L12816;

 L13327: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) == MEM || GET_CODE (operands[2]) == MEM)))
    {
      return 725;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L13328: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (GET_CODE (operands[1]) == MEM || GET_CODE (operands[2]) == MEM)))
    {
      return 726;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8048: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 682;
    }
  x1 = XEXP (x0, 0);
  goto L12816;

 L8103: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L8104;
    }
 L8147: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V4SFmode))
    {
      operands[1] = x1;
      goto L8148;
    }
  x1 = XEXP (x0, 0);
  goto L12826;

 L8104: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 696;
    }
  x1 = XEXP (x0, 1);
  goto L8147;

 L8148: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 707;
    }
  x1 = XEXP (x0, 0);
  goto L12826;

 L8213: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SFmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 34)
    goto L8214;
  x1 = XEXP (x0, 0);
  goto L12828;

 L8214: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8215;
    }
  x1 = XEXP (x0, 0);
  goto L12828;

 L8215: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 721;
    }
  x1 = XEXP (x0, 0);
  goto L12828;

 L8223: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SFmode)
    goto L13329;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13329: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case VEC_MERGE:
      goto L8224;
    case UNSPEC:
      goto L13341;
    case PLUS:
      goto L8286;
    case MINUS:
      goto L8300;
    case MULT:
      goto L8314;
    case DIV:
      goto L8328;
    case SQRT:
      goto L8366;
    case SMAX:
      goto L8642;
    case SMIN:
      goto L8656;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8224: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SFmode)
    goto L13346;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13346: ATTRIBUTE_UNUSED_LABEL
  tem = recog_12 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13341: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 3:
      goto L13374;
    case 1:
      goto L13375;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13374: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 41)
    goto L8279;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8279: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8280;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8280: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8281;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8281: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L8282;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8282: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 730;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13375: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 42LL:
      goto L8342;
    case 43LL:
      goto L8354;
    case 45LL:
      goto L8544;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8342: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8343;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8343: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 739;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8354: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8355;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8355: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 741;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8544: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_SSE))
    {
      return 769;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8286: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8287;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8287: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8288;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8288: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 731;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8300: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8301;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8301: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8302;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8302: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 733;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8314: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8315;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8315: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8316;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8316: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 735;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8329;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8329: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8330;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8330: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 737;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8366: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8367;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8367: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 743;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8642: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8643;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8643: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8644;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8644: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 779;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8656: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8657;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8657: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8658;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8658: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 781;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12803: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L8051;
    }
 L12817: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L8107;
    }
  if (register_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L8551;
    }
  goto L9267;

 L8051: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V4SImode))
    {
      operands[1] = x1;
      goto L8052;
    }
  x1 = XEXP (x0, 0);
  goto L12817;

 L8052: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 683;
    }
  x1 = XEXP (x0, 0);
  goto L12817;

 L8107: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V4SImode))
    {
      operands[1] = x1;
      goto L8108;
    }
 L8151: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V4SImode))
    {
      operands[1] = x1;
      goto L8152;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8108: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 697;
    }
  x1 = XEXP (x0, 1);
  goto L8151;

 L8152: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 708;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8551: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SImode)
    goto L13379;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13379: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case NOT:
      goto L8558;
    case VEC_MERGE:
      goto L8565;
    case EQ:
    case LT:
    case LE:
    case UNORDERED:
    case NE:
    case UNGE:
    case UNGT:
    case ORDERED:
    case UNEQ:
    case UNLT:
    case UNLE:
    case LTGT:
    case GE:
    case GT:
      goto L13378;
    default:
      x1 = XEXP (x0, 0);
      goto L9267;
   }
 L13378: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x1, V4SImode))
    {
      operands[3] = x1;
      goto L8552;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (sse_comparison_operator (x2, V4SImode))
    {
      operands[3] = x2;
      goto L8559;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8559: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8560;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8561;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8561: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 772;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode)
    goto L13382;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13382: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8575;
  if (sse_comparison_operator (x2, V4SImode))
    {
      operands[3] = x2;
      goto L8566;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8575: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (sse_comparison_operator (x3, V4SImode))
    {
      operands[3] = x3;
      goto L8576;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8576: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V4SFmode))
    {
      operands[1] = x4;
      goto L8577;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8577: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, V4SFmode))
    {
      operands[2] = x4;
      goto L8578;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8578: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L8579;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8579: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L8580;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8580: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 774;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8566: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8567;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8567: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, V4SFmode))
    {
      operands[2] = x3;
      goto L8568;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8568: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L8569;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8569: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L8570;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8570: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE))
    {
      return 773;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8552: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8553;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8553: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L8554;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8554: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 771;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12804: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V2DImode))
    {
      operands[0] = x1;
      goto L8055;
    }
 L12813: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V2DImode))
    {
      operands[0] = x1;
      goto L8091;
    }
  if (register_operand (x1, V2DImode))
    {
      operands[0] = x1;
      goto L8499;
    }
  goto L9267;

 L8055: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V2DImode))
    {
      operands[1] = x1;
      goto L8056;
    }
  x1 = XEXP (x0, 0);
  goto L12813;

 L8056: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 684;
    }
  x1 = XEXP (x0, 0);
  goto L12813;

 L8091: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V2DImode))
    {
      operands[1] = x1;
      goto L8092;
    }
 L8135: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V2DImode))
    {
      operands[1] = x1;
      goto L8136;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8092: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 693;
    }
  x1 = XEXP (x0, 1);
  goto L8135;

 L8136: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 704;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8499: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DImode)
    goto L13383;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13383: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case AND:
      goto L8500;
    case IOR:
      goto L8526;
    case XOR:
      goto L8538;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8500: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2DImode)
    goto L13387;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13387: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == NOT)
    goto L8514;
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L8501;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8514: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V2DImode))
    {
      operands[1] = x3;
      goto L8515;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[2] = x2;
      goto L8516;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8516: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 764;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[2] = x2;
      goto L8502;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8502: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 762;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L8527;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8527: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[2] = x2;
      goto L8528;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8528: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 766;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8538: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L8539;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8539: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[2] = x2;
      goto L8540;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8540: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 768;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12825: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L8199;
 L12805: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V8QImode))
    {
      operands[0] = x1;
      goto L8059;
    }
 L12820: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V8QImode))
    {
      operands[0] = x1;
      goto L8119;
    }
  if (register_operand (x1, V8QImode))
    {
      operands[0] = x1;
      goto L8737;
    }
  goto L9267;

 L8199: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13388;
    case DImode:
      goto L13389;
    default:
      break;
    }
  goto L12805;

 L13388: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L8200;
    }
  goto L12805;

 L8200: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V8QImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 32)
    goto L8201;
  x1 = XEXP (x0, 0);
  goto L12805;

 L8201: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8202;
    }
  x1 = XEXP (x0, 0);
  goto L12805;

 L8202: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8203;
    }
  x1 = XEXP (x0, 0);
  goto L12805;

 L8203: ATTRIBUTE_UNUSED_LABEL
  if (((TARGET_SSE || TARGET_3DNOW_A) && !TARGET_64BIT))
    {
      return 719;
    }
  x1 = XEXP (x0, 0);
  goto L12805;

 L13389: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L8207;
    }
  goto L12805;

 L8207: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V8QImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 32)
    goto L8208;
  x1 = XEXP (x0, 0);
  goto L12805;

 L8208: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8209;
    }
  x1 = XEXP (x0, 0);
  goto L12805;

 L8209: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8210;
    }
  x1 = XEXP (x0, 0);
  goto L12805;

 L8210: ATTRIBUTE_UNUSED_LABEL
  if (((TARGET_SSE || TARGET_3DNOW_A) && TARGET_64BIT))
    {
      return 720;
    }
  x1 = XEXP (x0, 0);
  goto L12805;

 L8059: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V8QImode))
    {
      operands[1] = x1;
      goto L8060;
    }
  x1 = XEXP (x0, 0);
  goto L12820;

 L8060: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 685;
    }
  x1 = XEXP (x0, 0);
  goto L12820;

 L8119: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V8QImode))
    {
      operands[1] = x1;
      goto L8120;
    }
 L8163: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V8QImode))
    {
      operands[1] = x1;
      goto L8164;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8120: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 700;
    }
  x1 = XEXP (x0, 1);
  goto L8163;

 L8164: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 711;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8737: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V8QImode)
    goto L13390;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13390: ATTRIBUTE_UNUSED_LABEL
  tem = recog_13 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L9267;

 L12806: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V4HImode))
    {
      operands[0] = x1;
      goto L8063;
    }
 L12819: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V4HImode))
    {
      operands[0] = x1;
      goto L8115;
    }
  if (register_operand (x1, V4HImode))
    {
      operands[0] = x1;
      goto L8743;
    }
  goto L9267;

 L8063: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V4HImode))
    {
      operands[1] = x1;
      goto L8064;
    }
  x1 = XEXP (x0, 0);
  goto L12819;

 L8064: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 686;
    }
  x1 = XEXP (x0, 0);
  goto L12819;

 L8115: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V4HImode))
    {
      operands[1] = x1;
      goto L8116;
    }
 L8159: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V4HImode))
    {
      operands[1] = x1;
      goto L8160;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8116: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 699;
    }
  x1 = XEXP (x0, 1);
  goto L8159;

 L8160: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 710;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8743: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4HImode)
    goto L13407;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13407: ATTRIBUTE_UNUSED_LABEL
  tem = recog_14 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L9267;

 L12807: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V2SImode))
    {
      operands[0] = x1;
      goto L8067;
    }
 L12818: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V2SImode))
    {
      operands[0] = x1;
      goto L8111;
    }
  if (register_operand (x1, V2SImode))
    {
      operands[0] = x1;
      goto L8677;
    }
  goto L9267;

 L8067: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V2SImode))
    {
      operands[1] = x1;
      goto L8068;
    }
  x1 = XEXP (x0, 0);
  goto L12818;

 L8068: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 687;
    }
  x1 = XEXP (x0, 0);
  goto L12818;

 L8111: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V2SImode))
    {
      operands[1] = x1;
      goto L8112;
    }
 L8155: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V2SImode))
    {
      operands[1] = x1;
      goto L8156;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8112: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 698;
    }
  x1 = XEXP (x0, 1);
  goto L8155;

 L8156: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 709;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8677: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2SImode)
    goto L13434;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13434: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case VEC_SELECT:
      goto L8678;
    case PLUS:
      goto L8750;
    case MINUS:
      goto L8799;
    case EQ:
      goto L8995;
    case GT:
      goto L9013;
    case ASHIFTRT:
      goto L9049;
    case LSHIFTRT:
      goto L9061;
    case ASHIFT:
      goto L9080;
    case VEC_MERGE:
      goto L9161;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8678: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode)
    goto L13443;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13443: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FIX:
      goto L8679;
    case UNSPEC:
      goto L13445;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8679: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8680;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8680: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 2)
    goto L8681;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8681: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L8682;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8682: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 1LL
      && (TARGET_SSE))
    {
      return 784;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13445: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 30)
    goto L8687;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8687: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8688;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8688: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 2)
    goto L8689;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8689: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L8690;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8690: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 1LL
      && (TARGET_SSE))
    {
      return 785;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8750: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SImode)
    goto L13447;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13447: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MULT)
    goto L8863;
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L8751;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8863: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L8864;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8864: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V2HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L8865;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8865: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, V4HImode))
    {
      operands[1] = x5;
      goto L8866;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8866: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 2)
    goto L8867;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8867: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 0LL)
    goto L8868;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8868: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 2LL)
    goto L8869;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8869: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L8870;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8870: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V2HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L8871;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8871: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V4HImode))
    {
      operands[2] = x5;
      goto L8872;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8872: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 2)
    goto L8873;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8873: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 0LL)
    goto L8874;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8874: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 2LL)
    goto L8875;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8875: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SImode
      && GET_CODE (x2) == MULT)
    goto L8876;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8876: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L8877;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8877: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V2HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L8878;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8878: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L8879;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8879: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 2)
    goto L8880;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8880: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 1LL)
    goto L8881;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8881: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 3LL)
    goto L8882;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L8883;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8883: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V2HImode
      && GET_CODE (x4) == VEC_SELECT)
    goto L8884;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8884: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[2]))
    goto L8885;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8885: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == PARALLEL
      && XVECLEN (x5, 0) == 2)
    goto L8886;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8886: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 0);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 1LL)
    goto L8887;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8887: ATTRIBUTE_UNUSED_LABEL
  x6 = XVECEXP (x5, 0, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 3LL
      && (TARGET_MMX))
    {
      return 811;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8751: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[2] = x2;
      goto L8752;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8752: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 794;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8799: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L8800;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8800: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[2] = x2;
      goto L8801;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8801: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 802;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8995: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L8996;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8996: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[2] = x2;
      goto L8997;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8997: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 825;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9013: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9014;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9014: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[2] = x2;
      goto L9015;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9015: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 828;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9049: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9050;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9050: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9051;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9051: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 834;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9061: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9062;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9062: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9063;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9063: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 836;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9080: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9081;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9081: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, DImode))
    {
      operands[2] = x2;
      goto L9082;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9082: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 839;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2SImode)
    goto L13449;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13449: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L9216;
  if (register_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9162;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9216: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SImode))
    {
      operands[1] = x3;
      goto L9217;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9217: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L9218;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9218: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9219;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9219: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9220;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2SImode))
    {
      operands[2] = x2;
      goto L9221;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9221: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_MMX))
    {
      return 849;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2SImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9163;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9163: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2SImode))
    {
      operands[2] = x3;
      goto L9164;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9164: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L9165;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9165: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L9166;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9166: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9167;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9167: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_MMX))
    {
      return 846;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12808: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L8071;
    }
 L12821: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L8123;
    }
  goto L9267;

 L8071: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V2SFmode))
    {
      operands[1] = x1;
      goto L8072;
    }
  x1 = XEXP (x0, 0);
  goto L12821;

 L8072: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 688;
    }
  x1 = XEXP (x0, 0);
  goto L12821;

 L8123: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V2SFmode))
    {
      operands[1] = x1;
      goto L8124;
    }
 L8167: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V2SFmode))
    {
      operands[1] = x1;
      goto L8168;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8124: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 701;
    }
  x1 = XEXP (x0, 1);
  goto L8167;

 L8168: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 712;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12809: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L8075;
    }
 L12812: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L8087;
    }
  if (register_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L8547;
    }
  goto L9267;

 L8075: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V2DFmode))
    {
      operands[1] = x1;
      goto L8076;
    }
  x1 = XEXP (x0, 0);
  goto L12812;

 L8076: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 689;
    }
  x1 = XEXP (x0, 0);
  goto L12812;

 L8087: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V2DFmode))
    {
      operands[1] = x1;
      goto L8088;
    }
 L8131: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V2DFmode))
    {
      operands[1] = x1;
      goto L8132;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8088: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 692;
    }
  x1 = XEXP (x0, 1);
  goto L8131;

 L8132: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 703;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8547: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DFmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 45)
    goto L8548;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8548: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 770;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12810: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L8079;
    }
 L12814: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L8095;
    }
  goto L9267;

 L8079: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V8HImode))
    {
      operands[1] = x1;
      goto L8080;
    }
  x1 = XEXP (x0, 0);
  goto L12814;

 L8080: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 690;
    }
  x1 = XEXP (x0, 0);
  goto L12814;

 L8095: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V8HImode))
    {
      operands[1] = x1;
      goto L8096;
    }
 L8139: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V8HImode))
    {
      operands[1] = x1;
      goto L8140;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8096: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 694;
    }
  x1 = XEXP (x0, 1);
  goto L8139;

 L8140: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 705;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12811: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L8083;
    }
 L12815: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L8099;
    }
  goto L9267;

 L8083: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (vector_move_operand (x1, V16QImode))
    {
      operands[1] = x1;
      goto L8084;
    }
  x1 = XEXP (x0, 0);
  goto L12815;

 L8084: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 691;
    }
  x1 = XEXP (x0, 0);
  goto L12815;

 L8099: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (register_operand (x1, V16QImode))
    {
      operands[1] = x1;
      goto L8100;
    }
 L8143: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x1, V16QImode))
    {
      operands[1] = x1;
      goto L8144;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8100: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 695;
    }
  x1 = XEXP (x0, 1);
  goto L8143;

 L8144: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 706;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12822: ATTRIBUTE_UNUSED_LABEL
  tem = recog_15 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L9267;

 L12824: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L8189;
    }
 L12841: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L9264;
    }
  goto L9267;

 L8189: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L13481;
  x1 = XEXP (x0, 0);
  goto L12841;

 L13481: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case UNSPEC:
      goto L13484;
    case VEC_SELECT:
      goto L8710;
    case ZERO_EXTEND:
      goto L8969;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12841;

 L13484: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 33)
    goto L8190;
  x1 = XEXP (x0, 0);
  goto L12841;

 L8190: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case V4SFmode:
      goto L13485;
    case V8QImode:
      goto L13486;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L13485: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8191;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8191: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE))
    {
      return 717;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L13486: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8196;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8196: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 718;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8710: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode)
    goto L13487;
  x1 = XEXP (x0, 0);
  goto L12841;

 L13487: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FIX:
      goto L8711;
    case UNSPEC:
      goto L13489;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8711: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8712;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8712: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L8713;
  x1 = XEXP (x0, 0);
  goto L12841;

 L8713: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE))
    {
      return 788;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L13489: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 30)
    goto L8725;
  x1 = XEXP (x0, 0);
  goto L12841;

 L8725: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8726;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8726: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L8727;
  x1 = XEXP (x0, 0);
  goto L12841;

 L8727: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE))
    {
      return 790;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8969: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8970;
  x1 = XEXP (x0, 0);
  goto L12841;

 L8970: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4HImode))
    {
      operands[1] = x3;
      goto L8971;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L8972;
  x1 = XEXP (x0, 0);
  goto L12841;

 L8972: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (immediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L8973;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L8973: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 821;
    }
  x1 = XEXP (x0, 0);
  goto L12841;

 L9264: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == UNSPEC_VOLATILE
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 40)
    goto L9265;
  x1 = XEXP (x0, 0);
  goto L9267;

 L9265: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_SSE))
    {
      return 852;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12827: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L8218;
    }
 L12838: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L8716;
    }
  goto L9267;

 L8218: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 34)
    goto L8219;
  x1 = XEXP (x0, 0);
  goto L12838;

 L8219: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L8220;
    }
  x1 = XEXP (x0, 0);
  goto L12838;

 L8220: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 722;
    }
  x1 = XEXP (x0, 0);
  goto L12838;

 L8716: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L13490;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13490: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case VEC_SELECT:
      goto L8717;
    case UNSPEC:
      goto L13493;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8717: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4DImode)
    goto L13495;
  x1 = XEXP (x0, 0);
  goto L9267;

 L13495: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FIX:
      goto L8718;
    case UNSPEC:
      goto L13497;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8719;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8719: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L8720;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8720: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE))
    {
      return 789;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13497: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 30)
    goto L8732;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8732: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (nonimmediate_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8733;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8733: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L8734;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8734: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE && TARGET_64BIT))
    {
      return 791;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13493: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 1:
      goto L13498;
    case 2:
      goto L13499;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13498: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 45)
    goto L8756;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8756: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == DImode)
    goto L13500;
 L8905: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_MMX))
    {
      return 814;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L13500: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L8757;
    case MINUS:
      goto L8806;
    case IOR:
      goto L8892;
    case XOR:
      goto L8899;
    case AND:
      goto L8910;
    case LSHIFTRT:
      goto L9068;
    case ASHIFT:
      goto L9087;
    default:
     break;
   }
  goto L8905;

 L8757: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8758;
    }
  goto L8905;

 L8758: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L8759;
    }
  goto L8905;

 L8759: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 795;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L8806: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8807;
    }
  goto L8905;

 L8807: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L8808;
    }
  goto L8905;

 L8808: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 803;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L8892: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8893;
    }
  goto L8905;

 L8893: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L8894;
    }
  goto L8905;

 L8894: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 812;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L8899: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8900;
    }
  goto L8905;

 L8900: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L8901;
    }
  goto L8905;

 L8901: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 813;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L8910: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L13508;
  goto L8905;

 L13508: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NOT)
    goto L8918;
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L8911;
    }
  goto L8905;

 L8918: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L8919;
    }
  goto L8905;

 L8919: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L8920;
    }
  goto L8905;

 L8920: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 816;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L8911: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L8912;
    }
  goto L8905;

 L8912: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 815;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L9068: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L9069;
    }
  goto L8905;

 L9069: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L9070;
    }
  goto L8905;

 L9070: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 837;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L9087: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L9088;
    }
  goto L8905;

 L9088: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L9089;
    }
  goto L8905;

 L9089: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_MMX))
    {
      return 840;
    }
  x1 = XEXP (x0, 1);
  x2 = XVECEXP (x1, 0, 0);
  goto L8905;

 L13499: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 61)
    goto L8954;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8954: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L8955;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8955: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L8956;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8956: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE || TARGET_3DNOW_A))
    {
      return 819;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12829: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, SFmode))
    {
      operands[0] = x1;
      goto L8272;
    }
  goto L9267;

 L8272: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SFmode
      && GET_CODE (x1) == VEC_SELECT)
    goto L8273;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8273: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L8274;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8274: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L8275;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8275: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE))
    {
      return 729;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12835: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L8583;
  goto L9267;

 L8583: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPmode
      && GET_CODE (x1) == COMPARE)
    goto L8584;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8585;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8585: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[0] = x3;
      goto L8586;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8586: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L8587;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8587: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L8588;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8588: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8589;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8590;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8590: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L8591;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8591: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE))
    {
      return 775;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L12836: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L8594;
  goto L9267;

 L8594: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPUmode
      && GET_CODE (x1) == COMPARE)
    goto L8595;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8595: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8596;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8596: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[0] = x3;
      goto L8597;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8597: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L8598;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8598: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L8599;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8599: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L8600;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8600: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V4SFmode))
    {
      operands[1] = x3;
      goto L8601;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L8601: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L8602;
  x1 = XEXP (x0, 0);
  goto L9267;

 L8602: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE))
    {
      return 776;
    }
  x1 = XEXP (x0, 0);
  goto L9267;

 L9268: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == BLKmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 44)
    goto L9269;
  x1 = XEXP (x0, 0);
  goto L9294;

 L9269: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, operands[0])
      && (TARGET_SSE || TARGET_3DNOW_A))
    {
      return 853;
    }
  x1 = XEXP (x0, 0);
  goto L9294;

 L12842: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2SFmode))
    {
      operands[0] = x1;
      goto L9295;
    }
  goto L10686;

 L9295: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2SFmode)
    goto L13509;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13509: ATTRIBUTE_UNUSED_LABEL
  tem = recog_16 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L10686;

 L12843: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2SImode))
    {
      operands[0] = x1;
      goto L9313;
    }
  goto L10686;

 L9313: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2SImode)
    goto L13540;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13540: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case GT:
      goto L9314;
    case GE:
      goto L9320;
    case EQ:
      goto L9326;
    case FIX:
      goto L9387;
    case SIGN_EXTEND:
      goto L9392;
    case VEC_SELECT:
      goto L9533;
    case UNSPEC:
      goto L13547;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9314: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9315;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9315: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9316;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9316: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 858;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9320: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9321;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9321: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9322;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9322: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 859;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9326: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9327;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9327: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[2] = x2;
      goto L9328;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9328: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 860;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9387: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case V2SFmode:
      goto L13548;
    case V2DFmode:
      goto L13549;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L13548: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, V2SFmode))
    {
      operands[1] = x2;
      goto L9388;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9388: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 865;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L13549: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9794;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9794: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 918;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9392: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2HImode
      && GET_CODE (x2) == SS_TRUNCATE)
    goto L9393;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9393: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == FIX)
    goto L9394;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9394: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V2SFmode))
    {
      operands[1] = x4;
      goto L9395;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9395: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW_A))
    {
      return 866;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9533: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V2SImode))
    {
      operands[1] = x2;
      goto L9534;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 2)
    goto L9535;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9535: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 1LL)
    goto L9536;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9536: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_3DNOW_A))
    {
      return 879;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L13547: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 30)
    goto L9798;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9798: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9799;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9799: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 919;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12844: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V8QImode))
    {
      operands[0] = x1;
      goto L9482;
    }
  goto L10686;

 L9482: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V8QImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 49)
    goto L9483;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9483: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V8QImode))
    {
      operands[1] = x2;
      goto L9484;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9484: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V8QImode))
    {
      operands[2] = x2;
      goto L9485;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9485: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_3DNOW))
    {
      return 872;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12845: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4HImode))
    {
      operands[0] = x1;
      goto L9516;
    }
  goto L10686;

 L9516: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4HImode
      && GET_CODE (x1) == TRUNCATE)
    goto L9517;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9517: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L9518;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9518: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V4SImode
      && GET_CODE (x3) == PLUS)
    goto L9519;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9519: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V4SImode
      && GET_CODE (x4) == MULT)
    goto L9520;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9520: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == V4SImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L9521;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9521: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, V4HImode))
    {
      operands[1] = x6;
      goto L9522;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9522: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == V4SImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L9523;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9523: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, V4HImode))
    {
      operands[2] = x6;
      goto L9524;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9524: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == V4SImode
      && GET_CODE (x4) == CONST_VECTOR
      && XVECLEN (x4, 0) == 4)
    goto L9525;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9525: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32768LL)
    goto L9526;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9526: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32768LL)
    goto L9527;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9527: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 2);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32768LL)
    goto L9528;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9528: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 3);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32768LL)
    goto L9529;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9529: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 16LL
      && (TARGET_3DNOW))
    {
      return 878;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12846: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L9564;
    }
 L12852: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L9738;
    }
 L12861: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L10579;
    }
 L12865: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L10665;
    }
  goto L10686;

 L9564: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DFmode)
    goto L13550;
  x1 = XEXP (x0, 0);
  goto L12852;

 L13550: ATTRIBUTE_UNUSED_LABEL
  tem = recog_17 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L12852;

 L9738: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DFmode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 34)
    goto L9739;
  x1 = XEXP (x0, 0);
  goto L12861;

 L9739: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9740;
    }
  x1 = XEXP (x0, 0);
  goto L12861;

 L9740: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 909;
    }
  x1 = XEXP (x0, 0);
  goto L12861;

 L10579: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DFmode)
    goto L13578;
  x1 = XEXP (x0, 0);
  goto L12865;

 L13578: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case UNSPEC:
      goto L13581;
    case VEC_MERGE:
      goto L10647;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12865;

 L13581: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13583;
  x1 = XEXP (x0, 0);
  goto L12865;

 L13583: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 38LL:
      goto L10580;
    case 39LL:
      goto L10585;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10580: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10581;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10581: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 1003;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10585: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10586;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10586: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 1004;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10647: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10648;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10648: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10649;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10649: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT)
    goto L13585;
  x1 = XEXP (x0, 0);
  goto L12865;

 L13585: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x2, 0) == XWINT (x2, 0))
    switch ((int) XWINT (x2, 0))
      {
      case 2LL:
        goto L13587;
      case 1LL:
        goto L13588;
      default:
        break;
      }
  x1 = XEXP (x0, 0);
  goto L12865;

 L13587: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && (GET_CODE (operands[1]) == MEM || GET_CODE (operands[2]) == MEM)))
    {
      return 1014;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L13588: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && (GET_CODE (operands[1]) == MEM || GET_CODE (operands[2]) == MEM)))
    {
      return 1015;
    }
  x1 = XEXP (x0, 0);
  goto L12865;

 L10665: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DFmode)
    goto L13589;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13589: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case VEC_MERGE:
      goto L10666;
    case UNSPEC:
      goto L13591;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10666: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10667;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10667: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10668;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10668: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 1017;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L13591: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 3
      && XINT (x1, 1) == 41)
    goto L10678;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10678: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10679;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10679: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10680;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10680: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 2);
  if (immediate_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L10681;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10681: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 1019;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12847: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2DImode))
    {
      operands[0] = x1;
      goto L9660;
    }
 L12853: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, V2DImode))
    {
      operands[0] = x1;
      goto L9743;
    }
  goto L10686;

 L9660: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DImode)
    goto L13593;
  x1 = XEXP (x0, 0);
  goto L12853;

 L13593: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case NOT:
      goto L9667;
    case VEC_MERGE:
      goto L9674;
    case PLUS:
      goto L9907;
    case MINUS:
      goto L9955;
    case MULT:
      goto L10024;
    case UNSPEC:
      goto L13602;
    case LSHIFTRT:
      goto L10246;
    case ASHIFT:
      goto L10264;
    case VEC_CONCAT:
      goto L10612;
    case EQ:
    case LT:
    case LE:
    case UNORDERED:
    case NE:
    case UNGE:
    case UNGT:
    case ORDERED:
    case UNEQ:
    case UNLT:
    case UNLE:
    case LTGT:
    case GE:
    case GT:
      goto L13592;
    default:
      x1 = XEXP (x0, 0);
      goto L12853;
   }
 L13592: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x1, V2DImode))
    {
      operands[3] = x1;
      goto L9661;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9667: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (sse_comparison_operator (x2, V2DImode))
    {
      operands[3] = x2;
      goto L9668;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9668: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9669;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9669: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9670;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9670: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 900;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2DImode)
    goto L13604;
  x1 = XEXP (x0, 0);
  goto L12853;

 L13604: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NOT:
      goto L9684;
    case VEC_SELECT:
      goto L10561;
    case EQ:
    case LT:
    case LE:
    case UNORDERED:
    case NE:
    case UNGE:
    case UNGT:
    case ORDERED:
    case UNEQ:
    case UNLT:
    case UNLE:
    case LTGT:
    case GE:
    case GT:
      goto L13603;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13606;
    default:
      x1 = XEXP (x0, 0);
      goto L12853;
   }
 L13603: ATTRIBUTE_UNUSED_LABEL
  if (sse_comparison_operator (x2, V2DImode))
    {
      operands[3] = x2;
      goto L9675;
    }
 L13606: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L10571;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9684: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (sse_comparison_operator (x3, V2DImode))
    {
      operands[3] = x3;
      goto L9685;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9685: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2DFmode))
    {
      operands[1] = x4;
      goto L9686;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9686: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, V2DFmode))
    {
      operands[2] = x4;
      goto L9687;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9687: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L9688;
  x1 = XEXP (x0, 0);
  goto L12853;

 L9688: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L9689;
  x1 = XEXP (x0, 0);
  goto L12853;

 L9689: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 902;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10561: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10562;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10562: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L10563;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10563: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10564;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10564: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10565;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10565: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L10566;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10566: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 1001;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9676;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9676: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, V2DFmode))
    {
      operands[2] = x3;
      goto L9677;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9677: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L9678;
  x1 = XEXP (x0, 0);
  goto L12853;

 L9678: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L9679;
  x1 = XEXP (x0, 0);
  goto L12853;

 L9679: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 901;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10572;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10572: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10573;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10573: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 2)
    goto L10574;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10574: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L10575;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10575: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10576;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10576: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 1LL
      && (TARGET_SSE2))
    {
      return 1002;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9907: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L9908;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9908: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[2] = x2;
      goto L9909;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9909: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 934;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9955: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L9956;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9956: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DImode))
    {
      operands[2] = x2;
      goto L9957;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9957: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 942;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10024: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V2DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L10025;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10025: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == VEC_SELECT)
    goto L10026;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10026: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V4SImode))
    {
      operands[1] = x4;
      goto L10027;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10027: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 2)
    goto L10028;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10028: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L10029;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10029: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 2LL)
    goto L10030;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10030: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V2DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L10031;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10031: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == VEC_SELECT)
    goto L10032;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10032: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V4SImode))
    {
      operands[2] = x4;
      goto L10033;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10033: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 2)
    goto L10034;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10034: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L10035;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10035: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 2LL
      && (TARGET_SSE2))
    {
      return 951;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L13602: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 61)
    goto L10121;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10121: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10122;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10122: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L10123;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10123: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 956;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10246: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L10247;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10248;
    }
 L10299: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10300;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10248: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 976;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10299;

 L10300: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10301;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10301: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 984;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10264: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L10265;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10265: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonmemory_operand (x2, TImode))
    {
      operands[2] = x2;
      goto L10266;
    }
 L10320: ATTRIBUTE_UNUSED_LABEL
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == SUBREG
      && XINT (x2, 1) == 0)
    goto L10321;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10266: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 979;
    }
  x1 = XEXP (x0, 1);
  x2 = XEXP (x1, 1);
  goto L10320;

 L10321: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonmemory_operand (x3, V2DImode))
    {
      operands[2] = x3;
      goto L10322;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10322: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 987;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10612: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode)
    goto L13608;
  x1 = XEXP (x0, 0);
  goto L12853;

 L13608: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L10623;
  if (nonimmediate_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L10613;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10623: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, V2DImode))
    {
      operands[1] = x3;
      goto L10624;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10624: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L10625;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10625: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L10626;
  x1 = XEXP (x0, 0);
  goto L12853;

 L10626: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 1011;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L10613: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT)
    goto L13609;
  x1 = XEXP (x0, 0);
  goto L12853;

 L13609: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x2, 0) == 0LL)
    goto L13611;
  x1 = XEXP (x0, 0);
  goto L12853;

 L13611: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && !TARGET_64BIT))
    {
      return 1009;
    }
 L13612: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && TARGET_64BIT))
    {
      return 1010;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9662;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9662: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L9663;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9663: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 899;
    }
  x1 = XEXP (x0, 0);
  goto L12853;

 L9743: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 34)
    goto L9744;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9744: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L9745;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9745: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 910;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12848: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L9692;
  goto L10686;

 L9692: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPmode
      && GET_CODE (x1) == COMPARE)
    goto L9693;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9693: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9694;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9694: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[0] = x3;
      goto L9695;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9695: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9696;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9696: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9697;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9697: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9698;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9698: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9699;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9699: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9700;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9700: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 903;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12849: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == REG
      && XINT (x1, 0) == 17)
    goto L9703;
  goto L10686;

 L9703: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CCFPUmode
      && GET_CODE (x1) == COMPARE)
    goto L9704;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9704: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9705;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9705: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[0] = x3;
      goto L9706;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9706: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9707;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9707: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9708;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9708: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9709;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9709: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9710;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9710: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9711;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9711: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 904;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12850: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L9714;
    }
 L12854: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L9748;
    }
 L12864: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, SImode))
    {
      operands[0] = x1;
      goto L10640;
    }
  goto L10686;

 L9714: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode)
    goto L13613;
  x1 = XEXP (x0, 0);
  goto L12854;

 L13613: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case UNSPEC:
      goto L13617;
    case FIX:
      goto L9808;
    case ZERO_EXTEND:
      goto L10136;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12854;

 L13617: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13619;
  x1 = XEXP (x0, 0);
  goto L12854;

 L13619: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 33LL:
      goto L9715;
    case 30LL:
      goto L9822;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9715: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_MODE (x2))
    {
    case V2DFmode:
      goto L13621;
    case V16QImode:
      goto L13622;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L13621: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L9716;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9716: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 905;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L13622: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9721;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9721: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 906;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9822: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9823;
  x1 = XEXP (x0, 0);
  goto L12854;

 L9823: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9824;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9824: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9825;
  x1 = XEXP (x0, 0);
  goto L12854;

 L9825: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 923;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9808: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9809;
  x1 = XEXP (x0, 0);
  goto L12854;

 L9809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9810;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9810: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9811;
  x1 = XEXP (x0, 0);
  goto L12854;

 L9811: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 921;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L10136: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == VEC_SELECT)
    goto L10137;
  x1 = XEXP (x0, 0);
  goto L12854;

 L10137: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V8HImode))
    {
      operands[1] = x3;
      goto L10138;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L10138: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L10139;
  x1 = XEXP (x0, 0);
  goto L12854;

 L10139: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (immediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10140;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L10140: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 958;
    }
  x1 = XEXP (x0, 0);
  goto L12854;

 L9748: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 34)
    goto L9749;
  x1 = XEXP (x0, 0);
  goto L12864;

 L9749: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L9750;
    }
  x1 = XEXP (x0, 0);
  goto L12864;

 L9750: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 911;
    }
  x1 = XEXP (x0, 0);
  goto L12864;

 L10640: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode
      && GET_CODE (x1) == VEC_SELECT)
    goto L10641;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10641: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L10642;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10642: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L10643;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10643: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 1013;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12851: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == MEM)
    goto L9724;
  if (register_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L9888;
    }
 L12862: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L10589;
    }
  goto L10686;

 L9724: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13623;
    case DImode:
      goto L13624;
    default:
      break;
    }
  goto L12862;

 L13623: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L9725;
    }
  goto L12862;

 L9725: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V16QImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 32)
    goto L9726;
  x1 = XEXP (x0, 0);
  goto L12862;

 L9726: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9727;
    }
  x1 = XEXP (x0, 0);
  goto L12862;

 L9727: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9728;
    }
  x1 = XEXP (x0, 0);
  goto L12862;

 L9728: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 907;
    }
  x1 = XEXP (x0, 0);
  goto L12862;

 L13624: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L9732;
    }
  goto L12862;

 L9732: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V16QImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 2
      && XINT (x1, 1) == 32)
    goto L9733;
  x1 = XEXP (x0, 0);
  goto L12862;

 L9733: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L9734;
    }
  x1 = XEXP (x0, 0);
  goto L12862;

 L9734: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (register_operand (x2, V16QImode))
    {
      operands[2] = x2;
      goto L9735;
    }
  x1 = XEXP (x0, 0);
  goto L12862;

 L9735: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 908;
    }
  x1 = XEXP (x0, 0);
  goto L12862;

 L9888: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V16QImode)
    goto L13625;
  x1 = XEXP (x0, 0);
  goto L12862;

 L13625: ATTRIBUTE_UNUSED_LABEL
  tem = recog_18 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L12862;

 L10589: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V16QImode)
    goto L13642;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13642: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L13644;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13644: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13646;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13646: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 38LL:
      goto L10590;
    case 39LL:
      goto L10595;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10590: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10591;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10591: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 1005;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10595: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10596;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10596: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 1006;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12855: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L9753;
    }
  goto L10686;

 L9753: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SFmode)
    goto L13648;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13648: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FLOAT:
      goto L9754;
    case VEC_MERGE:
      goto L9852;
    case SUBREG:
      goto L13651;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9754: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, V4SImode))
    {
      operands[1] = x2;
      goto L9755;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9755: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2))
    {
      return 912;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9852: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L9853;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9853: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == V4SFmode
      && GET_CODE (x2) == VEC_DUPLICATE)
    goto L9854;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9854: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SFmode
      && GET_CODE (x3) == FLOAT_TRUNCATE)
    goto L9855;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9855: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2DFmode))
    {
      operands[2] = x4;
      goto L9856;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9856: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 2);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 14LL
      && (TARGET_SSE2))
    {
      return 927;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L13651: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x1, 1) == 0)
    goto L9871;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9871: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == V4SImode
      && GET_CODE (x2) == VEC_CONCAT)
    goto L9872;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == SUBREG
      && XINT (x3, 1) == 0)
    goto L9873;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9873: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == V2SFmode
      && GET_CODE (x4) == FLOAT_TRUNCATE)
    goto L9874;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9874: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (nonimmediate_operand (x5, V2DFmode))
    {
      operands[1] = x5;
      goto L9875;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L9875: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == V2SImode
      && GET_CODE (x3) == CONST_VECTOR
      && XVECLEN (x3, 0) == 2)
    goto L9876;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9876: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L9877;
  x1 = XEXP (x0, 0);
  goto L10686;

 L9877: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 929;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12856: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4SImode))
    {
      operands[0] = x1;
      goto L9758;
    }
  goto L10686;

 L9758: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SImode)
    goto L13652;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13652: ATTRIBUTE_UNUSED_LABEL
  tem = recog_19 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L10686;

 L12857: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L9814;
    }
 L12863: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x1, DImode))
    {
      operands[0] = x1;
      goto L10599;
    }
  goto L10686;

 L9814: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode)
    goto L13677;
  x1 = XEXP (x0, 0);
  goto L12863;

 L13677: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case FIX:
      goto L9815;
    case UNSPEC:
      goto L13680;
    case MULT:
      goto L10011;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L12863;

 L9815: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9816;
  x1 = XEXP (x0, 0);
  goto L12863;

 L9816: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9817;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L9817: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9818;
  x1 = XEXP (x0, 0);
  goto L12863;

 L9818: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2 && TARGET_64BIT))
    {
      return 922;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L13680: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 30)
    goto L9829;
  x1 = XEXP (x0, 0);
  goto L12863;

 L9829: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == VEC_SELECT)
    goto L9830;
  x1 = XEXP (x0, 0);
  goto L12863;

 L9830: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L9831;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L9831: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L9832;
  x1 = XEXP (x0, 0);
  goto L12863;

 L9832: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_SSE2 && TARGET_64BIT))
    {
      return 924;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L10011: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L10012;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10012: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == VEC_SELECT)
    goto L10013;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10013: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, V2SImode))
    {
      operands[1] = x4;
      goto L10014;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L10014: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L10015;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10015: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L10016;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10016: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L10017;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10017: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == VEC_SELECT)
    goto L10018;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10018: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, V2SImode))
    {
      operands[2] = x4;
      goto L10019;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L10019: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == PARALLEL
      && XVECLEN (x4, 0) == 1)
    goto L10020;
  x1 = XEXP (x0, 0);
  goto L12863;

 L10020: ATTRIBUTE_UNUSED_LABEL
  x5 = XVECEXP (x4, 0, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 950;
    }
  x1 = XEXP (x0, 0);
  goto L12863;

 L10599: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == VEC_SELECT)
    goto L10600;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10600: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DImode))
    {
      operands[1] = x2;
      goto L10601;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10601: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L10602;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10602: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT)
    goto L13681;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13681: ATTRIBUTE_UNUSED_LABEL
  if (XWINT (x3, 0) == 0LL)
    goto L13683;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13683: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && !TARGET_64BIT))
    {
      return 1007;
    }
 L13684: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE2 && TARGET_64BIT))
    {
      return 1008;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12859: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V8HImode))
    {
      operands[0] = x1;
      goto L9894;
    }
  goto L10686;

 L9894: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V8HImode)
    goto L13685;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13685: ATTRIBUTE_UNUSED_LABEL
  tem = recog_20 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x1 = XEXP (x0, 0);
  goto L10686;

 L12860: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, TImode))
    {
      operands[0] = x1;
      goto L10325;
    }
  goto L10686;

 L10325: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == TImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 45)
    goto L10326;
  if (GET_CODE (x1) == CONST_INT
      && XWINT (x1, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 953;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10326: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) == TImode)
    goto L13716;
  x1 = XEXP (x0, 0);
  goto L10686;

 L13716: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ASHIFT:
      goto L10327;
    case LSHIFTRT:
      goto L10335;
    default:
     break;
   }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10327: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L10328;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10328: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L10329;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10329: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (immediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10330;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10330: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL
      && (TARGET_SSE2))
    {
      return 988;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10335: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, TImode))
    {
      operands[1] = x3;
      goto L10336;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10336: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MULT)
    goto L10337;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10337: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (immediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L10338;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10338: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL
      && (TARGET_SSE2))
    {
      return 989;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L12866: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x1, DFmode))
    {
      operands[0] = x1;
      goto L10671;
    }
  goto L10686;

 L10671: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == DFmode
      && GET_CODE (x1) == VEC_SELECT)
    goto L10672;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10672: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10673;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10673: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == PARALLEL
      && XVECLEN (x2, 0) == 1)
    goto L10674;
  x1 = XEXP (x0, 0);
  goto L10686;

 L10674: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL
      && (TARGET_SSE2))
    {
      return 1018;
    }
  x1 = XEXP (x0, 0);
  goto L10686;

 L10687: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == BLKmode)
    goto L13718;
  x1 = XEXP (x0, 0);
  goto L10703;

 L13718: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L13720;
  x1 = XEXP (x0, 0);
  goto L10703;

 L13720: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 1)
    goto L13722;
  x1 = XEXP (x0, 0);
  goto L10703;

 L13722: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 59LL:
      goto L10688;
    case 60LL:
      goto L10692;
    default:
      break;
    }
  x1 = XEXP (x0, 0);
  goto L10703;

 L10688: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, operands[0])
      && (TARGET_SSE2))
    {
      return 1021;
    }
  x1 = XEXP (x0, 0);
  goto L10703;

 L10692: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (rtx_equal_p (x2, operands[0])
      && (TARGET_SSE2))
    {
      return 1022;
    }
  x1 = XEXP (x0, 0);
  goto L10703;

 L12867: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V4SFmode))
    {
      operands[0] = x1;
      goto L10704;
    }
  goto ret0;

 L10704: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V4SFmode)
    goto L13724;
  goto ret0;

 L13724: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x1) == UNSPEC)
    goto L13729;
  goto ret0;

 L13729: ATTRIBUTE_UNUSED_LABEL
  switch (XVECLEN (x1, 0))
    {
    case 2:
      goto L13734;
    case 1:
      goto L13737;
    default:
      break;
    }
  goto ret0;

 L13734: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 71LL:
      goto L10705;
    case 72LL:
      goto L10717;
    case 73LL:
      goto L10729;
    default:
      break;
    }
  goto ret0;

 L10705: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L10706;
    }
  goto ret0;

 L10706: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L10707;
    }
  goto ret0;

 L10707: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1025;
    }
  goto ret0;

 L10717: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L10718;
    }
  goto ret0;

 L10718: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L10719;
    }
  goto ret0;

 L10719: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1027;
    }
  goto ret0;

 L10729: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L10730;
    }
  goto ret0;

 L10730: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[2] = x2;
      goto L10731;
    }
  goto ret0;

 L10731: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1029;
    }
  goto ret0;

 L13737: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 74LL:
      goto L10741;
    case 75LL:
      goto L10746;
    default:
      break;
    }
  goto ret0;

 L10741: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L10742;
    }
  goto ret0;

 L10742: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1031;
    }
  goto ret0;

 L10746: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (nonimmediate_operand (x2, V4SFmode))
    {
      operands[1] = x2;
      goto L10747;
    }
  goto ret0;

 L10747: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1032;
    }
  goto ret0;

 L12868: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V2DFmode))
    {
      operands[0] = x1;
      goto L10710;
    }
  goto ret0;

 L10710: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V2DFmode)
    goto L13739;
  goto ret0;

 L13739: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x1))
    {
    case UNSPEC:
      goto L13743;
    case VEC_DUPLICATE:
      goto L10756;
    default:
     break;
   }
  goto ret0;

 L13743: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x1, 0) == 2)
    goto L13746;
  goto ret0;

 L13746: ATTRIBUTE_UNUSED_LABEL
  switch (XINT (x1, 1))
    {
    case 71LL:
      goto L10711;
    case 72LL:
      goto L10723;
    case 73LL:
      goto L10735;
    default:
      break;
    }
  goto ret0;

 L10711: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10712;
    }
  goto ret0;

 L10712: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10713;
    }
  goto ret0;

 L10713: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1026;
    }
  goto ret0;

 L10723: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10724;
    }
  goto ret0;

 L10724: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10725;
    }
  goto ret0;

 L10725: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1028;
    }
  goto ret0;

 L10735: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (register_operand (x2, V2DFmode))
    {
      operands[1] = x2;
      goto L10736;
    }
  goto ret0;

 L10736: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 1);
  if (nonimmediate_operand (x2, V2DFmode))
    {
      operands[2] = x2;
      goto L10737;
    }
  goto ret0;

 L10737: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1030;
    }
  goto ret0;

 L10756: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DFmode)
    goto L13750;
  goto ret0;

 L13750: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == VEC_SELECT)
    goto L10762;
  if (memory_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L10757;
    }
  goto ret0;

 L10762: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, V2DFmode))
    {
      operands[1] = x3;
      goto L10763;
    }
  goto ret0;

 L10763: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == PARALLEL
      && XVECLEN (x3, 0) == 1)
    goto L10764;
  goto ret0;

 L10764: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL
      && (TARGET_PNI))
    {
      return 1035;
    }
  goto ret0;

 L10757: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1034;
    }
  goto ret0;

 L12869: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x1, V16QImode))
    {
      operands[0] = x1;
      goto L10750;
    }
  goto ret0;

 L10750: ATTRIBUTE_UNUSED_LABEL
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == V16QImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 76)
    goto L10751;
  goto ret0;

 L10751: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (memory_operand (x2, V16QImode))
    {
      operands[1] = x2;
      goto L10752;
    }
  goto ret0;

 L10752: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PNI))
    {
      return 1033;
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
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L286;
    case PLUS:
      goto L1217;
    case MINUS:
      goto L1911;
    case AND:
      goto L2918;
    case IOR:
      goto L3239;
    case XOR:
      goto L3622;
    case NEG:
      goto L4039;
    case ASHIFT:
      goto L4680;
    case ASHIFTRT:
      goto L4942;
    case LSHIFTRT:
      goto L5310;
    case ROTATE:
      goto L5592;
    case ROTATERT:
      goto L5768;
    default:
     break;
   }
  goto ret0;

 L286: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L287;
  goto ret0;

 L287: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L288;
  goto ret0;

 L288: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L289;
  goto ret0;

 L289: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L290;
  goto ret0;

 L290: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L291;
  goto ret0;

 L291: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 4LL
      && (!TARGET_64BIT))
    {
      return 41;
    }
  goto ret0;

 L1217: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L13801;
  goto ret0;

 L13801: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == PLUS)
    goto L1218;
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1437;
    }
  goto ret0;

 L1218: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LTU)
    goto L1219;
  goto ret0;

 L1219: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == CCmode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1220;
  goto ret0;

 L1220: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L1221;
  goto ret0;

 L1221: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1222;
    }
  goto ret0;

 L1222: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1223;
    }
  goto ret0;

 L1223: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1224;
  goto ret0;

 L1224: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (PLUS, SImode, operands)))
    {
      return 182;
    }
  goto ret0;

 L1437: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1438;
    }
  goto ret0;

 L1438: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1439;
  goto ret0;

 L1439: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (PLUS, SImode, operands)))
    {
      return 201;
    }
  goto ret0;

 L1911: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1912;
    }
  goto ret0;

 L1912: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L1913;
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1959;
    }
  goto ret0;

 L1913: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == LTU)
    goto L1914;
  goto ret0;

 L1914: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == CCmode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1915;
  goto ret0;

 L1915: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L1916;
  goto ret0;

 L1916: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1917;
    }
  goto ret0;

 L1917: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1918;
  goto ret0;

 L1918: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 230;
    }
  goto ret0;

 L1959: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1960;
  goto ret0;

 L1960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 232;
    }
  goto ret0;

 L2918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2919;
    }
  goto ret0;

 L2919: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2920;
    }
  goto ret0;

 L2920: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2921;
  goto ret0;

 L2921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (AND, SImode, operands)))
    {
      return 288;
    }
  goto ret0;

 L3239: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L13804;
  goto ret0;

 L13804: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ASHIFT:
      goto L4656;
    case ASHIFTRT:
      goto L4918;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13803;
    default:
      goto ret0;
   }
 L13803: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3240;
    }
  goto ret0;

 L4656: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[0]))
    goto L4657;
  goto ret0;

 L4657: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4658;
    }
  goto ret0;

 L4658: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L4659;
  goto ret0;

 L4659: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4660;
    }
  goto ret0;

 L4660: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == QImode
      && GET_CODE (x4) == MINUS)
    goto L4661;
  goto ret0;

 L4661: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L4662;
  goto ret0;

 L4662: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    goto L4663;
  goto ret0;

 L4663: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4664;
  goto ret0;

 L4664: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 412;
    }
  goto ret0;

 L4918: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[0]))
    goto L4919;
  goto ret0;

 L4919: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4920;
    }
  goto ret0;

 L4920: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ASHIFT)
    goto L4921;
  goto ret0;

 L4921: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4922;
    }
  goto ret0;

 L4922: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == QImode
      && GET_CODE (x4) == MINUS)
    goto L4923;
  goto ret0;

 L4923: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L4924;
  goto ret0;

 L4924: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (rtx_equal_p (x5, operands[2]))
    goto L4925;
  goto ret0;

 L4925: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4926;
  goto ret0;

 L4926: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 430;
    }
  goto ret0;

 L3240: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3241;
    }
  goto ret0;

 L3241: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3242;
  goto ret0;

 L3242: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (IOR, SImode, operands)))
    {
      return 306;
    }
  goto ret0;

 L3622: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L3623;
    }
  goto ret0;

 L3623: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L3624;
    }
  goto ret0;

 L3624: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3625;
  goto ret0;

 L3625: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (XOR, SImode, operands)))
    {
      return 328;
    }
  goto ret0;

 L4039: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4040;
    }
  goto ret0;

 L4040: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4041;
  goto ret0;

 L4041: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (NEG, SImode, operands)))
    {
      return 352;
    }
  goto ret0;

 L4680: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4681;
    }
  goto ret0;

 L4681: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4682;
    }
  goto ret0;

 L4682: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4683;
  goto ret0;

 L4683: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFT, SImode, operands)))
    {
      return 413;
    }
  goto ret0;

 L4942: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L4943;
    }
  goto ret0;

 L4943: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L13806;
 L5003: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5004;
    }
  goto ret0;

 L13806: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L4944;
    }
 L13807: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4974;
    }
  goto L5003;

 L4944: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4945;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L13807;

 L4945: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (INTVAL (operands[2]) == 31 && (TARGET_USE_CLTD || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 431;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L13807;

 L4974: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4975;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5003;

 L4975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 433;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5003;

 L5004: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5005;
  goto ret0;

 L5005: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 435;
    }
  goto ret0;

 L5310: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5311;
    }
  goto ret0;

 L5311: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5312;
    }
 L5341: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5342;
    }
  goto ret0;

 L5312: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5313;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5341;

 L5313: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 457;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5341;

 L5342: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5343;
  goto ret0;

 L5343: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 459;
    }
  goto ret0;

 L5592: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5593;
    }
  goto ret0;

 L5593: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5594;
    }
 L5623: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5624;
    }
  goto ret0;

 L5594: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5595;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5623;

 L5595: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATE, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 477;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5623;

 L5624: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5625;
  goto ret0;

 L5625: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATE, SImode, operands)))
    {
      return 479;
    }
  goto ret0;

 L5768: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L5769;
    }
  goto ret0;

 L5769: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5770;
    }
 L5799: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5800;
    }
  goto ret0;

 L5770: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5771;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5799;

 L5771: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATERT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 489;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5799;

 L5800: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5801;
  goto ret0;

 L5801: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATERT, SImode, operands)))
    {
      return 491;
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
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L13778;
    case ZERO_EXTRACT:
      goto L1753;
    default:
     break;
   }
 L13752: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L285;
    }
 L13753: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L329;
    }
  goto ret0;

 L13778: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L265;
    }
  goto L13752;

 L265: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_no_elim_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L266;
    }
  x2 = XEXP (x1, 0);
  goto L13752;

 L266: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L267;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13752;

 L267: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L268;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13752;

 L268: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (!TARGET_64BIT))
    {
      return 39;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13752;

 L1753: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L1754;
    }
  goto ret0;

 L1754: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L1755;
  goto ret0;

 L1755: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L1756;
  goto ret0;

 L1756: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L13779;
  goto ret0;

 L13779: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1757;
    case AND:
      goto L3062;
    case IOR:
      goto L3467;
    case XOR:
      goto L3805;
    default:
     break;
   }
  goto ret0;

 L1757: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L1758;
  goto ret0;

 L1758: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L1759;
    }
  goto ret0;

 L1759: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L1760;
  goto ret0;

 L1760: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L1813;
  goto ret0;

 L1813: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L1814;
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1762;
    }
 L1787: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1788;
    }
  goto ret0;

 L1814: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L1815;
    }
  goto ret0;

 L1815: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L1816;
  goto ret0;

 L1816: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L1817;
  goto ret0;

 L1817: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1818;
  goto ret0;

 L1818: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 224;
    }
  goto ret0;

 L1762: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1763;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1787;

 L1763: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 222;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1787;

 L1788: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1789;
  goto ret0;

 L1789: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT))
    {
      return 223;
    }
  goto ret0;

 L3062: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L3063;
  goto ret0;

 L3063: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L3064;
    }
  goto ret0;

 L3064: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3065;
  goto ret0;

 L3065: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3114;
  goto ret0;

 L3114: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L13783;
 L3066: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3067;
    }
  goto ret0;

 L13783: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L3115;
    case ZERO_EXTRACT:
      goto L3171;
    default:
     break;
   }
  goto L3066;

 L3115: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3116;
    }
 L3143: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3144;
    }
  goto L3066;

 L3116: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3117;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L3143;

 L3117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 300;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L3143;

 L3144: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3145;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3066;

 L3145: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT))
    {
      return 301;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3066;

 L3171: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3172;
    }
  goto L3066;

 L3172: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3173;
  goto L3066;

 L3173: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3174;
  goto L3066;

 L3174: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3175;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3066;

 L3175: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 302;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3066;

 L3067: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3068;
  goto ret0;

 L3068: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 298;
    }
  goto ret0;

 L3467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L3468;
  goto ret0;

 L3468: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L3469;
    }
  goto ret0;

 L3469: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3470;
  goto ret0;

 L3470: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3497;
  goto ret0;

 L3497: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L13785;
 L3471: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3472;
    }
  goto ret0;

 L13785: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L3498;
    case ZERO_EXTRACT:
      goto L3554;
    default:
     break;
   }
  goto L3471;

 L3498: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3499;
    }
 L3526: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3527;
    }
  goto L3471;

 L3499: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3500;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L3526;

 L3500: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 322;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L3526;

 L3527: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3528;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3471;

 L3528: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 323;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3471;

 L3554: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3555;
    }
  goto L3471;

 L3555: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3556;
  goto L3471;

 L3556: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3557;
  goto L3471;

 L3557: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3558;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3471;

 L3558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 324;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3471;

 L3472: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3473;
  goto ret0;

 L3473: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 321;
    }
  goto ret0;

 L3805: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L3806;
  goto ret0;

 L3806: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L3807;
    }
  goto ret0;

 L3807: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3808;
  goto ret0;

 L3808: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3835;
  goto ret0;

 L3835: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == SImode)
    goto L13787;
 L3809: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, VOIDmode))
    {
      operands[2] = x3;
      goto L3810;
    }
  goto ret0;

 L13787: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L3836;
    case ZERO_EXTRACT:
      goto L3892;
    default:
     break;
   }
  goto L3809;

 L3836: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3837;
    }
 L3864: ATTRIBUTE_UNUSED_LABEL
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3865;
    }
  goto L3809;

 L3837: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3838;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L3864;

 L3838: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 341;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  goto L3864;

 L3865: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3866;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3809;

 L3866: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 342;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3809;

 L3892: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (ext_register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3893;
    }
  goto L3809;

 L3893: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3894;
  goto L3809;

 L3894: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3895;
  goto L3809;

 L3895: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3896;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3809;

 L3896: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 343;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L3809;

 L3810: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3811;
  goto ret0;

 L3811: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((!TARGET_PARTIAL_REG_STALL || optimize_size)))
    {
      return 340;
    }
  goto ret0;

 L285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L13789;
  x2 = XEXP (x1, 0);
  goto L13753;

 L13789: ATTRIBUTE_UNUSED_LABEL
  tem = recog_22 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L13753;

 L329: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L13809;
 L295: ATTRIBUTE_UNUSED_LABEL
  if (const0_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L296;
    }
 L305: ATTRIBUTE_UNUSED_LABEL
  if (immediate_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L306;
    }
  goto ret0;

 L13809: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L675;
    case MULT:
      goto L2143;
    case DIV:
      goto L2581;
    case UDIV:
      goto L2734;
    case UNSPEC:
      goto L13816;
    case PLUS:
      goto L6498;
    case IF_THEN_ELSE:
      goto L7495;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13808;
    default:
      goto L295;
   }
 L13808: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L330;
    }
  goto L295;

 L675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case HImode:
      goto L13817;
    case QImode:
      goto L13818;
    default:
      break;
    }
  goto L295;

 L13817: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L676;
    }
  goto L295;

 L676: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L677;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L677: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_ZERO_EXTEND_WITH_AND && !optimize_size))
    {
      return 106;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L13818: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L722;
    }
  goto L295;

 L722: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L723;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L723: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13819;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L13819: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13821;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L13821: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13823;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L13823: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ZERO_EXTEND_WITH_AND && !optimize_size))
    {
      return 111;
    }
 L13824: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size))
    {
      return 112;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2143: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2144;
    }
  goto L295;

 L2144: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2145;
    }
  goto L295;

 L2145: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2146;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2146: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
    {
      return 246;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2581: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2582;
    }
  goto L295;

 L2582: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L2583;
    }
  goto L295;

 L2583: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2584;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2584: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2585;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2585: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L2586;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2586: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L2587;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (!optimize_size && !TARGET_USE_CLTD)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 267;
    }
 L2611: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[3])
      && (optimize_size || TARGET_USE_CLTD)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 268;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2734: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2735;
    }
  goto L295;

 L2735: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2736;
    }
  goto L295;

 L2736: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2737;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2737: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2738;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2738: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L2739;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2739: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2740;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L2740: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 273;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L13816: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 12)
    goto L6316;
  goto L295;

 L6316: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6317;
  goto L295;

 L6317: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6318;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L6318: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 531;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L6498: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == UNSPEC
      && XVECLEN (x3, 0) == 1
      && XINT (x3, 1) == 15)
    goto L6499;
  goto L295;

 L6499: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6500;
  goto L295;

 L6500: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6501;
    }
  goto L295;

 L6501: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6502;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L6502: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 546;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L7495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == LTU)
    goto L7496;
  goto L295;

 L7496: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == CCmode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L7497;
  goto L295;

 L7497: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7498;
  goto L295;

 L7498: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7499;
  goto L295;

 L7499: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7500;
  goto L295;

 L7500: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7501;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L7501: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 638;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L330: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L331;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L332;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0]))
    {
      return 47;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L295;

 L296: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L297;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L305;

 L297: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (reload_completed && (!TARGET_USE_MOV0 || optimize_size)))
    {
      return 42;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L305;

 L306: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L307;
  goto ret0;

 L307: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (reload_completed && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) == -1
   && (TARGET_PENTIUM || optimize_size)))
    {
      return 43;
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
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L358;
    }
 L13766: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1555;
    }
  goto ret0;

 L358: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L13826;
  x2 = XEXP (x1, 0);
  goto L13766;

 L13826: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L692;
    case MULT:
      goto L2173;
    case DIV:
      goto L2658;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13825;
    default:
      x2 = XEXP (x1, 0);
      goto L13766;
   }
 L13825: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L359;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L692: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L693;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L693: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L694;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L694: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13829;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L13829: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13831;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L13831: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13833;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L13833: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_ZERO_EXTEND_WITH_AND && !optimize_size))
    {
      return 108;
    }
 L13834: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_ZERO_EXTEND_WITH_AND || optimize_size))
    {
      return 109;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2173: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == HImode)
    goto L13836;
  x2 = XEXP (x1, 0);
  goto L13766;

 L13836: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2202;
    case SIGN_EXTEND:
      goto L2220;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13835;
    default:
      x2 = XEXP (x1, 0);
      goto L13766;
   }
 L13835: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2174;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2202: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L2203;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2203: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L2204;
  x2 = XEXP (x1, 0);
  goto L13766;

 L2204: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L2205;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2205: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2206;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2206: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_QIMODE_MATH
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 250;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2220: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L2221;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2221: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == HImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L2222;
  x2 = XEXP (x1, 0);
  goto L13766;

 L2222: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L2223;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2223: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2224;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2224: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_QIMODE_MATH
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 251;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2174: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2175;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2175: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2176;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2176: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
    {
      return 248;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2658: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2659;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2659: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2660;
    }
  x2 = XEXP (x1, 0);
  goto L13766;

 L2660: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2661;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2661: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L2662;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2662: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MOD)
    goto L2663;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2663: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2664;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L2664: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_HIMODE_MATH)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 270;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L359: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L360;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L360: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L361;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L361: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0])
      && (TARGET_PARTIAL_REG_STALL))
    {
      return 53;
    }
 L368: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x2, operands[0])
      && (! TARGET_PARTIAL_REG_STALL))
    {
      return 54;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13766;

 L1555: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L13838;
  goto ret0;

 L13838: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1556;
    case MINUS:
      goto L2037;
    case AND:
      goto L2975;
    case IOR:
      goto L3344;
    case XOR:
      goto L3727;
    case NEG:
      goto L4100;
    case ASHIFT:
      goto L4737;
    case ASHIFTRT:
      goto L5086;
    case LSHIFTRT:
      goto L5424;
    case ROTATE:
      goto L5652;
    case ROTATERT:
      goto L5828;
    default:
     break;
   }
  goto ret0;

 L1556: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L1557;
    }
  goto ret0;

 L1557: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L1558;
    }
  goto ret0;

 L1558: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1559;
  goto ret0;

 L1559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13849;
  goto ret0;

 L13849: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13851;
  goto ret0;

 L13851: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13853;
  goto ret0;

 L13853: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands)))
    {
      return 209;
    }
 L13854: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, HImode, operands)))
    {
      return 210;
    }
  goto ret0;

 L2037: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2038;
    }
  goto ret0;

 L2038: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2039;
    }
  goto ret0;

 L2039: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2040;
  goto ret0;

 L2040: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (MINUS, HImode, operands)))
    {
      return 238;
    }
  goto ret0;

 L2975: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2976;
    }
  goto ret0;

 L2976: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2977;
    }
  goto ret0;

 L2977: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2978;
  goto ret0;

 L2978: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (AND, HImode, operands)))
    {
      return 292;
    }
  goto ret0;

 L3344: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L3345;
    }
  goto ret0;

 L3345: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L3346;
    }
  goto ret0;

 L3346: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3347;
  goto ret0;

 L3347: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (IOR, HImode, operands)))
    {
      return 313;
    }
  goto ret0;

 L3727: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L3728;
    }
  goto ret0;

 L3728: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L3729;
    }
  goto ret0;

 L3729: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3730;
  goto ret0;

 L3730: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (XOR, HImode, operands)))
    {
      return 335;
    }
  goto ret0;

 L4100: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L4101;
    }
  goto ret0;

 L4101: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4102;
  goto ret0;

 L4102: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (NEG, HImode, operands)))
    {
      return 356;
    }
  goto ret0;

 L4737: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L4738;
    }
  goto ret0;

 L4738: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4739;
    }
  goto ret0;

 L4739: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4740;
  goto ret0;

 L4740: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13855;
  goto ret0;

 L13855: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13857;
  goto ret0;

 L13857: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13859;
  goto ret0;

 L13859: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)))
    {
      return 417;
    }
 L13860: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)))
    {
      return 418;
    }
  goto ret0;

 L5086: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L5087;
    }
  goto ret0;

 L5087: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5088;
    }
 L5101: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5102;
    }
  goto ret0;

 L5088: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5089;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5101;

 L5089: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 441;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5101;

 L5102: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5103;
  goto ret0;

 L5103: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, HImode, operands)))
    {
      return 442;
    }
  goto ret0;

 L5424: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L5425;
    }
  goto ret0;

 L5425: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5426;
    }
 L5439: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5440;
    }
  goto ret0;

 L5426: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5427;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5439;

 L5427: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 465;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5439;

 L5440: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5441;
  goto ret0;

 L5441: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 466;
    }
  goto ret0;

 L5652: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L5653;
    }
  goto ret0;

 L5653: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5654;
    }
 L5667: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5668;
    }
  goto ret0;

 L5654: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5655;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5667;

 L5655: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATE, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 481;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5667;

 L5668: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5669;
  goto ret0;

 L5669: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATE, HImode, operands)))
    {
      return 482;
    }
  goto ret0;

 L5828: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L5829;
    }
  goto ret0;

 L5829: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5830;
    }
 L5843: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5844;
    }
  goto ret0;

 L5830: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5831;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5843;

 L5831: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATERT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 493;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5843;

 L5844: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5845;
  goto ret0;

 L5845: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATERT, HImode, operands)))
    {
      return 494;
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
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L532;
    case ZERO_EXTEND:
      goto L750;
    case PLUS:
      goto L1170;
    case MINUS:
      goto L1837;
    case AND:
      goto L2891;
    case IOR:
      goto L3194;
    case XOR:
      goto L3577;
    case NEG:
      goto L4004;
    case ASHIFT:
      goto L4598;
    case ASHIFTRT:
      goto L4819;
    case LSHIFTRT:
      goto L5226;
    case ROTATE:
      goto L5564;
    case ROTATERT:
      goto L5740;
    default:
     break;
   }
  goto ret0;

 L532: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L533;
  goto ret0;

 L533: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L534;
  goto ret0;

 L534: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L535;
  goto ret0;

 L535: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L536;
  goto ret0;

 L536: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L537;
  goto ret0;

 L537: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL
      && (TARGET_64BIT))
    {
      return 79;
    }
  goto ret0;

 L750: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L751;
    }
  goto ret0;

 L751: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L752;
  goto ret0;

 L752: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 114;
    }
  goto ret0;

 L1170: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L13902;
  goto ret0;

 L13902: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == PLUS)
    goto L1185;
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1171;
    }
  goto ret0;

 L1185: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == LTU)
    goto L1186;
  goto ret0;

 L1186: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == CCmode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1187;
  goto ret0;

 L1187: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L1188;
  goto ret0;

 L1188: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L1189;
    }
  goto ret0;

 L1189: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1190;
    }
  goto ret0;

 L1190: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1191;
  goto ret0;

 L1191: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands)))
    {
      return 180;
    }
  goto ret0;

 L1171: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1172;
    }
 L1360: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1361;
    }
  goto ret0;

 L1172: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1173;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1360;

 L1173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands)))
    {
      return 179;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1360;

 L1361: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1362;
  goto ret0;

 L1362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands)))
    {
      return 196;
    }
  goto ret0;

 L1837: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1852;
    }
  goto ret0;

 L1852: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == PLUS)
    goto L1853;
  if (general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1839;
    }
 L1874: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1875;
    }
  goto ret0;

 L1853: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == LTU)
    goto L1854;
  goto ret0;

 L1854: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == CCmode
      && GET_CODE (x5) == REG
      && XINT (x5, 0) == 17)
    goto L1855;
  goto ret0;

 L1855: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 0LL)
    goto L1856;
  goto ret0;

 L1856: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x86_64_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1857;
    }
  goto ret0;

 L1857: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1858;
  goto ret0;

 L1858: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (MINUS, DImode, operands)))
    {
      return 226;
    }
  goto ret0;

 L1839: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1840;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1874;

 L1840: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && ix86_binary_operator_ok (MINUS, DImode, operands)))
    {
      return 225;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1874;

 L1875: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1876;
  goto ret0;

 L1876: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (MINUS, DImode, operands)))
    {
      return 227;
    }
  goto ret0;

 L2891: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2892;
    }
  goto ret0;

 L2892: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_szext_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2893;
    }
  goto ret0;

 L2893: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2894;
  goto ret0;

 L2894: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (AND, DImode, operands)))
    {
      return 286;
    }
  goto ret0;

 L3194: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3195;
    }
  goto ret0;

 L3195: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3196;
    }
  goto ret0;

 L3196: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3197;
  goto ret0;

 L3197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && ix86_binary_operator_ok (IOR, DImode, operands)))
    {
      return 303;
    }
  goto ret0;

 L3577: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L3578;
    }
  goto ret0;

 L3578: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3579;
    }
  goto ret0;

 L3579: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3580;
  goto ret0;

 L3580: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && ix86_binary_operator_ok (XOR, DImode, operands)))
    {
      return 325;
    }
  goto ret0;

 L4004: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (general_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4005;
    }
 L4016: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4017;
    }
  goto ret0;

 L4005: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4006;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4016;

 L4006: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT
   && ix86_unary_operator_ok (NEG, DImode, operands)))
    {
      return 349;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L4016;

 L4017: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4018;
  goto ret0;

 L4018: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_unary_operator_ok (NEG, DImode, operands)))
    {
      return 350;
    }
  goto ret0;

 L4598: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4599;
    }
  goto ret0;

 L4599: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4600;
    }
  goto ret0;

 L4600: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4601;
  goto ret0;

 L4601: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, DImode, operands)))
    {
      return 408;
    }
  goto ret0;

 L4819: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4820;
    }
  goto ret0;

 L4820: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L13903;
 L4848: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4849;
    }
  goto ret0;

 L13903: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L4821;
    }
 L13904: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4835;
    }
  goto L4848;

 L4821: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4822;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L13904;

 L4822: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && INTVAL (operands[2]) == 63 && (TARGET_USE_CLTD || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)))
    {
      return 423;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L13904;

 L4835: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4836;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L4848;

 L4836: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 424;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L4848;

 L4849: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4850;
  goto ret0;

 L4850: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)))
    {
      return 425;
    }
  goto ret0;

 L5226: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L5227;
    }
  goto ret0;

 L5227: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5228;
    }
 L5241: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5242;
    }
  goto ret0;

 L5228: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5229;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5241;

 L5229: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 451;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5241;

 L5242: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5243;
  goto ret0;

 L5243: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 452;
    }
  goto ret0;

 L5564: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L5565;
    }
  goto ret0;

 L5565: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5566;
    }
 L5579: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5580;
    }
  goto ret0;

 L5566: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5567;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5579;

 L5567: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 475;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5579;

 L5580: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5581;
  goto ret0;

 L5581: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATE, DImode, operands)))
    {
      return 476;
    }
  goto ret0;

 L5740: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L5741;
    }
  goto ret0;

 L5741: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5742;
    }
 L5755: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5756;
    }
  goto ret0;

 L5742: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5743;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5755;

 L5743: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 487;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5755;

 L5756: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5757;
  goto ret0;

 L5757: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, DImode, operands)))
    {
      return 488;
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
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case ZERO_EXTEND:
      goto L1239;
    case MULT:
      goto L2129;
    case DIV:
      goto L2504;
    case UDIV:
      goto L2682;
    case IOR:
      goto L3269;
    case XOR:
      goto L3652;
    case LSHIFTRT:
      goto L4051;
    case ASHIFT:
      goto L4641;
    case ASHIFTRT:
      goto L4903;
    case PLUS:
      goto L6514;
    case IF_THEN_ELSE:
      goto L7467;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13905;
    default:
      goto ret0;
   }
 L13905: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L580;
    }
  goto ret0;

 L1239: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L13917;
  goto ret0;

 L13917: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1240;
    case MINUS:
      goto L1934;
    case MULT:
      goto L2158;
    case AND:
      goto L2933;
    case IOR:
      goto L3254;
    case XOR:
      goto L3637;
    case ASHIFT:
      goto L4695;
    case ASHIFTRT:
      goto L4957;
    case LSHIFTRT:
      goto L5355;
    case ROTATE:
      goto L5607;
    case ROTATERT:
      goto L5783;
    default:
     break;
   }
  goto ret0;

 L1240: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L13928;
  goto ret0;

 L13928: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == PLUS)
    goto L1241;
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1452;
    }
  goto ret0;

 L1241: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == LTU)
    goto L1242;
  goto ret0;

 L1242: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == CCmode
      && GET_CODE (x6) == REG
      && XINT (x6, 0) == 17)
    goto L1243;
  goto ret0;

 L1243: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 0LL)
    goto L1244;
  goto ret0;

 L1244: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (nonimmediate_operand (x5, SImode))
    {
      operands[1] = x5;
      goto L1245;
    }
  goto ret0;

 L1245: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1246;
    }
  goto ret0;

 L1246: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1247;
  goto ret0;

 L1247: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands)))
    {
      return 183;
    }
  goto ret0;

 L1452: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1453;
    }
  goto ret0;

 L1453: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1454;
  goto ret0;

 L1454: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (PLUS, SImode, operands)))
    {
      return 202;
    }
  goto ret0;

 L1934: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1935;
    }
  goto ret0;

 L1935: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_MODE (x4) == SImode
      && GET_CODE (x4) == PLUS)
    goto L1936;
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1974;
    }
  goto ret0;

 L1936: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == SImode
      && GET_CODE (x5) == LTU)
    goto L1937;
  goto ret0;

 L1937: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == CCmode
      && GET_CODE (x6) == REG
      && XINT (x6, 0) == 17)
    goto L1938;
  goto ret0;

 L1938: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 0LL)
    goto L1939;
  goto ret0;

 L1939: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (general_operand (x5, SImode))
    {
      operands[2] = x5;
      goto L1940;
    }
  goto ret0;

 L1940: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1941;
  goto ret0;

 L1941: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 231;
    }
  goto ret0;

 L1974: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1975;
  goto ret0;

 L1975: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 233;
    }
  goto ret0;

 L2158: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2159;
    }
  goto ret0;

 L2159: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2160;
    }
  goto ret0;

 L2160: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2161;
  goto ret0;

 L2161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 247;
    }
  goto ret0;

 L2933: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2934;
    }
  goto ret0;

 L2934: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2935;
    }
  goto ret0;

 L2935: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2936;
  goto ret0;

 L2936: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (AND, SImode, operands)))
    {
      return 289;
    }
  goto ret0;

 L3254: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3255;
    }
  goto ret0;

 L3255: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3256;
    }
  goto ret0;

 L3256: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3257;
  goto ret0;

 L3257: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (IOR, SImode, operands)))
    {
      return 307;
    }
  goto ret0;

 L3637: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3638;
    }
  goto ret0;

 L3638: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3639;
    }
  goto ret0;

 L3639: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3640;
  goto ret0;

 L3640: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands)))
    {
      return 329;
    }
  goto ret0;

 L4695: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4696;
    }
  goto ret0;

 L4696: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4697;
    }
  goto ret0;

 L4697: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4698;
  goto ret0;

 L4698: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ASHIFT, SImode, operands)))
    {
      return 414;
    }
  goto ret0;

 L4957: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4958;
    }
  goto ret0;

 L4958: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L13930;
 L5018: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5019;
    }
  goto ret0;

 L13930: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L4959;
    }
 L13931: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4989;
    }
  goto L5018;

 L4959: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4960;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L13931;

 L4960: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && (TARGET_USE_CLTD || optimize_size)
   && INTVAL (operands[2]) == 31
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 432;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L13931;

 L4989: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4990;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5018;

 L4990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 434;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5018;

 L5019: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5020;
  goto ret0;

 L5020: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 436;
    }
  goto ret0;

 L5355: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5356;
    }
  goto ret0;

 L5356: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5357;
    }
  goto ret0;

 L5357: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5358;
  goto ret0;

 L5358: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 460;
    }
  goto ret0;

 L5607: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5608;
    }
  goto ret0;

 L5608: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5609;
    }
 L5638: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5639;
    }
  goto ret0;

 L5609: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5610;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5638;

 L5610: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 478;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5638;

 L5639: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5640;
  goto ret0;

 L5640: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATE, SImode, operands)))
    {
      return 480;
    }
  goto ret0;

 L5783: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5784;
    }
  goto ret0;

 L5784: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5785;
    }
 L5814: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5815;
    }
  goto ret0;

 L5785: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5786;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5814;

 L5786: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 490;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5814;

 L5815: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5816;
  goto ret0;

 L5816: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (ROTATERT, SImode, operands)))
    {
      return 492;
    }
  goto ret0;

 L2129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L13933;
  goto ret0;

 L13933: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2256;
    case SIGN_EXTEND:
      goto L2292;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L13932;
    default:
      goto ret0;
   }
 L13932: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2130;
    }
  goto ret0;

 L2256: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2257;
    }
  goto ret0;

 L2257: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L2258;
  goto ret0;

 L2258: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2259;
    }
  goto ret0;

 L2259: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2260;
  goto ret0;

 L2260: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 253;
    }
  goto ret0;

 L2292: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2293;
    }
  goto ret0;

 L2293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L2294;
  goto ret0;

 L2294: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2295;
    }
  goto ret0;

 L2295: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2296;
  goto ret0;

 L2296: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 255;
    }
  goto ret0;

 L2130: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2131;
    }
  goto ret0;

 L2131: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2132;
  goto ret0;

 L2132: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 245;
    }
  goto ret0;

 L2504: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2505;
    }
  goto ret0;

 L2505: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L2506;
    }
  goto ret0;

 L2506: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2507;
  goto ret0;

 L2507: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2508;
    }
  goto ret0;

 L2508: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MOD)
    goto L2509;
  goto ret0;

 L2509: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L2510;
  goto ret0;

 L2510: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_64BIT && !optimize_size && !TARGET_USE_CLTD)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 264;
    }
 L2534: ATTRIBUTE_UNUSED_LABEL
  if (rtx_equal_p (x3, operands[3])
      && (TARGET_64BIT && (optimize_size || TARGET_USE_CLTD))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 265;
    }
  goto ret0;

 L2682: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2683;
    }
  goto ret0;

 L2683: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2684;
    }
  goto ret0;

 L2684: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2685;
  goto ret0;

 L2685: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2686;
    }
  goto ret0;

 L2686: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == UMOD)
    goto L2687;
  goto ret0;

 L2687: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2688;
  goto ret0;

 L2688: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 271;
    }
  goto ret0;

 L3269: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L3270;
  goto ret0;

 L3270: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3271;
    }
  goto ret0;

 L3271: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_zext_immediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3272;
    }
  goto ret0;

 L3272: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3273;
  goto ret0;

 L3273: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT))
    {
      return 308;
    }
  goto ret0;

 L3652: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L3653;
  goto ret0;

 L3653: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3654;
    }
  goto ret0;

 L3654: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_zext_immediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L3655;
    }
  goto ret0;

 L3655: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3656;
  goto ret0;

 L3656: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (XOR, SImode, operands)))
    {
      return 330;
    }
  goto ret0;

 L4051: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L13935;
  goto ret0;

 L13935: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case NEG:
      goto L4052;
    case ZERO_EXTEND:
      goto L5325;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13936;
    default:
      goto ret0;
   }
 L13936: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L5297;
    }
  goto ret0;

 L4052: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ASHIFT)
    goto L4053;
  goto ret0;

 L4053: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (register_operand (x5, DImode))
    {
      operands[1] = x5;
      goto L4054;
    }
  goto ret0;

 L4054: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L4055;
  goto ret0;

 L4055: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 32LL)
    goto L4056;
  goto ret0;

 L4056: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4057;
  goto ret0;

 L4057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_unary_operator_ok (NEG, SImode, operands)))
    {
      return 353;
    }
  goto ret0;

 L5325: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5326;
    }
  goto ret0;

 L5326: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5327;
    }
  goto ret0;

 L5327: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5328;
  goto ret0;

 L5328: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 458;
    }
  goto ret0;

 L5297: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5298;
    }
  goto ret0;

 L5298: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5299;
  goto ret0;

 L5299: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 456;
    }
  goto ret0;

 L4641: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4642;
    }
  goto ret0;

 L4642: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4643;
    }
  goto ret0;

 L4643: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4644;
  goto ret0;

 L4644: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 411;
    }
  goto ret0;

 L4903: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4904;
    }
  goto ret0;

 L4904: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4905;
    }
  goto ret0;

 L4905: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4906;
  goto ret0;

 L4906: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT))
    {
      return 429;
    }
  goto ret0;

 L6514: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == UNSPEC
      && XVECLEN (x3, 0) == 1
      && XINT (x3, 1) == 15)
    goto L6515;
  goto ret0;

 L6515: ATTRIBUTE_UNUSED_LABEL
  x4 = XVECEXP (x3, 0, 0);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L6516;
  goto ret0;

 L6516: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L6517;
    }
  goto ret0;

 L6517: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6518;
  goto ret0;

 L6518: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT))
    {
      return 547;
    }
  goto ret0;

 L7467: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == LTU)
    goto L7468;
  goto ret0;

 L7468: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == CCmode
      && GET_CODE (x4) == REG
      && XINT (x4, 0) == 17)
    goto L7469;
  goto ret0;

 L7469: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 0LL)
    goto L7470;
  goto ret0;

 L7470: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL)
    goto L7471;
  goto ret0;

 L7471: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L7472;
  goto ret0;

 L7472: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7473;
  goto ret0;

 L7473: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT))
    {
      return 636;
    }
  goto ret0;

 L580: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L581;
  goto ret0;

 L581: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L582;
  goto ret0;

 L582: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0])
      && (TARGET_64BIT))
    {
      return 86;
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
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1374;
    case NEG:
      goto L1387;
    case MINUS:
      goto L1888;
    case AND:
      goto L2906;
    case IOR:
      goto L3209;
    case XOR:
      goto L3592;
    case NOT:
      goto L4522;
    case ASHIFT:
      goto L4613;
    case ASHIFTRT:
      goto L4862;
    case LSHIFTRT:
      goto L5255;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L14011;
    default:
      goto ret0;
   }
 L14011: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1404;
    }
  goto ret0;

 L1374: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L1375;
    }
  goto ret0;

 L1375: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x86_64_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1376;
    }
  goto ret0;

 L1376: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1377;
  goto ret0;

 L1377: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L1378;
    case CLOBBER:
      goto L1423;
    default:
     break;
   }
  goto ret0;

 L1378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1379;
    }
  goto ret0;

 L1379: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L1380;
  goto ret0;

 L1380: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1381;
  goto ret0;

 L1381: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, DImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 197;
    }
  goto ret0;

 L1423: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1424;
    }
  goto ret0;

 L1424: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 200;
    }
  goto ret0;

 L1387: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (x86_64_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1388;
    }
  goto ret0;

 L1388: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1389;
    }
  goto ret0;

 L1389: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1390;
  goto ret0;

 L1390: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1391;
    }
  goto ret0;

 L1391: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 198;
    }
  goto ret0;

 L1888: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L1889;
    }
  goto ret0;

 L1889: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x86_64_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L1890;
    }
  goto ret0;

 L1890: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1891;
  goto ret0;

 L1891: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1892;
  goto ret0;

 L1892: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1893;
    }
  goto ret0;

 L1893: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MINUS)
    goto L1894;
  goto ret0;

 L1894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1895;
  goto ret0;

 L1895: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, DImode, operands)))
    {
      return 228;
    }
  goto ret0;

 L2906: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2907;
    }
  goto ret0;

 L2907: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x86_64_szext_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2908;
    }
  goto ret0;

 L2908: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2909;
  goto ret0;

 L2909: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2910;
  goto ret0;

 L2910: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2911;
    }
  goto ret0;

 L2911: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == AND)
    goto L2912;
  goto ret0;

 L2912: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2913;
  goto ret0;

 L2913: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, DImode, operands)))
    {
      return 287;
    }
  goto ret0;

 L3209: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3210;
    }
  goto ret0;

 L3210: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x86_64_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3211;
    }
  goto ret0;

 L3211: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3212;
  goto ret0;

 L3212: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3213;
    case CLOBBER:
      goto L3226;
    default:
     break;
   }
  goto ret0;

 L3213: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3214;
    }
  goto ret0;

 L3214: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == IOR)
    goto L3215;
  goto ret0;

 L3215: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3216;
  goto ret0;

 L3216: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, DImode, operands)))
    {
      return 304;
    }
  goto ret0;

 L3226: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3227;
    }
  goto ret0;

 L3227: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, DImode, operands)))
    {
      return 305;
    }
  goto ret0;

 L3592: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L3593;
    }
  goto ret0;

 L3593: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (x86_64_general_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L3594;
    }
  goto ret0;

 L3594: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3595;
  goto ret0;

 L3595: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3596;
    case CLOBBER:
      goto L3609;
    default:
     break;
   }
  goto ret0;

 L3596: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3597;
    }
  goto ret0;

 L3597: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == XOR)
    goto L3598;
  goto ret0;

 L3598: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3599;
  goto ret0;

 L3599: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, DImode, operands)))
    {
      return 326;
    }
  goto ret0;

 L3609: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3610;
    }
  goto ret0;

 L3610: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, DImode, operands)))
    {
      return 327;
    }
  goto ret0;

 L4522: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4523;
    }
  goto ret0;

 L4523: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4524;
  goto ret0;

 L4524: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4525;
  goto ret0;

 L4525: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4526;
    }
  goto ret0;

 L4526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NOT)
    goto L4527;
  goto ret0;

 L4527: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, DImode, operands)))
    {
      return 399;
    }
  goto ret0;

 L4613: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4614;
    }
  goto ret0;

 L4614: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (immediate_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4615;
    }
  goto ret0;

 L4615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4616;
  goto ret0;

 L4616: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4617;
  goto ret0;

 L4617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4618;
    }
  goto ret0;

 L4618: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ASHIFT)
    goto L4619;
  goto ret0;

 L4619: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4620;
  goto ret0;

 L4620: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, DImode, operands)))
    {
      return 409;
    }
  goto ret0;

 L4862: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4863;
    }
  goto ret0;

 L4863: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14053;
  goto ret0;

 L14053: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4864;
    }
 L14054: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4877;
    }
  goto ret0;

 L4864: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4865;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14054;

 L4865: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4866;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14054;

 L4866: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4867;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14054;

 L4867: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L4868;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14054;

 L4868: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4869;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14054;

 L4869: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)))
    {
      return 426;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14054;

 L4877: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4878;
  goto ret0;

 L4878: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4879;
  goto ret0;

 L4879: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4880;
    }
  goto ret0;

 L4880: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L4881;
  goto ret0;

 L4881: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4882;
  goto ret0;

 L4882: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, DImode, operands)))
    {
      return 427;
    }
  goto ret0;

 L5255: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L5256;
    }
  goto ret0;

 L5256: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14055;
  goto ret0;

 L14055: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5257;
    }
 L14056: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5270;
    }
  goto ret0;

 L5257: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5258;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14056;

 L5258: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5259;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14056;

 L5259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5260;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14056;

 L5260: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5261;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14056;

 L5261: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5262;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14056;

 L5262: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 453;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14056;

 L5270: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5271;
  goto ret0;

 L5271: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5272;
  goto ret0;

 L5272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5273;
    }
  goto ret0;

 L5273: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5274;
  goto ret0;

 L5274: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5275;
  goto ret0;

 L5275: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 454;
    }
  goto ret0;

 L1404: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_immediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1405;
    }
 L1901: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1902;
    }
  goto ret0;

 L1405: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1406;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1901;

 L1406: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1407;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1901;

 L1407: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT
   &&  ix86_match_ccmode (insn, CCGCmode)))
    {
      return 199;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L1901;

 L1902: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1903;
  goto ret0;

 L1903: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1904;
    }
  goto ret0;

 L1904: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MINUS)
    goto L1905;
  goto ret0;

 L1905: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1906;
  goto ret0;

 L1906: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 229;
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
    case PLUS:
      goto L1467;
    case NEG:
      goto L1494;
    case MINUS:
      goto L1988;
    case AND:
      goto L2949;
    case IOR:
      goto L3286;
    case XOR:
      goto L3669;
    case NOT:
      goto L4544;
    case ASHIFT:
      goto L4711;
    case ASHIFTRT:
      goto L5033;
    case LSHIFTRT:
      goto L5371;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L14014;
    default:
      goto ret0;
   }
 L14014: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1524;
    }
  goto ret0;

 L1467: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1468;
    }
  goto ret0;

 L1468: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1469;
    }
  goto ret0;

 L1469: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1470;
  goto ret0;

 L1470: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L1471;
    case CLOBBER:
      goto L1543;
    default:
     break;
   }
  goto ret0;

 L1471: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L14057;
    case DImode:
      goto L14058;
    default:
      break;
    }
  goto ret0;

 L14057: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1472;
    }
  goto ret0;

 L1472: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1473;
  goto ret0;

 L1473: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1474;
  goto ret0;

 L1474: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 203;
    }
  goto ret0;

 L14058: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1485;
    }
  goto ret0;

 L1485: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L1486;
  goto ret0;

 L1486: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L1487;
  goto ret0;

 L1487: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1488;
  goto ret0;

 L1488: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 204;
    }
  goto ret0;

 L1543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1544;
    }
  goto ret0;

 L1544: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 208;
    }
  goto ret0;

 L1494: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1495;
    }
  goto ret0;

 L1495: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1496;
    }
  goto ret0;

 L1496: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L1497;
    case SET:
      goto L1514;
    default:
     break;
   }
  goto ret0;

 L1497: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1498;
    }
  goto ret0;

 L1498: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 205;
    }
  goto ret0;

 L1514: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1515;
    }
  goto ret0;

 L1515: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L1516;
  goto ret0;

 L1516: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == PLUS)
    goto L1517;
  goto ret0;

 L1517: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L1518;
  goto ret0;

 L1518: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCZmode)
   && ix86_binary_operator_ok (PLUS, SImode, operands)
   /* Current assemblers are broken and do not allow @GOTOFF in
      ought but a memory context.  */
   && ! pic_symbolic_operand (operands[2], VOIDmode)))
    {
      return 206;
    }
  goto ret0;

 L1988: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14059;
  goto ret0;

 L14059: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L1989;
    }
 L14060: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2002;
    }
  goto ret0;

 L1989: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L1990;
    }
  x4 = XEXP (x3, 0);
  goto L14060;

 L1990: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1991;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14060;

 L1991: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1992;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14060;

 L1992: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1993;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14060;

 L1993: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L1994;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14060;

 L1994: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1995;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14060;

 L1995: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 234;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14060;

 L2002: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2003;
    }
  goto ret0;

 L2003: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2004;
  goto ret0;

 L2004: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2005;
  goto ret0;

 L2005: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2006;
    }
  goto ret0;

 L2006: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2007;
  goto ret0;

 L2007: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MINUS)
    goto L2008;
  goto ret0;

 L2008: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L2009;
  goto ret0;

 L2009: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 235;
    }
  goto ret0;

 L2949: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14062;
  goto ret0;

 L14062: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L3087;
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L2950;
    }
  goto ret0;

 L3087: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (ext_register_operand (x5, VOIDmode))
    {
      operands[1] = x5;
      goto L3088;
    }
  goto ret0;

 L3088: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 8LL)
    goto L3089;
  goto ret0;

 L3089: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 8LL)
    goto L3090;
  goto ret0;

 L3090: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3091;
    }
  goto ret0;

 L3091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3092;
  goto ret0;

 L3092: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3093;
  goto ret0;

 L3093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L3094;
  goto ret0;

 L3094: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L3095;
    }
  goto ret0;

 L3095: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3096;
  goto ret0;

 L3096: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3097;
  goto ret0;

 L3097: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L3098;
  goto ret0;

 L3098: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L3099;
  goto ret0;

 L3099: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3100;
  goto ret0;

 L3100: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3101;
  goto ret0;

 L3101: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3102;
  goto ret0;

 L3102: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)))
    {
      return 299;
    }
  goto ret0;

 L2950: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L2951;
    }
  goto ret0;

 L2951: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2952;
  goto ret0;

 L2952: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2953;
  goto ret0;

 L2953: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L14063;
    case DImode:
      goto L14064;
    default:
      break;
    }
  goto ret0;

 L14063: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2954;
    }
  goto ret0;

 L2954: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == AND)
    goto L2955;
  goto ret0;

 L2955: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2956;
  goto ret0;

 L2956: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, operands)))
    {
      return 290;
    }
  goto ret0;

 L14064: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2967;
    }
  goto ret0;

 L2967: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2968;
  goto ret0;

 L2968: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == AND)
    goto L2969;
  goto ret0;

 L2969: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L2970;
  goto ret0;

 L2970: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, SImode, operands)))
    {
      return 291;
    }
  goto ret0;

 L3286: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3287;
    }
  goto ret0;

 L3287: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3288;
    }
 L3314: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_zext_immediate_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3315;
    }
  goto ret0;

 L3288: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3289;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3289: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3290;
    case CLOBBER:
      goto L3331;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3290: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L14065;
    case DImode:
      goto L14066;
    default:
      break;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L14065: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L3291;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3291: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == IOR)
    goto L3292;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3292: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3293;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3293: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands)))
    {
      return 309;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L14066: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3304;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3304: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3305;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3305: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == IOR)
    goto L3306;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3306: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3307;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3307: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands)))
    {
      return 310;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3331: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L3332;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3332: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 312;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3314;

 L3315: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3316;
  goto ret0;

 L3316: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3317;
  goto ret0;

 L3317: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3318;
    }
  goto ret0;

 L3318: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == IOR)
    goto L3319;
  goto ret0;

 L3319: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L3320;
  goto ret0;

 L3320: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3321;
  goto ret0;

 L3321: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, SImode, operands)))
    {
      return 311;
    }
  goto ret0;

 L3669: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14068;
  goto ret0;

 L14068: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x4) == ZERO_EXTRACT)
    goto L3962;
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L3670;
    }
  goto ret0;

 L3962: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (ext_register_operand (x5, VOIDmode))
    {
      operands[1] = x5;
      goto L3963;
    }
  goto ret0;

 L3963: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 8LL)
    goto L3964;
  goto ret0;

 L3964: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 2);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 8LL)
    goto L3965;
  goto ret0;

 L3965: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3966;
    }
 L3987: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3988;
    }
  goto ret0;

 L3966: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3967;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3967: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3968;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3968: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L3969;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3969: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L3970;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3970: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3971;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3971: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3972;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3972: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == XOR)
    goto L3973;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3973: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L3974;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3974: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3975;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3975: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3976;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3976: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3977;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3977: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (!TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 347;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3987;

 L3988: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3989;
  goto ret0;

 L3989: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3990;
  goto ret0;

 L3990: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ZERO_EXTRACT)
    goto L3991;
  goto ret0;

 L3991: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (ext_register_operand (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L3992;
    }
  goto ret0;

 L3992: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3993;
  goto ret0;

 L3993: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L3994;
  goto ret0;

 L3994: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == XOR)
    goto L3995;
  goto ret0;

 L3995: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ZERO_EXTRACT)
    goto L3996;
  goto ret0;

 L3996: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3997;
  goto ret0;

 L3997: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3998;
  goto ret0;

 L3998: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 2);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 8LL)
    goto L3999;
  goto ret0;

 L3999: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)))
    {
      return 348;
    }
  goto ret0;

 L3670: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, SImode))
    {
      operands[2] = x4;
      goto L3671;
    }
 L3697: ATTRIBUTE_UNUSED_LABEL
  if (x86_64_zext_immediate_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L3698;
    }
  goto ret0;

 L3671: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3672;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3672: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3673;
    case CLOBBER:
      goto L3714;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3673: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L14069;
    case DImode:
      goto L14070;
    default:
      break;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L14069: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L3674;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3674: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == XOR)
    goto L3675;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3676;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3676: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands)))
    {
      return 331;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L14070: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3687;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3687: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L3688;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3688: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == XOR)
    goto L3689;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3689: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3690;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3690: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands)))
    {
      return 332;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3714: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L3715;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3715: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 334;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L3697;

 L3698: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3699;
  goto ret0;

 L3699: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3700;
  goto ret0;

 L3700: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L3701;
    }
  goto ret0;

 L3701: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == XOR)
    goto L3702;
  goto ret0;

 L3702: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L3703;
  goto ret0;

 L3703: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L3704;
  goto ret0;

 L3704: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, SImode, operands)))
    {
      return 333;
    }
  goto ret0;

 L4544: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14071;
  goto ret0;

 L14071: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4545;
    }
 L14072: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4556;
    }
  goto ret0;

 L4545: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4546;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14072;

 L4546: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4547;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14072;

 L4547: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4548;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14072;

 L4548: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NOT)
    goto L4549;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14072;

 L4549: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, operands)))
    {
      return 402;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14072;

 L4556: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4557;
  goto ret0;

 L4557: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4558;
  goto ret0;

 L4558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4559;
    }
  goto ret0;

 L4559: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L4560;
  goto ret0;

 L4560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == NOT)
    goto L4561;
  goto ret0;

 L4561: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, SImode, operands)))
    {
      return 403;
    }
  goto ret0;

 L4711: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14073;
  goto ret0;

 L14073: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4712;
    }
 L14074: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4725;
    }
  goto ret0;

 L4712: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4713;
    }
  x4 = XEXP (x3, 0);
  goto L14074;

 L4713: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4714;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14074;

 L4714: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4715;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14074;

 L4715: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4716;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14074;

 L4716: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFT)
    goto L4717;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14074;

 L4717: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4718;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14074;

 L4718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands)))
    {
      return 415;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14074;

 L4725: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4726;
    }
  goto ret0;

 L4726: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4727;
  goto ret0;

 L4727: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4728;
  goto ret0;

 L4728: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4729;
    }
  goto ret0;

 L4729: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L4730;
  goto ret0;

 L4730: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ASHIFT)
    goto L4731;
  goto ret0;

 L4731: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L4732;
  goto ret0;

 L4732: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, SImode, operands)))
    {
      return 416;
    }
  goto ret0;

 L5033: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14075;
  goto ret0;

 L14075: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5034;
    }
 L14076: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5047;
    }
  goto ret0;

 L5034: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14077;
  x4 = XEXP (x3, 0);
  goto L14076;

 L14077: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5035;
    }
 L14078: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5062;
    }
  x4 = XEXP (x3, 0);
  goto L14076;

 L5035: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5036;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14078;

 L5036: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5037;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14078;

 L5037: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5038;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14078;

 L5038: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L5039;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14078;

 L5039: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5040;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14078;

 L5040: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 437;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14078;

 L5062: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5063;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14076;

 L5063: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5064;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14076;

 L5064: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5065;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14076;

 L5065: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L5066;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14076;

 L5066: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5067;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14076;

 L5067: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 439;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14076;

 L5047: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14079;
  goto ret0;

 L14079: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5048;
    }
 L14080: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5075;
    }
  goto ret0;

 L5048: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5049;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5049: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5050;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5050: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5051;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5051: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L5052;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5052: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ASHIFTRT)
    goto L5053;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5053: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5054;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5054: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 438;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14080;

 L5075: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5076;
  goto ret0;

 L5076: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5077;
  goto ret0;

 L5077: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5078;
    }
  goto ret0;

 L5078: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L5079;
  goto ret0;

 L5079: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == ASHIFTRT)
    goto L5080;
  goto ret0;

 L5080: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5081;
  goto ret0;

 L5081: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, SImode, operands)))
    {
      return 440;
    }
  goto ret0;

 L5371: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14081;
  goto ret0;

 L14081: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5372;
    }
 L14082: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L5385;
    }
  goto ret0;

 L5372: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14083;
  x4 = XEXP (x3, 0);
  goto L14082;

 L14083: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5373;
    }
 L14084: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5400;
    }
  x4 = XEXP (x3, 0);
  goto L14082;

 L5373: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5374;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14084;

 L5374: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5375;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14084;

 L5375: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5376;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14084;

 L5376: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5377;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14084;

 L5377: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5378;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14084;

 L5378: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 461;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14084;

 L5400: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5401;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14082;

 L5401: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5402;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14082;

 L5402: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L5403;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14082;

 L5403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5404;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14082;

 L5404: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5405;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14082;

 L5405: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 463;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14082;

 L5385: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14085;
  goto ret0;

 L14085: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5386;
    }
 L14086: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5413;
    }
  goto ret0;

 L5386: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5387;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5387: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5388;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5389;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5389: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5390;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L5391;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5391: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5392;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5392: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 462;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14086;

 L5413: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5414;
  goto ret0;

 L5414: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5415;
  goto ret0;

 L5415: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L5416;
    }
  goto ret0;

 L5416: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5417;
  goto ret0;

 L5417: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L5418;
  goto ret0;

 L5418: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L5419;
  goto ret0;

 L5419: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 464;
    }
  goto ret0;

 L1524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1525;
    }
 L2015: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2016;
    }
  goto ret0;

 L1525: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1526;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2015;

 L1526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1527;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2015;

 L1527: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffffffff) != 0x80000000))
    {
      return 207;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2015;

 L2016: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2017;
  goto ret0;

 L2017: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L14087;
    case DImode:
      goto L14088;
    default:
      break;
    }
  goto ret0;

 L14087: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2018;
    }
  goto ret0;

 L2018: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MINUS)
    goto L2019;
  goto ret0;

 L2019: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2020;
  goto ret0;

 L2020: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 236;
    }
  goto ret0;

 L14088: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2029;
    }
  goto ret0;

 L2029: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == ZERO_EXTEND)
    goto L2030;
  goto ret0;

 L2030: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == MINUS)
    goto L2031;
  goto ret0;

 L2031: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (rtx_equal_p (x4, operands[1]))
    goto L2032;
  goto ret0;

 L2032: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (rtx_equal_p (x4, operands[2])
      && (TARGET_64BIT && ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, SImode, operands)))
    {
      return 237;
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
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case PLUS:
      goto L1585;
    case NEG:
      goto L1598;
    case MINUS:
      goto L2052;
    case AND:
      goto L2990;
    case IOR:
      goto L3359;
    case XOR:
      goto L3742;
    case NOT:
      goto L4572;
    case ASHIFT:
      goto L4766;
    case ASHIFTRT:
      goto L5115;
    case LSHIFTRT:
      goto L5453;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L14017;
    default:
      goto ret0;
   }
 L14017: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L1615;
    }
  goto ret0;

 L1585: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L1586;
    }
  goto ret0;

 L1586: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      operands[2] = x4;
      goto L1587;
    }
  goto ret0;

 L1587: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1588;
  goto ret0;

 L1588: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L1589;
    case CLOBBER:
      goto L1634;
    default:
     break;
   }
  goto ret0;

 L1589: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1590;
    }
  goto ret0;

 L1590: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == PLUS)
    goto L1591;
  goto ret0;

 L1591: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1592;
  goto ret0;

 L1592: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, HImode, operands)))
    {
      return 211;
    }
  goto ret0;

 L1634: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1635;
    }
  goto ret0;

 L1635: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 214;
    }
  goto ret0;

 L1598: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, HImode))
    {
      operands[2] = x4;
      goto L1599;
    }
  goto ret0;

 L1599: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L1600;
    }
  goto ret0;

 L1600: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1601;
  goto ret0;

 L1601: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1602;
    }
  goto ret0;

 L1602: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 212;
    }
  goto ret0;

 L2052: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L2053;
    }
  goto ret0;

 L2053: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      operands[2] = x4;
      goto L2054;
    }
  goto ret0;

 L2054: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2055;
  goto ret0;

 L2055: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2056;
  goto ret0;

 L2056: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L2057;
    }
  goto ret0;

 L2057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L2058;
  goto ret0;

 L2058: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2059;
  goto ret0;

 L2059: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, HImode, operands)))
    {
      return 239;
    }
  goto ret0;

 L2990: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L2991;
    }
  goto ret0;

 L2991: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      operands[2] = x4;
      goto L2992;
    }
  goto ret0;

 L2992: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2993;
  goto ret0;

 L2993: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2994;
  goto ret0;

 L2994: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L2995;
    }
  goto ret0;

 L2995: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == AND)
    goto L2996;
  goto ret0;

 L2996: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2997;
  goto ret0;

 L2997: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, HImode, operands)))
    {
      return 293;
    }
  goto ret0;

 L3359: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L3360;
    }
  goto ret0;

 L3360: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      operands[2] = x4;
      goto L3361;
    }
  goto ret0;

 L3361: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3362;
  goto ret0;

 L3362: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3363;
    case CLOBBER:
      goto L3376;
    default:
     break;
   }
  goto ret0;

 L3363: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L3364;
    }
  goto ret0;

 L3364: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == IOR)
    goto L3365;
  goto ret0;

 L3365: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3366;
  goto ret0;

 L3366: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, HImode, operands)))
    {
      return 314;
    }
  goto ret0;

 L3376: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L3377;
    }
  goto ret0;

 L3377: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 315;
    }
  goto ret0;

 L3742: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L3743;
    }
  goto ret0;

 L3743: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, HImode))
    {
      operands[2] = x4;
      goto L3744;
    }
  goto ret0;

 L3744: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3745;
  goto ret0;

 L3745: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3746;
    case CLOBBER:
      goto L3759;
    default:
     break;
   }
  goto ret0;

 L3746: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L3747;
    }
  goto ret0;

 L3747: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == XOR)
    goto L3748;
  goto ret0;

 L3748: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3749;
  goto ret0;

 L3749: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, HImode, operands)))
    {
      return 336;
    }
  goto ret0;

 L3759: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L3760;
    }
  goto ret0;

 L3760: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 337;
    }
  goto ret0;

 L4572: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L4573;
    }
  goto ret0;

 L4573: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4574;
  goto ret0;

 L4574: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4575;
  goto ret0;

 L4575: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L4576;
    }
  goto ret0;

 L4576: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == NOT)
    goto L4577;
  goto ret0;

 L4577: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NEG, HImode, operands)))
    {
      return 405;
    }
  goto ret0;

 L4766: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L4767;
    }
  goto ret0;

 L4767: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4768;
    }
  goto ret0;

 L4768: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4769;
  goto ret0;

 L4769: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4770;
  goto ret0;

 L4770: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L4771;
    }
  goto ret0;

 L4771: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ASHIFT)
    goto L4772;
  goto ret0;

 L4772: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4773;
  goto ret0;

 L4773: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, HImode, operands)))
    {
      return 419;
    }
  goto ret0;

 L5115: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L5116;
    }
  goto ret0;

 L5116: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14089;
  goto ret0;

 L14089: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5117;
    }
 L14090: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5130;
    }
  goto ret0;

 L5117: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5118;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14090;

 L5118: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5119;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14090;

 L5119: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L5120;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14090;

 L5120: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L5121;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14090;

 L5121: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5122;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14090;

 L5122: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands)))
    {
      return 443;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14090;

 L5130: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5131;
  goto ret0;

 L5131: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5132;
  goto ret0;

 L5132: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L5133;
    }
  goto ret0;

 L5133: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L5134;
  goto ret0;

 L5134: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5135;
  goto ret0;

 L5135: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, HImode, operands)))
    {
      return 444;
    }
  goto ret0;

 L5453: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L5454;
    }
  goto ret0;

 L5454: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14091;
  goto ret0;

 L14091: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5455;
    }
 L14092: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5468;
    }
  goto ret0;

 L5455: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5456;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14092;

 L5456: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5457;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14092;

 L5457: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L5458;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14092;

 L5458: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5459;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14092;

 L5459: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5460;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14092;

 L5460: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 467;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14092;

 L5468: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5469;
  goto ret0;

 L5469: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5470;
  goto ret0;

 L5470: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L5471;
    }
  goto ret0;

 L5471: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5472;
  goto ret0;

 L5472: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5473;
  goto ret0;

 L5473: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, HImode, operands)))
    {
      return 468;
    }
  goto ret0;

 L1615: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L1616;
    }
 L2065: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2066;
    }
  goto ret0;

 L1616: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1617;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2065;

 L1617: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1618;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2065;

 L1618: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xffff) != 0x8000))
    {
      return 213;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2065;

 L2066: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2067;
  goto ret0;

 L2067: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L2068;
    }
  goto ret0;

 L2068: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L2069;
  goto ret0;

 L2069: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2070;
  goto ret0;

 L2070: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, HImode, operands)))
    {
      return 240;
    }
  goto ret0;
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
    case PLUS:
      goto L1692;
    case NEG:
      goto L1705;
    case MINUS:
      goto L2106;
    case AND:
      goto L3033;
    case IOR:
      goto L3420;
    case XOR:
      goto L3916;
    case NOT:
      goto L4588;
    case ASHIFT:
      goto L4807;
    case ASHIFTRT:
      goto L5201;
    case LSHIFTRT:
      goto L5539;
    case SUBREG:
    case REG:
    case MEM:
    case ADDRESSOF:
      goto L14020;
    default:
      goto ret0;
   }
 L14020: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L1722;
    }
  goto ret0;

 L1692: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L1693;
    }
  goto ret0;

 L1693: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L1694;
    }
  goto ret0;

 L1694: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L1695;
  goto ret0;

 L1695: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L1696;
    case CLOBBER:
      goto L1741;
    default:
     break;
   }
  goto ret0;

 L1696: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1697;
    }
  goto ret0;

 L1697: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L1698;
  goto ret0;

 L1698: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1699;
  goto ret0;

 L1699: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (PLUS, QImode, operands)))
    {
      return 218;
    }
  goto ret0;

 L1741: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1742;
    }
  goto ret0;

 L1742: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGOCmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 221;
    }
  goto ret0;

 L1705: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L1706;
    }
  goto ret0;

 L1706: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L1707;
    }
  goto ret0;

 L1707: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1708;
  goto ret0;

 L1708: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1709;
    }
  goto ret0;

 L1709: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCZmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 219;
    }
  goto ret0;

 L2106: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L2107;
    }
  goto ret0;

 L2107: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L2108;
    }
  goto ret0;

 L2108: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L2109;
  goto ret0;

 L2109: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2110;
  goto ret0;

 L2110: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L2111;
    }
  goto ret0;

 L2111: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L2112;
  goto ret0;

 L2112: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2113;
  goto ret0;

 L2113: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (MINUS, QImode, operands)))
    {
      return 243;
    }
  goto ret0;

 L3033: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L14093;
  goto ret0;

 L14093: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L3034;
    }
 L14094: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[0] = x4;
      goto L3047;
    }
  goto ret0;

 L3034: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3035;
    }
  x4 = XEXP (x3, 0);
  goto L14094;

 L3035: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3036;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14094;

 L3036: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3037;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14094;

 L3037: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L3038;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14094;

 L3038: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == AND)
    goto L3039;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14094;

 L3039: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3040;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14094;

 L3040: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (AND, QImode, operands)))
    {
      return 296;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14094;

 L3047: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L3048;
    }
  goto ret0;

 L3048: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3049;
  goto ret0;

 L3049: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3050;
  goto ret0;

 L3050: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == STRICT_LOW_PART)
    goto L3051;
  goto ret0;

 L3051: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3052;
  goto ret0;

 L3052: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == AND)
    goto L3053;
  goto ret0;

 L3053: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3054;
  goto ret0;

 L3054: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1])
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 297;
    }
  goto ret0;

 L3420: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L14095;
  goto ret0;

 L14095: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L3421;
    }
 L14096: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[0] = x4;
      goto L3434;
    }
  goto ret0;

 L3421: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3422;
    }
  x4 = XEXP (x3, 0);
  goto L14096;

 L3422: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3423;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3423: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3424;
    case CLOBBER:
      goto L3451;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3424: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L3425;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3425: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == IOR)
    goto L3426;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3426: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3427;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3427: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (IOR, QImode, operands)))
    {
      return 318;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3451: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L3452;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3452: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 320;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14096;

 L3434: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L3435;
    }
  goto ret0;

 L3435: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3436;
  goto ret0;

 L3436: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3437;
  goto ret0;

 L3437: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == STRICT_LOW_PART)
    goto L3438;
  goto ret0;

 L3438: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3439;
  goto ret0;

 L3439: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == IOR)
    goto L3440;
  goto ret0;

 L3440: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3441;
  goto ret0;

 L3441: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1])
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 319;
    }
  goto ret0;

 L3916: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == QImode)
    goto L14097;
  goto ret0;

 L14097: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L3917;
    }
 L14098: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, QImode))
    {
      operands[0] = x4;
      goto L3930;
    }
  goto ret0;

 L3917: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L3918;
    }
  x4 = XEXP (x3, 0);
  goto L14098;

 L3918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3919;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3919: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L3920;
    case CLOBBER:
      goto L3947;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L3921;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3921: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == XOR)
    goto L3922;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3922: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L3923;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3923: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_binary_operator_ok (XOR, QImode, operands)))
    {
      return 344;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3947: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L3948;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3948: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 346;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14098;

 L3930: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (general_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L3931;
    }
  goto ret0;

 L3931: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L3932;
  goto ret0;

 L3932: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L3933;
  goto ret0;

 L3933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == STRICT_LOW_PART)
    goto L3934;
  goto ret0;

 L3934: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3935;
  goto ret0;

 L3935: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == XOR)
    goto L3936;
  goto ret0;

 L3936: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3937;
  goto ret0;

 L3937: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1])
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && ix86_match_ccmode (insn, CCNOmode)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 345;
    }
  goto ret0;

 L4588: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L4589;
    }
  goto ret0;

 L4589: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4590;
  goto ret0;

 L4590: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4591;
  goto ret0;

 L4591: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L4592;
    }
  goto ret0;

 L4592: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == NOT)
    goto L4593;
  goto ret0;

 L4593: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (ix86_match_ccmode (insn, CCNOmode)
   && ix86_unary_operator_ok (NOT, QImode, operands)))
    {
      return 407;
    }
  goto ret0;

 L4807: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L4808;
    }
  goto ret0;

 L4808: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L4809;
    }
  goto ret0;

 L4809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4810;
  goto ret0;

 L4810: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4811;
  goto ret0;

 L4811: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L4812;
    }
  goto ret0;

 L4812: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == ASHIFT)
    goto L4813;
  goto ret0;

 L4813: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L4814;
  goto ret0;

 L4814: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)))
    {
      return 422;
    }
  goto ret0;

 L5201: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L5202;
    }
  goto ret0;

 L5202: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14099;
  goto ret0;

 L14099: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5203;
    }
 L14100: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5216;
    }
  goto ret0;

 L5203: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5204;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14100;

 L5204: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5205;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14100;

 L5205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L5206;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14100;

 L5206: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L5207;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14100;

 L5207: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5208;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14100;

 L5208: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands)))
    {
      return 449;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14100;

 L5216: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5217;
  goto ret0;

 L5217: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5218;
  goto ret0;

 L5218: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L5219;
    }
  goto ret0;

 L5219: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == ASHIFTRT)
    goto L5220;
  goto ret0;

 L5220: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5221;
  goto ret0;

 L5221: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (ASHIFTRT, QImode, operands)))
    {
      return 450;
    }
  goto ret0;

 L5539: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L5540;
    }
  goto ret0;

 L5540: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT)
    goto L14101;
  goto ret0;

 L14101: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5541;
    }
 L14102: ATTRIBUTE_UNUSED_LABEL
  if (const_int_1_31_operand (x4, QImode))
    {
      operands[2] = x4;
      goto L5554;
    }
  goto ret0;

 L5541: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5542;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14102;

 L5542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5543;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14102;

 L5543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L5544;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14102;

 L5544: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5545;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14102;

 L5545: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5546;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14102;

 L5546: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && (TARGET_SHIFT1 || optimize_size)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands)))
    {
      return 473;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L14102;

 L5554: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L5555;
  goto ret0;

 L5555: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L5556;
  goto ret0;

 L5556: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L5557;
    }
  goto ret0;

 L5557: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L5558;
  goto ret0;

 L5558: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L5559;
  goto ret0;

 L5559: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCGOCmode)
   && ix86_binary_operator_ok (LSHIFTRT, QImode, operands)))
    {
      return 474;
    }
  goto ret0;

 L1722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1723;
    }
 L2119: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2120;
    }
  goto ret0;

 L1723: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1724;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2119;

 L1724: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1725;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2119;

 L1725: ATTRIBUTE_UNUSED_LABEL
  if ((ix86_match_ccmode (insn, CCGCmode)
   && (INTVAL (operands[2]) & 0xff) != 0x80))
    {
      return 220;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L2119;

 L2120: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2121;
  goto ret0;

 L2121: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L2122;
    }
  goto ret0;

 L2122: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MINUS)
    goto L2123;
  goto ret0;

 L2123: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2124;
  goto ret0;

 L2124: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_match_ccmode (insn, CCmode)
   && ix86_binary_operator_ok (MINUS, QImode, operands)))
    {
      return 244;
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
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L13751;
    case HImode:
      goto L13754;
    case QImode:
      goto L13755;
    case DImode:
      goto L13756;
    case SFmode:
      goto L13759;
    case DFmode:
      goto L13760;
    case XFmode:
      goto L13761;
    case TFmode:
      goto L13762;
    case CCmode:
      goto L13765;
    case TImode:
      goto L13769;
    case CCZmode:
      goto L13770;
    default:
      break;
    }
 L376: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case STRICT_LOW_PART:
      goto L377;
    case REG:
      goto L13777;
    case PC:
      goto L6215;
    default:
     break;
   }
 L7985: ATTRIBUTE_UNUSED_LABEL
  operands[0] = x2;
  goto L7986;

 L13751: ATTRIBUTE_UNUSED_LABEL
  tem = recog_23 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L376;

 L13754: ATTRIBUTE_UNUSED_LABEL
  tem = recog_24 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L376;

 L13755: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L401;
    }
 L13767: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1646;
    }
  goto L376;

 L401: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode)
    goto L13862;
  x2 = XEXP (x1, 0);
  goto L13767;

 L13862: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L2187;
    case DIV:
      goto L2463;
    case UDIV:
      goto L2477;
    case SUBREG:
    case REG:
    case ADDRESSOF:
      goto L13861;
    default:
      x2 = XEXP (x1, 0);
      goto L13767;
   }
 L13861: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L402;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L2188;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2188: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2189;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2189: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2190;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L2190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_QIMODE_MATH
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 249;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L2463: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2464;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2464: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2465;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2465: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2466;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L2466: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_QIMODE_MATH))
    {
      return 262;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L2477: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2478;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2478: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2479;
    }
  x2 = XEXP (x1, 0);
  goto L13767;

 L2479: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2480;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L2480: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_QIMODE_MATH))
    {
      return 263;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L402: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L403;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L403: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L404;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L404: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0]))
    {
      return 60;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13767;

 L1646: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode)
    goto L13865;
  x2 = XEXP (x1, 0);
  goto L376;

 L13865: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1647;
    case MINUS:
      goto L2075;
    case AND:
      goto L3002;
    case IOR:
      goto L3389;
    case XOR:
      goto L3772;
    case NEG:
      goto L4123;
    case ASHIFT:
      goto L4778;
    case ASHIFTRT:
      goto L5140;
    case LSHIFTRT:
      goto L5478;
    case ROTATE:
      goto L5696;
    case ROTATERT:
      goto L5856;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L1647: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L1648;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1648: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1649;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1649: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1650;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1650: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13876;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13876: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13878;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13878: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13880;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13880: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands)))
    {
      return 215;
    }
 L13881: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (PLUS, QImode, operands)))
    {
      return 216;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L2075: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L2076;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L2076: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L2077;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L2077: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2078;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L2078: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (MINUS, QImode, operands)))
    {
      return 241;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L3002: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3003;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L3003: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3004;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L3004: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3005;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L3005: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (AND, QImode, operands)))
    {
      return 294;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L3389: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3390;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L3390: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3391;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L3391: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3392;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L3392: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (IOR, QImode, operands)))
    {
      return 316;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L3772: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3773;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L3773: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L3774;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L3774: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3775;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L3775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (XOR, QImode, operands)))
    {
      return 338;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4123: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L4124;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4124: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4125;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4125: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (NEG, QImode, operands)))
    {
      return 358;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4778: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L4779;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4779: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4780;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4780: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4781;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4781: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13882;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13882: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13884;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13884: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13886;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13886: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)))
    {
      return 420;
    }
 L13887: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_PARTIAL_REG_STALL
   && ix86_binary_operator_ok (ASHIFT, QImode, operands)))
    {
      return 421;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5140: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5141;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5141: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5142;
    }
 L5171: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5172;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5142: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5171;

 L5143: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 445;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5171;

 L5172: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5173;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, QImode, operands)))
    {
      return 447;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5478: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5479;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5479: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5480;
    }
 L5509: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5510;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5480: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5481;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5509;

 L5481: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (LSHIFTRT, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 469;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5509;

 L5510: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5511;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (LSHIFTRT, QImode, operands)))
    {
      return 471;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5696: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5697;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5697: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5698;
    }
 L5727: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5728;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5698: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5699;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5727;

 L5699: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATE, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 484;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5727;

 L5728: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5729;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5729: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATE, QImode, operands)))
    {
      return 486;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5856: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5857;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5857: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5858;
    }
 L5887: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5888;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L5858: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5859;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5887;

 L5859: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATERT, QImode, operands)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 495;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5887;

 L5888: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5889;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L5889: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ROTATERT, QImode, operands)))
    {
      return 497;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13756: ATTRIBUTE_UNUSED_LABEL
  if (push_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L511;
    }
 L13757: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L531;
    }
 L13758: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L579;
    }
  goto L376;

 L511: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (general_no_elim_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L512;
    }
  x2 = XEXP (x1, 0);
  goto L13757;

 L512: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L513;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13757;

 L513: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L514;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13757;

 L514: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (TARGET_64BIT))
    {
      return 77;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13757;

 L531: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L13888;
  x2 = XEXP (x1, 0);
  goto L13758;

 L13888: ATTRIBUTE_UNUSED_LABEL
  tem = recog_25 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L13758;

 L579: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L13906;
 L6408: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == CALL)
    goto L6409;
  if (const0_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L542;
    }
 L551: ATTRIBUTE_UNUSED_LABEL
  if (const_int_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L552;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L13906: ATTRIBUTE_UNUSED_LABEL
  tem = recog_26 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L6408;

 L6409: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MEM)
    goto L6410;
  x2 = XEXP (x1, 0);
  goto L376;

 L6410: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode)
    goto L13938;
  x2 = XEXP (x1, 0);
  goto L376;

 L13938: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L6411;
    }
 L13939: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L6457;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L6411: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[3] = x3;
  goto L6412;

 L6412: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 16)
    goto L6413;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13939;

 L6413: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (tls_symbolic_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L6414;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13939;

 L6414: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 539;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13939;

 L6457: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L6458;

 L6458: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_MODE (x1) == DImode
      && GET_CODE (x1) == UNSPEC
      && XVECLEN (x1, 0) == 1
      && XINT (x1, 1) == 17)
    goto L6459;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L6459: ATTRIBUTE_UNUSED_LABEL
  x2 = XVECEXP (x1, 0, 0);
  if (GET_CODE (x2) == CONST_INT
      && XWINT (x2, 0) == 0LL
      && (TARGET_64BIT))
    {
      return 542;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L542: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L543;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L551;

 L543: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && (!TARGET_USE_MOV0 || optimize_size)
   && reload_completed))
    {
      return 80;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L551;

 L552: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L553;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L553: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && (TARGET_PENTIUM || optimize_size)
   && reload_completed
   && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) == -1))
    {
      return 81;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13759: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L598;
    }
 L13763: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L860;
    }
 L13771: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L4145;
    }
 L13772: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L4174;
    }
  goto L376;

 L598: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L13941;
  x2 = XEXP (x1, 0);
  goto L13763;

 L13941: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L7577;
  if (register_operand (x2, SFmode))
    {
      operands[1] = x2;
      goto L599;
    }
  x2 = XEXP (x1, 0);
  goto L13763;

 L7577: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case LT:
      goto L7578;
    case GT:
      goto L7670;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L13763;

 L7578: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SFmode)
    goto L13942;
  x2 = XEXP (x1, 0);
  goto L13763;

 L13942: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L7579;
    }
 L13943: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L7598;
    }
  x2 = XEXP (x1, 0);
  goto L13763;

 L7579: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L7580;
    }
  x4 = XEXP (x3, 0);
  goto L13943;

 L7580: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7581;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13943;

 L7581: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7582;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13943;

 L7582: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7583;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13943;

 L7583: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE && TARGET_IEEE_FP))
    {
      return 646;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13943;

 L7598: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L7599;
    }
  x2 = XEXP (x1, 0);
  goto L13763;

 L7599: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7600;
  x2 = XEXP (x1, 0);
  goto L13763;

 L7600: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7601;
  x2 = XEXP (x1, 0);
  goto L13763;

 L7601: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7602;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L7602: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 647;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L7670: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SFmode)
    goto L13944;
  x2 = XEXP (x1, 0);
  goto L13763;

 L13944: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L7671;
    }
 L13945: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[1] = x4;
      goto L7690;
    }
  x2 = XEXP (x1, 0);
  goto L13763;

 L7671: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L7672;
    }
  x4 = XEXP (x3, 0);
  goto L13945;

 L7672: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7673;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13945;

 L7673: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7674;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13945;

 L7674: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7675;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13945;

 L7675: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE && TARGET_IEEE_FP))
    {
      return 652;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13945;

 L7690: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[2] = x4;
      goto L7691;
    }
  x2 = XEXP (x1, 0);
  goto L13763;

 L7691: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7692;
  x2 = XEXP (x1, 0);
  goto L13763;

 L7692: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7693;
  x2 = XEXP (x1, 0);
  goto L13763;

 L7693: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7694;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L7694: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 653;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L599: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L600;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L600: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L601;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L601: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0])
      && (reload_completed || !TARGET_SSE))
    {
      return 90;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13763;

 L860: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L13946;
  x2 = XEXP (x1, 0);
  goto L13771;

 L13946: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT_TRUNCATE:
      goto L861;
    case NEG:
      goto L4167;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L13771;

 L861: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      goto L13948;
    case XFmode:
      goto L13950;
    case TFmode:
      goto L13951;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L13771;

 L13948: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L862;
    }
 L13949: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L870;
    }
  x2 = XEXP (x1, 0);
  goto L13771;

 L862: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L863;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13949;

 L863: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L864;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13949;

 L864: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && !TARGET_SSE2))
    {
      return 133;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L13949;

 L870: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L871;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L871: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L872;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L872: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && TARGET_SSE2))
    {
      return 134;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L13950: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, XFmode))
    {
      operands[1] = x3;
      goto L893;
    }
  x2 = XEXP (x1, 0);
  goto L13771;

 L893: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L894;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L894: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L895;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L895: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 138;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L13951: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L906;
    }
  x2 = XEXP (x1, 0);
  goto L13771;

 L906: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L907;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L907: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L908;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L908: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 140;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L4167: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4168;
    }
  x2 = XEXP (x1, 0);
  goto L13771;

 L4168: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4169;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L4169: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L4170;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L4170: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode))))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 361;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13771;

 L4145: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L13952;
  x2 = XEXP (x1, 0);
  goto L13772;

 L13952: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4146;
    case ABS:
      goto L4331;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L13772;

 L4146: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (memory_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4147;
    }
  x2 = XEXP (x1, 0);
  goto L13772;

 L4147: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4148;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13772;

 L4148: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (NEG, SFmode, operands)))
    {
      return 360;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13772;

 L4331: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (memory_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4332;
    }
  x2 = XEXP (x1, 0);
  goto L13772;

 L4332: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4333;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13772;

 L4333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (ABS, SFmode, operands)))
    {
      return 379;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13772;

 L4174: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L13954;
  x2 = XEXP (x1, 0);
  goto L376;

 L13954: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4175;
    case ABS:
      goto L4352;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L4175: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4176;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4176: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4177;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4177: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_80387 && !TARGET_SSE
   && ix86_unary_operator_ok (NEG, SFmode, operands)))
    {
      return 362;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4352: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4353;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4353: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case USE:
      goto L4354;
    case CLOBBER:
      goto L4362;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4354: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L4355;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4355: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_SSE
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode))))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 380;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_80387 && ix86_unary_operator_ok (ABS, SFmode, operands) && !TARGET_SSE))
    {
      return 381;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13760: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L621;
    }
 L13764: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L917;
    }
 L13773: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L4186;
    }
 L13774: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L4232;
    }
  goto L376;

 L621: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L13957;
  x2 = XEXP (x1, 0);
  goto L13764;

 L13957: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L7623;
  if (register_operand (x2, DFmode))
    {
      operands[1] = x2;
      goto L622;
    }
  x2 = XEXP (x1, 0);
  goto L13764;

 L7623: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case LT:
      goto L7624;
    case GT:
      goto L7716;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L13764;

 L7624: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DFmode)
    goto L13958;
  x2 = XEXP (x1, 0);
  goto L13764;

 L13958: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L7625;
    }
 L13959: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L7644;
    }
  x2 = XEXP (x1, 0);
  goto L13764;

 L7625: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L7626;
    }
  x4 = XEXP (x3, 0);
  goto L13959;

 L7626: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7627;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13959;

 L7627: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7628;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13959;

 L7628: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7629;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13959;

 L7629: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE2 && TARGET_IEEE_FP && TARGET_SSE_MATH))
    {
      return 649;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13959;

 L7644: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L7645;
    }
  x2 = XEXP (x1, 0);
  goto L13764;

 L7645: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7646;
  x2 = XEXP (x1, 0);
  goto L13764;

 L7646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7647;
  x2 = XEXP (x1, 0);
  goto L13764;

 L7647: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7648;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L7648: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE2 && TARGET_SSE_MATH && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 650;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L7716: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DFmode)
    goto L13960;
  x2 = XEXP (x1, 0);
  goto L13764;

 L13960: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L7717;
    }
 L13961: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[1] = x4;
      goto L7736;
    }
  x2 = XEXP (x1, 0);
  goto L13764;

 L7717: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L7718;
    }
  x4 = XEXP (x3, 0);
  goto L13961;

 L7718: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7719;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13961;

 L7719: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7720;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13961;

 L7720: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7721;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13961;

 L7721: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE2 && TARGET_SSE_MATH && TARGET_IEEE_FP))
    {
      return 655;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L13961;

 L7736: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[2] = x4;
      goto L7737;
    }
  x2 = XEXP (x1, 0);
  goto L13764;

 L7737: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[1]))
    goto L7738;
  x2 = XEXP (x1, 0);
  goto L13764;

 L7738: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (rtx_equal_p (x3, operands[2]))
    goto L7739;
  x2 = XEXP (x1, 0);
  goto L13764;

 L7739: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7740;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L7740: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE2 && TARGET_SSE_MATH && !TARGET_IEEE_FP
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 656;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L622: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L623;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L623: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L624;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L624: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0])
      && (reload_completed || !TARGET_SSE2))
    {
      return 95;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13764;

 L917: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L13962;
  x2 = XEXP (x1, 0);
  goto L13773;

 L13962: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case FLOAT_TRUNCATE:
      goto L918;
    case NEG:
      goto L4208;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L13773;

 L918: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case XFmode:
      goto L13964;
    case TFmode:
      goto L13965;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L13773;

 L13964: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, XFmode))
    {
      operands[1] = x3;
      goto L919;
    }
  x2 = XEXP (x1, 0);
  goto L13773;

 L919: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L920;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L920: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L921;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L921: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387))
    {
      return 142;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L13965: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L932;
    }
  x2 = XEXP (x1, 0);
  goto L13773;

 L932: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L933;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L933: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L934;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L934: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387))
    {
      return 144;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L4208: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4209;
    }
  x2 = XEXP (x1, 0);
  goto L13773;

 L4209: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4210;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L4210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L4211;
    }
 L4227: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L4228;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L4211: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode))))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 364;
    }
  x1 = XVECEXP (x0, 0, 1);
  x2 = XEXP (x1, 0);
  goto L4227;

 L4228: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode))))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 365;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13773;

 L4186: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L13966;
  x2 = XEXP (x1, 0);
  goto L13774;

 L13966: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4187;
    case ABS:
      goto L4372;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L13774;

 L4187: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (memory_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4188;
    }
  x2 = XEXP (x1, 0);
  goto L13774;

 L4188: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4189;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13774;

 L4189: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (NEG, DFmode, operands)))
    {
      return 363;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13774;

 L4372: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (memory_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4373;
    }
  x2 = XEXP (x1, 0);
  goto L13774;

 L4373: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4374;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13774;

 L4374: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_unary_operator_ok (ABS, DFmode, operands)))
    {
      return 382;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13774;

 L4232: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L13968;
  x2 = XEXP (x1, 0);
  goto L376;

 L13968: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4233;
    case ABS:
      goto L4393;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L4233: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4234;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4234: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4235;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4235: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13970;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13970: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13972;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13972: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13974;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13974: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (NEG, DFmode, operands)))
    {
      return 366;
    }
 L13975: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (NEG, DFmode, operands)))
    {
      return 367;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4393: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4394;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4394: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  switch (GET_CODE (x1))
    {
    case USE:
      goto L4395;
    case CLOBBER:
      goto L4420;
    default:
     break;
   }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4395: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L4396;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4396: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode))))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 383;
    }
 L4413: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode))))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 384;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4420: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L13976;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13976: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L13978;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13978: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L13980;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13980: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (ABS, DFmode, operands)))
    {
      return 385;
    }
 L13981: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (ABS, DFmode, operands)))
    {
      return 386;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13761: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, XFmode))
    {
      operands[0] = x2;
      goto L660;
    }
 L13775: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, XFmode))
    {
      operands[0] = x2;
      goto L4256;
    }
  goto L376;

 L660: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, XFmode))
    {
      operands[1] = x2;
      goto L661;
    }
  x2 = XEXP (x1, 0);
  goto L13775;

 L661: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L662;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13775;

 L662: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L663;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13775;

 L663: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0]))
    {
      return 104;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13775;

 L4256: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == XFmode)
    goto L13982;
  x2 = XEXP (x1, 0);
  goto L376;

 L13982: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4257;
    case ABS:
      goto L4442;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L4257: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, XFmode))
    {
      operands[1] = x3;
      goto L4258;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4258: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4259;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (NEG, XFmode, operands)))
    {
      return 368;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4442: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, XFmode))
    {
      operands[1] = x3;
      goto L4443;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4443: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4444;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4444: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && TARGET_80387
   && ix86_unary_operator_ok (ABS, XFmode, operands)))
    {
      return 387;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13762: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TFmode))
    {
      operands[0] = x2;
      goto L667;
    }
 L13776: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, TFmode))
    {
      operands[0] = x2;
      goto L4268;
    }
  goto L376;

 L667: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, TFmode))
    {
      operands[1] = x2;
      goto L668;
    }
  x2 = XEXP (x1, 0);
  goto L13776;

 L668: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L669;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13776;

 L669: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[1]))
    goto L670;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13776;

 L670: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (rtx_equal_p (x2, operands[0]))
    {
      return 105;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L13776;

 L4268: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TFmode)
    goto L13984;
  x2 = XEXP (x1, 0);
  goto L376;

 L13984: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4269;
    case ABS:
      goto L4454;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L4269: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L4270;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4270: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4271;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4271: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_80387 && ix86_unary_operator_ok (NEG, TFmode, operands)))
    {
      return 369;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4454: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, TFmode))
    {
      operands[1] = x3;
      goto L4455;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4455: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4456;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4456: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_80387 && ix86_unary_operator_ok (ABS, TFmode, operands)))
    {
      return 388;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13765: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L1205;
  goto L376;

 L1205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 2
      && XINT (x2, 1) == 27)
    goto L1206;
  x2 = XEXP (x1, 0);
  goto L376;

 L1206: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L13986;
    case SImode:
      goto L13987;
    case QImode:
      goto L13988;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L13986: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L1207;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1207: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (x86_64_general_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L1208;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1208: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1209;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1209: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L1210;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1210: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L1211;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1211: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1212;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1212: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (TARGET_64BIT && ix86_binary_operator_ok (PLUS, DImode, operands)))
    {
      return 181;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13987: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L1264;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1264: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (general_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L1265;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1265: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1266;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1266: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1267;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1267: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L1268;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1268: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1269;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1269: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_binary_operator_ok (PLUS, SImode, operands)))
    {
      return 184;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13988: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L1275;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1275: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (general_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L1276;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L1276: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L1277;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1277: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L1278;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1278: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == PLUS)
    goto L1279;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1279: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L1280;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L1280: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2])
      && (ix86_binary_operator_ok (PLUS, QImode, operands)))
    {
      return 185;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13769: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, TImode))
    {
      operands[0] = x2;
      goto L2236;
    }
  goto L376;

 L2236: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == TImode
      && GET_CODE (x2) == MULT)
    goto L2237;
  x2 = XEXP (x1, 0);
  goto L376;

 L2237: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode)
    goto L13989;
  x2 = XEXP (x1, 0);
  goto L376;

 L13989: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case ZERO_EXTEND:
      goto L2238;
    case SIGN_EXTEND:
      goto L2274;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L2238: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2239;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L2239: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == ZERO_EXTEND)
    goto L2240;
  x2 = XEXP (x1, 0);
  goto L376;

 L2240: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2241;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L2241: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2242;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L2242: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 252;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L2274: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L2275;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L2275: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == SIGN_EXTEND)
    goto L2276;
  x2 = XEXP (x1, 0);
  goto L376;

 L2276: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[2] = x4;
      goto L2277;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L2277: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2278;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L2278: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 254;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13770: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L4027;
  goto L376;

 L4027: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == CCZmode
      && GET_CODE (x2) == COMPARE)
    goto L4028;
  x2 = XEXP (x1, 0);
  goto L376;

 L4028: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L13991;
    case SImode:
      goto L13992;
    case HImode:
      goto L13994;
    case QImode:
      goto L13995;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L13991: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x3))
    {
    case NEG:
      goto L4029;
    case LSHIFTRT:
      goto L4082;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L376;

 L4029: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DImode))
    {
      operands[1] = x4;
      goto L4030;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4030: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4031;
  x2 = XEXP (x1, 0);
  goto L376;

 L4031: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4032;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4032: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4033;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == NEG)
    goto L4034;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4034: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (TARGET_64BIT && ix86_unary_operator_ok (NEG, DImode, operands)))
    {
      return 351;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4082: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == NEG)
    goto L4083;
  x2 = XEXP (x1, 0);
  goto L376;

 L4083: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ASHIFT)
    goto L4084;
  x2 = XEXP (x1, 0);
  goto L376;

 L4084: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (register_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L4085;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4085: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_CODE (x6) == CONST_INT
      && XWINT (x6, 0) == 32LL)
    goto L4086;
  x2 = XEXP (x1, 0);
  goto L376;

 L4086: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L4087;
  x2 = XEXP (x1, 0);
  goto L376;

 L4087: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4088;
  x2 = XEXP (x1, 0);
  goto L376;

 L4088: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4089;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4089: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L4090;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4090: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == LSHIFTRT)
    goto L4091;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == NEG)
    goto L4092;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4092: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == ASHIFT)
    goto L4093;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4093: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (rtx_equal_p (x5, operands[1]))
    goto L4094;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4094: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L4095;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4095: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 32LL
      && (TARGET_64BIT && ix86_unary_operator_ok (NEG, SImode, operands)))
    {
      return 355;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13992: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L4071;
  if (nonimmediate_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L6360;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4071: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L4072;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4072: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4073;
  x2 = XEXP (x1, 0);
  goto L376;

 L4073: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4074;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4074: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L4075;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4075: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == NEG)
    goto L4076;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4076: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (ix86_unary_operator_ok (NEG, SImode, operands)))
    {
      return 354;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L6360: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L6361;
  x2 = XEXP (x1, 0);
  goto L376;

 L6361: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6362;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L6362: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6363;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L6363: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UNSPEC
      && XVECLEN (x2, 0) == 1
      && XINT (x2, 1) == 23)
    goto L6364;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L6364: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (rtx_equal_p (x3, operands[1]))
    {
      return 536;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13994: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L4113;
  x2 = XEXP (x1, 0);
  goto L376;

 L4113: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, HImode))
    {
      operands[1] = x4;
      goto L4114;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4114: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4115;
  x2 = XEXP (x1, 0);
  goto L376;

 L4115: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4116;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4116: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L4117;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4117: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == NEG)
    goto L4118;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4118: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (ix86_unary_operator_ok (NEG, HImode, operands)))
    {
      return 357;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L13995: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == NEG)
    goto L4136;
  x2 = XEXP (x1, 0);
  goto L376;

 L4136: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, QImode))
    {
      operands[1] = x4;
      goto L4137;
    }
  x2 = XEXP (x1, 0);
  goto L376;

 L4137: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 0LL)
    goto L4138;
  x2 = XEXP (x1, 0);
  goto L376;

 L4138: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L4139;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4139: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      operands[0] = x2;
      goto L4140;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4140: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode
      && GET_CODE (x2) == NEG)
    goto L4141;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L4141: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1])
      && (ix86_unary_operator_ok (NEG, QImode, operands)))
    {
      return 359;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L376;

 L377: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case HImode:
      goto L13997;
    case QImode:
      goto L13998;
    default:
      break;
    }
  goto L7985;

 L13997: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, HImode))
    {
      operands[0] = x3;
      goto L378;
    }
  goto L7985;

 L378: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, HImode))
    {
      operands[1] = x2;
      goto L379;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L379: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L380;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L380: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (reload_completed
   && ((!TARGET_USE_MOV0 && !TARGET_PARTIAL_REG_STALL) || optimize_size)))
    {
      return 56;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L13998: ATTRIBUTE_UNUSED_LABEL
  if (q_regs_operand (x3, QImode))
    {
      operands[0] = x3;
      goto L414;
    }
 L13999: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x3, QImode))
    {
      operands[0] = x3;
      goto L1675;
    }
  goto L7985;

 L414: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (const0_operand (x2, QImode))
    {
      operands[1] = x2;
      goto L415;
    }
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13999;

 L415: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L416;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13999;

 L416: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (reload_completed && (!TARGET_USE_MOV0 || optimize_size)))
    {
      return 62;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  goto L13999;

 L1675: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == QImode)
    goto L14000;
  x2 = XEXP (x1, 0);
  goto L7985;

 L14000: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L1676;
    case MINUS:
      goto L2090;
    case AND:
      goto L3017;
    case IOR:
      goto L3404;
    case XOR:
      goto L3787;
    case ASHIFTRT:
      goto L5155;
    case LSHIFTRT:
      goto L5493;
    case ROTATE:
      goto L5681;
    case ROTATERT:
      goto L5871;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L7985;

 L1676: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L1677;
  x2 = XEXP (x1, 0);
  goto L7985;

 L1677: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L1678;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L1678: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L1679;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L1679: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 217;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L2090: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L2091;
  x2 = XEXP (x1, 0);
  goto L7985;

 L2091: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L2092;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L2092: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2093;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L2093: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 242;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L3017: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3018;
  x2 = XEXP (x1, 0);
  goto L7985;

 L3018: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3019;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L3019: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3020;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L3020: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 295;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L3404: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3405;
  x2 = XEXP (x1, 0);
  goto L7985;

 L3405: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3406;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L3406: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3407;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L3407: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 317;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L3787: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L3788;
  x2 = XEXP (x1, 0);
  goto L7985;

 L3788: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (general_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L3789;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L3789: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L3790;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L3790: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 339;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5155: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L5156;
  x2 = XEXP (x1, 0);
  goto L7985;

 L5156: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5157;
    }
 L5186: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5187;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L5157: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5158;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5186;

 L5158: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (ix86_binary_operator_ok (ASHIFTRT, QImode, operands)
   && (! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 446;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5186;

 L5187: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5188;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5188: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 448;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5493: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L5494;
  x2 = XEXP (x1, 0);
  goto L7985;

 L5494: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5495;
    }
 L5524: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5525;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L5495: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5496;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5524;

 L5496: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 470;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5524;

 L5525: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5526;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 472;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5681: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L5682;
  x2 = XEXP (x1, 0);
  goto L7985;

 L5682: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5683;
    }
 L5712: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5713;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L5683: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5684;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5712;

 L5684: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 483;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5712;

 L5713: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5714;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5714: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 485;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5871: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[0]))
    goto L5872;
  x2 = XEXP (x1, 0);
  goto L7985;

 L5872: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (const_int_1_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5873;
    }
 L5902: ATTRIBUTE_UNUSED_LABEL
  if (nonmemory_operand (x3, QImode))
    {
      operands[1] = x3;
      goto L5903;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L5873: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5874;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5902;

 L5874: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (TARGET_SHIFT1 || optimize_size)))
    {
      return 496;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  goto L5902;

 L5903: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5904;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L5904: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && ((! TARGET_PARTIAL_REG_STALL || optimize_size)
   && (GET_CODE (operands[0]) != MEM || GET_CODE (operands[1]) != MEM)))
    {
      return 498;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L13777: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L1372;
  goto L7985;

 L1372: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == COMPARE)
    goto L1373;
  x2 = XEXP (x1, 0);
  goto L7985;

 L1373: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L14009;
    case SImode:
      goto L14012;
    case HImode:
      goto L14015;
    case QImode:
      goto L14018;
    default:
      break;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L14009: ATTRIBUTE_UNUSED_LABEL
  tem = recog_27 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L7985;

 L14012: ATTRIBUTE_UNUSED_LABEL
  tem = recog_28 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L7985;

 L14015: ATTRIBUTE_UNUSED_LABEL
  tem = recog_29 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L7985;

 L14018: ATTRIBUTE_UNUSED_LABEL
  tem = recog_30 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L7985;

 L6215: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  switch (GET_MODE (x2))
    {
    case SImode:
      goto L14103;
    case DImode:
      goto L14104;
    default:
      break;
    }
 L6250: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L6251;
  x2 = XEXP (x1, 0);
  goto L7985;

 L14103: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6216;
    }
  goto L6250;

 L6216: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L6217;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6250;

 L6217: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6218;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6250;

 L6218: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L6219;

 L6219: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 518;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6250;

 L14104: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L6224;
    }
  goto L6250;

 L6224: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L6225;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6250;

 L6225: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF)
    goto L6226;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6250;

 L6226: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  goto L6227;

 L6227: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT))
    {
      return 519;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  goto L6250;

 L6251: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == NE)
    goto L6252;
  x2 = XEXP (x1, 0);
  goto L7985;

 L6252: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L6253;
    }
  x2 = XEXP (x1, 0);
  goto L7985;

 L6253: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 1LL)
    goto L6254;
  x2 = XEXP (x1, 0);
  goto L7985;

 L6254: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == LABEL_REF)
    goto L6255;
  x2 = XEXP (x1, 0);
  goto L7985;

 L6255: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[0] = x4;
  goto L6256;

 L6256: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L6257;
  x2 = XEXP (x1, 0);
  goto L7985;

 L6257: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6258;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L6258: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L6259;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L6259: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6260;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L6260: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L6261;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L6261: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == -1LL
      && (!TARGET_64BIT && TARGET_USE_LOOP)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 2;
      return 520;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L7985;

 L7986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL)
    goto L7987;
  goto ret0;

 L7987: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == QImode
      && GET_CODE (x3) == MEM)
    goto L7988;
  goto ret0;

 L7988: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == SImode)
    goto L14105;
  goto ret0;

 L14105: ATTRIBUTE_UNUSED_LABEL
  if (constant_call_address_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L7989;
    }
 L14106: ATTRIBUTE_UNUSED_LABEL
  if (call_insn_operand (x4, SImode))
    {
      operands[1] = x4;
      goto L8002;
    }
  goto ret0;

 L7989: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L7990;

 L7990: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7991;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14106;

 L7991: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L7992;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14106;

 L7992: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7993;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14106;

 L7993: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L7994;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14106;

 L7994: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L7995;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14106;

 L7995: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 674;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  goto L14106;

 L8002: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  goto L8003;

 L8003: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L8004;
  goto ret0;

 L8004: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L8005;
  goto ret0;

 L8005: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L8006;
  goto ret0;

 L8006: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L8007;
  goto ret0;

 L8007: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L8008;
    }
  goto ret0;

 L8008: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 675;
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

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case REG:
      goto L14128;
    case MEM:
      goto L7129;
    default:
     break;
   }
 L14111: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L272;
    }
 L14114: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1023;
    }
 L14117: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2333;
    }
  goto ret0;

 L14128: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 7)
    goto L6332;
  goto L14111;

 L6332: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6333;
  x2 = XEXP (x1, 0);
  goto L14111;

 L6333: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 6)
    goto L6334;
  x2 = XEXP (x1, 0);
  goto L14111;

 L6334: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 4LL)
    goto L6335;
  x2 = XEXP (x1, 0);
  goto L14111;

 L6335: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6336;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L6336: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L6337;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L6337: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L6338;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L6338: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 6)
    goto L6339;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L6339: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6340;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L6340: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L6341;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L6341: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (!TARGET_64BIT))
    {
      return 534;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7129: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DImode:
      goto L14129;
    case SImode:
      goto L14130;
    default:
      break;
    }
  goto L14111;

 L14129: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L7130;
    }
  goto L14111;

 L7130: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7131;
    }
  x2 = XEXP (x1, 0);
  goto L14111;

 L7131: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7132;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7132: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L7133;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7133: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7134;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7134: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7135;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7135: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT)
    goto L14131;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L14131: ATTRIBUTE_UNUSED_LABEL
  if ((int) XWINT (x3, 0) == XWINT (x3, 0))
    switch ((int) XWINT (x3, 0))
      {
      case 8LL:
        goto L7136;
      case 4LL:
        goto L7160;
      default:
        break;
      }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7136: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7137;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7137: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 618;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7160: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7161;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7161: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 620;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L14130: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L7142;
    }
  goto L14111;

 L7142: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L7143;
    }
  x2 = XEXP (x1, 0);
  goto L14111;

 L7143: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7144;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7144: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L7145;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7145: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7146;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7146: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7147;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7147: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 4LL)
    goto L7148;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7148: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7149;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L7149: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (!TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 619;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14111;

 L272: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L273;
  x2 = XEXP (x1, 0);
  goto L14114;

 L273: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L274;
  x2 = XEXP (x1, 0);
  goto L14114;

 L274: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L275;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L275: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L276;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L276: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L277;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L277: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L278;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L278: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 4LL)
    goto L279;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L279: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L280;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L280: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L281;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L281: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (!TARGET_64BIT))
    {
      return 40;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14114;

 L1023: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == FIX)
    goto L1024;
  x2 = XEXP (x1, 0);
  goto L14117;

 L1024: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1025;
    }
  x2 = XEXP (x1, 0);
  goto L14117;

 L1025: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L1026;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14117;

 L1026: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L1027;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14117;

 L1027: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L1028;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14117;

 L1028: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L1029;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14117;

 L1029: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && FLOAT_MODE_P (GET_MODE (operands[1]))
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
    {
      return 153;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14117;

 L2333: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode)
    goto L14133;
  goto ret0;

 L14133: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case TRUNCATE:
      goto L2334;
    case DIV:
      goto L2568;
    case UDIV:
      goto L2721;
    case UNSPEC:
      goto L14138;
    case PLUS:
      goto L7761;
    default:
     break;
   }
  goto ret0;

 L2334: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L2335;
  goto ret0;

 L2335: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == MULT)
    goto L2336;
  goto ret0;

 L2336: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode)
    goto L14139;
  goto ret0;

 L14139: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ZERO_EXTEND:
      goto L2337;
    case SIGN_EXTEND:
      goto L2414;
    default:
     break;
   }
  goto ret0;

 L2337: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2338;
    }
  goto ret0;

 L2338: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L2339;
  goto ret0;

 L2339: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2340;
    }
  goto ret0;

 L2340: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L2341;
  goto ret0;

 L2341: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2342;
  goto ret0;

 L2342: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2343;
    }
  goto ret0;

 L2343: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2344;
  goto ret0;

 L2344: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
    {
      return 257;
    }
  goto ret0;

 L2414: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[1] = x6;
      goto L2415;
    }
  goto ret0;

 L2415: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L2416;
  goto ret0;

 L2416: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, SImode))
    {
      operands[2] = x6;
      goto L2417;
    }
  goto ret0;

 L2417: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 32LL)
    goto L2418;
  goto ret0;

 L2418: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2419;
  goto ret0;

 L2419: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2420;
    }
  goto ret0;

 L2420: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2421;
  goto ret0;

 L2421: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM))
    {
      return 260;
    }
  goto ret0;

 L2568: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode)
    goto L14141;
  goto ret0;

 L14141: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2569;
    }
 L14142: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2632;
    }
  goto ret0;

 L2569: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L2570;
    }
  x3 = XEXP (x2, 0);
  goto L14142;

 L2570: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2571;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2571: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L2572;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2572: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L2573;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2573: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L2574;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2574: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3]))
    goto L2575;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2575: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2576;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2576: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L14143;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L14143: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L14145;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L14145: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L14147;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L14147: ATTRIBUTE_UNUSED_LABEL
  if ((!optimize_size && !TARGET_USE_CLTD))
    {
      return 267;
    }
 L14148: ATTRIBUTE_UNUSED_LABEL
  if ((optimize_size || TARGET_USE_CLTD))
    {
      return 268;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14142;

 L2632: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2633;
    }
  goto ret0;

 L2633: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2634;
  goto ret0;

 L2634: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2635;
    }
  goto ret0;

 L2635: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MOD)
    goto L2636;
  goto ret0;

 L2636: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2637;
  goto ret0;

 L2637: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2638;
  goto ret0;

 L2638: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L2639;
  goto ret0;

 L2639: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[4] = x2;
      goto L2640;
    }
  goto ret0;

 L2640: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 269;
    }
  goto ret0;

 L2721: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L2722;
    }
  goto ret0;

 L2722: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L2723;
    }
  goto ret0;

 L2723: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2724;
  goto ret0;

 L2724: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2725;
    }
  goto ret0;

 L2725: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == UMOD)
    goto L2726;
  goto ret0;

 L2726: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2727;
  goto ret0;

 L2727: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2728;
  goto ret0;

 L2728: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L2729;
    case USE:
      goto L2768;
    default:
     break;
   }
  goto ret0;

 L2729: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    {
      return 273;
    }
  goto ret0;

 L2768: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[3])
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 274;
    }
  goto ret0;

 L14138: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 4
      && XINT (x2, 1) == 20)
    goto L7424;
  goto ret0;

 L7424: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_MODE (x3) == BLKmode
      && GET_CODE (x3) == MEM)
    goto L7425;
  goto ret0;

 L7425: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      operands[5] = x4;
      goto L7426;
    }
  goto ret0;

 L7426: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L7427;
    }
  goto ret0;

 L7427: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (immediate_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L7428;
    }
  goto ret0;

 L7428: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (register_operand (x3, SImode))
    {
      operands[4] = x3;
      goto L7429;
    }
  goto ret0;

 L7429: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L7430;
  goto ret0;

 L7430: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19)
    goto L7431;
  goto ret0;

 L7431: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7432;
  goto ret0;

 L7432: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[1] = x2;
      goto L7433;
    }
  goto ret0;

 L7433: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 634;
    }
  goto ret0;

 L7761: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L7762;
    }
  goto ret0;

 L7762: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (immediate_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L7763;
    }
  goto ret0;

 L7763: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7764;
  goto ret0;

 L7764: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L7765;
  goto ret0;

 L7765: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7766;
  goto ret0;

 L7766: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L7767;
  goto ret0;

 L7767: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (!TARGET_64BIT))
    {
      return 658;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_33 PARAMS ((rtx, rtx, int *));
static int
recog_33 (x0, insn, pnum_clobbers)
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
    case TRUNCATE:
      goto L2309;
    case ZERO_EXTEND:
      goto L2359;
    case DIV:
      goto L2491;
    case UDIV:
      goto L2669;
    case ASHIFT:
      goto L4625;
    case ASHIFTRT:
      goto L4887;
    case LSHIFTRT:
      goto L5280;
    case UNSPEC:
      goto L14160;
    case PLUS:
      goto L7772;
    default:
     break;
   }
  goto ret0;

 L2309: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == TImode
      && GET_CODE (x3) == LSHIFTRT)
    goto L2310;
  goto ret0;

 L2310: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == TImode
      && GET_CODE (x4) == MULT)
    goto L2311;
  goto ret0;

 L2311: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == TImode)
    goto L14161;
  goto ret0;

 L14161: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x5))
    {
    case ZERO_EXTEND:
      goto L2312;
    case SIGN_EXTEND:
      goto L2389;
    default:
     break;
   }
  goto ret0;

 L2312: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L2313;
    }
  goto ret0;

 L2313: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == TImode
      && GET_CODE (x5) == ZERO_EXTEND)
    goto L2314;
  goto ret0;

 L2314: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L2315;
    }
  goto ret0;

 L2315: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 64LL)
    goto L2316;
  goto ret0;

 L2316: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2317;
  goto ret0;

 L2317: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2318;
    }
  goto ret0;

 L2318: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2319;
  goto ret0;

 L2319: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 256;
    }
  goto ret0;

 L2389: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, DImode))
    {
      operands[1] = x6;
      goto L2390;
    }
  goto ret0;

 L2390: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_MODE (x5) == TImode
      && GET_CODE (x5) == SIGN_EXTEND)
    goto L2391;
  goto ret0;

 L2391: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (nonimmediate_operand (x6, DImode))
    {
      operands[2] = x6;
      goto L2392;
    }
  goto ret0;

 L2392: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) == CONST_INT
      && XWINT (x4, 0) == 64LL)
    goto L2393;
  goto ret0;

 L2393: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2394;
  goto ret0;

 L2394: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2395;
    }
  goto ret0;

 L2395: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2396;
  goto ret0;

 L2396: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 259;
    }
  goto ret0;

 L2359: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == SImode
      && GET_CODE (x3) == TRUNCATE)
    goto L2360;
  goto ret0;

 L2360: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) == DImode
      && GET_CODE (x4) == LSHIFTRT)
    goto L2361;
  goto ret0;

 L2361: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 0);
  if (GET_MODE (x5) == DImode
      && GET_CODE (x5) == MULT)
    goto L2362;
  goto ret0;

 L2362: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 0);
  if (GET_MODE (x6) == DImode)
    goto L14163;
  goto ret0;

 L14163: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x6))
    {
    case ZERO_EXTEND:
      goto L2363;
    case SIGN_EXTEND:
      goto L2440;
    default:
     break;
   }
  goto ret0;

 L2363: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (nonimmediate_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L2364;
    }
  goto ret0;

 L2364: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == ZERO_EXTEND)
    goto L2365;
  goto ret0;

 L2365: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (nonimmediate_operand (x7, SImode))
    {
      operands[2] = x7;
      goto L2366;
    }
  goto ret0;

 L2366: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L2367;
  goto ret0;

 L2367: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2368;
  goto ret0;

 L2368: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2369;
    }
  goto ret0;

 L2369: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2370;
  goto ret0;

 L2370: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 258;
    }
  goto ret0;

 L2440: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (nonimmediate_operand (x7, SImode))
    {
      operands[1] = x7;
      goto L2441;
    }
  goto ret0;

 L2441: ATTRIBUTE_UNUSED_LABEL
  x6 = XEXP (x5, 1);
  if (GET_MODE (x6) == DImode
      && GET_CODE (x6) == SIGN_EXTEND)
    goto L2442;
  goto ret0;

 L2442: ATTRIBUTE_UNUSED_LABEL
  x7 = XEXP (x6, 0);
  if (nonimmediate_operand (x7, SImode))
    {
      operands[2] = x7;
      goto L2443;
    }
  goto ret0;

 L2443: ATTRIBUTE_UNUSED_LABEL
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) == CONST_INT
      && XWINT (x5, 0) == 32LL)
    goto L2444;
  goto ret0;

 L2444: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L2445;
  goto ret0;

 L2445: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L2446;
    }
  goto ret0;

 L2446: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2447;
  goto ret0;

 L2447: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT
   && (GET_CODE (operands[1]) != MEM || GET_CODE (operands[2]) != MEM)))
    {
      return 261;
    }
  goto ret0;

 L2491: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode)
    goto L14165;
  goto ret0;

 L14165: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2492;
    }
 L14166: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2555;
    }
  goto ret0;

 L2492: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L2493;
    }
  x3 = XEXP (x2, 0);
  goto L14166;

 L2493: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2494;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2494: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L2495;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2495: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MOD)
    goto L2496;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2496: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L2497;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2497: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[3]))
    goto L2498;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2498: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2499;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2499: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L14167;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L14167: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L14169;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L14169: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L14171;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L14171: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && !optimize_size && !TARGET_USE_CLTD))
    {
      return 264;
    }
 L14172: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && (optimize_size || TARGET_USE_CLTD)))
    {
      return 265;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L14166;

 L2555: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2556;
    }
  goto ret0;

 L2556: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2557;
  goto ret0;

 L2557: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2558;
    }
  goto ret0;

 L2558: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MOD)
    goto L2559;
  goto ret0;

 L2559: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2560;
  goto ret0;

 L2560: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2561;
  goto ret0;

 L2561: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L2562;
  goto ret0;

 L2562: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[4] = x2;
      goto L2563;
    }
  goto ret0;

 L2563: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 266;
    }
  goto ret0;

 L2669: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L2670;
    }
  goto ret0;

 L2670: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L2671;
    }
  goto ret0;

 L2671: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2672;
  goto ret0;

 L2672: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[3] = x2;
      goto L2673;
    }
  goto ret0;

 L2673: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == UMOD)
    goto L2674;
  goto ret0;

 L2674: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2675;
  goto ret0;

 L2675: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2676;
  goto ret0;

 L2676: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  switch (GET_CODE (x1))
    {
    case CLOBBER:
      goto L2677;
    case USE:
      goto L2716;
    default:
     break;
   }
  goto ret0;

 L2677: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT))
    {
      return 271;
    }
  goto ret0;

 L2716: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (rtx_equal_p (x2, operands[3])
      && (TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 272;
    }
  goto ret0;

 L4625: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4626;
    }
  goto ret0;

 L4626: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4627;
    }
  goto ret0;

 L4627: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4628;
  goto ret0;

 L4628: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4629;
    }
  goto ret0;

 L4629: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4630;
  goto ret0;

 L4630: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && TARGET_CMOVE))
    {
      return 410;
    }
  goto ret0;

 L4887: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L4888;
    }
  goto ret0;

 L4888: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L4889;
    }
  goto ret0;

 L4889: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L4890;
  goto ret0;

 L4890: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L4891;
    }
  goto ret0;

 L4891: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4892;
  goto ret0;

 L4892: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && TARGET_CMOVE))
    {
      return 428;
    }
  goto ret0;

 L5280: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L5281;
    }
  goto ret0;

 L5281: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonmemory_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L5282;
    }
  goto ret0;

 L5282: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5283;
  goto ret0;

 L5283: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[3] = x2;
      goto L5284;
    }
  goto ret0;

 L5284: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5285;
  goto ret0;

 L5285: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && TARGET_CMOVE))
    {
      return 455;
    }
  goto ret0;

 L14160: ATTRIBUTE_UNUSED_LABEL
  if (XVECLEN (x2, 0) == 4
      && XINT (x2, 1) == 20)
    goto L7453;
  goto ret0;

 L7453: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 0);
  if (GET_MODE (x3) == BLKmode
      && GET_CODE (x3) == MEM)
    goto L7454;
  goto ret0;

 L7454: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, DImode))
    {
      operands[5] = x4;
      goto L7455;
    }
  goto ret0;

 L7455: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 1);
  if (register_operand (x3, QImode))
    {
      operands[2] = x3;
      goto L7456;
    }
  goto ret0;

 L7456: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 2);
  if (immediate_operand (x3, DImode))
    {
      operands[3] = x3;
      goto L7457;
    }
  goto ret0;

 L7457: ATTRIBUTE_UNUSED_LABEL
  x3 = XVECEXP (x2, 0, 3);
  if (register_operand (x3, DImode))
    {
      operands[4] = x3;
      goto L7458;
    }
  goto ret0;

 L7458: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L7459;
  goto ret0;

 L7459: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19)
    goto L7460;
  goto ret0;

 L7460: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7461;
  goto ret0;

 L7461: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[1] = x2;
      goto L7462;
    }
  goto ret0;

 L7462: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT)
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 635;
    }
  goto ret0;

 L7772: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L7773;
    }
  goto ret0;

 L7773: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (x86_64_immediate_operand (x3, DImode))
    {
      operands[2] = x3;
      goto L7774;
    }
  goto ret0;

 L7774: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7775;
  goto ret0;

 L7775: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L7776;
  goto ret0;

 L7776: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7777;
  goto ret0;

 L7777: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L7778;
  goto ret0;

 L7778: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (TARGET_64BIT))
    {
      return 659;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_34 PARAMS ((rtx, rtx, int *));
static int
recog_34 (x0, insn, pnum_clobbers)
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
    case SImode:
      goto L14121;
    case DImode:
      goto L14122;
    case HImode:
      goto L14124;
    case SFmode:
      goto L14119;
    case DFmode:
      goto L14120;
    case QImode:
      goto L14125;
    default:
      break;
    }
 L5955: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == PC)
    goto L5956;
  goto ret0;

 L14121: ATTRIBUTE_UNUSED_LABEL
  tem = recog_32 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  goto L5955;

 L14122: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L6345;
 L14112: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L518;
    }
 L14113: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L986;
    }
 L14116: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L2308;
    }
  goto L5955;

 L6345: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L6346;
  x2 = XEXP (x1, 0);
  goto L14112;

 L6346: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 6)
    goto L6347;
  x2 = XEXP (x1, 0);
  goto L14112;

 L6347: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L6348;
  x2 = XEXP (x1, 0);
  goto L14112;

 L6348: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6349;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L6349: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 6)
    goto L6350;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L6350: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == MEM)
    goto L6351;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L6351: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 6)
    goto L6352;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L6352: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6353;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L6353: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L6354;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L6354: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (TARGET_64BIT))
    {
      return 535;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14112;

 L518: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L14149;
  x2 = XEXP (x1, 0);
  goto L14113;

 L14149: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case MEM:
      goto L519;
    case SIGN_EXTEND:
      goto L777;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L14113;

 L519: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L520;
  x2 = XEXP (x1, 0);
  goto L14113;

 L520: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L521;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L521: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 7)
    goto L522;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L522: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L523;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L523: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == DImode
      && GET_CODE (x3) == REG
      && XINT (x3, 0) == 7)
    goto L524;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L524: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 8LL)
    goto L525;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L525: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L526;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L526: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode
      && GET_CODE (x2) == MEM)
    goto L527;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L527: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) == SCRATCH
      && (TARGET_64BIT))
    {
      return 78;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L777: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L778;
    }
  x2 = XEXP (x1, 0);
  goto L14113;

 L778: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L779;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L779: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17)
    goto L780;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L780: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L781;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L781: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      operands[2] = x2;
      goto L782;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L782: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT))
    {
      return 118;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14113;

 L986: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == FIX)
    goto L987;
  x2 = XEXP (x1, 0);
  goto L14116;

 L987: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L988;
    }
  x2 = XEXP (x1, 0);
  goto L14116;

 L988: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L989;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14116;

 L989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L990;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14116;

 L990: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L991;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14116;

 L991: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L992;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14116;

 L992: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && FLOAT_MODE_P (GET_MODE (operands[1]))
   && (!SSE_FLOAT_MODE_P (GET_MODE (operands[1])) || !TARGET_64BIT))
      && pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 148;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14116;

 L2308: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode)
    goto L14151;
  x2 = XEXP (x1, 0);
  goto L5955;

 L14151: ATTRIBUTE_UNUSED_LABEL
  tem = recog_33 (x0, insn, pnum_clobbers);
  if (tem >= 0)
    return tem;
  x2 = XEXP (x1, 0);
  goto L5955;

 L14124: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L7165;
 L14115: ATTRIBUTE_UNUSED_LABEL
  if (memory_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L1060;
    }
 L14118: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, HImode))
    {
      operands[0] = x2;
      goto L2644;
    }
  goto L5955;

 L7165: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L14173;
    case DImode:
      goto L14174;
    default:
      break;
    }
  goto L14115;

 L14173: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L7166;
    }
  goto L14115;

 L7166: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L7167;
    }
  x2 = XEXP (x1, 0);
  goto L14115;

 L7167: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7168;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7168: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L7169;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7169: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7170;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7170: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7171;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7171: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 2LL)
    goto L7172;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7172: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7173;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7173: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (!TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 621;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L14174: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L7178;
    }
  goto L14115;

 L7178: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L7179;
    }
  x2 = XEXP (x1, 0);
  goto L14115;

 L7179: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7180;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7180: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L7181;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7181: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7182;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7182: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7183;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7183: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 2LL)
    goto L7184;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7184: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7185;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L7185: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 622;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14115;

 L1060: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == FIX)
    goto L1061;
  x2 = XEXP (x1, 0);
  goto L14118;

 L1061: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L1062;
    }
  x2 = XEXP (x1, 0);
  goto L14118;

 L1062: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L1063;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14118;

 L1063: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, HImode))
    {
      operands[2] = x2;
      goto L1064;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14118;

 L1064: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L1065;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14118;

 L1065: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L1066;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14118;

 L1066: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387 && FLOAT_MODE_P (GET_MODE (operands[1]))
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))))
    {
      return 158;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14118;

 L2644: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode)
    goto L14175;
  x2 = XEXP (x1, 0);
  goto L5955;

 L14175: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L2645;
    case UDIV:
      goto L2788;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L5955;

 L2645: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2646;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L2646: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2647;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L2647: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2648;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2648: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L2649;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2649: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == MOD)
    goto L2650;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2650: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2651;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2651: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2652;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2652: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L2653;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2653: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_HIMODE_MATH))
    {
      return 270;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2788: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, HImode))
    {
      operands[1] = x3;
      goto L2789;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L2789: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, HImode))
    {
      operands[2] = x3;
      goto L2790;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L2790: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L2791;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2791: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[3] = x2;
      goto L2792;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2792: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == HImode
      && GET_CODE (x2) == UMOD)
    goto L2793;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2793: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L2794;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2794: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, operands[2]))
    goto L2795;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2795: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L2796;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2796: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, HImode))
    {
      operands[4] = x2;
      goto L2797;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L2797: ATTRIBUTE_UNUSED_LABEL
  if (pnum_clobbers != NULL)
    {
      *pnum_clobbers = 1;
      return 275;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L14119: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L4157;
    }
 L14126: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SFmode))
    {
      operands[0] = x2;
      goto L7782;
    }
  goto L5955;

 L4157: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode)
    goto L14177;
  x2 = XEXP (x1, 0);
  goto L14126;

 L14177: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4158;
    case ABS:
      goto L4343;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L14126;

 L4158: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4159;
    }
  x2 = XEXP (x1, 0);
  goto L14126;

 L4159: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4160;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4160: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L4161;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4161: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4162;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4162: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode)))))
    {
      return 361;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4343: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L4344;
    }
  x2 = XEXP (x1, 0);
  goto L14126;

 L4344: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4345;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4345: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, SFmode))
    {
      operands[2] = x2;
      goto L4346;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4346: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4347;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L4347: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode)))))
    {
      return 380;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14126;

 L7782: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SFmode
      && GET_CODE (x2) == IF_THEN_ELSE)
    goto L7783;
  x2 = XEXP (x1, 0);
  goto L5955;

 L7783: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (sse_comparison_operator (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L7784;
    }
 L7805: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == EQ)
    goto L7806;
  x2 = XEXP (x1, 0);
  goto L5955;

 L7784: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[4] = x4;
      goto L7785;
    }
  goto L7805;

 L7785: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[5] = x4;
      goto L7786;
    }
  goto L7805;

 L7786: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7787;
    }
  x3 = XEXP (x2, 0);
  goto L7805;

 L7787: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[3] = x3;
      goto L7788;
    }
  x3 = XEXP (x2, 0);
  goto L7805;

 L7788: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7789;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7805;

 L7789: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SFmode))
    {
      operands[6] = x2;
      goto L7790;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7805;

 L7790: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7791;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7805;

 L7791: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)
   && (!TARGET_IEEE_FP
       || (GET_CODE (operands[1]) != EQ && GET_CODE (operands[1]) != NE))))
    {
      return 660;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7805;

 L7806: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[3] = x4;
      goto L7807;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7807: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, SFmode))
    {
      operands[4] = x4;
      goto L7808;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7808: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[1] = x3;
      goto L7809;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7809: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (nonimmediate_operand (x3, SFmode))
    {
      operands[2] = x3;
      goto L7810;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7810: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7811;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7811: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SFmode))
    {
      operands[5] = x2;
      goto L7812;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7812: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7813;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7813: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 661;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L14120: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L4198;
    }
 L14127: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, DFmode))
    {
      operands[0] = x2;
      goto L7826;
    }
  goto L5955;

 L4198: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode)
    goto L14179;
  x2 = XEXP (x1, 0);
  goto L14127;

 L14179: ATTRIBUTE_UNUSED_LABEL
  switch (GET_CODE (x2))
    {
    case NEG:
      goto L4199;
    case ABS:
      goto L4384;
    default:
     break;
   }
  x2 = XEXP (x1, 0);
  goto L14127;

 L4199: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4200;
    }
  x2 = XEXP (x1, 0);
  goto L14127;

 L4200: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4201;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4201: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L4202;
    }
 L4218: ATTRIBUTE_UNUSED_LABEL
  if (general_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L4219;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4202: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4203;
  x1 = XVECEXP (x0, 0, 1);
  x2 = XEXP (x1, 0);
  goto L4218;

 L4203: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (!TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode)))))
    {
      return 364;
    }
  x1 = XVECEXP (x0, 0, 1);
  x2 = XEXP (x1, 0);
  goto L4218;

 L4219: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4220;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4220: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode)))))
    {
      return 365;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4384: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L4385;
    }
  x2 = XEXP (x1, 0);
  goto L14127;

 L4385: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE)
    goto L4386;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4386: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (nonmemory_operand (x2, DFmode))
    {
      operands[2] = x2;
      goto L4387;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4387: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L4388;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L4388: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode)
    goto L14181;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L14181: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L14183;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L14183: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L14185;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L14185: ATTRIBUTE_UNUSED_LABEL
  if ((!TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode)))))
    {
      return 383;
    }
 L14186: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_64BIT && TARGET_SSE2
   && (reload_in_progress || reload_completed
       || (register_operand (operands[0], VOIDmode)
	   && register_operand (operands[1], VOIDmode)))))
    {
      return 384;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14127;

 L7826: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DFmode
      && GET_CODE (x2) == IF_THEN_ELSE)
    goto L7827;
  x2 = XEXP (x1, 0);
  goto L5955;

 L7827: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (sse_comparison_operator (x3, VOIDmode))
    {
      operands[1] = x3;
      goto L7828;
    }
 L7849: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x3) == EQ)
    goto L7850;
  x2 = XEXP (x1, 0);
  goto L5955;

 L7828: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[4] = x4;
      goto L7829;
    }
  goto L7849;

 L7829: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[5] = x4;
      goto L7830;
    }
  goto L7849;

 L7830: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7831;
    }
  x3 = XEXP (x2, 0);
  goto L7849;

 L7831: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[3] = x3;
      goto L7832;
    }
  x3 = XEXP (x2, 0);
  goto L7849;

 L7832: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7833;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7849;

 L7833: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[6] = x2;
      goto L7834;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7849;

 L7834: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7835;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7849;

 L7835: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE2
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)
   && (!TARGET_IEEE_FP
       || (GET_CODE (operands[1]) != EQ && GET_CODE (operands[1]) != NE))))
    {
      return 662;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L7849;

 L7850: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[3] = x4;
      goto L7851;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7851: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (nonimmediate_operand (x4, DFmode))
    {
      operands[4] = x4;
      goto L7852;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7852: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[1] = x3;
      goto L7853;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7853: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (nonimmediate_operand (x3, DFmode))
    {
      operands[2] = x3;
      goto L7854;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7854: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L7855;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7855: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      operands[5] = x2;
      goto L7856;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7856: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L7857;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7857: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_SSE
   && (GET_CODE (operands[2]) != MEM || GET_CODE (operands[3]) != MEM)))
    {
      return 663;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L14125: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == MEM)
    goto L7189;
  goto L5955;

 L7189: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L14187;
    case DImode:
      goto L14188;
    default:
      break;
    }
  goto L5955;

 L14187: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[1] = x3;
      goto L7190;
    }
  goto L5955;

 L7190: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L7191;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7191: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7192;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7192: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L7193;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7193: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L7194;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7194: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7195;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7195: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 1LL)
    goto L7196;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7196: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7197;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7197: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (!TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 623;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L14188: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, DImode))
    {
      operands[1] = x3;
      goto L7202;
    }
  goto L5955;

 L7202: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (register_operand (x2, QImode))
    {
      operands[2] = x2;
      goto L7203;
    }
  x2 = XEXP (x1, 0);
  goto L5955;

 L7203: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L7204;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7204: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      operands[0] = x2;
      goto L7205;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7205: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode
      && GET_CODE (x2) == PLUS)
    goto L7206;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7206: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[1]))
    goto L7207;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7207: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT
      && XWINT (x3, 0) == 1LL)
    goto L7208;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7208: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == USE)
    goto L7209;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L7209: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 19
      && (TARGET_64BIT && (TARGET_SINGLE_STRINGOP || optimize_size)))
    {
      return 624;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L5955;

 L5956: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == IF_THEN_ELSE)
    goto L5957;
  goto ret0;

 L5957: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (comparison_operator (x3, VOIDmode))
    {
      operands[0] = x3;
      goto L5958;
    }
  goto ret0;

 L5958: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  if (register_operand (x4, VOIDmode))
    {
      operands[1] = x4;
      goto L5959;
    }
  goto ret0;

 L5959: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 1);
  if (register_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L5960;
    }
 L5982: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x4, VOIDmode))
    {
      operands[2] = x4;
      goto L5983;
    }
  goto ret0;

 L5960: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L5961;
    case PC:
      goto L6030;
    default:
     break;
   }
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L5961: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[3] = x4;
  goto L5962;

 L5962: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L5963;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L5963: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5964;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L5964: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 18)
    goto L5965;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L5965: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5966;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L5966: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_CMOVE && TARGET_80387
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0]))))
    {
      return 505;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L6030: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L6031;
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L6031: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[3] = x4;
  goto L6032;

 L6032: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6033;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L6033: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 18)
    goto L6034;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L6034: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6035;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L6035: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 17
      && (TARGET_CMOVE && TARGET_80387
   && !SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0]))))
    {
      return 508;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  goto L5982;

 L5983: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      goto L5984;
    case PC:
      goto L6054;
    default:
     break;
   }
  goto ret0;

 L5984: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[3] = x4;
  goto L5985;

 L5985: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == PC)
    goto L5986;
  goto ret0;

 L5986: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L5987;
  goto ret0;

 L5987: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 18)
    goto L5988;
  goto ret0;

 L5988: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L5989;
  goto ret0;

 L5989: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode)
    goto L14189;
  goto ret0;

 L14189: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L14191;
  goto ret0;

 L14191: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L14193;
  goto ret0;

 L14193: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0]))))
    {
      return 506;
    }
 L14194: ATTRIBUTE_UNUSED_LABEL
  if ((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0]))))
    {
      return 507;
    }
  goto ret0;

 L6054: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 2);
  if (GET_CODE (x3) == LABEL_REF)
    goto L6055;
  goto ret0;

 L6055: ATTRIBUTE_UNUSED_LABEL
  x4 = XEXP (x3, 0);
  operands[3] = x4;
  goto L6056;

 L6056: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER)
    goto L6057;
  goto ret0;

 L6057: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode
      && GET_CODE (x2) == REG
      && XINT (x2, 0) == 18)
    goto L6058;
  goto ret0;

 L6058: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER)
    goto L6059;
  goto ret0;

 L6059: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == CCFPmode)
    goto L14195;
  goto ret0;

 L14195: ATTRIBUTE_UNUSED_LABEL
  if (GET_CODE (x2) == REG)
    goto L14197;
  goto ret0;

 L14197: ATTRIBUTE_UNUSED_LABEL
  if (XINT (x2, 0) == 17)
    goto L14199;
  goto ret0;

 L14199: ATTRIBUTE_UNUSED_LABEL
  if ((TARGET_80387
   && SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0]))))
    {
      return 509;
    }
 L14200: ATTRIBUTE_UNUSED_LABEL
  if ((SSE_FLOAT_MODE_P (GET_MODE (operands[1]))
   && GET_MODE (operands[1]) == GET_MODE (operands[2])
   && ix86_fp_jump_nontrivial_p (GET_CODE (operands[0]))))
    {
      return 510;
    }
  goto ret0;
 ret0:
  return -1;
}

static int recog_35 PARAMS ((rtx, rtx, int *));
static int
recog_35 (x0, insn, pnum_clobbers)
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
    goto L6894;
 L14205: ATTRIBUTE_UNUSED_LABEL
  if (nonimmediate_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L1011;
    }
 L14208: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L2615;
    }
  goto ret0;

 L6894: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case SImode:
      goto L14219;
    case DImode:
      goto L14220;
    default:
      break;
    }
  goto L14205;

 L14219: ATTRIBUTE_UNUSED_LABEL
  if (register_operand (x3, SImode))
    {
      operands[2] = x3;
      goto L6895;
    }
  goto L14205;

 L6895: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == MEM)
    goto L6896;
  x2 = XEXP (x1, 0);
  goto L14205;

 L6896: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      operands[3] = x3;
      goto L6897;
    }
  x2 = XEXP (x1, 0);
  goto L14205;

 L6897: ATTRIBUTE_UNUSED_LABEL
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET)
    goto L6898;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14205;

 L6898: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      operands[0] = x2;
      goto L6899;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14205;

 L6899: ATTRIBUTE_UNUSED_LABEL
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode
      && GET_CODE (x2) == PLUS)
    goto L6900;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L14205;

 L6900: ATTRIBUTE_UNUSED_LABEL
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, operands[2]))
    goto L6901;
  x1 = XVECEXP (x0, 0, 0);