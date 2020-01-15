`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:48:39 10/30/2015
// Design Name:   Control_Unit
// Module Name:   D:/CPU_Test/Test1/T_Control_Unit.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Control_Unit
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_Control_Unit;

	// Inputs
	reg [5:0] op;
	reg [5:0] func;

	// Outputs
	wire RegDst;
	wire RegWrite;
	wire ALUSrc;
	wire MemWrite;
	wire MemRead;
	wire MemtoReg;
	wire Branch;
	wire [2:0] ALU_op;

	// Instantiate the Unit Under Test (UUT)
	Control_Unit uut (
		.op(op), 
		.func(func), 
		.RegDst(RegDst), 
		.RegWrite(RegWrite), 
		.ALUSrc(ALUSrc), 
		.MemWrite(MemWrite), 
		.MemRead(MemRead), 
		.MemtoReg(MemtoReg), 
		.Branch(Branch), 
		.ALU_op(ALU_op)
	);

	initial begin
		// Initialize Inputs
		func=6'b000000;
		op = 6'b000000;

		#100;
		func=6'b100010;		
		#100;
		func=6'b100100;		
		#100;
		func=6'b100101;		
		#100;
		func=6'b100110;	
	
		
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

