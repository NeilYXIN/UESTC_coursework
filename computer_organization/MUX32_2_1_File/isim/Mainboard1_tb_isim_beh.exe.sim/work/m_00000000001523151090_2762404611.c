/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/yx654/Desktop/MUX32_2_1_File/ALUop.v";



static void NetDecl_28_0(char *t0)
{
    char t4[8];
    char t12[8];
    char t15[8];
    char t40[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t13;
    char *t14;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    int t64;
    int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(28, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t13 = (t0 + 1208U);
    t14 = *((char **)t13);
    memset(t15, 0, 8);
    t13 = (t15 + 4);
    t16 = (t14 + 4);
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 0);
    t19 = (t18 & 1);
    *((unsigned int *)t15) = t19;
    t20 = *((unsigned int *)t16);
    t21 = (t20 >> 0);
    t22 = (t21 & 1);
    *((unsigned int *)t13) = t22;
    memset(t12, 0, 8);
    t23 = (t15 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t15);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t23) == 0)
        goto LAB4;

LAB6:    t29 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t29) = 1;

LAB7:    t30 = (t12 + 4);
    t31 = (t15 + 4);
    t32 = *((unsigned int *)t15);
    t33 = (~(t32));
    *((unsigned int *)t12) = t33;
    *((unsigned int *)t30) = 0;
    if (*((unsigned int *)t31) != 0)
        goto LAB9;

LAB8:    t38 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t38 & 1U);
    t39 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t39 & 1U);
    t41 = *((unsigned int *)t4);
    t42 = *((unsigned int *)t12);
    t43 = (t41 & t42);
    *((unsigned int *)t40) = t43;
    t44 = (t4 + 4);
    t45 = (t12 + 4);
    t46 = (t40 + 4);
    t47 = *((unsigned int *)t44);
    t48 = *((unsigned int *)t45);
    t49 = (t47 | t48);
    *((unsigned int *)t46) = t49;
    t50 = *((unsigned int *)t46);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB10;

LAB11:
LAB12:    t72 = (t0 + 3880);
    t73 = (t72 + 56U);
    t74 = *((char **)t73);
    t75 = (t74 + 56U);
    t76 = *((char **)t75);
    memset(t76, 0, 8);
    t77 = 1U;
    t78 = t77;
    t79 = (t40 + 4);
    t80 = *((unsigned int *)t40);
    t77 = (t77 & t80);
    t81 = *((unsigned int *)t79);
    t78 = (t78 & t81);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t83 | t77);
    t84 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t84 | t78);
    xsi_driver_vfirst_trans(t72, 0, 0U);
    t85 = (t0 + 3752);
    *((int *)t85) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB9:    t34 = *((unsigned int *)t12);
    t35 = *((unsigned int *)t31);
    *((unsigned int *)t12) = (t34 | t35);
    t36 = *((unsigned int *)t30);
    t37 = *((unsigned int *)t31);
    *((unsigned int *)t30) = (t36 | t37);
    goto LAB8;

LAB10:    t52 = *((unsigned int *)t40);
    t53 = *((unsigned int *)t46);
    *((unsigned int *)t40) = (t52 | t53);
    t54 = (t4 + 4);
    t55 = (t12 + 4);
    t56 = *((unsigned int *)t4);
    t57 = (~(t56));
    t58 = *((unsigned int *)t54);
    t59 = (~(t58));
    t60 = *((unsigned int *)t12);
    t61 = (~(t60));
    t62 = *((unsigned int *)t55);
    t63 = (~(t62));
    t64 = (t57 & t59);
    t65 = (t61 & t63);
    t66 = (~(t64));
    t67 = (~(t65));
    t68 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t68 & t66);
    t69 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t69 & t67);
    t70 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t70 & t66);
    t71 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t71 & t67);
    goto LAB12;

}

