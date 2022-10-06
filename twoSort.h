#ifndef TWOSORT_H
#define TWOSORT_H

#include <vector>
#include <iostream>
#include "insertionSort.h"


template<typename Comparable>
void twoSort(std::vector<Comparable>& v, int &reads, int &writes) {
    insertionSort(v, reads, writes);
    modifiedBubble(v, reads, writes);
}




// had to modify bubble to sort by a field other than the default comparison overrides

template<typename Comparable>
void modifiedBubble(std::vector<Comparable>& v, int &reads, int &writes) {
    int numComparisons = 0;
    bool haveSwapped = true;
    int numPasses = 0;
    while (haveSwapped) {
        haveSwapped = false;
        for (int i = 0; i < (v.size() - numPasses - 1); ++i) {
            // v.size() in comparison
            reads++;
            ++numComparisons;
            if (v[i].getSeaSurfaceTemp() > v[i + 1].getSeaSurfaceTemp()) {
                reads += 2;
                // comparing 2 reads of v

                // The two elements are out of order. Swap them.
                Comparable temp = v[i];
                writes++;
                reads++;

                v[i] = v[i + 1];
                reads++;
                writes++;

                v[i + 1] = temp;
                reads++;
                writes++;
                // both pretty clear reads
                
                haveSwapped = true;
            }
        }
        ++numPasses;
    }
}

#endif