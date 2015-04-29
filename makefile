main: hashtable.o 
	g++ hashtable.o -o hash-table
	
hashtable.o:hashtable.cpp
	g++ -c hashtable.cpp
	
clean:
	rm -rf *o main