static void Cont_30_1(char *t0)
{
    char t4[8];
    char t6[8];
    char t33[8];
    char t41[8];
    char t75[8];
    char t85[8];
    char t93[8];
    char t125[8];
    char t153[8];
    char t187[8];
    char t195[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    int t65;
    int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    char *t107;
    char *t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    int t117;
    int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    char *t129;
    char *t130;
    char *t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    char *t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    char *t157;
    char *t158;
    char *t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    unsigned int t175;
    unsigned int t176;
    int t177;
    int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    unsigned int t184;
    char *t185;
    char *t186;
    char *t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t196;
    unsigned int t197;
    unsigned int t198;
    char *t199;
    char *t200;
    char *t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    int t218;
    unsigned int t219;
    unsigned int t220;
    unsigned int t221;
    unsigned int t222;
    char *t223;
    char *t224;
    char *t225;
    char *t226;
    char *t227;
    unsigned int t228;
    unsigned int t229;
    char *t230;
    unsigned int t231;
    unsigned int t232;
    char *t233;
    unsigned int t234;
    unsigned int t235;
    char *t236;

LAB0:    t1 = (t0 + 2936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 1048U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 2);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 2);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    memset(t4, 0, 8);
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t6);
    t18 = (t17 & t16);
    t19 = (t18 & 1U);
    if (t19 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t14) == 0)
        goto LAB4;

LAB6:    t20 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t20) = 1;

LAB7:    t21 = (t4 + 4);
    t22 = (t6 + 4);
    t23 = *((unsigned int *)t6);
    t24 = (~(t23));
    *((unsigned int *)t4) = t24;
    *((unsigned int *)t21) = 0;
    if (*((unsigned int *)t22) != 0)
        goto LAB9;

LAB8:    t29 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t29 & 1U);
    t30 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t30 & 1U);
    t31 = (t0 + 1048U);
    t32 = *((char **)t31);
    memset(t33, 0, 8);
    t31 = (t33 + 4);
    t34 = (t32 + 4);
    t35 = *((unsigned int *)t32);
    t36 = (t35 >> 1);
    t37 = (t36 & 1);
    *((unsigned int *)t33) = t37;
    t38 = *((unsigned int *)t34);
    t39 = (t38 >> 1);
    t40 = (t39 & 1);
    *((unsigned int *)t31) = t40;
    t42 = *((unsigned int *)t4);
    t43 = *((unsigned int *)t33);
    t44 = (t42 & t43);
    *((unsigned int *)t41) = t44;
    t45 = (t4 + 4);
    t46 = (t33 + 4);
    t47 = (t41 + 4);
    t48 = *((unsigned int *)t45);
    t49 = *((unsigned int *)t46);
    t50 = (t48 | t49);
    *((unsigned int *)t47) = t50;
    t51 = *((unsigned int *)t47);
    t52 = (t51 != 0);
    if (t52 == 1)
        goto LAB10;

LAB11:
LAB12:    t73 = (t0 + 1048U);
    t74 = *((char **)t73);
    memset(t75, 0, 8);
    t73 = (t75 + 4);
    t76 = (t74 + 4);
    t77 = *((unsigned int *)t74);
    t78 = (t77 >> 2);
    t79 = (t78 & 1);
    *((unsigned int *)t75) = t79;
    t80 = *((unsigned int *)t76);
    t81 = (t80 >> 2);
    t82 = (t81 & 1);
    *((unsigned int *)t73) = t82;
    t83 = (t0 + 1048U);
    t84 = *((char **)t83);
    memset(t85, 0, 8);
    t83 = (t85 + 4);
    t86 = (t84 + 4);
    t87 = *((unsigned int *)t84);
    t88 = (t87 >> 0);
    t89 = (t88 & 1);
    *((unsigned int *)t85) = t89;
    t90 = *((unsigned int *)t86);
    t91 = (t90 >> 0);
    t92 = (t91 & 1);
    *((unsigned int *)t83) = t92;
    t94 = *((unsigned int *)t75);
    t95 = *((unsigned int *)t85);
    t96 = (t94 & t95);
    *((unsigned int *)t93) = t96;
    t97 = (t75 + 4);
    t98 = (t85 + 4);
    t99 = (t93 + 4);
    t100 = *((unsigned int *)t97);
    t101 = *((unsigned int *)t98);
    t102 = (t100 | t101);
    *((unsigned int *)t99) = t102;
    t103 = *((unsigned int *)t99);
    t104 = (t103 != 0);
    if (t104 == 1)
        goto LAB13;

