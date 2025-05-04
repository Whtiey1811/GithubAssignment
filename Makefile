CC = g++
CFLAGS = -Wall -std=c++11
LIBS = -ltinyxml2
TARGET = parsexml.exe
SRC = main.cpp parsexml.cpp
OBJ = $(SRC:.cpp=.o)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
