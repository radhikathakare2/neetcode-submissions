class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());

        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int daysUsed = 1;
            int currentWeight = 0;

            for (int weight : weights) {

                if (currentWeight + weight <= mid) {
                    currentWeight += weight;
                } 
                else {
                    daysUsed++;
                    currentWeight = weight;
                }
            }

            if (daysUsed <= days) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};