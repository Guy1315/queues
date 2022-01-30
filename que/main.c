#include <stdio.h>
#include <stdlib.h>
#include "que.h"

queue build_queue();
void print_queue(queue q);
int remove_element(queue q,general_info ele);
void reverse_queue(queue *q);

void main()
{
    queue q;
    queue_init(&q);
    q=build_queue();
    print_queue(q);
    remove_element(q,3);
    reverse_queue(&q);
    print_queue(q);

}

queue build_queue()
{
    general_info item;
    queue q;
    queue_init(&q);
    scanf("%d",&item);
    while (item!=-1)
    {
        queue_in(&q,item);
        scanf("%d",&item);
    }
    return q;
}

void print_queue(queue q)
{
    general_info item;
    queue p;
    queue_init(&p);
    while (!is_empty_q(q))
    {
        item=queue_out(&q);
        printf("item = %d \n",item);
        queue_in(&p,item);
    }
    while (!is_empty_q(p))
    {
        item=queue_out(&p);
        queue_in(&q,item);
    }
}

int remove_element(queue q,general_info ele)
{
    int check=0;
    general_info item;
    queue p;
    queue_init(&p);
    while (!is_empty_q(q))
    {
        item=queue_out(&q);
        if(check==0&&item==ele)
        {
            printf("the element exists \n");
            check=1;
        }
        else
            queue_in(&p,item);
    }
    while(!is_empty_q(p))
    {
        item=queue_out(&p);
        queue_in(&q,item);
    }
    print_queue(q);
    return check;
}

void reverse_queue(queue *q)
{
    int keep;
    if(is_empty_q(*q))
      return;
    keep = queue_out(&q);
    reverse_queue(&q);
    queue_in(&q,keep);
}
