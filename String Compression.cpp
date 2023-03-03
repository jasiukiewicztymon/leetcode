class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1; char target = chars[0];
        vector<char> res;
        res.push_back(target);

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] != target) {
                if (count > 1) {
                    string c = to_string(count);
                    for (char ch : c) 
                        res.push_back(ch);
                }

                target = chars[i];
                count = 1;
                res.push_back(target);
            }    
            else 
                count++;
        }
        if (count > 1) {
            string c = to_string(count);
            for (char ch : c) 
                res.push_back(ch);
        }

        chars = res;
        return res.size();    
    }
};
