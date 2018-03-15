#include<stdio.h>
int main()
{
	freopen("poj1269.in","r",stdin);
	freopen("did.out","w",stdout);
int n,i;
double x1,x2,x3,x4,y1,y2,y3,y4,x,y,a,b,c,d;
scanf("%d",&n);
printf("INTERSECTING LINES OUTPUT\n");
while(n--)
{
scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
a=x1-x2;
b=y1-y2;
c=x3-x4;
d=y3-y4;
if(a*d==b*c)
{
if(b*(x3-x1)==a*(y3-y1))
printf("LINE\n");
else
printf("NONE\n");
}
else
{
x=(a*(x3*y4-y3*x4)-c*(x1*y2-y1*x2))/(c*b-a*d);
y=(b*(x3*y4-y3*x4)-d*(x1*y2-y1*x2))/(c*b-a*d);
printf("POINT %.2lf %.2lf\n",x,y);
}
}
printf("END OF OUTPUT\n");
return 0;
 } 
