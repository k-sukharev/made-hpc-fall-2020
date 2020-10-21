CC=gcc
CFLAGS=-c
LIB_SOURCES=vec.cpp matrix.cpp
LIB_OBJECTS=$(LIB_SOURCES:.cpp=.o)
STATIC_LIB=static_lib.a
EXEC=matpower

all: $(EXEC)
$(EXEC): $(STATIC_LIB)
	$(CC) -O3 main.cpp -lstdc++ $(STATIC_LIB) -o $(EXEC)
$(STATIC_LIB): $(LIB_OBJECTS)
	ar rc $@ $(LIB_OBJECTS)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.o $(STATIC_LIB) $(EXEC)
