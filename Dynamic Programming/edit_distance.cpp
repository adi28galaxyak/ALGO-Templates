// Edit-Distance Dynamic Programming Problem

//		Reference: https://en.wikipedia.org/wiki/Edit_distance
//		INPUT: Two Strings
//		OUTPUT: The cost required to change string-1 into string-2 


#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<vector<int> > a;
int editDistance(string s1, string s2)
{
	int i,j;
	for(i=0;i<=s1.size();++i) a[i][0]=i;
	for(i=0;i<=s2.size();++i) a[0][i]=i;

	for(i=1;i<=s1.size();++i)
	{
		for(j=1;j<=s2.size();++j)
		{
			if(s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1];
			else
			a[i][j]=min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]))+1;
		}
	}
	return a[s1.size()][s2.size()];   //returning the cost to change string s1 into string s2

}
