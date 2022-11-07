#Question Link: https://leetcode.com/problems/house-robber/
#Question Description
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

#Algorithm
/*
1. This is a dynamic programming approach. We can store output at each house in a dp array which will help us calculate
loots in next houses.
2. Base case: for 1st house, we'll loot directly. for second house, we will check which house is better to loot 1st or second.
max value we'll store in array.
3. From 3rd house till last, our output will be simple dp[i]=max(dp[i-1], nums[i]+dp[i-2]). Either we take the house, or we skip it.
4. Now in this approach, we can see that we only need dp[i-1] and dp[i-1] to caculate dp[i]. Hence we can do SPACE OPTIMIZATION here 
by storing just these 2 values in each iteration as used in below solution.
*/

#Solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        else if(n==2)return max(nums[0], nums[1]);
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int temp=prev1;
            prev1=max(prev1, nums[i]+prev2);
            prev2=temp;
        }
        return prev1;
    }
};
