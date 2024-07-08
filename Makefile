CC=g++
all: main
	./main
main:
	$(CC) main.cpp object.cpp snake.cpp apple.cpp graphics.cpp -o main -lGL -lglut
clean:
	rm *.o main
