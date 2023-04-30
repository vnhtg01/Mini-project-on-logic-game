all: random_generation release_dimacs solution_display


random_generation: random_generation.c game_grill.o
	$(CC) $^ -o $@

release_dimacs: sortie_dimacs.c game_grill.o manipulation_fnc.o dimacs.o read.o
	$(CC) $^ -lm -o $@

solution_display: solution_display.c game_grill.o read.o
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) -c $< -o $@

.PHONY: clean 

clean:
	rm -f *.o
