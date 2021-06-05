CXX = g++
TARGET = main
OBJS = main.o table.o parser.o student.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

main.o: main.cpp table.h parser.h
	$(CXX) -c $<

%.o: %.cpp %.h
	$(CXX) -c $<

clean: 
	rm -rf $(TARGET) *.o 

test: $(TARGET)
	./$(TARGET) tests/test1.txt

.PHONY: all clean