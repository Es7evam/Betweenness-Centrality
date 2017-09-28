all:
	g++ main.cpp matrix.cpp criterios.cpp -o main --std=c++11 -Wall
run:
	./main <teste.in
run1:
	./main
