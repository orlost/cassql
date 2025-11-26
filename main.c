#include <stdio.h>
#include "structs.h"
#include "parser.c"

void main(int argc, char **argv){
	tokenlist tokenlist;
	char buffer[100];
	int i;
	for (i = 0; i < 100; i++){
		buffer[0] = '\0';
	}
	sprintf(buffer,"select * from table ;");
	parser(&tokenlist,buffer);
}
