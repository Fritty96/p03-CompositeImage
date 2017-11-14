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

//Takes entered string, checks if it's bmp- prints error if not.
//If bmp, goes on to check if its the first string
//if yes, puts it in vector
//if no, compares the string against the first string for size
//if same size, adds it to the vector of strings
//if not the same size, prints error message and discards


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

//supposed to go through all of the user input pictures
//find the sum of each pixel and average
//place new average within a new vector to create composite image

vector <vector <Pixel > > makeAverage(vector < vector <vector <Pixel> > > huge ){
Pixel rgb;
vector <vector <Pixel > > result;




            


    for (int row = 0; row < huge.size(); row++){
        for (int col = 0; col < huge[row].size(); col++){
        
        int sumR = 0;
        int sumG = 0;
        int sumB = 0;
            for (int depth = 0; depth < huge[row][col].size(); depth++){
            
            rgb = huge[row][col][depth];
            sumR = sumR + rgb.red;
            sumG = sumG + rgb.green;
            sumB = sumB + rbg.blue;
            
            }
        int averageR = sumR /depth;
        int averageG = sumG /depth;
        int averageB = sumB /depth;
        rgb.red = averageR;
        rgb.green = averageG;
        rgb.blue = averageB;
      
       result[row][col] = rgb;   
       }
   }
 


}
