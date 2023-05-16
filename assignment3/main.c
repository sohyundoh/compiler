/*
* main.c -각token에대한출력
* programmer – 도소현, 정유리, 김연희
* date – 04/24/2023
*/
#include<stdio.h>
#include<stdlib.h>
#include"tn.h"
#include"glob.h"

//extern stnum;
extern stindex;
int cErrors = 0;
int cLine = 1;

void main()
{
    enum tokentypes tn;
    // 표머리
    printf("%13s %13s %13s %13s\n", "Line number", "Token type", "ST-index", "Token");
    while ((tn = yylex()) != TEOF) {
        printtoken(tn);
        if (overflow) break;
    }

    // cErrors 개수출력
    if (cErrors == 0) {
        printf("\nNo errors detected");
    }
    else {
        printf("\n%d errors detected", cErrors);
    }
}

//토큰 처리 함수
void printtoken(enum tokentypes tn) {

    switch (tn) {
    case TCONST:
        printf("%13d %13s %13s %13s\n", cLine, "TCONST", "", yytext);
        break;
    case TELSE:
        printf("%13d %13s %13s %13s\n", cLine, "TELSE", "", yytext);
        break;
    case TIF:
        printf("%13d %13s %13s %13s\n", cLine, "TIF", "", yytext);
        break;
    case TINT:
        printf("%13d %13s %13s %13s\n", cLine, "TINT", "", yytext);
        break;
    case TRETURN:
        printf("%13d %13s %13s %13s\n", cLine, "TRETURN", "", yytext);
        break;
    case TVOID:
        printf("%13d %13s %13s %13s\n", cLine, "TVOID", "", yytext);
        break;
    case TWHILE:
        printf("%13d %13s %13s %13s\n", cLine, "TWHILE", "", yytext);
        break;
        //비교연산자
    case TEQUAL:
        printf("%13d %13s %13s %13s\n", cLine, "TEQUAL", "", yytext);
        break;
    case TNOTEQU:
        printf("%13d %13s %13s %13s\n", cLine, "TNOTEQU", "", yytext);
        break;
    case TLESS:
        printf("%13d %13s %13s %13s\n", cLine, "TLESS", "", yytext);
        break;
    case TGREAT:
        printf("%13d %13s %13s %13s\n", cLine, "TGREAT", "", yytext);
        break;
    case TLESSE:
        printf("%13d %13s %13s %13s\n", cLine, "TLESSE", "", yytext);
        break;
    case TGREATE:
        printf("%13d %13s %13s %13s\n", cLine, "TGREATE", "", yytext);
    break;
        //괄호
    case TBRASL:
        printf("%13d %13s %13s %13s\n", cLine, "TBRASL", "", yytext);
        break;
    case TBRASR:
        printf("%13d %13s %13s %13s\n", cLine, "TBRAS", "", yytext);
        break;
    case TBRAMR:
        printf("%13d %13s %13s %13s\n", cLine, "TBRAMR", "", yytext);
        break;
    case TBRAML:
        printf("%13d %13s %13s %13s\n", cLine, "TBRAML", "", yytext);
        break;
    case TBRALL:
        printf("%13d %13s %13s %13s\n", cLine, "TBRALL", "", yytext);
        break;
    case TBRALR:
        printf("%13d %13s %13s %13s\n", cLine, "TBRALR", "", yytext);
        break;

        //논리연산자
    case TAND:
        printf("%13d %13s %13s %13s\n", cLine, "TAND", "", yytext);
        break;
    case TOR:
        printf("%13d %13s %13s %13s\n", cLine, "TOR", "", yytext);
        break;
    case TNOT:
        printf("%13d %13s %13s %13s\n", cLine, "TNOT", "", yytext);
        break;
        //주석처리
    case TANNOT:
        printf("%13d %13s %13s %13s\n", cLine, "annotation", "", yytext);
        break;
        //증감연산자
    case TINC:
        printf("%13d %13s %13s %13s\n", cLine, "TINC", "", yytext);
        break;
    case TDEC:
        printf("%13d %13s %13s %13s\n", cLine, "TDEC", "", yytext);
        break;

        //대입연산자
    case TADDASSIGN:
        printf("%13d %13s %13s %13s\n", cLine, "TADDASSIGN", "", yytext);
        break;
    case TSUBASSIGN:
        printf("%13d %13s %13s %13s\n", cLine, "TSUBASSIGN", "", yytext);
        break;
    case TMULASSIGN:
        printf("%13d %13s %13s %13s\n", cLine, "TMULASSIGN", "", yytext);
        break;
    case TDIVASSIGN:
        printf("%13d %13s %13s %13s\n", cLine, "TDIVASSIGN", "", yytext);
        break;
    case TMODASSIGN:
        printf("%13d %13s %13s %13s\n", cLine, "TMODASSIGN", "", yytext);
        break;
    case TASSIGN:
        printf("%13d %13s %13s %13s\n", cLine, "TASSIGN", "", yytext);
        break;
        //줄넘김
    case TNEWLINE:
        printf("\n");
        break;
        //seperator
    case TCOMMA:
        printf("%13d %13s %13s %13s\n", cLine, "TCOMMA", "", yytext);
        break;
    case TSEMICOLON:
        printf("%13d %13s %13s %13s\n", cLine, "TSEMICOLON", "", yytext);
        break;
        //연산자
    case TADD:
        printf("%13d %13s %13s %13s\n", cLine, "TADD", "", yytext);
        break;
    case TSUB:
        printf("%13d %13s %13s %13s\n", cLine, "TSUB", "", yytext);
        break;
    case TMUL:
        printf("%13d %13s %13s %13s\n", cLine, "TMUL", "", yytext);
        break;
    case TDIV:
        printf("%13d %13s %13s %13s\n", cLine, "TDIV", "", yytext);
        break;
    case TMOD:
        printf("%13d %13s %13s %13s\n", cLine, "TMOD", "", yytext);
        break;

        //띄어쓰기나 tab
    case TBLANK:
        printf("%13d %13s %13s %13s\n", cLine, "TBLANK", "", yytext);
        break;
    case TTAB:
        printf("%13d %13s %13s %13s\n", cLine, "TTAB", "", yytext);
        break;

        //identifier
    case TIDENT:
        if (overflow) {
            printoverflowError();
            cErrors++;
        }
        else printf("%13d %13s %13d %13s\n", cLine, "TIDENT", stindex, yytext);
        break;

        //숫자 처리
    case TNUMBER:
        printf("%13d %13s %13d %13s\n", cLine, "TNUMBER", stindex, yytext);
        //printf("Number : %13s %13s\n", "", yytext);
        break;
	case TRNUMBER;
		printf("%13d %13s %13d %13s\n", cLine, "TRNUMBER", stindex, yytext);
        break;
        // 에러처리
    case TLONGIDERR: printtoolongError(); cErrors++; break;
    case TSWDIGITERR: printillidError(); cErrors++; break;
    case TILLSYMBOLERR: printillspError(); cErrors++; break;
    }
    printf("\n");
}
