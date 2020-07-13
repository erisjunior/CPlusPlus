CXX = g++
CXX_FLAGS = -I include -std=c++11

EXEC = company

all: $(EXEC)

$(EXEC): main.o Company.o Employee.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) -c src/main.cpp

Company.o: src/Company.cpp include/Company.hpp
	$(CXX) $(CXX_FLAGS) -c src/Company.cpp
Employee.o: src/Employee.cpp include/Employee.hpp
	$(CXX) $(CXX_FLAGS) -c src/Employee.cpp

clean:
	rm -rf *.o $(EXEC)
