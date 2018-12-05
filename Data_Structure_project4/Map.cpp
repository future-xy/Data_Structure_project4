#include "Map.h"
#include <algorithm>
#include <cmath>
#include <assert.h>
//#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
using std::string;
using std::map;
using std::set;
using std::pair;
using std::vector;

const string filename = "Map.csv";
namespace _Fc_Temp_Array_{
    Coordinate Located_Common[N];
    map<Coordinate,int> Index_Common;
    int Index_Key[N], Located_Key[N];
    bool Car_Access[N];
    double Edge_dis[N][N], Short_dis[N][N];
    double f[(1<<22)+3][20];

    int dcmp(double a){
        if ( fabs(a) < 1e-9) return 0;
        return a < 0 ? -1 : 1;
    }
} using namespace _Fc_Temp_Array_;

Map::Map(){//Build the Map from filename;
}
std::vector<Node> Map::getPlace()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Place) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getWC()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == WC) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getParking_lot()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Parking_lot) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getSmarket()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Smarket) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getRestaurant()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Restaurant) tot.push_back(item.second);
	return tot;
}
std::string Map::Info(Coordinate pos) {
	if ( adj_Matrix.count(pos)) return adj_Matrix[pos].info;
		else return "";

}

Coordinate Map::MatchSite(Coordinate position){
	Coordinate result=std::make_pair(-1,-1);
	for ( auto item : adj_Matrix){
		Coordinate tar=item.first;
		if( distance(tar, position) < RADIUS+1e-9)
			result = tar;
	}
	return result;
}

