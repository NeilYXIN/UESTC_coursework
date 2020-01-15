#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define MAX_COUNT 1024
#define SIGN_UNDEFINED_ERR 1
#define SIGN_REDEFINED_ERR 2
#define SIGN_EXECUTE_ERR 3
#define NO_SIGN_ERR 4
#define SIGN_RESERVE_ERR 5
#define NO_PARA_ERR 6
/*types��֧�����͵ļ���*/
typedef enum { integer } types;
/*��¼������Ϣ�Ľṹ��*/
typedef struct {
	char vname[17];
	char vproc[17];
	bool vkind;
	types vtype;
	int vlev;
	int vadr;
} varRecord;
/*��¼������Ϣ�Ľṹ��*/
typedef struct {
	char pname[17];
	types ptype;
	int plev;
	int varNum;
	int fadr;
	int ladr;
	int parameter;
	bool parameterIsDefined;
} proRecord;
/**********�ķ�����ʽ����**********
A������				A->B
B���ֳ���			B->begin C;M end
C��˵������		C->DC'
C'->;DC'|��
D��˵�����			D->E|J
E������˵��			E->integer F
F������				F->G
G����ʶ��			G->HG'
G'->HG'|IG'|��
H����ĸ				H->a|...|z|A|...|Z
I������				I->0|1|...|9
J������˵��			J->integer function G(K);L
K������				K->F
L��������			L->begin C;M end
M��ִ������		M->NM'
M'->;NM'|��
N��ִ�����			N->O|P|Q|W
O�������			O->read(F)
P��д���			P->write(F)
Q����ֵ���			Q->F:=R
R���������ʽ		R->SR'
R'->-SR'|��
S����				S->TS'
S'->*TS'|��
T������				T->F|U|Z
U������				U->V
V���޷�������		V->IV'
V'->IV'|��
W���������			W->if X then N else N
X���������ʽ		X->RYR
Y����ϵ�����		Y-><|<=|>|>=|=|<>
Z����������			Z->G(R)
**********************************/
void A();
void B();
void C();
void C_();
void D();
void E();
void F();
void G();
void J();
void K();
void L();
void M();
void M_();
void N();
void O();
void P();
void Q();
void R();
void R_();
void S();
void S_();
void T();
void U();
void W();
void X();
void Y();
void Z();
/*��ʼ���������������ļ���ȡ���ݣ����������ļ�����ʼ��ȫ�ֱ���*/
bool init(int argc, char* argv[]);
/*��������������var��pro�����е�Ԫ���������Ӧ�ļ����������ļ�*/
bool final();
/*���������������ֱ�Ϊ�кš�������ʹ������*/
bool error(int lineNum, int errNum, const char* sign);
/*�������Ŀ¼·�����������б�ܣ�����Ϊ��*/
void getPath(char* in, char* out);
/*����ļ�������������չ*/
void getFilename(char* in, char* out);
/*�����һ����,true��ʾ�ѵ���β��false��ʾ��δ����β*/
bool nextToken();
/*��õ�ǰ���ŵ���һ�ַ�,true��ʾ�ѵ�'\0'*/
bool nextChar();
/*�жϱ����Ƿ��Ѵ���*/
bool isVarExisted(char* vname, char* vproc, bool vkind);
/*�жϹ����Ƿ��Ѵ��ڣ�����Ϊ������*/
bool isProExisted(char* vname);
/*�����һ���ţ�ָ�벻��*/
int getNextToken();

char input[MAX_COUNT][17];//��������ļ����з��ŵ�����
int kind[MAX_COUNT];
int inputCount;//������ŵ�����
int pToken;//ָ��ǰ�������
int pChar;//ָ��ǰ��������еĵ�ǰ�ַ�

varRecord currentVar;//��ŵ�ǰ��������Ϣ
proRecord currentPro;//��ŵ�ǰ���̵���Ϣ

int lineNum;//��ǰ�к�

