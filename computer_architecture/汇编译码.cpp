//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib> 

int is01(char* st); //判断串的值是否合法为0或者1 
char * ToStr5(int n); //数字转化为二进制数 
char * ToStr16(int n); //数字转化为二进制数 
char * ToStr26(int n); //数字转化为二进制数 

int main()
{
	FILE *out, *in; //输出文件
					//freopen("D:\\in1.txt", "r", stdin);
	in = fopen("D:\\in1.txt", "r");
	out = fopen("D:\\out1.txt ", "w");
	char str[100]; //读取命令字符串 
	char s[25][20]; //这里规定下进程/资源名长度不超过20 
	int ri; //读取字符串命令解析指针 
	int si, sj; //命令s的指针 
	char instr[40]; //指令翻译的机器码	 
	char offsetstr[30]; //offset16位长 
	char rdstr[9], rsstr[9], rtstr[9], jumpstr[30]; //rd rs rt均为5位长
	char shiftstr[9]; //shift5位长 
	char immediatestr[30]; //immediate16位长

						   //while (fgets(str, 50, stdin) != NULL)
	while (fgets(str, 50, in) != NULL)
	{
		//printf("输入指令为:%s", str);   
		//将该行所有命令放于s[][]矩阵中 
		si = 0; //获取命令行初始化 表示有几个命令 
		for (ri = 0; str[ri] != '\n' && str[ri] != '\0' && ri < 50; ++ri)//判断\0是因为在子循环中已经到了\n,外循环一次再+1就到了\0，所以按照这种结构可以删去对\n的判断 
		{
			//printf("ri: %d\n", ri); 
			sj = 0; //命令长度 
			while (str[ri] != ' ' && str[ri] != ',' && str[ri] != '\n')//判断\n是最后一个字符串的特殊情况 
			{
				//printf("ri: %d\n", ri); 
				//printf("(%c)\n", str[ri]); 
				s[si][sj++] = str[ri++];
				//printf("si: %d, sj: %d\n", si, sj); 
			}
			if (str[ri - 1] != ' ')//反向理解，当连续空格时不增加 
			{
				s[si++][sj] = '\0'; //得到一个命令
			}
		}

		/*输出查看指令是否有问题
		for(int ii = 0; ii < si; ++ii)
		{
		printf("%s\n", s[ii]);
		}
		输出查看指令是否有问题*/

		//对s[][]矩阵进行条件判定
		if (si == 2)//只有jump target (其中jump后为26位address) 
		{
			strcpy(jumpstr, ToStr26(atoi(s[1])));
			//首先查看是否是jump指令且address长度为26且address里面值合法 
			if (!strcmp(s[0], "jump") && strlen(jumpstr) == 26 && is01(jumpstr))
			{
				strcpy(instr, "010010");
				//printf("1、%s\n", instr); 
				strcat(instr, jumpstr);
				//printf("2、%s\n", instr); 
			}
			else
			{
				printf("Input error!	%s", str);
			}
		}
		else if (si == 3)
		{
			//load 5位rt,16位offset(5位rs) 
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
			else if (!strcmp(s[0], "sub"))//暂时没有结果，需要搜索确定 
			{

			}
			else if (!strcmp(s[0], "mul"))//暂时没有结果，需要搜索确定
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
			else if (!strcmp(s[0], "sll"))//rd,rt,shift 对应s[1]s[2]s[3]
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
			else if (!strcmp(s[0], "addi"))//rt,rs,imm对应s[1]s[2]s[3]
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
			else if (!strcmp(s[0], "muli"))//待定 
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

		//输出指令和翻译结果 
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

char * ToStr5(int n) //数字转化为二进制数 
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

char * ToStr16(int n) //数字转化为二进制数 
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

char * ToStr26(int n) //数字转化为二进制数 
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



