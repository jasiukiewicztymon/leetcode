class Solution {
public:
    int cStr(string haystack, string needle) {
        if (needle.length() == 0 || haystack.length() == 0)
            return 0;
        if (haystack[0] == needle[0]) {
            std::cout << haystack.substr(1, haystack.length() - 1) << " " << needle.substr(1, needle.length() - 1) << "\n";
            if (cStr(haystack.substr(1, haystack.length() - 1), needle.substr(1, needle.length() - 1)) > -1) {
                return 0;
            } 
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle.length() == 0 || haystack.length() == 0)
            return 0;
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack[i] == needle[0]) {
                if (cStr(haystack.substr(i + 1, haystack.length() - i - 1), needle.substr(1, needle.length() - 1)) > -1) {
                    return i;
                } 
            }
        }
        return -1;
    }
};
