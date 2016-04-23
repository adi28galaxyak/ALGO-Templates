/* Subset sum problem:- If we are given an array consisting all positive integers and another number, we have to find whether a subset of array consists the numbers whose sum equalises with the given number.  */
// So ar[] is array, l,r are first and last number in the range of a subset and 'w' is the number

//		Reference: http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/

//		INPUT: Range of given Array and the total sum which is to be find
//		OUTPUT: Returns true if sum exist in the given range (adding some of elements of the range) otherwise returns false

#include<bits/stdc++.h>
using namespace std;
vector<int> ar;
bool subset_sum(int l,int r,int w)     // l,r is range inside the array from which we have to search for number whose sum equals the given number 'w'
{
	int i,j,n;
	n= r-l+1;
	bool arr[w+1][n+1];
	for(i=0;i<=n;i++)
	arr[0][i]=true;
	for(i=1;i<=w;i++)
	arr[i][0]=false;
	for(i=1;i<=w;i++)
	{
		for(j=1;j<=n;j++)
		{
			arr[i][j]=arr[i][j-1];
			if(i>=a[l+j-1])
			arr[i][j]= arr[i][j] || arr[i-a[l+j-1]][j-1];
		}
	}
	for (i=0;i<=w;i++)
    {
       for (j=0;j<=n;j++)
       printf("%4d",arr[i][j]);
       printf("\n");
    }
	return arr[w][n];
}