class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        vector<int> counts(26, 0);
        int max_count =0;
        int best = 0;
        for (int r = 0; r<s.size();r++){

            counts[s[r]-'A']++;
            max_count = max(max_count, counts[s[r]-'A']);

            while (r-l+1-max_count>k){
                counts[s[l]-'A']--;
                l++;
            }

            best = max(best, r-l+1);
        }

        return best;
    }
};
