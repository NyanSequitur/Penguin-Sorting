#include "dive.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "bubble.h"
#include "insertionSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "twoSort.h"




int main() {
    // Seeding the randomness w/ current time
    std::srand(std::time(NULL));


    int reads;
    int writes;
    int extraCount = 0;
    std::ofstream fileStream;


    std::vector<Dive> dives;
    const std::string FILE_NAME = "penguins.csv";

    // Run test to make sure everything works.
    diveTest();

    // Load file into vector
    readDivesFromFile(FILE_NAME, dives);

    // Verify count
    if (!verifyCount(FILE_NAME, dives)) std::cout << "Count mismatch error" << std::endl;
    else std::cout << "File loaded sucessfully" << std::endl;

    // 3d vector. spooky.
    std::vector<std::vector<Dive>> readWriteVector(10);

    // 

    for(int i = 1; i <= readWriteVector.size(); i++) {
        for (int j = 1; j <=(i*100) + extraCount; j++) {
            if (dives[j-1].getSeaSurfaceTemp() != 12345) readWriteVector[i-1].push_back(dives[j-1]);
            else extraCount++;
        }
        extraCount = 0;
    }


    // BUBBLE SORT

    fileStream.open("bubbleSort.csv");
    for (std::vector<Dive> numVec : readWriteVector) {
        std::vector<Dive> temp = numVec;
        bubbleSort(temp, reads, writes);
        fileStream << reads << " , " << writes << std::endl;
    }
    fileStream.close();

    
    // INSERTION SORT

    fileStream.open("insertionSort.csv");
    for (std::vector<Dive> numVec : readWriteVector) {
        std::vector<Dive> temp = numVec;
        insertionSort(temp, reads, writes);
        fileStream << reads << " , " << writes << std::endl;
    }
    fileStream.close();



    // QUICK SORT

    fileStream.open("quickSort.csv");
    for (std::vector<Dive> numVec : readWriteVector) {
        std::vector<Dive> temp = numVec;
        quicksortMedian3(temp, reads, writes);
        fileStream << reads << " , " << writes << std::endl;
    }
    fileStream.close();



    // HEAP SORT

    fileStream.open("heapSort.csv");
    for (std::vector<Dive> numVec : readWriteVector) {
        std::vector<Dive> temp = numVec;
        heapSort(temp, reads, writes);
        fileStream << reads << " , " << writes << std::endl;
    }
    fileStream.close();




    fileStream.open("twoSort.csv");
    for (std::vector<Dive> numVec : readWriteVector) {
        std::vector<Dive> temp = numVec;
        twoSort(temp, reads, writes);
        fileStream << reads << " , " << writes << std::endl;
    }
    fileStream.close();






    return 0;
}
