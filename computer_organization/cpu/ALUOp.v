`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:13:42 11/26/2016 
// Design Name: 
// Module Name:    ALUOp 
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
module ALUOp(
	input wire [5:0] func,
	input wire [1:0] ALUctr,
	output wire [2:0] ALUop
); 
	 wire temp = ALUctr[1] & ~ALUctr[0];
	 assign ALUop[2] = (temp & ((~func[2] & func[1]) | {func[2] & func[0]}))| ALUctr[0];
	 assign ALUop[1] = (temp & func[2] & func[1]) | (ALUctr[1] & ALUctr[0]);
	 assign ALUop[0] = (temp & func[2] & ~func[1]);
endmodule
