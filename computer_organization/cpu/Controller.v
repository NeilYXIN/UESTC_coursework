`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:27:09 11/26/2016 
// Design Name: 
// Module Name:    Controller 
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
module Controller(
	input wire [5:0] op , func,
	output wire RegDst , RegWrite , ALUSrc,
	output wire MemWrite , MemRead , MemtoReg,
	output wire Branch ,
	output wire [2:0] ALUop
);
	 
	 wire [1:0] ALUctr;
	 
	 Control U0( .op(op) ,
				  	 .RegDst(RegDst) ,
					 .RegWrite(RegWrite) ,
					 .ALUSrc(ALUSrc) ,
					 .MemWrite(MemWrite) ,
					 .MemRead(MemRead) ,
					 .MemtoReg(MemtoReg) ,
					 .Branch(Branch) ,
					 .ALUctr(ALUctr));
	 
	 ALUOp U1(.func(func),.ALUctr(ALUctr),.ALUop(ALUop));


endmodule
