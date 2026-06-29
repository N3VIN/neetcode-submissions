class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto vSize = arr.size();
        int right = -1;
        for(int i= vSize - 1; i >=0; --i){
            int num = arr[i];
            arr[i] = right;
            right = max(right, num);
        }

        return arr;

    }
};