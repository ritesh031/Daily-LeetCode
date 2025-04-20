/* 
Date: 20 April 2025
Leetcode: 781
Problem: Rabbits in Forest ( asked every rabbits that how many rabbits are more like you and return the total ) 
*/

//----------------------------------------------------------------------------------  Ritesh --------------------------------------------------------------------------------------------//
// CODE: 
// TC: O(n)
// SC: O(n) ---->> bcz of map DS 

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;      // SC: O(n)

        for(int &x : answers) {         // TC: O(n)
            mp[x]++;
        }

        int total = 0; 

        for(auto &it : mp) {          // TC: O(n)
            int x = it.first;      // answer
            int count = it.second; // kitne rabbits ne x answer kiya

            int groupSize = (x+1);
            int groups = ceil((double) count/groupSize);

            total += groups * groupSize;
        }
        return total;
    }
};
