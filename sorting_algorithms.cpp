// Sorting Algorithms Class Methods CPP File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

#include "sorting_program.h"

/*************INPUT**************/

// Swap elements method:
void swap_elements(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

/*************PROCESS**************/

// Bubble Sort Algorithm:
void sorting_algorithms::bubble_sort(apvector<int> &data_set, struct DATA_TRACKERS &trackers) {

    // Declare and initialize duration variable and timer object:
    trackers.duration = 0.00;

    // Start run time timer (bubble sort):
    trackers.start = clock();

    int n = data_set.length();

    // Bubble sort "sorted" flag:
    bool flag = true;

    /*************PROCESS**************/

    for (int i = 0; i < n-1; i++) {

        flag = false;

        for (int j = 0; j < n-i-1; j++) {

            // Increase the comparison counter and draw the current vector graphically.
            trackers.comparisons++;

            // Draw and highlight the current element in the loop:
            draw_current(data_set, j, j, color.RED);
            al_rest(0.002);

            if (data_set[j] > data_set[j+1]) {

                // Increase move counter and swap adjacent elements.
                trackers.moves++;
                swap_elements(data_set[j], data_set[j+1]);

                /*************OUTPUT**************/
                display_graphical_vector(data_set, trackers, color.WHITE);

                flag = true;
            }
        }

        // Flag it and break if it never enteres the comparison statement.
        if (flag == false) {
            display_graphical_vector(data_set, trackers, color.WHITE);
            break;
        }

    }

    // Stop the timer and set the duration:
    trackers.duration = (clock() - trackers.start ) / (double) CLOCKS_PER_SEC;

    // Draw the final pass animation of the sorting algorithm.
    draw_final_sort(data_set, n, trackers.duration);
}

// Insertion Sort Algorithm:
void sorting_algorithms::insertion_sort(apvector<int> &data_set, struct DATA_TRACKERS &trackers) {

    // Reset duration timer to 0.00:
    trackers.duration = 0.00;

    // Start run time timer (insertion sort):
    trackers.start = clock();

    // Declaration of sorting algorithm variable used to track values while sorting and traversing the list.
    int i, current, prev;
    int n = data_set.length();

    // Traverse the entire vector start at index 1:
    for (i = 1; i < n; i++) {

        // Set the current and predecessor elements:
        current = data_set[i];
        prev = i - 1;

        /*************PROCESS**************/

        // Compare the current element (current) to its predecessor (j).
        trackers.comparisons++;
        while (prev >= 0 && data_set[prev] > current) {

            data_set[prev+1] = data_set[prev];
            trackers.moves++;
            prev -= 1;
        }

        // Draw and highlight the current element in the loop:
        draw_current(data_set, prev+1, prev, color.RED);
        al_rest(0.2);

        data_set[prev+1] = current;

        /*************OUTPUT**************/

        // Redraw the current vector graphically.
        display_graphical_vector(data_set, trackers, color.WHITE);

    }

    // Stop the timer.
    trackers.duration = (clock() - trackers.start ) / (double) CLOCKS_PER_SEC;

    // Draw the final pass animation of the sorting algorithm.
    draw_final_sort(data_set, n, trackers.duration);
}

// Merge Sort Algorithm:
void sorting_algorithms::merge(apvector<int> &data_set, int l, int m, int r, struct DATA_TRACKERS &trackers) {

    /*************PROCESS**************/

    // Find and set the size of the sub-vectors:
    int size_left = m - l + 1;
    int size_right = r - m;

    // Create vectors to store temporary data throughout the recursive levels:
    apvector<int> left_temp_data(size_left);
    apvector<int> right_temp_data(size_right);

    // Initialize the temp sub-vectors using the current vector:
    for(int i = 0; i < size_left; i++) {
        left_temp_data[i] = data_set[l + i];
    }

    for(int j = 0; j < size_right; j++) {
        right_temp_data[j] = data_set[m + 1 + j];
    }

    // Initialize the indices of the sub and merged sub-vectors:
    int i = 0, j = 0, k = l;

    // Begin to merge the sub-vectors:
    while (i < size_left && j < size_right) {

        trackers.comparisons++;

        if (left_temp_data[i] <= right_temp_data[j]) {
            draw_current(data_set, k, k, color.RED);
            data_set[k] = left_temp_data[i];
            i++;
        }

        else {
            draw_current(data_set, k, k, color.RED);
            data_set[k] = right_temp_data[j];
            j++;
            trackers.moves++;
        }

        al_rest(0.025);
        display_graphical_vector(data_set, trackers, color.WHITE);

        k++;
    }

    // Copy the remaining elements of the left sub-vectors:
    while (i < size_left) {
        data_set[k] = left_temp_data[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right sub-vectors:
    while (j < size_right) {
        data_set[k] = right_temp_data[j];
        j++;
        k++;
    }
}

void sorting_algorithms::merge_sort(apvector<int> &data_set, int l, int r, struct DATA_TRACKERS &trackers) {

    if (l < r) {

        /*************PROCESS**************/
        int m = l + (r - l) / 2;

        // Sort first and second halves of the data set:
        merge_sort(data_set, l, m, trackers);
        merge_sort(data_set, m + 1, r, trackers);

        // Display the screen after each merge and increase the move counter.
        merge(data_set, l, m, r, trackers);

        /*************OUTPUT**************/
        // Draw the current vector graphically.
        display_graphical_vector(data_set, trackers, color.WHITE);
    }
}

// Binary Search Algorithm:
int sorting_algorithms::binary_search(apvector<int> &data_set, int l, int r, int x, struct DATA_TRACKERS &trackers) {

    if (r >= l) {

        // Find the middle element in the data set:
        int mid_element = l + (r - l) / 2;

        // If the search for element is in the middle return itself:
        trackers.comparisons++;
        if (data_set[mid_element] == x) {
            return mid_element;
        }

        // If element is smaller than mid, then search for it in the left sub-list:
        trackers.comparisons++;
        if (data_set[mid_element] > x) {
            draw_binary_right_gray(data_set, mid_element);
            return binary_search(data_set, l, mid_element - 1, x, trackers);
        }

        // If greater, search for the element in right sub-list:
        else {
            draw_binary_left_gray(data_set, mid_element);
            return binary_search(data_set, mid_element + 1, r, x, trackers);
        }
    }

    // return -1 if the number is not present.
    return -1;
}
