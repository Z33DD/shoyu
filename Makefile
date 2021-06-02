SOURCE=encrypt.cpp
TARGET=run

all: build run

build:
	gcc $(SOURCE) -lsodium -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm decypted.txt encrypted.bin $(TARGET)