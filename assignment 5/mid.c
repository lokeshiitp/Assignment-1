#include<stdio.h>
int checkSorted(int *X,int sX);


//combine function 
void combine(int *p, int *q, int a, int b){
    int i,j,k,t;       
    int x=a+b;
    int z[x];      
    for (i=0;i<a;i++){         
        z[i]=p[i];
    }
    for(i=0, j=a; j<x && i<b; i++, j++){
        z[j]=q[i];
    }

    

    for(i=0; i<x; i++){              
        for(j=i+1; j<x; j++){
            if(z[i] == z[j]){
                for(int k=j; k < x - 1; k++){
                    z[k] = z[k + 1];
                }
                x--;
                j--;
            }
        }
    }

    for(i=0;i<x;i++){           
        for(int j=i+1;j<x;j++){
            if (z[i]>z[j]){
                t=z[i];
                z[i]=z[j];
                z[j]=t;
            }
        }
    }

    for (int i=0; i<x;i++){           // final array
        printf("\n%d",z[i]);

    }

}





int main(){
    int a,b;
    printf("size for array A\n");     
    scanf("%d",&a);
    printf("size for array B\n");
    scanf("%d",&b);
    int p[a];
    int q[b];
    valid:
    printf("\nenter elements of b\n");    
    for(int i=0;i<a;i++){
        scanf("%d",&p[i]);
    }
    
    printf("\nenter elements of a\n");
    for(int i=0;i<b;i++){
        scanf("%d",&q[i]);
    }
    int x=checkSorted(p,a);
    int y=checkSorted(q,b);
    if(x==0){      //called check sorted funtion 
        printf("\na is not sorted");
        goto valid;
    }
    
    if(y==0){      
        printf("\nB ia not sorted");
        goto valid;
    }
    
    
    else{
        printf("\nthe final array is\n");
        combine( p ,q ,a,b);     
    }
}

int checkSorted(int *X, int sX)
{
    
    if (sX == 1 || sX == 0){
        return 1;
    }
    
    if (X[sX - 1] <= X[sX - 2]){
        return 0;
    }
    
    return checkSorted(X, sX - 1);
}