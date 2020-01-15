`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:50:44 11/26/2016 
// Design Name: 
// Module Name:    lshift2 
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
module lshift2(
	input wire [31:0] a,
	output wire [31:0] b
);
	
	assign b = a << 2;

endmodule

