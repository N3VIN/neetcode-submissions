class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto vSize = arr.size();
        int right = -1;
        for(auto it = arr.rbegin(); it != arr.rend(); ++it){
            int num = *it;
            *it = right;
            right = max(right, num);
        }

        return arr;

    }
};