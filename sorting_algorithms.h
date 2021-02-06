// Sorting Algorithms Class Header File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

// Once-Only Header File:
#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

// Main program header file:
#include "sorting_program.h"

class sorting_algorithms: public game_system {

  private:

    apvector<int> data_set;

  public:

    // Sorting Algorithms:
    void bubble_sort(apvector<int> &data_set, struct DATA_TRACKERS &trackers);
    void insertion_sort(apvector<int> &data_set, struct DATA_TRACKERS &trackers);
    void merge(apvector<int> &data_set, int l, int m, int r, struct DATA_TRACKERS &rackers);
    void merge_sort(apvector<int> &data_set, int l, int r, struct DATA_TRACKERS &trackers);

    // Search Algorithm:
    int binary_search(apvector<int> &data_set, int l, int r, int x, struct DATA_TRACKERS &trackers);

};

#endif
