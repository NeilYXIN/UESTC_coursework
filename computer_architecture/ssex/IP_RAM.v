`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:38:39 10/29/2012 
// Design Name: 
// Module Name:    IP_RAM 
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
module IP_RAM(we,addr,datain,clk,dataout
    );
	 input [31:0] datain;
	 input [31:0] addr;
	 input clk,we;
	 
	 output [31:0] dataout;
	 
	 reg [31:0] ram [0:31];
	 assign dataout=ram[addr];
	 
	 always @(posedge clk)begin
	 if(we)ram[addr]=datain;
	 end
	 integer i;
	 initial begin
	 for(i=0;i<32;i=i+1)
	    ram[i]=i;
		 ram[5'h00]=32'hBF800000;//0
		 ram[5'h14]=32'h000000a3;//20
		 ram[5'h15]=32'h00000027;//21
		 ram[5'h16]=32'h00000079;//22
		 ram[5'h17]=32'h00000115;//23
		 end
endmodule
