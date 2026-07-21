all: program

program: vehicle.o car.o bus.o truck.o fleet.o rental.o main.o
	g++ -std=c++98 -Wall -g -o program vehicle.o car.o bus.o truck.o fleet.o rental.o main.o

vehicle.o: vehicle.cpp
	g++ -std=c++98 -Wall -g -c vehicle.cpp

car.o: car.cpp
	g++ -std=c++98 -Wall -g -c car.cpp

bus.o: bus.cpp
	g++ -std=c++98 -Wall -g -c bus.cpp

truck.o: truck.cpp
	g++ -std=c++98 -Wall -g -c truck.cpp

fleet.o: fleet.cpp
	g++ -std=c++98 -Wall -g -c fleet.cpp

rental.o: rental.cpp
	g++ -std=c++98 -Wall -g -c rental.cpp

main.o: main.cpp
	g++ -std=c++98 -Wall -g -c main.cpp

clean:
	rm -f program vehicle.o car.o bus.o truck.o fleet.o rental.o main.o

gdb: program
	gdb ./program

.PHONY: all clean gdb