varRecord var[MAX_COUNT];//��ű�������������
proRecord pro[MAX_COUNT];//��Ź�������������
int varCount;//����������
int proCount;//���̵�����

FILE* inFile;//�����ļ����
FILE* outFile;//����ļ����
FILE* errFile;//�����ļ����
FILE* varFile;//�����ļ����
FILE* proFile;//�����ļ����

			  /*������*/
int main(int argc, char* argv[])
{
	if (init(argc, argv))
	{
		A();
		final();
	}
	return 0;
}
bool init(int argc, char* argv[])
{
	if (argc != 2)
	{
		return false;
	}
	else
	{
		char* inFilename = argv[1];
		char outFilename[MAX_COUNT] = "";
		char errFilename[MAX_COUNT] = "";
		char varFilename[MAX_COUNT] = "";
		char proFilename[MAX_COUNT] = "";
		char filename[MAX_COUNT] = "";
		char path[MAX_COUNT] = "";
		//����ļ�������������չ������·��
		getFilename(inFilename, filename);
		getPath(inFilename, path);
		//��������ļ�ȫ��·��

		strcat(outFilename, path);
		//strcat(outFilename, "\\");
		strcat(outFilename, filename);
		strcat(outFilename, ".dys");
		//���ɴ����ļ�ȫ��·��

		strcat(errFilename, path);
		//strcat(errFilename, "\\");
		strcat(errFilename, filename);
		strcat(errFilename, ".err");
		//���ɱ����ļ�ȫ��·��

		strcat(varFilename, path);
		//strcat(varFilename, "\\");
		strcat(varFilename, filename);
		strcat(varFilename, ".var");
		//���ɹ����ļ�ȫ��·��

		strcat(proFilename, path);
		//strcat(proFilename, "\\");
		strcat(proFilename, filename);
		strcat(proFilename, ".pro");
		//���ļ����
		if ((inFile = fopen(inFilename, "r")) && (outFile = fopen(outFilename, "w")) && (errFile = fopen(errFilename, "w")) && (varFile = fopen(varFilename, "w")) && (proFile = fopen(proFilename, "w")))
		{
			//��ʼ������ָ�롢�ַ�ָ�롢�кš����
			inputCount = 0;
			pToken = 0;
			pChar = 0;
			lineNum = 1;//��ǰ�к�
						//level = 0;//��ǰ���
						//varCountInPro = 0;
			strcpy(currentPro.pname, "");
			currentPro.plev = 0;
			currentPro.varNum = 0;
			currentPro.parameter = -1;

			varCount = 0;
			proCount = 0;
			//��ȡ�����ļ����ݣ���ʼ��input����
			while (!feof(inFile))
			{
				char stringOfLine[MAX_COUNT];
				if (fgets(stringOfLine, MAX_COUNT, inFile))
				{
					char lineString[20] = "";
					strncpy(lineString, stringOfLine, 19);
					char* kindString = strrchr(lineString, ' ');
					kind[inputCount] = atoi(kindString + 1);

					char string[17] = "";
					strncpy(string, stringOfLine, 16);
					char* lastString = strrchr(string, ' ');
					strcpy(input[inputCount], lastString + 1);

					inputCount++;
				}
			}
			return true;
		}
		else
		{
			fclose(inFile);
			fclose(outFile);
			fclose(errFile);
			fclose(varFile);
			fclose(proFile);
			return false;
		}


	}
}
bool final()
{
	for (int i = 0; i < varCount; i++)
	{
		int vkind = var[i].vkind ? 1 : 0;
		char* vtype = (var[i].vtype == integer) ? "integer" : "";
		fprintf(varFile, "%16s %16s %d %s %d %d\n", var[i].vname, var[i].vproc, vkind, vtype, var[i].vlev, var[i].vadr);
	}
	for (int i = 0; i < proCount; i++)
	{
		char* ptype = (pro[i].ptype == integer) ? "integer" : "";
		fprintf(proFile, "%16s %s %d %d %d\n", pro[i].pname, ptype, pro[i].plev, pro[i].fadr, pro[i].ladr);
	}
	if (fseek(inFile, 0, 0) == 0)
	{
		while (!feof(inFile))
			fputc(fgetc(inFile), outFile);

	}

	bool val;
	val = fclose(inFile);
	val = fclose(outFile);
	val = fclose(errFile);
	val = fclose(varFile);
	val = fclose(proFile);
	return val;
}
bool error(int errNum, const char* symbol)
{
	char* errInfo;
	switch (errNum)
	{
	case SIGN_UNDEFINED_ERR:
		fprintf(errFile, "***LINE:%d  %s�����޶���\n", lineNum, input[pToken]);
		break;
	case SIGN_REDEFINED_ERR:
		fprintf(errFile, "***LINE:%d  %s�����ض���\n", lineNum, input[pToken]);
		break;
	case SIGN_EXECUTE_ERR:
		fprintf(errFile, "***LINE:%d  %s������ƥ��ִ�����\n", lineNum, input[pToken]);
		break;
	case NO_SIGN_ERR:
		fprintf(errFile, "***LINE:%d  %s��ȱ��%s\n", lineNum, input[pToken], symbol);
		break;
	case SIGN_RESERVE_ERR:
		errInfo = "�Ա����ֿ�ͷ";
		break;
	case NO_PARA_ERR:
		fprintf(errFile, "***LINE:%d  ȱ���β�%s������\n", lineNum, symbol);
		break;
	default:
		errInfo = "δ֪����";
	}
	return true;
}
void getPath(char* in, char* out)
{
	char* name;
	name = strrchr(in, '\\');
	if (name != NULL)
		strncpy(out, in, strlen(in) - strlen(name) + 1);
	else
		strcpy(out, "");
}
void getFilename(char* in, char* out)
{
	char* fullName;
	char* extension;
	fullName = strrchr(in, '\\');
	extension = strrchr(in, '.');
	if (fullName != NULL)
		strncpy(out, fullName + 1, strlen(fullName) - 1 - strlen(extension));
	else
		strncpy(out, in, strlen(in) - strlen(extension));
}
bool nextToken()
{
	pToken++;
	pChar = 0;
	if (strcmp(input[pToken], "EOF") == 0)
	{
		return true;
	}
	while (strcmp(input[pToken], "EOLN") == 0)
	{
		pToken++;
		lineNum++;
	}
	return false;
}
bool nextChar()
{
	if (input[pToken][pChar] == '\0')
	{
		//nextToken();
		return true;
	}
	pChar++;
	return false;

}
bool isVarExisted(char* vname, char* vproc, bool vkind)
{
	for (int i = 0; i < varCount; i++)
	{
		if ((strcmp(vname, var[i].vname) == 0) && (strcmp(vproc, var[i].vproc) == 0) && (var[i].vkind == vkind))
			return true;
	}
	for (int i = 0; i < proCount; i++)
	{
		if (strcmp(vname, pro[i].pname) == 0)
			return true;
	}
	return false;
}
bool isProExisted(char* vname)
{
	for (int i = 0; i < varCount; i++)
	{
		if (strcmp(vname, var[i].vname) == 0)
			return true;
	}
	for (int i = 0; i < proCount; i++)
	{
		if (strcmp(vname, pro[i].pname) == 0)
			return true;
	}
	return false;
}
int getNextToken()
{
	int pNextToken = pToken + 1;
	while (strcmp(input[pNextToken], "EOLN") == 0)
	{
		pNextToken++;
	}
	return pNextToken;
}

