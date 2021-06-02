CXX = g++
TARGET = main
OBJS = main.o table.o util.o 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

main.o: main.cpp
	$(CXX) -c $<

%.o: %.cpp %.h
	$(CXX) -c $<

clean: 
	rm -rf $(TARGET) *.o 

.PHONY: all clean