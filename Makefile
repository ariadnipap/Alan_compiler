.PHONY: clean distclean default

CXX=g++
CXXFLAGS=-Wall

default: alanc

lexer.cpp: lexer.l
	flex -s -o lexer.cpp lexer.l

lexer.o: lexer.cpp lexer.hpp parser.hpp ast.hpp symbol.hpp

parser.hpp parser.cpp: parser.y
	bison -dv -o parser.cpp parser.y

parser.o: parser.cpp lexer.hpp ast.hpp symbol.hpp

alanc: parser.o lexer.o
	$(CXX) $(CXXFLAGS) -o alanc parser.o lexer.o

clean:
	$(RM) lexer.cpp parser.cpp parser.hpp parser.output *.o 

distclean: clean
	$(RM) alanc