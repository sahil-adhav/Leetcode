class Solution {
public:
    
    void isConnected(vector<vector<char>> &grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == '2')
        {
            return;
        }
        
        grid[i][j] = '2';
        
        isConnected(grid, i + 1, j); //right
        isConnected(grid, i - 1, j); //left
        isConnected(grid, i, j + 1); //up
        isConnected(grid, i, j - 1); //down
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int isLand = 0;
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    isConnected(grid, i, j);
                    isLand++;
                }
            }
        }
        
        return isLand;
    }
};