#include "Tubes.h"

void InsertNewFilm(List_child &LC, List_parent &LP)
/**
Nama : Yoga Ajitama
NIM :130117
**/
{
    film baru;
    cout<<"Judul: ";
    cin.ignore();
    getline(cin,baru.judul);
    cout<<"Genre: ";
    getline(cin,baru.genre);
    cout<<"Rating: ";
    cin>>baru.rating;
    insertLast(LC, alokasi(baru));
}

