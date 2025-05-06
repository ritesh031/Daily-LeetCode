/*
Date: 06 May 2025
Leetcode: 1920
Problem: Build Array from Permutation ( we have to return an array ans where ans[i] = nums[nums[i]] ) 

Easy Problem 
*/

// Intuition: just do what the question is said but it will take the extra memory n and we have to do it in-place

// So we use the simple mathematic:    a = b*q + r 
// do dry-run once so it will clear 

/********************************************Ritesh**********************************************************************/     

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);   // This is nothing but, write of old and new value at once place so in future we need so we take by doing modulo and division
        }

        // we are doing this for finding the solution in-place (don't take extra place) 

        for(int i=0; i<n; i++) {
            nums[i] = nums[i] / n;
        }
        return nums;
    }
};
