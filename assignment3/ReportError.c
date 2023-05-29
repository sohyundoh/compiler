#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"glob.h"

/*
 * global error print function
 * 에러 포맷에 맞춰 프린트
 * */
void printError() {
    printf("%13dfh", cLine);
    printf("%13s", "**ERROR**");
    printf("%13s", "");
    printf("%s ", yytext);
}

/* printtoolongError
    : identifier too longs*/
void printtoolongError() {
    printError();
    printf("long identifier");
}

/* printillidError
   : identifier illegal format */
void printillidError() {
    printError();
    printf("illegal identifier");
}

/* printillspError
   : illgal character/string */
void printillspError() {
    printError();
    printf("illegal character");
}

/* printoverflowError
   : overflow */
void printoverflowError() {
    printf("%-18s", "***error***");
    printf("%-18s", "");
    printf("OVERFLOW %s", yytext);
}
