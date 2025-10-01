
CC = g++
RELEASE_FLAGS = -O2 -Wall -DNDEBUG -std=c++11
DEBUG_FLAGS = -g -O0 -Wall -std=c++11
RELEASE_EXEC = calculator
DEBUG_EXEC = calculator-dbg
SOURCE = calculator.cpp
LIBS = -lboost_program_options -lm

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): $(SOURCE)
	$(CC) $(DEBUG_FLAGS) $(SOURCE) -o $(DEBUG_EXEC) $(LIBS)

release: $(RELEASE_EXEC)
	$(CC) $(RELEASE_FLAGS) $(SOURCE) -o $(RELEASE_EXEC) $(LIBS)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
