#include <fstream>

using namespace std;
// How to create a ppm formatted image file.
int width = 400, height = 400, maxval = 400;

int main(){
    ofstream img ("picture.ppm");
    img << "P3" << endl;
    img << width << " " << height << endl;
    img << maxval << endl;

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            int r = x % 400;
            int g = y % 400;
            int b = (x*y) % 400;

            img << r << " " << g << " " << b << endl;
        }
    }
    system("open picture.ppm");
    return 0;
}