#Question Link: https://leetcode.com/problems/subsets
#Question Description
/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#Algorithm
/*
We'll be using recursion+backtracking to solve this question. for an array of size n, we'll have 2^n subsets.
1. We'll start by creating a 2D vector which will store all the subsets. We'll keep a vector temp which will store the current subset
which we might push to ans 2D vector at end.
2. Now we call solve() function and we will pass current index as 0 (starting).
3. Base case: if i>array size, we'll push current created subset to ans and return.
4. Now we have 2 choice at each index, either we can include the current element or ignore it. Hence first we'll do recursive call to solve()
without including current element. Then once that completes, we'll push current element to temp (subset vector) and again call solve().
5. Once current element inclusive call is completed, we'll pop it from temp.
*/
#Solution
class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums, ans, temp, i+1);
        temp.push_back(nums[i]);
        solve(nums, ans,  temp, i+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        return ans;
    }
};
