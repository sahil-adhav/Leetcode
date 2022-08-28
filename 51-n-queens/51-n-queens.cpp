class Solution {
public:
    
    bool can_place_queen(int row, int col, vector<string>& board, int n){
        
        //check for upper diagonal left side
        int duprow = row;
        int dupcol = col;
        while(row >= 0 and col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        
        //check for left side
        row = duprow;
        col = dupcol;
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }
        
        //check for bottom diagonal left
        row = duprow;
        col = dupcol;
        while(row < n and col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        
        //if we can place queen
        return true;
    }
    
    void nQueen_solve(int col, vector<string> &board, vector<vector<string>> &queen_puzzle, int n){
        //Base Condition or condition is satisfied
        if(col == n){
            queen_puzzle.push_back(board);
            return;
        }
        
        //Calculation Part or we check if we can place the queen or not
        for(int row=0; row<n; row++){
            if(can_place_queen(row, col, board, n)){
                board[row][col] = 'Q';
                nQueen_solve(col+1, board, queen_puzzle, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> queen_puzzle;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        nQueen_solve(0, board, queen_puzzle, n);
        
        return queen_puzzle;
    }
};