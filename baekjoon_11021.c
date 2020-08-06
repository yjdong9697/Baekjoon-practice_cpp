#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    int data[T];
    for(int i = 0; i< T; i++)
    {
        int first , second;
        scanf("%d %d", &first, &second);
        data[i] = first + second;
    }
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: %d\n", i, data[i - 1]);
    }
    return 0;
}