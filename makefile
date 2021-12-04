target:	dayofyear

main:	dayofyear.h dayofyear.cpp main.cpp
		g++ -std=c++11 -c main.cpp dayofyear.cpp -Wall -Wextra -pedantic

dayofyear:	main
		g++ -std=c++11 main.cpp dayofyear.cpp -o dayofyear -Wall -Wextra -pedantic
clean:
		rm dayofyear *.o