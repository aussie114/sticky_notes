PROJECT = sticky_notes
OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

run: $(OBJECTS)
	gcc build/*.o -o $(PROJECT) -Wall -Wextra -Iinclude -lSDL3 -lSDL3_ttf
	./$(PROJECT) 0 "3/Dec/2025 pay water" "3/Dec/2025 10am interview"

build: $(OBJECTS)
	gcc build/*.o -o $(PROJECT) -Wall -Wextra -Iinclude -lSDL3 -lSDL3_ttf

build/%.o: src/%.c
	gcc  -Wall -Wextra -Iinclude -c $< -o $@

clean:
	rm -rf build/* $(PROJECT)
