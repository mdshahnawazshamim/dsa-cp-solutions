class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        
        int N = arr.size();
        priority_queue<int,vector<int>> f;
        priority_queue<int,vector<int>,greater<int>> s;
        
        vector<double> ans;
        f.push(arr[0]);
        ans.push_back(arr[0]);
        
        for(int i=1;i<N;++i)
        {
            if(arr[i]>f.top())
            {
                s.push(arr[i]);
            }
            else
            {
                f.push(arr[i]);
            }
            
            if(f.size()-s.size()==2)
            {
                s.push(f.top());
                f.pop();
            }
            else if(f.size()-s.size()==-1)
            {
                f.push(s.top());
                s.pop();
            }
            
            int x = f.size()+s.size();
            
            if(x%2==0)
            {
                ans.push_back((double((f.top())+s.top())/2));
            }
            else
            {
                ans.push_back(f.top());
            }
        }
        return ans;
        
    }
};
