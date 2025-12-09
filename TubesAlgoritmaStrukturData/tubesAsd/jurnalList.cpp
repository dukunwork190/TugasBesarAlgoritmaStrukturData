#include <iostream>
#include <string>
#include "jurnalList.h"
using namespace std;

void createListJurnal(ListJurnal &L){
    L.first = NULL;
}

addressJurnal createElment(infotypeJurnal x){
    addressJurnal P = new elmListJurnal;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertJurnal(ListJurnal &L, addressJurnal P){
    if (P != NULL) {
        if (L.first == NULL) {
            L.first = P;
        } else {
            addressJurnal last = L.first;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = P;
        }
    }
}

void deleteJurnal(ListJurnal &L, string idJurnal){
    addressJurnal P = L.first;
    if(P != NULL){
        if(P->info.idJurnal == idJurnal){
            L.first = P->next;
            delete P;
        } else {
            addressJurnal Q = P;
            P = P->next;
            while(P != NULL && P->info.idJurnal != idJurnal){
                Q = P;
                P = P->next;
            }
            if(P != NULL){
                Q->next = P->next;
                delete P;
            }
        }
    }
}

addressJurnal findJurnal(ListJurnal L, string idJurnal){
    addressJurnal P = L.first;
    while(P != NULL){
        if(P->info.idJurnal == idJurnal){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void printListJurnal(ListJurnal L){
    addressJurnal P = L.first;
    cout << "------------------------" << endl;
    while(P != NULL){
        cout << "ID Jurnal: " << P->info.idJurnal << endl;
        cout << "Judul Jurnal: " << P->info.judulJurnal << endl;
        cout << "Akreditasi Jurnal: " << (P->info.akreditasiJurnal ? "Ya" : "Tidak") << endl << endl;
        P = P->next;
    }
}