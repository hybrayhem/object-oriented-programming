target:	hw6

main:	iterable.h gtu_iterator.h gtu_iterator_const.h gtu_set.h gtu_array.h gtu_vector.h main.cpp
		g++ -std=c++11 -c main.cpp
#		g++ -std=c++11 -c main.cpp -Wall -Wextra -pedantic

hw6:	main
		g++ -std=c++11 main.cpp -o hw6
#		g++ -std=c++11 main.cpp -o gtu -Wall -Wextra -pedantic
clean:
		rm hw6 *.o *.gch