#include <vector>
#include <algorithm>

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<char> ch = {s[0]};
        for (int i = 1; i < s.size(); i++) {
            if (find(ch.begin(), ch.end(), s[i]) != ch.end())
                return s[i];
            else 
                ch.emplace_back(s[i]);
        }
        return '0';
    }
};
