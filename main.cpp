#include <iostream>
#include <string>
#include "penulisList.h"
#include "jurnalList.h"
#include "relasiList.h"

using namespace std;

int main(){
    ListPenulis LP;
    ListJurnal LJ;
    List_relasi LR;

    createListPenulis(LP);
    createListJurnal(LJ);
    createListRelasi(LR);

    ////////////////////////////////////////////PENULIS TEST//////////////////////////////////////////
    cout << endl << "////////TEST PENULIS////////" << endl;
    elmPenulis* penulis;
    penulis = alokasiPenulis(101, "Yohan", "Mahasiswa");
    insertPenulis(LP, penulis);
    penulis = alokasiPenulis(102, "Budi", "Dosen");
    insertPenulis(LP, penulis);

    // Print List Penulis 
    cout << "List Penulis:" << endl;
    elmPenulis* P = LP.first;
    while (P != NULL){
        cout << "ID Penulis: " << P->info.idPenulis << ", Nama: " << P->info.namaPenulis << ", Status: " << P->info.status << endl;
        P = P->next;
    }
    cout << endl;

    //print find penulis
    int searchId = 102;
    elmPenulis* foundPenulis = findPenulis(LP, searchId);
    if(foundPenulis != NULL){ 
        cout << "Found Penulis with ID " << searchId << ": " << foundPenulis->info.namaPenulis << endl;
    } else {
        cout << "Penulis with ID " << searchId << " not found." << endl;
    }
    cout << endl;

    //delete penulis
    deletePenulis(LP, 101); 
    cout << "List Penulis after deletion of ID 101:" << endl;

    // Print List Penulis after deletion
    P = LP.first;
    while (P != NULL){
        cout << "ID Penulis: " << P->info.idPenulis << ", Nama: " << P->info.namaPenulis << ", Status: " << P->info.status << endl;
        P = P->next;
    }
    cout << endl;

    ////////////////////////////////////////////JURNAL TEST//////////////////////////////////////////
    cout << endl << "////////TEST JURNAL////////" << endl;
    infotypeJurnal jurnal;
    jurnal.idJurnal = "J001";
    jurnal.judulJurnal = "Algoritma_dan_Struktur_Data";
    jurnal.akreditasiJurnal = true;
    addressJurnal P1 = createElment(jurnal);
    insertJurnal(LJ, P1);

    jurnal.idJurnal = "J002";
    jurnal.judulJurnal = "Pemrograman_Lanjut";
    jurnal.akreditasiJurnal = false;
    addressJurnal P2 = createElment(jurnal);
    insertJurnal(LJ, P2);

    jurnal.idJurnal = "J003";
    jurnal.judulJurnal = "Basis_Data";
    jurnal.akreditasiJurnal = true;
    addressJurnal P3 = createElment(jurnal);
    insertJurnal(LJ, P3);

    printListJurnal(LJ);

    deleteJurnal(LJ, "J002");
    cout << "List Jurnal after deletion of J002:" << endl;

    printListJurnal(LJ);

    //print find jurnal
    cout << "Find Jurnal with ID J003:";
    addressJurnal foundJurnal = findJurnal(LJ, "J003");
    if(foundJurnal != NULL){
        cout << "Judul Jurnal: " << foundJurnal->info.judulJurnal << endl;
    } else {
        cout << "Jurnal not found." << endl;
    }

    ////////////////////////////////////////////RELASI TEST////////////////////////////////////////////
    P = findPenulis(LP, 101); // Yohan
    addressJurnal J = findJurnal(LJ, "J001");
    address_relasi R1 = alokasiRelasi(P, J);
    insertRelasi(LR, R1);
    P = findPenulis(LP, 102);
    J = findJurnal(LJ, "J003");
    address_relasi R2 = alokasiRelasi(P, J);
    insertRelasi(LR, R2);
    
    return 0;
}

