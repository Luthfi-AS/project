#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "Artis.hpp"
#include "Playlist.hpp"
using namespace std;

struct Album
{
    string idAlbum;
    string judulAlbum;
    int jumlahLagu;
    Lagu *firstLagu;
    Album *nextAlbum;
};

typedef Album *ptrAlbum;

void createAlbum(ptrAlbum &newAlbum);                                                                                    // membuat node album baru taro di header album
void traversalAlbum(ptrArtis pBantuArtis); // menampilkan semua album dari artis tertentu di luar playlist taro di header album
void pickAlbumFromArtis(ptrArtis pBantuArtis, int pilihAlbum); // memilih album dari artis diluar playlist masukin ke header album
void pickAlbumFromList(first head, string key, int pilihAlbum);
void traversalAlbumByKey(first head, string key);
void fungsiMemilihAlbum(first head, string key); // mencari album tertentu yang ingin dilihat lagunya masukin ke header album
bool deleteAlbumWithNumber(ptrArtis pBantuArtis, ptrAlbum &ptrAlbumPrev, ptrAlbum &pBantuAlbum, int pilihAlbum);
void traversalSearchAlbum(first head, string key);                                                                       // mencari album tertentu yang ingin dilihat lagunya masukin ke header album
bool searchAlbuminArtis(ptrArtis pCariArtis, ptrAlbum &pCariAlbum, ptrAlbum &pCariAlbumPrev, const string key);          // mencari album dari artis tertentu masukin ke header album
void insertFirstAlbum(ptrAlbum &newAlbum, ptrArtis pCariArtis);                                                          // operasi insert first album masukin ke header album
void insertLastAlbum(ptrAlbum &newAlbum, ptrArtis pCariArtis);                                                           // operasi insert last album masukin ke header album
void deleteFirstAlbum(ptrArtis pCariArtis, ptrAlbum &pHapus);                                                            // operasi delete first album masukin ke header album
void deleteLastAlbum(ptrArtis pCariArtis, ptrAlbum &pHapus);                                                             // operasi delete last album masukin ke header album
void deletePcariAlbum(ptrArtis pCariArtis, ptrAlbum pCariAlbumPrev, ptrAlbum pCariAlbum, first &head, ptrAlbum &pHapus); // operasi menghapus album tertentu yang di search masukin ke header album

#endif
