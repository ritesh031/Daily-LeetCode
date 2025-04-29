/*
Date: 29 April 2025
Leetcode: 2962
Problem: Count Subarrays Where Max Element Appears at Least K Times ( return the count of subarray where maxElement of array present at least k times ) 
*/

// Approach-1 --> Using Sliding Window ( our Khandani Taemplet ) 
// TC: O(n)
// SC: O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(begin(nums), end(nums));

        int n = nums.size();
        int i = 0;
        int j = 0;

        long long result = 0;
        int countMax = 0;

        while(j<n) {
            if(nums[j] == maxE) {
                countMax++;
            }
            while(countMax >= k) {
                result += n-j;            // This is the main line you have to find 
                if(nums[i] == maxE) {     // Shrinking the window
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};


// Approach-2 
