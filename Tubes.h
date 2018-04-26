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


