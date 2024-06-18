CXX = g++

CXXFLAGS = -I/usr/local/include -pthread

LDFLAGS = -L/usr/local/lib -lssh2

BIN=bin

SRC=src

SRCS=$(wildcard $(SRC)/*.cpp)
BINS=$(SRCS:$(SRC)/%.cpp=%)

OBJS = $(SRCS:.cpp=.o)

all: $(BINS)

$(BINS): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BINS) $(OBJS)

.PHONY: all clean
