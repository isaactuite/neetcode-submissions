class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int lo = 0; lo<numbers.size()-1; lo++){
            int hi =numbers.size()-1;
            while (numbers[lo] + numbers[hi] >= target && lo<hi){
                if (numbers[lo]+numbers[hi]==target){
                    return {lo+1, hi+1};
                }
                hi--;
            }
        }
        return {};
    }
    
};
