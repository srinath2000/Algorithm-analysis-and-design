//Linear search
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t t1,t2;

void lin(int a[30000],int n,int s)
{ int i,f=0;
  for(i=0;i<n;i++)
   if(a[i]==s)
   { f=1;
     printf("\nThe searched element is found  ");
   }
  if(f==0)
   printf("\nThe searched element is not found\n");
}

void main()
{ int i,a[30000],n,s,ch;
  double m1;
  do{
  printf("\nEnter the limit : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   a[i]=rand();
 
  printf("\nEnter the searched element : ");
  scanf("%d",&s);
  t1=clock();
  lin(a,n,s);
  t2=clock();
  m1=(t2-t1)/(double)CLOCKS_PER_SEC;
  printf("Time: %f\n",m1);
  FILE *fp;
  fp=fopen("lin.dat","a");
  fprintf(fp,"%d",n);
  fprintf(fp,"%f",m1);
  fprintf(fp,"\n");
  printf("\nDo you want to exit  (1/0) : ");
  scanf("%d",&ch);
  if(ch==1)
   exit(0);
  }while(1);
}














