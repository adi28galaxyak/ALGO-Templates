// Given A line of the form ax+by+c=0 and a point (x1,y1) on cartisian plane. Finding the distance between the line and the point

#include<bits.std++.h>
using namespace std;
#define ll long long
#define ld long double
ld distance(ll A,ll B,ll C,ll X1,ll X2)
{
	return abs((ld)(A*X1+ B*Y1+ C)/ (ld)sqrtl(A*A + B*B));
}
int main()
{
	ll A,B,C,X1,X2;
	ld dis;
	scanf("%lld %lld %lld",&A,&B,&C);    // Takes the coefficients of x and y and constant 'C' as input

	scanf("%lld %lld",&X1,&Y1);
	dis= distance(A,B,C,X1,X2);
	printf("%Lf\n",dis);N
}