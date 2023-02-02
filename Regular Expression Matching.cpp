#include <regex>
class Solution {
public:
    vector<string> tokenizer(string s) {
        vector<string> res;

        stringstream ss(s);
        string w;
        while (!ss.eof()) {
            getline(ss, w, '*');
            res.push_back(w);
        }
        return res;
    }
    bool isMatch(string s, string p) {
        int index = 0;
        string res = "";

        vector<string> substr = tokenizer(p);

        for (int i = 0; i < substr.size(); i++) {
            bool inf = substr[i + 1] != ""; 
            
            string str = substr[i];
            str.pop_back();
            for (int j = 0; j < str.length(); j++) {
                if (s[index] == str[j] || str[j] == '.') {
                    res += s[index];
                    index++;
                }
                else 
                    return false;
            }

            if (!inf)
                break;
        }

        return s == res;
    }
};
