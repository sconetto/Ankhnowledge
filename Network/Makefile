SDL_CFLAGS := $(shell sdl-config --cflags)
SDL_LDFLAGS := $(shell sdl-config --libs)
STD_FLAGS = -W -Wall -ansi -pedantic

CPPSOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

all: init

init: $(CPPSOURCES: .cpp= .o)
	g++ -lSDL -o $@ $^ $(SDL_CFLAGS) $(SDL_LDFLAGS) $(STD_FLAGS)

%.o: %.cpp $(HEADERS)
	g++ $(STD_FLAGS) -c -o $@ $< $(SDL_CFLAGS) $(SDL_LDFLAGS)

clean:
	-rm -rf *.o init *~

# -include $(CPPSOURCES: .cpp= .d)

# %.d: %.cpp
# 	g++ $< -MM -MT '$*.o $*.d' -MD $(SDL_CFLAGS) $(SDL_LDFLAGS) 