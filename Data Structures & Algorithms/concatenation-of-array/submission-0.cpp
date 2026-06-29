class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto numsLen = nums.size();
        std::vector<int> ans(numsLen * 2);

        for(auto i = 0; i < numsLen; ++i){
            ans[i] = nums[i];
            ans[i + numsLen] = nums[i];
        }

        return ans;
    }
};