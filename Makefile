# Make file allows us to use system command Make file which use command from here
# The variables can be any name, not just these, but this is convention

# which file to compile
OBJS = Components/* GameEngine/* States/* Utils/*

# which compiler is used
CC = g++

# Flags for compiler
COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -std=c++11

OBJ_NAME = gg

# target to compile
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
