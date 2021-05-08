#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char name[10];
    int garde[3];
    int rank;
    float average;
    struct student *next;
}STU;

int main()
{
    STU *obj,*_obj,*pz_stu;
    STU *mp,*p,*mq,*q;
    int temp=0,i;
    int stu_count;
    float sum=0;

    scanf("%d",&stu_count);
    obj=(STU*)malloc(sizeof(STU));
    obj->next=NULL;
    while(temp<stu_count)
    {
        pz_stu=(STU*)malloc(sizeof(STU));
        pz_stu->rank=0;
        sum=0;
        scanf("%s",pz_stu->name);
        for(i=0;i<3;i++)
        {
            scanf("%d",&pz_stu->garde[i]);
            if(pz_stu->garde[i]<60)
            {
                pz_stu->rank=1;
            }
            sum+=pz_stu->garde[i];
        }
        pz_stu->average=sum/3;

        pz_stu->next=obj->next;
        obj->next=pz_stu;
        temp++;
    }

    while(pz_stu!=NULL)
    {
        if(pz_stu->rank==1)
        {
            printf("*name:%s score:%d %d %d\n",pz_stu->name,
                   pz_stu->garde[0],
                   pz_stu->garde[1],
                   pz_stu->garde[2]);
        }
        pz_stu=pz_stu->next;
    }

    _obj=(STU*)malloc(sizeof(STU));
    _obj->next=NULL;

    while(obj->next!=NULL)
    {
        mp=mq=obj;
        p=q=obj->next;
        while(q!=NULL)
        {
            if(p->average>=q->average)
            {
                mp=mq;
                p=q;
            }
            mq=mq->next;
            q=q->next;
        }
        mp->next=p->next;
        p->next=_obj->next;
        _obj->next=p;
    }

    pz_stu=_obj->next;
    temp=1;

    while(pz_stu!=NULL)
    {
        printf("[%d] name:%s %d %d %d\n",temp,
               pz_stu->name,
               pz_stu->garde[0],
               pz_stu->garde[1],
               pz_stu->garde[2]);
        pz_stu=pz_stu->next;
        temp++;
    }
}
