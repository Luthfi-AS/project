#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "Lagu.hpp"
#include "Artis.hpp"
#include "Fileoperation.hpp"
#include "Stack.hpp"
using namespace std;       

struct LaguPlaylist
{
    string judulLagu;
    string genre;
    int durasi;
    LaguPlaylist *nextLagu;
    LaguPlaylist *prevLagu;
};

typedef LaguPlaylist *ptrLaguPlaylist;
 
struct Queue
{
    ptrLaguPlaylist head;
    ptrLaguPlaylist tail;
};

struct playlist
{
    string namaPlaylist;
    string jumlahLagu;
    playlist *next;
    Queue laguQueue;
};

struct Lagu;
struct Album;
struct Artis;

typedef Lagu *ptrLagu;
typedef Album *ptrAlbum;
typedef Artis *ptrArtis;
typedef playlist *ptrPlaylist;
typedef ptrArtis first;
typedef ptrPlaylist firstPlaylist;

void createPlayList(firstPlaylist &headPlaylist); //membuat playlist Baru taro di header playlist
void createQueue(Queue& Q); // membuat queue baru untuk di dalam playlist taro di header playlist
void createNodePlayList(ptrPlaylist &newPlaylist); //membuat node playlist baru taro di header playlist
void createElementLaguPlayList(ptrLaguPlaylist &newLaguPlaylist, ptrLagu pBantu); //membuat node lagu baru dalam playlist 
void traversalPlaylist(firstPlaylist headPlaylist); //menampilkan semua playlist yang dimiliki user simpen di playlist
void deleteLaguFromPlaylist(ptrLaguPlaylist &pBantuLaguPlaylist, ptrPlaylist &pBantuPlaylist);
void insertFirstPlaylist(firstPlaylist &headPlaylist, ptrPlaylist &newPlaylist);
void insertLastPlaylist(firstPlaylist &headPlaylist, ptrPlaylist &newPlaylist);
void enqueue(ptrPlaylist &pBantuPlaylist, ptrLaguPlaylist &newSong); // memasukkan lagu ke dalam playlist taro di header playlist
void dequeue(ptrPlaylist &pPlaylist, ptrLaguPlaylist &playedSong); // menghapus lagu dalam playlist taro di header playlist
void pickPlaylistToInsert(firstPlaylist headPlaylist, ptrPlaylist &pBantuPlaylist, int pilihPlaylist);
void outputMenuLaguDalamPLaylist(ptrLaguPlaylist pBantuLaguPlaylist); // menampilkan judul genre dan durasi dari lagu yang dipilih di dalam playlist taro di header playlist

void traversalLaguDalamPlaylist(ptrPlaylist pBantuPlaylist); // menampilkan semua lagu dalam playlist yang sudah dipilih taro di header playlist
void playingByQueueInPlaylist(ptrPlaylist pBantuPlaylist);
void pickLaguFromPlaylist(ptrPlaylist pBantuPlaylist, int pilihLagu);
void pickRandomLaguFromPlaylist(ptrPlaylist pBantuPlaylist);

void pickPlaylistFromList(firstPlaylist headPlaylist, int pilihPlaylist); // memilih playlist dari banyaknya playlist di awal menu masukin ke header playlist
void putarLaguBerdasarkanQueuePlaylist (ptrPlaylist pBantuPlaylist); //memutar seluruh lagu yang ada di playlist tertentu masukin ke header playlist
void insertPlayList(firstPlaylist& head, ptrPlaylist newPlayList); // operasi insert last playlist masukin ke header playlist

#endif