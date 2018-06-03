etapa5: parser.tab.o lex.yy.o main.o hash.o ast.o semantic.o tac.o
		gcc -o etapa5 parser.tab.o lex.yy.o main.o hash.o ast.o semantic.o tac.o -std=c99
main.o: main.c
		gcc -c main.c -std=c99
tac.o: tac.c
		gcc -c tac.c -std=c99
hash.o: hash.c
		gcc -c hash.c -std=c99
semantic.o: semantic.c
		gcc -c semantic.c -std=c99
ast.o: ast.c
		gcc -c ast.c -std=c99
lex.yy.o: lex.yy.c
		gcc -c lex.yy.c -std=c99
lex.yy.c: scanner.l
		lex scanner.l
parser.tab.o: parser.tab.c
		gcc -c parser.tab.c -std=c99
parser.tab.c: parser.y
		yacc -d -v parser.y
clean:
	rm etapa4.exe lex.yy.c parser.tab.c parser.tab.h *.o