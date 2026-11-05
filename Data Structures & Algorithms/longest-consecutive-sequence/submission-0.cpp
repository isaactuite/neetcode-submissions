class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for (auto& x : nums){
            s.insert(x);
        }
        int longest = 0;
        for (auto& x : s){
            if (s.contains(x-1)) continue;
            int count = 1;
            int current = x;
            while (s.contains(current+1)){
                count++;
                current++;
            }

            if (count > longest) longest = count;

        }
        

        return longest;
    }
};
