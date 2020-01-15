`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:33:09 10/25/2015 
// Design Name: 
// Module Name:    Signed_extender 
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
module Signed_extender(
    input [15:0] a , 
	 output [31:0] b
    );
	 
	 assign b = { a[15]? 16'hffff:16'h0 , a};


endmodule
