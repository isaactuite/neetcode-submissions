class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pre(height.size());
        vector<int>suf(height.size());

        int largest = 0;
        for (int i = 0; i<height.size(); i++){
            if (height[i]>largest){
                largest=height[i];
            }
            pre[i]=largest;
        }
        largest = 0;
        for (int i = height.size()-1; i>=0; i--){
            if (height[i]>largest){
                largest=height[i];
            }

            suf[i]=largest;
        }

        int total = 0;

        for (int i = 0; i<height.size(); i++){
            total+=min(pre[i], suf[i])-height[i];
        }



        return total;
    }

};