void A()
{
	B();
}
void B()
{
	if (strcmp(input[pToken], "begin") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "begin");
		if (strcmp(input[pToken], "integer") != 0)
		{
			nextToken();
		}
	}
	C();
	if (strcmp(input[pToken], ";") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ";");
		if ((strcmp(input[pToken], "integer") != 0) && (strcmp(input[pToken], "read") != 0) && (strcmp(input[pToken], "write") != 0) && (kind[pToken] != 10))
		{
			nextToken();
		}
	}
	M();
	if (strcmp(input[pToken], "end") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "end");
	}
}
void C()
{
	D();
	C_();
}
void C_()
{

	if (strcmp(input[pToken], ";") == 0 && strcmp(input[getNextToken()], "integer") == 0)
	{
		nextToken();
		D();
		C_();
	}
	else
	{
		if (strcmp(input[pToken], "integer") == 0)
		{
			error(NO_SIGN_ERR, ";");
			D();
			C_();
		}
	}

}
void D()
{
	if (strcmp(input[pToken + 1], "function") == 0)
	{
		J();
	}
	else
	{
		E();
	}
}
void E()
{
	if (strcmp(input[pToken], "integer") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "integer");
		//if (kind[pToken] != 10)
		//{
		nextToken();
		//}
	}
	strcpy(currentVar.vname, input[pToken]);
	strcpy(currentVar.vproc, currentPro.pname);
	if (pToken == currentPro.parameter)
	{
		currentVar.vkind = true;
		currentPro.parameterIsDefined = true;
	}
	else
	{
		currentVar.vkind = false;
	}
	currentVar.vtype = integer;
	currentVar.vlev = currentPro.plev;
	currentVar.vadr = varCount;
	if (isVarExisted(input[pToken], currentPro.pname, currentVar.vkind))//������ڱ���
	{
		error(SIGN_REDEFINED_ERR, NULL);
	}
	else
	{
		if (currentPro.varNum == 0)//�����ǰ�����б�����Ϊ0����ǰ�����ǵ�ǰ���̵ĵ�һ������
		{
			currentPro.fadr = currentVar.vadr;
		}
		currentPro.ladr = currentVar.vadr;//���������һ�������ڱ������е�λ��
		currentPro.varNum++;//�����б�����++
		var[varCount] = currentVar;//��ǰ��������var����
		varCount++;//������++
	}
	F();
}
void F()
{
	G();
}
void G()
{
	if (kind[pToken] == 10)
	{
		nextToken();
	}
	/*
	char* keywords[] = { "begin", "end", "integer", "if", "then", "else", "function", "read", "write" };
	int keywordLength[] = { 5, 3, 7, 2, 4, 4, 8, 4, 5 };
	for (int i = 0; i < 9; i++)
	{
	if (strncmp(input[pToken], keywords[i], keywordLength[i]) == 0)
	{
	error(SIGN_RESERVE_ERR);
	}
	}
	H();
	G_();
	nextToken();*/
}


