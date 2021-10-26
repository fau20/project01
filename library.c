#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "playlist.h"
#include "library.h"

struct song_node ** make_library() {
  struct song_node ** library;
  library = calloc(27, sizeof(struct song_node *));
  return library;
}

int list_index(char *a) {
  if(tolower(a[0]) >= 97 && tolower(a[0]) <= 122) {
    return tolower(a[0]) - 97;
  }
  return 26;
}
struct song_node ** add_song(struct song_node ** library, char *a, char *n) {
  int index = list_index(a);
  library[index] = insert_order(library[index], a, n);

  return library;
}

struct song_node * song_search(struct song_node ** library, char *a, char *n) {
  int index = list_index(a);
  return find_node(library[index], a, n);
}

struct song_node * artist_search(struct song_node ** library, char *a) {
  int index = list_index(a);
  return find_first(library[index], a);
}

void letter_print(struct song_node ** library, char l) {
  if(tolower(l)>= 97 && tolower(l) <= 122) return print_list(library[l-97]);
  else print_list(library[26]);

}

void artist_print(struct song_node ** library, char *a) {
  int index = list_index(a);
  struct song_node *n = library[index];
  while(n) {
    if(strcasecmp(n->artist, a) == 0) print_song(n);
    n = n->next;
  }
}

void library_print(struct song_node ** library) {
  if(library != NULL)  {
  int i;
  for(i = 0; i < 27; i++) {
    if(i != 26) {
      printf("%c: ", 97+i);
    }
      else {
        printf("symbol: ");
      }
    print_list(library[i]);
  }
}
}

void shuffle_library(struct song_node ** library){
  srand(time(NULL));
  int i;
  for (i = 0; i < 10; i++) {
   srand(time(NULL) + i);
   int r = rand() % 27;

   while(library[r] == NULL)
    r = rand() % 27;

   print_song(random_song(library[r]));
 }
}

struct song_node ** delete_song(struct song_node ** library, char *a, char *n){
  int index = list_index(a);
  library[index] = remove_node(library[index], a, n);
  return library;
}

struct song_node ** clear_library(struct song_node ** library) {
    int i;
    for(i = 0; i < 27; i++) {
      library[i] = free_list(library[i]);
    }
    return library;
}
