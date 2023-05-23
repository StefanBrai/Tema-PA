#include "echipe.h"
void read_team(Team **top, FILE *f)
{
    Team *aux = malloc(sizeof(Team));
    Player *list_of_players = NULL;
    char buffer1[50], buffer2[50];
    int no_of_members, member_points;
    fscanf(f, "%d", &no_of_members);
    fgetc(f);
    fgets(buffer1, 49, f);
    aux->nr_players = no_of_members;
    aux->name_team = calloc((strlen(buffer1)) + 1, sizeof(char));
    strncpy(aux->name_team, buffer1, strlen(buffer1));
    aux->name_team[strlen(aux->name_team) - 1] = '\0';
    for (int i = 0; i < no_of_members; i++)
    {
        fscanf(f, "%s %s %d", buffer1, buffer2, &member_points);
        Player *p = malloc(sizeof(Player));
        p->firstName = malloc((strlen(buffer1) + 1) * sizeof(char));
        strcpy(p->firstName, buffer1);
        p->secondName = malloc((strlen(buffer2) + 1) * sizeof(char));
        strcpy(p->secondName, buffer2);
        p->points = member_points;
        p->next = NULL;
        if (list_of_players == NULL)
        {
            list_of_players = p;
        }
        else
        {
            p->next = list_of_players;
            list_of_players = p;
        }
    }
    aux->first_member = list_of_players;
    aux->next_team = NULL;
    if ((*top) == NULL)
    {
        (*top) = aux;
    }
    else
    {
        aux->next_team = (*top);
        (*top) = aux;
    }
}

void score_calculator(Team *top)
{
    Team *aux1;
    Player *aux2;
    for (aux1 = top; aux1 != NULL; aux1 = aux1->next_team)
    {
        aux1->punctaj_echipa = 0;
        for (aux2 = aux1->first_member; aux2 != NULL; aux2 = aux2->next)
        {
            aux1->punctaj_echipa += aux2->points;
        }
        aux1->punctaj_echipa = (aux1->punctaj_echipa) / aux1->nr_players;
    }
}

void team_removal(Team **top)
{
    float min = (*top)->punctaj_echipa;
    for (Team *aux = (*top)->next_team; aux != NULL; aux = aux->next_team)
    {
        if (aux->punctaj_echipa < min)
        {
            min = aux->punctaj_echipa;
        }
    }
    for (Team *aux = (*top); aux->next_team != NULL; aux = aux->next_team)
    {
        if (aux == (*top) && aux->punctaj_echipa == min)
        {
            (*top) = (*top)->next_team;
            break;
        }
        else if (aux->next_team->punctaj_echipa == min)
        {
            aux->next_team = aux->next_team->next_team;
            break;
        }
    }
}