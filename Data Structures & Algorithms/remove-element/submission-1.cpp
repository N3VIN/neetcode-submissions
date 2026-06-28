class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      std::vector<int> elements;
      for(auto num : nums){
        if(num != val){
            elements.push_back(num);
        }
      }

      nums = elements;

      return elements.size();
    }
};