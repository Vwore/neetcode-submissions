class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l=0,r=n-1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[0]<=target)
            {
                if(target>nums[mid])
                {
                    if(nums[mid]>=nums[0])
                    {
                        l=mid+1;
                    }
                    else r= mid-1;
                }
                else r=mid-1;
            }
            else{
                if(target<nums[mid])
                {
                    if(nums[mid]<nums[0])
                    {
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else{
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};
