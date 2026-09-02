#include <bits/stdc++.h>
using namespace std;

void baseConversion(long N)
{
    if(N==0)
    {
        return ;
    }
   
    baseConversion(N/2);cout<<N%2;
}

int main() {
    
    int t;cin>>t; // t test cases
    
    while(t--)
    {
        long N;cin>>N;
        baseConversion(N);
        cout<<"\n";
    }

}
