#include "bits/stdc++.h"
#define LL long long int

long double dist(pair<LL, LL> &A,pair<LL, LL> &B){
	return sqrtl((A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second));
}

int main(){
	pair<LL, LL> A, B;
	cin>>A.first>>A.second;
	cin>>B.first>>B.second;
	cout<<dist(A,B);
}