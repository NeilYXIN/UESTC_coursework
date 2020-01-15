`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:34:30 11/14/2015
// Design Name:   Single_Cycle_Computer_IO
// Module Name:   D:/CPU_Test/Test1/T_IO.v
// Project Name:  Test1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Single_Cycle_Computer_IO
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module T_IO;

	// Inputs
	reg Reset;
	reg Clock;
	reg BTN_IN;

	// Outputs
	wire [31:0] IO_addr;
	wire [31:0] IO_Result;
	wire [7:0] seg;
	wire [5:0] AN_SEL;

	// Instantiate the Unit Under Test (UUT)
	Single_Cycle_Computer_IO uut (
		.Reset(Reset), 
		.Clock(Clock), 
		.IO_addr(IO_addr), 
		.IO_Result(IO_Result), 
		.BTN_IN(BTN_IN), 
		.seg(seg), 
		.AN_SEL(AN_SEL)
	);

	initial begin
		// Initialize Inputs
		Reset = 0;
		Clock = 0;
		BTN_IN = 0;

		// Wait 100 ns for global reset to finish
		#100;
		Reset = 1;
		BTN_IN = ~BTN_IN;
		
		#100
		BTN_IN = ~BTN_IN;
		#100
		BTN_IN = ~BTN_IN;	
     	#100
		BTN_IN = ~BTN_IN;   
     	#100
		BTN_IN = ~BTN_IN; 
     	#100
		BTN_IN = ~BTN_IN; 		
		// Add stimulus here

	end
      
endmodule

