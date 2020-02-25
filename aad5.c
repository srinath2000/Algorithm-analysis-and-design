#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t t1,t2,t3,t4,t5,t6,t7,t8;
void insert(int,int*,int);
void fbub(int,double);
void fins(int,double);
void fsel(int,double);
void fq(int,double);

void bubble(int a[10],int n)
{ int i,j,s;
  for(i=1;i<n;i++)
   for(j=1;j<n;j++)
    if(a[j]>a[j+1])
    { s=a[j];
      a[j]=a[j+1];
      a[j+1]=s;
    }
}


void insertion(int a[10],int n)
{ int j;
  for(j=2;j<n+1;j++)
   insert(a[j],a,j-1);
}


void selection(int a[10],int n)
{ int i,j,s;
  for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
    if(a[i]>a[j])
    { s=a[i];
      a[i]=a[j];
      a[j]=s;
    }
} 


void quick(int a[10],int low,int high)
{ int s;
  if(low<high)
  { int i,j,k;
    i=low;
    j=high+1;
    k=low;
    do{
     do{ i++; }while((a[i]<=a[k])&&(i<=high));
     do{ j--; }while((a[j]>a[k])&&(j>=low));   
     if(i<j)
     { s=a[j];
       a[j]=a[i];
       a[i]=s;
     }
    }while(i<j);
    s=a[j];
    a[j]=a[k];
    a[k]=s;
    quick(a,low,j-1);
    quick(a,j+1,high);
  }
}


void display(int a[10],int n)
{ printf("Array: ");
  for(int i=1;i<=n;i++)
   printf("%d ",a[i]);
  printf("\n");
}


void main()
{ int ch,n,a[400000],i;
  double m1,m2,m3,m4;
  do{
  printf(" \n***********menu***********\n1. Bubbble sort\n2. Insertion sort\n3. Selection sort\n4. Quick sort\n5. Exit\n");
  printf("Enter Your Choice  : ");
  scanf("%d",&ch);
  switch(ch)
  { case 1:
    printf("Enter the limit  : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     a[i]=rand();
    t1=clock();
    bubble(a,n);
    t2=clock();
    
    m1=(t2-t1)/(double)CLOCKS_PER_SEC;
    printf("Time taken for bubble: %f\n",m1);
    fbub(n,m1);
    break;
    case 2:
    printf("Enter the limit : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     a[i]=rand();
    t3=clock();
    insertion(a,n);
    t4=clock();
    
    m2=(t4-t3)/(double)CLOCKS_PER_SEC;
    printf("Time taken for insertion: %f\n",m2);
    fins(n,m2);
    break;
    case 3:
    printf("Enter the limit : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     a[i]=rand();
    t5=clock();
    selection(a,n);
    t6=clock();
    
    m3=(t6-t5)/(double)CLOCKS_PER_SEC;
    printf("Time taken selection: %f\n",m3);
fsel(n,m3);
    break;
    case 4:
    printf("Enter the limit :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     a[i]=rand();
    t7=clock();
    quick(a,1,n);
    t8=clock();
    
    m4=(t8-t7)/(double)CLOCKS_PER_SEC;
    printf("Time taken quick: %f\n",m4);
fq(n,m4);
    break;
    case 5:
     exit(0);
  }
  }while(1);
}

void fbub(int n,double m)
{ FILE *fp;
  fp=fopen("bub.dat","a");
  fprintf(fp,"%d",n);
  fprintf(fp," ");
  fprintf(fp,"%f",m);
  fprintf(fp,"\n"); 
  fclose(fp);
}

void fins(int n,double m)
{ FILE *fp;
  fp=fopen("ins.dat","a");
  fprintf(fp,"%d",n);
  fprintf(fp," ");
  fprintf(fp,"%f",m);
  fprintf(fp,"\n"); 
  fclose(fp);
}

void fsel(int n,double m)
{ FILE *fp;
  fp=fopen("sel.dat","a");
  fprintf(fp,"%d",n);
  fprintf(fp," ");
  fprintf(fp,"%f",m);
  fprintf(fp,"\n"); 
  fclose(fp);
}

void fq(int n,double m)
{ FILE *fp;
  fp=fopen("q.dat","a");
  fprintf(fp,"%d",n);
  fprintf(fp," ");
  fprintf(fp,"%f",m);
  fprintf(fp,"\n"); 
  fclose(fp);
}

void insert(int e,int a[],int i)
{ a[0]=e;
  while(e<a[i])
  { a[i+1]=a[i];
    i--;
  }
  a[i+1]=e;
}
