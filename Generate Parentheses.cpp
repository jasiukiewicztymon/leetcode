class Solution {
public:
    vector<string> ans;
    void trace(int l, int r, string s) {
        if (l < 0 || r < 0)
            return;
        if (l == 0 && r == 0) {
            ans.push_back(s);
            return;
        }

        if (r > l) 
            trace(l, r - 1, s + ")");
        if (l > 0) 
            trace(l - 1, r, s + "(");
    }
    vector<string> generateParenthesis(int n) {
        trace(n, n, "");
        return ans;
    }
};
