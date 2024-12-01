#ifndef SNK_H_INCLUDED
#define SNK_H_INCLUDED
#include <iostream>
using namespace std;

//node = vertex = building
//edge = bridge = rute

struct infotypeRoute {
    int route;
    //rute = weight
};

struct infotypeBuilding {
    string buildingName;
};

typedef struct elmtBuilding *adrBuilding;
typedef struct elmtRoute *adrRoute;

struct elmtBuilding {
    infotypeBuilding info;
    adrRoute firstEdge;
    adrBuilding nextNode;
};

struct elmtRoute {
    infotypeRoute info;
    adrRoute nextEdge;
};

struct Graph {
    adrBuilding start;
};

void createGraph_103022300048_103022300011(Graph &G); //Membuat graph
void createRoute_103022300048_103022300011(adrRoute R); //Membuat rute
adrBuilding allocateBuilding_103022300048_103022300011(infotypeBuilding infoBuilding); //alokasi elemen gedung
adrRoute allocateRoute_103022300048_103022300011(infotypeRoute infoRoute); //alokasi elemen rute
void addBuilding_103022300048_103022300011(Graph &G, string B); //Menambah gedung
void addRoute_103022300048_103022300011(Graph &G, string R); //Menambah Rute
void connecting_103022300048_103022300011(Graph &G, string b1, string b2); //Mengconnect antar building
adrBuilding findBuilding_103022300048_103022300011(Graph G, infotypeBuilding B); //Searching gedung
adrRoute findRoute_103022300048_103022300011(Graph G, infotypeRoute R); //Searching rute
void deleteLastRoute_103022300048_103022300011(Graph &G, adrBuilding B, adrRoute &R);
void deleteAfterRoute_103022300048_103022300011(Graph &G, adrBuilding B, adrRoute Prec, adrRoute &R);
void shortestRoute_103022300048_103022300011(Graph &G, string start, string end); //Mencari rute terpendek


#endif // SNK_H_INCLUDED
