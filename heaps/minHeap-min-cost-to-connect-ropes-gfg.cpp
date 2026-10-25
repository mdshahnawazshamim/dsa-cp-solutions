class Solution {
  public:
    int minCost(vector<int>& arr) {
        
        int N = arr.size();
        
        priority_queue<int,vector<int>,greater<int>> pq(arr.begin(),arr.end());
        
        long long sum = 0;
        
        while(pq.size()!=1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int c = a+b;
            sum+=c;
            pq.push(c);
        }
        return sum;
        
    }
};
