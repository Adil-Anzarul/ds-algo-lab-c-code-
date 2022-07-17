#include <stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{

    int n;
    printf("Enter number of items\n");
    scanf("%d", &n);
    int value[n];
    int weight[n];
    int vpw[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d\n ", i+1);
        scanf("%d%d", &value[i], &weight[i]);
        vpw[i] = value[i] / weight[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vpw[j] < vpw[j + 1])
            {
                swap(&value[j], &value[j + 1]);
                swap(&weight[j], &weight[j + 1]);
                swap(&vpw[j], &vpw[j + 1]);
            }
        }
    }

    printf("Enter the weight of knapsack\n");
    int W;
    scanf("%d", &W);
    int profit=0;
    for(int i=0;i<n;i++)
    {
        if(W>=weight[i])
        {
            W=W-weight[i];
            profit+=value[i];
        }
        else if(W<weight[i])
        {
            profit+=W*vpw[i];
            break;
        }
    }
    printf("The total profit is %d\n",profit);

    return 0;
}