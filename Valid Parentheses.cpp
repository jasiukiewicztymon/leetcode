class Solution {
public:
    bool isValid(string s) {
        std::vector<char> v;
        for (auto e : s) {
            if (e == '(' || e == '[' || e == '{') 
                v.push_back(e);
            else if (v.size() > 0 && ((v[v.size() - 1] == '(' && e == ')') || (v[v.size() - 1] == '[' && e == ']') || (v[v.size() - 1] == '{' && e == '}')))
                v.pop_back();
            else 
                return false;
        }
        if (v.size() == 0)
            return true;
        return false;
    }
};
