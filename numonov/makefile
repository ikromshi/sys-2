# practicing with variables

# Compiler
CC=gcc

# The final executable name
OUTPUT=mediaPlayer

# The list of object files
OBJ=mediaPlayer.o listing1.2.o

# The main target
all: $(OUTPUT)

# Linking the final executable
$(OUTPUT): $(OBJ)
	$(CC) -o $(OUTPUT) $(OBJ)

# Compiling source files to object files
mediaPlayer.o: mediaPlayer.c
	$(CC) -c mediaPlayer.c

listing1.2.o: listing1.2.c
	$(CC) -c listing1.2.c

# Clean-up
clean:
	rm -f $(OUTPUT) $(OBJ)

