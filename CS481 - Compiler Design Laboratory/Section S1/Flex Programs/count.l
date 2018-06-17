%{
int chars = 0;
int words = 0;
int lines = 0;
int punctuations = 0;
%}
%%
[a-zA-Z0-9]+  { words++; chars += strlen(yytext); }
\n         { chars++; lines++; }
[.,:;?"']          { chars++; punctuations++; }
%%
main(int argc, char **argv)
{
  yylex();
  printf("%8d Lines %8d Words %8d Characters %8d Punctuations\n", lines, words, chars,punctuations);
}
