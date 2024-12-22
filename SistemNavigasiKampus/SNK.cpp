#include "SNK.h"

void createGraph_103022300048_103022300011(Graph &G){ //Membuat graph
/*{I.S. Belum terdefinisi sebuah graph
 F.S. Telah dibuat sebuah graph baru dengan start(G) = NULL}*/
    start(G) = NULL;
 }

adrBuilding allocateBuilding_103022300048_103022300011(infotypeBuilding infoBuilding){ //alokasi elemen gedung
/*{Mengembalikan pointer ke elemen building yang baru dengan infoBuilding terisi, firstJalan = NULL, dan nextBuilding = NULL}*/
    adrBuilding P = new elmtBuilding;
    info(P) = infoBuilding;
    firstJalan(P) = NULL;
    nextBuilding(P) = NULL;
    return P;
}

adrJalan allocateJalan_103022300048_103022300011(infotypeJalan info, adrBuilding destination){ //alokasi elemen rute
/*{Mengembalikan pointer ke elemen jalan yang baru dengan info terisi, destination terisi, dan nextJalan = NULL}*/
    adrJalan P = new elmtJalan;
    info(P) = info;
    nextJalan(P) = NULL;
    destination(P) = destination;
    return P;
}

void addBuilding_103022300048_103022300011(Graph &G, infotypeBuilding infoBuilding){ //Menambah gedung
/*{I.S. Graph mungkin kosong atau sudah memiliki building
 F.S. Building baru ditambahkan sebagai elemen terakhir pada graph}*/
    adrBuilding P = allocateBuilding_103022300048_103022300011(infoBuilding);
    if (start(G) == NULL) {
        start(G) = P;
    } else {
        adrBuilding Q = start(G);
        while (nextBuilding(Q) != NULL) {
            Q = nextBuilding(Q);
        }
        nextBuilding(Q) = P;
    }
 }

void addJalan_103022300048_103022300011(Graph &G, string fromBuilding, string toBuilding, int jarak){ //Menambah Rute
/*{I.S. Dua building dengan nama fromBuilding dan toBuilding ada dalam graph
 F.S. Jalan baru ditambahkan dari fromBuilding ke toBuilding dengan jarak tertentu}*/
    adrBuilding B1 = findBuilding_103022300048_103022300011(G, fromBuilding);
    adrBuilding B2 = findBuilding_103022300048_103022300011(G, toBuilding);
    if (B1 != NULL && B2 != NULL) {
        infotypeJalan info;
        info.jarak = jarak;
        adrJalan newJalan = allocateJalan_103022300048_103022300011(info, B2);
        adrJalan J = firstJalan(B1);
        if (J == NULL) {
            firstJalan(B1) = newJalan;
        } else {
            while (nextJalan(J) != NULL) {
                J = nextJalan(J);
            }
            nextJalan(J) = newJalan;
        }
    }
 }

adrBuilding findBuilding_103022300048_103022300011(Graph G, string buildingName){ //Searching gedung
/*{Mengembalikan pointer ke elemen building dengan nama buildingName jika ditemukan, NULL jika tidak}*/
    adrBuilding P = start(G);
    while (P != NULL) {
        if (info(P).buildingName == buildingName) {
            return P;
        }
        P = nextBuilding(P);
    }
    return NULL;
}


void deleteLastJalan_103022300048_103022300011(Graph &G, adrBuilding B, adrJalan &J){
/*{I.S. Building memiliki daftar jalan
 F.S. Jalan terakhir pada daftar dihapus, pointer J mengarah ke jalan yang dihapus}*/
    if (firstJalan(B) != NULL) {
        adrJalan P = firstJalan(B);
        adrJalan Q = NULL;
        while (nextJalan(P) != NULL) {
            Q = P;
            P = nextJalan(P);
        }
        if (Q == NULL) {
            firstJalan(B) = NULL;
        } else {
            nextJalan(Q) = NULL;
        }
        J = P;
    }
 }

void deleteAfterJalan_103022300048_103022300011(Graph &G, adrBuilding B, adrJalan Prec, adrJalan &J){
/*{I.S. Prec adalah pointer ke jalan sebelum jalan yang akan dihapus
 F.S. Jalan setelah Prec dihapus, pointer J mengarah ke jalan yang dihapus}*/
    if (Prec != NULL && nextJalan(Prec) != NULL) {
        J = nextJalan(Prec);
        nextJalan(Prec) = nextJalan(J);
        nextJalan(J) = NULL;
    }
 }

adrJalan shortestJalan_103022300048_103022300011(Graph &G, string buildingName){ //Mencari jalan terpendek
/*{Mengembalikan pointer ke elemen jalan dengan jarak terpendek dari gedung awal}*/
    adrBuilding startBuilding = findBuilding_103022300048_103022300011(G, buildingName);
    if (startBuilding == NULL || firstJalan(startBuilding) == NULL) {
        return NULL;
    }

    adrJalan shortestJalan = NULL;
    adrJalan J = firstJalan(startBuilding);
    int shortestDistance = info(J).jarak;

    while (J != NULL) {

        if (info(J).jarak < shortestDistance) {
            shortestDistance = info(J).jarak;
            shortestJalan = J;
        }
        J = nextJalan(J);
    }

    return shortestJalan;
 }

adrJalan emergencyRoute_103022300048_103022300011(Graph G, adrBuilding blockedBuilding) {
    if (blockedBuilding == NULL) {
        return NULL;
    }
    adrBuilding curr = start(G);
    while (curr != NULL) {
        adrJalan edge = firstJalan(current);
        while (edge != NULL) {
            if (destination(edge) == blockedBuilding) {
                info(edge).jarak = INT_MAX;
            }
            edge = nextJalan(edge);
        }
        current = nextBuilding(current);
    }
    return NULL;
}

#endif // SNK_H_INCLUDED
