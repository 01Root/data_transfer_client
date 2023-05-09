client : main.o clientSocket.o File.o
	g++ main.o clientSocket.o File.o -o client 

File.o : ../utils/File.cpp ../utils/File.h
	g++ -c ../utils/File.cpp -o File.o

clientSocket.o : clientSocket.cpp clientSocket.h
	g++ -c clientSocket.cpp -o clientSocket.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -f *.o

