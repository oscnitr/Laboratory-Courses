/*Design a machine that will recognize numbers between 0-999. For example: "Two hundred thirty nine" is a correct form of 239 in words.  It should also detect an incorrect input "Twelve hundred twenty two."*/
%{
int yyval,yyerror=0;
%}
%%
"zero"	{ yyval+=0; }
"one"	{ yyval+=1; }
"two"	{ yyval+=2; }
"three"	{ yyval+=3; }
"four"	{ yyval+=4; }
"five"	{ yyval+=5; }
"six"	{ yyval+=6; }
"seven"	{ yyval+=7; }
"eight"	{ yyval+=8; }
"nine"	{ yyval+=9; }
"ten"	{ yyval+=10; }
"eleven"	{ yyval+=11; }
"twelve"	{ yyval+=12; }
"thirteen"	{ yyval+=13; }
"fourteen"	{ yyval+=14; }
"fifteen"	{ yyval+=15; }
"sixteen"	{ yyval+=16; }
"seventeen"	{ yyval+=17; }
"eighteen"	{ yyval+=18; }
"nineteen"	{ yyval+=19; }
"twenty"	{ yyval+=20; }
"thirty"	{ yyval+=30; }
"forty"	{ yyval+=40; }
"fifty"	{ yyval+=50; }
"sixty"	{ yyval+=60; }
"seventy"	{ yyval+=70; }
"eighty"	{ yyval+=80; }
"ninety"	{ yyval+=90; }
"hundred"	{ yyval*=100; }
[ \t]	{}
. {yyerror= 1; }
%%
main(int argc, char **argv)
{
	yylex();
	if(yyerror == 1)
		printf("\nINVALID NUMBER\n");
	else if(yyval>=0 && yyval <=999)
	{
			printf("Number is %d\n",yyval);
			printf("Number is within range\n");
	}	
	else
			printf("Number is out of the range\n");		
	
}
