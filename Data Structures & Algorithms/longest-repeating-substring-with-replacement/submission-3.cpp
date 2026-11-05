class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int maxFreq = 0;
        int best = 0;
        int l =0;
        for (int r=0; r<s.size(); r++){
            m[s[r]]++;
            maxFreq = max(maxFreq, m[s[r]]);

            while (r-l+1-maxFreq>k){
                m[s[l]]--;
                l++;
            }

            best = max(best, r-l+1);


        }

        return best;
    }
};
