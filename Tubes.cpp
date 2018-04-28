#include "Tubes.h"
#include <cstdlib>

void InsertNewFilm(List_child &LC, List_parent &LP)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    film baru;
    cout<<"Judul : ";
    cin.ignore();
    getline(cin,baru.judul);
    cout<<"Genre : ";
    getline(cin,baru.genre);
    cout<<"Rating: ";
    cin>>baru.rating;
    if (findElm(LC, baru.judul) == NULL)
        insertLast(LC, alokasi(baru));
    else
        cout<<"Film telah tersedia"<<endl;
}

void ChangeFilm(List_child &LC, List_parent &LP)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    cout<<"Pilih teater yang ingin diganti filmnya: "<<endl;
    printInfo(LP);
    cout<<"Teater pilihan anda: ";
    int tepil;
    cin>>tepil;
    cout<<endl;
    teater *tepill = findElm(LP, tepil);
    cout<<"Film yang tayang pada teater "<<tepil<<": "<<endl;
    printInfo(child(tepill));
    if (first(child(tepill)) == NULL)
    {
        cout<<"Film tidak tersedia"<<endl;
    }
    else
    {
        cout<<"Film yang tersedia :"<<endl;
        printInfo(LC);
        cout<<"Judul film yang ingin diganti: ";
        string juduldiganti;
        cin.ignore();
        getline(cin,juduldiganti);
        address_child filmdiganti = findElm(LC, juduldiganti);
        address_relasi alamatfilm = findElm(child(tepill), filmdiganti);
        cout<<"Film baru: ";
        string judulpengganti;
        cin.ignore();
        getline(cin,judulpengganti);
        address_child filmpengganti = findElm(LC, judulpengganti);
        alamatfilm->info = filmpengganti;
        printInfo(child(tepill));
    }
}

void NewTeater(List_parent &LP) //Yoga
/**
Nama : Yoga Ajitama
NIM :130117
**/
{
    cout<<"Teater yang ada saat ini"<<endl;
    printInfo(LP);
    cout<<endl;
    int noteater;
    cout<<"Nomor teater baru: ";
    cin>>noteater;
    if (findElm(LP, noteater) == NULL)
    {
        teater* newteater = alokasi(noteater);
        InsertAndSort(LP, newteater);
        cout<<"Teater berhasil dibangun"<<endl;
    }
    else
    {
        cout<<"Duplikat Teater"<<endl;
    }
}

void DeleteFilm(List_child &LC,List_parent &LP)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    printInfo(LC);
    string judulfilm;
    cout<<"Judul film yang ingin dihapus: ";
    cin.ignore();
    getline(cin,judulfilm);
    address_child erasedfilm = findElm(LC, judulfilm);
    if (erasedfilm != NULL)
    {
        address_child filmbuangan;
        teater* P = first(LP);
        int i = 0;
        do
        {
            address_relasi Q = first(child(P));
            address_relasi R = findElm(child(P),erasedfilm);
            address_relasi S;
            if (R != NULL)
            {
                if (R == Q)
                    deleteFirst(child(P),S);
                else if (R != NULL)
                {
                    while (Q != NULL && info(next(Q)) != erasedfilm)
                        Q = next(Q);
                    if (Q != NULL)
                        deleteAfter(Q,S);
                }
                delete S;
            }
            i++;
            P = next(P);
        }while(P != first(LP));
        cout<<i<<endl;
        if (erasedfilm == first(LC))
            deleteFirst(LC,filmbuangan);
        else if(erasedfilm == last(LC))
            deleteLast(LC,filmbuangan);
        else
            deleteAfter(prev(erasedfilm), filmbuangan); //disini nih
        delete filmbuangan;
    }
}

void FilmToTeater(List_child &LC, List_parent &LP)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    printInfo(LC);
    string judulfilm;
    int noteater;
    cout<<"Judul film yang ingin ditambahkan: ";
    cin.ignore();
    getline(cin,judulfilm);
    if (findElm(LC, judulfilm) == NULL)
    {
        cout<<"Film tidak tersedia"<<endl;
    }
    else
    {
        printInfo(LP);
        cout<<"Teater yang diinginkan: ";
        cin>>noteater;
        address_child Q = findElm(LC, judulfilm);
        address_parent P= findElm(LP,noteater);
        if (!isConnected(P,Q)) {
            insertFirst(child(P), alokasi(Q));
            cout<<"Film berhasil ditambahkan ke teater "<<noteater<<endl<<endl;
            printInfo(child(P));
        }
        else {
            cout<<"Film berjudul "<<judulfilm<<" telah tersedia di teater "<<noteater<<endl;
        }
    }
}

