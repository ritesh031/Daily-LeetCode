/*
Date: 27 April 2025
Leetcode: 3392
Problem: Count Subarrays of Length Three With a Condition ( return the count of subarray of length 3 whose middle element is the twice of sum of 1st and 3rd element )
*/

/***********************************************Ritesh*********************************************************************/

// Easiest Problem 
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=1; i<n-1; i++) {
            if(nums[i] == (nums[i-1] + nums[i+1])*2 ) {
                result++;
            }
        }
        return result;
    }
};
