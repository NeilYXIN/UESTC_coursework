`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:08:41 10/30/2015
// Design Name:   Control
// Module Name:   D:/CPU_Test/Test1/T_control.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_control;

	// Inputs
	reg [5:0] op;

	// Outputs
	wire RegDst;
	wire RegWrite;
	wire ALUSrc;
	wire MemWrite;
	wire MemRead;
	wire MemtoReg;
	wire Branch;
	wire [1:0] ALUctr;

	// Instantiate the Unit Under Test (UUT)
	Control uut (
		.op(op), 
		.RegDst(RegDst), 
		.RegWrite(RegWrite), 
		.ALUSrc(ALUSrc), 
		.MemWrite(MemWrite), 
		.MemRead(MemRead), 
		.MemtoReg(MemtoReg), 
		.Branch(Branch), 
		.ALUctr(ALUctr)
	);

	initial begin
		// Initialize Inputs
		op = 6'b000000;

		// Wait 100 ns for global reset to finish
		#100;
		op = 6'b000000;
    	#100;
		op = 6'b100011;   
	   #100;
		op = 6'b101011;		
		#100;
		op = 6'b000100;
	   #100;
		op = 6'b001111;
	end
      
endmodule

