class Solution {
public:
    vector<string> all(int n, vector<string> set) {
        vector<string> ans, chs = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        n -= 2;

        for (auto s : set) {
            for (auto c : chs[n]) {
                ans.push_back(s + c);
            }
        }

        if (ans.size() == 0) 
            for (auto c : chs[n]) {
                string s(1, c);
                ans.push_back(s);
            }

        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        for (auto d : digits) {
            string s(1, d);
            int i = stoi(s);

            ans = all(i, ans);
        }

        return ans;
    }
};
