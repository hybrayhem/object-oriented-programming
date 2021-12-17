target:	boardgame

main:	board_game2d.h eight_puzzle.h main.cpp
		g++ -std=c++11 -c main.cpp board_game2d.cpp peg_solitaire.cpp -Wall -Wextra -pedantic

boardgame:	main
		g++ -std=c++11 main.cpp board_game2d.cpp eight_puzzle.cpp -o boardgame -Wall -Wextra -pedantic
clean:
		rm boardgame *.o