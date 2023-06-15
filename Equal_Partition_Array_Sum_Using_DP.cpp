#include<bits/stdc++.h>
using namespace std;

// DP Top Down Approach

int solvepartition(int index,vector<int>&nums,int target,vector<vector<int>>& dp)
{
	if(index>nums.size()) return 0;
	if(target<0) return 0;
	
	if(target==0) return 1;
	
	if(dp[index][target]!=-1) return dp[index][target]; // step 3
	
	int include=solvepartition(index+1,nums,target-nums[index],dp);
        int exclude=solvepartition(index+1,nums,target-0,dp);
	
	 return dp[index][target]=include or exclude; // step 2 store ans in dp
	
	
}

int main()
{
	int n,num;
	vector<int> nums;
	cout<<"Enter Size of Array"<<endl;
	cin>>n;
	cout<<"Enter Array Elements"<<endl;
	for(int i=0;i<n;i++)
	{
	    cin>>num;
		nums.push_back(num);
	}
	int total_sum=0;
	int ans;

	
	for(auto x:nums)
	{
		total_sum+=x; //calcuating total_Sum
	}
	vector<vector<int>> dp(nums.size()+1,vector<int>(total_sum/2+1,-1)); // step 1 create dp

	if(total_sum%2==0) // if totalsum is divided by 2 then only we will call function as then only ans is possible
	{
		ans=solvepartition(0,nums,total_sum/2,dp);
	}
	if(ans==1) cout<<"True";
	else cout<<"False";

	
	return 0;
}
