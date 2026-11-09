class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;

        backtrack(nums, target, 0, cur, res);
        return res;


    }

    void backtrack(vector<int>& nums, int remaining, int start, vector<int>& cur, vector<vector<int>>& res){
        if (remaining == 0){
            res.push_back(cur);
            return;
        }

        for (int i = start; i<nums.size(); i++){
            if (nums[i]>remaining) break;
            cur.push_back(nums[i]);
            backtrack(nums, remaining-nums[i], i, cur, res);
            cur.pop_back();
        }
        
    }
};
