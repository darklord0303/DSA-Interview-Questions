#Question Link: https://leetcode.com/problems/maximum-subarray
#Question Description
/*
Given an integer array nums, find the 
subarray
 which has the largest sum and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#Algorithm
/*
1. This problem can be approached using dynamic programming. We only need to store the current Best sum and answer.
2. Base case: currentBest and ans both equals to nums[0]
3. For i=1->n, at each point we'll check if currentBest is +ve or -ve. If it is negative, then that means prev element
should not be considered in subarray. hence it is essentially break for prev considered subarray. Now we set currentBest
to current element.
4. If currentBest is +ve, then we just simply current value to currentBest and move frwd.
5. In each iteration, we'll capture the max value so far and store in ans variable.
6. At the end, we'll return ans;
*/

#Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentBest=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            if(currentBest<0){
                currentBest=nums[i];
            }
            else{
                currentBest+=nums[i];
            }
            ans=max(ans, currentBest);
        }
        return ans;
    }
};