LAB14:
LAB15:    t126 = *((unsigned int *)t41);
    t127 = *((unsigned int *)t93);
    t128 = (t126 | t127);
    *((unsigned int *)t125) = t128;
    t129 = (t41 + 4);
    t130 = (t93 + 4);
    t131 = (t125 + 4);
    t132 = *((unsigned int *)t129);
    t133 = *((unsigned int *)t130);
    t134 = (t132 | t133);
    *((unsigned int *)t131) = t134;
    t135 = *((unsigned int *)t131);
    t136 = (t135 != 0);
    if (t136 == 1)
        goto LAB16;

LAB17:
LAB18:    t154 = *((unsigned int *)t3);
    t155 = *((unsigned int *)t125);
    t156 = (t154 & t155);
    *((unsigned int *)t153) = t156;
    t157 = (t3 + 4);
    t158 = (t125 + 4);
    t159 = (t153 + 4);
    t160 = *((unsigned int *)t157);
    t161 = *((unsigned int *)t158);
    t162 = (t160 | t161);
    *((unsigned int *)t159) = t162;
    t163 = *((unsigned int *)t159);
    t164 = (t163 != 0);
    if (t164 == 1)
        goto LAB19;

LAB20:
LAB21:    t185 = (t0 + 1208U);
    t186 = *((char **)t185);
    memset(t187, 0, 8);
    t185 = (t187 + 4);
    t188 = (t186 + 4);
    t189 = *((unsigned int *)t186);
    t190 = (t189 >> 0);
    t191 = (t190 & 1);
    *((unsigned int *)t187) = t191;
    t192 = *((unsigned int *)t188);
    t193 = (t192 >> 0);
    t194 = (t193 & 1);
    *((unsigned int *)t185) = t194;
    t196 = *((unsigned int *)t153);
    t197 = *((unsigned int *)t187);
    t198 = (t196 | t197);
    *((unsigned int *)t195) = t198;
    t199 = (t153 + 4);
    t200 = (t187 + 4);
    t201 = (t195 + 4);
    t202 = *((unsigned int *)t199);
    t203 = *((unsigned int *)t200);
    t204 = (t202 | t203);
    *((unsigned int *)t201) = t204;
    t205 = *((unsigned int *)t201);
    t206 = (t205 != 0);
    if (t206 == 1)
        goto LAB22;

LAB23:
LAB24:    t223 = (t0 + 3944);
    t224 = (t223 + 56U);
    t225 = *((char **)t224);
    t226 = (t225 + 56U);
    t227 = *((char **)t226);
    memset(t227, 0, 8);
    t228 = 1U;
    t229 = t228;
    t230 = (t195 + 4);
    t231 = *((unsigned int *)t195);
    t228 = (t228 & t231);
    t232 = *((unsigned int *)t230);
    t229 = (t229 & t232);
    t233 = (t227 + 4);
    t234 = *((unsigned int *)t227);
    *((unsigned int *)t227) = (t234 | t228);
    t235 = *((unsigned int *)t233);
    *((unsigned int *)t233) = (t235 | t229);
    xsi_driver_vfirst_trans(t223, 2, 2);
    t236 = (t0 + 3768);
    *((int *)t236) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB9:    t25 = *((unsigned int *)t4);
    t26 = *((unsigned int *)t22);
    *((unsigned int *)t4) = (t25 | t26);
    t27 = *((unsigned int *)t21);
    t28 = *((unsigned int *)t22);
    *((unsigned int *)t21) = (t27 | t28);
    goto LAB8;

LAB10:    t53 = *((unsigned int *)t41);
    t54 = *((unsigned int *)t47);
    *((unsigned int *)t41) = (t53 | t54);
    t55 = (t4 + 4);
    t56 = (t33 + 4);
    t57 = *((unsigned int *)t4);
    t58 = (~(t57));
    t59 = *((unsigned int *)t55);
    t60 = (~(t59));
    t61 = *((unsigned int *)t33);
    t62 = (~(t61));
    t63 = *((unsigned int *)t56);
    t64 = (~(t63));
    t65 = (t58 & t60);
    t66 = (t62 & t64);
    t67 = (~(t65));
    t68 = (~(t66));
    t69 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t69 & t67);
    t70 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t70 & t68);
    t71 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t71 & t67);
    t72 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t72 & t68);
    goto LAB12;

