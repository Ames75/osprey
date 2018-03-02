/*
*  (C) 2008-2011 Advanced Micro Devices, Inc. All Rights Reserved.
*
*  This file is part of AMD LibM 3.0.
*
*  AMD LibM 3.0 is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  AMD LibM 3.0 is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with AMD LibM 3.0.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#include "../inc/libm_amd.h"
#include "../inc/libm_util_amd.h"

#define USE_VAL_WITH_FLAGS
#define USE_NAN_WITH_FLAGS
#define USE_SCALEDOUBLE_1
#define USE_SCALEDOUBLE_2
#define USE_SCALEUPDOUBLE1024
#define USE_SCALEDOWNDOUBLE
#define USE_HANDLE_ERROR
#include "../inc/libm_inlines_amd.h"
#undef USE_VAL_WITH_FLAGS
#undef USE_NAN_WITH_FLAGS
#undef USE_SCALEDOUBLE_1
#undef USE_SCALEDOUBLE_2
#undef USE_SCALEUPDOUBLE1024
#undef USE_SCALEDOWNDOUBLE
#undef USE_HANDLE_ERROR

#include "../inc/libm_errno_amd.h"

#ifndef WINDOWS
/* Deal with errno for out-of-range arguments
   (only used when _LIB_VERSION is _SVID_) */
static inline double retval_errno_edom(double x, double y)
{
  struct exception exc;
  exc.arg1 = x;
  exc.arg2 = y;
  exc.name = (char *)"atan2";
  exc.type = DOMAIN;
  exc.retval = HUGE;
  if (!matherr(&exc))
    {
      (void)fputs("atan2: DOMAIN error\n", stderr);
      __set_errno(EDOM);
    }
  return exc.retval;
}
#endif

#ifdef WINDOWS
#pragma function(atan2)
#endif

