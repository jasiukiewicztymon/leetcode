class Solution {
public:
    string addBinary(string a, string b) {
        int r = 0;

        int ai = a.length() - 1, bi = b.length() - 1;

        string res = "";

        while (ai >= 0 || bi >= 0) {
            if (ai >= 0 && a[ai] == '1')
                r++;
            if (bi >= 0 && b[bi] == '1')
                r++;

            if (r % 2 == 1) {
                res = '1' + res;
                r--;
            }
            else {
                res = '0' + res;
            }

            r /= 2;
            ai--;
            bi--;
        }

        while (r) {
            if (r % 2 == 1) {
                res = '1' + res;
                r--;
            }
            else {
                res += '0';
            }
            r /= 2;
        }

        return res;
    }
};
