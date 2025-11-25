#pragma once
#include <stdio.h>
#include <string.h>
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

int typereturn(token *token){
	if (strcmp(token->name,"CREATE")){
		return CREATE;
	}
	if (strcmp(token->name,"DROP")){
		return DROP;
	}
	if (strcmp(token->name,"ALTER")){
		return ALTER;
	}
	if (strcmp(token->name,"DB")){
		return DB;
	}
	if (strcmp(token->name,"TABLE")){
		return TABLE;
	}
	if (strcmp(token->name,"ROW")){
		return ROW;
	}
	if (strcmp(token->name,"COLUMN")){
		return COLUMN;
	}
	if (strcmp(token->name,"ADD")){
		return ADD;
	}
	if (strcmp(token->name,"SELECT")){
		return SELECT;
	}
	if (strcmp(token->name,"UPDATE")){
		return UPDATE;
	}
	if (strcmp(token->name,"INSERT")){
		return INSERT;
	}
	if (strcmp(token->name,"DELETE")){
		return DELETE;
	}
	if (strcmp(token->name,"FROM")){
		return FROM;
	}
	if (strcmp(token->name,"WHERE")){
		return WHERE;
	}
	if (strcmp(token->name,"*")){
		return ASTERISK;
	}
	if (strcmp(token->name,";")){
		return SEMICOLON;
	}
	if (strcmp(token->name,"=")){
		return EQUALS;
	}
}

void lexer(tokenlist *tokenlist, char *string){
	
}

void parser(tokenlist *tokenlist, char *string){
	scanner(tokenlist,string);
	lexer(tokenlist,string);
}