double FN_PROTOTYPE(atan2)(double y, double x)
{
  /* Arrays atan_jby256_lead and atan_jby256_tail contain
     leading and trailing parts respectively of precomputed
     values of atan(j/256), for j = 16, 17, ..., 256.
     atan_jby256_lead contains the first 21 bits of precision,
     and atan_jby256_tail contains a further 53 bits precision. */

  static const double atan_jby256_lead[  241] = {
    6.24187886714935302734e-02,  /* 0x3faff55b00000000 */
    6.63088560104370117188e-02,  /* 0x3fb0f99e00000000 */
    7.01969265937805175781e-02,  /* 0x3fb1f86d00000000 */
    7.40829110145568847656e-02,  /* 0x3fb2f71900000000 */
    7.79666304588317871094e-02,  /* 0x3fb3f59f00000000 */
    8.18479657173156738281e-02,  /* 0x3fb4f3fd00000000 */
    8.57268571853637695312e-02,  /* 0x3fb5f23200000000 */
    8.96031260490417480469e-02,  /* 0x3fb6f03b00000000 */
    9.34767723083496093750e-02,  /* 0x3fb7ee1800000000 */
    9.73475575447082519531e-02,  /* 0x3fb8ebc500000000 */
    1.01215422153472900391e-01,  /* 0x3fb9e94100000000 */
    1.05080246925354003906e-01,  /* 0x3fbae68a00000000 */
    1.08941912651062011719e-01,  /* 0x3fbbe39e00000000 */
    1.12800359725952148438e-01,  /* 0x3fbce07c00000000 */
    1.16655409336090087891e-01,  /* 0x3fbddd2100000000 */
    1.20507001876831054688e-01,  /* 0x3fbed98c00000000 */
    1.24354958534240722656e-01,  /* 0x3fbfd5ba00000000 */
    1.28199219703674316406e-01,  /* 0x3fc068d500000000 */
    1.32039666175842285156e-01,  /* 0x3fc0e6ad00000000 */
    1.35876297950744628906e-01,  /* 0x3fc1646500000000 */
    1.39708757400512695312e-01,  /* 0x3fc1e1fa00000000 */
    1.43537282943725585938e-01,  /* 0x3fc25f6e00000000 */
    1.47361397743225097656e-01,  /* 0x3fc2dcbd00000000 */
    1.51181221008300781250e-01,  /* 0x3fc359e800000000 */
    1.54996633529663085938e-01,  /* 0x3fc3d6ee00000000 */
    1.58807516098022460938e-01,  /* 0x3fc453ce00000000 */
    1.62613749504089355469e-01,  /* 0x3fc4d08700000000 */
    1.66415214538574218750e-01,  /* 0x3fc54d1800000000 */
    1.70211911201477050781e-01,  /* 0x3fc5c98100000000 */
    1.74003481864929199219e-01,  /* 0x3fc645bf00000000 */
    1.77790164947509765625e-01,  /* 0x3fc6c1d400000000 */
    1.81571602821350097656e-01,  /* 0x3fc73dbd00000000 */
    1.85347914695739746094e-01,  /* 0x3fc7b97b00000000 */
    1.89118742942810058594e-01,  /* 0x3fc8350b00000000 */
    1.92884206771850585938e-01,  /* 0x3fc8b06e00000000 */
    1.96644186973571777344e-01,  /* 0x3fc92ba300000000 */
    2.00398445129394531250e-01,  /* 0x3fc9a6a800000000 */
    2.04147100448608398438e-01,  /* 0x3fca217e00000000 */
    2.07889914512634277344e-01,  /* 0x3fca9c2300000000 */
    2.11626768112182617188e-01,  /* 0x3fcb169600000000 */
    2.15357661247253417969e-01,  /* 0x3fcb90d700000000 */
    2.19082474708557128906e-01,  /* 0x3fcc0ae500000000 */
    2.22801089286804199219e-01,  /* 0x3fcc84bf00000000 */
    2.26513504981994628906e-01,  /* 0x3fccfe6500000000 */
    2.30219483375549316406e-01,  /* 0x3fcd77d500000000 */
    2.33919143676757812500e-01,  /* 0x3fcdf11000000000 */
    2.37612247467041015625e-01,  /* 0x3fce6a1400000000 */
    2.41298794746398925781e-01,  /* 0x3fcee2e100000000 */
    2.44978547096252441406e-01,  /* 0x3fcf5b7500000000 */
    2.48651623725891113281e-01,  /* 0x3fcfd3d100000000 */
    2.52317905426025390625e-01,  /* 0x3fd025fa00000000 */
    2.55977153778076171875e-01,  /* 0x3fd061ee00000000 */
    2.59629487991333007812e-01,  /* 0x3fd09dc500000000 */
    2.63274669647216796875e-01,  /* 0x3fd0d97e00000000 */
    2.66912937164306640625e-01,  /* 0x3fd1151a00000000 */
    2.70543813705444335938e-01,  /* 0x3fd1509700000000 */
    2.74167299270629882812e-01,  /* 0x3fd18bf500000000 */
    2.77783632278442382812e-01,  /* 0x3fd1c73500000000 */
    2.81392335891723632812e-01,  /* 0x3fd2025500000000 */
    2.84993648529052734375e-01,  /* 0x3fd23d5600000000 */
    2.88587331771850585938e-01,  /* 0x3fd2783700000000 */
    2.92173147201538085938e-01,  /* 0x3fd2b2f700000000 */
    2.95751571655273437500e-01,  /* 0x3fd2ed9800000000 */
    2.99322128295898437500e-01,  /* 0x3fd3281800000000 */
    3.02884817123413085938e-01,  /* 0x3fd3627700000000 */
    3.06439399719238281250e-01,  /* 0x3fd39cb400000000 */
    3.09986352920532226562e-01,  /* 0x3fd3d6d100000000 */
    3.13524961471557617188e-01,  /* 0x3fd410cb00000000 */
    3.17055702209472656250e-01,  /* 0x3fd44aa400000000 */
    3.20578098297119140625e-01,  /* 0x3fd4845a00000000 */
    3.24092388153076171875e-01,  /* 0x3fd4bdee00000000 */
    3.27598333358764648438e-01,  /* 0x3fd4f75f00000000 */
    3.31095933914184570312e-01,  /* 0x3fd530ad00000000 */
    3.34585189819335937500e-01,  /* 0x3fd569d800000000 */
    3.38066101074218750000e-01,  /* 0x3fd5a2e000000000 */
    3.41538190841674804688e-01,  /* 0x3fd5dbc300000000 */
    3.45002174377441406250e-01,  /* 0x3fd6148400000000 */
    3.48457098007202148438e-01,  /* 0x3fd64d1f00000000 */
    3.51903676986694335938e-01,  /* 0x3fd6859700000000 */
    3.55341434478759765625e-01,  /* 0x3fd6bdea00000000 */
    3.58770608901977539062e-01,  /* 0x3fd6f61900000000 */
    3.62190723419189453125e-01,  /* 0x3fd72e2200000000 */
    3.65602254867553710938e-01,  /* 0x3fd7660700000000 */
    3.69004726409912109375e-01,  /* 0x3fd79dc600000000 */
    3.72398376464843750000e-01,  /* 0x3fd7d56000000000 */
    3.75782966613769531250e-01,  /* 0x3fd80cd400000000 */
    3.79158496856689453125e-01,  /* 0x3fd8442200000000 */
    3.82525205612182617188e-01,  /* 0x3fd87b4b00000000 */
    3.85882616043090820312e-01,  /* 0x3fd8b24d00000000 */
    3.89230966567993164062e-01,  /* 0x3fd8e92900000000 */
    3.92570018768310546875e-01,  /* 0x3fd91fde00000000 */
    3.95900011062622070312e-01,  /* 0x3fd9566d00000000 */
    3.99220705032348632812e-01,  /* 0x3fd98cd500000000 */
    4.02532100677490234375e-01,  /* 0x3fd9c31600000000 */
    4.05834197998046875000e-01,  /* 0x3fd9f93000000000 */
    4.09126996994018554688e-01,  /* 0x3fda2f2300000000 */
    4.12410259246826171875e-01,  /* 0x3fda64ee00000000 */
    4.15684223175048828125e-01,  /* 0x3fda9a9200000000 */
    4.18948888778686523438e-01,  /* 0x3fdad00f00000000 */
    4.22204017639160156250e-01,  /* 0x3fdb056400000000 */
    4.25449609756469726562e-01,  /* 0x3fdb3a9100000000 */
    4.28685665130615234375e-01,  /* 0x3fdb6f9600000000 */
    4.31912183761596679688e-01,  /* 0x3fdba47300000000 */
    4.35129165649414062500e-01,  /* 0x3fdbd92800000000 */
    4.38336372375488281250e-01,  /* 0x3fdc0db400000000 */
    4.41534280776977539062e-01,  /* 0x3fdc421900000000 */
    4.44722414016723632812e-01,  /* 0x3fdc765500000000 */
    4.47900772094726562500e-01,  /* 0x3fdcaa6800000000 */
    4.51069593429565429688e-01,  /* 0x3fdcde5300000000 */
    4.54228639602661132812e-01,  /* 0x3fdd121500000000 */
    4.57377910614013671875e-01,  /* 0x3fdd45ae00000000 */
    4.60517644882202148438e-01,  /* 0x3fdd791f00000000 */
    4.63647603988647460938e-01,  /* 0x3fddac6700000000 */
    4.66767549514770507812e-01,  /* 0x3fdddf8500000000 */
    4.69877958297729492188e-01,  /* 0x3fde127b00000000 */
    4.72978591918945312500e-01,  /* 0x3fde454800000000 */
    4.76069211959838867188e-01,  /* 0x3fde77eb00000000 */
    4.79150056838989257812e-01,  /* 0x3fdeaa6500000000 */
    4.82221126556396484375e-01,  /* 0x3fdedcb600000000 */
    4.85282421112060546875e-01,  /* 0x3fdf0ede00000000 */
    4.88333940505981445312e-01,  /* 0x3fdf40dd00000000 */
    4.91375446319580078125e-01,  /* 0x3fdf72b200000000 */
    4.94406938552856445312e-01,  /* 0x3fdfa45d00000000 */
    4.97428894042968750000e-01,  /* 0x3fdfd5e000000000 */
    5.00440597534179687500e-01,  /* 0x3fe0039c00000000 */
    5.03442764282226562500e-01,  /* 0x3fe01c3400000000 */
    5.06434917449951171875e-01,  /* 0x3fe034b700000000 */
    5.09417057037353515625e-01,  /* 0x3fe04d2500000000 */
    5.12389183044433593750e-01,  /* 0x3fe0657e00000000 */
    5.15351772308349609375e-01,  /* 0x3fe07dc300000000 */
    5.18304347991943359375e-01,  /* 0x3fe095f300000000 */
    5.21246910095214843750e-01,  /* 0x3fe0ae0e00000000 */
    5.24179458618164062500e-01,  /* 0x3fe0c61400000000 */
    5.27101993560791015625e-01,  /* 0x3fe0de0500000000 */
    5.30014991760253906250e-01,  /* 0x3fe0f5e200000000 */
    5.32917976379394531250e-01,  /* 0x3fe10daa00000000 */
    5.35810947418212890625e-01,  /* 0x3fe1255d00000000 */
    5.38693904876708984375e-01,  /* 0x3fe13cfb00000000 */
    5.41567325592041015625e-01,  /* 0x3fe1548500000000 */
    5.44430732727050781250e-01,  /* 0x3fe16bfa00000000 */
    5.47284126281738281250e-01,  /* 0x3fe1835a00000000 */
    5.50127506256103515625e-01,  /* 0x3fe19aa500000000 */
    5.52961349487304687500e-01,  /* 0x3fe1b1dc00000000 */
    5.55785179138183593750e-01,  /* 0x3fe1c8fe00000000 */
    5.58598995208740234375e-01,  /* 0x3fe1e00b00000000 */
    5.61403274536132812500e-01,  /* 0x3fe1f70400000000 */
    5.64197540283203125000e-01,  /* 0x3fe20de800000000 */
    5.66981792449951171875e-01,  /* 0x3fe224b700000000 */
    5.69756031036376953125e-01,  /* 0x3fe23b7100000000 */
    5.72520732879638671875e-01,  /* 0x3fe2521700000000 */
    5.75275897979736328125e-01,  /* 0x3fe268a900000000 */
    5.78021049499511718750e-01,  /* 0x3fe27f2600000000 */
    5.80756187438964843750e-01,  /* 0x3fe2958e00000000 */
    5.83481788635253906250e-01,  /* 0x3fe2abe200000000 */
    5.86197376251220703125e-01,  /* 0x3fe2c22100000000 */
    5.88903427124023437500e-01,  /* 0x3fe2d84c00000000 */
    5.91599464416503906250e-01,  /* 0x3fe2ee6200000000 */
    5.94285964965820312500e-01,  /* 0x3fe3046400000000 */
    5.96962928771972656250e-01,  /* 0x3fe31a5200000000 */
    5.99629878997802734375e-01,  /* 0x3fe3302b00000000 */
    6.02287292480468750000e-01,  /* 0x3fe345f000000000 */
    6.04934692382812500000e-01,  /* 0x3fe35ba000000000 */
    6.07573032379150390625e-01,  /* 0x3fe3713d00000000 */
    6.10201358795166015625e-01,  /* 0x3fe386c500000000 */
    6.12820148468017578125e-01,  /* 0x3fe39c3900000000 */
    6.15428924560546875000e-01,  /* 0x3fe3b19800000000 */
    6.18028640747070312500e-01,  /* 0x3fe3c6e400000000 */
    6.20618820190429687500e-01,  /* 0x3fe3dc1c00000000 */
    6.23198986053466796875e-01,  /* 0x3fe3f13f00000000 */
    6.25770092010498046875e-01,  /* 0x3fe4064f00000000 */
    6.28331184387207031250e-01,  /* 0x3fe41b4a00000000 */
    6.30883216857910156250e-01,  /* 0x3fe4303200000000 */
    6.33425712585449218750e-01,  /* 0x3fe4450600000000 */
    6.35958671569824218750e-01,  /* 0x3fe459c600000000 */
    6.38482093811035156250e-01,  /* 0x3fe46e7200000000 */
    6.40995979309082031250e-01,  /* 0x3fe4830a00000000 */
    6.43500804901123046875e-01,  /* 0x3fe4978f00000000 */
    6.45996093750000000000e-01,  /* 0x3fe4ac0000000000 */
    6.48482322692871093750e-01,  /* 0x3fe4c05e00000000 */
    6.50959014892578125000e-01,  /* 0x3fe4d4a800000000 */
    6.53426170349121093750e-01,  /* 0x3fe4e8de00000000 */
    6.55884265899658203125e-01,  /* 0x3fe4fd0100000000 */
    6.58332824707031250000e-01,  /* 0x3fe5111000000000 */
    6.60772323608398437500e-01,  /* 0x3fe5250c00000000 */
    6.63202762603759765625e-01,  /* 0x3fe538f500000000 */
    6.65623664855957031250e-01,  /* 0x3fe54cca00000000 */
    6.68035984039306640625e-01,  /* 0x3fe5608d00000000 */
    6.70438766479492187500e-01,  /* 0x3fe5743c00000000 */
    6.72832489013671875000e-01,  /* 0x3fe587d800000000 */
    6.75216674804687500000e-01,  /* 0x3fe59b6000000000 */
    6.77592277526855468750e-01,  /* 0x3fe5aed600000000 */
    6.79958820343017578125e-01,  /* 0x3fe5c23900000000 */
    6.82316303253173828125e-01,  /* 0x3fe5d58900000000 */
    6.84664726257324218750e-01,  /* 0x3fe5e8c600000000 */
    6.87004089355468750000e-01,  /* 0x3fe5fbf000000000 */
    6.89334869384765625000e-01,  /* 0x3fe60f0800000000 */
    6.91656589508056640625e-01,  /* 0x3fe6220d00000000 */
    6.93969249725341796875e-01,  /* 0x3fe634ff00000000 */
    6.96272850036621093750e-01,  /* 0x3fe647de00000000 */
    6.98567867279052734375e-01,  /* 0x3fe65aab00000000 */
    7.00854301452636718750e-01,  /* 0x3fe66d6600000000 */
    7.03131675720214843750e-01,  /* 0x3fe6800e00000000 */
    7.05400466918945312500e-01,  /* 0x3fe692a400000000 */
    7.07660198211669921875e-01,  /* 0x3fe6a52700000000 */
    7.09911346435546875000e-01,  /* 0x3fe6b79800000000 */
    7.12153911590576171875e-01,  /* 0x3fe6c9f700000000 */
    7.14387893676757812500e-01,  /* 0x3fe6dc4400000000 */
    7.16613292694091796875e-01,  /* 0x3fe6ee7f00000000 */
    7.18829631805419921875e-01,  /* 0x3fe700a700000000 */
    7.21037864685058593750e-01,  /* 0x3fe712be00000000 */
    7.23237514495849609375e-01,  /* 0x3fe724c300000000 */
    7.25428581237792968750e-01,  /* 0x3fe736b600000000 */
    7.27611064910888671875e-01,  /* 0x3fe7489700000000 */
    7.29785442352294921875e-01,  /* 0x3fe75a6700000000 */
    7.31950759887695312500e-01,  /* 0x3fe76c2400000000 */
    7.34108448028564453125e-01,  /* 0x3fe77dd100000000 */
    7.36257076263427734375e-01,  /* 0x3fe78f6b00000000 */
    7.38397598266601562500e-01,  /* 0x3fe7a0f400000000 */
    7.40530014038085937500e-01,  /* 0x3fe7b26c00000000 */
    7.42654323577880859375e-01,  /* 0x3fe7c3d300000000 */
    7.44770050048828125000e-01,  /* 0x3fe7d52800000000 */
    7.46877670288085937500e-01,  /* 0x3fe7e66c00000000 */
    7.48976707458496093750e-01,  /* 0x3fe7f79e00000000 */
    7.51068115234375000000e-01,  /* 0x3fe808c000000000 */
    7.53150939941406250000e-01,  /* 0x3fe819d000000000 */
    7.55226135253906250000e-01,  /* 0x3fe82ad000000000 */
    7.57292747497558593750e-01,  /* 0x3fe83bbe00000000 */
    7.59351730346679687500e-01,  /* 0x3fe84c9c00000000 */
    7.61402606964111328125e-01,  /* 0x3fe85d6900000000 */
    7.63445377349853515625e-01,  /* 0x3fe86e2500000000 */
    7.65480041503906250000e-01,  /* 0x3fe87ed000000000 */
    7.67507076263427734375e-01,  /* 0x3fe88f6b00000000 */
    7.69526004791259765625e-01,  /* 0x3fe89ff500000000 */
    7.71537303924560546875e-01,  /* 0x3fe8b06f00000000 */
    7.73540973663330078125e-01,  /* 0x3fe8c0d900000000 */
    7.75536537170410156250e-01,  /* 0x3fe8d13200000000 */
    7.77523994445800781250e-01,  /* 0x3fe8e17a00000000 */
    7.79504299163818359375e-01,  /* 0x3fe8f1b300000000 */
    7.81476497650146484375e-01,  /* 0x3fe901db00000000 */
    7.83441066741943359375e-01,  /* 0x3fe911f300000000 */
    7.85398006439208984375e-01}; /* 0x3fe921fb00000000 */

  static const double atan_jby256_tail[  241] = {
    2.13244638182005395671e-08,  /* 0x3e56e59fbd38db2c */
    3.89093864761712760656e-08,  /* 0x3e64e3aa54dedf96 */
    4.44780900009437454576e-08,  /* 0x3e67e105ab1bda88 */
    1.15344768460112754160e-08,  /* 0x3e48c5254d013fd0 */
    3.37271051945395312705e-09,  /* 0x3e2cf8ab3ad62670 */
    2.40857608736109859459e-08,  /* 0x3e59dca4bec80468 */
    1.85853810450623807768e-08,  /* 0x3e53f4b5ec98a8da */
    5.14358299969225078306e-08,  /* 0x3e6b9d49619d81fe */
    8.85023985412952486748e-09,  /* 0x3e43017887460934 */
    1.59425154214358432060e-08,  /* 0x3e511e3eca0b9944 */
    1.95139937737755753164e-08,  /* 0x3e54f3f73c5a332e */
    2.64909755273544319715e-08,  /* 0x3e5c71c8ae0e00a6 */
    4.43388037881231070144e-08,  /* 0x3e67cde0f86fbdc7 */
    2.14757072421821274557e-08,  /* 0x3e570f328c889c72 */
    2.61049792670754218852e-08,  /* 0x3e5c07ae9b994efe */
    7.81439350674466302231e-09,  /* 0x3e40c8021d7b1698 */
    3.60125207123751024094e-08,  /* 0x3e635585edb8cb22 */
    6.15276238179343767917e-08,  /* 0x3e70842567b30e96 */
    9.54387964641184285058e-08,  /* 0x3e799e811031472e */
    3.02789566851502754129e-08,  /* 0x3e6041821416bcee */
    1.16888650949870856331e-07,  /* 0x3e7f6086e4dc96f4 */
    1.07580956468653338863e-08,  /* 0x3e471a535c5f1b58 */
    8.33454265379535427653e-08,  /* 0x3e765f743fe63ca1 */
    1.10790279272629526068e-07,  /* 0x3e7dbd733472d014 */
    1.08394277896366207424e-07,  /* 0x3e7d18cc4d8b0d1d */
    9.22176086126841098800e-08,  /* 0x3e78c12553c8fb29 */
    7.90938592199048786990e-08,  /* 0x3e753b49e2e8f991 */
    8.66445407164293125637e-08,  /* 0x3e77422ae148c141 */
    1.40839973537092438671e-08,  /* 0x3e4e3ec269df56a8 */
    1.19070438507307600689e-07,  /* 0x3e7ff6754e7e0ac9 */
    6.40451663051716197071e-08,  /* 0x3e7131267b1b5aad */
    1.08338682076343674522e-07,  /* 0x3e7d14fa403a94bc */
    3.52999550187922736222e-08,  /* 0x3e62f396c089a3d8 */
    1.05983273930043077202e-07,  /* 0x3e7c731d78fa95bb */
    1.05486124078259553339e-07,  /* 0x3e7c50f385177399 */
    5.82167732281776477773e-08,  /* 0x3e6f41409c6f2c20 */
    1.08696483983403942633e-07,  /* 0x3e7d2d90c4c39ec0 */
    4.47335086122377542835e-08,  /* 0x3e680420696f2106 */
    1.26896287162615723528e-08,  /* 0x3e4b40327943a2e8 */
    4.06534471589151404531e-08,  /* 0x3e65d35e02f3d2a2 */
    3.84504846300557026690e-08,  /* 0x3e64a498288117b0 */
    3.60715006404807269080e-08,  /* 0x3e635da119afb324 */
    6.44725903165522722801e-08,  /* 0x3e714e85cdb9a908 */
    3.63749249976409461305e-08,  /* 0x3e638754e5547b9a */
    1.03901294413833913794e-07,  /* 0x3e7be40ae6ce3246 */
    6.25379756302167880580e-08,  /* 0x3e70c993b3bea7e7 */
    6.63984302368488828029e-08,  /* 0x3e71d2dd89ac3359 */
    3.21844598971548278059e-08,  /* 0x3e61476603332c46 */
    1.16030611712765830905e-07,  /* 0x3e7f25901bac55b7 */
    1.17464622142347730134e-07,  /* 0x3e7f881b7c826e28 */
    7.54604017965808996596e-08,  /* 0x3e7441996d698d20 */
    1.49234929356206556899e-07,  /* 0x3e8407ac521ea089 */
    1.41416924523217430259e-07,  /* 0x3e82fb0c6c4b1723 */
    2.13308065617483489011e-07,  /* 0x3e8ca135966a3e18 */
    5.04230937933302320146e-08,  /* 0x3e6b1218e4d646e4 */
    5.45874922281655519035e-08,  /* 0x3e6d4e72a350d288 */
    1.51849028914786868886e-07,  /* 0x3e84617e2f04c329 */
    3.09004308703769273010e-08,  /* 0x3e6096ec41e82650 */
    9.67574548184738317664e-08,  /* 0x3e79f91f25773e6e */
    4.02508285529322212824e-08,  /* 0x3e659c0820f1d674 */
    3.01222268096861091157e-08,  /* 0x3e602bf7a2df1064 */
    2.36189860670079288680e-07,  /* 0x3e8fb36bfc40508f */
    1.14095158111080887695e-07,  /* 0x3e7ea08f3f8dc892 */
    7.42349089746573467487e-08,  /* 0x3e73ed6254656a0e */
    5.12515583196230380184e-08,  /* 0x3e6b83f5e5e69c58 */
    2.19290391828763918102e-07,  /* 0x3e8d6ec2af768592 */
    3.83263512187553886471e-08,  /* 0x3e6493889a226f94 */
    1.61513486284090523855e-07,  /* 0x3e85ad8fa65279ba */
    5.09996743535589922261e-08,  /* 0x3e6b615784d45434 */
    1.23694037861246766534e-07,  /* 0x3e809a184368f145 */
    8.23367955351123783984e-08,  /* 0x3e761a2439b0d91c */
    1.07591766213053694014e-07,  /* 0x3e7ce1a65e39a978 */
    1.42789947524631815640e-07,  /* 0x3e832a39a93b6a66 */
    1.32347123024711878538e-07,  /* 0x3e81c3699af804e7 */
    2.17626067316598149229e-08,  /* 0x3e575e0f4e44ede8 */
    2.34454866923044288656e-07,  /* 0x3e8f77ced1a7a83b */
    2.82966370261766916053e-09,  /* 0x3e284e7f0cb1b500 */
    2.29300919890907632975e-07,  /* 0x3e8ec6b838b02dfe */
    1.48428270450261284915e-07,  /* 0x3e83ebf4dfbeda87 */
    1.87937408574313982512e-07,  /* 0x3e89397aed9cb475 */
    6.13685946813334055347e-08,  /* 0x3e707937bc239c54 */
    1.98585022733583817493e-07,  /* 0x3e8aa754553131b6 */
    7.68394131623752961662e-08,  /* 0x3e74a05d407c45dc */
    1.28119052312436745644e-07,  /* 0x3e8132231a206dd0 */
    7.02119104719236502733e-08,  /* 0x3e72d8ecfdd69c88 */
    9.87954793820636301943e-08,  /* 0x3e7a852c74218606 */
    1.72176752381034986217e-07,  /* 0x3e871bf2baeebb50 */
    1.12877225146169704119e-08,  /* 0x3e483d7db7491820 */
    5.33549829555851737993e-08,  /* 0x3e6ca50d92b6da14 */
    2.13833275710816521345e-08,  /* 0x3e56f5cde8530298 */
    1.16243518048290556393e-07,  /* 0x3e7f343198910740 */
    6.29926408369055877943e-08,  /* 0x3e70e8d241ccd80a */
    6.45429039328021963791e-08,  /* 0x3e71535ac619e6c8 */
    8.64001922814281933403e-08,  /* 0x3e77316041c36cd2 */
    9.50767572202325800240e-08,  /* 0x3e7985a000637d8e */
    5.80851497508121135975e-08,  /* 0x3e6f2f29858c0a68 */
    1.82350561135024766232e-07,  /* 0x3e8879847f96d909 */
    1.98948680587390608655e-07,  /* 0x3e8ab3d319e12e42 */
    7.83548663450197659846e-08,  /* 0x3e75088162dfc4c2 */
    3.04374234486798594427e-08,  /* 0x3e605749a1cd9d8c */
    2.76135725629797411787e-08,  /* 0x3e5da65c6c6b8618 */
    4.32610105454203065470e-08,  /* 0x3e6739bf7df1ad64 */
    5.17107515324127256994e-08,  /* 0x3e6bc31252aa3340 */
    2.82398327875841444660e-08,  /* 0x3e5e528191ad3aa8 */
    1.87482469524195595399e-07,  /* 0x3e8929d93df19f18 */
    2.97481891662714096139e-08,  /* 0x3e5ff11eb693a080 */
    9.94421570843584316402e-09,  /* 0x3e455ae3f145a3a0 */
    1.07056210730391848428e-07,  /* 0x3e7cbcd8c6c0ca82 */
    6.25589580466881163081e-08,  /* 0x3e70cb04d425d304 */
    9.56641013869464593803e-08,  /* 0x3e79adfcab5be678 */
    1.88056307148355440276e-07,  /* 0x3e893d90c5662508 */
    8.38850689379557880950e-08,  /* 0x3e768489bd35ff40 */
    5.01215865527674122924e-09,  /* 0x3e3586ed3da2b7e0 */
    1.74166095998522089762e-07,  /* 0x3e87604d2e850eee */
    9.96779574395363585849e-08,  /* 0x3e7ac1d12bfb53d8 */
    5.98432026368321460686e-09,  /* 0x3e39b3d468274740 */
    1.18362922366887577169e-07,  /* 0x3e7fc5d68d10e53c */
    1.86086833284154215946e-07,  /* 0x3e88f9e51884becb */
    1.97671457251348941011e-07,  /* 0x3e8a87f0869c06d1 */
    1.42447160717199237159e-07,  /* 0x3e831e7279f685fa */
    1.05504240785546574184e-08,  /* 0x3e46a8282f9719b0 */
    3.13335218371639189324e-08,  /* 0x3e60d2724a8a44e0 */
    1.96518418901914535399e-07,  /* 0x3e8a60524b11ad4e */
    2.17692035039173536059e-08,  /* 0x3e575fdf832750f0 */
    2.15613114426529981675e-07,  /* 0x3e8cf06902e4cd36 */
    5.68271098300441214948e-08,  /* 0x3e6e82422d4f6d10 */
    1.70331455823369124256e-08,  /* 0x3e524a091063e6c0 */
    9.17590028095709583247e-08,  /* 0x3e78a1a172dc6f38 */
    2.77266304112916566247e-07,  /* 0x3e929b6619f8a92d */
    9.37041937614656939690e-08,  /* 0x3e79274d9c1b70c8 */
    1.56116346368316796511e-08,  /* 0x3e50c34b1fbb7930 */
    4.13967433808382727413e-08,  /* 0x3e6639866c20eb50 */
    1.70164749185821616276e-07,  /* 0x3e86d6d0f6832e9e */
    4.01708788545600086008e-07,  /* 0x3e9af54def99f25e */
    2.59663539226050551563e-07,  /* 0x3e916cfc52a00262 */
    2.22007487655027469542e-07,  /* 0x3e8dcc1e83569c32 */
    2.90542250809644081369e-07,  /* 0x3e937f7a551ed425 */
    4.67720537666628903341e-07,  /* 0x3e9f6360adc98887 */
    2.79799803956772554802e-07,  /* 0x3e92c6ec8d35a2c1 */
    2.07344552327432547723e-07,  /* 0x3e8bd44df84cb036 */
    2.54705698692735196368e-07,  /* 0x3e9117cf826e310e */
    4.26848589539548450728e-07,  /* 0x3e9ca533f332cfc9 */
    2.52506723633552216197e-07,  /* 0x3e90f208509dbc2e */
    2.14684129933849704964e-07,  /* 0x3e8cd07d93c945de */
    3.20134822201596505431e-07,  /* 0x3e957bdfd67e6d72 */
    9.93537565749855712134e-08,  /* 0x3e7aab89c516c658 */
    3.70792944827917252327e-08,  /* 0x3e63e823b1a1b8a0 */
    1.41772749369083698972e-07,  /* 0x3e8307464a9d6d3c */
    4.22446601490198804306e-07,  /* 0x3e9c5993cd438843 */
    4.11818433724801511540e-07,  /* 0x3e9ba2fca02ab554 */
    1.19976381502605310519e-07,  /* 0x3e801a5b6983a268 */
    3.43703078571520905265e-08,  /* 0x3e6273d1b350efc8 */
    1.66128705555453270379e-07,  /* 0x3e864c238c37b0c6 */
    5.00499610023283006540e-08,  /* 0x3e6aded07370a300 */
    1.75105139941208062123e-07,  /* 0x3e878091197eb47e */
    7.70807146729030327334e-08,  /* 0x3e74b0f245e0dabc */
    2.45918607526895836121e-07,  /* 0x3e9080d9794e2eaf */
    2.18359020958626199345e-07,  /* 0x3e8d4ec242b60c76 */
    8.44342887976445333569e-09,  /* 0x3e4221d2f940caa0 */
    1.07506148687888629299e-07,  /* 0x3e7cdbc42b2bba5c */
    5.36544954316820904572e-08,  /* 0x3e6cce37bb440840 */
    3.39109101518396596341e-07,  /* 0x3e96c1d999cf1dd0 */
    2.60098720293920613340e-08,  /* 0x3e5bed8a07eb0870 */
    8.42678991664621455827e-08,  /* 0x3e769ed88f490e3c */
    5.36972237470183633197e-08,  /* 0x3e6cd41719b73ef0 */
    4.28192558171921681288e-07,  /* 0x3e9cbc4ac95b41b7 */
    2.71535491483955143294e-07,  /* 0x3e9238f1b890f5d7 */
    7.84094998145075780203e-08,  /* 0x3e750c4282259cc4 */
    3.43880599134117431863e-07,  /* 0x3e9713d2de87b3e2 */
    1.32878065060366481043e-07,  /* 0x3e81d5a7d2255276 */
    4.18046802627967629428e-07,  /* 0x3e9c0dfd48227ac1 */
    2.65042411765766019424e-07,  /* 0x3e91c964dab76753 */
    1.70383695347518643694e-07,  /* 0x3e86de56d5704496 */
    1.54096497259613515678e-07,  /* 0x3e84aeb71fd19968 */
    2.36543402412459813461e-07,  /* 0x3e8fbf91c57b1918 */
    4.38416350106876736790e-07,  /* 0x3e9d6bef7fbe5d9a */
    3.03892161339927775731e-07,  /* 0x3e9464d3dc249066 */
    3.31136771605664899240e-07,  /* 0x3e9638e2ec4d9073 */
    6.49494294526590682218e-08,  /* 0x3e716f4a7247ea7c */
    4.10423429887181345747e-09,  /* 0x3e31a0a740f1d440 */
    1.70831640869113847224e-07,  /* 0x3e86edbb0114a33c */
    1.10811512657909180966e-07,  /* 0x3e7dbee8bf1d513c */
    3.23677724749783611964e-07,  /* 0x3e95b8bdb0248f73 */
    3.55662734259192678528e-07,  /* 0x3e97de3d3f5eac64 */
    2.30102333489738219140e-07,  /* 0x3e8ee24187ae448a */
    4.47429004000738629714e-07,  /* 0x3e9e06c591ec5192 */
    7.78167135617329598659e-08,  /* 0x3e74e3861a332738 */
    9.90345291908535415737e-08,  /* 0x3e7a9599dcc2bfe4 */
    5.85800913143113728314e-08,  /* 0x3e6f732fbad43468 */
    4.57859062410871843857e-07,  /* 0x3e9eb9f573b727d9 */
    3.67993069723390929794e-07,  /* 0x3e98b212a2eb9897 */
    2.90836464322977276043e-07,  /* 0x3e9384884c167215 */
    2.51621574250131388318e-07,  /* 0x3e90e2d363020051 */
    2.75789824740652815545e-07,  /* 0x3e92820879fbd022 */
    3.88985776250314403593e-07,  /* 0x3e9a1ab9893e4b30 */
    1.40214080183768019611e-07,  /* 0x3e82d1b817a24478 */
    3.23451432223550478373e-08,  /* 0x3e615d7b8ded4878 */
    9.15979180730608444470e-08,  /* 0x3e78968f9db3a5e4 */
    3.44371402498640470421e-07,  /* 0x3e971c4171fe135f */
    3.40401897215059498077e-07,  /* 0x3e96d80f605d0d8c */
    1.06431813453707950243e-07,  /* 0x3e7c91f043691590 */
    1.46204238932338846248e-07,  /* 0x3e839f8a15fce2b2 */
    9.94610376972039046878e-09,  /* 0x3e455beda9d94b80 */
    2.01711528092681771039e-07,  /* 0x3e8b12c15d60949a */
    2.72027977986191568296e-07,  /* 0x3e924167b312bfe3 */
    2.48402602511693757964e-07,  /* 0x3e90ab8633070277 */
    1.58480011219249621715e-07,  /* 0x3e854554ebbc80ee */
    3.00372828113368713281e-08,  /* 0x3e60204aef5a4bb8 */
    3.67816204583541976394e-07,  /* 0x3e98af08c679cf2c */
    2.46169793032343824291e-07,  /* 0x3e90852a330ae6c8 */
    1.70080468270204253247e-07,  /* 0x3e86d3eb9ec32916 */
    1.67806717763872914315e-07,  /* 0x3e8685cb7fcbbafe */
    2.67715622006907942620e-07,  /* 0x3e91f751c1e0bd95 */
    2.14411342550299170574e-08,  /* 0x3e5705b1b0f72560 */
    4.11228221283669073277e-07,  /* 0x3e9b98d8d808ca92 */
    3.52311752396749662260e-08,  /* 0x3e62ea22c75cc980 */
    3.52718000397367821054e-07,  /* 0x3e97aba62bca0350 */
    4.38857387992911129814e-07,  /* 0x3e9d73833442278c */
    3.22574606753482540743e-07,  /* 0x3e95a5ca1fb18bf9 */
    3.28730371182804296828e-08,  /* 0x3e61a6092b6ecf28 */
    7.56672470607639279700e-08,  /* 0x3e744fd049aac104 */
    3.26750155316369681821e-09,  /* 0x3e2c114fd8df5180 */
    3.21724445362095284743e-07,  /* 0x3e95972f130feae5 */
    1.06639427371776571151e-07,  /* 0x3e7ca034a55fe198 */
    3.41020788139524715063e-07,  /* 0x3e96e2b149990227 */
    1.00582838631232552824e-07,  /* 0x3e7b00000294592c */
    3.68439433859276640065e-07,  /* 0x3e98b9bdc442620e */
    2.20403078342388012027e-07,  /* 0x3e8d94fdfabf3e4e */
    1.62841467098298142534e-07,  /* 0x3e85db30b145ad9a */
    2.25325348296680733838e-07,  /* 0x3e8e3e1eb95022b0 */
    4.37462238226421614339e-07,  /* 0x3e9d5b8b45442bd6 */
    3.52055880555040706500e-07,  /* 0x3e97a046231ecd2e */
    4.75614398494781776825e-07,  /* 0x3e9feafe3ef55232 */
    3.60998399033215317516e-07,  /* 0x3e9839e7bfd78267 */
    3.79292434611513945954e-08,  /* 0x3e645cf49d6fa900 */
    1.29859015528549300061e-08,  /* 0x3e4be3132b27f380 */
    3.15927546985474913188e-07,  /* 0x3e9533980bb84f9f */
    2.28533679887379668031e-08,  /* 0x3e5889e2ce3ba390 */
    1.17222541823553133877e-07,  /* 0x3e7f7778c3ad0cc8 */
    1.51991208405464415857e-07,  /* 0x3e846660cec4eba2 */
    1.56958239325240655564e-07}; /* 0x3e85110b4611a626 */

  /* Some constants and split constants. */

  static double pi = 3.1415926535897932e+00, /* 0x400921fb54442d18 */
             piby2 = 1.5707963267948966e+00, /* 0x3ff921fb54442d18 */
             piby4 = 7.8539816339744831e-01, /* 0x3fe921fb54442d18 */
       three_piby4 = 2.3561944901923449e+00, /* 0x4002d97c7f3321d2 */
           pi_head = 3.1415926218032836e+00, /* 0x400921fb50000000 */
           pi_tail = 3.1786509547056392e-08, /* 0x3e6110b4611a6263 */
        piby2_head = 1.5707963267948965e+00, /* 0x3ff921fb54442d18 */
        piby2_tail = 6.1232339957367660e-17; /* 0x3c91a62633145c07 */

  double u, v, vbyu, q1, q2, s, u1, vu1, u2, vu2, uu, c, r;
  unsigned int swap_vu, index, xzero, yzero, xnan, ynan, xinf, yinf;
  int m, xexp, yexp, diffexp;

  /* Find properties of arguments x and y. */

  unsigned long long ux, ui, aux, xneg, uy, auy, yneg;

  GET_BITS_DP64(x, ux);
  GET_BITS_DP64(y, uy);
  aux = ux & ~SIGNBIT_DP64;
  auy = uy & ~SIGNBIT_DP64;
  xexp = (int)((ux & EXPBITS_DP64) >> EXPSHIFTBITS_DP64);
  yexp = (int)((uy & EXPBITS_DP64) >> EXPSHIFTBITS_DP64);
  xneg = ux & SIGNBIT_DP64;
  yneg = uy & SIGNBIT_DP64;
  xzero = (aux == 0);
  yzero = (auy == 0);
  xnan = (aux > PINFBITPATT_DP64);
  ynan = (auy > PINFBITPATT_DP64);
  xinf = (aux == PINFBITPATT_DP64);
  yinf = (auy == PINFBITPATT_DP64);

  diffexp = yexp - xexp;

  /* Special cases */

  if (xnan)
#ifdef WINDOWS
    return handle_error("atan2", ux|0x0008000000000000, _DOMAIN, 0,
                        EDOM, x, y);
#else
    return x + x; /* Raise invalid if it's a signalling NaN */
#endif
  else if (ynan)
#ifdef WINDOWS
    return handle_error("atan2", uy|0x0008000000000000, _DOMAIN, 0,
                        EDOM, x, y);
#else
    return y + y; /* Raise invalid if it's a signalling NaN */
#endif
  else if (yzero)
    { /* Zero y gives +-0 for positive x
         and +-pi for negative x */
#ifndef WINDOWS
      if ((_LIB_VERSION == _SVID_) && xzero)
        /* Sigh - _SVID_ defines atan2(0,0) as a domain error */
        return retval_errno_edom(x, y);
      else
#endif
      if (xneg)
	{
	  if (yneg) return val_with_flags(-pi,AMD_F_INEXACT);
          else return val_with_flags(pi,AMD_F_INEXACT);
	}
      else return y;
    }
  else if (xzero)
    { /* Zero x gives +- pi/2
         depending on sign of y */
      if (yneg) return val_with_flags(-piby2,AMD_F_INEXACT);
      else val_with_flags(piby2,AMD_F_INEXACT);
    }

  /* Scale up both x and y if they are both below 1/4.
     This avoids any possible later denormalised arithmetic. */

  if ((xexp < 1021 && yexp < 1021))
    {
      scaleUpDouble1024(ux, &ux);
      scaleUpDouble1024(uy, &uy);
      PUT_BITS_DP64(ux, x);
      PUT_BITS_DP64(uy, y);
      xexp = (int)((ux & EXPBITS_DP64) >> EXPSHIFTBITS_DP64);
      yexp = (int)((uy & EXPBITS_DP64) >> EXPSHIFTBITS_DP64);
      diffexp = yexp - xexp;
    }

  if (diffexp > 56)
    { /* abs(y)/abs(x) > 2^56 => arctan(x/y)
         is insignificant compared to piby2 */
      if (yneg) return val_with_flags(-piby2,AMD_F_INEXACT);
      else return val_with_flags(piby2,AMD_F_INEXACT);
    }
  else if (diffexp < -28 && (!xneg))
    { /* x positive and dominant over y by a factor of 2^28.
         In this case atan(y/x) is y/x to machine accuracy. */

      if (diffexp < -1074) /* Result underflows */
        {
          if (yneg)
            return val_with_flags(-0.0,AMD_F_INEXACT | AMD_F_UNDERFLOW);
          else
            return val_with_flags(0.0,AMD_F_INEXACT | AMD_F_UNDERFLOW);
        }
      else
        {
          if (diffexp < -1022)
            {
              /* Result will likely be denormalized */
              y = scaleDouble_1(y, 100);
              y /= x;
              /* Now y is 2^100 times the true result. Scale it back down. */
              GET_BITS_DP64(y, uy);
	      scaleDownDouble(uy, 100, &uy);
              PUT_BITS_DP64(uy, y);
	      if ((uy & EXPBITS_DP64) == 0)
		return val_with_flags(y, AMD_F_INEXACT | AMD_F_UNDERFLOW);
	      else
		return y;
             }
          else
            return y / x;
        }
    }
  else if (diffexp < -56 && xneg)
    { /* abs(x)/abs(y) > 2^56 and x < 0 => arctan(y/x)
         is insignificant compared to pi */
    if (yneg) return val_with_flags(-pi,AMD_F_INEXACT);
    else return val_with_flags(pi,AMD_F_INEXACT);
    }
  else if (yinf && xinf)
    { /* If abs(x) and abs(y) are both infinity
         return +-pi/4 or +- 3pi/4 according to
         signs.  */
    if (xneg)
      {
      if (yneg) return val_with_flags(-three_piby4,AMD_F_INEXACT);
      else return val_with_flags(three_piby4,AMD_F_INEXACT);
      }
    else
      {
      if (yneg) return val_with_flags(-piby4,AMD_F_INEXACT);
      else return val_with_flags(piby4,AMD_F_INEXACT);
      }
    }

  /* General case: take absolute values of arguments */

  u = x; v = y;
  if (xneg) u = -x;
  if (yneg) v = -y;

  /* Swap u and v if necessary to obtain 0 < v < u. Compute v/u. */

  swap_vu = (u < v);
  if (swap_vu) { uu = u; u = v; v = uu; }
  vbyu = v/u;

  if (vbyu > 0.0625)
    { /* General values of v/u. Use a look-up
         table and series expansion. */

      index = (int)(256*vbyu + 0.5);
      q1 = atan_jby256_lead[index-16];
      q2 = atan_jby256_tail[index-16];
      c = index*1./256;
      GET_BITS_DP64(u, ui);
      m = (int)((ui & EXPBITS_DP64) >> EXPSHIFTBITS_DP64) - EXPBIAS_DP64;
      u = scaleDouble_2(u,-m);
      v = scaleDouble_2(v,-m);
      GET_BITS_DP64(u, ui);
      PUT_BITS_DP64(0xfffffffff8000000 & ui, u1); /* 26 leading bits of u */
      u2 = u - u1;

      r = ((v-c*u1)-c*u2)/(u+c*v);

      /* Polynomial approximation to atan(r) */

      s = r*r;
      q2 = q2 + r - r*(s * (0.33333333333224095522 - s*(0.19999918038989143496)));
    }
  else if (vbyu < 1.e-8)
    { /* v/u is small enough that atan(v/u) = v/u */
      q1 = 0.0;
      q2 = vbyu;
    }
  else  /* vbyu <= 0.0625 */
    {
      /* Small values of v/u. Use a series expansion
	 computed carefully to minimise cancellation */

      GET_BITS_DP64(u, ui);
      PUT_BITS_DP64(0xffffffff00000000 & ui, u1);
      GET_BITS_DP64(vbyu, ui);
      PUT_BITS_DP64(0xffffffff00000000 & ui, vu1);
      u2 = u - u1;
      vu2 = vbyu - vu1;

      q1 = 0.0;
      s  = vbyu*vbyu;
      q2 = vbyu +
	((((v - u1*vu1) - u2*vu1) - u*vu2)/u -
	 (vbyu*s*(0.33333333333333170500 -
		  s*(0.19999999999393223405 -
		     s*(0.14285713561807169030 -
			s*(0.11110736283514525407 -
			   s*(0.90029810285449784439E-01)))))));
    }

  /* Tidy-up according to which quadrant the arguments lie in */

  if (swap_vu) {q1 = piby2_head - q1; q2 = piby2_tail - q2;}
  if (xneg) {q1 = pi_head - q1; q2 = pi_tail - q2;}
  q1 = q1 + q2;

  if (yneg) q1 = - q1;

  return q1;
}
weak_alias (atan2, FN_PROTOTYPE(atan2))

