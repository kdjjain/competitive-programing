#include <bits/stdc++.h>                
using namespace std;
#define int long long int 
#define ff first
#define ss second
#define ll  int 
#define p 1000000007
vector<int >g[100005];
int vis[100005];
vector<double >ans;
int ncr[2005][2005];
int fact[1000000];
int inv[1000000];
void cal(){
	ncr[0][0]=1;
	for(int i=1; i<=2004; i++)
	{
		ncr[i][0]=1,ncr[i][i]=1;
		for(int j=1; j<i; j++)
		{
			ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1]);
		}
	}
	
}
int nck(int x, int y)
{
	return ncr[x][y];
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void cal1(){
	fact[0]=1;
	for(int i=1; i<1000000; i++)
	{
		fact[i]=(fact[i-1]*i)%p; //if(i<10)cout << fact[i]<<" ";
	}
	for(int i=0; i<1000000; i++)
	{
		inv[i]=binpow(fact[i],p-2,p);
	}
}

int val(char x)
{
	if(x>='0' && x<='9')
	return x-'0';
	if(x>='A' && x<='Z')
	return x-'A'+10;
	if(x>='a' && x<='z')
	return x-'a'+36;
	if(x=='-')
	return 62;
	if(x=='_')
	return 63;
}
int bit(int x)
{
	int c=0;
	while(x>0)
	{
		if(x%2==1)
		c++;
		x=x/2;
	}return c;
}


int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   cal1();
   int q=1 ;
   //cin >> t;
   while(q--)
   {   int n;
       cin >> n;
       int ans=1,j=1;
       for(int i=0; i<n ; i++)
       {
       	  int x;
       	  cin >> x;
       	  for(int k=0; k<x-1; k++)
       	  {
       	  	 ans=(ans*j)%p;
       	  	 j++;
       	  }j++;
       	  ans = (ans*inv[x-1])%p;
       } cout << ans;
   	  
   }
                                                                                      
    return 0;
        }
