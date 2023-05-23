#include "arbori.h"
int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[2], "rt");
    if (f == NULL)
    {
        printf("could not open file");
    }
    Team *list_team = NULL;
    Team *winners_point4 = NULL;
    Tree *list_avl_front = NULL;
    Tree *list_avl_rear = NULL;
    int no_of_teams;
    fscanf(f, "%d", &no_of_teams);
    for (int i = 0; i < no_of_teams; i++)
    {
        read_team(&list_team, f);
    }
    fclose(f);
    FILE *c = fopen(argv[1], "rt");
    int cerinte[5];
    for (int i = 0; i < 5; i++)
    {
        fscanf(c, "%d", &cerinte[i]);
    }
    fclose(c);
    if (cerinte[0] == 1)
    {
        f = fopen(argv[3], "wt");
        if (f == NULL)
        {
            printf("could not open file");
        }
        for (Team *aux = list_team; aux != NULL; aux = aux->next_team)
        {
            fprintf(f, "%s\n", aux->name_team);
        }
        score_calculator(list_team);
        fclose(f);
    }
    if (cerinte[1] == 1)
    {
        f = fopen(argv[3], "wt");
        int l = 1;
        while (l * 2 <= no_of_teams)
        {
            l = l * 2;
        }
        for (int i = 0; i < (no_of_teams - l); i++)
        {
            team_removal(&list_team);
        }
        for (Team *aux = list_team; aux != NULL; aux = aux->next_team)
        {
            aux->name_team[strlen(aux->name_team) - 1] = '\0';
            if (aux->name_team[strlen(aux->name_team) - 1] == 32)
                strcpy(aux->name_team + strlen(aux->name_team) - 1, aux->name_team + strlen(aux->name_team));
            fprintf(f, "%s\n", aux->name_team);
        }
        fclose(f);
    }
    if (cerinte[2] == 1)
    {
        f = fopen(argv[3], "at");
        if (f == NULL)
        {
            printf("nu se deschide");
        }
        Queue *q = createQueue();
        Team *stack_winners = NULL;
        Team *stack_losers = NULL;
        Team *aux = list_team;
        aux = list_team;
        int l = 0, round = 1;
        while (aux != NULL)
        {
            enQueue(q, aux);
            aux = aux->next_team;
            l += 1;
        }
        for (int k = 1; k < l; k = k * 2)
        {
            fprintf(f, "\n--- ROUND NO:%d\n", round);
            while (q->front != NULL)
            {
                fprintf(f, "%s", q->front->name_team);
                for (int o = 0; o < 33 - strlen(q->front->name_team); o++)
                {
                    fprintf(f, " ");
                }
                fprintf(f, "-");
                for (int o = 0; o < 33 - strlen(q->front->next_team->name_team); o++)
                {
                    fprintf(f, " ");
                }
                fprintf(f, "%s\n", q->front->next_team->name_team);
                if (q->front->punctaj_echipa > q->front->next_team->punctaj_echipa)
                {
                    push(&stack_winners, (q->front));
                    deQueue(q);
                    stack_winners->punctaj_echipa += 1;
                    push(&stack_losers, (q->front));
                    deQueue(q);
                }
                else
                {
                    push(&stack_losers, (q->front));
                    deQueue(q);
                    push(&stack_winners, (q->front));
                    stack_winners->punctaj_echipa += 1;
                    deQueue(q);
                }
            }
            int counter = 0;
            aux = stack_winners;
            while (aux != NULL)
            {
                counter += 1;
                aux = aux->next_team;
            }
            if (counter == 8)
            {
                aux = stack_winners;
                while (aux != NULL)
                {
                    push(&winners_point4, aux);
                    aux = aux->next_team;
                }
            }
            Team *display_winners = stack_winners;
            fprintf(f, "\nWINNERS OF ROUND NO:%d\n", round);
            round += 1;
            while (display_winners != NULL)
            {
                fprintf(f, "%s", display_winners->name_team);
                for (int o = 0; o <= 33 - strlen(display_winners->name_team); o++)
                {
                    fprintf(f, " ");
                }
                fprintf(f, "-  %.2f\n", display_winners->punctaj_echipa);
                display_winners = display_winners->next_team;
            }
            aux = stack_winners;
            while (aux != NULL)
            {
                enQueue(q, aux);
                aux = aux->next_team;
            }
            while (!isEmpty(stack_winners))
            {
                pop(&stack_winners);
            }
            while (!isEmpty(stack_losers))
            {
                pop(&stack_losers);
            }
        }
        fclose(f);
    }
    if (cerinte[3] == 1)
    {
        f = fopen(argv[3], "at");
        Team *aux = winners_point4;
        Tree *BST = NULL;
        for (int g = 0; g < 8; g++)
        {
            BST = AddToTree(BST, aux->punctaj_echipa, aux->name_team);
            aux = aux->next_team;
        }
        fprintf(f, "\nTOP 8 TEAMS:\n");
        displayBST(BST, f, &list_avl_front, &list_avl_rear);
        fclose(f);
    }
    if (cerinte[4] == 1)
    {
        f = fopen(argv[3], "at"); // i love you <3
        AVL *a = NULL;
        for(int i = 0 ; i < 8 ; i++)
        {
            a = insert_avl(a, list_avl_front);
            list_avl_front = list_avl_front->right;
        }
        fprintf(f, "\nTHE LEVEL 2 TEAMS ARE:\n");
        for(int i =1 ; i< 8 ; i+=2)
        printlevel(a, i, f);
        fclose(f);
    }
    return 0;
}