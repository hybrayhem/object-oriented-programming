target:	pegame

main:	boards.h main.h main.cpp
		g++ -std=c++11 -c main.cpp -Wall -Wextra -pedantic

pegame:	main
		g++ -std=c++11 main.cpp -o pegame -Wall -Wextra -pedantic
clean:
		rm pegame main.o