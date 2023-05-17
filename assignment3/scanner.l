%{
/*lex source for Mini C*/
#include "tn.h"

%}
%%
"const"		return(TCONST);
"else"		return(TELSE);
"if"		return(TIF);
"int"		return(TINT);
"return"	return(TRETURN);
"void"		return(TVOID);
"while"		return(TWHILE);
"=="		return(TEQUAL);
"!="		return(TNOTEQU);
">"		return(TLESS);
"<"		return(TGREAT);
"<="		return(TLESSE);
">="		return(TGREATE);
"&&"		return(TAND);
"!"		return(TNOT);
"||"		return(TOR);
"++"		return(TINC);
"--"		return(TDEC);
"+="		return(TADDASSIGN);
"-="		return(TSUBASSIGN);
"*="		return(TMULASSIGN);
"/="		return(TDIVASSIGN);
"%="		return(TMODASSIGN);
"("		return(TBRASL);
")" 		return(TBRASR);
"{" 		return(TBRAML);
"}" 		return(TBRAMR);
"["		return(TBRALL);
"]"		return(TBRALR);
","		return(TCOMMA);
":"		return(TCOLON)
";"		return(TSEMICOLON)
[A-Za-z_][A-Za-z0-9_]*		return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);
[0-9]+"."[0-9]+             return(TRNUMBER);
[a-zA-Z_]([a-zA-Z_]|[0-9])*           {
                            if(yyleng >= 11) return(TLONGIDERR);
                            else{
                                SymbolTable();
                                return(TIDENT);
                            }
                        }
[0-9]([0-9]|[a-zA-Z_])+ 	return(TSWDIGITERR);
.               return(TILLSYMBOLERR);
"/*"([^*]|\*+[^*/])*\**"*"	;
"//".*	;
[ \t\n] ;
.	return(yytext[0]);
 
"+"		return(TADD);
"-"		return(TSUB);
"*"		return(TMUL);
"/"		return(TDIV);
"%"		return(TMOD);
%%

int yywrap() {
	return 1;
}
