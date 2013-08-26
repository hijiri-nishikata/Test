#
#Makefile
#
#This is declaration of variable number.
CXXFLAGS=-Wall
PROGRAM=test
SRCS=linkedlist.cpp list.cpp
OBJS=$(SRCS:.cpp=.o)

#
#This is processing
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(OBJS)

linkedlist.o: linkedlist.cpp list.h
list.o: list.cpp list.h


.PHONY: clean
clean:
	$(RM) *~ $(PROGRAM) $(OBJS)
