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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000003775170419_2009983731_init();
    work_m_00000000001650841550_4062847055_init();
    work_m_00000000001176349636_0267516215_init();
    work_m_00000000004134133675_1307194410_init();
    work_m_00000000002599571985_1794110034_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002599571985_1794110034");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
