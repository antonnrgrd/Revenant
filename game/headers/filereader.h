
#ifndef FREADER
#define FREADER
#include "information_reader.h"
#include "item.h"
/*We create a seperate source file for the reading in of actual structs due to the discovery of the issue of pointers being valid during the function call, but ceasing to be valid after the return of the function call (see the comment on reading in char pointers in the information_reader for an in-depth explanation, the same issue occured here and splitting to another source file fixed it */
Item *fr_readin_reagent(char *reagent_file_path);
Item *fr_readin_consumable(char *consumable_file_path);
#endif
