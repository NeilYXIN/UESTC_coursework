`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:02:51 10/23/2015
// Design Name:   Sign_Extender
// Module Name:   E:/CPU_Test/Test1/T_signed_extender.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Sign_Extender
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_signed_extender;

	// Inputs
	reg [15:0] a;

	// Outputs
	wire [31:0] b;

	// Instantiate the Unit Under Test (UUT)
	Sign_Extender uut (
		.a(a), 
		.b(b)
	);

	initial begin
		// Initialize Inputs
		a = 16'h7abc;

		// Wait 100 ns for global reset to finish
		#100;
      a = 16'h8abc;  
		  
		// Add stimulus here

	end
      
endmodule

