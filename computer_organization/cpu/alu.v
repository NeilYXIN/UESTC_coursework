`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:24:04 11/19/2016 
// Design Name: 
// Module Name:    alu 
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
module alu(
	input wire [31:0] A,
	input wire [31:0] B,
	input wire [2:0] optr,
	output wire [31:0] ret,
	output wire zero
);
	
	assign ret = (optr == 3'b000) ? A + B :
					(optr == 3'b100) ? A - B :
					(optr == 3'b001) ? A & B :
					(optr == 3'b101) ? A | B :
					(optr == 3'b010) ? A ^ B :
					(optr == 3'b110) ? {B[15],16'h0} : 0;
	
	assign zero = ~|ret;

endmodule
