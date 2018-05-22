etapa2: y.tab.o lex.yy.o main.o
	gcc -o etapa4 y.tab.o lex.yy.o main.o -Wall

main.o: main.c
	gcc -c main.c -Wall

hash.o: hash.c
	gcc -c hash.c -Wall
	
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -Wall

lex.yy.c: scanner.l
	lex scanner.l
	
y.tab.o: y.tab.c
	gcc -c y.tab.c -Wall

y.tab.c: parser.y
	yacc -d parser.y

clean:
	rm etapa4.exe lex.yy.c y.tab.c y.tab.h *.o
