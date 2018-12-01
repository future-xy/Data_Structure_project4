##  Basic Requirements
###  1.Try to use C++11 or newer standards
###  2.Please name your variables meaningfully
###  3.Write some comments   
###  4.Do not use "using namespace std;" anywhere   



    

##  Front-End  

##  Back-End  
###  1.Struct `Node`  

####  --Coordinates:  
>#####  `std::pair<int,int> (x,y);`  

####  --Type of nodes, Point is assistant for Place  

>#####  `enum Type_node{Place, Point, Restaurant, WC, Parking_lot, Smarket}`  

####  --Adjacency list, storing the coordinate as "value"  

>#####  `std::set<std::pair<int,int> >`  

####  --Introduction of Place, others are ""  
>#####  `string Info;`  

###  2.Class：`Map`  
process Nodes  
####  --Store the Nodes in memory:  
>#####  `std::map<Pair, Node>`  

####  --Compute the shortest path, return a vector storing all Nodes in the path:  
>#####  `vector<pair<int, int> > Navigation_shortest(pair<int, int>, pair<int, int>);`  

####  --Store Nodes for long(use .csv file):  
