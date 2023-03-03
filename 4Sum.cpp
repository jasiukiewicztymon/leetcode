class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> set;
        vector<vector<int>> ans;

        if (nums.size() < 4) return ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 3; i++){
            for(int j = i + 1 ; j < nums.size() - 2 ; j++){
                long long nt = (long long)target - (long long)nums[i] - (long long)nums[j];
                int l = j + 1, r = nums.size() - 1;
                while(l < r){
                    if(nums[l] + nums[r] < nt){
                        l++;
                    }
                    else if(nums[l] + nums[r] > nt){
                        r--;
                    }
                    else{
                        set.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                    }
                }
            }
        }

        for(auto it : set){
            ans.push_back(it);
        }

        return ans;
    }
};
