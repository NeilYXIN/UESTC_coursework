`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:44:59 11/12/2015
// Design Name:   Single_Cycle_Computer
// Module Name:   D:/CPU_Test/Test1/T_computer.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Single_Cycle_Computer
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_computer;

	// Inputs
	reg Reset;
	reg Clock;

	// Instantiate the Unit Under Test (UUT)
	Single_Cycle_Computer uut (
		.Reset(Reset), 
		.Clock(Clock)
	);

	initial begin
		// Initialize Inputs
		Reset = 0;
		Clock = 0;

		// Wait 100 ns for global reset to finish
		#100;
		Reset = 1;
		Clock = ~Clock;
		#100
		Clock = ~Clock;
		#100
		Clock = ~Clock;		
  		#100
		Clock = ~Clock;      
		// Add stimulus here

	end
      
endmodule

