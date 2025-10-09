#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500005;
const int MAXQ = 500005;
int Fa[MAXN];
struct Edge{
int to,next;//边的另一端 to，下一条边的编号 next
}edge[MAXN << 1];
struct Query{
int to,next,id; //一个查询的另一点 to，下一个查询的编号 next，查询点对的编号id
}query[MAXQ << 1];
int head[MAXN],qhead[MAXQ],answer[MAXQ];//纪录边的编号、查询的编号及查询结果
int tot,qtot; //tot 和 qtot 分别记树边的编号和查询的编号
int find(int x) //并查集查找祖先
{
return Fa[x] = x == Fa[x] ? x : find(Fa[x]);
}
void Union(int u,int v){//并查集集合合并
int a =find(u),b =find(v);
if (a !=b) Fa[a] =b;
}
void addEdge(int u,int v){ //存储边及倍边
edge[tot] =(Edge){v,head[u]};
head[u] =tot ++;
edge[tot] =(Edge){u,head[v]};
head[v] =tot ++;
}
void addQuery(int u,int v,int id)//存储查询及辅助查询
{
query[qtot] =(Query){v,qhead[u],id};
qhead[u] =qtot ++;
query[qtot] =(Query){u,qhead[v],id};
qhead[v] =qtot ++;
}
void init(){ //结构初始化
tot =qtot = 0;
memset(head, - 1,sizeof(head));
memset(qhead, - 1,sizeof(qhead));
memset(Fa, - 1,sizeof(Fa));
}
void LCA(int u){ //最近公共祖先程序
int i,v;
Fa[u] =u;
for (i =head[u]; ~i;i =edge[i].next)
{
v =edge[i].to; //边的另一端点
if (~Fa[v]) continue;
LCA(v); //继续递归搜索
Union(v,u); //递归结束进行归并到父节点
}
for (i =qhead[u]; ~i;i =query[i].next)
{
v =query[i].to;
if (~Fa[v]) answer[query[i].id] = find(v);
}
}
int main(){
int t,cnt=1,n,u,v,i,Q,root;
while(scanf("%d%d",&n,&Q)==2){//树节点数量 n，查询次数 Q
//printf("Case %d\n", cnt++);
scanf("%d",&root);
init(); //初始化
for (i = 1; i <= n-1; ++i)//输入 n 条边信息，建树
{
scanf("%d%d",&u,&v);
addEdge(u,v);
}
for (i = 1; i <= Q; ++i)//输入 Q 条查询信息，并存储
{
scanf("%d%d",&u,&v);
addQuery(u,v,i);
}
LCA(root); //调用最近公共祖先程序
for (i = 1; i <= Q; ++i){ //输出 Q 次查询结果
printf("%d\n", answer[i]);
}
}
return 0;
}