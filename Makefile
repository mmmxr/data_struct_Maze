.PHONY:clean

maze:maze.c
	gcc -o $@ $^ 
clean:
	rm -f maze