LAB13:    t105 = *((unsigned int *)t93);
    t106 = *((unsigned int *)t99);
    *((unsigned int *)t93) = (t105 | t106);
    t107 = (t75 + 4);
    t108 = (t85 + 4);
    t109 = *((unsigned int *)t75);
    t110 = (~(t109));
    t111 = *((unsigned int *)t107);
    t112 = (~(t111));
    t113 = *((unsigned int *)t85);
    t114 = (~(t113));
    t115 = *((unsigned int *)t108);
    t116 = (~(t115));
    t117 = (t110 & t112);
    t118 = (t114 & t116);
    t119 = (~(t117));
    t120 = (~(t118));
    t121 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t121 & t119);
    t122 = *((unsigned int *)t99);
    *((unsigned int *)t99) = (t122 & t120);
    t123 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t123 & t119);
    t124 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t124 & t120);
    goto LAB15;

LAB16:    t137 = *((unsigned int *)t125);
    t138 = *((unsigned int *)t131);
    *((unsigned int *)t125) = (t137 | t138);
    t139 = (t41 + 4);
    t140 = (t93 + 4);
    t141 = *((unsigned int *)t139);
    t142 = (~(t141));
    t143 = *((unsigned int *)t41);
    t144 = (t143 & t142);
    t145 = *((unsigned int *)t140);
    t146 = (~(t145));
    t147 = *((unsigned int *)t93);
    t148 = (t147 & t146);
    t149 = (~(t144));
    t150 = (~(t148));
    t151 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t151 & t149);
    t152 = *((unsigned int *)t131);
    *((unsigned int *)t131) = (t152 & t150);
    goto LAB18;

LAB19:    t165 = *((unsigned int *)t153);
    t166 = *((unsigned int *)t159);
    *((unsigned int *)t153) = (t165 | t166);
    t167 = (t3 + 4);
    t168 = (t125 + 4);
    t169 = *((unsigned int *)t3);
    t170 = (~(t169));
    t171 = *((unsigned int *)t167);
    t172 = (~(t171));
    t173 = *((unsigned int *)t125);
    t174 = (~(t173));
    t175 = *((unsigned int *)t168);
    t176 = (~(t175));
    t177 = (t170 & t172);
    t178 = (t174 & t176);
    t179 = (~(t177));
    t180 = (~(t178));
    t181 = *((unsigned int *)t159);
    *((unsigned int *)t159) = (t181 & t179);
    t182 = *((unsigned int *)t159);
    *((unsigned int *)t159) = (t182 & t180);
    t183 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t183 & t179);
    t184 = *((unsigned int *)t153);
    *((unsigned int *)t153) = (t184 & t180);
    goto LAB21;

LAB22:    t207 = *((unsigned int *)t195);
    t208 = *((unsigned int *)t201);
    *((unsigned int *)t195) = (t207 | t208);
    t209 = (t153 + 4);
    t210 = (t187 + 4);
    t211 = *((unsigned int *)t209);
    t212 = (~(t211));
    t213 = *((unsigned int *)t153);
    t214 = (t213 & t212);
    t215 = *((unsigned int *)t210);
    t216 = (~(t215));
    t217 = *((unsigned int *)t187);
    t218 = (t217 & t216);
    t219 = (~(t214));
    t220 = (~(t218));
    t221 = *((unsigned int *)t201);
    *((unsigned int *)t201) = (t221 & t219);
    t222 = *((unsigned int *)t201);
    *((unsigned int *)t201) = (t222 & t220);
    goto LAB24;

}

