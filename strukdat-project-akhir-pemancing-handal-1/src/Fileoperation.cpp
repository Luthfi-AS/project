#include "../include/Fileoperation.hpp"

void loadLagu(ptrArtis &pBantu)
{
    ifstream file("Data/Lagu.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    string line;
    pBantu = nullptr;
    ptrArtis currentArtis = nullptr;
    ptrAlbum currentAlbum = nullptr;

    while (getline(file, line))
    {
        if (line == "Artis:")
        {
            ptrArtis newArtis = new Artis;
            getline(file, newArtis->idArtis);
            getline(file, newArtis->namaArtis);
            file >> newArtis->jumlahAlbum;
            file.ignore();
            newArtis->nextArtis = nullptr;
            newArtis->firstAlbum = nullptr;

            insertLastArtis(newArtis, pBantu);
            currentArtis = newArtis;
            currentAlbum = nullptr;
        }
        else if (line == "Album:")
        {
            ptrAlbum newAlbum = new Album;
            getline(file, newAlbum->idAlbum);
            getline(file, newAlbum->judulAlbum);
            file >> newAlbum->jumlahLagu;
            file.ignore();
            newAlbum->nextAlbum = nullptr;
            newAlbum->firstLagu = nullptr;

            insertLastAlbum(newAlbum, currentArtis);
            currentAlbum = newAlbum;
        }
        else if (line == "Lagu:")
        {
            ptrLagu newLagu = new Lagu;
            getline(file, newLagu->idLagu);
            getline(file, newLagu->judulLagu);
            getline(file, newLagu->genre);
            file >> newLagu->durasi;
            file.ignore();
            newLagu->nextLagu = nullptr;
            newLagu->prevLagu = nullptr;

            insertLastLagu(newLagu, currentAlbum);
        }
    }

    file.close();
}

void loadPlaylist(firstPlaylist &headPlaylist)
{
    ifstream file("Data/Playlist.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan." << endl;
        return;
    }
    string line;
    ptrPlaylist currentPlaylist = nullptr;

    while (getline(file, line))
    {
        if (line == "Playlist:"){
            currentPlaylist = new playlist;
            getline(file, currentPlaylist->namaPlaylist);

            currentPlaylist->next = nullptr;
            currentPlaylist->laguQueue.head = nullptr;
            currentPlaylist->laguQueue.tail = nullptr;

            insertLastPlaylist(headPlaylist, currentPlaylist); 
        }  else if (line == "Lagu:")
        {
            ptrLaguPlaylist newLaguPlaylist = new LaguPlaylist;
            getline(file, newLaguPlaylist->judulLagu);
            getline(file, newLaguPlaylist->genre);
            file >> newLaguPlaylist->durasi;
            file.ignore();  // <- ini perlu untuk menangani newline setelah durasi

            newLaguPlaylist->nextLagu = nullptr;
            newLaguPlaylist->prevLagu = nullptr;

            enqueue(currentPlaylist, newLaguPlaylist);
        }
    }

    file.close();
}



void saveLagu(ptrArtis head)
{
    ofstream file("data.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }

    ptrArtis currentArtis = head;
    while (currentArtis != nullptr)
    {
        file << "Artis:" << endl;
        file << currentArtis->idArtis << endl;
        file << currentArtis->namaArtis << endl;
        file << currentArtis->jumlahAlbum << endl;

        ptrAlbum currentAlbum = currentArtis->firstAlbum;
        while (currentAlbum != nullptr)
        {
            file << "Album:" << endl;
            file << currentAlbum->idAlbum << endl;
            file << currentAlbum->judulAlbum << endl;
            file << currentAlbum->jumlahLagu << endl;

            ptrLagu currentLagu = currentAlbum->firstLagu;
            while (currentLagu != nullptr)
            {
                file << "Lagu:" << endl;
                file << currentLagu->idLagu << endl;
                file << currentLagu->judulLagu << endl;
                file << currentLagu->genre << endl;
                file << currentLagu->durasi << endl;
                currentLagu = currentLagu->nextLagu;
            }
            currentAlbum = currentAlbum->nextAlbum;
        }
        currentArtis = currentArtis->nextArtis;
    }

    file.close();
}

void savePlaylist(firstPlaylist head)
{
    ofstream file("Data/Playlist.txt");
    if (!file.is_open())
    {
        cout << "File tidak ditemukan." << endl;
        return;
    }
    ptrPlaylist currentplaylist = head;
    while (currentplaylist != nullptr)
    {
        file << "Playlist:" << endl;
        file << currentplaylist->namaPlaylist << endl;
        ptrLaguPlaylist currentLagu = currentplaylist->laguQueue.head;
        while (currentLagu != nullptr)
        {
            file << "Lagu:" << endl;
            file << currentLagu->judulLagu << endl;
            file << currentLagu->genre << endl;
            file << currentLagu->durasi << endl;
            currentLagu = currentLagu->nextLagu;
        }

        currentplaylist = currentplaylist->next;
    }
    file.close();
}
