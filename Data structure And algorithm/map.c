#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char dir[] = {'D', 'R', 'U', 'L'};
bool visited[MAX_N][MAX_N];
char path[MAX_N * MAX_N];
int pathLen = 0;
int rows = 0, cols = 0;

bool isSafe(int x, int y, int maze[MAX_N][MAX_N]) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0 && !visited[x][y];
}

// Depth-first search
bool dfs(int x, int y, int maze[MAX_N][MAX_N]) {
    // If reached the bottom-right corner
    if (x == rows - 1 && y == cols - 1) {
        return true;
    }
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isSafe(nx, ny, maze)) {
            path[pathLen++] = dir[i];
            if (dfs(nx, ny, maze)) {
                return true;
            }
            pathLen--; // Backtrack
        }
    }
    visited[x][y] = false;
    return false;
}

int main() {
    int maze[MAX_N][MAX_N];
    char input[MAX_N + 1]; // To store each row as a string

    while (true) {
        if (fgets(input, sizeof(input), stdin) == NULL || strcmp(input, "\n") == 0) {
            break;
        }
        input[strcspn(input, "\n")] = 0; // Remove the newline character

        if (cols == 0) {
            cols = strlen(input); // Set the number of columns based on the first row
        }

        for (int j = 0; j < cols; j++) {
            maze[rows][j] = input[j] - '0';
        }
        rows++;
    }

    if (dfs(0, 0, maze)) {
        path[pathLen] = '\0'; // Null terminate the string
        printf("Path: %s\n", path);
    } else {
        printf("NO PASS\n");
    }

    return 0;
}
