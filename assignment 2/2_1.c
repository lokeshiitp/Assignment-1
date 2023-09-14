#include<stdio.h>
int main(){
    int option,marks;
    do {printf("choose any one option \n");
     printf("1.choose 1 to enter marks \n");
     printf("2.choose 2 to exit \n");
      scanf("%d",&option);
      if(option ==1){
          printf("enter marks \n");
      scanf("%d",&marks);
       switch(marks){
           case 91 ... 100 :
           printf("AA \n");
           break;
           case 81 ... 90 :
           printf("AB \n");
           break;
           case 71 ... 80 :
           printf("BB \n");
           break;
           case 61 ... 70 :
           printf("BC \n");
           break;
           case 51 ... 60 :
           printf("CC \n");
           break;
           case 41 ... 50 :
           printf("CD \n");
           break;
           case 31 ... 40 :
           printf("DD \n");
           break;
           case 0 ... 30 :
           printf("F \n");
           break;
           default :
           printf("error:invalid input \n");
       }
      }
      else{
          printf("program is terminated \n");
      }
    }while(option!=2);
    return 0;
}