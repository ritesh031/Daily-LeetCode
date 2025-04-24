/*
Date: 24 April 2025
Leetcode: 2799
Problem: Count Complete subarrays in an Array ( Complete Subarray: no. of distinct elements in subarray == no. of distinct elements in given Array ) 
*/

/**********************************************Sliding Window (Classic Problem) ***************Ritesh**************************************************/

// Code: 
// TC: O(n)
// SC: O(n)

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums), end(nums)); // For distinct element in given array(nums)
        int c = st.size();   // number of distinct elements in nums

        int i = 0;
        int j = 0;
        int result = 0;

        unordered_map<int, int> mp;

        while(j<n) {
            mp[nums[j]]++;
            while(mp.size() == c) {
                result += (n-j);
                mp[nums[i]]--;

                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};
