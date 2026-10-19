class Solution {
public:
    bool possi(vector<vector<char>>& board, int row, int col, char ch) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }
        for (int i=0; i<9;i++) {
            if (board[i][col]==ch)
                return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for (int i = sr; i < sr + 3; i++) {
            for(int j=sc;j<sc+3;j++) {
                if (board[i][j]==ch) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>> &board,int i,int j){
        if(i==9 && j==0) return true;
        if(board[i][j] >= '1' && board[i][j] <= '9'){
            if(i<=8){
                int ti,tj;
                if(j==8){ tj=0; ti=i+1;}
                else {tj=j+1; ti=i;}
                return dfs(board,ti,tj);
            }
        }
        vector<char> v={'1','2','3','4','5','6','7','8','9'};
        for(auto ch:v){
            if(possi(board,i,j,ch)){
                int ti,tj;
                if(i<=8){
                    if(j==8){ tj=0; ti=i+1;}
                    else {tj=j+1; ti=i;}
                    board[i][j]=ch;
                    if(dfs(board,ti,tj)) return true;
                    board[i][j]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
};