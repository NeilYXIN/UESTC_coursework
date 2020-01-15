#include<stdio.h>
#include<string.h>
#include<Windows.h>
#define MAX 1024
#define illegal_char 1
#define illegal_operator 2

bool isLetter(char character)
{
	if ((character >= 'a'&&character <= 'z') || (character >= 'A'&&character <= 'Z'))
		return true;
	else
		return false;
}

bool isNumber(char character)
{
	if (character >= '0'&&character <= '9')
		return true;
	else
		return false;
}

void retract(char& character)
{
	ungetc(character, stdin);
	character = NULL;
}

int isReserved(char* token)
{
	if (!strcmp(token, "begin"))
		return 1;
	else if (!strcmp(token, "end"))
		return 2;
	else if (!strcmp(token, "integer"))
		return 3;
	else if (!strcmp(token, "if"))
		return 4;
	else if (!strcmp(token, "then"))
		return 5;
	else if (!strcmp(token, "else"))
		return 6;
	else if (!strcmp(token, "function"))
		return 7;
	else if (!strcmp(token, "read"))
		return 8;
	else if (!strcmp(token, "write"))
		return 9;
	else
		return 0;
}

int isSymbol()
{
	return 10;
}

int isConst()
{
	return 11;
}

char getfirstchar()
{
	char ch;
	ch = getchar();
	while (1)
	{
		if (ch == '\r' || ch == '\t' || ch == ' ')
		{
			ch = getchar();
		}
		else
		{
			break;
		}
	}
	return ch;
}

void output(const char* token, int kindNum)
{
	printf("%16s %2d\n", token, kindNum);
}

bool error(int line, int errorid)
{
	char* err;
	switch (errorid)
	{
	case illegal_char:
		err = "illegal char!";
		break;
	case illegal_operator:
		err = "illgal operator£¡";
		break;
	default:
		err = "unkown error!";
	}
	if (fprintf(stderr, "***LINE:%d  %s\n", line, err) >= 0)
		return true;
	else
		return false;
}

bool LexAnalyze()
{
	static int line = 1;
	char character;
	char token[17] = "";
	character = getfirstchar();
	switch (character)
	{
	case '\n':
		output("EOLN", 24);
		line++;
		break;
	case EOF:
		output("EOF", 25);
		return false;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		while (isNumber(character))
		{
			char s[2] = { character };
			strcat(token, s);
			character = getchar();
		}
		retract(character);
		int val;
		val = isConst();
		output(token, val);
		break;
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		while (isLetter(character) || isNumber(character))
		{
			char s[2] = { character };
			strcat(token, s);
			character = getchar();
		}
		retract(character);
		int num;
		num = isReserved(token);
		if (num != 0)
			output(token, num);
		else
		{
			int val;
			val = isSymbol();
			output(token, val);
		}
		break;
	case '=':
		output("=", 12);
		break;
	case '<':
		character = getchar();
		if (character == '>')
			output("<>", 13);
		else if (character == '=')
			output("<=", 14);
		else
		{
			retract(character);
			output("<", 15);
		}
		break;
	case '>':
		character = getchar();
		if (character == '=')
			output(">=", 16);
		else
		{
			retract(character);
			output(">", 17);
		}
		break;
	case '-':
		output("-", 18);
		break;
	case '*':
		output("*", 19);
		break;
	case ':':
		character = getchar();
		if (character == '=')
			output(":=", 20);
		else
			error(line, 2);
		break;
	case '(':
		output("(", 21);
		break;
	case ')':
		output(")", 22);
		break;
	case ';':
		output(";", 23);
		break;
	default:
		error(line, 1);
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

void getname(char* in, char* out)
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

bool init()
{
	char* inname = "C:\\ex\\test.pas";
	printf("%s", inname);
	char outname[MAX] = "";
	char errname[MAX] = "";
	char name[MAX] = "";
	char path[MAX] = "";
	getname(inname, name);
	getPath(inname, path);
	strcat(outname, path);
	strcat(outname, name);
	strcat(outname, ".dyd");
	strcat(errname, path);
	strcat(errname, name);
	strcat(errname, ".err");
	if (freopen(inname, "r", stdin) != NULL&&freopen(outname, "w", stdout) != NULL&&freopen(errname, "w", stderr) != NULL)
		return true;
	else
		return false;
}

void main()
{
	init();
	while (LexAnalyze())
	{
	}

	fclose(stdin);
	fclose(stdout);
	fclose(stderr);

	return;
}
