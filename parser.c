#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"

int typereturn(char *input){
	int i;
	char name[20];
	char c;
	for (i = 0; i < 20; i++){
		name[i] = '\0';
	}
	for (i = 0; i < 20; i++){
		c = input[i];
		if (c != '\0' && c != ' '){
			c = toupper(c);
			name[i] = c;
		}
	}
	if (!strcmp(name,"CREATE")){
		return CREATE;
	}
	if (!strcmp(name,"DROP")){
		return DROP;
	}
	if (!strcmp(name,"ALTER")){
		return ALTER;
	}
	if (!strcmp(name,"DB")){
		return DB;
	}
	if (!strcmp(name,"TABLE")){
		return TABLE;
	}
	if (!strcmp(name,"ROW")){
		return ROW;
	}
	if (!strcmp(name,"COLUMN")){
		return COLUMN;
	}
	if (!strcmp(name,"ADD")){
		return ADD;
	}
	if (!strcmp(name,"SELECT")){
		return SELECT;
	}
	if (!strcmp(name,"UPDATE")){
		return UPDATE;
	}
	if (!strcmp(name,"INSERT")){
		return INSERT;
	}
	if (!strcmp(name,"DELETE")){
		return DELETE;
	}
	if (!strcmp(name,"FROM")){
		return FROM;
	}
	if (!strcmp(name,"WHERE")){
		return WHERE;
	}
	if (!strcmp(name,"*")){
		return ASTERISK;
	}
	if (!strcmp(name,";")){
		return SEMICOLON;
	}
	if (!strcmp(name,"=")){
		return EQUALS;
	}
	return GENERIC;
}

void scanner(tokenlist *tokenlist, char *string){
	int i,j,k,l;
	char c;
	char tokenbuffer[25];
	j = 0;
	k = 0;
	for (i = 0;i < 100;i++){
		c = string[i];
		if (c != ';'){
			tokenbuffer[j] = c;
			if (c == '\0'){
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
		} else {
			if (j){
				sprintf(tokenlist->tokens[k].name,"%s",tokenbuffer);
				tokenlist->tokens[k].id = k;
				k++;
			}
			sprintf(tokenlist->tokens[k].name,"%c",';');
			tokenlist->tokens[k].id = k;
			k++;
			for (j = 0; j < 25; j++){
				tokenbuffer[j] = '\0';
			}
			j = 0;
		}
	}
	for (l = 0; l <= k; l++){
		tokenlist->tokens[l].type = typereturn(tokenlist->tokens[l].name);
		printf("%i:%s ",tokenlist->tokens[l].type,tokenlist->tokens[l].name);
	}
	printf("\n");
}

void lexer(tokenlist *tokenlist, char *string){
	
}

void parser(tokenlist *tokenlist, char *string){
	scanner(tokenlist,string);
	lexer(tokenlist,string);
}

