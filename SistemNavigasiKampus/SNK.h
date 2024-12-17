#ifndef SNK_H_INCLUDED
#define SNK_H_INCLUDED
#include <iostream>

#define start(P) P.start
#define info(P) P->info
#define firstJalan(P) P->firstJalan
#define nextBuilding(P) P->nextBuilding
#define nextJalan(P) P->nextJalan
#define destination(P) P->destination

using namespace std;

// node = vertex = building
// edge = bridge = jalan

struct infotypeJalan {
    int weight; // jalan = weight
};

struct infotypeBuilding {
    string buildingName;
};

typedef struct elmtBuilding *adrBuilding;
typedef struct elmtJalan *adrJalan;

struct elmtBuilding {
    infotypeBuilding info;
    adrJalan firstJalan;
    adrBuilding nextBuilding;
};

struct elmtJalan {
    infotypeJalan info;
    adrJalan nextJalan;
    adrBuilding destination; // destination building
};

struct Graph {
    adrBuilding start;
};

void createGraph_103022300048_103022300011(Graph &G); //Membuat graph
/*{I.S. Belum terdefinisi sebuah graph
 F.S. Telah dibuat sebuah graph baru dengan start(G) = NULL}*/

adrBuilding allocateBuilding_103022300048_103022300011(infotypeBuilding infoBuilding); //alokasi elemen gedung
/*{Mengembalikan pointer ke elemen building yang baru dengan infoBuilding terisi, firstJalan = NULL, dan nextBuilding = NULL}*/

adrJalan allocateJalan_103022300048_103022300011(infotypeJalan info, adrBuilding destination); //alokasi elemen rute
/*{Mengembalikan pointer ke elemen jalan yang baru dengan info terisi, destination terisi, dan nextJalan = NULL}*/

void addBuilding_103022300048_103022300011(Graph &G, infotypeBuilding infoBuilding); //Menambah gedung
/*{I.S. Graph mungkin kosong atau sudah memiliki building
 F.S. Building baru ditambahkan sebagai elemen terakhir pada graph}*/

void addJalan_103022300048_103022300011(Graph &G, string fromBuilding, string toBuilding, int jarak); //Menambah Rute
/*{I.S. Dua building dengan nama fromBuilding dan toBuilding ada dalam graph
 F.S. Jalan baru ditambahkan dari fromBuilding ke toBuilding dengan jarak tertentu}*/

adrBuilding findBuilding_103022300048_103022300011(Graph G, string buildingName); //Searching gedung
/*{Mengembalikan pointer ke elemen building dengan nama buildingName jika ditemukan, nullptr jika tidak}*/

//adrJalan findJalan_103022300048_103022300011(Graph G, infotypeJalan J); //Searching rute
/*{Mengembalikan nilai pointer ke elemen rute dengan informasi R jika ditemukan
 atau NULL jika tidak ada rute dengan informasi tersebut di graph G}*/

void deleteLastJalan_103022300048_103022300011(Graph &G, adrBuilding B, adrJalan &J);
/*{I.S. Building memiliki daftar jalan
 F.S. Jalan terakhir pada daftar dihapus, pointer J mengarah ke jalan yang dihapus}*/

void deleteAfterJalan_103022300048_103022300011(Graph &G, adrBuilding B, adrJalan Prec, adrJalan &J);
/*{I.S. Prec adalah pointer ke jalan sebelum jalan yang akan dihapus
 F.S. Jalan setelah Prec dihapus, pointer J mengarah ke jalan yang dihapus}*/

adrJalan shortestJalan_103022300048_103022300011(Graph &G, string buildingName); //Mencari jalan terpendek
/*{Mengembalikan pointer ke elemen jalan dengan jarak terpendek dari gedung awal}*/


#endif // SNK_H_INCLUDED
