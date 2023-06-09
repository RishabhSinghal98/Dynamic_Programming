#include<bits/stdc++.h>
using namespace std;

int minimumcoins(vector<int>&coins,int n)
{
	vector<int> dp(n+1,INT_MAX); //indexing of vector represent amount
	
	dp[0]=0; //initializing dp[0]=0 as for making 0 amount we need 0 coins 

	
	for(int i=1;i<=n;i++) // running loop from 1 to n i.e total amount
	{
		for(int j=0;j<coins.size();j++) // running loop from 0 to coins(vector) size
		{
			if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
			{
			   dp[i]=min(dp[i],1+dp[i-coins[j]]);
	       	}
			
		}
	 
	}
	if(dp[n]==INT_MAX) return -1;
	
	else return dp[n];
	
			
	
}
int main()
{
	vector<int> coins={7,5,1};
	int n=18;
	
	int ans=minimumcoins(coins,n);
	if(ans==-1) cout<<"No Minimum Number of coins";
	else cout<<"Minimim Number of coins are "<<ans;
}
