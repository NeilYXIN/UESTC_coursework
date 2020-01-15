`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:48:30 10/29/2015
// Design Name:   ALUop
// Module Name:   D:/CPU_Test/Test1/T_ALUop.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALUop
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_ALUop;

	// Inputs
	reg [5:0] func;
	reg [1:0] ALUctr;

	// Outputs
	wire [2:0] ALU_op;

	// Instantiate the Unit Under Test (UUT)
	ALUop uut (
		.func(func), 
		.ALUctr(ALUctr), 
		.ALU_op(ALU_op)
	);

	initial begin
		// Initialize Inputs
		func = 6'b100000;
		ALUctr = 2'b10;

		// Wait 100 ns for global reset to finish
		#100;
		func = 6'b100010;

		#100;
		func = 6'b100100;

		#100;
		func = 6'b100101;

		#100;
		func = 6'b100110;

      #100;
		ALUctr = 2'b00;
      #100;
		ALUctr = 2'b01;
      #100;
		ALUctr = 2'b11;
	end
      
endmodule

