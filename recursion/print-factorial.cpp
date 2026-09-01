#include <bits/stdc++.h>
using namespace std;

unsigned long long Print(unsigned long long  N)
{
    if(N==0)
    {
        return 1;
    }
    
    return Print(N-1) * N;
}
    

int main() {
	unsigned long long N;cin>>N;
	cout<<Print(N);
}
