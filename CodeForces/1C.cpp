/* ------------------------------*/
/* Created by LinX on 2021/3/26.*/
/* ------------------------------*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

const double PI=acos(-1.0);
const double eps=1e-3;
struct node
{
    double x,y;
};
node a,b,c;
double get_dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double fgcd(double a,double b)
{
    if (fabs(b)<eps) return a;
    return fgcd(b,fmod(a,b));
}

int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=EOF) {
        double A,B,C,D,S,R,ac,bc,ab;
        ac=get_dis(a,c);
        ab=get_dis(a,b);
        bc=get_dis(b,c);
        A=acos((ac*ac+ab*ab-bc*bc)/(2*ac*ab));
        B=acos((bc*bc+ab*ab-ac*ac)/(2*bc*ab));
        C=acos((ac*ac+bc*bc-ab*ab)/(2*ac*bc));
        R=bc/(2*sin(A));
        A*=2,B*=2,C*=2;
        D=fgcd(fgcd(A,B),fgcd(A,C));
        printf("%.8f\n",R*R*sin(D)/2.0*((2*PI)/D));
    }
    return 0;
}