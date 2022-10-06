/**
 * Clayton Cafiero
 * CS 124
 * 05-Jan-2021
 */
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <iostream>

/**
 * Using median-of-three method of choosing a pivot
 */
template<typename Comparable>
int partitionMedian3(std::vector<Comparable>& v, int start, int end, int &reads, int &writes) {

    int middle = (start + end) / 2;
    if (v[middle] < v[start]) {
        reads += 2;
        // swap middle and start
        Comparable temp = v[start];
        reads++;
        writes++;
        v[start] = v[middle];
        reads++;
        writes++;
        v[middle] = temp;
        reads++;
        writes++;
    }
    if (v[end] < v[start]) {
        reads += 2;
        // swap end and start
        Comparable temp = v[start];
        reads++;
        writes++;
        v[start] = v[end];
        reads++;
        writes++;
        v[end] = temp;
        reads++;
        writes++;
    }
    if (v[middle] < v[end]) {
        // swap middle and end
        Comparable temp = v[middle];
        reads++;
        writes++;
        v[middle] = v[end];
        reads++;
        writes++;
        v[end] = temp;
        reads++;
        writes++;
    }
    // the above leave the median of three at the end
    Comparable pivot = v[end];

    int i = start;
    for (int j = start; j <= end; ++j) {
        if (v[j] < pivot) {
            // swap j and i
            Comparable temp = v[j];
            reads++;
            writes++;
            v[j] = v[i];
            reads++;
            writes++;
            v[i] = temp;
            reads++;
            writes++;
            ++i;
        }
    }
    // swap i and end
    Comparable temp = v[i];
    reads++;
    writes++;
    v[i] = v[end];
    reads++;
    writes++;
    v[end] = temp;
    reads++;
    writes++;
    return i;
}


/**
 * Quicksort
 */
template<typename Comparable>
void quicksortMedian3(std::vector<Comparable>& v,
                      int start, int end, int &reads, int &writes) {
    if (end <= start) {
        return;  // base case for recursion; single element
    } else {
        // recursive case
        int p = partitionMedian3(v, start, end, reads, writes);
        quicksortMedian3(v, start, p - 1, reads, writes);
        quicksortMedian3(v, p + 1, end, reads, writes);
    }
}

/**
 * Quicksort. This is to set up the first recursive call.
 */

template<typename Comparable>
void quicksortMedian3(std::vector<Comparable>& v, int &reads, int &writes) {
    reads = writes = 0;
    quicksortMedian3(v, 0, v.size() - 1, reads, writes);
}

#endif