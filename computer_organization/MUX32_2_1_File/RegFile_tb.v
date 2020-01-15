`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:19:33 11/20/2014
// Design Name:   RegFile
// Module Name:   C:/Demo/MUX32_2_1/RegFile_tb.v
// Project Name:  MUX32_2_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RegFile
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module RegFile_tb;

	// Inputs
	reg [4:0] Rn1;
	reg [4:0] Rn2;
	reg [4:0] Wn;
	reg Write;
	reg [31:0] Wd;
	reg Clock;

	// Outputs
	wire [31:0] A;
	wire [31:0] B;

	// Instantiate the Unit Under Test (UUT)
	RegFile uut (
		.Rn1(Rn1), 
		.Rn2(Rn2), 
		.Wn(Wn), 
		.Write(Write), 
		.Wd(Wd), 
		.A(A), 
		.B(B), 
		.Clock(Clock)
	);

	initial begin
		// Initialize Inputs
		Rn1 = 0;
		Rn2 = 0;
		Wn = 0;
		Write = 0;
		Wd = 0;
		Clock = 0;

		// Wait 100 ns for global reset to finish
	
        #100;
		// Add stimulus here
		

	#100;
	Write=1;Wn=4;Wd=511;Clock=1;Rn1=0;Rn2=0;
	
	
	#100;
	Write=0;Wn=0;Wd=0;Clock=0;Rn1=4;Rn2=0;
	
	#100;
	Write=1;Wn=8;Wd=811;Clock=1;Rn1=0;Rn2=0;
	
	#100;
	Write=0;Wn=0;Wd=0;Clock=1;Rn1=0;Rn2=8;
	
	
	
	
	
	end
      
endmodule

