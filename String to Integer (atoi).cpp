class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        std::string num = "";

        bool sign = false, isNum = false;

        for (int i = 0; i < s.length(); i++) {
            // +-
            if (s[i] == '+' || s[i] == '-') {
                if (isNum)
                    break;
                if (i < s.length() - 1)
                    if (int(s[i + 1]) < 48 || int(s[i + 1]) > 57)
                        return 0;

                if (sign)
                    return 0;
                if (s[i] == '-')
                    num += s[i];
                sign = true;
            }
            // numerique 
            else if (int(s[i]) > 47 && int(s[i]) < 58) {
                isNum = true;
                num += s[i];
            }
            // break 
            else if (s[i] != ' ') {
                if (isNum)
                    break;
                return 0;
            }
            else if (isNum && s[i] == ' ')
                break;
        }

        cout << num << "\n";
        try {
            if (!isNum)
                return 0;

            ret = stoi(num);
            cout << ret << "\n";
            return ret;
        } catch (...) {
            if (num[0] == '-')
                return INT_MIN;
            return INT_MAX;
        }
    }
};
