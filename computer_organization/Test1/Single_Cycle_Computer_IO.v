`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:14:34 11/13/2015 
// Design Name: 
// Module Name:    Single_Cycle_Computer_IO 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Single_Cycle_Computer_IO(
    input Reset , Clock , 
	 
    //output [31:0] IO_addr , IO_Result,	 
		 
		 
	 //以下用于IO输入输出
	 input BTN_IN,          //单步脉冲输入
	 output [7:0] seg,      //数码管7段
	 output [5:0] AN_SEL ,
    output LED0 , LED1  	 
    );
	 
	 reg  [31:0] clockdiv = 0;
	 wire  BTN_Out; 
	 wire MemWrite, MemRead , MemtoReg;
    wire [31:0] Inst , MemOutData , data , b_data ,  addr , Memdata , Result;

	 //单步执行时钟控制
	 BTN_Anti_Jitter anti_jitter( clockdiv[12] , BTN_IN , BTN_Out ); //按钮去抖动
   // assign BTN_Out = BTN_IN;
	// assign IO_addr = addr;
	// assign IO_Result = Result;
	
	assign LED0 = BTN_IN;
	assign LED1 = Reset;
	 always @ (posedge Clock)  clockdiv <= clockdiv + 1;
	 
	 //数码管显示
	 wire [23:0] disp;
	 assign disp = {addr[7:0],Result[31:16]};
	 Hex7seg_decode hex7(disp , clockdiv[18:16] , seg , AN_SEL);
	 
    MIPS_CPU U0( Inst, Reset , BTN_Out , data, Result , b_data , addr, 	MemWrite, MemRead , MemtoReg );
    INST_ROM U1(  BTN_Out ,  addr,  Inst );
	 DATA_RAM U2(  BTN_Out , MemOutData ,  b_data , Result ,	MemWrite, MemRead);
	 MUX32_2_1 U3(Result , MemOutData , MemtoReg , data);

endmodule
