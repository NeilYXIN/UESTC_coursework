`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:18:25 10/26/2012 
// Design Name: 
// Module Name:    pipeexe 
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
module pipeexe(ea_depen,eb_depen,malu,wdi,ealuc,ea,eb,eimm,ern0,epc4,ejal,ern,ealu,z
    );
	 input [31:0] ea,eb,eimm,epc4,malu,wdi;
	 input [4:0] ern0;
	 input [4:0] ealuc;
	 input ejal;
	 input [1:0] ea_depen,eb_depen;
	 
	 output [31:0] ealu;
	 output [4:0] ern;
	 output z;
	 
	 wire [31:0] alua,alub,sa,ealu0,epc8;
	 
	 assign sa={eimm[4:0],eimm[31:5]};//��λλ��������
	 
	 cla32 ret_addr(epc4,32'h4,1'b0,epc8);//��PC+4�ټ�4���PC+8����jal��
	 
	 mux4x32 alu_ina (ea,sa,malu,wdi,ea_depen,alua);//ѡ��ALU a�˵�������Դ
	 
	 mux4x32 alu_inb (eb,eimm,malu,wdi,eb_depen,alub);//ѡ��ALU b�˵�������Դ
	 
	 mux2x32 save_pc8(ealu0,epc8,ejal,ealu);//ѡ�����ALU�������Դ��ejalΪ0ʱ��ALU�ڲ�����Ľ����Ϊ1ʱ��PC+8
	 
	 assign ern=ern0|{5{ejal}};//��jalָ��ִ��ʱ���ѷ��ص�ַд��31�żĴ���
	 
	 alu al_unit (alua,alub,ealuc,ealu0,z);//ALU
endmodule
