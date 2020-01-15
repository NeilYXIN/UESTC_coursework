`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:28:04 10/23/2015
// Design Name:   Fetch
// Module Name:   D:/CPU_Test/Test1/T_Fetch.v
// Project Name:  Test1
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

module T_Fetch;

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
		Reset = 1;
		Clock = ~Clock;
		#100;
		Clock = ~Clock;
		#100;
		Clock = ~Clock;
		#100;
		Clock = ~Clock;
		
		#100;
		Clock = ~Clock;
      B = 1;
		Z = 1;
	   
		#100;
			
      B_addr = 32'h1234abcd;
      Clock = ~Clock;		
		#100;
		Clock = ~Clock;	
		// Add stimulus here

	end
      
endmodule

