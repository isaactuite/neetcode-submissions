class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i<nums.size(); i++){
            if (i>0 && nums[i] == nums[i-1]) continue;

            int lo = i+1;
            int hi = nums.size()-1;

            while (lo<hi){
                int sum = nums[i]+nums[lo]+nums[hi];
                if (sum==0){
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    lo++;
                    while (nums[lo]==nums[lo-1] && lo<hi){
                        lo++;
                    }

                    
                }
                else if (sum>0){
                    hi--;
                } else if (sum<0){
                    lo++;
                }
            }
        }

        return ans;
    }
};