void Map::BuildGraph(int n,int op){
    for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			Edge_dis[i][j] = Short_dis[i][j]=i==j ? 0 : INF;
    for (int i=0; i<n; ++i) Car_Access[i] = false;
	for (auto ItemA: adj_Matrix){
		int i= Index_Common[ItemA.first];
		for (auto NextTuple:ItemA.second.neighbors){
			if ( std::get<1>(NextTuple )==op || op==-1){
				int j= Index_Common[std::get<0>(NextTuple)];
				Short_dis[i][j] = Edge_dis[i][j]=distance(ItemA.first, std::get<0>(NextTuple));
			}
			if( std::get<1>(NextTuple) == 1 ) Car_Access[i]= true;
        }
	}
    for (int k=0; k<n; ++k) // Floyd
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                Short_dis[i][j] = std::min(Short_dis[i][j], Short_dis[i][k] + Short_dis[k][j]);
}
int Map::Label_Common(){
    int n=0;Index_Common.clear();
	for (auto item : adj_Matrix){
		Located_Common[n] = item.first;
		Index_Common[item.first] = n++;
	}
	return n;
}
int Map::Label_Key(const vector<Coordinate> &KeySite){
    int m=0;
    for ( auto item : KeySite){
        Index_Key[Index_Common[item]] =m;
        Located_Key[m]= Index_Common[item];
        m++;
	}
	return m;
}
std::vector<Coordinate> Map::shortest_particular(
    const vector<Coordinate> &KeySite ,int op) {
	int n=Label_Common();int m=Label_Key(KeySite);
	BuildGraph(n, op);
    #ifdef che
/*	debug("Places: ");
	for (int i=0; i<m; ++i){
        int j= Located_Key[i];
        debug("(%d,%d)\t",Located_Common[j].first, Located_Common[j].second);
    }
	debug("\nn=%d\n",n);

	for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)//if ( Edge_dis[i][j] < INF)
        {
            debug("(%d, %d)---->(%d, %d) , dis= %lf\n", Located_Common[i].first,Located_Common[i].second,
                                                        Located_Common[j].first,Located_Common[j].second,
                                                        Short_dis[i][j]);
        }
*/
	#endif
	// DP
	for (int S=0; S<(1<<m); ++S)
		for (int i=0; i<m; ++i) f[S][i]=INF;
	int from_no= Index_Key[Index_Common[KeySite.front()]], to_no = Index_Key[Index_Common[KeySite.back()]];
	f[1<<from_no][from_no] = 0;

	for (int S=1; S<(1<<m); ++S)
		for (int i=0; i<m; ++i)	if( S&1<<i)
			for (int j=0; j<m; ++j)	if ( !(S&1<<j))
				f[S|1<<j][j] = std::min(f[S|1<<j][j] , f[S][i] + Short_dis[Located_Key[i] ][ Located_Key[j] ]);
	std::vector<int> Sequence_no; Sequence_no.push_back(Located_Key[to_no]);
	#ifdef che
	debug("the minimal cost = %lf\n", f[(1<<m)-1][to_no]);
	#endif
	for (int S=(1<<m)-1, i=to_no,j; S > (1<<from_no);){
		for (j=0; j<m; ++j)
			if ( j!=i  && (S&1<<j)){
                double distij= Short_dis[Located_Key[i]][ Located_Key[j]];
                #ifdef che
                debug("j=%d, %lf+%lf==%lf = %d \n",j,f[S^1<<i][j],distij,f[S][i],dcmp(f[S^1<<i][j] + distij-f[S][i] ));
                #endif
                if (dcmp(f[S^1<<i][j] + distij -f[S][i] )==0 ) break;
            }



		Walk_Along_Shortest(n,Located_Key[i],Located_Key[j],Sequence_no);
		#ifdef che
		debug("when S=0x%X, i=%d,j=%d\n",S,i,j);
		assert(j<m);
		#endif
		S^= 1<<i;i=j;
	}
	vector<Coordinate> Sequence;
	for (auto i : Sequence_no) Sequence.push_back(Located_Common[i]);
	std::reverse(Sequence.begin(), Sequence.end());
	return Sequence;
}
std::vector<Coordinate> Map::shortest_Navigation_Car(
	const vector<Coordinate> &KeySite) {
	int n= Label_Common();int m= Label_Key(KeySite);BuildGraph(n, -1);
    int tunnal = -1, to = Index_Common[KeySite.back()];
	BuildGraph(n,-1);
	for (int i=0; i<n; ++i)if (Car_Access[i]){
        if ( tunnal==-1 ||  Short_dis[i][to] < Short_dis[tunnal][to]) tunnal = i;
        #ifdef che
        debug("(%d,%d)is accessible, dis=%lf\n",Located_Common[i].first,Located_Common[i].second,Short_dis[i][to]);
//        debug("\ttunnal = (%d, %d) \n", Located_Common[tunnal].first, Located_Common[tunnal].second);
        #endif
    }
    #ifdef che
    debug("tunnal=(%d,%d)\n", Located_Common[tunnal],Located_Common[tunnal]);
    #endif
    vector<Coordinate> route1=KeySite,route2;
    route1.pop_back(); route1.push_back(Located_Common[tunnal] );
    route2.push_back( Located_Common[tunnal]); route2.push_back(KeySite.back());
    vector<Coordinate> path1=shortest_particular(route1,1),path2;
    if ( route2.front() != route2.back()){
        path2=shortest_particular(route2,-1);
        path1.pop_back();path1.insert(path1.end(),path2.begin(),path2.end());
    }
    return path1;
}

std::vector<Coordinate> Map::shortest_Navigation_Walk(
	const vector<Coordinate> &KeySite) {
		return shortest_particular(KeySite,-1);
	}

void Map::Walk_Along_Shortest(int n,int from, int to, vector<int> &Sequence){
	for (int cur= from, next; cur!= to; cur= next){
		for (next=0; next<n; next++)
			if ( next!=cur && dcmp(Short_dis[cur][to] -Short_dis[next][to]-Edge_dis[cur][next])==0 )
				break;
        #ifdef che
 //       debug("cur=%d, next= %d, to=%d\n", cur, next, to);
        #endif
		Sequence.push_back(next);
	}
}

double Map::distance(Coordinate a, Coordinate b){
	double dx= a.first-b.first, dy= a.second-b.second;
	return sqrt(dx*dx + dy*dy);
}
//#endif // !MAP_H
