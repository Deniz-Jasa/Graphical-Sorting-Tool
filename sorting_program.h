// Graphical Sorting Primary Header File - Graphical Sorting Algorithms Assignment - Deniz Jasarbasic

// Once-Only Header File:
#ifndef SORTING_PROGRAM_H
#define SORTING_PROGRAM_H

// Standard C++ and Allegro libraries:
#include <iostream>
#include <cstdlib>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

// Apvector library:
#include "apvector.h"

// Console text color library:
#include "ConsoleColor.h"

// Project header files:
#include "menu_game_systems.h"
#include "sorting_algorithms.h"

// Allegro Graphical Sorting Program display size:
#define display_width 1280
#define display_height 720

using namespace std;

/*************STRUCTURE**************/

typedef struct DATA_TRACKERS {

    int moves;
    int comparisons;
    double duration;
    int data_set_size;
    clock_t start;

} DATA_TRACKERS;

/*************ADDITIONAL FUNCTIONS BY FILE NAMES************/

/**** Allegro Setup (additional addons & functions) ****/
void must_init(bool test, const char *description);
void display_init();
void display_deinit();

/**** Game Systems (vector functions) ****/
void initialize_vector(apvector<int> &data_set);
void initialize_vector_inorder(apvector<int> &data_set);

/**** Sorting Algorithms (additional function) ****/
void swap_elements(int &x, int &y);

#endif
