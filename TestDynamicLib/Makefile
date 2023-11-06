iterative_methods.so: iterative_methods.cpp iterative_methods.h

	g++ -c iterative_methods.cpp

main: main.cpp iterative_methods.so

	g++ main.cpp iterative_methods.so -o main
