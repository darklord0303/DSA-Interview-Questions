#Question Link: https://leetcode.com/problems/n-queens/
#Question Description
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

#Algorithm
/*
We will use recursion+backtracking to explore allpossibe ways. We  will be keeping a string vector which will represent the board.
1. We will start placing queens column wise. So initially we'll pass 0 to our solve function.
2. Our base case for solving will be if column>=n, then that means we have found a way to place n queens in 0->(n-1) columns. Hence we'll
push the current board into our answer and will return.
3. If col<n, then we'll loop through all rows for the current column. We'll be using a isvalid() function to check whether we can place
the queen in the current cell or not. 
4. If we can then we'll update our board and call solve for next column.
5. IMP: Once we come back from the recursive call after placing a queen, we need to remove the queen from that place.
6. Once all calls are done, we'll have the final answer matrix.
*/
#Solution

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(vector<string> &temp, int row, int col, int n){
        int r1=row,c1=col;
        while(row>=0 && col>=0){
            if(temp[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=r1;col=c1;
        while(col>=0){
            if(temp[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col=c1;
        while(row<n && col>=0){
            if(temp[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int n, vector<vector<string>> &ans, vector<string> &temp, int col){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(temp, i, col, n)){
                temp[i][col]='Q';
                solve(n, ans, temp, col+1);
                temp[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n); 
        string s(n,'.');
        for(int i=0;i<n;i++){
            temp[i]=s;
        }
        solve(n, ans, temp, 0);

        return ans;
    }
};
