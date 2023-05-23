#include "stive&cozi.h"
int top(Team *top)
{
    if (isEmpty(top))
        return INT_MIN;
    return top->punctaj_echipa;
}

void push(Team **top,Team *current)
{	
	Team*node=malloc(sizeof(Team));
	//node->first_member=current->first_member;
	node->name_team = malloc((strlen(current->name_team)+1) * sizeof(char));
	strcpy(node->name_team,current->name_team);
	node->nr_players=current->nr_players;
	node->next_team=NULL;
	node->punctaj_echipa=current->punctaj_echipa;
    node->next_team=(*top);
	(*top)=node;
}

int pop(Team **top)
{
    if (isEmpty(*top))
        return INT_MIN;
    Team *temp = (*top);
    int aux = temp->punctaj_echipa;
    *top = (*top)->next_team;
    free(temp);
    return aux;
}

int isEmpty(Team *top)
{
    return top == NULL;
}

void deleteStack(Team **top)
{
    Team *temp;
    while (!isEmpty(*top))
        temp = *top;
    *top = (*top)->next_team;
    free(temp);
}
Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

 void enQueue(Queue*q, Team *top){
	Team* newNode=(Team*)malloc(sizeof(Team));
    newNode->nr_players=top->nr_players;
    newNode->name_team=malloc((strlen((top)->name_team)+1)* sizeof(char));
	strcpy(newNode->name_team,top->name_team);
	//newNode->first_member =top->first_member;
	newNode->punctaj_echipa =top->punctaj_echipa;
	newNode->next_team=NULL;
	if (q->rear==NULL) q->rear=newNode; 
	else{
		(q->rear)->next_team=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear; 
}
 
int deQueue(Queue*q) {  
	Team* aux; int d;
	if (isEmptyq(q)) return INT_MIN;
	
	aux=q->front; 
	d=aux->punctaj_echipa;
	q->front=(q->front)->next_team;
	free(aux);
	return d;  	
} 

int isEmptyq(Queue*q){
	return (q->front==NULL);
}

void deleteQueue(Queue*q){
	Team* aux;
	while (!isEmptyq(q)){
		aux=q->front;
		q->front=q->front->next_team;
		free(aux);
	}
	free(q);
}