static void Cont_31_2(char *t0)
{
    char t5[8];
    char t13[8];
    char t47[8];
    char t55[8];
    char t89[8];
    char t99[8];
    char t107[8];
    char t139[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    int t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    char *t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    char *t111;
    char *t112;
    char *t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    int t131;
    int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    char *t143;
    char *t144;
    char *t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t153;
    char *t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    char *t167;
    char *t168;
    char *t169;
    char *t170;
    char *t171;
    unsigned int t172;
    unsigned int t173;
    char *t174;
    unsigned int t175;
    unsigned int t176;
    char *t177;
    unsigned int t178;
    unsigned int t179;
    char *t180;

LAB0:    t1 = (t0 + 3184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 1048U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t5);
    t16 = (t14 & t15);
    *((unsigned int *)t13) = t16;
    t17 = (t3 + 4);
    t18 = (t5 + 4);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t17);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    *((unsigned int *)t19) = t22;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB4;

LAB5:
LAB6:    t45 = (t0 + 1048U);
    t46 = *((char **)t45);
    memset(t47, 0, 8);
    t45 = (t47 + 4);
    t48 = (t46 + 4);
    t49 = *((unsigned int *)t46);
    t50 = (t49 >> 1);
    t51 = (t50 & 1);
    *((unsigned int *)t47) = t51;
    t52 = *((unsigned int *)t48);
    t53 = (t52 >> 1);
    t54 = (t53 & 1);
    *((unsigned int *)t45) = t54;
    t56 = *((unsigned int *)t13);
    t57 = *((unsigned int *)t47);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t59 = (t13 + 4);
    t60 = (t47 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB7;

LAB8:
LAB9:    t87 = (t0 + 1208U);
    t88 = *((char **)t87);
    memset(t89, 0, 8);
    t87 = (t89 + 4);
    t90 = (t88 + 4);
    t91 = *((unsigned int *)t88);
    t92 = (t91 >> 1);
    t93 = (t92 & 1);
    *((unsigned int *)t89) = t93;
    t94 = *((unsigned int *)t90);
    t95 = (t94 >> 1);
    t96 = (t95 & 1);
    *((unsigned int *)t87) = t96;
    t97 = (t0 + 1208U);
    t98 = *((char **)t97);
    memset(t99, 0, 8);
    t97 = (t99 + 4);
    t100 = (t98 + 4);
    t101 = *((unsigned int *)t98);
    t102 = (t101 >> 0);
    t103 = (t102 & 1);
    *((unsigned int *)t99) = t103;
    t104 = *((unsigned int *)t100);
    t105 = (t104 >> 0);
    t106 = (t105 & 1);
    *((unsigned int *)t97) = t106;
    t108 = *((unsigned int *)t89);
    t109 = *((unsigned int *)t99);
    t110 = (t108 & t109);
    *((unsigned int *)t107) = t110;
    t111 = (t89 + 4);
    t112 = (t99 + 4);
    t113 = (t107 + 4);
    t114 = *((unsigned int *)t111);
    t115 = *((unsigned int *)t112);
    t116 = (t114 | t115);
    *((unsigned int *)t113) = t116;
    t117 = *((unsigned int *)t113);
    t118 = (t117 != 0);
    if (t118 == 1)
        goto LAB10;

LAB11:
LAB12:    t140 = *((unsigned int *)t55);
    t141 = *((unsigned int *)t107);
    t142 = (t140 | t141);
    *((unsigned int *)t139) = t142;
    t143 = (t55 + 4);
    t144 = (t107 + 4);
    t145 = (t139 + 4);
    t146 = *((unsigned int *)t143);
    t147 = *((unsigned int *)t144);
    t148 = (t146 | t147);
    *((unsigned int *)t145) = t148;
    t149 = *((unsigned int *)t145);
    t150 = (t149 != 0);
    if (t150 == 1)
        goto LAB13;

LAB14:
LAB15:    t167 = (t0 + 4008);
    t168 = (t167 + 56U);
    t169 = *((char **)t168);
    t170 = (t169 + 56U);
    t171 = *((char **)t170);
    memset(t171, 0, 8);
    t172 = 1U;
    t173 = t172;
    t174 = (t139 + 4);
    t175 = *((unsigned int *)t139);
    t172 = (t172 & t175);
    t176 = *((unsigned int *)t174);
    t173 = (t173 & t176);
    t177 = (t171 + 4);
    t178 = *((unsigned int *)t171);
    *((unsigned int *)t171) = (t178 | t172);
    t179 = *((unsigned int *)t177);
    *((unsigned int *)t177) = (t179 | t173);
    xsi_driver_vfirst_trans(t167, 1, 1);
    t180 = (t0 + 3784);
    *((int *)t180) = 1;

LAB1:    return;
LAB4:    t25 = *((unsigned int *)t13);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t13) = (t25 | t26);
    t27 = (t3 + 4);
    t28 = (t5 + 4);
    t29 = *((unsigned int *)t3);
    t30 = (~(t29));
    t31 = *((unsigned int *)t27);
    t32 = (~(t31));
    t33 = *((unsigned int *)t5);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (~(t35));
    t37 = (t30 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t41 & t39);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & t40);
    t43 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t43 & t39);
    t44 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t44 & t40);
    goto LAB6;

