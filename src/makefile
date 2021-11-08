target:	pegame

main:	peg_solitaire.h peg_solitaire.cpp main.cpp
		g++ -std=c++11 -c main.cpp peg_solitaire.cpp -Wall -Wextra -pedantic

pegame:	main
		g++ -std=c++11 main.cpp peg_solitaire.cpp -o pegame -Wall -Wextra -pedantic
clean:
		rm pegame *.o