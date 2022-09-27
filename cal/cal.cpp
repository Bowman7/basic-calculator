#include "cal.h"
#include<iostream>
#include<stdio.h>

struct box
{
	float val;
	struct box *next;
};

struct box *head=NULL;
void insert(int var)
{
	struct box *tmp=new box;
        tmp->val=var;
	tmp->next=NULL;
	if(head==NULL)
	{
		head =tmp;
	}
	else
	{
		tmp->next=head;
		head=tmp;
	}
}

void display()
{
	struct box *p;
	p=head;
	while(p!=NULL)
	{
		printf(" %f ",p->val);
		p=p->next;
	}
}
