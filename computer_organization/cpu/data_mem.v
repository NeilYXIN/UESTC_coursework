`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:08:45 12/03/2016 
// Design Name: 
// Module Name:    data_mem 
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
module data_mem(
	input Clock,
	output[31:0] dataout,
	input [31:0] datain,
	input [31:0] addr,
	input write , read
);
	reg [31:0] ram [0:31];	
	assign dataout = read ? ram[addr[6:2]] : 32'hxxxxxxxx;	
	always @ (posedge Clock) begin
	    if(write) 
	        ram[addr] <= datain;
	end

	initial begin
		ram[0] <= 2;
		ram[1] <= 3;
		ram[2] <= 5;
	end


endmodule
