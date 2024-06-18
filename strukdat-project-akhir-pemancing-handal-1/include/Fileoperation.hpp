#ifndef FILEOPERATION_HPP
#define FILEOPERATION_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Lagu.hpp"
#include "Artis.hpp"
#include "Playlist.hpp"
#include "Album.hpp"

using namespace std;

struct LaguPlaylist;
struct Lagu;
struct Album;
struct Artis;
struct playlist;
struct Queue;

typedef LaguPlaylist *ptrLaguPlaylist;
typedef Lagu *ptrLagu;
typedef Album *ptrAlbum;
typedef Artis *ptrArtis;
typedef playlist *ptrPlaylist;
typedef ptrArtis first;
typedef ptrPlaylist firstPlaylist;

void loadPlaylist(firstPlaylist &headPlaylist);
void saveLagu(ptrArtis head);
void loadLagu(ptrArtis &pBantu);
void savePlaylist(firstPlaylist head);

#endif
