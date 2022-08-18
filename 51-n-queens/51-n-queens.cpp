class Solution {
public:
    
   void nQueen_solve(int col, vector<string>& board, vector<vector<string>>& queen_puzzle, vector<int>& leftrow, vector<int>& upperdiagonal, vector<int>& lowerdiagonal, int n){
       //Base condition or condition satisfied
       if(col == n){
           queen_puzzle.push_back(board);
           return;
       }
       
       //we check if we can place queen or not
       for(int row=0; row<n; row++){
           if(leftrow[row] == 0 and lowerdiagonal[row+col] == 0 and
             upperdiagonal[n-1 + col-row] == 0){
               
               board[row][col] = 'Q';
               leftrow[row] = 1;
               lowerdiagonal[row + col] = 1;
               upperdiagonal[n-1 + col-row] = 1;
               
               nQueen_solve(col+1, board, queen_puzzle, leftrow, upperdiagonal, lowerdiagonal, n);
               
               board[row][col] = '.';
               leftrow[row] = 0;
               lowerdiagonal[row + col] = 0;
               upperdiagonal[n-1 + col-row] = 0;
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
        
        vector<int> leftrow(n, 0);
        vector<int> upperdiagonal(2*n-1, 0);
        vector<int> lowerdiagonal(2*n-1, 0);
        
        nQueen_solve(0, board, queen_puzzle, leftrow, upperdiagonal, lowerdiagonal, n);
        
        return queen_puzzle;
    }
};