void J()
{
	proRecord proBackup = currentPro;//���ݵ�ǰ���̣���ƥ����G���̺�ָ�
	if (strcmp(input[pToken], "integer") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "integer");
		if (strcmp(input[pToken], "function") != 0)
		{
			nextToken();
		}
	}
	if (strcmp(input[pToken], "function") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "function");
		if (kind[pToken] != 10)
		{
			nextToken();
		}
	}
	strcpy(currentPro.pname, input[pToken]);
	currentPro.ptype = integer;
	currentPro.plev++;
	currentPro.varNum = 0;
	currentPro.parameterIsDefined = false;
	if (isProExisted(input[pToken]))
	{
		error(SIGN_REDEFINED_ERR, NULL);
	}
	G();
	if (strcmp(input[pToken], "(") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if (kind[pToken] != 10)
		{
			nextToken();
		}
	}
	/*
	strcpy(currentVar.vname, input[pToken]);
	strcpy(currentVar.vproc, currentPro.pname);
	currentVar.vkind = true;
	currentVar.vtype = integer;
	currentVar.vlev = currentPro.plev;
	currentVar.vadr = varCount;
	*/
	currentPro.parameter = pToken;
	K();

	/*
	if (currentPro.varNum == 0)
	{
	currentPro.fadr = currentVar.vadr;
	}
	currentPro.ladr = currentVar.vadr;
	currentPro.varNum++;
	var[varCount] = currentVar;
	varCount++;
	*/
	if (strcmp(input[pToken], ")") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if (strcmp(input[pToken], ";") != 0)
		{
			nextToken();
		}
	}
	if (strcmp(input[pToken], ";") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ";");
		if (strcmp(input[pToken], "begin") != 0)
		{
			nextToken();
		}
	}
	L();
	currentPro = proBackup;//ƥ����G���̺�ָ�ԭ����
}
void K()
{
	F();
}
void L()
{
	if (strcmp(input[pToken], "begin") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "begin");
		if (strcmp(input[pToken], "integer") != 0)
		{
			nextToken();
		}
	}
	C();
	if (!currentPro.parameterIsDefined)
	{
		error(NO_PARA_ERR, input[currentPro.parameter]);
	}
	pro[proCount] = currentPro;//�������������J()��������currentPro����pro��������ΪM�п��ܻ�ʹ�õ�ǰ����(�ݹ�)
	proCount++;
	if (strcmp(input[pToken], ";") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ";");
		if ((strcmp(input[pToken], "integer") != 0) && (strcmp(input[pToken], "read") != 0) && (strcmp(input[pToken], "write") != 0) && (kind[pToken] != 10))
		{
			nextToken();
		}
	}
	M();
	if (strcmp(input[pToken], "end") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "end");
		if ((strcmp(input[pToken], ";") != 0) && (strcmp(input[pToken], "end") != 0))
		{
			nextToken();
		}
	}


	/*if (strcmp(input[pToken], "begin") == 0)
	{
	nextToken();
	C();
	pro[proCount] = currentPro;//�������������J()��������currentPro����pro��������ΪM�п��ܻ�ʹ�õ�ǰ����(�ݹ�)
	proCount++;
	if (strcmp(input[pToken], ";") == 0)
	{
	nextToken();
	M();
	if (strcmp(input[pToken], "end") == 0)
	{
	nextToken();
	}
	else
	{
	error(SIGN_MATCH_ERR);
	}
	}
	else
	{
	error(SIGN_MATCH_ERR);
	}
	}
	else
	{
	error(SIGN_MATCH_ERR);
	}*/

}
void M()
{
	N();
	M_();
}
void M_()
{
	if (strcmp(input[pToken], ";") == 0)
	{
		nextToken();
		N();
		M_();
	}
	else
	{
		//if ((strcmp(input[pToken], "read") == 0) || (strcmp(input[pToken], "write") == 0)||(strcmp(input[pToken], "if") == 0)||(kind[pToken] == 10))
		if ((strcmp(input[pToken], "end") != 0) && (strcmp(input[pToken], "EOF") != 0))
		{
			error(NO_SIGN_ERR, ";");
			N();
			M_();
		}
	}
}
void N()
{
	if (strcmp(input[pToken], "read") == 0)
	{
		O();
	}
	else if (strcmp(input[pToken], "write") == 0)
	{
		P();
	}
	else if (strcmp(input[pToken], "if") == 0)
	{
		W();
	}
	else if (kind[pToken] == 10)
	{
		Q();
	}
	else
	{
		error(SIGN_EXECUTE_ERR, NULL);
		nextToken();
	}
}
void O()
{
	if (strcmp(input[pToken], "read") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "read");
		if (strcmp(input[pToken], "(") != 0)
		{
			nextToken();
		}
	}
	if (strcmp(input[pToken], "(") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if (kind[pToken] != 10)
		{
			nextToken();
		}
	}
	if (!isVarExisted(input[pToken], currentPro.pname, false) && !isVarExisted(input[pToken], currentPro.pname, true))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	F();
	if (strcmp(input[pToken], ")") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if ((strcmp(input[pToken], ";") != 0) && (strcmp(input[pToken], "end") != 0))
		{
			nextToken();
		}
	}
}
void P()
{
	if (strcmp(input[pToken], "write") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "write");
		if (strcmp(input[pToken], "(") != 0)
		{
			nextToken();
		}
	}
	if (strcmp(input[pToken], "(") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if (kind[pToken] != 10)
		{
			nextToken();
		}
	}
	if (!isVarExisted(input[pToken], currentPro.pname, false) && !isVarExisted(input[pToken], currentPro.pname, true))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	F();
	if (strcmp(input[pToken], ")") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if ((strcmp(input[pToken], ";") != 0) && (strcmp(input[pToken], "end") != 0))
		{
			nextToken();
		}
	}
}
void Q()
{
	if (!isVarExisted(input[pToken], currentPro.pname, false) && !isVarExisted(input[pToken], currentPro.pname, true) && !isProExisted(input[pToken]))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	F();
	if (strcmp(input[pToken], ":=") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ":=");
		if ((kind[pToken] != 10) && (kind[pToken] != 11))
		{
			nextToken();
		}
	}
	R();
}
void R()
{
	S();
	R_();
}
void R_()
{
	if (strcmp(input[pToken], "-") == 0)
	{
		nextToken();
		S();
		R_();
	}
	else
	{
		if ((kind[pToken] == 10) || (kind[pToken] == 11))
		{
			S();
			R_();
		}
	}
}
void S()
{
	T();
	S_();
}
void S_()
{
	if (strcmp(input[pToken], "*") == 0)
	{
		nextToken();
		T();
		S_();
	}
	else
	{
		if ((kind[pToken] == 10) || (kind[pToken] == 11))
		{
			T();
			S_();
		}
	}
}
void T()
{
	if (input[pToken][pChar] >= '0' && input[pToken][pChar] <= '9')
	{
		U();
	}
	else if (strcmp(input[getNextToken()], "(") == 0)///////////////////////pToken+1
	{
		Z();
	}
	else
	{
		if (!isVarExisted(input[pToken], currentPro.pname, false) && !isVarExisted(input[pToken], currentPro.pname, true))
		{
			error(SIGN_UNDEFINED_ERR, NULL);
		}
		F();
	}
}
void U()
{
	if (kind[pToken] == 11)
	{
		nextToken();
	}
}

