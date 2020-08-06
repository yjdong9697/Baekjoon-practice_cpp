#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    int data[T][2];
    for(int i = 0; i< T; i++)
    {
        int first , second;
        scanf("%d %d", &first, &second);
        data[i][0] = first;
        data[i][1] = second;
    }
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: %d + %d = %d\n", i, data[i - 1][0], data[i - 1][1], data[i -1][0] + data[i -1][1]);
    }
    return 0;
}