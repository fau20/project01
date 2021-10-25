#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "playlist.h"

void print_song(struct song_node *s) {
  printf("{%s, %s} | ", s->artist, s->name);
}
struct song_node * make_song(char *a, char *n) {
  struct song_node *s = malloc(sizeof(struct song_node));

  strncpy(s->artist, a, sizeof(s->artist));
  strncpy(s->name, n, sizeof(s->name));
  s->next = NULL;

  return s;
}


struct song_node * insert_front(struct song_node *front,struct song_node *n) {
  n->next = front;
  return n;
}
//insert node in order
int compare_song(struct song_node *s1, struct song_node *s2) {
  int i;
  i = strcasecmp(s1->artist, s2->artist);
  if(i != 0) return i;
  int j;
  j = strcasecmp(s1->name, s2->name);
  return j;
}
struct song_node * insert_order(struct song_node *front, char *a, char *n) {
  struct song_node * new = make_song(a,n);
  int i;
    struct song_node * current = front;
    while (current->next) {
      i = compare_song(front, current);
      if(i < 0) current = current->next;
      else insert_front(front,current);
    }
  return current;
}

//print list
void print_list(struct song_node *s) {
    struct song_node *current = s;
    printf("[");
    while(current) {
    print_song(current);
    current = current->next;
    }
    printf("]\n");
}

// find node based on artist and song
struct song_node * find_node(struct song_node *s, char *a, char *n) {
    struct song_node *current = s;
    while(current) {
      if(s->artist == a && s->name == n) return current;
      else current = current->next;
  }
  return NULL;
}

// find node of first song from artist
struct song_node * find_first(struct song_node *s, char *a) {
    struct song_node *current = s;
    while(current) {
      if(s->artist == a) return current;
      else current = current->next;
  }
  return NULL;
}

struct song_node * random_song(struct song_node *s) {
  int i = 0;
  struct song_node *t = s;
  while(t) {
    i++;
    t = t->next;
  }

  int r = rand() % i;
  int n = 0;
  while(n < r) {
    s = s->next;
  }
  return s;
}

struct song_node * remove_node(struct song_node *front, char *a, char *n) {
  if (front == NULL) return NULL;
  if(front->artist == a && front->name == n) front = front->next;

  struct song_node * first = front;
  while(first->next) {
  if(first->next->artist == a && first->next->name == n) {
    first->next = first->next->next;
    return front;
  }
  else {
    first = first-> next;
  }
  }
  return front;
}

struct song_node * free_list(struct song_node *s) {
  struct song_node *d = s;
  while(s) {
    struct song_node *b = s;
    s = s->next;
    free(b);
  }
  return NULL;
}
