// Allegro Setup CPP File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

#include "sorting_program.h"

extern ALLEGRO_DISPLAY* disp;

/*************INPUT**************/

// Modular function that test all allegro functions and addons before running the program.
void must_init(bool test, const char *description) {

    if(test)
        return;

    //If allegro and its addons cannot be intizalized, returns error and name of troubled function or addon.
    cout << red << "ERROR! Couldn't initialize the " << description << "." << white << endl;
    exit(1);
}

void display_init() {

    // Anti-aliasing (makes primitives and images smoother)
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    // Allegro Display:
    disp = al_create_display(display_width, display_height);
    must_init(disp, "display");
}

// Allegro Primitives and Images:
void menu_system::primitive_init() {

    must_init(al_init_primitives_addon(), "primitives");
}

// Menu Bitmaps & Images:
void menu_system::menu_images_init() {

    // Allegro Image Addon:
    must_init(al_init_image_addon(), "image addon");


    // Main Menu Title & Logo:

    // Main Menu Buttons:
    menu_play_button = al_load_bitmap("images/menu_images/menu_play_buttons.png");
    must_init(menu_play_button, "menu play button image");

    menu_credits_button = al_load_bitmap("images/menu_images/menu_credits_buttons.png");
    must_init(menu_credits_button, "menu credits button image");

    menu_instructions_button = al_load_bitmap("images/menu_images/menu_instructions_buttons.png");
    must_init(menu_instructions_button, "menu instructions button image");

    main_menu_return = al_load_bitmap("images/menu_images/return_button.png");
    must_init(main_menu_return, "return to main menu button image");

    // Background:
    menu_background = al_load_bitmap("images/menu_images/menu_background.png");
    must_init(menu_background, "menu background image");
}

// Game Bitmaps & Images:
void game_system::game_images_init() {

    // Algorithm Buttons:
    bubble_sort_button = al_load_bitmap("images/game_images/buttons/bubble_sort_button.png");
    must_init(bubble_sort_button, "bubble sort button image");

    insertion_sort_button = al_load_bitmap("images/game_images/buttons/insertion_sort_button.png");
    must_init(insertion_sort_button, "insertion sort button image");

    merge_sort_button = al_load_bitmap("images/game_images/buttons/merge_sort_button.png");
    must_init(merge_sort_button, "merge sort button image");

    reset_button = al_load_bitmap("images/game_images/buttons/reset_button.png");
    must_init(reset_button, "reset button image");

    binary_search_button = al_load_bitmap("images/game_images/buttons/binary_search_button.png");
    must_init(binary_search_button, "binary search button image");

    // Counter and increase/decrease buttons.
    increase_1_button = al_load_bitmap("images/game_images/buttons/increase_1_button.png");
    must_init(increase_1_button, "increase 1 button image");

    increase_10_button = al_load_bitmap("images/game_images/buttons/increase_10_button.png");
    must_init(increase_10_button, "increase 10 button image");

    decrease_1_button = al_load_bitmap("images/game_images/buttons/decrease_1_button.png");
    must_init(decrease_1_button, "decrease 1 button image");

    decrease_10_button = al_load_bitmap("images/game_images/buttons/decrease_10_button.png");
    must_init(decrease_10_button, "decrease 10 button image");

    search_counter_image = al_load_bitmap("images/game_images/counter.png");
    must_init(search_counter_image, "search counter image");

}

// Allegro Mouse & keyboard Input addons:
void menu_system::mouse_init() {

    must_init(al_install_mouse(), "mouse");
}

void menu_system::keyboard_init() {

    must_init(al_install_keyboard(), "keyboard");
}

// Allegro fonts, color, and sound functions:
void menu_system::font_init() {

    al_init_font_addon();
    al_init_ttf_addon();

    // Body/Title Font:
    font.menu_text = al_load_font("fonts/arial.ttf", 20, 0);
    must_init(font.menu_text, "menu text font");

    // Body/Title Text Font:
    font.game_text = al_load_font("fonts/arial.ttf", 25, 0);
    must_init(font.game_text, "game text font");

    // Small text font:
    font.small_game_text = al_load_font("fonts/arial.ttf", 12, 0);
    must_init(font.small_game_text, "game text font");
}

// Intialization of in game and menu audio.
void menu_system::audio_init() {

    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(128);

    audio.button_click = al_load_sample("sounds/digital_button_click.wav");
    must_init(audio.button_click, "button click sound");

    audio.error = al_load_sample("sounds/error.wav");
    must_init(audio.error, "error click sound");

    audio.found = al_load_sample("sounds/found.wav");
    must_init(audio.error, "error click sound");

}

// Game and menu sound methods:
void menu_system::button_click_sound(float volume, float speed) {

    al_play_sample(
        audio.button_click,         // the sample to play
        volume,                     // gain ('volume')
        0.0,                        // pan ('balance')
        speed,                      // speed
        ALLEGRO_PLAYMODE_ONCE,      // play mode
        NULL                        // sample id
    );
}

void menu_system::error_click_sound(float volume, float speed) {

    al_play_sample(
        audio.error,                // the sample to play
        volume,                     // gain ('volume')
        0.0,                        // pan ('balance')
        speed,                      // speed
        ALLEGRO_PLAYMODE_ONCE,      // play mode
        NULL                        // sample id
    );
}

void menu_system::found_sound(float volume, float speed) {

    al_play_sample(
        audio.found,                // the sample to play
        volume,                     // gain ('volume')
        0.0,                        // pan ('balance')
        speed,                      // speed
        ALLEGRO_PLAYMODE_ONCE,      // play mode
        NULL                        // sample id
    );
}

// Game and menu color method:
void menu_system::color_init() {

    color.BLACK = al_map_rgb(0, 0, 0);
    color.WHITE = al_map_rgb(255, 255, 255);
    color.RED = al_map_rgb(255, 0, 0);
    color.GREEN = al_map_rgb(0, 255, 0);
    color.GREY = al_map_rgb(128, 128, 128);
}

// Deinitialization of allegro addons and functions:
void display_deinit() {

    al_destroy_display(disp);
}

void menu_system::menu_images_deinit() {

    al_destroy_bitmap(menu_background);
    al_destroy_bitmap(menu_play_button);
    al_destroy_bitmap(menu_credits_button);
    al_destroy_bitmap(menu_instructions_button);
    al_destroy_bitmap(main_menu_return);
}

void game_system::game_images_deinit() {

    al_destroy_bitmap(reset_button);
    al_destroy_bitmap(merge_sort_button);
    al_destroy_bitmap(insertion_sort_button);
    al_destroy_bitmap(bubble_sort_button);
    al_destroy_bitmap(binary_search_button);
    al_destroy_bitmap(increase_10_button);
    al_destroy_bitmap(increase_1_button);
    al_destroy_bitmap(decrease_10_button);
    al_destroy_bitmap(decrease_1_button);
    al_destroy_bitmap(search_counter_image);
}

void menu_system::font_deinit() {

    al_destroy_font(font.menu_text);
    al_destroy_font(font.game_text);
}
