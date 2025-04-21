/*
Date: 21 April 2025
Leetcode: 2145
Problem: Count the hidden sequences ( basic given some condition and on that basic we have to count that hidden sequences ) 

I had mantioned the Intuitions in my notebook of daily leetcode problem copy 
*/

//---------------------------------------------------------------------------------------------------------Ritesh--------------------------------------------------------------------------------------------------------

//Code:
// TC: O(n) 
// SC: O(1)

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0; // a[0] first element of hidden sequence
        int minVal = 0; 
        int maxVal = 0; 

        for(int &d : differences) {
            curr = curr + d; 

            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper-maxVal) - (lower-minVal) + 1 <= 0) {
                return 0;
            }
        }
        return (upper-maxVal) - (lower-minVal) + 1;
    }
};
