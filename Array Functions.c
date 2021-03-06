#include <stdio.h>
#include <windows.h>
//Array Manipulation Project, @anilfromdit #1000014217 #C3
#define cyan "\x1B[36m" //To Give Cyan color to text
#define reset "\x1B[0m" //To Reset to Default Color
//Header
void header()
{

    system("cls"); //To clear previous Output
    printf("**************************************\n\n");
    printf(cyan "\t\t\t\t\t\t    WELCOME\n\n");
    printf("\t\t\t\t\tINTEGER ARRAY MANUPULATION PROJECT\n\n" reset);
    printf("**************************************\n\n");
}
int main();
void out()
{
    header();
    printf("\nThank You For Using This Program\n\n");
    printf("This Program Was Made By ");
    printf(cyan "Himanshu Rawat\n\n" reset); // using cyan and reset to highlight my name
    printf("Hit Enter To Exit......");
    fflush(stdin); //To clear buffer
    getchar();     //To hold screen
    system("cls"); //To clear all the previous outputs by this program before exiting
    exit(0);
}
int *search(int *arr, int size)
{
    header();
    int search, c = 0, i = 0, j = 0;
    int loc[size];
    printf("Enter Integer you want to search:");
    scanf("%d", &search);
    while (i < size)
    {
        if (arr[i] == search)
        {
            c++;
            loc[j] = i;
            j++;
        }
        i++;
    }

    if (c == 0)
    {
        printf("\nYour Element %d is not present in Array\n", search);
    }
    else
    {
        printf("Your integer %d present %d time(s) in array at position(s) ", search, c);
        for (i = 0; i < j; i++)
        {
            printf("%d", loc[i] + 1);
            if (i != (j - 1))
            {
                printf(", ");
            }
        }
    }

    printf("\n\nPress Enter To Return To Main Menu\n");
    fflush(stdin);
    getchar();
    main();
}
int *insert(int *arr, int size)
{
    header();
    int num, pos, temp, i;
    printf("\nEnter The Element You Wish To Add To Your Array:");
    scanf("%d", &num);
A:
    printf("\n\nEnter the Position Where you want to add new element: ");
    scanf("%d", &pos);

    if (pos > (size + 1))
    {
        printf("\n\nOops That's an invalid location please try again\n");
        goto A;
    }
    for (i = 0; i < size; ++i)
    {
        if (i == (pos - 1))
        {
            temp = arr[i];
            arr[i] = num;

            if ((pos - 1) != (size - 1) && (pos - 1) != 0)
            {
                for (int i = size; i >= pos; --i)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = temp;
            }
            else if ((pos - 1) == (size - 1))
            {
                for (int j = size; j > pos - 1; --j)
                {
                    arr[j] = temp;
                }
            }
            else if ((pos - 1) == 0)
            {
                for (int j = size - 1; j > pos - 1; --j)
                {
                    arr[j + 1] = arr[j];
                }
                arr[pos] = temp;
            }
        }
        else if ((pos - 1) == size)
        {
            arr[pos - 1] = num;
        }
        else if (pos == 0)
        {
            printf("\nPlease Enter Position between 1 to %d.", size);
            goto A;
            break;
        }
    }
    printf("\n");
    printf("Your Updated Array Consist of:\n");
    for (i = 0; i <= size; ++i)
        printf("%d ", arr[i]);

    printf("\n\nPress Enter To Return To Main Menu\n");
    fflush(stdin); //To clear buffer
        getchar();     //To hold screen
        main(); //calling main function
}
int* delete (int *arr, int size)
{
    int Del,flag=0,i,j;
B:
    printf("\nEnter the number you want to delete : ");
    scanf("%d",&Del);
    for(i=0;i<size;++i)
    {
        if(arr[i]==Del)
        {
            for(j=i;j<size;++j)
            {   
                arr[j]=arr[j+1];
            }
            ++flag;
        }
    }
    if(flag==0)
    {    
        printf("%d is Not Present in your array . ",Del);
        printf("\nPlease Try Again\n");
        goto B;
    } 
    else  if(flag!=0)
    {
        printf("Updated Array Consists:\n");
        for(i=0;i<size-1;++i)
        printf("%d ",arr[i]);
    }

    printf("\n\nPress Enter To Return To Main Menu\n");
    fflush(stdin); //To clear buffer
        getchar();     //To hold screen
        main(); //calling main function
}
int* sort(int *arr,int size){
int i,j;
    for(i=0;i<=size-2;++i)
    {
        int flag=0;
        for(j=0;j<=size-i-2;++j)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                int Temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=Temp;
            }
        }
        if(flag==0)
        break;
    }
    printf("Your Array in Ascending order:\n");
    for(i=0;i<size;++i)
    {
        printf("%d ",arr[i]);
    }

    printf("\n\nYour Array in Descending order:\n");
    for(i=size-1;i>=0;--i)
    {
        printf("%d ",arr[i]);
    }




    printf("\n\nPress Enter To Return To Main Menu\n");
    fflush(stdin); //To clear buffer
        getchar();     //To hold screen
        main(); //calling main function
}
int* removeDuplicate(int* arr,int size){
    int i,j;
    for(i=0;i<size;++i)
    {
        for(j=i+1;j<size;++j)
        {
            if(arr[i]==arr[j])
            {
                int k;
                for(k=j+1;k<size;++k)
                {
                    arr[k-1]=arr[k];
                }
                --size;
                --j;
            }
        }
    }
    printf("Update Array Consist of:\n");
    for(i=0;i<size;++i)
    {
        printf("%d",arr[i]);
        if(i!=(size-1))
        printf(", ");
    }


printf("\n\nPress Enter To Return To Main Menu\n");
    fflush(stdin); //To clear buffer
        getchar();     //To hold screen
        main(); //calling main function

}
int main()
{
    header();
    int opt, size, i, arr[200];
    printf("Choose An Option:\n");
    printf("1. Search an Element\n");
    printf("2. Insert an Element\n");
    printf("3. Delete Elemtens\n");
    printf("4. Sort the element in ascending and Descending order\n");
    printf("5. Remove Duplicates\n");
    printf("6. Exit\n\n");
    printf("Enter Your Choice:");
    scanf("%d", &opt);
    if (opt < 1 || opt > 6)
    {
        printf("Please Choose An Appropiate Option\nHit Enter To Continue...");
        fflush(stdin); //To clear buffer
        getchar();     //To hold screen
        main(); //calling main function
    }
    else if (opt == 6)
    {
        out(); //To exit
    }
    else
    {
        header();
        printf("Enter Number of Elements you want in array:");
        scanf(" %d", &size);
        printf("\nEnter %d Elements\n", size);
        for (i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    switch (opt)
    {
    case 1:
        search(arr, size);
        break;
    case 2:
        insert(arr, size);
        break;
    case 3:
        delete(arr, size);
        break;
    case 4:
        sort(arr, size);
        break;
    case 5:
        removeDuplicate(arr,size);
        break;
    }

    return 0;
}