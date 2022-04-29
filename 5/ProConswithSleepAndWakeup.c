#include <stdio.h>
int main()
{
    int buffer[10], bufsize, in, out, produce, consume, choice = 0;
    in = 0;
    out = 0;
    bufsize = 10;
    while (choice != 3)
    {
        printf("1. Produce \t 2. Consume \t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((in + 1) % bufsize == out)
                printf("Buffer is Full\n");
            else
            {
                printf("Enter the value: ");
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % bufsize;
            }
            break;
        case 2:
            if (in == out)
                printf("Buffer is Empty\n");
            else
            {
                consume = buffer[out];
                printf("The consumed value is %d\n", consume);
                out = (out + 1) % bufsize;
            }
            break;
        }
    }
    return 0;
}
