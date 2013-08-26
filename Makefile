#
#Makefile
#
#This is declaration of variable number.
CXX=g++
CFLAGS=-Wall
PROGRAM=test
SRCS=test.cpp
OBJS=$(SRCS:.cpp=.o)

#
#This is processing
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CFLAGS) -o $(PROGRAM) $(OBJS)

.cpp.o:
	$(CXX) $(CFLAGS) -c $< 

.PHONY: clean
clean:
	$(RM) *~ $(PROGRAM) $(OBJS)
