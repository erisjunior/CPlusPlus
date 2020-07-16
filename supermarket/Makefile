CXX = g++
CXX_FLAGS = -I include -std=c++11

EXEC = supermarket

all: $(EXEC)

$(EXEC): main.o App.o Client.o Market.o Product.o Supplier.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.hpp include/vector_supermarket.hpp
	$(CXX) $(CXX_FLAGS) -c src/App.cpp
Client.o: src/Client.cpp include/Client.hpp include/vector_supermarket.hpp
	$(CXX) $(CXX_FLAGS) -c src/Client.cpp
Market.o: src/Market.cpp include/Market.hpp include/vector_supermarket.hpp
	$(CXX) $(CXX_FLAGS) -c src/Market.cpp
Product.o: src/Product.cpp include/Product.hpp
	$(CXX) $(CXX_FLAGS) -c src/Product.cpp
Supplier.o: src/Supplier.cpp include/Supplier.hpp include/vector_supermarket.hpp
	$(CXX) $(CXX_FLAGS) -c src/Supplier.cpp

clean:
	rm -rf *.o $(EXEC)
