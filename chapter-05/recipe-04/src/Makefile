
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 #-DNDEBUG
INCLUDES = -I$(HOME)/local/include
LDFLAGS = -lgtest_main -lgtest -lpthread
LDPATH = -L$(HOME)/local/lib
VPATH = 

SOURCES = $(shell ls *.cpp)
PROGS = sample

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

$(PROGS): $(SOURCES) $(LIB_SOURCES)
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
