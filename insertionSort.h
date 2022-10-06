/**
 * Clayton Cafiero
 * CS 124
 * 28-Dec-2020
 *
 * Insertion sort
 */
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <iostream>


/**
 * Insertion sort. Treat the 0 index item as being sorted
 * from the start. Outer loop begins at index 1.
 */
template<typename Comparable>
void insertionSort(std::vector<Comparable>& v, int &reads, int &writes) {
    reads = writes = 0;
    for (int i = 1; i < v.size(); ++i) {
        reads++;
        // read in loop


        Comparable value = v[i];  // the value we're going to insert
        reads++;
        writes++;

        int j = i - 1;
        while (j >= 0 && v[j] > value) {
            reads++;
            // read in loop


            v[j + 1] = v[j];  // shift the larger item right
            reads++;
            writes++;
            --j;  // move left
        }
        v[j + 1] = value;  // insert
        reads++;
        writes++;
    }
}

#endif