#include "SNK.h"

void createGraph_103022300048_103022300011(Graph &G){ //Membuat graph
/*{I.S. Belum terdefinisi sebuah graph
 F.S. Telah dibuat sebuah graph baru dengan start(G) = nil}*/
 start(G) == NULL;
}
void createBuilding_103022300048_103022300011(char newBuilding ,adrBuilding &B) { //Membuat rute
    B = new building;
}
adrBuilding allocateBuilding_103022300048_103022300011(infotypeBuilding infoBuilding); //alokasi elemen gedung
/*{Mengembalikan nilai pointer ke sebuah elemen gedung yang baru dialokasikan
 dengan infoBuilding(v) = infoBuilding, firstEdge(v) = nil, dan nextNode(v) = nil}*/
    adrBuilding P;
    P = new elmtBuilding;
    info(P) = infoBuilding;
    firstJalan(P) = NULL;
    nextBuilding = NULL;
    return P;

adrRoute allocateJalan_103022300048_103022300011(infotypeJalan infoJalan); //alokasi elemen rute
/*{Mengembalikan nilai pointer ke sebuah elemen rute yang baru dialokasikan
 dengan infoRoute(R) = infoRoute dan nextEdge(R) = nil}*/
    adrJalan P;
    P = new elmtJalan;
    info(P) = infoJalan;
    nextBuilding = NULL;
    return P;

void addBuilding_103022300048_103022300011(Graph &G, adrBuilding P) {
/*{I.S. Mungkin ada atau tidak ada gedung di graph G
 F.S. Sebuah gedung baru dengan nama B ditambahkan ke graph G,
      menjadi elemen terakhir dalam daftar building (nextNode) atau menjadi start(G) jika kosong}*/
    adrBuilding Q;
    if (start(G) == NULL) {
        start(G) = P;
    }else {
            Q = start(G);
            while (nextBuilding(Q) != NULL) {
                Q = nextBuilding(Q)
            }
            nextBuilding(Q)
    }
}

void addJalan_103022300048_103022300011(Graph &G, string J); //Menambah Rute
/*{I.S. Mungkin ada atau tidak ada rute di graph G
 F.S. Sebuah rute baru dengan informasi R ditambahkan di antara gedung yang relevan di graph G}*/
void connecting_103022300048_103022300011(Graph &G, string b1, string b2); //Mengconnect antar building
/*{I.S. Dua gedung (b1 dan b2) sudah ada di graph tetapi tidak saling terhubung
 F.S. Dibuat hubungan (edge/rute) di antara gedung b1 dan b2}*/
adrBuilding findBuilding_103022300048_103022300011(Graph G, infotypeBuilding B); //Searching gedung
/*{Mengembalikan nilai pointer ke elemen gedung dengan nama B jika ditemukan
 atau NULL jika tidak ada gedung dengan nama tersebut di graph G}*/
    adrBuilding P;
    adrBuilding Q;
    if (start(G) == NULL) {
        return NULL
    }else {
        P = start(G);
        while(infoBuilding(P) != B) && (nextBuilding(P) != NULL) {
            Q = nextBuilding(Q);
        }
        if (infoBuilding(P) == B) {
            return P;
        }else {
            return NULL;
        }
    }
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
