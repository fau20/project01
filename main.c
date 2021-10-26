#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "playlist.h"
#include "library.h"

int main() {
  struct song_node *start = NULL;
  start = insert_order(start, "ac/dc", "thunderstruck");
  start = insert_order(start, "pearl jam", "alive");
  start = insert_order(start, "pearl jam","yellow ledbetter");
  start = insert_order(start, "radiohead", "street spirit (fade out)");
  start = insert_order(start,"pink floyd", "time");
  start = insert_order(start, "radiohead", "paranoid android");
  start = insert_order(start,"pearl jam", "even flow");

  printf("Testing print_list:\n");
  print_list(start);
  printf("\n====================================\n");

  printf("Testing print_song:\n");
  print_song(start);
  printf("\n====================================\n");

  printf("Testing find_node:\n");
  print_song(find_node(start, "pearl jam", "alive"));
  printf("\n====================================\n");

  printf("Testing find_artist:\n");
  print_song(find_first(start, "pink floyd"));
  printf("\n====================================\n");

  printf("Testing random:\n");
  print_song(random_song(start));
  printf("\n====================================\n");

  printf("Testing remove:\n");
  print_song(remove_node(start, "ac/dc", "thunderstruck"));
  print_list(start);
  printf("\n====================================\n");

  printf("free_list:\n");
  (free_list(start));
  printf("\n====================================\n");

  printf("\n\nMUSIC LIBRARY TESTS\n==================================\n");
  struct song_node ** library = make_library();
  library = add_song(library, "ac/dc", "thunderstruck");
  library = add_song(library, "pearl jam", "alive");
  library = add_song(library, "pearl jam","yellow ledbetter");
  library = add_song(library, "radiohead", "street spirit (fade out)");
  library = add_song(library,"pink floyd", "time");
  library = add_song(library, "radiohead", "paranoid android");
  library = add_song(library,"pearl jam", "even flow");

  printf("Testing print_letter:\n");
  letter_print(library, 'p');
  printf("\n====================================\n");

  printf("Testing print_library:\n");
  library_print(library);
  printf("\n====================================\n");

  printf("Testing song_search:\n");
  print_song(song_search(library, "pearl jam", "alive"));
  printf("\n====================================\n");

  printf("Testing artist_search:\n");
  print_song(artist_search(library, "pearl jam"));
  printf("\n====================================\n");

  printf("Testing artist_print:\n");
  artist_print(library, "pearl jam");
  printf("\n====================================\n");

  printf("Testing shuffle_library:\n");
  shuffle_library(library);
  printf("\n====================================\n");

  printf("Testing delete_song:\n");
  delete_song(library, "pearl jam", "alive");
  library_print(library);
  printf("\n====================================\n");

  printf("Testing clear_library:\n");
  clear_library(library);
  printf("\n====================================\n");
}
