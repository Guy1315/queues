#ifndef q_h
#define q_h
typedef int general_info;

typedef struct q_node_type{
    general_info data;
    struct q_node_type *next;
}*q_node_ptr;

typedef struct q_type{
    q_node_ptr front;
    q_node_ptr rear;
}queue;

void queue_init(queue *q);
void queue_in(queue *q,general_info evar);
general_info queue_out(queue *q);
general_info queue_top(queue *q);
int is_empty_q(queue q);
#endif // q


