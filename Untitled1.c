#include<stdio.h>
#include<stdlib.h>
#define MAXDEQUEUE 20

typedef int DeQueueEntryType;
typedef enum{FALSE, TRUE} Boolean;

typedef struct dequeue{
    int count;
    int front;
    int rear;
    DeQueueEntryType item[MAXDEQUEUE];
}DeQueue;

void CreateDeQueue(DeQueue *dq){
    dq->count=0;
    dq->front=dq->rear=-1;
}

Boolean IsDeQueueFull(DeQueue *dq){
    return ((dq->front==0 && dq->rear==MAXDEQUEUE-1) || dq->front==dq->rear+1);
}

Boolean IsDeQueueEmpty(DeQueue *dq){
    return (dq->front==-1);
}

void InsertRear(DeQueueEntryType x, DeQueue *dq){
    if(IsDeQueueFull(dq)){
        printf("Dequeue is Full, So you can't insert Data!\n\n");
        exit(1);
    }else{
        if(IsDeQueueEmpty(dq)){
            dq->front=dq->rear=0;
        }else if(dq->rear==MAXDEQUEUE-1){
            dq->rear=0;
        }else{
            dq->rear++;
        }
        dq->item[dq->rear]=x;
    }
}

void InsertFront(DeQueueEntryType x, DeQueue *dq){
    if(IsDeQueueFull(dq)){
        printf("DeQueue is Full, So you can't insert Data!\n\n");
        exit(1);
    }else{
        if(IsDeQueueEmpty(dq)){
            dq->front=dq->rear=0;
        }else if(dq->front==0){
            dq->front=MAXDEQUEUE-1;
        }else{
            dq->front--;
        }
        dq->item[dq->front]=x;
    }
}

void RemoveRear(DeQueueEntryType *x, DeQueue *dq){
    if(IsDeQueueEmpty(dq)){
        printf("The DeQue is Empty, So you can't Remove\n\n");
        exit(1);
    }else{
        *x=dq->item[dq->rear];
        if(dq->rear==dq->front){
            dq->rear=dq->front=-1;
        }else if(dq->rear==0){
            dq->rear=MAXDEQUEUE-1;
        }else{
            dq->rear--;
        }
    }
}

void RemoveFront(DeQueueEntryType *x, DeQueue *dq){
    if(IsDeQueueEmpty(dq)){
        printf("The DeQue is Empty, So you can't Remove\n\n");
        exit(1);
    }else{
        if(dq->rear==dq->front){
            dq->front=dq->rear=-1;
        }else if(dq->front==MAXDEQUEUE-1){
            dq->front=0;
        }else{
            dq->front++;
        }
    }
}

void DisplayDeQueue(DeQueue *dq){
    if(IsDeQueueEmpty(dq)){
        printf("This is an Empty DeQueue");
        exit(1);
    }
    int front_pos = dq->front;
    int rear_pos = dq->rear;

    printf("\nQueue Elements : \n\n");

    if(front_pos <= rear_pos){
        while(front_pos <= rear_pos){
            printf("%d\n",dq->item[front_pos++]);
        }
    }else{
        while(front_pos<=MAXDEQUEUE){
            printf("%d\n",dq->item[front_pos++]);
        }
        front_pos=0;
        while(front_pos<=rear_pos){
            printf("%d\n",dq->item[front_pos++]);
        }
    }
}

int main(){

    DeQueue dq;
    int num=0;

    do{
        printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)\n6.Print\n7.Exit\n\nEnter your choice : ");
        scanf("%d",&num);

        switch(num){
        case 1:{
            int no_ele = 0, element = 0;
            CreateDeQueue(&dq);
            printf("\nEnter number of elements : ");
            scanf("%d",&no_ele);

            for(int i=0;i<no_ele;i++){
                scanf("%d",&element);
                InsertRear(element, &dq);
            }
        }
        break;
        case 2:{
            int element=0;
            printf("\nEnter element to be inserted : ");
            scanf("%d",&element);
            InsertRear(element, &dq);
        }
        break;
        case 3:{
            int element=0;
            printf("\nEnter element to be inserted : ");
            scanf("%d",&element);
            InsertFront(element, &dq);
        }
        break;
        case 4:{
            int x;
            RemoveRear(&x, &dq);
        }
        break;
        case 5:{
            int x;
            RemoveFront(&x, &dq);
        }
        break;
        case 6:{
            DisplayDeQueue(&dq);
        }
        break;
    }
    }while(num!=7);

 return 0;
}

