#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"
#include "Image_Class.h"
using namespace std;


int main() {
    string filename = "try.jpeg";
    Image img(filename);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            for (int c = 0; c < 3; c++) {
                img.setPixel(x, y, c, 255 -img.getPixel(x, y, c));
            }
        }
    }

    string outputFilename = "reversed" + filename;
    img.saveImage(outputFilename);

    cout << "Your image has been reversed!" << endl;

}
