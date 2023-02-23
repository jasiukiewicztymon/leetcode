class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v = {};
        sort(nums.begin(), nums.end());

        for (int a : nums)
            if (v.size() == 0 || a != v[v.size() - 1])
                v.push_back(a);
        
        nums = v;
        return v.size();
    }
};
