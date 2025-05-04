CC = g++
CFLAGS = -Wall
LIBS = -ltinyxml2
TARGET = target/myprogram.exe
SRC = parsexml.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p target
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f target/myprogram.exe
