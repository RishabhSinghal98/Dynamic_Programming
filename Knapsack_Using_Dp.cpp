#include<bits/stdc++.h>
using namespace std;
//Top Down Approach

int find_profit(int index,vector<int>& weight,vector<int> & profit,int capacity,vector<vector<int>> dp)
{ 
     // base case
	if(index==0) //When I reach at index 0 while moving from right to left
	{
		if(weight[0]<=capacity) //If weight of that index is less tha my max_weight than omly i will include it otherwise return 0
		{
			return weight[0];
		}
		else return 0;
	}
	if(dp[index][capacity]!=-1) return dp[index][capacity];
	
	int include=0; // defining include over here bcoz want to use include out of if block also
	if(weight[index]<=capacity) 
	{
	  include=profit[index]+find_profit(index-1,weight,profit,capacity-weight[index],dp); // if we include that index than we will decrease the capacity by that index weight and will add profit of that index to includ
    }    
	 
	int exclude=0+find_profit(index-1,weight,profit,capacity,dp);// if we exclude that index than we wont decrease the capacity and wont add that indexes profit
	 
	dp[index][capacity]=max(include,exclude); // at last we will take max value of both and then return to its reccursive call
    
	return dp[index][capacity];	
}

int main()
{
	int n=3;
	vector<int> profit={60,100,120};
	vector<int> weight={10,20,30};
	
	int max_weight=50;
	
	vector<vector<int>> dp(n,vector<int>(max_weight+1,-1));//step 1 created 2d Dp as index and max_weight value is getting changed in reccursive calls
	
	int ans=find_profit(n-1,weight,profit,max_weight,dp); 
	
	cout<<"The maximum Profit is "<<ans;
}
