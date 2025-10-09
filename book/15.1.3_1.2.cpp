#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200000];
struct node
{
int x,p;
node(){}
node(int xx,int pp){x=xx;p=pp;}
}list[20000];
int main()
{
int n,k,cnt=0;
while(scanf("%d%d",&n,&k)==2) //读入 n 和 k
{
printf("Case %d\n",++cnt);
for(int i=1;i<=n;i++) scanf("%d",&a[i]); //读入原始序列a[1..n]
int head=1,tail=1;
list[1]=node(a[1],1);
for(int i=1;i<=n;i++)
{
while(head<=tail&&list[tail].x<=a[i]) tail--; //删尾
list[++tail]=node(a[i],i); //得到最优解并插入
while(i-list[head].p>=k) head++; //去头
if(i>=k)
{
if(i!=k)printf(" "); //保证行尾部没有多余空格
printf("%d",list[head].x);
}
}
printf("\n");
}
return 0;
}