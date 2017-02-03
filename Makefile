lab2: main.o Node.o DoubleLinkedList.o OpenHashTable.o
	g++ -std=c++11 -g -Wall main.o Node.o DoubleLinkedList.o OpenHashTable.o -o lab2

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

OpenHashTable.o: OpenHashTable.h OpenHashTable.cpp
	g++ -std=c++11 -g -Wall -c OpenHashTable.cpp

DoubleLinkedList.o: DoubleLinkedList.h DoubleLinkedList.cpp
	g++ -std=c++11 -g -Wall -c DoubleLinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

clean:
	rm *.o lab2
	echo clean done
