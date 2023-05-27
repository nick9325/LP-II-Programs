#include<bits/stdc++.h>

using namespace std;


void prims(vector<vector<int>> adj[],int n){
	
	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> q;

	vector<int> vis(n,0);
	vector<vector<int>> ans;
	q.push({{0,0},-1});
	int sum=0;
	while(!q.empty()){

		auto it=q.top();
		q.pop();

		int node=it.first.second;
		int wt=it.first.first;
		int par=it.second;
		
		if(vis[node]==1) continue;
		vis[node]=1;
		sum+=wt;
		if(par!=-1) ans.push_back({par,node});

		for(auto x:adj[node]){
			
			int adjNode=x[0];
			int adjWt=x[1];

			if(!vis[adjNode]){
				q.push({{adjWt,adjNode},node});
			}			

		}

	}


	cout<<"MST as follows:"<<endl;

	for(auto x:ans){
	      cout<<x[0]<<" "<<x[1]<<endl;
	}	
	cout<<endl;
	cout<<"The minimum weight of MST is: "<<sum<<endl;

}


int main(){

	int n,m;
	cin>>n>>m;

	vector<vector<int>> adj[n+1];
	
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}



	prims(adj,n);

	
	
	

return 0;
}