all: test usecase 

main.o: main.cpp hash_table.o
	g++ main.cpp

test: example_test.o
	g++ -o test example_test.o

usecase: main.o
	g++ -o usecase main.o

example_test.o: example_test.cpp hash_table.o
	g++ -c example_test.cpp

hash_table.o: hash_table.cpp
	g++ hash_table.cpp

