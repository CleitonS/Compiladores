#ifndef _HASHC_
#define _HASHC_
#include "hash.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>


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

hash * hashfind(char *yytext){
	int adress = hashadress(yytext);
	hash *node;
	for(node=Table[adress];node; node = node->next)
	{
		if (strcmp(node->yytext, yytext) == 0)
			return node;
	}
	return 0;
}


hash * hashinsert(int type, char *yytext)
{
	int adress;
	hash * newnode=0;
	if (hashfind(yytext) != 0)
		return hashfind(yytext);

	adress = hashadress(yytext);
	newnode=(hash*)calloc(1,sizeof(hash));
	newnode->type = type;
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

#endif