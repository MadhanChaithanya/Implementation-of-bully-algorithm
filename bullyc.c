#include<stdio.h>

typedef struct process
{
   int id;
   int crash;
}process;
process P[10];

int total,coordinator;

int highest()
{
   int max=0,i,loc;
 
  for(i=1;i<=total;i++)
  {
     if(P[i].id>max)
     {
       if(P[i].crash==0)
       {
        max=P[i].id;
        loc=i;
       }  
     }
  }
  return(loc);
}

void election(int newco)
{
 int i,j,new;
  int total1=0;
 for(j=1;j<=total;j++)
  if(P[j].crash!=1)
            total1++;
        while(newco<=total1)
 {  
  for(i=newco+1;i<=total;i++)
     if(P[newco].id< P[i].id)
        printf("\n  Election message sent to Process %d by process %d \n",i,newco);
    printf("\n");
    for(i=newco+1;i<=total;i++)
     if(P[i].crash==0 && P[newco].id< P[i].id )
         printf("\n  OK message received from Process %d \n",i);
   else if(P[i].crash=1 && P[newco].id< P[i].id)
             printf("\n  Process %d is not responding.. \n",i);
             newco=newco+1;
    if(newco<=total1)
               printf("\n  process %d is taking over.. \n",newco);
  }
 coordinator=newco-1;
   printf("\n New elected coordinator is Process %d",coordinator);  
}

void Crash()
{
 int no,i,newco;
 printf("\n  Enter the Process Number of the Process to be crashed:  \n");
    scanf("%d",&no);
 P[no].crash=1;
    printf("\n  Process %d has crashed.. ",no); 
  for(i=1;i<=total;i++)
   {
    if(P[i].crash==0)
       printf("\n Process %d is active \n",i);
     else 
       printf("\n Process %d is Inactive \n",i); 
   }
   if(no==coordinator)
     { 
        printf("\n  Enter a process number which should start the election: ");
        scanf("%d",&newco);
   election(newco);
   }
}

void Recover()
{
   int rec;
    printf("\n Enter the Process number of the process to be recovered: ");
     scanf("%d",&rec);
   P[rec].crash=0;
    election(rec);
}

void Bully()
{
 int op;
 coordinator=highest(); 
 printf("\n  Process %d is the Coordinator...",coordinator);
 do{  
  printf("\nn 1.Crash \n 2.Recover \n 3.Exit ");
        printf("\n Enter your choice: ");
        scanf("%d",&op);
       switch(op)
      {
         case 1: Crash();
               break;
   case 2: Recover();
             break;
   case 3: 
             break; 
      }
    }while(op!=3);
}


void main()
{
 
   int i,id;
 int ch;
 printf("\n Enter Number of Processes: ");
 scanf("%d",&total);
  printf("\nEnter the id for the processes from low priority to high priorityn");
    for(i=1;i<=total;i++)
   {  
       printf("\n Enter id for Process %d: ",i);
       scanf("%d",&id);
       P[i].id=id;
       P[i].crash=0;
   }
  Bully();
 
}
