//KEY LEARNINGS:
    //To check whether a product is divisible by a number,
    //compare the prime factors required by that number with the prime factors available in the product.
    //Example: 12 = 2^2 * 3, so the product must contain atleast 2 factors of 2 and 1 factor of 3.

#include <bits/stdc++.h>
using namespace std;

void solve() {
 int n,k;cin>>n>>k;
 vector<int> v(n);
 int mini =INT_MAX;
 int evencount=0;
 for(int i=0;i<n;++i)
 {
    cin>>v[i];
    if(v[i]%2==0){evencount++;}
    int a = (k-(v[i]%k))%k;
    mini = min(mini,a);
 }
 if(k==4)
    {
        if(evencount>=2)
        {
            mini=0;
        }
        else if(evencount>=1)
        {
            mini = min(mini,1);
        }
        else
        {
             mini = min(mini,2);
        }
    }

 cout<<mini<<"\n";
 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
