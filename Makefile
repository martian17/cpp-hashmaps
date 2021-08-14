.PHONY: all run clean

SOURCE := byte_hash.cpp
BINARY := byte_hash
DEPS   := 

CFLAGS := -Wall
#LIBS   := $(shell pkg-config --static --cflags --libs $(DEPS))
LIBS   := $(shell pkg-config --cflags --libs $(DEPS))

all: $(BINARY)

$(BINARY): $(SOURCE)
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBS)

run:
	./$(BINARY)

clean:
	rm -f ./$(BINARY)