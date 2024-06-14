#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Lagu.h"
#include "Artis.h"
#include "Playlist.h"
#include "Album.h"
using namespace std;

void loadplaylist();
void save(ptrArtis head);
void load(ptrArtis &pBantu);

#endif