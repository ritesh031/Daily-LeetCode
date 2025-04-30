/*
Date: 30 April 2025
Leetcode: 1295
Problem: Find Numbers with Even Number of Digits ( return the count of element whose have even digits ) 
*/

/*************************************************Ritesh****************************************************/

// There are many ways to find the count digits of any number 
// Approach-1: in constant time, if the constraints are known 
// TC: O(1) 
// SC: O(1) 

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] >= 10 && nums[i] <= 99 
            || nums[i] >= 1000 && nums[i] <= 9999
            || nums[i] == 100000) {
                result += 1;
            }
        }
        return result;
    }
};

// Approach-2 --> 
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0; 

        for(int i=0; i<n; i++) {
            int cnt = 0;
            while(nums[i]) {
                cnt++;
                nums[i]/=10;
            }
            if(cnt % 2 == 0) {
                result += 1;
            }
        }
        return result;
    }
};

// Approach-3 --> 
// TC: O(n) --> only one 'for' loop is running
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0; i<n; i++) {
            string s = to_string(nums[i]);
            if(s.length() % 2 == 0) result += 1;
        }
        return result;
    }
};

// Approach-4 ---> 
// TC: O(N)

/*
Things to understand: 
floor(3.2) -----> 3
ceil(3.2) ------> 4 
  */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i : nums) {
            int digit = floor(log10(i)) + 1;
            if(digit % 2 == 0) result += 1;
        }
        return result;
    }
};

// Approach-5
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0; i<n; i++) {
            int digit = ceil(log10(nums[i] + 1));
            if(digit % 2 == 0) result += 1;
        }
        return result;
    }
};





