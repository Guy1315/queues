#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "que.h"

void queue_init(queue* q)
{
    q->rear=NULL;
    q->front=NULL;
}

void queue_in(queue* q, general_info evar)
{
    q_node_ptr p;
    p = (q_node_ptr)malloc(sizeof(struct q_node_type));
    assert (p != NULL);
    p->data = evar;
    p->next = NULL;
    if (q->front == NULL)
        q->front=p;
    else
        q->rear->next=p;
    q->rear=p;
}

general_info queue_out(queue* q)
{
    general_info val;
    q_node_ptr p;
    p=(q_node_ptr)malloc(sizeof(struct q_node_type));
    assert(p!=NULL);
    p=q->front;
    val=q->front->data;
    q->front=q->front->next;
    if(q->front == NULL)
        q->rear=NULL;
    free(p);
    return val;
}

general_info queue_top(queue* q)
{

    return q->front->data;
}

int is_empty_q(queue q)
{
    return(q.front==NULL);
}

