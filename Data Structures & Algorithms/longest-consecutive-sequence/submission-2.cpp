class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (auto& x : nums) s.insert(x);

        int best_length =0;
        for (auto& x : s){
            if (s.contains(x-1)) continue;
            
            int current = x;
            int length = 0;
            while (s.contains(current)){
                current++;
                length++;
                
            }
            best_length = max(best_length, length);
        }

        return best_length;
    }
};
