SOURCE = main.cpp
EXECUTABLE = main.exe

all: build run

build:
	g++ -I src/include -L src/lib -o main $(SOURCE) -lmingw32 -lSDL2main -lSDL2

run:
	.\$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)