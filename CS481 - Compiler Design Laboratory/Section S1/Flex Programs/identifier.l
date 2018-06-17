
%%
[a-zA-Z_][a-zA-Z0-9_]*	{ printf("%s - Valid identifier",yytext); }
[0-9][a-zA-Z0-9_]*		{ printf("%s - Invalid identifier",yytext); }
([a-zA-Z0-9_]*[.,:;*\-+@&$#/"\"""\'"<>!~`^?|%]+[a-zA-Z0-9_]*)* { printf("%s - Invalid symbols",yytext); }
. { printf("%s", yytext); }
%%
main(int argc, char **argv)
{
  yylex();
  printf("%s",yytext);
}
