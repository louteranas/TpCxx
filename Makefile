TESTS=$(wildcard test/*.cpp)
HDRS=$(wildcard src/*.h)
SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp, build/%.o,${SRCS})
BINARIES=$(patsubst test/%.cpp, build/%, ${TESTS})

CXX?=g++
CXXFLAGS+=-std=c++11 -Wall -Wextra

all: ${BINARIES}

build/%: build/%.o ${OBJS}
	${CXX} ${CXXFLAGS} $^ -o $@
	
build/%.o: src/%.cpp ${HDRS}
	${CXX} ${CXXFLAGS} -c $< -o $@
	
build/%.o: test/%.cpp ${OBJS}
	${CXX} ${CXXFLAGS} -I./src -c $< -o $@
	
clean:
	${RM} build/*
	
check: ${BINARIES}
	./build/main
	
