//主席树 求区间<=H的数的数量
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=200005;
const ll mod=1e7+9;
const int inf=0x3f3f3f3f;
int read(){     //输入外挂

	int res=0,ch,flag=0;
	if((ch=getchar())=='-')
		flag=1;
	else if(ch>='0'&&ch<='9')
		res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return flag?-res:res;
}
//使用：  v=read();
void Out(int a){    //输出外挂
	if(a>9)
		Out(a/10);
	putchar(a%10+'0');
}
//使用：  Out(ans[i]);
struct Node{
	int L,R;
	int sum;
}node[MAXN*20];
struct ques{
	int L,R,H;
}q[MAXN];
int a[MAXN],root[MAXN];
int b[MAXN*2];//用于离散化的数组
int n,m,cnt;
int ms[MAXN];//数据较大时开成map
int flag=0;//用于初始化的最大下标
void init(){
	root[0]=0;
	cnt=1;//一定要用1
	node[0].L=node[0].R=node[0].sum=0;
	/*for(int i=0;i<=flag;i++){
		node[i].L=node[i].R=node[i].sum=0;
	}*/ //其实不需要
}
void update(int p,int &rt,int l,int r){
	node[cnt++]=node[rt];
	rt=cnt-1;
	node[rt].sum++;
	flag=rt;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)update(p, node[rt].L, l, mid);
	else update(p, node[rt].R, mid+1, r);
}
/*  别人家的query函数
int query(int i,int j,int x,int l,int r){
	if(l == r)  return tree[i].sum - tree[j].sum;
	int mid = (l+r)>>1,ret = 0;
	if(x <= mid)    ret += query(tree[i].ls,tree[j].ls,x,l,mid);
	else{
		ret += tree[tree[i].ls].sum - tree[tree[j].ls].sum;
		ret += query(tree[i].rs,tree[j].rs,x,mid+1,r);
	}
	return ret;
}*/
// lr是要查询的区间  LR是数字的范围 返回个数 !!!!!!!!!
int query(int rt,int l,int r,int L,int R){
	if(R<L)return 0;
	if(!rt)return 0;
	if(l>=L&&r<=R){
		return node[rt].sum;
	}
	int mid=(l+r)>>1;
	int res=0;
	if(L<=mid)res+=query(node[rt].L, l, mid, L, R);
	if(R>=mid+1)res+=query(node[rt].R, mid+1, r, L, R);
	return res;
}
int main(){
	int T,cnt=1;
	gi(T);
	while(T--){
		printf("Case #%d:",cnt++);
		scanf("%d",&n);
		init();
		int len=0;
		for(int i=1;i<=n;i++){a[i]=read();b[++len]=a[i];}
		
		for(int i=1;i<=n;i++){
			b[++len]=i;
		}
		sort(b+1,b+len+1);
		int le=unique(b+1, b+len+1)-b-1;
		for(int i=1;i<=le;i++)ms[b[i]]=i;//当value范围小的时候 ms开成int型数组即可 不需要开map
		//其实是一种权值线段树 所有要离散化一下 必须把query里的值也添加进来共同离散化
		for(int i=1;i<=n;i++)a[i]=ms[a[i]];
		for(int i=1;i<=n;i++){
			root[i]=root[i-1];
			update(a[i], root[i], 1, le);	//le是离散化后的value的最大值
		}
		for(int i=1;i<=n;i++){
			q[i].L=1;q[i].R=i;
			int l=0,r=q[i].R-q[i].L+1;
			int ans=0;
			while(l<=r){
				int mid=(l+r)/2;
				int mm=ms[mid],nn=le;
				int t1=query(root[q[i].L-1],1,le,mm,nn);
				int t2=query(root[q[i].R],1,le,mm,nn);
				if(t2-t1>=mid){
					ans=mid;
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			putchar(' ');
			Out(ans);
		//	cout<<endl;
			
		}
		putchar('\n');
	}
	
	return 0;
}
