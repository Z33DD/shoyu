SOURCE=main.cpp
TARGET=run

all: build run

build:
	gcc $(SOURCE) -lsodium -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm decrypted.txt encrypted.bin $(TARGET)