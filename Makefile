all: test usecase 

test: example_test.o
	g++ -o test example_test.o

usecase: main.o
	g++ -o usecase main.o

example_test.o: example_test.cpp hash_table.cpp
	g++ -c example_test.cpp

main.o: 