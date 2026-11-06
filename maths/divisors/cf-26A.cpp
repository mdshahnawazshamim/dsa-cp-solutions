#include <bits/stdc++.h>
using namespace std;

bool solve(int n)
{
   int count=0;
   int flag=0;

   for(int i=2;i*i<=n;++i)
   {
     while(n%i==0)
     { 
        n/=i;
        if(flag==0)
        {
            count++;
            flag=1;
        }
     }
     flag=0;
     
   }
   if(n>1){count++;}
   if(count==2){return true;}
   else{return false;}
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int n;cin>>n;
   int almost_prime=0;

   while(n>5)
   {
    bool a=solve(n);
    if(a){almost_prime++;}
    n--;
   }
   cout<<almost_prime;

}


