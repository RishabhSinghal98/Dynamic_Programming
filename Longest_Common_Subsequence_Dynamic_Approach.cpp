#include<bits/stdc++.h>
using namespace std;

int findlcs(string a,string b)
{
	vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0)); // created 2d dp
	int ans=0;
	
	for(int i=a.size()-1;i>=0;i--)  //starting loop from end till starting
	{
		for(int j=b.size()-1;j>=0;j--)  //starting loop from end till starting index
		{
			if(a[i]==b[j])
			{
				ans=1+dp[i+1][j+1];    // if both characters are same 
			}
			else
			{
				ans=max(dp[i+1][j],dp[i][j+1]);   // if characters are not same so two cases either i+1 or j+1
			}
			dp[i][j]=ans;         //strore the ans 
		}
	}
	return dp[0][0];    // return the ans stored from o index as we started from last index
}




int main()
{
	string a;
	string b;
	cout<<"Enter First String"<<endl;
	cin>>a;
	cout<<"Enter Second String"<<endl;
	cin>>b;
	int ans=findlcs(a,b);
	
	cout<<"The Length of Common Subsequence is "<<ans;
	return 0;
	
}
