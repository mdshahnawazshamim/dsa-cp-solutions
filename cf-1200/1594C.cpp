#include <bits/stdc++.h>
using namespace std;


void solve()
{
        int n;cin>>n;
	    char c;cin>>c;
	    string s;cin>>s;
	    
	    bool all_c = true;
	    for(int i=0;i<n;++i)
	    {
	        if(s[i]!=c)
	        {
	            all_c=false;
	            break;
	        }
	    }
	    
	    if(all_c)
	    {
	        cout<<0<<"\n";
	        return;
	    }
	    
	    for(int x=1;x<=n;++x)
	    {
	        bool valid = true;
	        for(int i=x;i<=n;i+=x)
	        {
	            if(s[i-1]!=c)
	            {
	                valid=false;
	                break;
	            }
	        }
	        if(valid)
	        {
	            cout<<1<<"\n"<<x<<"\n";return;
	        }
	    }
	    
	    cout<<2<<"\n"<<n<<" "<<n-1<<"\n";
}
 
int main() {
	
	int t;cin>>t;
	while(t--)
	{
	    solve();
	}
 
}
