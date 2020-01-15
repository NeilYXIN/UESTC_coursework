`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:55:58 11/07/2015
// Design Name:   MIPS_CPU
// Module Name:   D:/CPU_Test/Test1/T_MIPS_CPU.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MIPS_CPU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_MIPS_CPU;

	// Inputs
	reg [31:0] Inst;
	reg Reset;
	reg Clock;
	reg [31:0] data;

	// Outputs
	wire [31:0] Result;
	wire [31:0] addr;
	wire MemWrite;
	wire MemRead;
	wire MemtoReg;

	// Instantiate the Unit Under Test (UUT)
	MIPS_CPU uut (
		.Inst(Inst), 
		.Reset(Reset), 
		.Clock(Clock), 
		.data(data), 
		.Result(Result), 
		.addr(addr), 
		.MemWrite(MemWrite), 
		.MemRead(MemRead), 
		.MemtoReg(MemtoReg)
	);

	initial begin
		// Initialize Inputs
		Inst = 32'b000000_00001_00010_00111_00000_100000;
		Reset = 1;
		Clock = 0;
		data = 0;

		// Wait 100 ns for global reset to finish
		#100;
		Reset = 1;
      Clock = ~Clock;
		#100;
      Clock = ~Clock;		
		#100;
      Clock = ~Clock;		
		// Add stimulus here

	end
      
endmodule

