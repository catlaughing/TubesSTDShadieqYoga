#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child X) {
    address_child P = new elmlist_child;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        last(L)->next = P;
        last(L) = P;
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
        cout<<endl;
        cout<<"Judul: "<<info(P).judul<<endl;
        cout<<"Genre: "<<info(P).genre<<endl;
        cout<<"Rating: "<<info(P).rating<<endl;
        cout<<"---------------"<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, string judul) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).judul==judul) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
