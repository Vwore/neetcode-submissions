class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int  n = points.size();
        vector<pair<double,int>> dist;
        for(int i=0;i<n;i++)
        {
            double length = sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
            dist.push_back({length,i});
        }
        sort(dist.begin(),dist.end());
        // for(int i=0;i<n;i++)
        // {
        //     cout<<dist[i].first<<" ";
        //     cout<<points[dist[i].second][0]<<","<<points[dist[i].second][1]<<endl;
        // }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++)
        {

            ans.push_back(points[dist[i].second]);
        }
        return ans;
    }
};
