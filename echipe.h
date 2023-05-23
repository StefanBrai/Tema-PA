#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player
{
    char* firstName;
    char* secondName;
    int points;
    struct player *next;
}Player;

typedef struct team {
    int nr_players;
    char *name_team;
    Player *first_member;
    struct team *next_team;
    float punctaj_echipa;
}Team;

void read_team(Team **top, FILE *f);

void score_calculator(Team* top);

void team_removal(Team **top);
