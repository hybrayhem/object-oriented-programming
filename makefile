target:	gtu

main:	gtu_iterator.h gtu_iterator_const.h gtu_set.h gtu_array.h gtu_vector.h main.cpp
		g++ -std=c++11 -c main.cpp -Wall -Wextra -pedantic

gtu:	main
		g++ -std=c++11 main.cpp -o gtu -Wall -Wextra -pedantic
clean:
		rm gtu *.o