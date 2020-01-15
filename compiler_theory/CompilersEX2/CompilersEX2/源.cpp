#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define MAX 1024
#define SIGN_UNDEFINED_ERR 1
#define SIGN_REDEFINED_ERR 2
#define SIGN_EXE_ERR 3
#define NO_SIGN_ERR 4
#define SIGN_RESERVED_ERR 5
#define NO_PARAMETER_ERR 6

typedef enum { integer } types;

typedef struct {
	char vname[17];
	char vprocc[17];
	bool vkind;
	types vtype;
	int vlev;
	int vadr;
} varRecord;

typedef struct {
	char pname[17];
	types ptype;
	int plev;
	int varNum;
	int fadr;
	int ladr;
	int parameter;
	bool parameterIsDefined;
} procRecord;

void PROGRAM();
void SUBPROGRAM();
void STATETABLE();
void STATETABLE_();
void STATEMENT();
void VARSTATE();
void VAR();
void IDENTIFIER();
void FUNCTIONSTATE();
void PARAMETER();
void FUNCTION();
void EXETABLE();
void EXETABLE_();
void EXE();
void READ();
void WRITE();
void ASSIGN();
void ALGORITHM();
void ALGORITHM_();
void OBJECT();
void OBJECT_();
void FACTOR();
void CONSTANT();
void CONSENTENCE();
void CONDITION();
void OPERATOR();
void CALLFUNC();

char input[MAX][17];
int kind[MAX];
int inputCount;
int pwords;
int pChar;
varRecord currentVar;
procRecord currentProc;
int lineNum;
varRecord var[MAX];
procRecord proc[MAX];
int varCount;
int procCount;

FILE* inFile;
FILE* outFile;
FILE* errFile;
FILE* varFile;
FILE* procFile;

