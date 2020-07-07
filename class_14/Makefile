CXX = g++
CXX_FLAGS = -I include -std=c++11

EXEC = bank
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

ID = 20190044334

all: $(EXEC)

$(EXEC): main.o Agency.o BankAccount.o Client.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) -c src/main.cpp

Agency.o: src/Agency.cpp include/Agency.h
	$(CXX) $(CXX_FLAGS) -c src/Agency.cpp
BankAccount.o: src/BankAccount.cpp include/BankAccount.h
	$(CXX) $(CXX_FLAGS) -c src/BankAccount.cpp
Client.o: src/Client.cpp include/Client.h
	$(CXX) $(CXX_FLAGS) -c src/Client.cpp

clean:
	rm -rf *.o $(EXEC)
