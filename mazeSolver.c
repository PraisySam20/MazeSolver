#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to check if a given position is valid or not
int isValid(int row, int col, char maze[ROWS][COLS]) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Depth-First Search function to solve the maze
int solveMaze(int row, int col, char maze[ROWS][COLS]) {
	int i;
    // Check if the current position is outside the maze boundaries
    if (!isValid(row, col, maze)) {
        return 0;
    }

    // If we reach the goal
    if (maze[row][col] == 'G') {
        return 1; // Maze is solved
    }

    // If the current cell is a wall or has been visited, return 0
    if (maze[row][col] != ' ' && maze[row][col] != 'S') {
        return 0;
    }

    // Mark the current cell as visited
    char originalCell = maze[row][col];  // Save the original cell value
    maze[row][col] = '.';

    // Try moving in all four directions: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (i = 0; i < 4; i++) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        // Recursively check the new position
        if (solveMaze(newRow, newCol, maze)) {
            return 1; // Path found
        }
    }

    // If none of the directions leads to a solution, revert the cell to its original state
    maze[row][col] = originalCell; // Revert the current cell
    return 0; // No path found
}

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
	int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to deallocate memory for the maze
void freeMaze(char maze[ROWS][COLS]) {
    // No dynamic memory allocation in this example, so nothing to free
}

int main() {
    char maze[ROWS][COLS] = {
        {'S', ' ', '#', '#', '#', ' ',' ', '#', '#', '#'},
        {'#', ' ', '#', '#', ' ', '#',' ', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ','#', ' ', '#', ' '},
        {'#', '#', '#', '#', '#', ' ',' ', ' ', '#', ' '},
        {'#', ' ', ' ', ' ', '#', '#','#', ' ', ' ', ' '},
        {'#', ' ', ' ', '#', ' ', ' ','#', ' ', '#', ' '},
        {' ', '#', '#', '#', ' ', '#',' ', '#', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', ' ',' ', '#', ' ', '#'},
        {'#', '#', ' ', '#', '#', ' ','#', ' ', ' ', ' '},
        {'G', ' ', ' ', ' ', ' ', ' ',' ', ' ', '#', ' '}
    };

    printf("Maze before solving:\n");
    printMaze(maze);

    // Find the starting point
    int startRow, startCol;
    int i,j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    // Solve the maze
    if (solveMaze(startRow, startCol, maze)) {
        printf("\nMaze after solving:\n");
        printMaze(maze);
        printf("\nMaze is solved!\n");
    } else {
        printf("\nNo solution found.\n");
    }

    // Deallocate memory for the maze
    freeMaze(maze);

    return 0;
}
