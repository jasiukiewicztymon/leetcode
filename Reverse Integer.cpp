class Solution {
public:
    int reverse(int x) {
        string s1 = to_string(x), s = "";
        for (int i = s1.size() - 1; i >= 0; i--) 
            s += s1[i];
        while (s[0] == '0' && s.size() > 1)
            s.erase(0,1);
        if (x < 0) {
            s.erase(s.size() - 1, 1);
            s = '-' + s;
        }
        try {
            int ret = stoi(s);
            return ret;
        } catch(...) { return 0; }
    }
};
