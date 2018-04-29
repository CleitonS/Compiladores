#ifndef _HASH_
#define _HASH_
#define HASHSIZE 50007
#define SYMBOL_TYPE_ID 1
#define SYMBOL_TYPE_LIT_INT 2
#define SYMBOL_TYPE_LIT_FLOAT 3
#define SYMBOL_TYPE_LIT_CHAR 4
#define SYMBOL_TYPE_LIT_STRING 5


typedef struct hash_node
{
	int type;
	char *yytext;
	struct hash_node *next;

}hash;
hash *hashfind(char *yytext);
void hashinit(void);
hash * hashinsert(int type, char *yytext);
void hashprint(void);
int hashadress(char *yytext);

#endif