LAB7:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t13 + 4);
    t70 = (t47 + 4);
    t71 = *((unsigned int *)t13);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (~(t73));
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (~(t77));
    t79 = (t72 & t74);
    t80 = (t76 & t78);
    t81 = (~(t79));
    t82 = (~(t80));
    t83 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t83 & t81);
    t84 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t84 & t82);
    t85 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t85 & t81);
    t86 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t86 & t82);
    goto LAB9;

LAB10:    t119 = *((unsigned int *)t107);
    t120 = *((unsigned int *)t113);
    *((unsigned int *)t107) = (t119 | t120);
    t121 = (t89 + 4);
    t122 = (t99 + 4);
    t123 = *((unsigned int *)t89);
    t124 = (~(t123));
    t125 = *((unsigned int *)t121);
    t126 = (~(t125));
    t127 = *((unsigned int *)t99);
    t128 = (~(t127));
    t129 = *((unsigned int *)t122);
    t130 = (~(t129));
    t131 = (t124 & t126);
    t132 = (t128 & t130);
    t133 = (~(t131));
    t134 = (~(t132));
    t135 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t135 & t133);
    t136 = *((unsigned int *)t113);
    *((unsigned int *)t113) = (t136 & t134);
    t137 = *((unsigned int *)t107);
    *((unsigned int *)t107) = (t137 & t133);
    t138 = *((unsigned int *)t107);
    *((unsigned int *)t107) = (t138 & t134);
    goto LAB12;

LAB13:    t151 = *((unsigned int *)t139);
    t152 = *((unsigned int *)t145);
    *((unsigned int *)t139) = (t151 | t152);
    t153 = (t55 + 4);
    t154 = (t107 + 4);
    t155 = *((unsigned int *)t153);
    t156 = (~(t155));
    t157 = *((unsigned int *)t55);
    t158 = (t157 & t156);
    t159 = *((unsigned int *)t154);
    t160 = (~(t159));
    t161 = *((unsigned int *)t107);
    t162 = (t161 & t160);
    t163 = (~(t158));
    t164 = (~(t162));
    t165 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t165 & t163);
    t166 = *((unsigned int *)t145);
    *((unsigned int *)t145) = (t166 & t164);
    goto LAB15;

}

