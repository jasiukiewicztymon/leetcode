class Solution {
public:
    string longestPalindrome(string s) {
        string res(1, s[0]);
        for (int i = 1; i < s.length(); i++) {
            /*
            Yx -> yxY?
            YY -> xYYx?
            */
            if (s[i] == s[i - 1]) {
                // YY
                string temp = "";
                temp += s[i]; temp += s[i - 1];
                int index = 1; 
                while (i - 1 - index >= 0 && i + index < s.length() && s[i + index] == s[i - 1 - index]) {
                    temp = s[i - 1 - index] + temp + s[i + index];
                    index++;
                }

                if (temp.length() > res.length())
                    res = temp;
            }
            // Yx
            string temp(1, s[i]);
            int index = 1; 
            while (i - index >= 0 && i + index < s.length() && s[i + index] == s[i - index]) {
                temp = s[i - index] + temp + s[i + index];
                index++;
            }

            if (temp.length() > res.length())
                res = temp;
        }
        return res;
    }
};
