class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if bigger 
        int MAX = 1;
        std::string substr(1, s[0]);
        for (int i = 1; i < s.length(); i++) {
            int index = substr.find(s[i]);
            if (index < 0) 
                substr += s[i];
            else {
                if (substr.length() > MAX)
                    MAX = substr.length();

                // abcA
                // bcA
                substr = substr.substr(index + 1, substr.length() - index - 1);
                substr += s[i];
            }
        }
        if (substr.length() > MAX)
            MAX = substr.length();
        if (s.length() == 0)
            return 0;
        return MAX;
    }
};
