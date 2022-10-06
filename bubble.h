/**
 * Egbert Porcupine
 * CS 124
 * 27-Dec-2020
 * 
 * Bubble sort
 */
#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>
#include <iostream>


template<typename Comparable>
void bubbleSort(std::vector<Comparable>& v, int &reads, int &writes) {
    reads = writes = 0;
    int numComparisons = 0;
    bool haveSwapped = true;
    int numPasses = 0;
    while (haveSwapped) {
        haveSwapped = false;
        for (int i = 0; i < (v.size() - numPasses - 1); ++i) {
            // v.size() in comparison
            reads++;


            ++numComparisons;
            if (v[i] > v[i + 1]) {
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