`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:27:22 12/03/2016 
// Design Name: 
// Module Name:    Mainboard 
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
module Mainboard(
   input Clock,	
	input Reset,
	output [31:0] Inst,
	output [31:0] PC,
	output [31:0] Result,
	output [31:0] B_data
    );
   wire [31:0] b_data;	
	wire  MemWrite,MemRead;
	
	Data_Flow U0 ( Reset ,Clock , Inst, B_data, MemWrite,MemRead,Result ,b_data, PC);  
	Inst_mem U1(PC, Inst);	
	Data_mem U2(Clock , B_data , b_data , Result , MemWrite , MemRead );


endmodule
