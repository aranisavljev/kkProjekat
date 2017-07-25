CC=g++ 
CFLAGS= -std=c++11 -g -Wall

program: lex.yy.o parser.tab.o izraz.o naredba.o
	$(CC) $(CFLAGS) -o $@ $^
parser.tab.o: parser.tab.cpp parser.tab.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
lex.yy.o: lex.yy.c parser.tab.hpp
	$(CC) $(CFLAGS) -Wno-sign-compare -c -o $@ $<
lex.yy.c: lexer.lex
	flex -i $<
naredba.o: naredba.cpp naredba.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
izraz.o: izraz.cpp izraz.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
		rm -rf *~ *tab* lex.yy.* *.o program *.output
