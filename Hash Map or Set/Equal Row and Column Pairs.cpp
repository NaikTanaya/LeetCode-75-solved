class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> transpose(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                transpose[i][j] = grid[j][i];
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i] == transpose[j]) count++;
            }
        }
        return count;
    }
};



//2nd solution
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;

// Check each pair of rows and columns
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                // Check each element in the row and column for equality
                bool equal = true;
                for (int k = 0; k < grid[i].size(); k++) {
                    if (grid[i][k] != grid[k][j]) {
                        equal = false;
                        break;  // If any element is not equal, break out of the loop
                    }
                }

                // If all elements are equal, increment the count
                if (equal) {
                    count++;
                }
            }
        }
        return count;
    }
};

// Example 1:


// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]

// Example 2:


// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]
