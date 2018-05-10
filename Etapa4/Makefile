etapa2: parser.tab.o lex.yy.o main.o
	gcc -o etapa4 parser.tab.o lex.yy.o main.o 

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c
	
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l
	
parser.tab.o: parser.tab.c
	gcc -c parser.tab.c 

parser.tab.c: parser.y
	yacc -d -v parser.y

clean:
	rm etapa4.exe lex.yy.c parser.tab.c parser.tab.h *.o