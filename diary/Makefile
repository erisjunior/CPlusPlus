CXX = g++
CXX_FLAGS = -I include -std=c++11

EXEC = diary
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

ID = 20190044334

all: $(EXEC)

$(EXEC): main.o Diary.o App.o Aux.o Date.o Time.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

main.o: src/main.cpp
	$(CXX) $(CXX_FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(CXX) $(CXX_FLAGS) -c src/Diary.cpp

App.o: src/App.cpp include/App.h
	$(CXX) $(CXX_FLAGS) -c src/App.cpp

Aux.o: src/Aux.cpp include/Aux.h
	$(CXX) $(CXX_FLAGS) -c src/Aux.cpp

Date.o: src/Date.cpp include/Date.h
	$(CXX) $(CXX_FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp include/Time.h
	$(CXX) $(CXX_FLAGS) -c src/Time.cpp

# %.o: %.cpp
# 	$(CXX) $(CXX_FLAGS) -c $^

zip: src/* include/*
	zip $(ID).zip src/* include/*

clean:
	rm -rf *.o $(EXEC)
