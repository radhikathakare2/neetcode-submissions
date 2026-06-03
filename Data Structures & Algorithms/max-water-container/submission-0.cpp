class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lp=0;
        int rp = heights.size()-1;
        int maxWater = 0;
        while(lp<rp){
            int w = rp-lp;
            int ht = min(heights[lp], heights[rp]);
            int area = w * ht;

            maxWater = max(maxWater,area);

            heights[lp]<heights[rp]? lp++ : rp--;
        }
        return maxWater;
    }
};
