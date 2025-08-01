class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v;
        
        for(int i=1;i<=n;i++)
        {   
            long long ans =1;
            vector<int> temp;
            temp.push_back(ans);
            for(int j=1;j<i;j++)
            {
                ans = ans * (i-j);
                ans = ans / j;
                temp.push_back(ans);
            }
            v.push_back(temp);
        }
        return v;
    }
};