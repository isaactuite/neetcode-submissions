class Solution {
public:
    int maxArea(vector<int>& heights) {
        int hi, lo;
        hi = heights.size()-1;
        lo=0;
        int largest = 0;
        while (lo<hi){
            int sum = min(heights[hi], heights[lo])*(hi-lo);
            if (sum>largest) largest = sum;

            if (heights[lo]>heights[hi]){
                hi--;
            } else if (heights[lo]<=heights[hi]){
                lo++;
            }


        }

        return largest;

    }
};
