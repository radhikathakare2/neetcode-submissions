class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(int x : nums)
            mp[x]++;

        vector<int> ans;

        int limit = nums.size()/3;

        for(auto it : mp){
            if(it.second > limit)
                ans.push_back(it.first);
        }

        return ans;
    }
};