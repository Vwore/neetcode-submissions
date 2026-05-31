class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefix(n,-1),suffix(n,-1);
        int maxNum=-1;
        for(int i=0;i<n;i++)
        {
            prefix[i]=maxNum;
            maxNum=max(maxNum,height[i]);
        }   
        maxNum = -1;
        for(int i=n-1;i>=0;i--)
        {
            suffix[i]=maxNum;
            maxNum=max(maxNum,height[i]);
        }   

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(height[i]<prefix[i] && height[i]<suffix[i])
            {
                ans+= min(prefix[i],suffix[i])-height[i];
            }
        }
        return ans;
    }
};
