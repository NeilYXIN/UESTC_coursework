`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:02:44 12/10/2016
// Design Name:   Data_Flow
// Module Name:   C:/Users/yx654/Desktop/MUX32_2_1_File/Data_Flow_tb.v
// Project Name:  MUX32_2_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Data_Flow
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Data_Flow_tb;

	// Inputs
	reg Reset;
	reg Clock;
	reg [31:0] Inst;
	reg [31:0] Data;

	// Outputs
	wire MemWrite;
	wire MemRead;
	wire [31:0] Result;
	wire [31:0] B_data;
	wire [31:0] NextPC;

	// Instantiate the Unit Under Test (UUT)
	Data_Flow uut (
		.Reset(Reset), 
		.Clock(Clock), 
		.Inst(Inst), 
		.Data(Data), 
		.MemWrite(MemWrite), 
		.MemRead(MemRead), 
		.Result(Result), 
		.B_data(B_data), 
		.NextPC(NextPC)
	);

	initial begin
		// Initialize Inputs
		Reset = 0;
		Clock = 0;
		Inst = 0;
		Data = 0;

		// Wait 100 ns for global reset to finish
		#100;
			Reset = 1;
		#100;
		Inst = 32'h00002820;
		Data = 32'h12345678;
		#100;
		Clock = 1;
		#100;
		Clock = 0;
		#100;
		Inst = 32'h8CB10000;
		#100;
		Clock = 1;
		#100; 
		Clock = 0;
		#100; 
		Reset = 0;
		#100; 
		
        
		// Add stimulus here

	end
      
endmodule

