#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
//#include<map>
#define ll long long
#define mset(a,x) memset(a,x,sizeof(a))

using namespace std;
const double PI=acos(-1);
const int inf=0x3f3f3f3f;
const double esp=1e-6;
const int maxn=1e6+5;
const int mod=1e9+7;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll inv(ll b){if(b==1)return 1; return (mod-mod/b)*inv(mod%b)%mod;}
ll fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n%mod;n=n*n%mod;}return r;}
ll Fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n;n=n*n;}return r;}
ll upd(ll x,ll v){x=x+v>=mod?x+v-mod:x+v;return x;}
int vis[maxn],dis[maxn],s[maxn];
int mapp[10005][10005];
struct path{
	int u,v,w;
}a[100005];
	int n,m;
	ll ans;
void spfa(int st){
	int u,v;
	queue <int>q;
	q.push(st);
	vis[st]=1;
	dis[st]=0;
	s[st]=0;
	while(!q.empty()){
		u=q.front();
		q.pop();
		vis[u]=0;
		//printf("uu=%d\n",u); 
		for(int i=1;i<=n;i++){
			if(dis[i]>=dis[u]+mapp[u][i]){
				if(dis[i]>dis[u]+mapp[u][i]){
					dis[i]=dis[u]+mapp[u][i];
					s[i]=mapp[u][i];
					if(!vis[i]){
						q.push(i);
						vis[i]=1;
					}
				}
				else
					if(s[i]>mapp[u][i])
						s[i]=mapp[u][i];
			}
		/*	for(int i=1;i<=n;i++)
			printf("%d ",dis[i]);
			printf("\n");
				for(int i=1;i<=n;i++)
				printf("%d ",s[i]);
					printf("\n");*/
		}
	}
	for(int i=1;i<=n;i++)
		ans+=s[i];
}
int main(){
	int st;
	int x,y,z;
	while(~scanf("%d%d",&n,&m)){
		mset(vis,0);
		mset(dis,inf);
		mset(s,inf);
		mset(mapp,inf);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			mapp[x][y]=mapp[y][x]=z;
		}
		scanf("%d",&st);
		spfa(st);
		printf("%lld",ans);
	}
	return 0;
} 
