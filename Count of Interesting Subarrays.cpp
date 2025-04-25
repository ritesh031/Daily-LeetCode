/*
Date: 25 April 2025
Leetcode: 2845
Problem: Count of Interesting Subarrays ( subarray will be interestig : when elements of subarray divisible by given m then store that count, and if that count is also divisible by given m then that subarray is interesting subarray ) 

Before seeing this problem, see the follow up Leetcode: 974 
*/

// Optimal Approach similar to Leetcode 974 
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        unordered_map<int, long long> mp; //remainder -> count
        long long sum = 0; //sum will be equal to cnt of those elements % m == k

        long long result = 0;

        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] % m == k)
                sum += 1;

            int r1 = sum%m;

            int r2 = (r1 - k + m) % m;

            result += mp[r2];
            mp[r1]++;
        }

        return result;

    }
};
