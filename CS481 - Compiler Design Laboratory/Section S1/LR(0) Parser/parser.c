#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"closure_goto.h"
#include"parsingtable.h"
#include"first_follow.h"
#include"parse.h"

int main() {
	start();	//Compute closure and goto.

	initialize_first_follow(); //first_follow.h
	compute_first();	//first_follow.h
	compute_follow();	//first_follow.h

	create_parsing_table();		//parsingtable.h

	parse();	//Parse the input string. Present in parse.h

	return 0;
}
