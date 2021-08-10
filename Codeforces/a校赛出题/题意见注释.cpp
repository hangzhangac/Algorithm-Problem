//给定n条线段 2*n个端点不重复 问是否存在li<lj<lk<ri<rj<rk的三条线段
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
int book[MAXN];

stack<int>s;
stack<int>q;
int main(){
	gi(n);
	for(int i=1;i<=n;i++){
		int x,y;
		gi2(x,y);
		book[x]=y; //book[i]记录的是 如果i为左端点 book[i]为右端点坐标 如果为右端点 则为0
	}
	for(int i=1;i<=2*n;i++){
		if(book[i]){//当前点是左端点
			int r=book[i];
			if(!q.empty()&&r>q.top()){//判断r大于第二个栈里的栈首
				printf("YES\n");//存在
				return 0;
			}
			if(!s.empty()&&r>s.top()){//若小于第二个栈栈首 却大于第一个栈栈首，则添加到第二个栈中
				q.push(r);
			}
			else s.push(r);//若小于第一个栈栈首，则直接加到第一个栈中
		}
		else{//遍历到这条线的右端点，要删除这条线
			int r=i;
			if(!s.empty()&&s.top()==r){//这里一定是true 它一定会在第一个栈中出现，因为r比它小的线段早已经删除，他不可能出现在第二个栈中
				s.pop(); 
				stack<int>s1;
				while(!q.empty()&&(s.empty()||q.top()<s.top())){//第二个栈中的某一些点，是因为要删除的这条线加到第二个栈中的，要把他们转移回第一个栈
					//也就是说 假设当前要删的线段编号为i 有一些j 满足 rj>ri 他们被加到第二个栈中了，由于删除了i,他们被退回第一个栈。如果他们大于当前栈顶，则不需要返回第一个栈了。
					s1.push(q.top());
					q.pop();
				}
				while(!s1.empty()){//保持第一个栈的单调递减性
					s.push(s1.top());
					s1.pop();
				}
			}
//			else{
//				if(!q.empty()&&q.top()==r){
//					q.pop();
//				}
//			}
		}
	}
	printf("YES\n");
	
	
	
	return 0;
}














