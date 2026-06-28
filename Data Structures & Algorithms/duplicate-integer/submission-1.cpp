class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::ranges::sort(nums);
        return std::ranges::adjacent_find(nums) != nums.end(); 
    }
};