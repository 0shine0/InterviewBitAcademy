/**
 *   author: sahushivam
 *   created: 11 November 2019 (Monday)  14:51:43
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,a,b) for(int i = a; i<b; i++)
#define MOD 1000000007
#define INF 1e18
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int long long
#define N 200005
vector<int> gp1[N],gp2[N];
vector<int> vis1(N),comp(N),vis3(N),vis4(N);
vector<set<int>> gp3(N);

void init()
{
	for(int i=0;i<N;i++)
	{	
		gp1[i].clear(); gp2[i].clear();
		vis1[i]=0; comp[i]=-1; vis3[i]=0; vis4[0];
	}
}
void dfs1(int n,vector<int> &s)
{
	vis1[n]=1;
	for(auto c:gp1[n])
	{
		if(!vis1[c])
			dfs1(c,s);
	}
	s.PB(n);
}

void dfs2(int n,int com)
{
	comp[n]=com;
	for(auto c:gp2[n])
	{
		if(comp[c]==-1)
			dfs2(c,com);
	}
}
void dfs3(int n,vector<int> &s)
{
	vis3[n]=1;
	for(auto c:gp3[n])
	{
		if(!vis3[c])
			dfs3(c,s);
	}
	s.PB(n);
}
void dfs4(int n)
{
	vis4[n]=1;
	for(auto c: gp3[n])
	{
		if(!vis4[c])
			dfs4(c);
	}
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    int n,m;
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	a--; b--;
    	gp1[a].PB(b);
    	gp2[b].PB(a);
    }
    vector<int> s;

    for(int i=0;i<n;i++){
    	if(!vis1[i]){
    		dfs1(i,s);
    	}
    }

    reverse(s.begin(),s.end());
    int com=0;
    for(int i=0;i<n;i++)
    {
    	if(comp[s[i]]==-1){
    		dfs2(s[i],com++);
    	}
    }

    for(int i=0;i<n;i++)
    {
    	for(auto j:gp2[i])
    	{
    		if(comp[i]==comp[j]) continue;
    		if(gp3[comp[i]].find(comp[j])==gp3[comp[i]].end())
    		{
    			gp3[comp[i]].insert(comp[j]);
    		}
    	}
    }
   
    vector<int> s3;
    for(int i=0;i<com;i++){
    	if(!vis3[i]){
    		dfs3(i,s3);
    	}
    }

    reverse(s3.begin(),s3.end());

    bool flag=true;
    dfs4(s3[0]);
    for(int i=0;i<com;i++)
    {
    	if(!vis4[i])
    	{
    		flag=false;
    	}
    }
    if(flag==false) 
    {
    	cout<<0;
    }
    else
    {
    	vector<int> ans;
    	int vv=s3[0];
    	for(int i=0;i<n;i++){
	    	if(vv==comp[i])
	    	{
	    		ans.PB(i+1);
	    	}
	    }
	    cout<<ans.size()<<endl;
	    for(auto i: ans)
	    	cout<<i<<" ";

    }
return 0;
}