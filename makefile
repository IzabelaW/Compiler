program: Parser.y Lexer.l
			bison -d Parser.y
			flex Lexer.l
			g++ -std=c++14 -o program lex.yy.c Parser.tab.c  
