//program with linked list(to compare its time complexity with an array)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t t1,t2;
struct node
{ int d;
  struct node *next; };

void main()
{ int ch,it,k,n,i=1;
  struct node *h,*temp,*l,*b,*p,*lar;
  h=NULL;
printf("enter the limit :");
scanf("%d",&k);
  do{
    temp=(struct node *)malloc(sizeof(struct node));
    temp->d=rand();
    temp->next=NULL;
    if(h==NULL)
    { h=temp;
      l=temp;
    }
    else
    { l->next=temp;
      l=temp;
    }
    i++;
  }while(i<1000);
 

  t1=clock();
  printf("position :");
  scanf("%d",&n);
  if(h->d==n)
  { temp=h;
    h=h->next;
    free(temp);
  } 

  l=h;
  for(i=0;i<k;i++)
  { if(i==n)
    { b->next=l->next;
      lar=l->next;
      it=l->next->d;
      free(l);
    }
    else
    { b=l;
      l=l->next;
    }
  }
 
  while(lar!=NULL)
  { if(lar->d>it)
     it=lar->d;
    lar=lar->next;
  }
  printf("   the next Largest element is  : %d",it);
  t2=clock();
  double m1;
  m1=(t2-t1)/(double)CLOCKS_PER_SEC;
  printf("\nTime taken is  : %f\n",m1);
}
  
  






