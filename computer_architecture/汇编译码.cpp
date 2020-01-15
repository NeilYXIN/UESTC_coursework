//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib> 

int is01(char* st); //�жϴ���ֵ�Ƿ�Ϸ�Ϊ0����1 
char * ToStr5(int n); //����ת��Ϊ�������� 
char * ToStr16(int n); //����ת��Ϊ�������� 
char * ToStr26(int n); //����ת��Ϊ�������� 

int main()
{
	FILE *out, *in; //����ļ�
					//freopen("D:\\in1.txt", "r", stdin);
	in = fopen("D:\\in1.txt", "r");
	out = fopen("D:\\out1.txt ", "w");
	char str[100]; //��ȡ�����ַ��� 
	char s[25][20]; //����涨�½���/��Դ�����Ȳ�����20 
	int ri; //��ȡ�ַ����������ָ�� 
	int si, sj; //����s��ָ�� 
	char instr[40]; //ָ���Ļ�����	 
	char offsetstr[30]; //offset16λ�� 
	char rdstr[9], rsstr[9], rtstr[9], jumpstr[30]; //rd rs rt��Ϊ5λ��
	char shiftstr[9]; //shift5λ�� 
	char immediatestr[30]; //immediate16λ��

						   //while (fgets(str, 50, stdin) != NULL)
	while (fgets(str, 50, in) != NULL)
	{
		//printf("����ָ��Ϊ:%s", str);   
		//�����������������s[][]������ 
		si = 0; //��ȡ�����г�ʼ�� ��ʾ�м������� 
		for (ri = 0; str[ri] != '\n' && str[ri] != '\0' && ri < 50; ++ri)//�ж�\0����Ϊ����ѭ�����Ѿ�����\n,��ѭ��һ����+1�͵���\0�����԰������ֽṹ����ɾȥ��\n���ж� 
		{
			//printf("ri: %d\n", ri); 
			sj = 0; //����� 
			while (str[ri] != ' ' && str[ri] != ',' && str[ri] != '\n')//�ж�\n�����һ���ַ������������ 
			{
				//printf("ri: %d\n", ri); 
				//printf("(%c)\n", str[ri]); 
				s[si][sj++] = str[ri++];
				//printf("si: %d, sj: %d\n", si, sj); 
			}
			if (str[ri - 1] != ' ')//������⣬�������ո�ʱ������ 
			{
				s[si++][sj] = '\0'; //�õ�һ������
			}
		}

		/*����鿴ָ���Ƿ�������
		for(int ii = 0; ii < si; ++ii)
		{
		printf("%s\n", s[ii]);
		}
		����鿴ָ���Ƿ�������*/

		//��s[][]������������ж�
		if (si == 2)//ֻ��jump target (����jump��Ϊ26λaddress) 
		{
			strcpy(jumpstr, ToStr26(atoi(s[1])));
			//���Ȳ鿴�Ƿ���jumpָ����address����Ϊ26��address����ֵ�Ϸ� 
			if (!strcmp(s[0], "jump") && strlen(jumpstr) == 26 && is01(jumpstr))
			{
				strcpy(instr, "010010");
				//printf("1��%s\n", instr); 
				strcat(instr, jumpstr);
				//printf("2��%s\n", instr); 
			}
			else
			{
				printf("Input error!	%s", str);
			}
		}
		else if (si == 3)
		{
			//load 5λrt,16λoffset(5λrs) 
			if (!strcmp(s[0], "load"))
			{
				sscanf(s[1], "r%s", rtstr);
				sscanf(s[2], "%[0-9](r%[0-9])\n", offsetstr, rsstr);
				strcpy(offsetstr, ToStr16(atoi(offsetstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				//printf("%s\n", offsetstr); 
				//printf("%s\n", rsstr); 
				//printf("%s\n", rtstr); 
				if (strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(offsetstr) == 16 && is01(offsetstr))
				{
					strcpy(instr, "001101");
					strcat(instr, offsetstr);
					strcat(instr, rsstr);
					strcat(instr, rtstr); //rtstr
				}
			}
			else if (!strcmp(s[0], "store") && strlen(s[1]) == 26 && is01(s[1]))
			{
				sscanf(s[1], "r%s", rtstr);
				sscanf(s[2], "%[0-9](r%[0-9])\n", offsetstr, rsstr);
				strcpy(offsetstr, ToStr16(atoi(offsetstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				//printf("%s\n", offsetstr); 
				//printf("%s\n", rsstr); 
				//printf("%s\n", rtstr); 
				if (strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(offsetstr) == 16 && is01(offsetstr))
				{
					strcpy(instr, "001110");
					strcat(instr, offsetstr);
					strcat(instr, rsstr);
					strcat(instr, rtstr); //rtstr
				}
			}
			else
			{
				printf("Error!	%s", str);
			}
		}
		else if (si == 4)
		{
			if (!strcmp(s[0], "add"))
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rsstr); //rs
				sscanf(s[3], "r%s", rtstr); //rt
											//printf("%s\n", rdstr); 
											//printf("%s\n", rsstr); 
											//printf("%s\n", rtstr); 
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "00000000000100000");
					strcat(instr, rdstr);
					strcat(instr, rsstr);
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "sub"))//��ʱû�н������Ҫ����ȷ�� 
			{

			}
			else if (!strcmp(s[0], "mul"))//��ʱû�н������Ҫ����ȷ��
			{

			}
			else if (!strcmp(s[0], "and"))
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rsstr); //rs
				sscanf(s[3], "r%s", rtstr); //rt
											//printf("%s\n", rdstr); 
											//printf("%s\n", rsstr); 
											//printf("%s\n", rtstr); 
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "00000100000100000");
					strcat(instr, s[1]);
					strcat(instr, s[2]);
					strcat(instr, s[3]);
				}
			}
			else if (!strcmp(s[0], "or"))
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rsstr); //rs
				sscanf(s[3], "r%s", rtstr); //rt
											//printf("%s\n", rdstr); 
											//printf("%s\n", rsstr); 
											//printf("%s\n", rtstr); 
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "00000100001000000");
					strcat(instr, s[1]);
					strcat(instr, s[2]);
					strcat(instr, s[3]);
				}
			}
			else if (!strcmp(s[0], "xor"))
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rsstr); //rs
				sscanf(s[3], "r%s", rtstr); //rt
											//printf("%s\n", rdstr); 
											//printf("%s\n", rsstr); 
											//printf("%s\n", rtstr); 
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "00000100010000000");
					strcat(instr, s[1]);
					strcat(instr, s[2]);
					strcat(instr, s[3]);
				}
			}
			else if (!strcmp(s[0], "sll"))//rd,rt,shift ��Ӧs[1]s[2]s[3]
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rtstr); //rt
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(shiftstr, ToStr5(atoi(s[3])));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(shiftstr) == 5 && is01(shiftstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "000010000011");
					strcat(instr, shiftstr);
					strcat(instr, rdstr);
					strcat(instr, "00000");
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "srl"))
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rtstr); //rt
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(shiftstr, ToStr5(atoi(s[3])));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(shiftstr) == 5 && is01(shiftstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "000010000010");
					strcat(instr, shiftstr);
					strcat(instr, rdstr);
					strcat(instr, "00000");
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "sra"))
			{
				sscanf(s[1], "r%s", rdstr); //rd
				sscanf(s[2], "r%s", rtstr); //rt
				strcpy(rdstr, ToStr5(atoi(rdstr)));
				strcpy(shiftstr, ToStr5(atoi(s[3])));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				if (strlen(rdstr) == 5 && is01(rdstr) &&
					strlen(shiftstr) == 5 && is01(shiftstr) &&
					strlen(rtstr) == 5 && is01(rtstr))
				{
					strcpy(instr, "000010000001");
					strcat(instr, shiftstr);
					strcat(instr, rdstr);
					strcat(instr, "00000");
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "addi"))//rt,rs,imm��Ӧs[1]s[2]s[3]
			{
				sscanf(s[1], "r%s", rtstr); //rt
				sscanf(s[2], "r%s", rsstr); //rs
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(immediatestr, ToStr16(atoi(immediatestr)));
				if (strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(immediatestr) == 16 && is01(immediatestr))
				{
					strcpy(instr, "000101");
					strcat(instr, immediatestr);
					strcat(instr, rsstr);
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "muli"))//���� 
			{

			}
			else if (!strcmp(s[0], "andi"))
			{
				sscanf(s[1], "r%s", rtstr); //rt
				sscanf(s[2], "r%s", rsstr); //rs
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(immediatestr, ToStr16(atoi(immediatestr)));
				if (strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(immediatestr) == 16 && is01(immediatestr))
				{
					strcpy(instr, "001001");
					strcat(instr, immediatestr);
					strcat(instr, rsstr);
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "ori"))
			{
				sscanf(s[1], "r%s", rtstr); //rt
				sscanf(s[2], "r%s", rsstr); //rs
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(immediatestr, ToStr16(atoi(immediatestr)));
				if (strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(immediatestr) == 16 && is01(immediatestr))
				{
					strcpy(instr, "001010");
					strcat(instr, immediatestr);
					strcat(instr, rsstr);
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "xori"))
			{
				sscanf(s[1], "r%s", rtstr); //rt
				sscanf(s[2], "r%s", rsstr); //rs
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(immediatestr, ToStr16(atoi(immediatestr)));
				if (strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(immediatestr) == 16 && is01(immediatestr))
				{
					strcpy(instr, "001100");
					strcat(instr, immediatestr);
					strcat(instr, rsstr);
					strcat(instr, rtstr);
				}
			}
			else if (!strcmp(s[0], "beq"))// rs,rt,label  s[1]s[2]s[3]
			{
				sscanf(s[1], "r%s", rsstr); //rt
				sscanf(s[2], "r%s", rtstr); //rs
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				strcpy(offsetstr, ToStr16(atoi(s[3])));//label<=>offset
				if (strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(offsetstr) == 16 && is01(offsetstr))
				{
					strcpy(instr, "001111");
					strcat(instr, offsetstr);
					strcat(instr, rsstr);
					strcat(instr, rtstr); //rtstr
				}
			}
			else if (!strcmp(s[0], "bne"))
			{
				sscanf(s[1], "r%s", rsstr); //rt
				sscanf(s[2], "r%s", rtstr); //rs
				strcpy(rsstr, ToStr5(atoi(rsstr)));
				strcpy(rtstr, ToStr5(atoi(rtstr)));
				strcpy(offsetstr, ToStr16(atoi(s[3])));
				if (strlen(rsstr) == 5 && is01(rsstr) &&
					strlen(rtstr) == 5 && is01(rtstr) &&
					strlen(offsetstr) == 16 && is01(offsetstr))
				{
					strcpy(instr, "001111");
					strcat(instr, offsetstr);
					strcat(instr, rsstr);
					strcat(instr, rtstr); //rtstr
				}
			}
			else
			{
				printf("Error!	%s", str);
			}
		}
		else
		{
			printf("Error!	%s", str);
		}

		//���ָ��ͷ����� 
		printf("%s\n", str);
		printf("%s\n", instr);
		fprintf(out, "%s\n", instr);
	}
	fclose(in);
	fclose(out);
	return 0;
}

int is01(char* st)
{
	int stlen = strlen(st);
	for (int i = 0; i < stlen; ++i)
	{
		if (!(st[i] == '0' || st[i] == '1'))
		{
			return 0;
		}
	}

	return 1;
}

char * ToStr5(int n) //����ת��Ϊ�������� 
{
	char st[30];
	strcpy(st, "00000");
	//printf("%s\n%d\n", st, n); 
	for (int i = 4; i >= 0; --i)
	{
		st[i] += (n % 2);
		n /= 2;
	}
	//printf("%s\n", st);
	return st;
}

char * ToStr16(int n) //����ת��Ϊ�������� 
{
	char st[30];
	strcpy(st, "0000000000000000");
	//printf("%s\n%d\n", st, n); 
	for (int i = 15; i >= 0; --i)
	{
		st[i] += (n % 2);
		n /= 2;
	}
	//printf("%s\n", st);
	return st;
}

char * ToStr26(int n) //����ת��Ϊ�������� 
{
	char st[30];
	strcpy(st, "00000000000000000000000000");
	//printf("%s\n%d\n", st, n); 
	for (int i = 25; i >= 0; --i)
	{
		st[i] += (n % 2);
		n /= 2;
	}
	//printf("%s\n", st);
	return st;
}



