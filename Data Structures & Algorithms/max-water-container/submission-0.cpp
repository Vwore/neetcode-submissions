class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0,r=n-1,ans=0;
        while(l<r)
        {
            int width = r-l;
            if(heights[l]<heights[r])
            {
                ans=max(ans,width*heights[l]);
                l++;
            }
            else if(heights[l]>heights[r])
            {
                ans=max(ans,width*heights[r]);
                r--;
            }
            else{
                ans=max(ans,width*heights[l]);
                r--;
                l++;
            }
        }
        return ans;
    }
};
