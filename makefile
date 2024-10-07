# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable name
TARGET = forky

# Object files
OBJ = forky.o pattern1.o pattern2.o

# Default target to build the program
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile the main file (forky.c)
forky.o: forky.c
	$(CC) $(CFLAGS) -c forky.c

# Compile pattern1.c
pattern1.o: pattern1.c
	$(CC) $(CFLAGS) -c pattern1.c

# Compile pattern2.c
pattern2.o: pattern2.c
	$(CC) $(CFLAGS) -c pattern2.c

# Clean target to remove compiled files
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild the entire project
rebuild: clean all
