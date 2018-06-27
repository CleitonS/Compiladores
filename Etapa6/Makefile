etapa6: y.tab.o lex.yy.o main.o hash.o ast.o semantic.o tac.o
		gcc -o etapa6 y.tab.o lex.yy.o main.o hash.o ast.o semantic.o tac.o -std=c99 -Wall
main.o: main.c
		gcc -c main.c -std=c99 
tac.o: tac.c
		gcc -c tac.c -std=c99 -Wall
hash.o: hash.c
		gcc -c hash.c -std=c99 -Wall
semantic.o: semantic.c
		gcc -c semantic.c -std=c99 -Wall
ast.o: ast.c
		gcc -c ast.c -std=c99 -Wall
y.tab.o: y.tab.c
		gcc -c y.tab.c -std=c99
y.tab.c: parser.y
		yacc -dy -v parser.y
lex.yy.o: lex.yy.c
		gcc -c lex.yy.c -std=c99
lex.yy.c: scanner.l
		lex scanner.l
clean:
	rm etapa6.exe lex.yy.c y.tab.c y.tab.h *.o