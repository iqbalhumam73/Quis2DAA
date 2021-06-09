#include <iostream>
using namespace std;
#define m 5


void routefinder(int startingpoint, int map[m][m]) {
    int dist[m];
    bool included[m];
    for (int i=0;i<m;i++) dist[i]=INT_MAX, included[i]=0;
    dist[startingpoint]=0;
    for (int i=0;i<m-1;i++) {
    	int minimumIndex = mindist(dist, included);
    	included[i]=1;
    	for (int j=0;j<m;j++) {
    		if (!included[j] && map[minimumIndex][j] && dist[minimumIndex] != INT_MAX && dist[minimumIndex] + map[minimumIndex][j] < dist[j])
    			dist[j]=dist[minimumIndex]+map[minimumIndex][j];
    	}
    }
    printroute(dist);
}
     
int main(){
	int startingpoint;
    int map[m][m] = { { 0, 4, 9, 5, 3 },
    				   { 4, 0, 9, 2, 3 },
    				   { 5, 9, 0, 9, 3 },
    				   { 6, 2, 9, 0, 1 },
    				   { 7, 3, 3, 1, 0 }};
    cout << "Insert Starting Point : ";
    cin >> startingpoint;
    routefinder(startingpoint, map);
}
