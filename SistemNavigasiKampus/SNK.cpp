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

void findShortestRoute(Graph G, string fromBuilding, string toBuilding) {
    const int MAX_GEDUNG = 100;  // Asumsi maksimum gedung
    int distances[MAX_GEDUNG];
    bool visited[MAX_GEDUNG];
    string namaBangunan[MAX_GEDUNG];
    string path[MAX_GEDUNG];
    int jumlahGedung = 0;

    // Menyimpan semua nama gedung ke array
    adrBuilding P = start(G);
    while (P != NULL) {
        namaBangunan[jumlahGedung] = info(P).buildingName;
        jumlahGedung++;
        P = nextBuilding(P);
    }

    // Inisialisasi array distances dan visited
    for (int i = 0; i < jumlahGedung; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
        path[i] = "";
    }

    // Mencari index gedung awal
    int indexGedungAwal = -1;
    for (int i = 0; i < jumlahGedung; i++) {
        if (namaBangunan[i] == fromBuilding) {
            indexGedungAwal = i;
            break;
        }
    }

    if (indexGedungAwal == -1) {
        cout << "Gedung awal tidak ditemukan!" << endl;
        return;
    }

    // Set jarak awal ke 0 untuk gedung awal
    distances[indexGedungAwal] = 0;
    path[indexGedungAwal] = fromBuilding;

    // Algoritma Dijkstra
    for (int count = 0; count < jumlahGedung - 1; count++) {
        // Cari gedung dengan jarak minimum dari gedung yang belum dikunjungi
        int jarakMinimum = INT_MAX;
        int indexGedungMinimum = -1;

        for (int g = 0; g < jumlahGedung; g++) {
            if (!visited[g] && distances[g] < jarakMinimum) {
                jarakMinimum = distances[g];
                indexGedungMinimum = g;
            }
        }

        if (indexGedungMinimum == -1) break;  // Tidak ada jalur yang tersedia

        // Tandai gedung sebagai sudah dikunjungi
        visited[indexGedungMinimum] = true;

        // Update jarak ke gedung tetangga
        adrBuilding gedungSaatIni = findBuilding_103022300048_103022300011(G, namaBangunan[indexGedungMinimum]);
        adrJalan J = firstJalan(gedungSaatIni);

        while (J != NULL) {
            string namaGedungTujuan = info(destination(J)).buildingName;
            // Cari index gedung tujuan
            int indexGedungTujuan = -1;
            for (int i = 0; i < jumlahGedung; i++) {
                if (namaBangunan[i] == namaGedungTujuan) {
                    indexGedungTujuan = i;
                    break;
                }
            }

            if (indexGedungTujuan != -1 && !visited[indexGedungTujuan]) {
                int jarakBaru = distances[indexGedungMinimum] + info(J).jarak;
                if (jarakBaru < distances[indexGedungTujuan]) {
                    distances[indexGedungTujuan] = jarakBaru;
                    path[indexGedungTujuan] = path[indexGedungMinimum] + " -> " + namaGedungTujuan;
                }
            }
            J = nextJalan(J);
        }
    }

    // Mencari index gedung tujuan
    int indexGedungTujuan = -1;
    for (int i = 0; i < jumlahGedung; i++) {
        if (namaBangunan[i] == toBuilding) {
            indexGedungTujuan = i;
            break;
        }
    }

    if (indexGedungTujuan == -1) {
        cout << "Gedung tujuan tidak ditemukan!" << endl;
        return;
    }

    // Tampilkan hasil
    if (distances[indexGedungTujuan] == INT_MAX) {
        cout << "Tidak ada rute yang tersedia dari " << fromBuilding
             << " ke " << toBuilding << endl;
    } else {
        cout << "Rute terpendek dari " << fromBuilding
             << " ke " << toBuilding << ":" << endl;
        cout << "Path: " << path[indexGedungTujuan] << endl;
        cout << "Total jarak: " << distances[indexGedungTujuan] << endl;
    }
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
