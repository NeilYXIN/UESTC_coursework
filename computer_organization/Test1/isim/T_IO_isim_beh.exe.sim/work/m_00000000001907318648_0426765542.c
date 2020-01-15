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

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/CPU_Test/Test1/Hex7seg_decode.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {32U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {16U, 0U};
static unsigned int ng6[] = {3U, 0U};
static unsigned int ng7[] = {8U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {5U, 0U};
static unsigned int ng10[] = {63U, 0U};
static unsigned int ng11[] = {6U, 0U};
static unsigned int ng12[] = {91U, 0U};
static unsigned int ng13[] = {79U, 0U};
static unsigned int ng14[] = {102U, 0U};
static unsigned int ng15[] = {109U, 0U};
static unsigned int ng16[] = {125U, 0U};
static unsigned int ng17[] = {7U, 0U};
static unsigned int ng18[] = {127U, 0U};
static unsigned int ng19[] = {9U, 0U};
static unsigned int ng20[] = {111U, 0U};
static unsigned int ng21[] = {10U, 0U};
static unsigned int ng22[] = {119U, 0U};
static unsigned int ng23[] = {11U, 0U};
static unsigned int ng24[] = {124U, 0U};
static unsigned int ng25[] = {12U, 0U};
static unsigned int ng26[] = {57U, 0U};
static unsigned int ng27[] = {13U, 0U};
static unsigned int ng28[] = {94U, 0U};
static unsigned int ng29[] = {14U, 0U};
static unsigned int ng30[] = {121U, 0U};
static unsigned int ng31[] = {15U, 0U};
static unsigned int ng32[] = {113U, 0U};



static void Cont_31_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 1720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 2264);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 7);
    t18 = (t0 + 2204);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_33_1(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;

LAB0:    t1 = (t0 + 1864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 2212);
    *((int *)t2) = 1;
    t3 = (t0 + 1892);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng0);

LAB5:    xsi_set_current_line(34, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1012);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 6);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 692U);
    t3 = *((char **)t2);

LAB6:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t3, 3, t2, 3);
    if (t6 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB2;

LAB7:    xsi_set_current_line(36, ng0);

LAB20:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t7 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 0);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 15U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 15U);
    t15 = (t0 + 1104);
    xsi_vlogvar_assign_value(t15, t7, 0, 0, 4);
    xsi_set_current_line(36, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 6);
    goto LAB19;

LAB9:    xsi_set_current_line(37, ng0);

LAB21:    xsi_set_current_line(37, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t7 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 4);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 4);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 15U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 15U);
    t15 = (t0 + 1104);
    xsi_vlogvar_assign_value(t15, t7, 0, 0, 4);
    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 6);
    goto LAB19;

LAB11:    xsi_set_current_line(38, ng0);

LAB22:    xsi_set_current_line(38, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t7 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 8);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 8);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 15U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 15U);
    t15 = (t0 + 1104);
    xsi_vlogvar_assign_value(t15, t7, 0, 0, 4);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng5)));
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 6);
    goto LAB19;

LAB13:    xsi_set_current_line(39, ng0);

LAB23:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t7 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 12);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 12);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 15U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 15U);
    t15 = (t0 + 1104);
    xsi_vlogvar_assign_value(t15, t7, 0, 0, 4);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng7)));
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 6);
    goto LAB19;

LAB15:    xsi_set_current_line(40, ng0);

LAB24:    xsi_set_current_line(40, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t7 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 16);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 16);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 15U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 15U);
    t15 = (t0 + 1104);
    xsi_vlogvar_assign_value(t15, t7, 0, 0, 4);
    xsi_set_current_line(40, ng0);
    t2 = ((char*)((ng8)));
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 6);
    goto LAB19;

LAB17:    xsi_set_current_line(41, ng0);

LAB25:    xsi_set_current_line(41, ng0);
    t4 = (t0 + 600U);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t7 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 20);
    *((unsigned int *)t7) = t10;
    t11 = *((unsigned int *)t8);
    t12 = (t11 >> 20);
    *((unsigned int *)t4) = t12;
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t13 & 15U);
    t14 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t14 & 15U);
    t15 = (t0 + 1104);
    xsi_vlogvar_assign_value(t15, t7, 0, 0, 4);
    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng4)));
    t4 = (t0 + 1012);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 6);
    goto LAB19;

}

static void Always_45_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 2008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 2220);
    *((int *)t2) = 1;
    t3 = (t0 + 2036);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(45, ng0);

LAB5:    xsi_set_current_line(46, ng0);
    t4 = (t0 + 1104);
    t5 = (t4 + 36U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng1)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t7, 4);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng6)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng8)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng9)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng11)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng17)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng7)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng19)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng21)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng23)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng25)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng27)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng29)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng31)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 4, t2, 4);
    if (t8 == 1)
        goto LAB37;

LAB38:
LAB39:    goto LAB2;

LAB7:    xsi_set_current_line(47, ng0);
    t9 = ((char*)((ng10)));
    t10 = (t0 + 1196);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 8);
    goto LAB39;

LAB9:    xsi_set_current_line(48, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB11:    xsi_set_current_line(49, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB13:    xsi_set_current_line(50, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB15:    xsi_set_current_line(51, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB17:    xsi_set_current_line(52, ng0);
    t3 = ((char*)((ng15)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB19:    xsi_set_current_line(53, ng0);
    t3 = ((char*)((ng16)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB21:    xsi_set_current_line(54, ng0);
    t3 = ((char*)((ng17)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB23:    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng18)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB25:    xsi_set_current_line(56, ng0);
    t3 = ((char*)((ng20)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB27:    xsi_set_current_line(57, ng0);
    t3 = ((char*)((ng22)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB29:    xsi_set_current_line(58, ng0);
    t3 = ((char*)((ng24)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB31:    xsi_set_current_line(59, ng0);
    t3 = ((char*)((ng26)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB33:    xsi_set_current_line(60, ng0);
    t3 = ((char*)((ng28)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB35:    xsi_set_current_line(61, ng0);
    t3 = ((char*)((ng30)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

LAB37:    xsi_set_current_line(62, ng0);
    t3 = ((char*)((ng32)));
    t4 = (t0 + 1196);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 8);
    goto LAB39;

}


extern void work_m_00000000001907318648_0426765542_init()
{
	static char *pe[] = {(void *)Cont_31_0,(void *)Always_33_1,(void *)Always_45_2};
	xsi_register_didat("work_m_00000000001907318648_0426765542", "isim/T_IO_isim_beh.exe.sim/work/m_00000000001907318648_0426765542.didat");
	xsi_register_executes(pe);
}
