class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i<nums.size(); i++){
            if (i>0 and nums[i]==nums[i-1]) continue;
            int lo = i+1; int hi = nums.size()-1;

            while (lo<hi){
                int total = nums[i]+nums[lo]+nums[hi];

                if (total == 0){
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    while(lo<hi && nums[lo] == nums[lo-1]){
                        lo++;
                    }
                }
                else if (total>0){

                    hi--;
                } else if (total<0){
                    lo++;
                }

            }
        }

        return ans;
    }       
};
