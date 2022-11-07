#Question Description
/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - 1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
*/

#Algorithm
/*
1. We can simply write a recursive function which can calculate min steps by calling on all three ways. but that will cause TLE as
excessive number of calls and overlapping subproblems will increase runtime. Instead we'll be using dynamic programming to avoid
overlapping subproblems. We'll store min_steps for all nums from 1->n.
2. Base case: if n==1, then ans=0 (as we dont need to do anything).
3. We'll recursively call our function based on all 3 possible steps. Minimum value will be output for current n.
4. at the end, we'll return dp[n].
*/
#Solution
#include <vector>
using namespace std;
int solve(int n,vector<int> &dp){
	if(n==1){
		return dp[1]=0;
	}

	if(dp[n]!=INT_MAX)return dp[n];

	int a1=solve(n-1, dp)+1;

	int a2=INT_MAX;
	if(n%2==0)a2=solve(n/2, dp)+1;

	int a3=INT_MAX;
	if(n%3==0)a3=solve(n/3, dp)+1;
	
   dp[n] = min(a1, min(a2, a3));
   return dp[n]; 
}
int countStepsToOne(int n)
{
	vector<int> dp(n+1, INT_MAX);
	solve(n, dp);
	return dp[n];
}

#include <bits/stdc++.h>
using namespace std;
#include "solution.h"

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
