class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_set <int> st;
        int n= nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]!=i)
            {
                if(nums[nums[i]]==nums[i]) return nums[i];
                else{
                    int temp=nums[nums[i]];
                    nums[nums[i]]=nums[i];
                    nums[i]=temp;
                }
            }
            else{
                i++;
            }
        }
        return -1;
    }
};