bool final()
{
	for (int i = 0; i < varCount; i++)
	{
		int vkind = var[i].vkind ? 1 : 0;
		char* vtype = (var[i].vtype == integer) ? "integer" : "";
		fprintf(varFile, "%16s %16s %d %s %d %d\n", var[i].vname, var[i].vprocc, vkind, vtype, var[i].vlev, var[i].vadr);
	}
	for (int i = 0; i < procCount; i++)
	{
		char* ptype = (proc[i].ptype == integer) ? "integer" : "";
		fprintf(procFile, "%16s %s %d %d %d\n", proc[i].pname, ptype, proc[i].plev, proc[i].fadr, proc[i].ladr);
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
	val = fclose(procFile);
	return val;
}

bool error(int errNum, const char* symbol)
{
	char* errInfo;
	switch (errNum)
	{
	case SIGN_UNDEFINED_ERR:
		fprintf(errFile, "***LINE:%d  %s UNDEFINED SIGN\n", lineNum, input[pwords]);
		break;
	case SIGN_REDEFINED_ERR:
		fprintf(errFile, "***LINE:%d  %s REDEFINED SIGN\n", lineNum, input[pwords]);
		break;
	case SIGN_EXE_ERR:
		fprintf(errFile, "***LINE:%d  %s NO MATCH\n", lineNum, input[pwords]);
		break;
	case NO_SIGN_ERR:
		fprintf(errFile, "***LINE:%d  %s LACK %s\n", lineNum, input[pwords], symbol);
		break;
	case SIGN_RESERVED_ERR:
		errInfo = "ILLEGAL BEGINNING words";
		break;
	case NO_PARAMETER_ERR:
		fprintf(errFile, "***LINE:%d LACK STATEMENT OF PARAMETER %s\n", lineNum, symbol);
		break;
	default:
		errInfo = "UNKOWN ERROR";
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

bool nextwords()
{
	pwords++;
	pChar = 0;
	if (strcmp(input[pwords], "EOF") == 0)
	{
		return true;
	}
	while (strcmp(input[pwords], "EOLN") == 0)
	{
		pwords++;
		lineNum++;
	}
	return false;
}

bool nextChar()
{
	if (input[pwords][pChar] == '\0')
	{
		return true;
	}
	pChar++;
	return false;
}

bool isVarExisted(char* vname, char* vprocc, bool vkind)
{
	for (int i = 0; i < varCount; i++)
	{
		if ((strcmp(vname, var[i].vname) == 0) && (strcmp(vprocc, var[i].vprocc) == 0) && (var[i].vkind == vkind))
			return true;
	}
	for (int i = 0; i < procCount; i++)
	{
		if (strcmp(vname, proc[i].pname) == 0)
			return true;
	}
	return false;
}

bool isProcExisted(char* vname)
{
	for (int i = 0; i < varCount; i++)
	{
		if (strcmp(vname, var[i].vname) == 0)
			return true;
	}
	for (int i = 0; i < procCount; i++)
	{
		if (strcmp(vname, proc[i].pname) == 0)
			return true;
	}
	return false;
}

int getNextwords()
{
	int pNextwords = pwords + 1;
	while (strcmp(input[pNextwords], "EOLN") == 0)
	{
		pNextwords++;
	}
	return pNextwords;
}

void init()
{
		char* inFilename = "c:\\ex\\test.dyd";
		char outFilename[MAX] = "";
		char errFilename[MAX] = "";
		char varFilename[MAX] = "";
		char procFilename[MAX] = "";
		char filename[MAX] = "";
		char path[MAX] = "";
		getFilename(inFilename, filename);
		getPath(inFilename, path);
		strcat(outFilename, path);
		strcat(outFilename, filename);
		strcat(outFilename, ".dys");
		strcat(errFilename, path);
		strcat(errFilename, filename);
		strcat(errFilename, ".err");
		strcat(varFilename, path);
		strcat(varFilename, filename);
		strcat(varFilename, ".var");
		strcat(procFilename, path);
		strcat(procFilename, filename);
		strcat(procFilename, ".pro");
		if ((inFile = fopen(inFilename, "r")) && (outFile = fopen(outFilename, "w")) && (errFile = fopen(errFilename, "w")) && (varFile = fopen(varFilename, "w")) && (procFile = fopen(procFilename, "w")))
		{
			inputCount = 0;
			pwords = 0;
			pChar = 0;
			lineNum = 1;
			strcpy(currentProc.pname, "");
			currentProc.plev = 0;
			currentProc.varNum = 0;
			currentProc.parameter = -1;
			varCount = 0;
			procCount = 0;
			while (!feof(inFile))
			{
				char stringOfLine[MAX];
				if (fgets(stringOfLine, MAX, inFile))
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
		}
}

void PROGRAM()
{
	SUBPROGRAM();
}

void SUBPROGRAM()
{
	if (strcmp(input[pwords], "begin") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "begin");
		if (strcmp(input[pwords], "integer") != 0)
		{
			nextwords();
		}
	}
	STATETABLE();
	if (strcmp(input[pwords], ";") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ";");
		if ((strcmp(input[pwords], "integer") != 0) && (strcmp(input[pwords], "read") != 0) && (strcmp(input[pwords], "write") != 0) && (kind[pwords] != 10))
		{
			nextwords();
		}
	}
	EXETABLE();
	if (strcmp(input[pwords], "end") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "end");
	}
}
void STATETABLE()
{
	STATEMENT();
	STATETABLE_();
}
void STATETABLE_()
{

	if (strcmp(input[pwords], ";") == 0 && strcmp(input[getNextwords()], "integer") == 0)
	{
		nextwords();
		STATEMENT();
		STATETABLE_();
	}
	else
	{
		if (strcmp(input[pwords], "integer") == 0)
		{
			error(NO_SIGN_ERR, ";");
			STATEMENT();
			STATETABLE_();
		}
	}
}

void STATEMENT()
{
	if (strcmp(input[pwords + 1], "function") == 0)
	{
		FUNCTIONSTATE();
	}
	else
	{
		VARSTATE();
	}
}

void VARSTATE()
{
	if (strcmp(input[pwords], "integer") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "integer");
		nextwords();
	}
	strcpy(currentVar.vname, input[pwords]);
	strcpy(currentVar.vprocc, currentProc.pname);
	if (true == currentVar.vkind)
	{
		
		currentProc.parameterIsDefined = true;
	}
	else
	{
		currentVar.vkind = false;
	}
	currentVar.vtype = integer;
	currentVar.vlev = currentProc.plev;
	currentVar.vadr = varCount;
	if (isVarExisted(input[pwords], currentProc.pname, currentVar.vkind))
	{
		error(SIGN_REDEFINED_ERR, NULL);
	}
	else
	{
		if (currentProc.varNum == 0)//如果当前过程中变量数为0，则当前变量是当前过程的第一个变量
		{
			currentProc.fadr = currentVar.vadr;
		}
		currentProc.ladr = currentVar.vadr;//过程中最后一个变量在变量表中的位置
		currentProc.varNum++;//过程中变量数++
		var[varCount] = currentVar;//当前变量存入var数组
		varCount++;//变量数++
	}
	VAR();
}

