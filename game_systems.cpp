// Game Systems CPP File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

#include "sorting_program.h"
#include <algorithm>

// Global variable within the scope of this file.
int search_number = 0;

/*************INPUT*************/

// Game Systems constructor:
game_system::game_system() {

    font_init();
    game_images_init();
    color_init();
    audio_init();
};

// Create and initialize a given vector in order:
void initialize_vector_inorder(apvector<int> &data_set) {

    // Create an ordered list given the length of the vector
    for (int i = 0; i < data_set.length(); i++) {
        data_set[i] = i+1;
    }
}

// Shuffle method:
void shuffle_apvector(apvector<int> &data_set, int n) {

    srand((unsigned) time(0));

    for (int i = n - 1; i > 0; i--) {

        // Pick a random index from 0 to i
        int j = rand() % (i + 1);

        // Swap arr[i] with the element at random index
        swap_elements(data_set[i], data_set[j]);
    }
}

// Create and initialize a given vector with random integers:
void initialize_vector(apvector<int> &data_set) {

    // Create an ordered list given the length of the vector
    initialize_vector_inorder(data_set);

    // Shuffle the ordered list
    shuffle_apvector(data_set, data_set.length());
}

/*************PROCESS*************/

// Game Systems Mouse input:
void game_system::mouse_input(ALLEGRO_EVENT &event, int &mouse_x, int &mouse_y, apvector<int> data_set, struct DATA_TRACKERS &trackers) {

    // Sorting object called within this scope:
    sorting_algorithms sort;

    // Bubble Sort button dimensions:
    int bubble_button_x1 = bubble_sort_button_x;
    int bubble_button_y1 = bubble_sort_button_y;
    int bubble_button_x2 = bubble_sort_button_x + al_get_bitmap_width(bubble_sort_button); // add the width to find x2
    int bubble_button_y2 = bubble_sort_button_y + al_get_bitmap_height(bubble_sort_button);

    // Insertion sort button dimensions:
    int insertion_button_x1 = insertion_sort_button_x;
    int insertion_button_y1 = insertion_sort_button_y;
    int insertion_button_x2 = insertion_sort_button_x + al_get_bitmap_width(insertion_sort_button);
    int insertion_button_y2 = insertion_sort_button_y + al_get_bitmap_height(insertion_sort_button);

    // Reset button dimensions:
    int reset_button_x1 = reset_button_x;
    int reset_button_y1 = reset_button_y;
    int reset_button_x2 = reset_button_x + al_get_bitmap_width(reset_button);
    int reset_button_y2 = reset_button_y + al_get_bitmap_height(reset_button);

    // Merge Sort button dimensions:
    int merge_button_x1 = merge_sort_button_x;
    int merge_button_y1 = merge_sort_button_y;
    int merge_button_x2 = merge_sort_button_x + al_get_bitmap_width(merge_sort_button);
    int merge_button_y2 = merge_sort_button_y + al_get_bitmap_height(merge_sort_button);

    // Increase button dimensions (+1):
    int increase_1_button_x1 = increase_1_button_x;
    int increase_1_button_y1 = counter_buttons_y;
    int increase_1_button_x2 = increase_1_button_x + al_get_bitmap_width(increase_1_button);
    int increase_1_button_y2 = counter_buttons_y + al_get_bitmap_height(increase_1_button);

    // Decrease button dimensions (-1):
    int decrease_1_button_x1 = decrease_1_button_x;
    int decrease_1_button_y1 = counter_buttons_y;
    int decrease_1_button_x2 = decrease_1_button_x + al_get_bitmap_width(decrease_1_button);
    int decrease_1_button_y2 = counter_buttons_y + al_get_bitmap_height(decrease_1_button);

    // Increase button dimensions (+10):
    int increase_10_button_x1 = increase_10_button_x;
    int increase_10_button_y1 = counter_buttons_y;
    int increase_10_button_x2 = increase_10_button_x + al_get_bitmap_width(increase_10_button);
    int increase_10_button_y2 = counter_buttons_y + al_get_bitmap_height(increase_10_button);

    // Decrease button dimensions (-10):
    int decrease_10_button_x1 = decrease_10_button_x;
    int decrease_10_button_y1 = counter_buttons_y;
    int decrease_10_button_x2 = decrease_10_button_x + al_get_bitmap_width(decrease_10_button);
    int decrease_10_button_y2 = counter_buttons_y + al_get_bitmap_height(decrease_10_button);

    // Search button dimensions (-10):
    int search_button_x1 = binary_search_button_x;
    int search_button_y1 = counter_buttons_y;
    int search_button_x2 = binary_search_button_x + al_get_bitmap_width(binary_search_button); // add the width to find x2
    int search_button_y2 = counter_buttons_y + al_get_bitmap_height(binary_search_button);

    // Search increase button (+1):
    if ((event.mouse.button & 1) && (mouse_x > increase_1_button_x1 && mouse_x < increase_1_button_x2) && (mouse_y > increase_1_button_y1 && mouse_y < increase_1_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;
        search_number++;

        // re-draw the game, with updated data:
        draw(trackers);

        // Reintialize and display, if not already in order to 1-100.
        initialize_vector_inorder(data_set);
        display_graphical_vector(data_set, trackers, color.WHITE);
        al_flip_display();
    }

    // Search decrease button (-1):
    if ((event.mouse.button & 1) && (mouse_x > decrease_1_button_x1 && mouse_x < decrease_1_button_x2) && (mouse_y > decrease_1_button_y1 && mouse_y < decrease_1_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;
        search_number--;

        // re-draw the game, with updated data:
        draw(trackers);

        // Reintialize and display, if not already in order to 1-100.
        initialize_vector_inorder(data_set);
        display_graphical_vector(data_set, trackers, color.WHITE);
        al_flip_display();
    }

    // Search increase button (+10):
    if ((event.mouse.button & 1) && (mouse_x > increase_10_button_x1 && mouse_x < increase_10_button_x2) && (mouse_y > increase_10_button_y1 && mouse_y < increase_10_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;
        search_number += 10;

        // re-draw the game, with updated data:
        draw(trackers);

        // Reintialize and display, if not already in order to 1-100.
        initialize_vector_inorder(data_set);
        display_graphical_vector(data_set, trackers, color.WHITE);
        al_flip_display();
    }

    // Search decrease button (-10):
    if ((event.mouse.button & 1) && (mouse_x > decrease_10_button_x1 && mouse_x < decrease_10_button_x2) && (mouse_y > decrease_10_button_y1 && mouse_y < decrease_10_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;
        search_number -= 10;

        // re-draw the game, with updated data:
        draw(trackers);

        // Reintialize and display, if not already in order to 1-100.
        initialize_vector_inorder(data_set);
        display_graphical_vector(data_set, trackers, color.WHITE);
        al_flip_display();
    }

    if ((event.mouse.button & 1) && (mouse_x > search_button_x1 && mouse_x < search_button_x2) && (mouse_y > search_button_y1 && mouse_y < search_button_y2)) {

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;

        // Reintialize and display, if not already in order to 1-100.
        initialize_vector_inorder(data_set);

        // Begin the timer
        trackers.start = clock();

        // Search for selected number!
        int search_index = sort.binary_search(data_set, 0, data_set.length()-1, search_number, trackers);

        trackers.duration = (clock() - trackers.start ) / (double) CLOCKS_PER_SEC;

        // If serached number is not present in the vector:
        if (search_index == -1) {

            draw(trackers);
            display_graphical_vector(data_set, trackers, color.GREY);

            // Let the user the selected element is not present in the vector.
            error_click_sound(.5, 1.0);
            al_draw_textf(font.game_text, color.RED, counter_image_x-350, counter_buttons_y+100, 0, "Error! Element %d does not exist in the vector.", search_number);
            al_flip_display();
        }

        else {

            // Draw any remaining non-grayed out spots from left to right of the searched numbers.
            draw_binary_left_gray(data_set, search_index-1);
            draw_binary_right_gray(data_set, search_index+1);
            al_flip_display();
            draw(trackers);
            display_graphical_vector(data_set, trackers, color.GREY);
            draw_current(data_set, search_index, search_index, color.GREEN);

            // Let the user know that the searched number has been found (include num and index).
            found_sound(.4, 1.0);
            al_draw_textf(font.game_text, color.GREEN, counter_image_x-450, counter_buttons_y+100, 0, "Using a binary search, element %d was found at index %d.", search_number, search_index);
            al_draw_textf(font.game_text, color.WHITE, timer_text_x+122, text_y, 0, "%0.2f s", trackers.duration);
            al_flip_display();
        }

    }

    // Bubble sort button input:
    if ((event.mouse.button & 1) && (mouse_x > bubble_button_x1 && mouse_x < bubble_button_x2) && (mouse_y > bubble_button_y1 && mouse_y < bubble_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;

        sort.bubble_sort(data_set, trackers);
    }

    // Insertion sort button input:
    if ((event.mouse.button & 1) && (mouse_x > insertion_button_x1 && mouse_x < insertion_button_x2) && (mouse_y > insertion_button_y1 && mouse_y < insertion_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;

        sort.insertion_sort(data_set, trackers);
    }

    // Merge sort button input:
    if ((event.mouse.button & 1) && (mouse_x > merge_button_x1 && mouse_x < merge_button_x2) && (mouse_y > merge_button_y1 && mouse_y < merge_button_y2)) {

        button_click_sound(.5, 1.0);

        // Begin the timer
        trackers.start = clock();

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;

        sort.merge_sort(data_set, 0, data_set.length() - 1, trackers);

        trackers.duration = (clock() - trackers.start ) / (double) CLOCKS_PER_SEC;
        draw_final_sort(data_set, data_set.length(), trackers.duration);
    }

    // Reset button input:
    if ((event.mouse.button & 1) && (mouse_x > reset_button_x1 && mouse_x < reset_button_x2) && (mouse_y > reset_button_y1 && mouse_y < reset_button_y2)) {

        button_click_sound(.5, 1.0);

        // Reset data tracking variables:
        trackers.moves = 0;
        trackers.comparisons = 0;
        search_number = 0;

        display_graphical_vector(data_set, trackers, color.WHITE);
    }
}

// Game Systems draw method - draws the game UI:
void game_system::draw(struct DATA_TRACKERS &trackers) {

    al_clear_to_color(color.BLACK);

    // Sorting algorithm border and title:
    al_draw_rectangle(bubble_sort_button_x - 8, reset_button_y - 10, merge_sort_button_x+180, reset_button_y+45, color.WHITE, 1);
    al_draw_filled_rectangle(insertion_sort_button_x+10, reset_button_y+40, insertion_sort_button_x+al_get_bitmap_width(insertion_sort_button)-10, reset_button_y+60, color.BLACK);
    al_draw_text(font.small_game_text, color.WHITE, insertion_sort_button_x+34, reset_button_y+40, 0, "Sorting Algorithms");

    // Binary Search border and title:
    al_draw_rectangle(increase_1_button_x - 8, reset_button_y - 10, binary_search_button_x+65, reset_button_y+45, color.WHITE, 1);
    al_draw_filled_rectangle(insertion_sort_button_x+535, reset_button_y+40, insertion_sort_button_x+665, reset_button_y+60, color.BLACK);
    al_draw_text(font.small_game_text, color.WHITE, insertion_sort_button_x+563, reset_button_y+40, 0, "Binary Search");

    // Sorting & search algorithm buttons:
    al_draw_bitmap(bubble_sort_button, bubble_sort_button_x, bubble_sort_button_y, 0);
    al_draw_bitmap(insertion_sort_button, insertion_sort_button_x, insertion_sort_button_y, 0);
    al_draw_bitmap(merge_sort_button, merge_sort_button_x, merge_sort_button_y, 0);
    al_draw_bitmap(reset_button, reset_button_x, reset_button_y, 0);
    al_draw_bitmap(binary_search_button, binary_search_button_x, counter_buttons_y, 0);

    // Search counter and buttons:
    al_draw_bitmap(increase_1_button, increase_1_button_x, counter_buttons_y, 0);
    al_draw_bitmap(decrease_1_button, decrease_1_button_x, counter_buttons_y, 0);
    al_draw_bitmap(increase_10_button, increase_10_button_x, counter_buttons_y, 0);
    al_draw_bitmap(decrease_10_button, decrease_10_button_x, counter_buttons_y, 0);
    al_draw_bitmap(search_counter_image, counter_image_x, counter_buttons_y - 62, 0);

    if (to_string(search_number).length() == 1) {
        al_draw_textf(font.game_text, color.BLACK, counter_image_x+115, counter_buttons_y+2, 0, "%d", search_number);
    }

    else if (to_string(search_number).length() == 2) {
        al_draw_textf(font.game_text, color.BLACK, counter_image_x+108, counter_buttons_y+2, 0, "%d", search_number);
    }

    else {
        al_draw_textf(font.game_text, color.BLACK, counter_image_x+102, counter_buttons_y+2, 0, "%d", search_number);
    }

    // Algorithm metrics and stats:
    al_draw_text(font.game_text, color.WHITE, timer_text_x, text_y, 0, "Run Time:");
    al_draw_textf(font.game_text, color.WHITE, comparisons_text_x, text_y, 0, "Comparisons: %d", trackers.comparisons);
    al_draw_textf(font.game_text, color.WHITE, moves_text_x, text_y, 0, "Swaps/Moves: %d", trackers.moves);
    al_draw_textf(font.game_text, color.WHITE, data_set_size_text_x, text_y, 0, "Data Sample Size: %d", trackers.data_set_size);
}

// Game Systems draw method - draws a graphical representation of the data set vector:
void game_system::display_graphical_vector(apvector<int> data_set, struct DATA_TRACKERS &trackers, ALLEGRO_COLOR c) {

    al_clear_to_color(color.BLACK);
    draw(trackers);

    for (int i = 0; i < data_set.length(); i++) {

        al_draw_filled_rectangle((i+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[i]*5), (i+4.1)*((display_width)/data_set.length()), display_height-100, c);
        al_draw_rectangle((i+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[i]*5), (i+4.1)*((display_width)/data_set.length()), display_height-100, color.BLACK, 1);
    }

    al_flip_display();
}

// Game Systems draw method - draws and highlights (red) the current element in the vector:
void game_system::draw_current(apvector<int> data_set, int current_element, int j, ALLEGRO_COLOR color) {

    al_draw_filled_rectangle((j+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[current_element]*5), (j+4.1)*((display_width)/data_set.length()), display_height-100, color);
    al_flip_display();
}

// Game Systems draw method - draws and animates the final sort pass:
void game_system::draw_final_sort(apvector<int> data_set, int n, double duration) {

    al_rest(0.6);

    for (int k = 0; k < n; k++) {
        al_draw_filled_rectangle((k+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[k]*5), (k+4.1)*((display_width)/data_set.length()), display_height-100, color.GREEN);
        al_rest(0.015);
        al_flip_display();
    }

    for (int k = 0; k < n-1; k++) {
        al_draw_filled_rectangle((k+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[k]*5), (k+4.1)*((display_width)/data_set.length()), display_height-100, color.WHITE);
        al_flip_display();
    }

    al_draw_textf(font.game_text, color.WHITE, timer_text_x+122, text_y, 0, "%0.2f s", duration);
    al_flip_display();
}

// Game Systems draw method - draws and animates binary right sub-vector pass:
void game_system::draw_binary_right_gray(apvector<int> &data_set, int mid_element) {

    for (int k = mid_element; k < data_set.length(); k++) {
        al_draw_filled_rectangle((k+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[k]*5), (k+4.1)*((display_width)/data_set.length()), display_height-100, color.GREY);
        al_rest(0.014);
        al_flip_display();
    }
}

// Game Systems draw method - draws and animates binary left sub-vector pass:
void game_system::draw_binary_left_gray(apvector<int> &data_set, int mid_element) {

    for (int k = mid_element; k >= 0; k--) {
        al_draw_filled_rectangle((k+3.5)*((display_width)/data_set.length()), display_height-100-(data_set[k]*5), (k+4.1)*((display_width)/data_set.length()), display_height-100, color.GREY);
        al_rest(0.014);
        al_flip_display();
    }
}

void game_system::game_process(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event, bool &menu_condition, bool &game_condition, struct DATA_TRACKERS &trackers, apvector<int> &data_set) {

    bool redraw_game = true;
    int mouse_x, mouse_y;

    while(game_condition) {

        al_wait_for_event(queue, &event);

        /*************INPUT**************/

        switch(event.type) {

        case ALLEGRO_EVENT_DISPLAY_CLOSE:

            // If user clicks the display close button, end the loop, break, and close the program.
            game_condition = false;
            break;

        case ALLEGRO_EVENT_MOUSE_AXES:

            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
            break;

        /*************PROCESS*************/

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

            al_flush_event_queue(queue);
            mouse_input(event, mouse_x, mouse_y, data_set, trackers);
            al_flush_event_queue(queue);
            break;

        }

        /*************OUTPUT*************/

        if(redraw_game && al_is_event_queue_empty(queue)) {

            al_clear_to_color(color.BLACK); // Set backgrond to black

            // Draw the game UI:
            draw(trackers);

            // Draw the vector graphically:
            display_graphical_vector(data_set, trackers, color.WHITE);

            al_flip_display(); // Flips the display (updates the front and back buffer to display the drawings).
            redraw_game = false;
        }
    }
}

/*************OUTPUT*************/

// Game Systems deconstructor:
game_system::~game_system() {

    game_images_deinit();
    font_deinit();
};
