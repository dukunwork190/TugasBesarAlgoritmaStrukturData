#ifndef JURNALLIST_H
#define JURNALLIST_H

#include <iostream>
#include <string>

using namespace std;

struct dataJurnal {
    string idJurnal;
    string judulJurnal;
    bool akreditasiJurnal;
};

typedef dataJurnal infotypeJurnal;

struct elmListJurnal {
    infotypeJurnal info;
    struct elmListJurnal* next;
};

typedef elmListJurnal* addressJurnal;

struct ListJurnal {
    addressJurnal first;
};

void createListJurnal(ListJurnal &L);
addressJurnal createElment(infotypeJurnal x);
void insertJurnal(ListJurnal &L, addressJurnal P);
void deleteJurnal(ListJurnal &L, string idJurnal);
addressJurnal findJurnal(ListJurnal L, string idJurnal);
void printListJurnal(ListJurnal L);

#endif