void W()
{
	if (strcmp(input[pToken], "if") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "if");
		if ((kind[pToken] != 10) && (kind[pToken] != 11))
		{
			nextToken();
		}
	}
	X();
	if (strcmp(input[pToken], "then") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "then");
		if ((strcmp(input[pToken], "integer") != 0) && (strcmp(input[pToken], "read") != 0) && (strcmp(input[pToken], "write") != 0) && (kind[pToken] != 10))
		{
			nextToken();
		}
	}
	N();
	if (strcmp(input[pToken], "else") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "else");
		if ((strcmp(input[pToken], "integer") != 0) && (strcmp(input[pToken], "read") != 0) && (strcmp(input[pToken], "write") != 0) && (kind[pToken] != 10))
		{
			nextToken();
		}
	}
	N();
}
void X()
{
	R();
	Y();
	R();
}
void Y()
{
	if (strcmp(input[pToken], "<") == 0 || strcmp(input[pToken], "<=") == 0 || strcmp(input[pToken], ">") == 0 || strcmp(input[pToken], ">=") == 0 || strcmp(input[pToken], "=") == 0 || strcmp(input[pToken], "<>") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "��ϵ�����");
		if ((kind[pToken] != 10) && (kind[pToken] != 11))
		{
			nextToken();
		}
	}
}
void Z()
{
	if (!isProExisted(input[pToken]))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	G();
	if (strcmp(input[pToken], "(") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if ((kind[pToken] != 10) && (kind[pToken] != 11))
		{
			nextToken();
		}
	}
	R();
	if (strcmp(input[pToken], ")") == 0)
	{
		nextToken();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if ((strcmp(input[pToken], "-") != 0) && (strcmp(input[pToken], "*") != 0) && (strcmp(input[pToken], ";") != 0) && (strcmp(input[pToken], "end")))
		{
			nextToken();
		}
	}
}