class Solution {
public:
    string convert(string s, int numRows) {
        // devide to chunks of size 2 * numRows - 2
        /*
            *           *       * * *
            *    *      * *     * * *
            *   *       *
            *  *
            * *
            *
        */
        vector<string> lines;
        for (int i = 0; i < numRows; i++) 
            lines.push_back("");

        int lineIndex = 0;
        bool pos = true, end = false;;

        if (numRows == 1)
            return s;
        if (numRows == 2) {
            string s1 = "";
            string s2 = "";

            for (int i = 0; i < s.length(); i++) {
                if (i % 2 == 0)
                    s1 += s[i];
                else 
                    s2 += s[i];
            }
            return s1 + s2;
        }

        int CHUNCK_SIZE = 2 * numRows - 2;

        if (numRows == 3)
            CHUNCK_SIZE = 4;

        for (int i = 0; i < (s.length() / CHUNCK_SIZE) + 1; i++) {
            for (int j = 0; j < CHUNCK_SIZE; j++) {
                if ((i * CHUNCK_SIZE)+j == s.length()) {
                    end = true;
                    break;
                }

                lines[lineIndex] += s[(i * CHUNCK_SIZE)+j];         

                if (lineIndex == numRows - 1)
                    pos = false;
                else if (lineIndex == 0)
                    pos = true;

                pos ? lineIndex++ : lineIndex--;
            }
            if (end)
                break;
        }

        string ret = "";

        for (auto l : lines)
            ret += l;

        return ret;
    }
};
