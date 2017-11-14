#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"


using namespace std;



void filevalid(string, vector<string> &, int &);

 
vector < vector <Pixel> > MakeAverage(vector < vector <vector <Pixel> > > );




int main(){

int i = 0;
string userimage;

vector < string > fileimages;



 do{
cout << "Enter BMP File Name" << endl;
cin >> userimage;
  if (userimage == "Done" || userimage == "done"){
    break;
    }
  else{
    filevalid( "userimage", fileimages, i);
    i++; 
    }
 }
while ( i < 10);
  
makeAverage();


return 0;
}





void filevalid(string a, vector < string > & bmp, int & i){

Bitmap image;

image.open(a);
bool valid;
valid = image.isImage();

    if (valid == false){
    i--;
    cout << "File entered was not valid BMP file" << endl;
    }
    else if (valid == true){
        if (bmp.size() == 0){
        bmp.push_back(a);
        }
        else if (bmp.size() != 0){
        Bitmap original;

        original.open(bmp[0]);

        vector <vector <Pixel> > first = original.toPixelMatrix();
        vector <vector <Pixel> > newpic = image.toPixelMatrix();
            if (first.size() == newpic.size() && first[0].size() == newpic[0].size()){
            bmp.push_back(a);
            }
            else{
            cout << "Image size is not compatible with other images." << endl;
            i--;
            }
        }

    }

}


//average function

vector <vector <Pixel > > makeAverage(vector < vector <vector <Pixel> > > huge ){

vector < vector < vector < Pixel > > > huge;
vector <vector <Pixel > > result;
Pixel rgb;
 sumR = 0;
 sumG = 0;
 sumB = 0;
            


    for (int row = 0; row < huge.size(); row++){
        for (int col = 0; col < huge[row].size(); col++){
            for (int depth = 0; depth < huge[row][col].size(); depth++){
            rgb = huge[row][col][depth];
            sumR = sumR + rgb.red;
            sumG = sumG + rgb.green;
            sumB = sumB + rbg.blue;
            
            }
            int average = (sumR + sumG + sumB)/depth.size();

       }
   }
}
