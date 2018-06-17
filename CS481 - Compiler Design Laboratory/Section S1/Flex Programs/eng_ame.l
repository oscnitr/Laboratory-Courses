/* English -> American */
%%
"colour"                 { printf("color"); }
"flavour"                 { printf("flavor"); }
"clever"                 { printf("smart"); }
"smart"                 { printf("elegant"); }
"conservative"        { printf("liberal"); }
"bike"                         { printf("byke"); }
"mobile"                 { printf("cell phone"); }
"hat"                         { printf("cap"); }
"english"                 { printf("american"); }
"football"                 { printf("soccer"); }

. { printf("%s", yytext); }
%%
