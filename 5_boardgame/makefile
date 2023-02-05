target:	boardgame

main:	board_game2d.h eight_puzzle.h klotski.h peg_solitaire.h main.cpp
		g++ -std=c++11 -c main.cpp board_game2d.cpp eight_puzzle.cpp klotski.cpp peg_solitaire.cpp -Wall -Wextra -pedantic

boardgame:	main
		g++ -std=c++11 main.cpp board_game2d.cpp eight_puzzle.cpp klotski.cpp peg_solitaire.cpp -o boardgame -Wall -Wextra -pedantic
clean:
		rm boardgame *.o