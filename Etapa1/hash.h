#define HASHSIZE 50007

typedef struct hash_node
{
	int type;
	char *yytext;
	struct hash_node *next;

}hash;

void hashinit(void);
hash * hashinsert(int type, char *yytext);
void hashprint(void);
int hashadress(char *yytext);

