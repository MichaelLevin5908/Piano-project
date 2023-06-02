#include <iostream>

using namespace std;
char transformNote(int octave, char noteLetter, char accidentalSign);

char transformNote(int octave, char noteLetter, char accidentalSign)
{
      // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** transformNote was called with first argument = "
             << octave << endl;
    }

      // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
      //      to -1, 0,   1,   2,   3, ...,  11, 12

    int note;
    switch (noteLetter)
    {
      case 'C':  note =  0; break;
      case 'D':  note =  2; break;
      case 'E':  note =  4; break;
      case 'F':  note =  5; break;
      case 'G':  note =  7; break;
      case 'A':  note =  9; break;
      case 'B':  note = 11; break;
      default:   return ' ';
    }
    switch (accidentalSign)
    {
      case '#':  note++; break;
      case 'b':  note--; break;
      case ' ':  break;
      default:   return ' ';
    }

      // Convert ..., A#1, B1, C2, C#2, D2, ...
      //      to ..., -2,  -1, 0,   1,  2, ...

    int sequenceNumber = 12 * (octave - 2) + note;

    string keymap = "1!2@34$5%6^78*9(0qQwWeErtTyYuiIoOpPasSdDfgGhHjJklLzZxcCvVbBnm";
    if(sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap.at(sequenceNumber);
    }

bool isProperPiece(string piece){
if(piece.length() == 0)
return true;
if(piece[piece.length()-1] != '/')
return false;
int i = 0;
while(i<piece.length())
if(piece[i] == '/')
    i++;
else if(piece[i] == '1'|| piece[i] == '2'|| piece[i] == '3'|| piece[i] == '4'|| piece[i] == '5'|| piece[i] == '6'|| piece[i] == '7'|| piece[i] == '8'|| piece[i] == '9')
        i++;
else if(piece[i] == '#' || piece[i] == 'b')
i++;
else if(piece[i] != 'A' && piece[i] != 'B' && piece[i] != 'C' && piece[i] != 'D' && piece[i] != 'E' && piece[i] != 'F' && piece[i] != 'G'){
return false;
i++;}
return true;
}



bool isplayablePiece(string piece, int &position){
char ch1, ch2, ch3;
for(int i = 0;i<piece.length();i++){
    for(int j = 1;j<piece.length();j++){
        for(int f = 2; f<piece.length();f++){
ch1 = piece[i];
ch2 = piece[j];
ch3 = piece[f];
if(piece[0] == 'C' && piece[1] == '7')
return true;
else if(piece[0] == '1' && piece[1] == '1'){
    if(piece[0]){
        position = 0;
    }
    else{position =1;}
return false;}
else if(piece[0] == '7' && piece[1] == '7'){
    if(piece[0]){
        position = 0;
    }
    else{position =1;}
return false;}
else if(ch1 == 'B' && ch2 == '#' && ch3 == '1' )
    return true;
else if(ch2 == 'C' && ch3 == '7')
return true;
else if(ch1 == 'C' && ch2 =='b' && ch3 == '7')
return true;
else if(ch3 == '7'){
return false;
position = piece[f]-2;}
else if(ch3 == '1'){
position = piece[f]-2;
return false;}
            }
        }
    }
return true;
}
int transformPiece(string piece, string& instructions, int& badBeat){
if(!isProperpiece(piece));{
    return 1;
}
if(isProperpiece(piece) && !isPlayablepiece(piece));{
    return 2;}
int i = 0;
int noteCounter = 0;
string final;
char accidentalSign = ' ';
char note = piece[i];
int beatCounter = 0;
while(i<piece.length()){
if(piece[i] == '/'){
    piece[i] = ' ';
    i++;
    beatCounter++;
    continue;
    }
while(i != '/' || badBeat > 0){
    noteCounter+=1;
    if (piece[i] == '#'  ||  piece[i] == 'b')
            {
                accidentalSign = piece[i];
                i++;
            }
            int octave = 4;
            if (isdigit(piece[i]))
            {
                octave = piece[i] - '0';
                i++;
            }
    char note = transformNote(int octave, char noteLetter, char accidentalSign);
    if(note = ' ')
        badBeat = beatCounter;
    else if (piece[i] != '/'  &&  noteCounter == 1){
                final += '[';
                final += note;}
        }
    else if (noteCounter > 1){
            final += ']';
            i++;}
            final = instructions 
            return 0;
    }
}


int main(){
    return 0;
}
