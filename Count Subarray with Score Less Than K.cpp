/*
Date: 28 April 2025
Leetcode: 2302
Problem: Count subarrays with score less than k ( Score of subarray: (sum of it's element) * (length of subarray) ) 
*/

// We'll use the KHANDANI Templet of Sliding Window to solve this problem 
// TC: O(2n)
// SC: O(1) 

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        long long result = 0; 
        long long sum    = 0;

        int i = 0;
        int j = 0;

        while(j<n) {          // Sliding Window khandani Templet
            sum += nums[j];

            while(i<=j && sum*(j-i+1) >= k) {    // Shrink the Window bcz the calculated score is greater than given k
                sum -= nums[i];
                i++;
            }

            // i...j
            // i+1....j
            // i+2....j
            result += (j-i+1);
            j++;
        }
        return result;
    }
};
