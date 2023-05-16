#include <stdio.h>
//에러는 줄(line)도 프린트 하기
yyerror(sb)
char *sb;
{
	printf("%s\n",sb);
}