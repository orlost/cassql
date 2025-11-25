#pragma once
#include <stdio.h>
#include "structs.h"

void scanner(tokenlist *tokenlist, char *string){
	int i,j,k,l;
	char c;
	char tokenbuffer[25];
	j = 0;
	k = 0;
	for (i = 0;i < 100;i++){
		c = string[i];
		printf("%c\n",c);
		tokenbuffer[j] = c;
		if (c == '\0' || c == ';'){
			i = 100;
			sprintf(tokenlist->tokens[k].name,"%s",tokenbuffer);
			tokenlist->tokens[k].id = k;
		} else if (c == ' '){
			sprintf(tokenlist->tokens[k].name,"%s",tokenbuffer);
			tokenlist->tokens[k].id = k;
			k++;
			for (j = 0; j < 25; j++){
				tokenbuffer[j] = '\0';
			}
			j = 0;
		} else {	
			j++;
		}
	}
	for (l = 0; l <= k; l++){
		printf("%s ",tokenlist->tokens[l].name);
	}
	printf("\n");
}

void lexer(tokenlist *tokenlist, char *string){
	
}

void parser(tokenlist *tokenlist, char *string){
	scanner(tokenlist,string);
	lexer(tokenlist,string);
}

