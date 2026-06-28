class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int counter{0};
       int result{0};

       for(auto num : nums){
        if(num == 1){
            ++counter;
        }
        else{
            result = max(result, counter);
            counter = 0;
        }
       }

       return max(result, counter);
    }
};