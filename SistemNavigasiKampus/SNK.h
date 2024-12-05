#ifndef SNK_H_INCLUDED
#define SNK_H_INCLUDED
#include <iostream>
using namespace std;

//node = vertex = building
//edge = bridge = jalan

struct infotypeJalan {
    int jalan;
    //jalan = weight
};

struct infotypeBuilding {
    string buildingName;
};

typedef struct elmtBuilding *adrBuilding;
typedef struct elmtJalan *adrJalan;

struct elmtBuilding {
    infotypeBuilding info;
    adrJalan firstJalan;
    adrBuilding nextNode;
};

struct elmtJalan {
    infotypeJalan info;
    adrJalan nextEdge;
};

struct Graph {
    adrBuilding start;
};

void createGraph_103022300048_103022300011(Graph &G); //Membuat graph
/*{I.S. Belum terdefinisi sebuah graph
 F.S. Telah dibuat sebuah graph baru dengan start(G) = nil}*/
void createRoute_103022300048_103022300011(adrJalan J); //Membuat rute
/*{I.S. Belum terdefinisi sebuah rute (edge)
 F.S. Telah dialokasi sebuah rute baru dengan infoRoute(R) sesuai parameter,
      nextEdge(R) = nil}*/
adrBuilding allocateBuilding_103022300048_103022300011(infotypeBuilding infoBuilding); //alokasi elemen gedung
/*{Mengembalikan nilai pointer ke sebuah elemen gedung yang baru dialokasikan
 dengan infoBuilding(v) = infoBuilding, firstEdge(v) = nil, dan nextNode(v) = nil}*/
adrRoute allocateJalan_103022300048_103022300011(infotypeJalan info); //alokasi elemen rute
/*{Mengembalikan nilai pointer ke sebuah elemen rute yang baru dialokasikan
 dengan infoRoute(R) = infoRoute dan nextEdge(R) = nil}*/
void addBuilding_103022300048_103022300011(Graph &G, string B); //Menambah gedung
/*{I.S. Mungkin ada atau tidak ada gedung di graph G
 F.S. Sebuah gedung baru dengan nama B ditambahkan ke graph G,
      menjadi elemen terakhir dalam daftar building (nextNode) atau menjadi start(G) jika kosong}*/
void addJalan_103022300048_103022300011(Graph &G, string J); //Menambah Rute
/*{I.S. Mungkin ada atau tidak ada rute di graph G
 F.S. Sebuah rute baru dengan informasi R ditambahkan di antara gedung yang relevan di graph G}*/
void connecting_103022300048_103022300011(Graph &G, string b1, string b2); //Mengconnect antar building
/*{I.S. Dua gedung (b1 dan b2) sudah ada di graph tetapi tidak saling terhubung
 F.S. Dibuat hubungan (edge/rute) di antara gedung b1 dan b2}*/
adrBuilding findBuilding_103022300048_103022300011(Graph G, infotypeBuilding B); //Searching gedung
/*{Mengembalikan nilai pointer ke elemen gedung dengan nama B jika ditemukan
 atau NULL jika tidak ada gedung dengan nama tersebut di graph G}*/
adrJalan findJalan_103022300048_103022300011(Graph G, infotypeJalan J); //Searching rute
/*{Mengembalikan nilai pointer ke elemen rute dengan informasi R jika ditemukan
 atau NULL jika tidak ada rute dengan informasi tersebut di graph G}*/
void deleteLastJalan_103022300048_103022300011(Graph &G, adrBuilding B, adrRoute &J);
/*{I.S. Sebuah gedung B memiliki daftar rute, dan setidaknya ada satu rute di daftar
 F.S. Rute terakhir di daftar rute gedung B dihapus, dan pointer R mengarah ke rute yang dihapus}*/
void deleteAfterJalan_103022300048_103022300011(Graph &G, adrBuilding B, adrRoute Prec, adrRoute &J);
/*{I.S. Sebuah gedung B memiliki daftar rute, dan terdapat rute setelah rute tertentu Prec
 F.S. Rute setelah Prec dihapus, dan pointer R mengarah ke rute yang dihapus}*/
void shortestJalan_103022300048_103022300011(Graph &G, string awal, string terakhir); //Mencari rute terpendek
/*{I.S. Graph G telah didefinisikan, serta terdapat dua gedung (start dan end) yang valid
 F.S. Menemukan dan menampilkan rute terpendek antara gedung start dan end berdasarkan weight rute}*/


#endif // SNK_H_INCLUDED
