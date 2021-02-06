// Menu Systems CPP File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

#include "sorting_program.h"

/*************OUTPUT*************/

// Menu Systems Constructor
menu_system::menu_system() {

    keyboard_init();
    mouse_init();
    primitive_init();
    menu_images_init();
    color_init();
    audio_init();
    font_init();
};

// Menu Systems draw method - draws the menu UI:
void menu_system::draw() {

    // Clears and set background to black:
    al_clear_to_color(color.BLACK);

    // Background & Title:
    al_draw_bitmap(menu_background, 0, 0, 0);

    // Menu buttons & bitmaps:
    al_draw_bitmap(menu_play_button, (display_width-450)/2, (display_height-200)/2, 0);
    al_draw_bitmap(menu_credits_button, (display_width-450)/2, (display_height)/2, 0);
    al_draw_bitmap(menu_instructions_button, (display_width-450)/2, (display_height+190)/2, 0);

}

// Menu Systems draw method - draws the menu credits:
void menu_system::draw_credits() {

    al_clear_to_color(color.BLACK);

    // Background & Title:
    al_draw_bitmap(menu_background, 0, 0, 0);

    // Return button:
    al_draw_bitmap(main_menu_return, -95, -50, 0);
    al_draw_text(font.menu_text, color.WHITE, 60, 18, 0, "Return to the Main Menu");

    // Additional creator and product information:
    al_draw_text(font.menu_text, color.WHITE, 170, 280, 0, "This version of Graphical Sorting was created by Deniz Jasarbasic for his ICS4U computer science summative.");
    al_draw_text(font.menu_text, color.WHITE, 188, 310, 0, "Copyright 2020-2021 Deniz Jasarbasic. All Rights Reserved. No part of this software may be reproduced, ");
    al_draw_text(font.menu_text, color.WHITE, 198, 340, 0, "distributed, or transmitted in any form or by any means unless given by the written consent of the DJA. ");

    al_flip_display();
}

// Menu Systems draw method - draws the menu instructions:
void menu_system::draw_instructions() {

    al_clear_to_color(color.BLACK);

    // Background & Title:
    al_draw_bitmap(menu_background, 0, 0, 0);

    // Return button:
    al_draw_bitmap(main_menu_return, -95, -50, 0);
    al_draw_text(font.menu_text, color.WHITE, 60, 18, 0, "Return to the Main Menu");

    // Instructions information:
    al_draw_text(font.menu_text, color.WHITE, 140, 190, 0, "The Graphical Sorting program is a tool that helps visualize various sorting algorithms graphically. In this program,");
    al_draw_text(font.menu_text, color.WHITE, 140, 220, 0, "users can pick from three different sorting algorithms and one search algorithm,");
    al_draw_text(font.menu_text, color.WHITE, 200, 290, 0, "1. Bubble Sort (Simple Sort) - Time Complexity: O(n^2).");
    al_draw_text(font.menu_text, color.WHITE, 200, 340, 0, "2. Insertion Sort (Simple Sort) - Time Complexity: O(n^2).");
    al_draw_text(font.menu_text, color.WHITE, 200, 390, 0, "3. Merge Sort (Advanced Sort) - Time Complexity: O(n*log(n)).");
    al_draw_text(font.menu_text, color.WHITE, 200, 440, 0, "4. Binary Search (Advanced Search) - Time Complexity: O(log(n)).");
    al_draw_text(font.menu_text, color.WHITE, 140, 510, 0, "Once selected, the algorithm will visually sort the unsorted list. If the binary search algorithm is selected, the program");
    al_draw_text(font.menu_text, color.WHITE, 140, 540, 0, "will automatically sort the list if it has not been sorted yet. Finally, the algorithm wiil return the index of the searched");
    al_draw_text(font.menu_text, color.WHITE, 140, 570, 0, "element. If the element is not present in the vector, the user will be notified.");

    al_flip_display();

}

/*************INPUT*************/

// Menu Systems mouse input and tracking.
bool menu_system::mouse_tracking_input(ALLEGRO_EVENT &event, int &mouse_x, int &mouse_y) {

    // Play button dimensions:
    int play_x1 = al_get_bitmap_width(menu_play_button) - 30;
    int play_y1 = al_get_bitmap_height(menu_play_button) + 169;
    int play_x2 = al_get_bitmap_width(menu_play_button) + 405;
    int play_y2 = al_get_bitmap_height(menu_play_button) + 215;

    // Credit button dimensions:
    int credit_x1 = al_get_bitmap_width(menu_credits_button) - 40;
    int credit_y1 = al_get_bitmap_height(menu_credits_button) + 255;
    int credit_x2 = al_get_bitmap_width(menu_credits_button) + 370;
    int credit_y2 = al_get_bitmap_height(menu_credits_button) + 305;

    // Instructions button dimensions:
    int instructions_x1 = al_get_bitmap_width(menu_instructions_button) - 40;
    int instructions_y1 = al_get_bitmap_height(menu_instructions_button) + 350;
    int instructions_x2 = al_get_bitmap_width(menu_instructions_button) + 405;
    int instructions_y2 = al_get_bitmap_height(menu_instructions_button) + 407;

    /*************PROCESS*************/

    // Play:
    if ((event.mouse.button & 1) && (mouse_x > play_x1 && mouse_x < play_x2) && (mouse_y > play_y1 && mouse_y < play_y2)) {
        button_click_sound(.5, 1.0);
        return false; // return false, and exit menu loop.
    }

    // Credit:
    if ((event.mouse.button & 1) && (mouse_x > credit_x1 && mouse_x < credit_x2) && (mouse_y > credit_y1 && mouse_y < credit_y2)) {
        button_click_sound(.5, 1.0);
        draw_credits();
        return true;
    }

    // Return to main menu:
    if ((event.mouse.button & 1) && (mouse_x > 10 && mouse_x < 50 ) && (mouse_y > 0 && mouse_y < 50)) {
        button_click_sound(.5, 1.0);
        draw();
        al_flip_display();
        return true;
    }

    // Instructions:
    if ((event.mouse.button & 1) && (mouse_x > instructions_x1 && mouse_x < instructions_x2) && (mouse_y > instructions_y1 && mouse_y < instructions_y2)) {
        button_click_sound(.5, 1.0);
        draw_instructions();
        return true;
    }

    return true; // Stay in the menu (true) until an action is made or button is selected.
}

void menu_system::menu_process(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_EVENT event, bool &menu_condition, bool &game_condition) {

    bool redraw_menu = true;
    int mouse_x, mouse_y;

    while(menu_condition) {

        al_wait_for_event(queue, &event);

        switch(event.type) {

        /*************INPUT**************/

        case ALLEGRO_EVENT_DISPLAY_CLOSE:

            // If the program is closed, end the loop, break, and close the program.
            menu_condition = false;
            game_condition = false;
            break;

        case ALLEGRO_EVENT_MOUSE_AXES:

            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
            break;

        /*************PROCESS*************/

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

            menu_condition = mouse_tracking_input(event, mouse_x, mouse_y);
            game_condition = !(menu_condition);
            break;
        }

        /*************OUTPUT*************/

        if(redraw_menu && al_is_event_queue_empty(queue)) {

            al_clear_to_color(color.BLACK); // Set backgrond to black

            // Draw all menu information including: credits, instructions, and the play button.
            draw();

            al_flip_display(); // Flips the display (updates the front and back buffer to display the drawings).
            redraw_menu = false;
        }
    }
}

/*************OUTPUT*************/

// Menu Systems Deconstructor:
menu_system::~menu_system() {

    menu_images_deinit();
};
