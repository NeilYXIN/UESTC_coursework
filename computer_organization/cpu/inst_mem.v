`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:05:26 12/03/2016 
// Design Name: 
// Module Name:    inst_mem 
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
module inst_mem(
	input wire [31:0] address,
	output wire [31:0] inst
);
	wire [31:0] ram[0:31];
	//assign ram[5'h00] = 32'h00002820;
	//assign ram[5'h01] = 32'h8CB10000;
	//                       |    |    |    |     |    |      
	assign ram[0] = 32'b00000000000000000000100000100000;//add $1,$0,$0
	assign ram[1] = 32'b10001100001000100000000000000000;//lw $2,0($1)
	assign ram[2] = 32'b10001100001000110000000000000100;//lw $3,4($1)
	assign ram[3] = 32'b00000000010000110001000000100000;//add $2,$2,$3
	assign ram[4] = 32'b10001100001000110000000000001000;//lw $3,8($1)
	assign ram[5] = 32'b00010000010000110000000000000001;//beq $2,3,1
	assign ram[6] = 32'b10101100001000000000000000001100;//sw $0,12($1)
	assign ram[7] = 32'b10101100001000100000000000001100;//sw $2,12($1)
	
	
	assign inst = ram[address[6:2]];

endmodule
