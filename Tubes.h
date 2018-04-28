#include <iostream>


#include <conio.h>
#include <string>

using namespace std;
#include "list_child.h"
#include "list_parent.h"
#include "list_relasi.h"

void InsertNewFilm(List_child &LC, List_parent &LP); //Yoga
void ChangeFilm(List_child &LC, List_parent &LP);
void NewTeater(List_parent &LP); //Yoga
void DeleteFilm(List_child &LC, List_parent &LP);
void FilmToTeater(List_child &LC, List_parent &LP);
void DelTeater(List_child &LC, List_parent &LP); //Yoga
bool isConnected(address_parent P, address_child Q);
void cekRelasi(List_child &LC, List_parent &LP);
void printAll(List_parent &LP);
void DiskonekFilmteater(List_relasi &L, address_child C);
void HapusFilmDariTeater(List_parent &LP, List_child LC);
void RekomedasiGenre(List_child LC, List_parent LP);
void displayChild (List_child LC);
void displayParent (List_parent LP);
void displayChildofParent(List_parent LP);
