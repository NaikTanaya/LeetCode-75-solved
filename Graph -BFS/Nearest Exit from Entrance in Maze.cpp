class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        // now we will do bfs at every level using queue

        queue<pair<int, int>> q;
        int steps = 1;

        // all valid traversal directions can be
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // push entry to queue and make it visited also apply bfs
        q.push({entrance[0], entrance[1]});

        // make it visited
        maze[entrance[0]][entrance[1]] = '+';  //a[0][1]

        while(!q.empty())
        {
            int size = q.size();
            // for every node in queue visit all its adjacent nodes which are
            // not visited yet
            for (int i = 0; i < size; i++) {
                auto [x_cord, y_cord] = q.front();
                q.pop();

                // check in all the 4 directions, non visited nodes.
                for (int k = 0; k < 4; k++) {
                    int x = x_cord + direction[k][0];
                    int y = y_cord + direction[k][1];

                    // if it is invalid move (visited, out of bound.) ,
                    // continue.
                    if (x < 0 || y < 0 || x >= row || y >= col ||
                        maze[x][y] == '+')
                        continue;
                    // If we have reached the exit then current steps are the
                    // min steps to reach the exit
                    if (x == 0 || y == 0 || x == row - 1 ||
                        y == col - 1)
                        return steps;
                    // block the cell as we have visited and push in queue.
                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
            steps++;
        }
        return -1;
    }
};

// Example 1:

// Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
// Output: 1
// Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
// Initially, you are at the entrance cell [1,2].
// - You can reach [1,0] by moving 2 steps left.
// - You can reach [0,2] by moving 1 step up.
// It is impossible to reach [2,3] from the entrance.
// Thus, the nearest exit is [0,2], which is 1 step away.

// Example 2:

// Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
// Output: 2
// Explanation: There is 1 exit in this maze at [1,2].
// [1,0] does not count as an exit since it is the entrance cell.
// Initially, you are at the entrance cell [1,0].
// - You can reach [1,2] by moving 2 steps right.
// Thus, the nearest exit is [1,2], which is 2 steps away.

// Example 3:

// Input: maze = [[".","+"]], entrance = [0,0]
// Output: -1
// Explanation: There are no exits in this maze.
