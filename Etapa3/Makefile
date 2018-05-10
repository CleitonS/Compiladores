etapa3: y.tab.o lex.yy.o main.o
	gcc -o etapa3 y.tab.o lex.yy.o main.o 

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c
	
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: scanner.l
	lex scanner.l
	
y.tab.o: y.tab.c
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d -v parser.y

clean:
	rm etapa3.exe lex.yy.c y.tab.c parser.tab.h *.o
