CXX = g++
CXX_FLAGS = -I include -std=c++11

EXEC = bank
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

ID = 20190044334

all: $(EXEC)

$(EXEC): main.o Agency.o BankAccount.o Client.o ClientPJ.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) -c src/main.cpp

Agency.o: src/Agency.cpp include/Agency.hpp
	$(CXX) $(CXX_FLAGS) -c src/Agency.cpp
BankAccount.o: src/BankAccount.cpp include/BankAccount.hpp
	$(CXX) $(CXX_FLAGS) -c src/BankAccount.cpp
Client.o: src/Client.cpp include/Client.hpp
	$(CXX) $(CXX_FLAGS) -c src/Client.cpp
ClientPJ.o: src/ClientPJ.cpp include/ClientPJ.hpp
	$(CXX) $(CXX_FLAGS) -c src/ClientPJ.cpp

clean:
	rm -rf *.o $(EXEC)
