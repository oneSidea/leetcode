class Solution {
public:
    static bool intToStrSort(int a, int b) {
        string strA = std::to_string(a);
        string strB = std::to_string(b);
        return strA+strB > strB+strA;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), intToStrSort);
        string res = "";
        if(nums[0]==0)
            return "0";     //排序后数组首位为0，则数组元素的值均为0
        for(int i=0; i<nums.size(); i++) {
            res += std::to_string(nums[i]);
        }
        return res;
    }
};