`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:03:47 10/22/2015
// Design Name:   ALU
// Module Name:   E:/CPU_Test/Test1/T2.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T2;

	// Inputs
	reg [31:0] A;
	reg [31:0] B;
	reg [2:0] ALU_operation;

	// Outputs
	wire [31:0] Result;
	wire Zero;

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.A(A), 
		.B(B), 
		.ALU_operation(ALU_operation), 
		.Result(Result), 
		.Zero(Zero)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		ALU_operation = 0;

		// Wait 100 ns for global reset to finish
		#100;
		A = 32'h45;
		B = 32'h45;
		ALU_operation = 3'b000;  //add
        
		#100
		ALU_operation = 3'b100;  //sub
		
		#100
		ALU_operation = 3'b001;  //and
		
   	#100
		ALU_operation = 3'b101;  //or
		
	  	#100
		ALU_operation = 3'b010;  //xor
		  	  
	  	#100
		ALU_operation = 3'b110;  //lui
		  
		  
		// Add stimulus here

	end
      
endmodule

