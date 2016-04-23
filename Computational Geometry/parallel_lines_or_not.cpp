// Given Two lines of the form ax+by+c=0 and lx+my+n=0 on cartisian plane. Determining whether they are parallel, Coincident or Perpendicular or not.

#include<bits.std++.h>
using namespace std;
#define ll long long
#define ld long double
bool isParallel(ll A,ll B,ll C,ll L,ll M,ll N)
{
	if((A*M== B*L)&& (A*N != L*C)&& (B*N !=M*C)) return true;
	else return false;
}
bool isCoincident(ll A,ll B,ll C,ll L,ll M,ll N)
{
	if((A*M== B*L)&& (A*N == L*C)&& (B*N ==M*C)) return true;
	else return false;
}
bool isPerpendicular(ll A,ll B,ll C,ll L,ll M,ll N)
{
	if((A*L +B*M)==0) return true;
	else return false;
}
int main()
{
	ll A,B,C,L,M,N;
	scanf("%lld %lld %lld",&A,&B,&C);      // Takes the coefficients of x and y and constant 'C' for the first line as input 
	scanf("%lld %lld %lld",&L,&M,&N);      // Takes the coefficients of x and y and constant 'N' for the second line as input

	bool check= isParallel(A,B,C,L,M,N);
	(check)?printf("Yes\n"):printf("No\n");
	
}