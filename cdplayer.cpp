#include <iostream>
#include <string>
using namespace std;

bool isValidCDPlayerString(string cdstring); // defining functions
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
bool isOpen(string cdstring);
int currentTrack(string cdstring);

bool isValidCDPlayerString(string cdstring){
    size_t cdlength = cdstring.size();
    int open = 0,disc = 0,ctrack1 = -1, play= 0, errortracker = 0,ntrack = 0;
    if(cdstring[0] != 'O')
        errortracker++;        // Variable to track errors, increments by one  if the first command is not O
    for(int i = 0; i < cdlength; i++){
        if(cdstring[i]=='O'&& open == 0)
            open = 1;
        else if(cdstring[i]=='C' && open == 1)
            open = 0;
        else if(cdstring[i]=='I' && disc == 0 && open == 1){
            disc = 1;
            ctrack1 = 0;
        }
        else if(cdstring[i]=='R' && disc == 1 && open == 1){
            disc = 0;
            ctrack1= -1;
        }
        else if(cdstring[i]=='P' && disc == 1 && open == 0)
            play = 1;
        else if(cdstring[i] == 'S' && play == 1)
            play = 0;
        else if(isdigit(cdstring[i]) && play == 1){
            ntrack = int(cdstring[i])-48;
            if(ntrack == (ctrack1+1)){
                ctrack1 = ntrack;    //updating current track if valid
            }
            else{
                errortracker++;
            }}
        else{
            errortracker++;
        }}
    if(errortracker == 0)  // if there are no errors, then this would return true
        return true;
    else     // if it detects any errors, then the function would return false
        return false;
}
bool hasCD(string cdstring){
    int hascd = 0;
    size_t cdlength = cdstring.size();
    for(int i = 0; i < cdlength; i++){
        if(cdstring[i] == 'I')
            hascd = 1;
        else if(cdstring[i] == 'R')
            hascd = 0;
    }
        if(isValidCDPlayerString(cdstring) == true && hascd == 1)  // if the string is valid and the cdplayer has a cd, then the function returns true
            return true;
        else
            return false;
}
int totalTracksPlayed(string cdstring){
    int ttp = 0;
    size_t cdlength = cdstring.size();
    for(int i = 0; i < cdlength; i++){
        if(isdigit(cdstring[i]))
            ttp ++;
    }
    if(isValidCDPlayerString(cdstring) == true)
        return(ttp);
    else
        return(-1);
}
int currentTrack(string cdstring){
    size_t cdlength = cdstring.size();
    int ctrack = 1;                         // Variable to keep track of current track
    for(int i = 0; i < cdlength; i++){
        if(cdstring[i] == 'R')
            ctrack = -1;
        else if(cdstring[i] == 'I')
            ctrack = 1;
        else if(isdigit(cdstring[i]))
            ctrack = int(cdstring[i])-47;
    }
    if(hasCD(cdstring) == false)
        ctrack = -1;
    if(isValidCDPlayerString(cdstring) == true)
        return(ctrack);
    else
        return(-1);
}
bool isOpen(string cdstring){
    int open1 = 0;
    size_t cdlength = cdstring.size();
    for(int i = 0; i < cdlength; i++){
        if(cdstring[i] == 'O')
            open1 = 1;     // Changing the variable to open if the current character being replaced int
        else if(cdstring[i] == 'C')
            open1 = 0;
    }
    if( isValidCDPlayerString(cdstring) == true && open1 == 1)
        return true;
    else
        return false;
}
int main(){
    string s;
    cout.setf( ios::boolalpha );
    for(;;){
        cout <<"Enter a possible result string: ";
        getline(cin, s); if (s == "quit") break;
        cout << "isValidCDPlayerString returns ";
        cout << isValidCDPlayerString(s) << endl;
        cout << "isOpen(s) returns ";
        cout << isOpen(s) << endl;
        cout << "hasCD(s) returns ";
        cout << hasCD(s) << endl;
        cout << "totalTracksPlayed(s) returns ";
        cout << totalTracksPlayed(s) << endl;
        cout << "currentTrack(s) returns ";
        cout << currentTrack(s) << endl;
        }
    return(0);
}

