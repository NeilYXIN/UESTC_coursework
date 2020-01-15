`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:22:27 11/27/2016 
// Design Name: 
// Module Name:    Control_Unit 
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
module Control_Unit(
   input [5:0] op , func,
	output RegDst , RegWrite , ALUSrc ,
   output MemWrite,MemRead , MemtoReg ,
	output Branch , 
	output [2:0] ALU_op
    );
   
	wire [1:0] ALUctr;

   Control U0( op,RegDst,RegWrite,ALUSrc ,MemWrite,MemRead , MemtoReg ,Branch ,  ALUctr);

	ALUop U1(func,ALUctr,ALU_op); 
	
endmodule
