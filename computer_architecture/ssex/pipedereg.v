`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:59:18 10/26/2012 
// Design Name: 
// Module Name:    pipedereg 
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
module pipedereg(d_jump,d_bmp,dwreg,dm2reg,dwmem,daluc,da,db,dimm,drn,
                 djal,dpc4,clk,clrn,ewreg,em2reg,ewmem,
					  ealuc,ea,eb,eimm,ern,ejal,epc4,
					  da_depen,db_depen,ea_depen,eb_depen,e_jump,e_bmp
    );
	 input [31:0] da,db,dimm,dpc4;
	 input [4:0] drn;
	 input [4:0] daluc;
	 input dwreg,dm2reg,dwmem,djal,d_jump,d_bmp;
	 input clk,clrn;
	 input [1:0] da_depen,db_depen;
	 
	 output [31:0] ea,eb,eimm,epc4;
	 output [4:0] ern;
	 output [4:0] ealuc;
	 output ewreg,em2reg,ewmem,ejal,e_jump,e_bmp;
	 output [1:0] ea_depen,eb_depen;
	 
	 reg [31:0] ea,eb,eimm,epc4;
	 reg [4:0] ern;
	 reg [4:0] ealuc;
	 reg ewreg,em2reg,ewmem,ejal,e_jump,e_bmp;
	 reg [1:0] ea_depen,eb_depen;
	 always @(negedge clrn or posedge clk)
	     if(clrn==0)
		      begin
				    ewreg<=0;    em2reg<=0;
					 ewmem<=0;    ealuc<=0;
					 eb_depen<=0;  ea<=0;
					 eb<=0;       eimm<=0;
					 ern<=0;      ea_depen<=0;
					 ejal<=0;     epc4<=0;
					 e_jump<=0;    e_bmp<=0;
			   end
			else
			    begin
				    ewreg<=dwreg;    em2reg<=dm2reg;
					 ewmem<=dwmem;    ealuc<=daluc;
					 eb_depen<=db_depen;  ea<=da;
					 eb<=db;       eimm<=dimm;
					 ern<=drn;      ea_depen<=da_depen;
					 ejal<=djal;     epc4<=dpc4;
					 e_jump<=d_jump;    e_bmp<=d_bmp;
				 end
endmodule
