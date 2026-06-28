class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       std::erase_if(nums, [val](int i){
        return i == val;
       });

       return nums.size();
    }
};