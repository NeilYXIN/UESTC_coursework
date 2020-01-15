`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:56:24 12/22/2016
// Design Name:   Mainboard
// Module Name:   C:/Users/yx654/Desktop/MUX32_2_1_File/Mainboard1_tb.v
// Project Name:  MUX32_2_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mainboard
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Mainboard1_tb;

	// Inputs
	reg Clock;
	reg Reset;

	// Outputs
	wire [31:0] Inst;
	wire [31:0] PC;
	wire [31:0] Result;
	wire [31:0] B_data;

	// Instantiate the Unit Under Test (UUT)
	Mainboard uut (
		.Clock(Clock), 
		.Reset(Reset), 
		.Inst(Inst), 
		.PC(PC), 
		.Result(Result), 
		.B_data(B_data)
	);

	initial begin
		// Initialize Inputs
		Clock = 0;
		Reset = 0;

		// Wait 100 ns for global reset to finish
		#100;
          Reset= 1;
		end
		always begin
		#50;
		Clock=~Clock;  
		// Add stimulus here

	end
      
endmodule

