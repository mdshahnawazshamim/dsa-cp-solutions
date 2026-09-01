#include <bits/stdc++.h>
using namespace std;

void print(int N)
{   
    if(N==1)
    {
        cout<<1<<"\n";return;
    }
    print(N-1);cout<<N<<"\n";
    
}

int main() {
	
	int N;cin>>N;
	
	print(N);
	
}
