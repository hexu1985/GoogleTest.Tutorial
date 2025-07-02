
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g #-std=c++11
INCLUDES = -I$(HOME)/local/googletest/include
LDFLAGS = -lgtest -lpthread
LDPATH = -L$(HOME)/local/googletest/lib
VPATH = 

SOURCES = $(shell ls *.cpp)
PROGS = sample

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

$(PROGS): $(SOURCES) $(LIB_SOURCES)
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
