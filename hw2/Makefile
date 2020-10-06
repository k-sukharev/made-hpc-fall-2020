CC=gcc
CFLAGS=-c
LIB_SOURCES=matvec.cpp matmul.cpp
LIB_OBJECTS=$(LIB_SOURCES:.cpp=.o)
STATIC_LIB=static_lib.a
EXECUTABLE=mm_exec

all: $(EXECUTABLE)
$(EXECUTABLE): $(STATIC_LIB)
	$(CC) -g main.cpp -lstdc++ $(STATIC_LIB) -o $@_g
	$(CC) -O3 main.cpp -lstdc++ $(STATIC_LIB) -o $@_O3
$(STATIC_LIB): $(LIB_OBJECTS)
	ar rc $@ $(LIB_OBJECTS)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.o $(EXECUTABLE)_g $(EXECUTABLE)_O3 $(STATIC_LIB)
