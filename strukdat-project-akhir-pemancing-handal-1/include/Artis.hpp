#ifndef ARTIS_HPP
#define ARTIS_HPP

#include "Album.hpp"
#include "Playlist.hpp"
#include "Fileoperation.hpp"
using namespace std;

struct Artis
{
    string idArtis;
    string namaArtis;
    int jumlahAlbum;
    Album *firstAlbum;
    Artis *nextArtis;
};

typedef Artis *ptrArtis;
typedef ptrArtis first;

void createDataList(first &list);
void createArtis(ptrArtis &newArtis);                                                               // membuat node artis baru taro di header artis
void traversalArtis(first head);                                                                    // menampilkan semua artis di luar playlist taro di header artis
void pickArtisFromList(first head, string key, int pilihArtis);                                     // memilih artis dari banyaknya artis dengan nama artis yang di cari diluar playlist masukin ke header artis
void traversalSearchArtis(first head, string key);
void traversalArtisByKey(first head, string key);
void fungsiMemilihArtis(first head, string key); // mencari artis dengan nama artis masukin ke header artis
bool deleteArtisWithNumber(first head, ptrArtis &ptrArtisPrev, ptrArtis &pBantuArtis, int pilihArtis);
bool searchArtis(first head, ptrArtis &pCariArtis, ptrArtis &pCariArtisPrev, const string key);     // mencari artis tertentu diluar playlilst masukin ke header artis
void insertFirstArtis(ptrArtis &newArtis, first &head);                                             // operasi insert first artis masukin ke header artis
void insertLastArtis(ptrArtis &newArtis, first &head);                                              // operasi insert last artis masukin ke header artis
void deleteFirstArtis(first &head, ptrArtis &pHapus);                                               // operasi delete first artis masukin ke header artis
void deleteLastArtis(first &head, ptrArtis &pHapus);                                                // operasi delete last  artis masukin ke header artis
void deletePcariArtis(ptrArtis pCariArtis, ptrArtis pCariArtisPrev, first &head, ptrArtis &pHapus); // operasi menghapus artis tertentu yang dicari masukin ke header artis

#endif // ARTIS_H
