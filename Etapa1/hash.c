#include "hash.h"
#include "string.h"


hash * Table[HASHSIZE];

void hashinit(void)
{
	int i;
	for(i=0; i<HASHSIZE; i++)
	{
		Table[i] = 0;
	}
		
}


int hashadress(char *yytext)
{
	int adress=1;
	int i;
	
	for (i=0;i<strlen(yytext);i++)
	{
		adress = (adress+yytext[i]%HASHSIZE+1);
	}	
	return adress-1;
}


hash * hashinsert(int type, char *yytext)
{
	int adress;
	hash * newnode=0;
	adress = hashadress(yytext);
	newnode=(hash*)calloc(1,sizeof(hash));
	newnode->yytext=calloc(strlen(yytext)+1,sizeof(char));
	
	strcpy(newnode->yytext,yytext);
	newnode->next=Table[adress];
	Table[adress]=newnode;
	return newnode;
}

void hashprint()
{
	int i;
	hash* node;
	for(i=0; i<HASHSIZE;i++)
	{
		
		for(node=Table[i];node; node = node->next)
		{			
			printf("Table[%d] has %s \n", i, node->yytext);
		}
	}
	
}

