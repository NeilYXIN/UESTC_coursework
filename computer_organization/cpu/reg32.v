`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:02:14 11/19/2016 
// Design Name: 
// Module Name:    reg32 
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
module reg32(
	input wire [4:0] rn1,
	input wire [4:0] rn2,
	input wire [4:0] wn,
	input wire write,
	input wire [31:0] wd,
	input wire clk,
	output wire [31:0] A,
	output wire [31:0] B
);
	reg [31:0] data[31:0];
	assign A = rn1 == 0 ? 0 : data[rn1];
	assign B = rn2 == 0 ? 0 : data[rn2];
	

	always @ (posedge clk) begin
		if(write && wn != 0) begin
			data[wn] <= wd;
		end
	end

endmodule
