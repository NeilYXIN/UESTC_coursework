`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:30:17 11/27/2016 
// Design Name: 
// Module Name:    Fetch 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Fetch(
input B , Z , Reset , Clock ,
input [31:0] B_addr,
output [31:0] addr
    );
	 
reg [31:0] PC;	
wire [31:0] U0_o;	
wire [31:0] U1_C;	
wire [31:0] U2_C;	
wire [31:0] Next_PC;	
wire sel = Z & B;	
Left_2_Shifter U0 (B_addr, U0_o);	
ADD32 U1 (PC, 4, U1_C);	
ADD32 U2 (U1_C, U0_o, U2_C);	
MUX32_2_1 M1 (U1_C, U2_C, sel, Next_PC);		
assign addr = PC;		
always @ (posedge Clock or negedge Reset) begin		
if (Reset == 0)			
PC = 0;	
	else		
	PC = Next_PC;	
end
endmodule
