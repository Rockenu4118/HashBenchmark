# Compiler
CC = g++

# Flags
CFLAGS = -I/opt/homebrew/opt/openssl@3.0/include -L/opt/homebrew/opt/openssl@3.0/lib -lssl -lcrypto

# Source files
SRC = main.cpp

# Executable name
TARGET = main

default: $(TARGET)

$(TARGET):
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

clean:
	rm $(TARGET)





