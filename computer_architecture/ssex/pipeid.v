`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:26:59 10/25/2012 
// Design Name: 
// Module Name:    pipeid 
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
module pipeid(dpc4,inst,wrn,
              wdi,wwreg,clk,clrn,bpc,jpc,pcsource,
				  wreg,m2reg,wmem,aluc,aluimm,a,b,imm,rn,
				  shift,jal,rsrtequ,
				  ern,mrn,e_wreg,m_wreg,e_m2reg,m_m2reg,e_jump,e_bmp,
				  a_depen,b_depen,load_depen,d_jump,d_bmp
    );//ID
	 input [31:0] dpc4,inst,wdi;
	 input [4:0] wrn;
	 input wwreg;
	 input clk,clrn;
	 input rsrtequ;
	 input [4:0] ern,mrn;
	 input e_wreg,m_wreg,e_m2reg,m_m2reg,e_jump,e_bmp; 
	 
	 output [31:0] bpc,jpc,a,b,imm;
	 output [4:0] rn;
	 output [4:0] aluc;
	 output [1:0] pcsource;
	 output wreg,m2reg,wmem,aluimm,shift,jal;	 
	 output [1:0] a_depen,b_depen;
    output load_depen,d_jump,d_bmp;
	 
	 wire [5:0] op,func;
	 wire [4:0] rs,rt,rd;
	 wire [31:0] qa,qb,br_offset;
	 wire [15:0] ext16;
	 wire regrt,sext,e;
	 
	 assign func=inst[25:20];  
	 assign op=inst[31:26];
	 assign rs=inst[9:5];
	 assign rt=inst[4:0];
	 assign rd=inst[14:10];
	 
	 assign jpc={dpc4[31:28],inst[25:0],2'b00};//jump,jalָ���Ŀ���ַ�ļ���
	
	pipeidcu cu(rsrtequ,func,                          //���Ʋ���
	             op,wreg,m2reg,wmem,aluc,regrt,aluimm,
					 sext,pcsource,shift,jal,
					 rs,rt,ern,mrn,e_jump,e_bmp,e_wreg,m_wreg,e_m2reg,m_m2reg,a_depen,b_depen,load_depen
					 ,d_jump,d_bmp);
					 
    regfile rf (rs,rt,wdi,wrn,wwreg,~clk,clrn,qa,qb);//�Ĵ����ѣ���32��32λ�ļĴ�����0�żĴ�����Ϊ0
	 
	 mux2x5 des_reg_no (rd,rt,regrt,rn); //ѡ��Ŀ�ļĴ�����������rd,����rt
	 
	 assign a=qa;
	 assign b=qb;
	 assign e=sext&inst[25];//������չ��0��չ
	 assign ext16={16{e}};//������չ
	 assign imm={ext16,inst[25:10]};//�����������з�����չ
	 assign br_offset={imm[29:0],2'b00};
	 
	 cla32 br_addr (dpc4,br_offset,1'b0,bpc);//beq,bneָ���Ŀ���ַ�ļ���
	
endmodule