static void Cont_32_3(char *t0)
{
    char t5[8];
    char t13[8];
    char t45[8];
    char t48[8];
    char t73[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t46;
    char *t47;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    char *t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    int t97;
    int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    unsigned int t110;
    unsigned int t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;

LAB0:    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 1048U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t14 = *((unsigned int *)t3);
    t15 = *((unsigned int *)t5);
    t16 = (t14 & t15);
    *((unsigned int *)t13) = t16;
    t17 = (t3 + 4);
    t18 = (t5 + 4);
    t19 = (t13 + 4);
    t20 = *((unsigned int *)t17);
    t21 = *((unsigned int *)t18);
    t22 = (t20 | t21);
    *((unsigned int *)t19) = t22;
    t23 = *((unsigned int *)t19);
    t24 = (t23 != 0);
    if (t24 == 1)
        goto LAB4;

LAB5:
LAB6:    t46 = (t0 + 1048U);
    t47 = *((char **)t46);
    memset(t48, 0, 8);
    t46 = (t48 + 4);
    t49 = (t47 + 4);
    t50 = *((unsigned int *)t47);
    t51 = (t50 >> 1);
    t52 = (t51 & 1);
    *((unsigned int *)t48) = t52;
    t53 = *((unsigned int *)t49);
    t54 = (t53 >> 1);
    t55 = (t54 & 1);
    *((unsigned int *)t46) = t55;
    memset(t45, 0, 8);
    t56 = (t48 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t48);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB10;

LAB8:    if (*((unsigned int *)t56) == 0)
        goto LAB7;

LAB9:    t62 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t62) = 1;

LAB10:    t63 = (t45 + 4);
    t64 = (t48 + 4);
    t65 = *((unsigned int *)t48);
    t66 = (~(t65));
    *((unsigned int *)t45) = t66;
    *((unsigned int *)t63) = 0;
    if (*((unsigned int *)t64) != 0)
        goto LAB12;

LAB11:    t71 = *((unsigned int *)t45);
    *((unsigned int *)t45) = (t71 & 1U);
    t72 = *((unsigned int *)t63);
    *((unsigned int *)t63) = (t72 & 1U);
    t74 = *((unsigned int *)t13);
    t75 = *((unsigned int *)t45);
    t76 = (t74 & t75);
    *((unsigned int *)t73) = t76;
    t77 = (t13 + 4);
    t78 = (t45 + 4);
    t79 = (t73 + 4);
    t80 = *((unsigned int *)t77);
    t81 = *((unsigned int *)t78);
    t82 = (t80 | t81);
    *((unsigned int *)t79) = t82;
    t83 = *((unsigned int *)t79);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB13;

LAB14:
LAB15:    t105 = (t0 + 4072);
    t106 = (t105 + 56U);
    t107 = *((char **)t106);
    t108 = (t107 + 56U);
    t109 = *((char **)t108);
    memset(t109, 0, 8);
    t110 = 1U;
    t111 = t110;
    t112 = (t73 + 4);
    t113 = *((unsigned int *)t73);
    t110 = (t110 & t113);
    t114 = *((unsigned int *)t112);
    t111 = (t111 & t114);
    t115 = (t109 + 4);
    t116 = *((unsigned int *)t109);
    *((unsigned int *)t109) = (t116 | t110);
    t117 = *((unsigned int *)t115);
    *((unsigned int *)t115) = (t117 | t111);
    xsi_driver_vfirst_trans(t105, 0, 0);
    t118 = (t0 + 3800);
    *((int *)t118) = 1;

LAB1:    return;
LAB4:    t25 = *((unsigned int *)t13);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t13) = (t25 | t26);
    t27 = (t3 + 4);
    t28 = (t5 + 4);
    t29 = *((unsigned int *)t3);
    t30 = (~(t29));
    t31 = *((unsigned int *)t27);
    t32 = (~(t31));
    t33 = *((unsigned int *)t5);
    t34 = (~(t33));
    t35 = *((unsigned int *)t28);
    t36 = (~(t35));
    t37 = (t30 & t32);
    t38 = (t34 & t36);
    t39 = (~(t37));
    t40 = (~(t38));
    t41 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t41 & t39);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & t40);
    t43 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t43 & t39);
    t44 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t44 & t40);
    goto LAB6;

LAB7:    *((unsigned int *)t45) = 1;
    goto LAB10;

LAB12:    t67 = *((unsigned int *)t45);
    t68 = *((unsigned int *)t64);
    *((unsigned int *)t45) = (t67 | t68);
    t69 = *((unsigned int *)t63);
    t70 = *((unsigned int *)t64);
    *((unsigned int *)t63) = (t69 | t70);
    goto LAB11;

LAB13:    t85 = *((unsigned int *)t73);
    t86 = *((unsigned int *)t79);
    *((unsigned int *)t73) = (t85 | t86);
    t87 = (t13 + 4);
    t88 = (t45 + 4);
    t89 = *((unsigned int *)t13);
    t90 = (~(t89));
    t91 = *((unsigned int *)t87);
    t92 = (~(t91));
    t93 = *((unsigned int *)t45);
    t94 = (~(t93));
    t95 = *((unsigned int *)t88);
    t96 = (~(t95));
    t97 = (t90 & t92);
    t98 = (t94 & t96);
    t99 = (~(t97));
    t100 = (~(t98));
    t101 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t101 & t99);
    t102 = *((unsigned int *)t79);
    *((unsigned int *)t79) = (t102 & t100);
    t103 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t103 & t99);
    t104 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t104 & t100);
    goto LAB15;

}


extern void work_m_00000000001523151090_2762404611_init()
{
	static char *pe[] = {(void *)NetDecl_28_0,(void *)Cont_30_1,(void *)Cont_31_2,(void *)Cont_32_3};
	xsi_register_didat("work_m_00000000001523151090_2762404611", "isim/Mainboard1_tb_isim_beh.exe.sim/work/m_00000000001523151090_2762404611.didat");
	xsi_register_executes(pe);
}
