#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"
#include "Image_Class.h"

using namespace std;


int main() {
   string filename = "p.jpg";
    Image img(filename);

    int factor = 4;

    int newWidth = img.width / factor;
    int newHeight = img.height / factor;

// Create a new image for downsampling
    Image downsampledImage(newWidth, newHeight);

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            for (int c = 0; c < 3; c++) {
                int sum = 0;
                // Calculate the average pixel value
                for (int j = 0; j < factor; j++) {
                    for (int i = 0; i < factor; i++) {
                        sum += img.getPixel(x * factor + i, y * factor + j, c);
                    }
                }
                int avg = sum / (factor * factor);
                downsampledImage.setPixel(x, y, c, avg);
            }
        }
    }

// Upsample image to the original size
    Image blurredImage(img.width, img.height);
    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            for (int c = 0; c < 3; c++) {
                int value = downsampledImage.getPixel(x, y, c);
                for (int j = 0; j < factor; j++) {
                    for (int i = 0; i < factor; i++) {
                        blurredImage.setPixel(x * factor + i, y * factor + j, c, value);
                    }
                }
            }
        }
    }

    string outputFilename = "blurred_" + filename;
    blurredImage.saveImage(outputFilename);

    cout << "Your image has been blurred!" << endl;
    return 0;

}
