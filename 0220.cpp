class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0 || nums.empty()) 
            return false;
        map<long, int> m{{nums[0], 1}};
        for (int i = 1; i < nums.size(); ++i) {
            auto it = m.lower_bound(nums[i]);
            if (it != m.end() && abs(it->first - (long)nums[i]) <= t)
                return true;
            if (it != m.begin() && abs((--it)->first - (long)nums[i]) <= t)
                return true;
            ++m[nums[i]];
            if (i - k >= 0 && --m[nums[i - k]] == 0)
                m.erase(nums[i - k]);
        }
        return false;


        // if (nums.empty()) return false;
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = i + 1; j < nums.size(); ++j) {
        //         if (j - i > k) break;
        //         if (abs((long)nums[i] - (long)nums[j]) <= t) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};