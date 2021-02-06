// Menu & Game Systems Class Header File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

// Once-Only Header File:
#ifndef MENU_GAME_SYSTEMS_H
#define MENU_GAME_SYSTEMS_H

#include "sorting_program.h"

// Menu Systems Class:
class menu_system {

  protected:

    /*************STRUCTURES**************/

    // Graphical Sorting menu and game fonts and audio:
    typedef struct FONT {

        ALLEGRO_FONT* menu_text;
        ALLEGRO_FONT* game_text;
        ALLEGRO_FONT* small_game_text;

    } FONT;

    FONT font;

    typedef struct AUDIO {

        ALLEGRO_SAMPLE* button_click;
        ALLEGRO_SAMPLE* error;
        ALLEGRO_SAMPLE* found;

    } AUDIO;

    AUDIO audio;

    /*************BITMAPS**************/

    // Graphical Sorting menu background bitmap:
    ALLEGRO_BITMAP* menu_background;

    // Graphical Sorting menu buttons:
    ALLEGRO_BITMAP* menu_play_button;
    ALLEGRO_BITMAP* menu_credits_button;
    ALLEGRO_BITMAP* menu_instructions_button;
    ALLEGRO_BITMAP* main_menu_return;

  public:

    /*************STRUCTURE**************/

    // Graphical Sorting menu and game colors:
    typedef struct COLOR {

        ALLEGRO_COLOR RED;
        ALLEGRO_COLOR WHITE;
        ALLEGRO_COLOR BLACK;
        ALLEGRO_COLOR GREEN;
        ALLEGRO_COLOR GREY;

    } COLOR;

    COLOR color;

    /*************METHODS**************/

    // Menu System constructor & deconstructor:
    menu_system();
    ~menu_system();

    // Menu System Methods:

    // Allegro menu logic method:
    void menu_process(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event, bool &menu_condition, bool &game_condition);

    // Menu draw methods:
    void draw();
    void draw_credits();
    void draw_instructions();

    // Menu mouse tracking and input method:
    bool mouse_tracking_input(ALLEGRO_EVENT &event, int &mouse_x, int &mouse_y);

    // Allegro addons:
    void keyboard_init();
    void mouse_init();
    void menu_images_init();
    void menu_images_deinit();
    void color_init();
    void audio_init();
    void primitive_init();
    void button_click_sound(float volume, float speed);
    void error_click_sound(float volume, float speed);
    void found_sound(float volume, float speed);
    void font_init();
    void font_deinit();

};

// Game Systems Class (inherits menu attributes, such as fonts, colors, sounds):
class game_system: public menu_system {

  protected:

    /*************BITMAPS**************/

    // Graphical Sorting game buttons:

    // Sorting & search buttons:
    ALLEGRO_BITMAP* bubble_sort_button;
    ALLEGRO_BITMAP* insertion_sort_button;
    ALLEGRO_BITMAP* merge_sort_button;
    ALLEGRO_BITMAP* binary_search_button;
    ALLEGRO_BITMAP* reset_button;

    // Search increase, decrease, and counter buttons and images:
    ALLEGRO_BITMAP* increase_1_button;
    ALLEGRO_BITMAP* increase_10_button;
    ALLEGRO_BITMAP* decrease_1_button;
    ALLEGRO_BITMAP* decrease_10_button;
    ALLEGRO_BITMAP* search_counter_image;;

    /*************BITMAP PROPERTIES**************/

    // Button bitmap locations (x,y):

    // Sorting & search buttons:
    const int bubble_sort_button_x = 35;
    const int bubble_sort_button_y = 20;
    const int insertion_sort_button_x = 218;
    const int insertion_sort_button_y = 20;
    const int merge_sort_button_x = 400;
    const int merge_sort_button_y = 20;
    const int binary_search_button_x = 947;
    const int reset_button_x = 1070;
    const int reset_button_y = 20;

    // Search increase and decrease buttons:
    const int increase_1_button_x = 635;
    const int decrease_1_button_x = 690;
    const int increase_10_button_x = 745;
    const int decrease_10_button_x = 800;

    // Search counter image and button:
    const int counter_image_x = 777;
    const int counter_buttons_y = 20;

    // Sorting metrics and data text properties:
    const int timer_text_x = 55;
    const int comparisons_text_x = 343;
    const int moves_text_x = 653;
    const int data_set_size_text_x = 960;
    const int text_y = 650;

  public:

    /*************METHODS**************/

    // Game System constructor & deconstructor:
    game_system();
    ~game_system();

    // Game System Methods:

    // Allegro game logic method:
    void game_process(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event, bool &menu_condition, bool &game_condition, struct DATA_TRACKERS &trackers, apvector<int> &data_set);

    // Game draw methods:
    void draw(struct DATA_TRACKERS &trackers);
    void draw_current(apvector<int> data_set, int current_element, int j, ALLEGRO_COLOR color);
    void draw_binary_right_gray(apvector<int> &data_set, int mid_element);
    void draw_binary_left_gray(apvector<int> &data_set, int mid_element);
    void draw_final_sort(apvector<int> data_set, int n, double duration);
    void display_graphical_vector(apvector<int> data_set, struct DATA_TRACKERS &trackers, ALLEGRO_COLOR color);

    // Game mouse tracking and input method:
    void mouse_input(ALLEGRO_EVENT &event, int &mouse_x, int &mouse_y, apvector<int> data_set, struct DATA_TRACKERS &trackers);

    // Game bitmap initialization and deintialization methods:
    void game_images_init();
    void game_images_deinit();

};

#endif
