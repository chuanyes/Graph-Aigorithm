typedef struct Arcnode{
	int data;
	struct Arcnode* next;
}Arcnode;
typedef struct {
	int data;
	Arcnode* first;
}Vnode,Nodelist[MAXSIZE];
typedef struct AlGraph{
	Nodelist G;
	int vexnum,arcnum;
}AlGraph;
=======================
typedef struct{
	int adjvex[MAXSIZE];
	int arcvex[MAXSIZE][MAXSIZE];
	int vexnum,arcnum;
}MGraph;
=======================
void BFS_Taverl(Graph G){
	InitQueue(Q);
	EnQueue(Q,0);
	bool visited[MAXSIZE];//默认全FALSE
	for(int i=0;i<G.vexnum;i++){
		if(!visited[i])
			BFS(G,i);
	}
}
void BFS(Graph G,int V){
	while(!IsEmpty(Q)){
		DeQueue(Q,v);
		for(w=firstneighbor(G,v);w>0;w=nextneighbor(G,w,v)){
			if(!visited[w]){
				visite[i];
				EnQueue(Q,v);
				visited[i]=TURE;
			}
		}
	}
}
============================================================
void DFS_Taveral(Graph G){
	bool visited[MAXSIZE];//默认全FALSE
	for(int i=0;i<G.vexnum;i++){
		if(!visited[i])
			DFS(G,i);
	}
}
void DFS(Graph G,int v){
	visite[v];
	for(w=firstneighbor(G,v);w>0;w=nextneighbor(G,w,v)){
		if(!visited[w])
			DFS(G,w);
	}
}
============================================================
int MiniSpanTree_PRIM (Graph G){
	int k;
	int sum=0;
	int cost[MAXSIZE];
	for(int i=0;i<G.vexnum;i++){
		cost[i]=G.arcvex[0][i];
	}
	cost[0]=1;
	for(int j=0;j<G.vexnum&&cost[j]==0;j++){
		k=search(cost);
		sum+=cost[k];
		cost[k]=1;
		for(int m=0;m<G.vexnum&&cost[m]==0;j++){
			if(cost[m]>G.arcvex[k][m])
				cost[m]=G.arcvex[k][m];
	}
	return sum;
}
=============================================================
typedef struct {
	int a;
	int b;
	int weight;
}Edge;
int Find(*parent, int x){
	while(parent[x]>0) x=parent[x];
	return x;
}
int MiniSpanTree_KRUSCUAL(Graph G){
	Edge edges[MAXSIZE];
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			if(G.arcvex[i][j]<65535){
				edges[i].weight=G.arcvex[i][j];
				edges[i].a=i;
				edges[i].b=j;
			}
		}		
	}
	int parent[MAXSIZE];
	sort(edges);
	for(int i=0 ;i<G.vexnum;i++ ) 
		parent[i]=-1;
	for(int j=0;j<G.arcnum;j++){
		m=Find(parent,edges.b);
		n=Find(parent,edges.a);
		if(m!=n){
			parent(n)=m;
			sum+=edges.weight;
		}
	}
	
return sum;

}
========================================================
void Dijkstra(int dist[],int path[],Graph G,int v){
	for(int i=0;i<G.vexnum;i++){
		for(int j=0;j<G.vexnum;j++){
			if(G.arcvex[i][j]<65535)
				path[j]=i;
			else
				path[j]=-1;
			
		}
	}
	for(int i=0;i<vexnum;i++){
		dist[i]=G.arcvex[i];
	}			
	int s[MAXSIZE];//默认全为0
	s[v]=1;
	for（int i=0;i<vexnum&&s[i]==0;i++）{
		k=search(dist)
		s[k]=1;
		for(int j=0;j<vexnum&&s[j]==0;j++)
			if(dist[j]>dist[k]+G.arcvex[k][j]){
				dist[j]=dist[k]+G.arcvex[k][j];
				path[j]=k;
			}
	}

}
===========================================================
void Folyd(Graph G){
	int M[MAXSIZE][MAXSIZE];
	for(int i=0;i<vexnum;i++){
		for(int j=0;j<vexnum;j++){
			M[i][j]=G.arcvex[i][j];
			path[i][j]=-1;
		}
	}
	for(int i=0;i<vexnum;i++){
		for(int j=0;j<vexnum;j++){
			for(int k=0;k<vexnum;k++){
				if(M[j][k]>M[j][i]+M[i][k]){
					M[j][k]=M[j][i]+M[i][k];
					path[j][k]=i;

			}
				}
		}
	}
}
