#
#Makefile
#
#This is declaration of variable number.
CXX=g++
CFLAGS=-Wall
PROGRAM=test
SRCS=linkedlist.cpp list.cpp
OBJS=$(SRCS:.cpp=.o)

#
#This is processing
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CFLAGS) -o $(PROGRAM) $(OBJS)

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

test.o: test.cpp list.h
list.o: list.cpp list.h


.PHONY: clean
clean:
	$(RM) *~ $(PROGRAM) $(OBJS)
