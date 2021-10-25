struct song_node{
  char artist[100];
  char name[100];
  struct song_node *next;
};

void print_song(struct song_node *s);
struct song_node * make_song(char *a, char *n);
struct song_node * insert_front(struct song_node *front,struct song_node *n);
int compare_song(struct song_node *s1, struct song_node *s2);
struct song_node * insert_order(struct song_node *front, char *a, char *n);
void print_list(struct song_node *s);
struct song_node * find_node(struct song_node *s, char *a, char *n);
struct song_node * find_first(struct song_node *s, char *a);
struct song_node * random_song(struct song_node *s);
struct song_node * remove_node(struct song_node *front, char *a, char *n);
struct song_node * free_list(struct song_node *s);
