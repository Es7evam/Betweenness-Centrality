all:
	g++ main.cpp matrix.cpp betCentrality.cpp Lista.c -o main --std=c++11
run:
	./main <teste.in
run1:
	./main
