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
static const char *ng0 = "C:/Users/yx654/Desktop/ssex/mux6x32.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};



static int sp_select(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    t0 = 1;
    xsi_set_current_line(29, ng0);
    t3 = (t1 + 4120);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);

LAB2:    t6 = ((char*)((ng1)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 3, t6, 3);
    if (t7 == 1)
        goto LAB3;

LAB4:    t3 = ((char*)((ng2)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 3, t3, 3);
    if (t7 == 1)
        goto LAB5;

LAB6:    t3 = ((char*)((ng3)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 3, t3, 3);
    if (t7 == 1)
        goto LAB7;

LAB8:    t3 = ((char*)((ng4)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 3, t3, 3);
    if (t7 == 1)
        goto LAB9;

LAB10:    t3 = ((char*)((ng5)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 3, t3, 3);
    if (t7 == 1)
        goto LAB11;

LAB12:    t3 = ((char*)((ng6)));
    t7 = xsi_vlog_unsigned_case_compare(t5, 3, t3, 3);
    if (t7 == 1)
        goto LAB13;

LAB14:
LAB16:
LAB15:    xsi_set_current_line(36, ng0);
    t3 = (t1 + 3160);
    t4 = (t3 + 56U);
    t6 = *((char **)t4);
    t8 = (t1 + 3000);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 32);

LAB17:    t0 = 0;

LAB1:    return t0;
LAB3:    xsi_set_current_line(30, ng0);
    t8 = (t1 + 3160);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t1 + 3000);
    xsi_vlogvar_assign_value(t11, t10, 0, 0, 32);
    goto LAB17;

LAB5:    xsi_set_current_line(31, ng0);
    t4 = (t1 + 3320);
    t6 = (t4 + 56U);
    t8 = *((char **)t6);
    t9 = (t1 + 3000);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 32);
    goto LAB17;

LAB7:    xsi_set_current_line(32, ng0);
    t4 = (t1 + 3480);
    t6 = (t4 + 56U);
    t8 = *((char **)t6);
    t9 = (t1 + 3000);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 32);
    goto LAB17;

LAB9:    xsi_set_current_line(33, ng0);
    t4 = (t1 + 3640);
    t6 = (t4 + 56U);
    t8 = *((char **)t6);
    t9 = (t1 + 3000);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 32);
    goto LAB17;

LAB11:    xsi_set_current_line(34, ng0);
    t4 = (t1 + 3800);
    t6 = (t4 + 56U);
    t8 = *((char **)t6);
    t9 = (t1 + 3000);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 32);
    goto LAB17;

LAB13:    xsi_set_current_line(35, ng0);
    t4 = (t1 + 3960);
    t6 = (t4 + 56U);
    t8 = *((char **)t6);
    t9 = (t1 + 3000);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 32);
    goto LAB17;

}

static void Cont_39_0(char *t0)
{
    char t31[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;

LAB0:    t1 = (t0 + 5040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t0 + 1640U);
    t4 = *((char **)t2);
    t2 = (t0 + 1800U);
    t5 = *((char **)t2);
    t2 = (t0 + 1960U);
    t6 = *((char **)t2);
    t2 = (t0 + 2120U);
    t7 = *((char **)t2);
    t2 = (t0 + 2280U);
    t8 = *((char **)t2);
    t2 = (t0 + 2440U);
    t9 = *((char **)t2);
    t2 = (t0 + 4848);
    t10 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t10, 0, 0);
    t12 = (t0 + 3160);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 3320);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);
    t14 = (t0 + 3480);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 32);
    t15 = (t0 + 3640);
    xsi_vlogvar_assign_value(t15, t6, 0, 0, 32);
    t16 = (t0 + 3800);
    xsi_vlogvar_assign_value(t16, t7, 0, 0, 32);
    t17 = (t0 + 3960);
    xsi_vlogvar_assign_value(t17, t8, 0, 0, 32);
    t18 = (t0 + 4120);
    xsi_vlogvar_assign_value(t18, t9, 0, 0, 3);

LAB4:    t19 = (t0 + 4944);
    t20 = *((char **)t19);
    t21 = (t20 + 80U);
    t22 = *((char **)t21);
    t23 = (t22 + 272U);
    t24 = *((char **)t23);
    t25 = (t24 + 0U);
    t26 = *((char **)t25);
    t27 = ((int  (*)(char *, char *))t26)(t0, t20);
    if (t27 != 0)
        goto LAB6;

LAB5:    t20 = (t0 + 4944);
    t28 = *((char **)t20);
    t20 = (t0 + 3000);
    t29 = (t20 + 56U);
    t30 = *((char **)t29);
    memcpy(t31, t30, 8);
    t32 = (t0 + 848);
    t33 = (t0 + 4848);
    t34 = 0;
    xsi_delete_subprogram_invocation(t32, t28, t0, t33, t34);
    t35 = (t0 + 5440);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    memcpy(t39, t31, 8);
    xsi_driver_vfirst_trans(t35, 0, 31);
    t40 = (t0 + 5360);
    *((int *)t40) = 1;

LAB1:    return;
LAB6:    t19 = (t0 + 5040U);
    *((char **)t19) = &&LAB4;
    goto LAB1;

}


extern void work_m_00000000003984927494_0244682482_init()
{
	static char *pe[] = {(void *)Cont_39_0};
	static char *se[] = {(void *)sp_select};
	xsi_register_didat("work_m_00000000003984927494_0244682482", "isim/pipelinedcpu_tb_isim_beh.exe.sim/work/m_00000000003984927494_0244682482.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
