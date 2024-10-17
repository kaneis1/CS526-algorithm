#include<iostream>
#include<cmath>
using namespace std;
int n;
int f[20][20];
int a[20];
int history[20];
int F(int x,int y,int p)
{
    if(x==y)return -a[x];
    if(p)
    return max(F(x+1,y,0)+a[x],F(x,y-1,0)+a[y]);
    else
    return max(F(x+1,y,1)-a[x],F(x,y-1,1)-a[y]);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cout<<F(1,n,1,n/2)<<endl;
    for(int i=0;i<n/2;i++)
    cout<<history[i]<<" ";
}