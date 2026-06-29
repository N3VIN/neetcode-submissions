class Solution {
   public:
    bool isValid(string s) {
        std::vector<char> cStack;
        for (auto c : s) {
            if ((c == '(') || (c == '{') || (c == '[')) {
                cStack.push_back(c);
            } else {
                if (cStack.empty()) return false;

                auto top = cStack.back();
                if ((c == ')' && top == '(') || (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    cStack.pop_back();
                } else {
                    return false;
                }
            }
        }

        return cStack.empty();
    }
};