#include <iostream>
#include "relasiList.h"

using namespace std;   

void createListRelasi(List_relasi &L) {
    L.first = NULL;
}

address_relasi alokasiRelasi(elmPenulis* P, addressJurnal J) {
    address_relasi Q = new elmlist_relasi;
    Q->child = J;
    Q->parent = P;
    Q->next = NULL;
    return Q;
}

address_relasi findRelasi(List_relasi L, elmPenulis P, addressJurnal J) {
    address_relasi Q = L.first;
    while (Q != NULL) {
        if (Q->parent->info.idPenulis == P.info.idPenulis && Q->child->info.idJurnal == J->info.idJurnal) {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

void insertRelasi(List_relasi &L, address_relasi R) {
    if (L.first == NULL) {
        L.first = R;
    } else {
        address_relasi Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
    R->next = NULL;
}

void deleteRelasi(List_relasi &L, address_relasi R) {
    if (L.first != NULL) {
        if (L.first == R) {
            L.first = R->next;
            delete R;
        } else {
            address_relasi Q = L.first;
            while (Q->next != NULL && Q->next != R) {
                Q = Q->next;
            }
            if (Q->next == R) {
                Q->next = R->next;
                delete R;
            }
        }
    }
}