void VAR()
{
	IDENTIFIER();
}
void IDENTIFIER()
{
	if (kind[pwords] == 10)
	{
		
		nextwords();
		currentVar.vkind = true;
	}
}

void FUNCTIONSTATE()
{
	procRecord procBackup = currentProc;
	if (strcmp(input[pwords], "integer") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "integer");
		if (strcmp(input[pwords], "function") != 0)
		{
			nextwords();
		}
	}
	if (strcmp(input[pwords], "function") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "function");
		if (kind[pwords] != 10)
		{
			nextwords();
		}
	}
	strcpy(currentProc.pname, input[pwords]);
	currentProc.ptype = integer;
	currentProc.plev++;
	currentProc.varNum = 0;
	currentProc.parameterIsDefined = false;
	if (isProcExisted(input[pwords]))
	{
		error(SIGN_REDEFINED_ERR, NULL);
	}
	IDENTIFIER();
	if (strcmp(input[pwords], "(") == 0)
	{
		
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if (kind[pwords] != 10)
		{
			nextwords();
		}
	}
	
	currentProc.parameter = pwords;
	PARAMETER();

	if (strcmp(input[pwords], ")") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if (strcmp(input[pwords], ";") != 0)
		{
			nextwords();
		}
	}
	if (strcmp(input[pwords], ";") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ";");
		if (strcmp(input[pwords], "begin") != 0)
		{
			nextwords();
		}
	}
	FUNCTION();
	currentProc = procBackup;//匹配完IDENTIFIER过程后恢复原过程
}

void PARAMETER()
{
	VAR();
}

void FUNCTION()
{
	if (strcmp(input[pwords], "begin") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "begin");
		if (strcmp(input[pwords], "integer") != 0)
		{
			nextwords();
		}
	}
	STATETABLE();
	if (!currentProc.parameterIsDefined)
	{
		error(NO_PARAMETER_ERR, input[currentProc.parameter]);
	}
	proc[procCount] = currentProc;
	procCount++;
	if (strcmp(input[pwords], ";") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ";");
		if ((strcmp(input[pwords], "integer") != 0) && (strcmp(input[pwords], "read") != 0) && (strcmp(input[pwords], "write") != 0) && (kind[pwords] != 10))
		{
			nextwords();
		}
	}
	EXETABLE();
	if (strcmp(input[pwords], "end") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "end");
		if ((strcmp(input[pwords], ";") != 0) && (strcmp(input[pwords], "end") != 0))
		{
			nextwords();
		}
	}
}

void EXETABLE()
{
	EXE();
	EXETABLE_();
}

void EXETABLE_()
{
	if (strcmp(input[pwords], ";") == 0)
	{
		nextwords();
		EXE();
		EXETABLE_();
	}
	else
	{
		if ((strcmp(input[pwords], "end") != 0) && (strcmp(input[pwords], "EOF") != 0))
		{
			error(NO_SIGN_ERR, ";");
			EXE();
			EXETABLE_();
		}
	}
}

void EXE()
{
	if (strcmp(input[pwords], "read") == 0)
	{
		READ();
	}
	else if (strcmp(input[pwords], "write") == 0)
	{
		WRITE();
	}
	else if (strcmp(input[pwords], "if") == 0)
	{
		CONSENTENCE();
	}
	else if (kind[pwords] == 10)
	{
		ASSIGN();
	}
	else
	{
		error(SIGN_EXE_ERR, NULL);
		nextwords();
	}
}

void READ()
{
	if (strcmp(input[pwords], "read") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "read");
		if (strcmp(input[pwords], "(") != 0)
		{
			nextwords();
		}
	}
	if (strcmp(input[pwords], "(") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if (kind[pwords] != 10)
		{
			nextwords();
		}
	}
	if (!isVarExisted(input[pwords], currentProc.pname, false) && !isVarExisted(input[pwords], currentProc.pname, true))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	VAR();
	if (strcmp(input[pwords], ")") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if ((strcmp(input[pwords], ";") != 0) && (strcmp(input[pwords], "end") != 0))
		{
			nextwords();
		}
	}
}

