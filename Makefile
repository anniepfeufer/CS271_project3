all: test usecase 

test: test_hash_table.o
	g++ -o test test_hash_table.o

hash_table.o: hash_table.cpp 
	g++ -c hash_table.cpp

usecase.o: usecase.cpp hash_table.o
	g++ -c usecase.cpp

usecase: usecase.o main.o
	g++ -o usecase main.o

test_hash_table.o: test_hash_table.cpp hash_table.cpp
	g++ -c test_hash_table.cpp

main.o: main.cpp usecase.cpp
	g++ -c main.cpp
clean:
	rm -f all *.o

