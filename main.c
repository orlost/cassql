#include <stdio.h>

struct token{
	int id;
	char name[20];
};

struct tokenlist{
	struct token tokens[10000];
	struct token unique[1000];
};

void main(int argc, char **argv){
	printf("test\n");
}
