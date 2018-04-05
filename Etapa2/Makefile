etapa1: lex.yy.c parser.tab
	gcc -o etapa1 lex.yy.c
	
lex.yy.c: scanner.l
	lex scanner.l
	
parser.tab:parser.y
	yacc parser.y
	
clean:
	rm lex.yy.c etapa1.exe parser.tab