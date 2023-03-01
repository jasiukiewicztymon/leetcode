class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
            
                const int sum = nums[i] + nums[j] + nums[k];
                if (0 == sum) 
                    res.insert({nums[i], nums[j++], nums[k--]});
                else if (0 > sum)
                    j++;
                else if (0 < sum)
                    k--;
            }
        }

        vector<vector<int>> rs;
        
        std::copy(res.begin(), res.end(), std::back_inserter(rs));

        return rs;
    }
};
