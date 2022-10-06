#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <iostream>





inline int leftChild(int i) {
    return 2*i+1;
}

template<typename Comparable>
void percolateDown(std::vector<Comparable>& v, int start, int end, int &reads, int &writes) {
    int root = start;
    while (leftChild(root) <= end) {
        // If the index of our element is i, then left child index 
        // will be 2*i+1
        int child = leftChild(root);
        if (child+1 <= end && v[child] < v[child + 1]) {
            // there is a right child and its value is greater than
            // that of the left child
            ++child;
            reads += 2;
            // 2 reads in the comparison
        }

        if (v[root] < v[child]) {
            reads += 2;
            Comparable temp = v[root];
            reads++;
            writes++;

            v[root] = v[child];
            reads++;
            writes++;

            v[child] = temp;
            writes++;
            root = child;
        } else {
            return;
        }
    }
}

template<typename Comparable>
void heapify(std::vector<Comparable>& v, int size, int &reads, int &writes) {
    int start = (size - 2) /2 ;
    while (start >= 0) {
        percolateDown(v, start, size-1, reads, writes);
        --start;
    }
}

template<typename Comparable>
void heapSort(std::vector<Comparable>& v, int &reads, int &writes) {
    reads = writes = 0;
    int size = v.size();
    reads++;
    int end = size - 1;
    heapify(v, size, reads, writes);
    while(end > 0) {
        Comparable temp = v[end];
        reads++;
        writes++;
        v[end] = v[0];
        reads++;
        writes++;
        v[0] = temp;
        reads++;
        writes++;
        --end;
        percolateDown(v, 0, end, reads, writes);
    }   
}

#endif