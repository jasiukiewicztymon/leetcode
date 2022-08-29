# leetcode

#include<cstring>
#include<vector>

class Solution {
public: 
    int rToN(char ch);
    int romanToInt(string s);
};

int Solution::rToN(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500; 
        case 'M': return 1000;
    }
    return 0;
}
int Solution::romanToInt(string s) {
    int t = 0;
    vector<int> nums;
    nums.emplace_back(rToN(s[0]));
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            nums[nums.size() - 1] += rToN(s[i]);
        }
    }
    for (int i = 0)
    return t;
}
