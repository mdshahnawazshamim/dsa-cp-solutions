//GeeksforGeeks

class Solution {
  public:
    string removePair(string &s) {
        
       if(s.empty()) return "-1";
       int n = s.size();
       stack<char> st;
       st.push(s[0]);
       
       for(int i=1;i<n;++i)
       {
           if(st.size()>0 && s[i]==st.top())
           {
               st.pop();
           }
           else
           {
               st.push(s[i]);
           }
       }
       if(st.size()==0)
       {
           return "-1";
       }
       else
       {   string ans="";
           while(st.size()!=0)
           {
               ans.push_back(st.top());
               st.pop();
           }
           for(int i=0;i<ans.size()/2;++i)
           {
               swap(ans[i],ans[ans.size()-1-i]);
           }
           return ans;
       }
        
    }
};

