class Solution {
public:
    string intToRoman(int num);
    string rightDec(int num, int dec);
};

string Solution::intToRoman(int num) {
    string strNum = to_string(num), ret = "";
    for (int i = 0; i < strNum.size(); i++) {
        ret += rightDec(int(strNum[i]) - 48, strNum.size() - i);
    }
    return ret;
}
string Solution::rightDec(int num, int dec) {
    string mid = "", max = "", min = "";
    switch (dec) {
        case 1:
            mid = "V", max = "X", min = "I"; break;
        case 2:
            mid = "L", max = "C", min = "X"; break;
        case 3:
            mid = "D", max = "M", min = "C"; break;
        case 4:
            string ret = "M";
            for (int i = 1; i < num; i++)
                ret += 'M';
            return ret;
    }
    
    if (num == 9)
        return min + max;
    else if (num == 4)
        return min + mid;
    else if (num < 4) {
        string ret = "";
        for (int i = 0; i < num; i++)
            ret += min;
        return ret;
    }            
    else if (num >= 5) {
        for (int i = 0; i < num - 5; i++) 
            mid += min;
        return mid;
    }
        
    return "";
}
