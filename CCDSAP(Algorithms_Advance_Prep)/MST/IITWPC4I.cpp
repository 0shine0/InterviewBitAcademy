/**
 *   author: sahushivam
 *   created: 10 November 2019 (Sunday)  17:07:16
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

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {
    	int n,m; cin>>n>>m;
    	vector<int> a(n); 
    	for(int i=0;i<n;i++) cin>>a[i];
    	vector<int> milkman;
    	vector<vector<pair<int,int>>>graph(n);
    	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
		vector<int> visited(n,0);
		int count=0,ans=0;
    	int s;
    	for(int i=0;i<n;i++)
    	{
    		if(a[i])
    		{
    			pq.push({0,i});
    		}
    	}
    	for(int i=0;i<m;i++)
    	{
    		int a,b,c; cin>>a>>b>>c;
    		a--; b--;
    		graph[a].push_back({b,c});
    		graph[b].push_back({a,c});
    	}
	while(!pq.empty())
	{
		pair<int,int> x=pq.top();
		pq.pop();
		if(visited[x.second]) continue;
		ans+=x.first;
		
		count++;
		visited[x.second]=1;
		for(auto i: graph[x.second])
		{
			if(!visited[i.first]){
				pq.push({i.second,i.first});
			}
		}
		if(count==n) break;
	}
    	if(count!=n)
    	{
    		cout<<"impossible\n";
    	}
    	else
    		cout<<ans<<endl;
    }
return 0;
}