 // program for COMBINED ARRAYC
 #include <stdio.h>
    void main()
    {
 
        int arrayA[50], arrayB[50], arrayC[100], m, n, i, j, k = 0;
        printf("\n Enter size of array Array A: ");
        scanf("%d", &m);
 
        printf("\n Enter sorted elements of array A: \n");
        for (i = 0; i < m; i++) 
        {
            scanf("%d", &arrayA[i]);   // enter arrayA
        }
 
        printf("\n Enter size of array B: ");
        scanf("%d", &n);
 
        printf("\n Enter sorted elements of array B: \n");
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &arrayB[i]);     // enter arrayB
        }
 
        i = 0;
        j = 0;
 
        while (i < m && j < n) 
        {
            if (arrayA[i] < arrayB[j]) 
            {
                arrayC[k] = arrayA[i];
                i++;
            }
 
            else 
            {
                arrayC[k] = arrayB[j];
                j++;
            }
            k++;
        }
 
        if (i >= m) 
        {
            while (j < n) 
            {
                arrayC[k] = arrayB[j];
                j++;
                k++;
            }
        }
 
        if (j >= n) 
        {
            while (i < m)
            {
                arrayC[k] = arrayA[i];
                i++;
                k++;
            }
        }
 
        printf("\n After merging: \n");
        for (i = 0; i < m + n; i++) 
        {
            printf("\n%d", arrayC[i]);     //FINAL arrayC
        }
 
    }