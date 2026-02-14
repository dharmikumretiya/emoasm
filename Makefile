CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Iinclude

SRC = src/main.cpp \
	  src/Assembler.cpp \
	  src/Lexer.cpp  \
	  src/Parser.cpp \
	  src/SymbolTable.cpp \
	  src/OpcodeTable.cpp

OUT = emoasm

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT) examples/hello.emo out.obj

clean:
	rm -f $(OUT) out.obj
