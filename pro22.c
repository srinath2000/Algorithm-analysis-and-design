//binary search
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble(int *,int);
clock_t t1,t2;

void bin(int a[300000],int n,int s)
{ int i,f=0,l=0,u=n-1,m;
  while(l<=u)
  { m=(l+u)/2;
    if(a[m]==s)
    { printf("The search element is found\ns");
      f=1;
      break;
    }
    else if(a[m]<s)
     l=m+1;
    else
     u=m-1;
  }
  if(f==0)
   printf("the searched element is  not found\n");
}

void main()
{ int i,a[300000],n,s,ch;
  double m1;
  do{
  printf(" Enter the limit  : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   a[i]=rand();
  //for(i=0;i<n;i++)
 // printf("%d \t",a[i]);
  printf("Enter the element to be searched  : ");
  scanf("%d",&s);
  bubble(a,n);
  t1=clock();
  bin(a,n,s);
  t2=clock();
  m1=(t2-t1)/(double)CLOCKS_PER_SEC;
  printf("Time: %f\n",m1);
  FILE *fp;
  fp=fopen("bin.dat","a");
  fprintf(fp,"%d",n);
  fprintf(fp,"%f",m1);
  fprintf(fp,"\n");
  printf("\nDo you want to exit(1/0): ");
  scanf("%d",&ch);
  if(ch==1)
   exit(0);
  }while(1);
}

void bubble(int a[300000],int n)
{ int i,j,s;
  for(i=1;i<n;i++)
   for(j=1;j<n;j++)
    if(a[j]>a[j+1])
    { s=a[j];
      a[j]=a[j+1];
      a[j+1]=s;
    }
}
