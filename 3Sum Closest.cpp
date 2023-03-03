class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int diff = INT_MAX;
        int closest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int d = abs(sum - target);
                if (d < diff) {
                    diff = d;
                    closest = sum;
                }
                if (sum > target) {
                    r--;
                }
                else
                    l++;
            }
        }

        return closest;
    }
};
