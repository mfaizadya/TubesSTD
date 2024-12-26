#include <iostream>
#include <string>
#include "SNK.h"

using namespace std;

int main()
{
    Graph G;
    createGraph_103022300048_103022300011(G);
    int pilihan;
    string namaGedung, gedungAwal, gedungTujuan;
    int jarak;

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
