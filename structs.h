#pragma once

enum tokentype {GENERIC, CREATE, DROP, ALTER, DB, TABLE, ROW, COLUMN, ADD, SELECT, UPDATE, INSERT, DELETE, FROM, WHERE, ASTERISK, SEMICOLON, EQUALS};

typedef struct{
	int id;
	int type;
	char name[20];
} token;

typedef struct{
	token tokens[10000];
	token unique[1000];
} tokenlist;

char keywordlist[100][100] = {
	"CREATE",
	"DROP",
	"ALTER",
	"DB",
	"TABLE",
	"ROW",
	"COLUMN",

	"ADD",


	"SELECT",
	"UPDATE",
	"INSERT",
	"DELETE",

	"FROM",
	"WHERE",
	
	"*"	
};

