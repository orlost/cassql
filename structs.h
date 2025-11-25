#pragma once

typedef struct{
	int id;
	char name[20];
} token;

typedef struct{
	token tokens[10000];
	token unique[1000];
} tokenlist;

char keywordlist[100][100] = {
	"SELECT",
	"UPDATE",
	"INSERT"	
};

