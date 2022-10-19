#Question Description
/*
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/

#Algorithm
/*
1. Check all subsets for the given array.
2. To store current subset, we'll use a temp vector. subsets will be explored using concept where we'll either include the current element in
the subset, or ignore it.
3. If sum==k, then include that subset in the answer.
*/
#Solution
#include <bits/stdc++.h>
void solve(int input[], int n, int k, vector<int> &temp, vector<vector<int>> &ans, int currentSum, int i){
    if(i>=n){
        if(currentSum==k){
            ans.push_back(temp);
        }
        return;
    }
        
    solve(input, n, k, temp, ans, currentSum, i+1);
    temp.push_back(input[i]);
    solve(input, n, k, temp, ans, currentSum+input[i], i+1);
    temp.pop_back();
}
void printSubsetSumToK(int input[], int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(input, n, k, temp, ans, 0, 0);
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*-------MAIN
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
*/
