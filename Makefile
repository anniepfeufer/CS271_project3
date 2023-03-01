all: test usecase 

test: example_test.o
	g++ -o test example_test.o
	

hash_table.o: hash_table.cpp 
	g++ -c hash_table.cpp


usecase.o: usecase.cpp hash_table.o
	g++ usecase.cpp

example_test.o: example_test.cpp hash_table.o
	g++ -c example_test.cpp

hash_table.o: hash_table.cpp 
	g++ -c hash_table.cpp

