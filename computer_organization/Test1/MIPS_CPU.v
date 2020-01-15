`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:08:53 11/07/2015 
// Design Name: 
// Module Name:    MIPS_CPU 
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
module MIPS_CPU(
    input [31:0]  Inst,
    input Reset , Clock,
	 input [31:0] data,
	 output [31:0] Result , b_data , addr,
	 output MemWrite, MemRead , MemtoReg 
    );
	 
	
	 wire RegDst , RegWrite , ALUSrc  ,Branch , Zero;
	 wire [2:0] ALU_op;
	 
	 wire [4:0] Wn;
	 
	 wire [31:0] A , B , Ext_Imm , ALU_B ;
	 
	 reg [31:0] addr1;
	 
	 Fetch U0(Branch , Zero , Reset , Clock , Ext_Imm , addr);
	 
	 Control_Unit U1( .op(Inst[31:26]) , .func(Inst[5:0]),
	             .RegDst(RegDst) , .RegWrite(RegWrite) , .ALUSrc(ALUSrc) ,
                .MemWrite(MemWrite),.MemRead(MemRead) , .MemtoReg(MemtoReg) ,
	             .Branch(Branch) , .ALU_op(ALU_op)  );
					 			 
	 MUX5_2_1 U2( Inst[20:16] , Inst[15:11] , RegDst , Wn );
	 

    RegFile U3(Inst[25:21] , Inst[20:16] ,Wn ,RegWrite , data , A ,B , Clock);
	
    Sign_Extender U4( Inst[15:0] , Ext_Imm);
 
    MUX32_2_1 U5( B , Ext_Imm , ALUSrc , ALU_B );
	 
	 ALU U6 ( A , ALU_B , ALU_op , Result , Zero);

endmodule
