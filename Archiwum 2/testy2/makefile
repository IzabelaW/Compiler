program: Parser.y Lexer.l
			bison -d Parser.y
			flex Lexer.l
			g++ -o program lex.yy.c Parser.tab.c  
