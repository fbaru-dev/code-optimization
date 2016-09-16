CXX = icpc
OPTFLAGS = -std=c++11 -O3

DEBUGFLAGS = -g -Wall
OMPFLAGS = -qopenmp

INCLUDES = 
LIBS = 


CXXFLAGS = $(OPTFLAGS) $(DEBUGFLAGS) $(OMPFLAGS)

SOURCES = main.cpp

.SUFFIXES: .o .cpp 

##########################################
OBJSC = $(SOURCES:.cpp=.o)
##########################################

EXEC=mm.x

all: cpu

%.o: %.cpp
	$(info )
	$(info Compiling the object file for CPU: )
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 

cpu: $(OBJSC)
	$(info )
	$(info Linking the CPU executable:)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $(EXEC) $(OBJSC)
	
run: 
	$(info )
	$(info Run the default test case on CPU: )
	./mm.x 
	
clean: 
	rm -f $(OBJSC) mm.x


