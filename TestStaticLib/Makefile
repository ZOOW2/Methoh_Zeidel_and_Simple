# Specify the compiler
CC = g++

# Specify compilation flags
CFLAGS = -c -Wall

# Specify linker flags
LDFLAGS = -L.-lZeidel

# Specify include directories
INCLUDES = -I.

# Define the executable target
TARGET = Test

# Define the source files
SOURCES = Test.cpp Source.cpp

# Define object files
OBJECTS = Test.o Source.o

# Define the library file
LIBRARY = Zeidel.a

all: $(TARGET)

$(TARGET): $(OBJECTS) $(LIBRARY)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS) $(INCLUDES)

$(LIBRARY): Source.o
	ar crs $(LIBRARY) Source.o

Test.o: Test.cpp
	$(CC) $(CFLAGS) Test.cpp $(INCLUDES)

Source.o: Source.cpp Header.h
	$(CC) $(CFLAGS) Source.cpp $(INCLUDES)

clean:
	rm -f $(OBJECTS) $(LIBRARY) $(TARGET)
