CC=g++
all: main
	./main
main:
	$(CC) main.cpp snake.cpp graphics.cpp -o main -lGL -lglut
clean:
	rm *.o main
