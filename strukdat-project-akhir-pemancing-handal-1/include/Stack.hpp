#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include "Lagu.hpp"
#include "Album.hpp"
#include "Artis.hpp"
#include "Playlist.hpp"
#include "Fileoperation.hpp"

using namespace std;
struct historyLagu
{
    string judulLagu;
    string genre;
    int durasi;
};

struct stackHistoryOutPlaylist
{
    historyLagu lagu;
    stackHistoryOutPlaylist *nextLagu;
    stackHistoryOutPlaylist *prevLagu;
};

struct stackHistoryInPlaylist
{
    historyLagu lagu;
    stackHistoryInPlaylist *nextLagu;
    stackHistoryInPlaylist *prevLagu;
};

struct playlist;
struct Lagu;
struct LaguPlaylist;

typedef LaguPlaylist *ptrLaguPlaylist;

typedef Lagu *ptrLagu;
typedef stackHistoryOutPlaylist *ptrStack;
typedef stackHistoryInPlaylist *ptrStackS;
typedef ptrStack topStack;
typedef ptrStackS topStackS;

typedef playlist *ptrPlaylist;
typedef ptrPlaylist firstPlaylist;

extern topStack top;
extern topStackS topS;
extern firstPlaylist headPlaylist;

void peek(topStack top);
void peekS(topStackS topS);
void pushSong(topStack &top, ptrStack &newLagu);
void pushSongS(topStackS &topS, ptrStackS &newLagu);
void popSongS(topStackS &topS);
void popSong(topStack &top);
void createStack(topStack &top);
void createNodeStackForOutsidePlaylist(ptrStack &newHistory, ptrLagu pBantuLagu);
void createNodeStackForInsidePlaylist(ptrStackS &newHistory, ptrLaguPlaylist pBantuLagu);




#endif