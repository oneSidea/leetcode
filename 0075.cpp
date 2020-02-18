class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        if(nums.size()) {
            int p0 = 0;     //p0指向0最右，初始化为0
            int p2 = nums.size();   //p2指向2最左的元素，初始化为数组外
            for(int i=0; i<p2;) {
                if(nums[i]==2) {
                    swap(nums[i], nums[--p2]);
                }
                else if(nums[i]==0) {
                    swap(nums[i++], nums[p0++]);
                }
                else   
                    i++;
            }
        }
    }
};