void WRITE()
{
	if (strcmp(input[pwords], "write") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "write");
		if (strcmp(input[pwords], "(") != 0)
		{
			nextwords();
		}
	}
	if (strcmp(input[pwords], "(") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if (kind[pwords] != 10)
		{
			nextwords();
		}
	}
	if (!isVarExisted(input[pwords], currentProc.pname, false) && !isVarExisted(input[pwords], currentProc.pname, true))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	VAR();
	if (strcmp(input[pwords], ")") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if ((strcmp(input[pwords], ";") != 0) && (strcmp(input[pwords], "end") != 0))
		{
			nextwords();
		}
	}
}

void ASSIGN()
{
	if (!isVarExisted(input[pwords], currentProc.pname, false) && !isVarExisted(input[pwords], currentProc.pname, true) && !isProcExisted(input[pwords]))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	VAR();
	if (strcmp(input[pwords], ":=") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ":=");
		if ((kind[pwords] != 10) && (kind[pwords] != 11))
		{
			nextwords();
		}
	}
	ALGORITHM();
}

void ALGORITHM()
{
	OBJECT();
	ALGORITHM_();
}

void ALGORITHM_()
{
	if (strcmp(input[pwords], "-") == 0)
	{
		nextwords();
		OBJECT();
		ALGORITHM_();
	}
	else
	{
		if ((kind[pwords] == 10) || (kind[pwords] == 11))
		{
			OBJECT();
			ALGORITHM_();
		}
	}
}

void OBJECT()
{
	FACTOR();
	OBJECT_();
}

void OBJECT_()
{
	if (strcmp(input[pwords], "*") == 0)
	{
		nextwords();
		FACTOR();
		OBJECT_();
	}
	else
	{
		if ((kind[pwords] == 10) || (kind[pwords] == 11))
		{
			FACTOR();
			OBJECT_();
		}
	}
}

void FACTOR()
{
	if (input[pwords][pChar] >= '0' && input[pwords][pChar] <= '9')
	{
		CONSTANT();
	}
	else if (strcmp(input[getNextwords()], "(") == 0)
	{
		CALLFUNC();
	}
	else
	{
		if (!isVarExisted(input[pwords], currentProc.pname, false) && !isVarExisted(input[pwords], currentProc.pname, true))
		{
			error(SIGN_UNDEFINED_ERR, NULL);
		}
		VAR();
	}
}

void CONSTANT()
{
	if (kind[pwords] == 11)
	{
		nextwords();
	}
}

void CONSENTENCE()
{
	if (strcmp(input[pwords], "if") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "if");
		if ((kind[pwords] != 10) && (kind[pwords] != 11))
		{
			nextwords();
		}
	}
	CONDITION();
	if (strcmp(input[pwords], "then") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "then");
		if ((strcmp(input[pwords], "integer") != 0) && (strcmp(input[pwords], "read") != 0) && (strcmp(input[pwords], "write") != 0) && (kind[pwords] != 10))
		{
			nextwords();
		}
	}
	EXE();
	if (strcmp(input[pwords], "else") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "else");
		if ((strcmp(input[pwords], "integer") != 0) && (strcmp(input[pwords], "read") != 0) && (strcmp(input[pwords], "write") != 0) && (kind[pwords] != 10))
		{
			nextwords();
		}
	}
	EXE();
}

void CONDITION()
{
	ALGORITHM();
	OPERATOR();
	ALGORITHM();
}

void OPERATOR()
{
	if (strcmp(input[pwords], "<") == 0 || strcmp(input[pwords], "<=") == 0 || strcmp(input[pwords], ">") == 0 || strcmp(input[pwords], ">=") == 0 || strcmp(input[pwords], "=") == 0 || strcmp(input[pwords], "<>") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "关系运算符");
		if ((kind[pwords] != 10) && (kind[pwords] != 11))
		{
			nextwords();
		}
	}
}

void CALLFUNC()
{
	if (!isProcExisted(input[pwords]))
	{
		error(SIGN_UNDEFINED_ERR, NULL);
	}
	IDENTIFIER();
	if (strcmp(input[pwords], "(") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, "(");
		if ((kind[pwords] != 10) && (kind[pwords] != 11))
		{
			nextwords();
		}
	}
	ALGORITHM();
	if (strcmp(input[pwords], ")") == 0)
	{
		nextwords();
	}
	else
	{
		error(NO_SIGN_ERR, ")");
		if ((strcmp(input[pwords], "-") != 0) && (strcmp(input[pwords], "*") != 0) && (strcmp(input[pwords], ";") != 0) && (strcmp(input[pwords], "end")))
		{
			nextwords();
		}
	}
}

void main()
{
	init();
	PROGRAM();
	final();
	return ;
}