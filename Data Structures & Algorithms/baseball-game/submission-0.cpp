class Solution {
   public:
    int calPoints(vector<string>& operations) {
        std::vector<int> adds;
        for (auto op : operations) {
            if (op == "+") {
                adds.push_back(adds.back() + adds[adds.size() - 2]);
            } else if (op == "D") {
                adds.push_back(adds.back() * 2);
            } else if (op == "C") {
                adds.pop_back();
            } else {
                adds.push_back(std::stoi(op));
            }
        }
        
        return std::accumulate(adds.begin(), adds.end(), 0);
    }
};