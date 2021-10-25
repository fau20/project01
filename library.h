
struct song_node ** make_library();
int list_index(char *a);
struct song_node ** add_song(struct song_node ** library, char *a, char *n);
struct song_node * song_search(struct song_node ** library, char *a, char *n);
struct song_node * artist_search(struct song_node ** library, char *a);
void letter_print(struct song_node ** library, char l);
void artist_print(struct song_node ** library, char *a);
void library_print(struct song_node ** library);
void shuffle_library(struct song_node ** library);
struct song_node ** delete_song(struct song_node ** library, char *a, char *n);
struct song_node ** clear_library(struct song_node ** library);
