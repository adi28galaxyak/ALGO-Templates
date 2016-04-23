// String Interleaving Dynamic Programming Problem

//		Reference: http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings

//		INPUT: Three Strings
//		OUTPUT: Returns true if string-3 is entirely made up of string-1 and string-2 retaining the same order of both the strings otherwise returns false 


#include<bits/stdc++.h>
using namespace std;
bool string_interleaving(string str1, string str2, string str3)
{
	int len1= str1.size(), len2= str2.size();
	bool ar[len2+1][len1+1];
	ar[0][0] = true;
	int len= str3.size();
	//For the first Row
	for(j=0;j<len1;++j)
	{
	    if(str1[j]==str3[j]&& ar[0][j]==true) ar[0][j+1]=true;
	    else ar[0][j+1]=false;
    }
	//For the first column
	for(i=0;i<len2;++i)
	{
	    if(str2[i]==str3[i]&& ar[i][0]==true) ar[i+1][0]=true;
	    else ar[i+1][0]=false;
	}
	
	for(i=1;i<len2+1;++i)
	for(j=1;j<len1+1;++j)
	{
		if(str3[i+j-1]==str1[j-1]&& ar[i][j-1]==true) ar[i][j]=true;
		else if (str3[i+j-1]==str2[i-1]&& ar[i-1][j]==true) ar[i][j]=true;
		else ar[i][j]=false;
	}
	
	(ar[len2][len1]==true&&len==r+d)?return true:return false; 
}