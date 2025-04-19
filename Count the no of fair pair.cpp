/* 
Date: 19 April 2025 
Leetcode: 2563 
Problem: Count the Number of fair pairs ( binary search ) 
*/ 


//Approach (simple binary search trick)
// Code:  (optimal)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(begin(nums), end(nums));  //nlog 

        long long result = 0;

        for(int i=0; i<n; i++){   // O(n * logn)
        // lower_bound and upper bound uses the Binary Search internally
        
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums);  //Give the first element "NOT LESS" than (lower - nums[i])  // log(n)
            int x = idx - 1 - i;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums);  //Give the first element "NOT LESS" than (lower - nums[i])  // log(n)
            int y = idx - 1 - i;

            result += (y-x);
        }
        return result;
    }
};

// By Ritesh
