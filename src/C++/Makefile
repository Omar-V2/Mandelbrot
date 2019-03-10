CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-Wall -std=c++17
LDFLAG=-lm

rendermac: mandel_render.cpp
	$(CXX) $(CFGLAGS) $(LDFLAGS) -o mac_render mandel_render.cpp
clean:
	$(RM) mac_render