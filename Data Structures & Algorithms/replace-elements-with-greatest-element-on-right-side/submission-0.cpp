class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> ans(arr.size());
        int right = -1;
        int temp = 0;
        for(int i=arr.size() - 1; i >=0; --i){
            ans[i] = right;

            if(right < arr[i]){
                right = arr[i];
            }
        }

        return ans;

    }
};