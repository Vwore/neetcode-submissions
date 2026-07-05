class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea =-1;
        vector<int> span;
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(j>=0 && heights[j]>=heights[i])    j--;
            int leftSpan = i-j;
            j=i;
            while(j<n && heights[j]>=heights[i]) j++;
            int rightSpan = j-i;
            
            int totalSpan =leftSpan+rightSpan-1;
            maxArea = max(maxArea, totalSpan*heights[i]);
        }
        return maxArea;
    }
};
