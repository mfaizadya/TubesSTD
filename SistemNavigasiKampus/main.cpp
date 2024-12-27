#include "SNK.h"


int main()
{
    Graph G;
    createGraph_103022300048_103022300011(G);
    int pilihan;
    string namaGedung, gedungAwal, gedungTujuan;
    int jarak;

    infotypeBuilding b1;
    b1.buildingName = "TULT";
    addBuilding_103022300048_103022300011(G,b1);
    infotypeBuilding b2;
    b2.buildingName = "Asrama";
    addBuilding_103022300048_103022300011(G,b2);
    infotypeBuilding b3;
    b3.buildingName = "BTP";
    addBuilding_103022300048_103022300011(G,b3);
    infotypeBuilding b4;
    b4.buildingName = "GKU";
    addBuilding_103022300048_103022300011(G,b4);
    infotypeBuilding b5;
    b5.buildingName = "TUCH";
    addBuilding_103022300048_103022300011(G,b5);
    infotypeBuilding b6;
    b6.buildingName = "Cacuk";
    addBuilding_103022300048_103022300011(G,b6);
    infotypeBuilding b7;
    b7.buildingName = "MSU";
    addBuilding_103022300048_103022300011(G,b7);
    infotypeBuilding b8;
    b8.buildingName = "FIK";
    addBuilding_103022300048_103022300011(G,b8);
    infotypeBuilding b9;
    b9.buildingName = "FEB";
    addBuilding_103022300048_103022300011(G,b9);
    infotypeBuilding b10;
    b10.buildingName = "FIT";
    addBuilding_103022300048_103022300011(G,b10);

    addJalan_103022300048_103022300011(G, "TULT", "Asrama", 200);
    addJalan_103022300048_103022300011(G, "TULT", "BTP", 400);
    addJalan_103022300048_103022300011(G, "Asrama", "GKU", 500);
    addJalan_103022300048_103022300011(G, "GKU", "Cacuk", 400);
    addJalan_103022300048_103022300011(G, "GKU", "MSU", 600);
    addJalan_103022300048_103022300011(G, "Cacuk", "MSU", 200);
    addJalan_103022300048_103022300011(G, "GKU", "TUCH", 400);
    addJalan_103022300048_103022300011(G, "TUCH", "FIK", 100);
    addJalan_103022300048_103022300011(G, "FIK", "FEB", 120);
    addJalan_103022300048_103022300011(G, "FIK", "FIT", 350);
    addJalan_103022300048_103022300011(G, "FIT", "FEB", 300);


    do {
        displayMenu_103022300048_103022300011();
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1: {

                cout << "\n-- Tambah Gedung Baru --" << endl;
                cout << "Masukkan nama gedung: ";
                cin >> namaGedung;

                bool exists = false;
                adrBuilding current = start(G); // Mengakses elemen pertama daftar gedung
                while (current != NULL) {
                    if (info(current).buildingName == namaGedung) {
                        exists = true;
                        break;
                    }
                    current = nextBuilding(current); // Lanjut ke gedung berikutnya
                }
                if (exists) {
                    cout << "Gedung dengan nama \"" << namaGedung << "\" sudah ada!" << endl;
                } else {
                    infotypeBuilding newBuilding;
                    newBuilding.buildingName = namaGedung;
                    addBuilding_103022300048_103022300011(G, newBuilding);
                    cout << "Gedung berhasil ditambahkan!" << endl;
                }
                break;
            }

            case 2: {
                cout << "\n-- Tambah Rute/Jalan --" << endl;
                cout << "Gedung asal: ";
                cin >> gedungAwal;
                cout << "Gedung tujuan: ";
                cin >> gedungTujuan;
                cout << "Jarak (dalam meter): ";
                cin >> jarak;

                addJalan_103022300048_103022300011(G, gedungAwal, gedungTujuan, jarak);
                cout << "Rute berhasil ditambahkan!" << endl;
                break;
            }

            case 3: {
                cout << "\n-- Cari Gedung --" << endl;
                cout << "Masukkan nama gedung: ";
                cin >> namaGedung;

                adrBuilding found = findBuilding_103022300048_103022300011(G, namaGedung);
                if (found != NULL) {
                    cout << "Gedung '" << namaGedung << "' ditemukan!" << endl;

                    // Tampilkan rute yang tersedia dari gedung ini
                    cout << "Rute yang tersedia dari gedung ini:" << endl;
                    adrJalan J = firstJalan(found);
                    if (J == NULL) {
                        cout << "- Tidak ada rute yang tersedia" << endl;
                    } else {
                        while (J != NULL) {
                            cout << "- Ke " << info(destination(J)).buildingName
                                 << " (Jarak: " << info(J).jarak << " meter)" << endl;
                            J = nextJalan(J);
                        }
                    }
                } else {
                    cout << "Gedung tidak ditemukan." << endl;
                }
                break;
            }

            case 4: {
                cout << "\n-- Gedung yang Sering Dikunjungi --" << endl;
                frequentlyVisited_103022300048_103022300011(G);
                break;
            }

            case 5: {
                cout << "\n-- Petunjuk Arah --" << endl;
                cout << "Gedung asal: ";
                cin >> gedungAwal;
                cout << "Gedung tujuan: ";
                cin >> gedungTujuan;

                showRouteSteps_103022300048_103022300011(G, gedungAwal, gedungTujuan);
                break;
            }

            case 6: {
                cout << "\n-- Cari Rute Terpendek --" << endl;
                cout << "Gedung asal: ";
                cin >> gedungAwal;
                cout << "Gedung tujuan: ";
                cin >> gedungTujuan;

                findShortestRoute_103022300048_103022300011(G, gedungAwal, gedungTujuan);
                break;
            }

            case 7: {
                cout << "\n-- Emergency Route --" << endl;
                cout << "Masukkan nama gedung yang diblokir: ";
                cin >> namaGedung;

                adrBuilding blockedBuilding = findBuilding_103022300048_103022300011(G, namaGedung);
                if (blockedBuilding != NULL) {
                    adrJalan alternativeRoute = emergencyRoute_103022300048_103022300011(G, blockedBuilding);
                    cout << "Rute alternatif telah dihitung. Gunakan menu 6 untuk mencari rute terpendek yang menghindari gedung ini." << endl;
                } else {
                    cout << "Gedung tidak ditemukan." << endl;
                }
                break;
            }

            case 8: {
                cout << "\n-- Tampilkan Peta --" << endl;
                printMapGraph_103022300048_103022300011(G);
                break;
            }

            case 0: {
                cout << "\nTerima kasih telah menggunakan Sistem Navigasi Kampus!" << endl;
                break;
            }

            default: {
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }

    } while (pilihan != 0);

    return 0;
}
