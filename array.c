//program with array (for comparing its time complexity with linked list)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t t1,t2;

void main()
{ int a[100000],n,i,m,lar,ch,r; 
  printf("\nenter the limit : ");
  scanf("%d",&ch);
  for(i=0;i<ch;i++)
  { r=rand();
    a[i]=r;
  }
  t1=clock();
  printf("\nposition : ");
  scanf("%d",&i);
  m=--i;
  for(;i<ch-1;i++)
   a[i]=a[i+1];
  
  
  lar=a[m++];
  for(;m<n-1;m++)
   if(a[m]>lar)
    lar=a[m];
  printf("  the next  Largest element is  : %d\n",lar);
  t2=clock();
  double m1;
  m1=(t2-t1)/(double)CLOCKS_PER_SEC;
  printf("Time taken is  : %f\n",m1);
}
