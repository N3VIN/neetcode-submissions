class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto vSize = arr.size();
        std::vector<int> ans(vSize);
        int right = -1;
        int temp = 0;
        for(int i= vSize - 1; i >=0; --i){
            ans[i] = right;

            if(right < arr[i]){
                right = arr[i];
            }
        }

        return ans;

    }
};