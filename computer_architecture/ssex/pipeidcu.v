`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:55:16 10/26/2012 
// Design Name: 
// Module Name:    pipeidcu 
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
module pipeidcu(rsrtequ,func,
	             op,wreg,m2reg,wmem,aluc,regrt,aluimm,
					 sext,pcsource,shift,jal,
					 rs,rt,ern,mrn,ejump,ebmp,ewreg,mwreg,em2reg,mm2reg,adepen,bdepen,loaddepen,
					 djump,dbmp
    );
	 input [4:0] rs,rt,ern,mrn;
	 input rsrtequ,ewreg,mwreg,em2reg,ejump,ebmp,mm2reg; 
	 input [5:0] func,op;
	 
	 output wreg,m2reg,wmem,regrt,aluimm,sext,shift,jal;
	 output [4:0] aluc;
	 output [1:0] pcsource;
	 output [1:0] adepen,bdepen;
	 output loaddepen,djump,dbmp;
	 
	 wire i_add,i_sub,i_mul,i_and,i_or,i_xor,i_sll,i_srl,i_sra,i_jr;            //��ָ���������
	 wire i_addi,i_muli,i_andi,i_ori,i_xori,i_lw,i_sw,i_beq,i_bne,i_lui,i_j,i_jal;
	 
	 and(i_add,~op[5],~op[4],~op[3],~op[2],~op[1],~op[0],~func[2],~func[1],func[0]);
	 and(i_sub,~op[5],~op[4],~op[3],~op[2],~op[1],~op[0],~func[2],func[1],~func[0]);
	 and(i_mul,~op[5],~op[4],~op[3],~op[2],~op[1],~op[0],~func[2],func[1],func[0]);
	
	 
	 and(i_and,~op[5],~op[4],~op[3],~op[2],~op[1],op[0],~func[2],~func[1],func[0]);
	 and(i_or,~op[5],~op[4],~op[3],~op[2],~op[1],op[0],~func[2],func[1],~func[0]);
	
	 and(i_xor,~op[5],~op[4],~op[3],~op[2],~op[1],op[0],func[2],~func[1],~func[0]);
	 
	 and(i_sra,~op[5],~op[4],~op[3],~op[2],op[1],~op[0],~func[2],~func[1],func[0]);
	 and(i_srl,~op[5],~op[4],~op[3],~op[2],op[1],~op[0],~func[2],func[1],~func[0]);
	 and(i_sll,~op[5],~op[4],~op[3],~op[2],op[1],~op[0],~func[2],func[1],func[0]);
	 and(i_jr,~op[5],~op[4],~op[3],~op[2],op[1],~op[0],func[2],~func[1],~func[0]);
	 
	 and(i_addi,~op[5],~op[4],~op[3],op[2],~op[1],op[0]);
	
	 and(i_muli,~op[5],~op[4],~op[3],op[2],op[1],op[0]);
	 
	 
	 and(i_andi,~op[5],~op[4],op[3],~op[2],~op[1],op[0]);
	 and(i_ori,~op[5],~op[4],op[3],~op[2],op[1],~op[0]);

	 and(i_xori,~op[5],~op[4],op[3],op[2],~op[1],~op[0]);
	 
	 and(i_lw,~op[5],~op[4],op[3],op[2],~op[1],op[0]);
	 and(i_sw,~op[5],~op[4],op[3],op[2],op[1],~op[0]);
	 and(i_beq,~op[5],~op[4],op[3],op[2],op[1],op[0]);
	 and(i_bne,~op[5],op[4],~op[3],~op[2],~op[1],~op[0]);
	 and(i_lui,~op[5],op[4],~op[3],~op[2],~op[1],op[0]);
	 and(i_j,~op[5],op[4],~op[3],~op[2],op[1],~op[0]);
	 and(i_jal,~op[5],op[4],~op[3],~op[2],op[1],op[0]);
	
	 wire i_rs=i_add|i_sub|i_mul|i_and|i_or|i_xor|i_jr|i_addi|i_muli|           
	           i_andi|i_ori|i_xori|i_lw|i_sw|i_beq|i_bne;
	 wire i_rt=i_add|i_sub|i_mul|i_and|i_or|i_xor|i_sra|i_srl|i_sll|i_sw|i_beq|i_bne;
////////////////////////////////////////////////////////////////////////////////////////	 

    ////////////////////////////////////////////�����źŵ�����/////////////////////////////////////////////////////////
    assign wreg=(i_add|i_sub|i_mul|i_and|i_or|i_xor|i_sll|           //wregΪ1ʱд�Ĵ�������ĳһ�Ĵ���������д
	              i_srl|i_sra|i_addi|i_muli|i_andi|i_ori|i_xori|
					  i_lw|i_lui|i_jal) & ~ejump & ~ebmp;
	 assign regrt=i_addi|i_muli|i_andi|i_ori|i_xori|i_lw|i_lui;    //regrtΪ1ʱĿ�ļĴ�����rt������Ϊrd
	 assign jal=i_jal;                                           //Ϊ1ʱִ��jalָ�������
	 assign m2reg=i_lw;  //Ϊ1ʱ���洢������д��Ĵ���������ALU���д��Ĵ���
	 assign shift=i_sll|i_srl|i_sra;//Ϊ1ʱALUa�����ʹ����λλ��
	 assign aluimm=i_addi|i_muli|i_andi|i_ori|i_xori|i_lw|i_lui|i_sw;//Ϊ1ʱALUb�����ʹ��������
	 assign sext=i_addi|i_muli|i_lw|i_sw|i_beq|i_bne;//Ϊ1ʱ������չ����������չ
	 assign aluc[4]=i_sra;//ALU�Ŀ�����
	 assign aluc[3]=i_sub|i_or|i_ori|i_xor|i_xori| i_srl|i_sra|i_beq|i_bne;//ALU�Ŀ�����
	 assign aluc[2]=i_sll|i_srl|i_sra|i_lui;//ALU�Ŀ�����
	 assign aluc[1]=i_and|i_andi|i_or|i_ori|i_xor|i_xori|i_beq|i_bne;//ALU�Ŀ�����
	 assign aluc[0]=i_mul|i_muli|i_xor|i_xori|i_sll|i_srl|i_sra|i_beq|i_bne;//ALU�Ŀ�����

	 assign wmem=i_sw & ~ejump & ~ebmp;//Ϊ1ʱд�洢��������д
	 assign pcsource[1]=i_jr|i_j|i_jal;//ѡ����һ��ָ��ĵ�ַ��00ѡPC+4,01ѡת�Ƶ�ַ��10ѡ�Ĵ����ڵ�ַ��11ѡ��ת��ַ
	 assign pcsource[0]=i_beq&rsrtequ|i_bne&~rsrtequ|i_j|i_jal;
	
	 wire exe_adepen,exe_bdepen,mem_adepen,mem_bdepen,
	 beq,bne;			
			
	 assign loadadepen = (rs == ern )&em2reg&i_rs;//��ָ���rs��loadָ���rtһ����������load�����ұ�ָ��Ĵ���
	 assign loadbdepen = (rt == ern )&em2reg&i_rt;
	 assign loaddepen = loadadepen|loadbdepen;
	 
	 assign djump = i_j;
	 assign beq = (rs == rt) &i_beq;
	 assign bne = ~(rs == rt) &i_bne;
	 assign dbmp = beq | bne;
	 
	 assign exe_adepen = i_rs&(rs == ern)&(ewreg|em2reg);
	 assign mem_adepen = i_rs&(rs == mrn)&(mwreg|mm2reg);
	 assign exe_bdepen = i_rt&(rt == ern)&ewreg;
	 assign mem_bdepen = i_rt&(rt == mrn)&mwreg;
	 //alu��·ѡ������ź�
	 assign adepen[0]= shift& ~adepen[1]|(~exe_adepen|mem_adepen)&adepen[1];
    assign adepen[1]= exe_adepen|mem_adepen;
	 assign bdepen[0]= aluimm& ~bdepen[1]|(~exe_bdepen|mem_bdepen)&bdepen[1];
    assign bdepen[1]= exe_bdepen|mem_bdepen;
endmodule