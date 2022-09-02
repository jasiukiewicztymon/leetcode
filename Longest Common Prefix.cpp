class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string out = ""; char c;
        while (1) {
            for (int i = 0; i < strs.size(); i++) {
                if (out.size() == strs[i].size())
                    return out;
                if (i == 0)
                    c = strs[i][out.size()];
                
                if (strs[i][out.size()] != c)
                    return out;
                if (i == strs.size() - 1 && strs[i][out.size()] == c)
                    out += c;
            }
        }
    }
};
