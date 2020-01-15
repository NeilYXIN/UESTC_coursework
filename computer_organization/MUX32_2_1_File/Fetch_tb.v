`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:44:11 11/27/2016
// Design Name:   Fetch
// Module Name:   C:/Users/yx654/Desktop/MUX32_2_1/Fetch_tb.v
// Project Name:  MUX32_2_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Fetch
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Fetch_tb;

	// Inputs
	reg B;
	reg Z;
	reg Reset;
	reg Clock;
	reg [31:0] B_addr;

	// Outputs
	wire [31:0] addr;

	// Instantiate the Unit Under Test (UUT)
	Fetch uut (
		.B(B), 
		.Z(Z), 
		.Reset(Reset), 
		.Clock(Clock), 
		.B_addr(B_addr), 
		.addr(addr)
	);

	initial begin
		// Initialize Inputs
		B = 0;
		Z = 0;
		Reset = 0;
		Clock = 0;
		B_addr = 0;

		// Wait 100 ns for global reset to finish
		#100;
		B = 0;
		Z = 0;
		Reset = 0;
		Clock = 0;
		B_addr = 0;
		
		#100;
		B = 0;
		Z = 0;
		Reset = 1;
		Clock = 1;
		B_addr = 0;
				
		#100;
		B = 0;
		Z = 1;
		Reset = 1;
		Clock = 0;
		B_addr = 0;
				
		#100;
		B = 1;
		Z = 0;
		Reset = 1;
		Clock = 1;
		B_addr = 0;
		
				
		#100;
		B = 0;
		Z = 0;
		Reset = 1;
		Clock = 0;
		B_addr = 0;
				
		#100;
		B = 1;
		Z = 1;
		Reset = 0;
		Clock = 1;
		B_addr = 0;
				
		#100;
		B = 1;
		Z = 1;
		Reset = 1;
		Clock = 0;
		B_addr = 32'b00001111000011110000111100001111;
				
		#100;
		B = 1;
		Z = 1;
		Reset = 1;
		Clock = 1;
		B_addr = 32'b00001111000011110000111100001111;
		
		#100;
		B = 1;
		Z = 1;
		Reset = 0;
		Clock = 0;
		B_addr = 32'b00001111000011110000111100001111;
		// Add stimulus here

	end
      
endmodule

