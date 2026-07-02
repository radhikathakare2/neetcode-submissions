class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (nums[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (nums[mid] < target)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
    }
};
