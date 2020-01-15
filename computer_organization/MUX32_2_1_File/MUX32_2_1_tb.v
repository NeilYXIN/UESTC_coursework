`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:32:52 12/22/2016
// Design Name:   MUX32_2_1
// Module Name:   C:/Users/yx654/Desktop/MUX32_2_1_File/MUX32_2_1_tb.v
// Project Name:  MUX32_2_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MUX32_2_1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MUX32_2_1_tb;
	reg [31:0] A;
	reg [31:0] B;
	reg Sel;
	wire [31:0] O;

	// Instantiate the Unit Under Test (UUT)
	MUX32_2_1 uut (
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
		#100;
        
		// Add stimulus here
       A <= 32'haaaa0000;
		B <= 32'hbbbb1111;
		Sel <= 1'b0;
		
		#100;
		Sel <= 1'b1;

	end
      
endmodule