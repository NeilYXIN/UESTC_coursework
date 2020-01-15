`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:17:26 12/03/2016 
// Design Name: 
// Module Name:    Data_Flow 
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
module Data_Flow(
input Reset,Clock,
input [31:0] Inst,
	input [31:0] Data,
	output MemWrite,
	output MemRead,
	output [31:0] Result,
	output [31:0] B_data,
	output [31:0] NextPC
    );
	
	wire Zero, Branch;
	wire RegDst;
	wire RegWrite;
	wire ALUSrc;
	wire MemtoReg;
	wire [2:0] ALU_op;
	wire [4:0] Wn;
	wire [31:0] A,B, ALU_B,Ext_Imm,Wd;


assign B_data=B;
	Fetch U0 (Branch,Zero,Reset,Clock, Ext_Imm, NextPC);
	Control_Unit U1 (Inst[31:26], Inst[5:0], RegDst, RegWrite, ALUSrc, 
						MemWrite, MemRead, MemtoReg, Branch, ALU_op);
	ALU U2 (A, ALU_B, ALU_op, Result, Zero);
	RegFile U3 (Inst[25:21], Inst[20:16], Wn, RegWrite, Wd, A, B, Clock);
	MUX5_2_1 U4 (Inst[20:16], Inst[15:11], RegDst, Wn);
	MUX32_2_1 U5 (B,Ext_Imm, ALUSrc, ALU_B);
	Sign_Extender U6 (Inst[15:0], Ext_Imm);
	MUX32_2_1 U7 (Result, Data, MemtoReg, Wd);
	endmodule
	