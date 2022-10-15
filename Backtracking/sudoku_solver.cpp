#Question Link: https://leetcode.com/problems/sudoku-solver/
#Question Description
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/

#Algorithm
/*
Imp: Whenever we are filling out any empty cell with any value, then it must obey the 3 rules mentioned in the question above. So to check that part,
we'll make a function named "isValid()" which will check of we can fill some value in the empty cell.

1. Traverse the entire 9x9 board.
2. Whenever we find an empty cell, we check from 1-9 which value can be filled in the cell using isValid function.
3. Then we fill the valid value and call the function recuresively for other empty cell.
4. If these recursive function do not return true, then we remove the value we just put so that we can check out other valid values.
5. Once we are done with all calls, out board will be filled with the solution values.
*/
#Solution
class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char val){
        for(int i=0;i<9;i++){
            if(board[i][col]==val)return false;
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==val)return false;
        }

        int startC,startR;
        if(row>=0 && row<=2)startR=0;
        else if(row>=3 && row<=5)startR=3;
        else if(row>=6)startR=6;

        if(col>=0 && col<=2)startC=0;
        else if(col>=3 && col<=5)startC=3;
        else if(col>=6)startC=6;

        for(int i=startR;i<=(startR+2);i++){
            for(int j=startC;j<=(startC+2);j++){
                if(board[i][j]==val)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char val='1';val<='9';val++){
                        if(isValid(board, i, j, val)){
                            board[i][j]=val;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }
};
