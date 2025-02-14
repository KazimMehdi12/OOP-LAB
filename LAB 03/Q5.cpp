#include<iostream>
using namespace std;

class MusicPlayer{
private:
    string playlist[100];
    int totalSongs;
    string currentlyPlayingSong;

public:
    void Initialize(){
        totalSongs = 0;
        currentlyPlayingSong = " ";
    }

    void addSong(string songName){
        if(totalSongs < 100){
            playlist[totalSongs] = songName;
            totalSongs++;
        }
    }

    void removeSong(string songName){
       for(int i=0; i<totalSongs; i++){
          if(playlist[i] == songName){
              for(int j=i; j<totalSongs-1; j++){
                  playlist[j] = playlist[j+1];
			  }   totalSongs--;
                  return;              }
        }
    }

    void playSong(string songName){
        for(int i=0; i<totalSongs; i++){
          if(playlist[i] == songName){
              currentlyPlayingSong = songName;
			  cout<<"Current Playing Songs: "<<currentlyPlayingSong<<endl;
              return;
                      }
        }   cout<<"Song Not Found"<<endl;
    }

    void Display(){
        cout<<"Playlist:"<<endl;
        for(int i=0; i<totalSongs; i++) {
            cout<<i+1<<"  "<<playlist[i]<<endl;
			   }
    }
};

int main() {
    MusicPlayer IP;
    
    IP.Initialize();
    IP.addSong("Song X");
    IP.addSong("Song Y");
    IP.addSong("Song Z");
    IP.Display();
    IP.playSong("Song Y");
    IP.removeSong("Song X");
    IP.Display();
    
    return 0;
}
