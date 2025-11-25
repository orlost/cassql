#include <stdio.h>

struct token{
	int id;
	char name[20];
};

struct tokenlist{
	struct token tokens[10000];
	struct token unique[1000];
};

char keywordlist[100][100] = {
	"SELECT",
	"UPDATE",
	"INSERT"	
};

void parser(struct tokenlist *tokenlist, char *string){
	int i,j,k,l;
	char c;
	char tokenbuffer[25];
	j = 0;
	for (i = 0;i < 100;i++){
		c = string[i];
		printf("%c\n",c);
		tokenbuffer[j] = c;
		if (c == '\0' || c == ';'){
			i = 100;
		} else if (c == ' '){
			printf("%s\n",tokenbuffer);
			for (j = 0; j < 25; j++){
				tokenbuffer[j] = '\0';
			}
			j = 0;
		} else {	
			j++;
		}
	}
	printf("\n");
}

void main(int argc, char **argv){
	struct tokenlist tokenlist;
	char buffer[100];
	int i;
	for (i = 0; i < 100; i++){
		buffer[0] = '\0';
	}
	sprintf(buffer,"select * from table;");
	parser(&tokenlist,buffer);
}
