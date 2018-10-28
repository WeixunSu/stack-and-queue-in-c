#include <stdio.h>

struct LinkedNode{
	struct LinkedNode* next;
	int value;
};

struct stack{
	struct LinkedNode* top;
};

struct queue{
	struct LinkedNode* head;
	struct LinkedNode* tail;
};

// get item(int) at the top and remove it
int stackPop(struct stack* s){
	struct LinkedNode* temp = s->top->next;
	int value = s->top->value;
	s->top = temp;
	return value;
}

// add an item(int) at the top
void stackPush(struct stack* s, struct LinkedNode* n){
	struct LinkedNode* temp = s->top;
	s->top = n;
	s->top->next = temp;
}

// Get item(int) at the top without removing it
int stackPeek(struct stack* s){
	return s->top->value;
}

int stackIsEmpty(struct stack* s){
	if (s->top == NULL) return 1;
	return 0;
}

int queueIsEmpty(struct queue* q){
	if (q->head == NULL) return 1;
	return 0;
}

void queueAdd(struct queue* q, struct LinkedNode* n){
	if (queueIsEmpty(q)){
		q->tail = n;
		q->head = n;
		q->tail->next = NULL;
		return;
	}
	struct LinkedNode* temp = q->tail;
	q->tail = n;
	q->tail->next = NULL;
	temp->next = q->tail;
}

int queuePoll(struct queue* q){
	int value = q->head->value;
	struct LinkedNode* temp = q->head->next;
	q->head = temp;
	return value;
}

int main(){
	struct LinkedNode one = {.next = NULL, .value = 1};
	struct LinkedNode two = {.next = NULL, .value = 2};

	// stack example
	struct stack s = {.top = NULL};
	stackPush(&s, &one);
	stackPush(&s, &two);
	printf("Pop stack: %d\n", stackPop(&s));
	printf("Is stack empty yet? Yes(1), No(0) \t%d\n", stackIsEmpty(&s));
	printf("Peek stack: %d\n", stackPeek(&s));
	printf("Is stack empty yet? Yes(1), No(0) \t%d\n", stackIsEmpty(&s));
	printf("Pop stack: %d\n", stackPop(&s));
	printf("Is stack empty yet? Yes(1), No(0) \t%d\n", stackIsEmpty(&s));


	// queue example
	struct queue q = {.head = NULL, .tail = NULL};
	queueAdd(&q, &one);
	queueAdd(&q, &two);
	printf("Poll queue: %d\n", queuePoll(&q));
	printf("Is queue empty yet? Yes(1), No(0) \t%d\n", queueIsEmpty(&q));
	printf("Poll queue: %d\n", queuePoll(&q));
	printf("Is queue empty yet? Yes(1), No(0) \t%d\n", queueIsEmpty(&q));

	return 0;
}

