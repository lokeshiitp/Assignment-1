#include <stdio.h>
void ComputeTerm(int n)
{
    if(n<=0)
      {
          printf("Wrong Input");
      }
    else
    {                               // for 1,2,3 value also 1,2,3
        if(n==1)
         printf("1");
        else if(n==2)
         printf("2");
        else if(n==3)
         printf("3");
        else
        {
            int seclast=2,thirdlast=1,last=3;
            for(int i=4;i<=n;i++)                //for n>3 
            {
                int ans = seclast + 2*thirdlast;
                if(i==n)
                    printf("%d",ans);
                else
                {
                    thirdlast=seclast;
                    seclast=last;
                    last=ans;
                }


            }
        }

    }
}
int main()
{
  int n;
  scanf("%d",&n);
  ComputeTerm(n);

    return 0;
}