class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int SIZE = nums1.size() + nums2.size(); 
        
        vector<int> numsMerge(SIZE);
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), numsMerge.begin());
        std::sort(numsMerge.begin(), numsMerge.end());

        if (SIZE % 2 == 0) 
            return (numsMerge[SIZE / 2 - 1] + numsMerge[SIZE / 2]) / 2.0;
        else 
            return numsMerge[SIZE / 2];
    }
};
