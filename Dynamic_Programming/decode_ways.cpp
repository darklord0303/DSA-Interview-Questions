#Question Link: https://leetcode.com/problems/decode-ways/
#Question Description
/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
*/

#Algorithm
/*
1. Here, simple approach will be to check all possible codes that can be formed. To check all codes, at each point, we'll have 2 ways,
either select current digit and convert that single digit to alphabet or select current and next digit and if those form num<=26, then
convert that to alphabet and proceed ahead.
2. Ex if num=21153, then in step 1, i'll call recursive function for (b)(1153) and (u)(153).
3. But this will cause TLE as time is increasing due to unncessary steps or overlapping subproblems. To avoid that, we'll store the current string
num wise data in a map.(MEMOIZATION)
4. Base case: If length of current string is 0 or 1, we return 1 as only 1 possible way or code for this case.
*/

#Solution
class Solution {
public:
int solve(string s, map<string, int> &mp){
    if(s.length()!=0){
        if(s[0]=='0')return 0;
    }
    if(s.length()==0 || s.length()==1){
        return 1;
    }
    
    if(mp.find(s)!=mp.end())return mp[s];

    int a1=solve(s.substr(1), mp);
    string temp=s.substr(0,2);
   
    if(stoi(temp)<=26){
        a1+=solve(s.substr(2), mp);
    }
    return mp[s]=a1;
}
    int numDecodings(string s) {
        map<string, int> mp;
        int ans=solve(s, mp);
        return ans;
    }
};
