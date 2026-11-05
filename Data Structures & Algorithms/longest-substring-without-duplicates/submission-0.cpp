class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        if (s.empty()) return 0;

        int l=0;
        int longest = 0;
        int current_longest = 0;
        for (int r = 0; r<s.size(); r++){
            while(charset.contains(s[r])){
                charset.erase(s[l]);
                l++;
            }
            
            charset.insert(s[r]);
            longest = max(longest, r-l+1);

            
        }

        return longest;
    }
};
