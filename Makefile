all:
	g++ my_inf_arith.cpp main.cpp -o my_inf_arith

libmy_inf_arith:
	g++ -c my_inf_arith.cpp main.cpp
	ar rcs libmy_inf_arith.a my_inf_arith.o main.o
	rm -f my_inf_arith.o main.o

clean:
	rm -f my_inf_arith *.o libmy_inf_arith.a
