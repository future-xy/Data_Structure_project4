#include "Map.h"
#include <algorithm>
#include <cmath>
#include <assert.h>
#include<fstream>
#include<sstream>
#include <utility>
//#define che
#define debug(...) fprintf(stderr, __VA_ARGS__)
using std::map;
using std::ios;
using std::ifstream;
using std::string;
using std::stringstream;
using std::tuple;
using std::set;
using std::make_pair;
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

Map::Map() {//Build the Map from filename;

	ifstream inFile(filename, ios::in);
	string information;
	getline(inFile, information);
	while (getline(inFile, information)) {
		Node node;
		string temp;
		stringstream ss(information);
		getline(ss, temp, ',');
		const char *cstr = temp.c_str();
		int first, second;
		sscanf(cstr, "%d %d", &first, &second);
		Coordinate point(first, second);
		node.coordinate = point;

		getline(ss, temp, ',');
		node.name = temp;

		getline(ss, temp, ',');
		//int choice;
		if (temp == "Place") {
			//choice = 0;
			node.type = Place;
		}
		else if (temp == "Restaurant") {
			//choice = 1;
			node.type = Restaurant;
		}
		else if (temp == "WC") {
			//choice = 2;
			node.type = WC;
		}
		else if (temp == "Parking_lot") {
			//choice = 3;
			node.type = Parking_lot;
		}
		else if (temp == "Smarket") {
			//choice = 4;
			node.type = Smarket;
		}
		else {
			//choice = 5;
			node.type = Point;
		}

		getline(ss, temp, ',');
		node.info = temp;

		while (getline(ss, temp, ',')) {
			const char *_cstr = temp.c_str();
			int a, b, c;
			sscanf(_cstr, "%d %d %d", &a, &b, &c);
			Coordinate p(a, b);
			tuple <Coordinate, int> pt(p, c);
			node.neighbors.insert(pt);
		}

		adj_Matrix[point] = node;
	}
    #ifdef che
    vector<Coordinate> kk;
    kk.push_back(make_pair(1409,672)); kk.push_back(make_pair(1404,1743));
    vector<Coordinate> res = shortest_Navigation_Car(kk);
    for (auto v:res) printf("(%d, %d)\n",v.first, v.second);
    #endif
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
		if(item.second.type==Place &&  distance(tar, position) < RADIUS+1e-9)
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
//	debug("the minimal cost = %lf m=%d from_no=%d, to_no=%d\n", f[(1<<m)-1][to_no],m,from_no, to_no);
	debug("f[0x1][0] = %lf, f[0x3][1]= %lf, dis=%lf ? %lf ? \n", f[1][0], f[3][1], Short_dis[Located_Key[0] ][ Located_Key[1] ],
                        Short_dis[Located_Key[1] ][ Located_Key[0] ]);
	#endif
    #ifdef che
	debug("Places: ");
	for (int i=0; i<m; ++i){
        int j= Located_Key[i];
        debug("(%d,%d)\t",Located_Common[j].first, Located_Common[j].second);
    }
	debug("\nn=%d\n",n);

/*	for (int i=0; i<n; ++i)
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

	for (int S=(1<<m)-1, i=to_no,j; S > (1<<from_no);){
		for (j=0; j<m; ++j)
			if ( j!=i  && (S&1<<j)){
                double distij= Short_dis[Located_Key[i]][ Located_Key[j]];
                #ifdef che
                debug("distij=[%d][%d]\t", Located_Key[i], Located_Key[j]);
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
	for (auto i : Sequence_no)
        Sequence.push_back(Located_Common[i]);
	std::reverse(Sequence.begin(), Sequence.end());

	return Sequence;
}
std::vector<Coordinate> Map::shortest_Navigation_Car(
	const vector<Coordinate> &KeySite) {
	int n= Label_Common();
	BuildGraph(n, -1);
    int tunnal_start = -1, tunnal_finish = -1,to = Index_Common[KeySite.back()],from=Index_Common[KeySite.front()];
	for (int i=0; i<n; ++i)if (Car_Access[i]){
        if ( tunnal_finish==-1 ||  Short_dis[i][to] < Short_dis[tunnal_finish][to]) tunnal_finish = i;
        if ( tunnal_start==-1 || Short_dis[i][from] < Short_dis[tunnal_start][from] ) tunnal_start=i;
        #ifdef che
        debug("(%d,%d)is accessible, dis=%lf\n",Located_Common[i].first,Located_Common[i].second,Short_dis[i][to]);
//        debug("\ttunnal = (%d, %d) \n", Located_Common[tunnal].first, Located_Common[tunnal].second);
        #endif
    }
    #ifdef che
    debug("tunnal=(%d,%d)\t(%d,%d)\n", Located_Common[tunnal_start].first,Located_Common[tunnal_start].second,
            Located_Common[tunnal_finish].first,Located_Common[tunnal_finish].second);
    #endif
    vector<Coordinate> route_start,route_navigator, route_finish, route,tmp;

    route_start.push_back(KeySite.front());route_start.push_back(Located_Common[tunnal_start] );
    route_navigator.push_back(Located_Common[tunnal_start]);
    route_navigator.insert(route_navigator.begin()+1, KeySite.begin()+1, KeySite.end()-1);
    route_navigator.push_back(Located_Common[tunnal_finish]);
    route_finish.push_back( Located_Common[tunnal_finish]); route_finish.push_back(KeySite.back());
    #ifdef che
    debug("route_navigator : ");for (auto v:route_navigator) debug("(%d,%d)\t",v.first, v.second);
    debug("\n");
    #endif
    if ( KeySite.front()!=Located_Common[tunnal_start]){
        tmp = shortest_particular(route_start,-1);
        route.insert(route.end(),tmp.begin(),tmp.end());
    }
    if ( route_navigator.size() >1){
        tmp = shortest_particular(route_navigator,1);
        if ( route.size()) route.pop_back();
        route.insert(route.end(), tmp.begin(), tmp.end());
    }
    if ( Located_Common[tunnal_finish]!=KeySite.back()){
        tmp = shortest_particular(route_finish,-1);
        if ( route.size()) route.pop_back();
        route.insert(route.end(), tmp.begin(), tmp.end());
    }
    return route;
}

std::vector<Coordinate> Map::shortest_Navigation_Walk(
	const vector<Coordinate> &KeySite) {
        vector<Coordinate> res=shortest_particular(KeySite,-1);
		return res;
	}

void Map::Walk_Along_Shortest(int n,int from, int to, vector<int> &Sequence){
	for (int cur= from, next; cur!= to; cur= next){
		for (next=0; next<n; next++)
			if ( next!=cur && dcmp(Short_dis[cur][to] -Short_dis[next][to]-Edge_dis[cur][next])==0 )
				break;

		Sequence.push_back(next);
	}
}

double Map::distance(Coordinate a, Coordinate b){
	double dx= a.first-b.first, dy= a.second-b.second;
	return sqrt(dx*dx + dy*dy);
}

std::vector<Coordinate> Map::Recommend_1()  //medial axis
{
	vector<Coordinate> path1;

	path1.push_back(make_pair(1430, 697));
	path1.push_back(make_pair(1434, 834));
	path1.push_back(make_pair(1447, 941));
	path1.push_back(make_pair(1486, 941));
	path1.push_back(make_pair(1485, 1050));
	path1.push_back(make_pair(1486, 1255));
	path1.push_back(make_pair(1501, 1465));
	path1.push_back(make_pair(1451, 1465));
	path1.push_back(make_pair(1455, 1512));
	path1.push_back(make_pair(1467, 1579));
	path1.push_back(make_pair(1466, 1735));
	path1.push_back(make_pair(1404, 1743));
	path1.push_back(make_pair(1339, 1735));
	path1.push_back(make_pair(1338, 1689));
	path1.push_back(make_pair(1349, 1512));
	path1.push_back(make_pair(1355, 1466));
	path1.push_back(make_pair(1300, 1465));
	path1.push_back(make_pair(1323, 1257));
	path1.push_back(make_pair(1323, 1049));
	path1.push_back(make_pair(1327, 941));
	path1.push_back(make_pair(1369, 941));
	path1.push_back(make_pair(1372, 834));
	path1.push_back(make_pair(1379, 697));

	path1.push_back(make_pair(1430, 697));

	return path1;

}

std::vector<Coordinate> Map::Recommend_2()// Dormitory area
{

	vector<Coordinate> path1;

	path1.push_back(make_pair(1329, 2438));
	path1.push_back(make_pair(1138, 2529));
	path1.push_back(make_pair(1298, 2698));
	path1.push_back(make_pair(1193, 2811));
	path1.push_back(make_pair(1298, 2698));
	path1.push_back(make_pair(1488, 2711));

	return path1;

}

std::vector<Coordinate> Map::Recommend_3() // pedestrian overpass + underpass
{
	vector<Coordinate> path1;

	path1.push_back(make_pair(829, 2177));
	path1.push_back(make_pair(832, 1749));
	path1.push_back(make_pair(925, 1674));
	path1.push_back(make_pair(834, 1561));
	path1.push_back(make_pair(855, 1506));
	path1.push_back(make_pair(944, 1477));
	path1.push_back(make_pair(1029, 1591));
	path1.push_back(make_pair(1153, 1531));
	path1.push_back(make_pair(1355, 1466));
	path1.push_back(make_pair(1349, 1512));
	path1.push_back(make_pair(1388, 1689));
	path1.push_back(make_pair(1339, 1735));
	path1.push_back(make_pair(1324, 1821));
	path1.push_back(make_pair(1047, 2033));
	path1.push_back(make_pair(829, 2177));


	return path1;

}
//#endif // !MAP_H
