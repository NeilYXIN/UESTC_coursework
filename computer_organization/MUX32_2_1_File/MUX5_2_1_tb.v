`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:09:12 11/20/2014
// Design Name:   MUX5_2_1
// Module Name:   C:/Demo/MUX32_2_1/MUX5_2_1_tb.v
// Project Name:  MUX32_2_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MUX5_2_1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MUX5_2_1_tb;

	// Inputs
	reg [4:0] A;
	reg [4:0] B;
	reg Sel;

	// Outputs
	wire [4:0] O;

	// Instantiate the Unit Under Test (UUT)
	MUX5_2_1 uut (
		.A(A), 
		.B(B), 
		.Sel(Sel), 
		.O(O)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		Sel = 0;

		// Wait 100 ns for global reset to finish
		
        
		// Add stimulus here
      #100;
      Sel=0;A=0;B=0;
		#100;
      Sel=0;A=0;B=1;
		
		#100;
		Sel=0;A=1;B=0;
		#100;
		Sel=0;A=1;B=1;
		
      #100;
      Sel=1;A=0;B=0;
		#100;
      Sel=1;A=0;B=1;
		
		#100;
      Sel=1;A=1;B=0;
		#100;
      Sel=1;A=1;B=1;
	
	end
      
endmodule

