`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:22:07 11/12/2015 
// Design Name: 
// Module Name:    Single_Cycle_Computer 
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
module Single_Cycle_Computer(
    input Reset , Clock
    );

    wire MemWrite, MemRead , MemtoReg;

    wire [31:0] Inst , MemOutData , data , b_data ,  addr , Memdata , Result;

    MIPS_CPU U0( Inst, Reset , Clock, data, Result , b_data , addr, 	MemWrite, MemRead , MemtoReg );

    INST_ROM U1(  Clock,  addr,  Inst );
	 DATA_RAM U2(  Clock , MemOutData ,  b_data , Result ,	MemWrite, MemRead);
	 
	 MUX32_2_1 U3(Result , MemOutData , MemtoReg , data);
	 
endmodule
