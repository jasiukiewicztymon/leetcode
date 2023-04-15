class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = {};

        if (nums.size() == 1)
            return {{nums[0]}};
        
        for (int i = 0; i < nums.size(); i++) {
            vector<int> n(nums);
            auto it = n.begin() + i;
            n.erase(it);

            vector<vector<int>> r = permute(n);

            for (auto a : r) {
                a.insert(a.begin(), nums[i]);
                res.push_back(a);
            }
        }

        return res;
    }
};
