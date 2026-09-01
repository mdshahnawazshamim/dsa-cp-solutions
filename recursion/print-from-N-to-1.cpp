#include <bits/stdc++.h>
using namespace std;

void print(int N)
{
    cout<<N;
    if(N==1){return;}
    cout<<" ";
    print(N-1);
    
}

int main() {
	
	int N;cin>>N;
	
	print(N);
}

