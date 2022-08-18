class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(board[row][col] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(c, row, col, board)){
                            board[row][col] = c;
                            if(solve(board) == true){
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(char c, int row, int col, vector<vector<char>>& board){
        
        for(int i=0; i<9; i++){
            
            //checking in a row
            if(board[i][col] == c){
                return false;
            }
            
            //checking in a col
            if(board[row][i] == c){
                return false;
            }
            
            //checking in the 3x3 box
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c){
                return false;
            }
            
        }
        return true;

    }
};