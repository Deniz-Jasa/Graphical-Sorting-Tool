/************************************************************************************************************************
 *  Name: Deniz Jasarbasic                      Graphical Sorting Algorithms Assignment                     2020/10/29  *
 *                                                                                                                      *
 *  DESCRIPTION: The Graphical Sorting program is a tool that helps visualize various sorting algorithms graphically.   *
 *  In this program, users can pick from three different sorting algorithms and one search algorithm, a bubble sort,    *
 *  insertion sort, merge sort, and a binary search. Users can reset the vector and compare different algorithms with   *
 *  various outputed metrics and stats, such as number of comparisons, moves, and run times.                            *
 *************************************************************************************************************************/

#include "sorting_program.h"

// Allegro display:
ALLEGRO_DISPLAY* disp;

// Modular function that test that all allegro addons and functions are set and pre-initialized before main.
void must_init(bool test, const char *description);

int main() {

    /*************ALLEGRO**************/

    // Initialization of Allegro and Allegro addons:
    must_init(al_init(), "allegro");

    ALLEGRO_TIMER* timer = al_create_timer(0.2 / 60.0); // Creating a timer that updates 60 frames per second.
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue(); // Creating an event queue.
    must_init(queue, "queue");

    must_init(al_init_image_addon(), "image addon");

    display_init();

    // Initialization of menu and game class objects:
    menu_system menu;
    game_system game;

    // Registering keyboard, timer, and the display.
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_mouse_event_source());

    al_set_window_title(disp, "Graphical Sorting Algorithms Tool");

    /*************LOCAL VARIABLES**************/

    // Menu and game conditions:
    bool game_condition = false;
    bool menu_condition = true;

    // Initialization of data tracking member variables:
    DATA_TRACKERS trackers;

    trackers.moves = 0;
    trackers.comparisons = 0;
    trackers.data_set_size = 100;

    // Data set vector:
    apvector<int> data_set(trackers.data_set_size, 0);

    /*************INPUT*************/

    // Initialization of the vector data set:
    initialize_vector(data_set);

    /*************EVENTS*************/

    ALLEGRO_EVENT event;
    al_start_timer(timer);

    /*************PROCESS*************/

    // Game and menu logic:
    menu.menu_process(queue, event, menu_condition, game_condition);
    game.game_process(queue, event, menu_condition, game_condition, trackers, data_set);

    /*************OUTPUT*************/

    // Deinitialization of all Allegro addons, events, and timer:
    display_deinit();
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0; // Sucessfull run!
}
