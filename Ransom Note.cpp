class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < ransomNote.length(); i++) {
            int in = magazine.find(ransomNote[i]);
            if (in == -1)
                return false;
            else 
                magazine.erase(in, 1);
        }
        return true;
    }
};
