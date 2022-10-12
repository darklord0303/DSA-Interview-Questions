#Question Description
/*Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
*/

#Algorithm
/*
1. Here we'll be using backtracking to find all the relevant paths.
2. To Avoid using additional space, we'll modify the input path matrix itself.
3. We'll define a solve() function which will take inputs: given matrix, n(size), ans vector of type string(this will store the path strings like "DDRDRD" etc), current
 path string, (i,j) the current cell that we are at and a char which will define direction of movement).
4. We start at (0,0). First of all we'll define base condition i.e. if current cell is the last cell, then that means we have reached our destination.
Hence we'll add the final direction char to current path string and will push the final string in ans vector.
5. Next is the edge conditions and visiting conditions. If our (i,j) values are out of bound of given matrix, we'll simply return. Also, if current cell is already
visited or current cell==0, then also we'll return.
6. Now return conditions are defined, we'll first visit the cell. To visit, we'll set value=2 in the given matrix itself. Then we'll recursively call the functions
in all 4 directions i.e. U, D, L, R.
7. Once we return after all these calls, we'll again set value of current cell=1 so that if it can be included in some other path, it should not already see as visited.
8. Once all function calls end, we'll have the required path string in ans vector and we'll return it.
*/
#Solution

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, string current, int i, int j, char ch){
        if(i==(n-1) && j==(n-1) && m[i][j]==1){
            current+=ch;
            ans.push_back(current);
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==2 || m[i][j]==0)return;
        
        m[i][j]=2;
        //ch=='X', this was start cell. From here movements will start. Hence X is just dummy value.
        if(ch!='X')current+=ch;
        
        solve(m, n, ans, current, i+1, j, 'D');
        solve(m, n, ans, current, i, j+1, 'R');
        solve(m, n, ans, current, i-1, j, 'U');
        solve(m, n, ans, current, i, j-1, 'L');
        
        m[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        solve(m, n, ans, "",0 , 0, 'X');
        return ans;
    }
};

/* ----MAIN----
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
*/
