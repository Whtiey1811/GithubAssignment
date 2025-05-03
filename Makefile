CC = g++
CFLAGS = -Wall
LIBS = -ltinyxml2
TARGET = parsexml
SRC = parsexml.cpp

$(TARGET): $(SRC)
    $(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
    rm -f $(TARGET)
