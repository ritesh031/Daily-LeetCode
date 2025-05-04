/*
Date: 04 April 2025
Leetcode: 1128
Problem: Number of Equivalent Domino Pairs ( read problem on leetcode once ) 
*/

//Approach-1 (Using map of pair)
//T.C : O(n * logn) , note that we are using ordered_map here and insertion in it is log(n)
//S.C : O(n)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) { //(2, 1) ---- (1, 2)
                swap(d[0], d[1]);
            }

            mp[{d[0], d[1]}]++;
        }

        int result = 0;

        for(auto &it : mp) {
            int freq = it.second;

            result += freq * (freq-1)/2; //freqC2
        }

        return result;

    }
};


//Approach-2 (constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> vec(100);

        int result = 0;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) {
                swap(d[0], d[1]);
            }

            int num = d[0]*10 + d[1]; //(a, b) --> a*10 + b;

            result += vec[num];

            vec[num]++;
        }

        return result;
    }
};
