/*
Date: 25 April 2025
Leetcode: 974
Problem: Subarray Sums divisible by K ( return the count of all the subarray that sum is divisible by given K ) 

This is follow up Question of today Leetcode: 2845 ( Count of interesting Subarrays ) 
*/

// Brute  TC: O(N^3)
// Better TC: O(N^2)  Both gives the time limit exceeds



/************************************************Ritesh*********************optimal*****************************************************/
// Most Optimal Approach 
// TC: O(n)
// Once visit my notebook for better understanding, you can't. I can only HAHAHAHAHAH

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;         // starting me rem ko 0 hi rakhenge, so map me count 1 ho jayega
        int result = 0;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if(rem < 0) {               // Edge Case when we got the negative sum so rem got negative
                rem += k;
            }

            if(mp.find(rem) != mp.end()) {   // that mean, hamne rem ko map me pahle dekha hai
                result += mp[rem];           // result me rem ka count add kar denge 
            }
            mp[rem]++;                       // then rem count ko bhi increase karke update kar denge
        }
        return result;
    }
};

