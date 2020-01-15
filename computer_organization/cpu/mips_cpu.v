`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:39:43 12/03/2016 
// Design Name: 
// Module Name:    mips_cpu 
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
module mips_cpu(
	input wire [31:0] Inst,
	input wire res,clk,
	input wire [31:0] ReadData,
	output wire [31:0] result,b_data,InstAddr,
	output wire MemWrite,MemRead
);
	wire RegDst,RegWrite,ALUSrc,Branch,Zero,MemtoReg;
	wire [2:0] ALU_op;
	
	wire [4:0] Wn;
	
	wire [31:0] A,B,Ext_Imm,ALU_B,data;
	
	assign b_data = B;
	
	fetch U0(Branch,Zero,res,clk,Ext_Imm,InstAddr);
	
	Controller U1 (
		.op(Inst[31:26]),
		.func(Inst[5:0]),
		
		.RegDst(RegDst),
		.RegWrite(RegWrite),
		.ALUSrc(ALUSrc),
		.MemWrite(MemWrite),
		.MemRead(MemRead),
		.MemtoReg(MemtoReg),
		.Branch(Branch),
		.ALUop(ALU_op)
	);
	
	mux5 U2 (Inst[20:16],Inst[15:11],RegDst,Wn);
	
	mux32 U7 (result,ReadData,MemtoReg,data);
	
	reg32 U3 (Inst[25:21],Inst[20:16],Wn,RegWrite,data,clk,A,B);
	
	sign_extender U4 (Inst[15:0],Ext_Imm);
	
	mux32 U5(B,Ext_Imm,ALUSrc,ALU_B);
	
	alu U6 (A,ALU_B,ALU_op,result,Zero);

endmodule
