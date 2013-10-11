SDL_CFLAGS := $(shell sdl-config --cflags)
SDL_LDFLAGS := $(shell sdl-config --libs)
STD_FLAGS = -W -Wall -ansi -pedantic

CPPSOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

all: init

init: $(CPPSOURCES:.cpp=.o)
	rm main.o
	g++ -lSDL_net -lSDL -o $@ main.cpp $(subst main.o, ,$^) $(STD_FLAGS) $(SDL_LDFLAGS) $(SDL_CFLAGS)

%.o: %.cpp $(HEADERS)
	g++ $(STD_FLAGS) -c $^ $(SDL_LDFLAGS) $(SDL_CFLAGS) $(STD_FLAGS) -lSDL -lSDL_net
	
clean:
	-rm -rf *.o networklib.a *~

# -include $(CPPSOURCES: .cpp= .d)
# %.d: %.cpp
# 	g++ $< -MM -MT '$*.o $*.d' -MD $(SDL_CFLAGS) $(SDL_LDFLAGS) 
