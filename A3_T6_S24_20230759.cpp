#include <iostream>
#include <string>
#include "Image_Class.h"

using namespace std;

bool isValid(int x, int y, Image& img) {
    return (x >= 0 && x < img.width && y >= 0 && y < img.height);
}
/*
    img.width - 1: This expression calculates the maximum index value for the horizontal dimension (width) of the image.
     Since array indices start from 0, the maximum index is one less than the width of the image.

    img.height - 1: Similarly, this expression calculates the maximum index value for the vertical dimension (height) of the image.

    img.width - 1 - x: In the context of rotating the image by 90 degrees clockwise,
    the new x-coordinate is determined by subtracting the original x-coordinate (x) from the maximum index value for the width (img.width - 1).
    This effectively flips the image horizontally.

    img.height - 1 - y: Similarly, in this context, the new y-coordinate is determined by
    subtracting the original y-coordinate (y) from the maximum index value for the height (img.height - 1).
    This effectively flips the image vertically.


*/

int main() {
    string filename = "try.jpeg";
    Image img(filename);

    int deg;
    cout << "Enter rotation degrees (90, 180, 270): ";
    cin >> deg;

    if(deg == 90){
              Image rotImage(img.height, img.width);

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            for (int c = 0; c < 3; ++c) {
                int newX = y;
                // flips the image horizontally and transposes it.
                int newY = img.width - 1 - x;
                if (isValid(newX, newY, img)) {
                    rotImage.setPixel(newX, newY, c, img.getPixel(x, y, c));
                }
            }
        }
    }

    img = rotImage;
    }
    else if(deg == 180){
        Image rotImage(img.width, img.height);

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            for (int c = 0; c < 3; ++c) {
                int newX = img.width - 1 - x;
                int newY = img.height - 1 - y;

                if (isValid(newX, newY, img)) {
                    rotImage.setPixel(newX, newY, c, img.getPixel(x, y, c));
                }
            }
        }
    }

    img = rotImage;
    }
    else if (deg == 270){
        Image rotImage(img.height, img.width);

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            for (int c = 0; c < 3; ++c) {
                int newX = img.height - 1 - y;
                int newY = x;
                if (isValid(newX, newY, img)) {
                    rotImage.setPixel(newX, newY, c, img.getPixel(x, y, c));
                }
            }
        }
    }

    img = rotImage;
    }
    else {
        cout << "Wrong degrees enter correct ones !" << endl;
    }

    string outputFilename = "rotated" + to_string(deg) + filename;
    img.saveImage(outputFilename);

    cout << "Your image has been rotated successfully!" << endl;

    return 0;
}
