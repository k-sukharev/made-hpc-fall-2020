CC=gcc
CFLAGS=-c -fopenmp -O3
LIB_SOURCES=vec.cpp matrix.cpp ranking.cpp
LIB_OBJECTS=$(LIB_SOURCES:.cpp=.o)
STATIC_LIB=static_lib.a
EXEC=pagerank_optim

all: $(EXEC)
$(EXEC): $(STATIC_LIB)
	$(CC) -fopenmp main.cpp -lstdc++ $(STATIC_LIB) -o $(EXEC)
$(STATIC_LIB): $(LIB_OBJECTS)
	ar rc $@ $(LIB_OBJECTS)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.o $(STATIC_LIB) $(EXEC)
