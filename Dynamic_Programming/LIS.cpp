#Question Link: https://leetcode.com/problems/longest-increasing-subsequence/
#Question Description
/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#Algorithm
/*
1. We can use dynamic programming to solve this question. At each index, we'll check prev indexes to calculate current index value.
2. We'll create another dp array and for each index in input array, we'll store max possible LIS length till that index in dp array.
3. Base Case: dp[0]=1. This corresponds to 1st value in input array. So length=1;
4. For i=1->n-1, let us consider index 0<k<=n-1, we'll check for indexes [0, k-1] for each value<input[k], what is the max LIS stored so
far. To the max LIS, we'll add this current kth value i.e. we'll do +1.
5. Simultaneously, we'll keep a variable ans which will store max value present in dp array.
6. Finally, we'll return ans.
*/

#Solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            int maxm=0;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    maxm=max(maxm, dp[j]);
                }
            }
            dp[i]=maxm+1;
            ans=max(ans, dp[i]);
        }
       return ans; 
    }
};