void DelTeater(List_child &LC, List_parent &LP) //Yoga
/**
Nama : Yoga Ajitama
NIM :130117
**/
{
    cout<<"Teater yang tersedia: "<<endl;
    printInfo(LP);
    int tecur;
    cout<<"Teater yang ingin dihancurkan :";
    cin>>tecur;
    address_parent P = findElm(LP, tecur);
    address_parent R;
    address_parent S;
    address_relasi Q;
    if (P != NULL)
    {
        while (first(child(P)) != NULL)
        {
            deleteFirst(child(P),Q);
            delete Q;
        }
        if (P == first(LP))
        {
            deleteFirst(LP,S);
            cout<<"Teater berhasil dihancurkan"<<endl;
        }
        else
        {
            R = first(LP);
            while (next(R) != P)
            {
                R = next(R);
            }
            deleteAfter(LP,R,S);
            cout<<"Teater berhasil dihancurkan"<<endl;
        }
        delete S;
    }
    else
    {
        cout<<"Teater tidak ditemukan"<<endl;
    }
}

bool isConnected(address_parent P, address_child Q) {
    /**
    Nama : Yoga Ajitama
    NIM : 1301170471
    **/
    address_relasi R = findElm(child(P),Q);
    return (R != NULL);
}


void cekRelasi(List_child &LC, List_parent &LP) {

/**
Nama : Yoga Ajitama
NIM : 1301170471
**/

    int noteater;
    string judul;
    bool x = false;
    cout<<"Masukkan judul film: ";
    cin.ignore();
    getline(cin,judul);
    cout<<"Masukkan nomor teater : ";
    cin>>noteater;
    address_parent P = findElm(LP,noteater);
    address_child Q = findElm(LC,judul);
    if (P != NULL && Q != NULL) {
        x = isConnected(P,Q);
    }
    if (x == false) {
        cout<<"Teater dan film tidak terhubung"<<endl;
    }
    else {
        cout<<"Teater dan film terhubung"<<endl;
    }
}

void printAll(List_parent &LP)
/**
Nama : Yoga Ajitama
NIM : 1301170471
**/
{
    if (first(LP) == NULL)
        cout<<"Teater masih kosong"<<endl;
    else
    {
        address_parent P = first(LP);
        do
        {
            cout<<"Teater "<<info(P)<<endl;
            printInfo(child(P));
            cout<<endl;
            P = next(P);
        }while (P != first(LP));
    }
}

void DiskonekFilmteater(List_relasi &L, address_child C)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    address_relasi P;
    address_relasi Q = first(L);
    if (info(Q) == C)
        deleteFirst(L,P);
    else
    {
        while (info(next(Q)) != C)
            Q = next(Q);
        deleteAfter(Q,P);
    }
    delete P;
}

void HapusFilmDariTeater(List_parent &LP, List_child LC)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    int noteater;
    string judul;
    printInfo(LP);
    cout<<"Masukkan nomor teater yang ingin dihapus film nya: ";
    cin>>noteater;
    cout<<endl;
    address_parent P = findElm(LP,noteater);

    printInfo(child(P));
    cout<<"Masukkan judul yang ingin dihapus: ";
    cin.ignore();
    getline(cin, judul);
    address_child C = findElm(LC, judul);
    address_relasi R = findElm(child(P),C);
    if (R != NULL)
    {
        DiskonekFilmteater(child(P),C);
        cout<<"Film berhasil dihapus dari teater "<<noteater<<endl;
    }
    else
        cout<<"Judul tidak tersedia"<<endl;
}

void RekomedasiGenre(List_child LC, List_parent LP)
/**
Nama : Nuurshadieq
NIM : 1301171087
**/
{
    printGenre(LC);
    string genre;
    cout<<"Genre yang anda inginkan: ";
    cin.ignore();
    getline(cin, genre);
    findGenre(LC, genre);
}

void displayChild (List_child LC)
/**
Nama : Yoga Ajitama
NIM : 1301170471
**/
{
    cout<<"Film yang tersedia di database: "<<endl;
    printInfo(LC);
}

void displayParent (List_parent LP)
/**
Nama : Yoga Ajitama
NIM : 1301170471
**/
{
    cout<<"Teater yang tersedia saat ini: "<<endl;
    printInfo(LP);
}

void displayChildofParent(List_parent LP)
{
    /**
    Nama : Nuurshadieq
    NIM : 1301171087
    **/

    int noteater;
    printInfo(LP);
    cout<<"Masukkan nomor teater yang anda inginkan: ";
    cin>>noteater;
    address_parent P = findElm(LP,noteater);
    printInfo(child(P));
}
