/*
Date: 26 April 2025
Leetcode: 2444
Problem: Count Subarays with Fixed bounds ( you have to return the count of that subarrays whose max and min element is equal to given maxK and minK ) 
*/

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
//Find all subarrays and check if min is minK and max is maxK
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;

        for (int start = 0; start < n; ++start) {
            int currentMin = nums[start];
            int currentMax = nums[start];

            for (int end = start; end < n; ++end) {
                currentMin = min(currentMin, nums[end]);
                currentMax = max(currentMax, nums[end]);

                if (currentMin == minK && currentMax == maxK) {
                    count++;
                }
            }
        }

        return count;
    }
};


//Approach-2 : Sliding Window
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        
        int minPosition = -1;
        int maxPosition = -1;
        int leftBound   = -1;            // CulpritIdx = not in the range of minK and maxK
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if(nums[i] == minK)
                minPosition = i;
            if(nums[i] == maxK)
                maxPosition = i;
            
            int count = min(maxPosition, minPosition) - leftBound;
            
            ans += (count <= 0) ? 0 : count;
            
        }
        
        return ans;
    }
};
