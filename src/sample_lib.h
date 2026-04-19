#ifndef SAMPLE_LIB_H
#define SAMPLE_LIB_H

#define MAX_NAME 128
#define MAX_INPUT 256

typedef struct House {
  char street_name[MAX_NAME];
  int number;
  double lat;
  double lon;
  struct House *next;
} House;

typedef struct {
  House *head;
  int count;
} HouseList;

typedef struct Place {
  char name[MAX_NAME];
  double lat;
  double lon;
  struct Place *next;
} Place;

typedef struct {
  Place *head;
  int count;
} PlaceList;

int is_valid_map_name(const char *name);
void run_program(void);

/* Houses */
void init_house_list(HouseList *list);
int append_house(HouseList *list, const char *street_name, int number,
                 double lat, double lon);
void free_house_list(HouseList *list);
House *find_exact_house(HouseList *list, const char *street_name, int number);
int street_exists(HouseList *list, const char *street_name);
int collect_valid_numbers(HouseList *list, const char *street_name,
                          int numbers[], int max_numbers);


                          /* Places */
void init_place_list(PlaceList *list);
int append_place(PlaceList *list, const char *name, double lat, double lon);
void free_place_list(PlaceList *list);
Place *find_exact_place(PlaceList *list, const char *name);

int collect_similar_streets(HouseList *list, const char *input,
                            char suggestions[][MAX_NAME], int max_suggestions);
                    
#endif