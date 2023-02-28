all: test usecase 

test: example_test.o
	g++ -o test example_test.o
	
main.o: main.cpp hash_table.o usecase.o
	g++ main.cpp

usecase.o: usecase.cpp hash_table.o
	g++ usecase.cpp

example_test.o: example_test.cpp hash_table.o
	g++ -c example_test.cpp

hash_table.o: hash_table.cpp 
	g++ hash_table.cpp

