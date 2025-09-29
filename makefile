main:	
	g++ -std=c++11 -g *.cpp -o main

clean:
	rm -f *.o main

run:	main
	./main

debug:
	gdb ./main

coverage:	
	valgrind --leak-check=full ./main	