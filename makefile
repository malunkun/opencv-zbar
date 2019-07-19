CXX          = g++
CFLAGS    = -Wall 
LDFLAGS  = `pkg-config --cflags --libs opencv zbar`
SRCS = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SRCS))

all:$(TARGETS)
$(TARGETS):$(SRCS)
	$(CXX) -o $@ $< $(LDFLAGS) $(CFLAGS)

clean:
	rm *.o

.PHONY: clean all
