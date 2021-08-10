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
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=100005;
vector<int>ans;
int ms[1000006];
int main()
{
	//cout << "请输入一个整数" << endl;
	int num;
	cin >> num;
	if(num==1){
		printf("1 0\n");
		return 0;
	}
	int i;
	int maxn=0;
	for (i = 2;i <= num;i++)//核心代码
	{
		while (num != i)//先确定num不等于2
			if (num%i == 0)//当num/i没有余数时，说明i是num的一个质数
			{
				if(ms[i]==0){
					ms[i]=1;
					ans.push_back(i);
				}
				else
				ms[i]++;
				maxn=max(maxn,ms[i]);
				num = num / i;//取num/i整数部分
			}
			else break;//然后跳出，重新来，此时num变了，i也变成2了，因为重新开始
	}
	if(ms[num]==0){
		ans.push_back(num);
	}
	ms[num]++;
	int t=1;
	for(int i=0;i<ans.size();i++){
		t*=ans[i];
	}
	printf("%d ",t);
	int mmax=0;
	int cnt=0;
	int ff=0;
	int pos=-1;
	for(int i=2;i<=1000000;i++){
		if(ms[i]){
			if(ms[i]!=1)
			ff++;
			mmax=max(mmax,ms[i]);
			if(ms[i]&1){cnt=1;}
		}
	}
	if(!ff){
		
		printf("0\n");
		return 0;
	}
	if(cnt==1){
		int t=log2(mmax)+eps;
		if((1<<t)==mmax)
		cnt+=t;
		else{
			cnt++;
			cnt+=t;
		}
	}
	else{
		
		int t=log2(mmax)+eps;
		cnt+=t;
		//cout<<"fea"<<t<<endl;
		if((1<<t)==mmax){
			//cout<<"fea"<<t<<endl;
			for(int i=1;i<=1000000;i++){
				if(ms[i]&&ms[i]!=mmax){
					cnt++;break;
				}
			}
		}
		else{
			cnt+=2;
			//cnt+=t;
		}
	}
	printf("%d\n",cnt);
	
	return 0;
}
