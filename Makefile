CXX=g++
LIBS=
LIBDIR=-L /opt/local/lib
INCDIR=-I/opt/local/include
CFLAGS=-Wall
TARGETS=test
SRCS=test.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGETS) $(OBJS)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(INCDIR) $(LIBDIR) $(LIBS)

.cpp.o:
	$(CXX) $(CFLAGS) -c $< $(INCDIR) $(LIBDIR) $(LIB)

.PHONY: clean
clean:
	$(RM) *~ $(TARGETS) $(OBJS)
