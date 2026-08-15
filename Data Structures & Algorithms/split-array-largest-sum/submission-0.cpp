class Solution {
public:
    bool isPossible(vector<int>& nums, int k, long long capacity) {

        int subarrays = 1;
        long long sum = 0;

        for (int num : nums) {

            if (sum + num <= capacity) {
                sum += num;
            }
            else {
                subarrays++;
                sum = num;
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long low = *max_element(nums.begin(), nums.end());

        long long high = 0;

        for (int num : nums)
            high += num;

        long long ans = high;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {

                ans = mid;

                // Try smaller maximum sum
                high = mid - 1;
            }
            else {

                // Need a larger capacity
                low = mid + 1;
            }
        }

        return ans;
    }
};