//Use of Binary Exponentiation / Fast Power
//Use of Modular Inverse using Fermat's Little Theorem
//Use of Begger's Method

#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

long long power(long long a, long long b)
{
    long long res=1;
    
    while(b)
    {
        if(b%2)
        {
            res= res*a % MOD;
        }
        
        a = a*a % MOD;
        b>>=1;
    }
    return res%MOD;
}


long long nCr(long long n, long long r)
{ long long ans1=1;
  long long ans2=1;
  long long i =1;
  
  r=min(r,n-r);
  
  while(r--)
  {
      ans1*=n;
      ans1%=MOD;
      
      ans2*=i;
      ans2%=MOD;
      
      i++;
      n--;
  }
  
  long long invans2 = power(ans2,MOD-2);
  return ans1 * invans2 % MOD;
 
}

int main() {
	long long n;cin>>n;
   long long ans = (2*(nCr(n+n-1,n-1))%MOD-n+MOD)%MOD;
   cout<<ans;
}
