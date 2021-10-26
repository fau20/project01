#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "playlist.h"

void print_song(struct song_node *s) {
  printf("{%s, %s} ", s->artist, s->name);
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
  if(strcasecmp(s1->artist, s2->artist) == 0) {
    return (strcasecmp(s1->name, s2->name));
  }
  else return (strcasecmp(s1->artist, s2->artist));
}
struct song_node * insert_order(struct song_node *front, char *a, char *n) {
  struct song_node * new = make_song(a,n);
  if(front == NULL || (compare_song(new, front) <= 0)) {
    front = insert_front(front, new);
    return front;
  }
  struct song_node * start = front;
    while (front->next) {
      if(compare_song(new, front->next) <= 0) {
        new->next = front->next;
        front->next = new;
        return start;
      }
      front = front->next;
    }
    if(compare_song(new, front) <= 0) {
		    front = insert_front(front,new);
        return front;
	}

	  front->next = new;
	  new->next = NULL;
    return start;
}

//print list
void print_list(struct song_node *s) {
    printf("[");
    while(s) {
    print_song(s);
    printf("| ");
    s = s->next;
    }
    printf("]\n");
}

// find node based on artist and song
struct song_node * find_node(struct song_node *s, char *a, char *n) {
  if(s == NULL) return NULL;
    while(s) {
      if((strcasecmp(s->artist,a) == 0) && (strcasecmp(s->name,n) == 0)) return s;
      s = s->next;
  }
  return NULL;
}

// find node of first song from artist
struct song_node * find_first(struct song_node *s, char *a) {
  if(s == NULL) return NULL;
    while(s) {
      if((strcasecmp(s->artist,a) == 0)) return s;
      s = s->next;
  }
  return NULL;
}

struct song_node * random_song(struct song_node *s) {
  int i = 0;
  struct song_node *t = s;
  while(t->next != NULL) {
    i++;
    t = t->next;
  }
  int r = rand() % i;
  int n = 0;
  while(n < r) {
    s = s->next;
    n++;
  }
  return s;
}

struct song_node * remove_node(struct song_node *front, char *a, char *n) {
  if (front == NULL) return NULL;
  if((strcasecmp(front->artist,a) == 0) && (strcasecmp(front->name,n) == 0)) {
    front = front->next;
    return front;
  }
  struct song_node * first = front;
  while(front->next) {
  if((strcasecmp(front->next->artist,a) == 0) && (strcasecmp(front->next->name,n) == 0)) {
    front->next = front->next->next;
    return front;
  }
    else front = front-> next;
  }
  return first;
}

struct song_node * free_list(struct song_node *s) {
  if(s == NULL) return NULL;
  struct song_node * front  = s;
  struct song_node *d = s;
  while(s) {
    d = s;
    s = s->next;
    free(d);
  }
  return front;
}
