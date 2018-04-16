#include <stddef.h>
#define ROW 6
#define COL 6
typedef struct Maze
{
    int maze[ROW][COL];
}Maze;

typedef struct Point
{
    int x;
    int y;
}Point;
