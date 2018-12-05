#include <bits/stdc++.h>
//using namespace std;
//#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MK make_pair
#define PB push_back
#include <tuple>
#define fi first
#define se second
#include "Map.h"

using std::vector;

typedef long long LL;
typedef std::pair<int, int> PII;

PII pos[N];
Map amap;
int main(){
//	#ifdef che
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
//	#endif
	int n,m;scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i){
		scanf("%d%d", &pos[i].fi, &pos[i].se);
		int type;scanf("%d", &type);
		Node newnode;
		newnode.coordinate=pos[i];
		newnode.type= type==1 ? Place : Point;
		amap.adj_Matrix[pos[i]] = newnode;
	}
	for (int i=0,u,v, ty; i<m; ++i){
		scanf("%d%d%d", &u, &v, &ty);
		amap.adj_Matrix[ pos[u]].neighbors.insert(make_tuple(pos[v],ty));
		amap.adj_Matrix[ pos[v]].neighbors.insert(make_tuple(pos[u],ty));
	}
	vector<PII> key;
	key.push_back(pos[13]);key.push_back( pos[2]);
    std::vector<PII> path = amap.shortest_Navigation_Walk(key);
    for ( auto p : path) printf("(%d, %d)\n", p.first, p.second);
    printf("\n");
    key.push_back(pos[9]);
    path=amap.shortest_Navigation_Car(key);
    for ( auto p : path) printf("(%d, %d)\n", p.first, p.second);
	return 0;
}
