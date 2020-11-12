#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Provided for students.
void read_maze(string filename, vector<vector<char> > &maze) {
    ifstream ifile(filename);
    int size = 0;
    for (int i = 0; ifile; i++) {
        string line;
        getline(ifile, line);
        if (i == 0) {
            vector<char> maze_line;
            for (char c : line) {
                maze_line.push_back(c);
            }
            size = maze_line.size();
            maze.push_back(maze_line);
        } else {
            vector<char> maze_line(size);
            for (int j = 0; j < line.size(); j++) {
                maze_line[j] = line[j];
            }
            for (int j = line.size(); j < maze_line.size(); j++) {
                maze_line[j] = ' ';
            }
            maze.push_back(maze_line);
        }
    }
    maze.pop_back();
    ifile.close();
}

bool solve_helper(vector<vector<char> > &maze, size_t row, size_t column) {
    maze[row][column] = '*';
    size_t rows = maze.size(), columns = maze[0].size();
    if (row == rows-2 && column == columns-1) {
        return true;
    }

    if (row+1 < rows && maze[row+1][column] == ' ' && solve_helper(maze, row+1, column)) {
        return true;
    }
    if (row > 0 && maze[row-1][column] == ' ' && solve_helper(maze, row-1, column)){
        return true;
    }
    if (column+1 < columns && maze[row][column+1] == ' ' && solve_helper(maze, row, column+1)) {
        return true;
    }
    if (column > 0 && maze[row][column-1] == ' ' && solve_helper(maze, row, column-1)) {
        return true;
    }

    maze[row][column] = ' ';
    return false;
}

bool solve(vector<vector<char> > &maze) {
    return solve_helper(maze, 1, 0);
}

// Driver code provided.
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "argc must be 3" << endl; // run like ----> ./maze_solver maze.txt output.txt
        return 1;
    }
    vector<vector<char> > maze;
    read_maze(argv[1], maze);

    if (solve(maze)) {
        ofstream ofile(argv[2]);
        if (ofile) {
            for (int i = 0; i < maze.size(); i++) {
                for (int j = 0; j < maze[i].size(); j++) {
                    ofile << maze[i][j];
                }
                ofile << endl;
            }
        }
        ofile.close();
    }

    return 0;
}

