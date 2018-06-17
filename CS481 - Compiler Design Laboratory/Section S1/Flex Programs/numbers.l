%%
([0]*[1]*)*	{printf("Binary Number");}
[0-7]+	{printf("Octal Number");}
[0][x][0-9A-F]+ {printf("Hexadecimal");}
[+-][0-9]+ {printf("Signed integer");}
[0-9]+	{printf("Unsigned integer");}
[0-9]+[l]	{printf("Long integer");}
.+ { printf("Remaining string", yytext); }
%%
