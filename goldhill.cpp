#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream ifs;
ofstream ofs;
ofstream ofss;

struct pix
{
    char r;
	char g;
	char b;
} px;

char    Header[54];

char infile[]       =   "d:\\goldhill.bmp";
char outfile[]      =   "d:\\goldhill_bw.bmp";
char image_data[]   =   "d:\\goldhill_data.txt";

int main()
{

    ifs.open( infile, ios::in|ios::binary );
    ifs.read( (char*) (&Header),sizeof(Header) );

    ofs.open( outfile, ios::out|ios::binary);
    ofs.write( (char*) (&Header),sizeof(Header) );

    ofss.open( image_data, ios::out);

    while(!ifs.eof())
    {
        ifs.read( (char*) (&px),sizeof(px) );

		int avg = (int)((px.r + px.g + px.b)/3);

        ofss<<"Lena.bmp: "<<(int)px.r<<", "<<(int)px.g<<", "<<(int)px.b<<"    "<<"Average: "<<(int)avg<<endl;

        px.r = px.g = px.b = avg;

        ofs.write((char*) (&px),sizeof(px));
    }

    ifs.close();
    ofs.close();
    ofss.close();

    return 0;
}
