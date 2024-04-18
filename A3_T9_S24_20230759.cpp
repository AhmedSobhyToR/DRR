#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"
#include "Image_Class.h"


using namespace std;

int main() {
    int width, colors[3], fancyColor[3];
    string filename = "try.jpeg";
    Image img(filename);


    cout << "Enter the frame width: "<< endl;
    cin >> width;


    cout << "Enter the frame colors you want (Red, Green, Blue): "  << endl;
    for (int i = 0; i < 3; i++) {
        cin >> colors[i];
    }
// Simple Frame and also used for Fancy Frame

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            if (x <width ||y < width || x>= img.width-width|| y >=img.height-width) {
                for (int c = 0; c < 3; c++) {
                    img.setPixel(x, y, c, colors[c]);
                }
            }
        }
    }
// Fancy Frame
/*
    // Squares inside the frame to make a fancy frame
    cout << "Enter the square colors you want (Red, Green, Blue): " << endl;
    for (int i = 0; i < 3; i++) {
        cin >> fancyColor[i];
    }

    int square = width / 4;
    for (int y = 0; y < img.height; y += square * 2) {
        for (int x = 0; x < img.width; x += square * 2) {
            if (x < width || y < width || x >= img.width - width || y >= img.height - width) {
                for (int i = 0; i < square; i++) {
                    for (int j = 0; j < square; j++) {
                        img.setPixel(x + i, y + j, 0, fancyColor[0]);
                        img.setPixel(x + i, y + j, 1, fancyColor[1]);
                        img.setPixel(x + i, y + j, 2, fancyColor[2]);
                    }
                }
            }
        }
    }*/


    string outputFilename = "framed" + filename;
    img.saveImage(outputFilename);

    cout << "Your frame has got added successfully!"<< endl;

}
