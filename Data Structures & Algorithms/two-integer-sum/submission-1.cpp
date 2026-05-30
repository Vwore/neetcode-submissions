class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapping;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            mapping[nums[i]]=i;
        }

        for(int i=0;i<n;i++)
        {
            // target - nums[i]
            if(mapping.find(target-nums[i]) != mapping.end() && mapping[target-nums[i]]!=i )
            {
                return {i,mapping[target-nums[i]]};
            }
        }
        return {-1,-1};
    }
};
