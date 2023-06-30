#include<bits/stdc++.h>
using namespace std;

int findlcs(string a,string b,int i,int j,vector<vector<int>>& dp)
{
	int size1=a.size();
	int size2=b.size();
	
	int ans=0;
	
	//base case if i&j reaches size of string i.e out of the string length
	if(i==size1 || j==size2 ) return 0;
	
	if(dp[i][j]!=-1) return dp[i][j];

	// if both characters are equal then increment both i&j;
	if(a[i]==b[j]) 
	{
		ans+=1+findlcs(a,b,i+1,j+1,dp);
	}
	//else if the characters are not equal then either increment i or j and take max of it.
	else
	{
		ans=max(findlcs(a,b,i+1,j,dp),findlcs(a,b,i,j+1,dp));
	}
	return dp[i][j]=ans;
}




int main()
{
	string a;
	string b;
	cout<<"Enter First String"<<endl;
	cin>>a;
	cout<<"Enter Second String"<<endl;
	cin>>b;
	vector<vector<int>> dp(a.size(),vector<int>(b.size(),-1));
	int ans=findlcs(a,b,0,0,dp);
	
	cout<<"The Length of Common Subsequence is "<<ans;
	
	return 0;
	
}
