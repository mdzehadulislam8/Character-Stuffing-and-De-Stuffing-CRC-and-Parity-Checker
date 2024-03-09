#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PASSWORD "admin"

void playWrongPasswordSound()
{
// Play the sound using Windows
    printf("\a"); // Produces a sound
}
void clearConsole()
{

    printf("\033[2J\033[H");
}
void login()
{
    char password[50];
    int attempts = 3;
    while (attempts > 0)
    {
        clearConsole();
        printf("\t\t\t\tGreen University Of Bangladesh (GUB)\n\n");
        printf("\t\t\t\t Data Communication Project\n\n");
        printf("Login...\n\n");
        printf("Enter password: ");
        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n')
        {
            if (ch == '\b')
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                password[i++] = ch;
                printf("*");
            }
        }
        password[i] = '\0';
        printf("\n");
        if (strcmp(password, PASSWORD) == 0)
        {
            printf("Login Successfully!\n");
            getchar(); // Wait for a key press
            clearConsole();
            return;
        }
        else
        {
            attempts--;
            printf("Wrong password! Attempts left: %d\n", attempts);
            playWrongPasswordSound();
            getchar(); // Wait for a key press
            clearConsole();
        }
    }
    printf("Too many wrong attempts. Exiting...\n");
    exit(9);
}
// character stuffing and de-stuffing
void characterStuffingAndDeStuffing()
{
    int i=0,j=0;
    char d[100],l[]="DLEETX",sd[100],ds[100];
    printf("\t\t\t\t\tEnter Data in UpperCase: ");
    scanf("%s",d);

    sd[0]='D', sd[1]='L', sd[2]='E',sd[3]='S',sd[4]='T',sd[5]='X';
    j=6;
    while(d[i]!='\0')
    {
        if(d[i]=='D'&& d[i+1]=='L'&& d[i+2]=='E')
        {
            sd[j]='D', sd[j+1]='L', sd[j+2]='E', sd[j+3]='D',
                                            sd[j+4]='L', sd[j+5]='E';
            j+=6;
            i+=3;
        }
        else
            sd[j++]=d[i++];
    }
    sd[j]='\0';
    strcpy(ds,sd);
    strcat(sd,l);
    printf("After Stuffing: ");
    printf("%s",sd);
    i=0;
    j=6;
    while(ds[j]!='\0')
    {
        if( ds[j]=='D'&&ds[j+1]=='L'&& ds[j+2]=='E'&&
                ds[j+3]=='D'&& ds[j+4]=='L'&& ds[j+5]=='E')
        {
            d[i]='D', d[i+1]='L',d[i+2]='E';
            j+=6;
            i+=3;
        }

        else
            d[i++]=ds[j++];
    }
    d[i]='\0';
    printf("\n\nAfter De−Stuffing: ");
    printf("%s",d);
}
// Function for CRC checking
void checkCRC()
{
    char data[20], div[20], temp[4], total[100];
    int i, j, datalen, divlen, len, flag = 1;
    printf("\t\t\t\t\tEnter the total bit of data: ");
    scanf("%d", &datalen);
    printf("\t\t\t\t\tEnter the total bit of divisor: ");
    scanf("%d", &divlen);
    len = datalen + divlen - 1;
    printf("\t\t\t\t\tEnter the data: ");
    scanf("%s", data);
    printf("\t\t\t\t\tEnter the divisor: ");
    scanf("%s", div);
    for (i = 0; i < datalen; i++)
    {
        total[i] = data[i];
        temp[i] = data[i];

    }
    for (i = datalen; i < len; i++)
        total[i] = '0';
// CRC checking function
    for (j = 0; j < divlen; j++)
        data[j] = total[j];
    while (j <= len)
    {
        if (data[0] == '1')
        {
            for (i = 1; i < divlen; i++)
                data[i] = (data[i] == div[i]) ? '0' : '1';
        }
        for (i = 0; i < divlen - 1; i++)
            data[i] = data[i + 1];
        data[i] = total[j++];
    }
    for (i = 0; i < divlen - 1; i++)
    {
        if (data[i] == '1')
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("Successful! No errors found.\n");
    else
        printf("Received code word contains errors.\n");
}

// Function for odd parity checking
void oddParityCheck()
{
    char data[100];
    printf("\t\t\t\t\tEnter the data: ");
    scanf("%s", data);
    int length = strlen(data);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] == '1')
        {
            count++;
        }
    }
    int c = length + 1;
    if (count % 2 == 0)
    {
        for (int i = c, j = c - 1; i > 0; i--, j--)
        {
            data[i] = data[j];
        }
        data[0] = '1';
        printf("After adding '1' at the front of the data: %s\n", data);
    }
    else
    {
        for (int i = c, j = c - 1; i > 0; i--, j--)
        {
            data[i] = data[j];
        }
        data[0] = '0';
        printf("After adding '0' at the front of the data: %s\n", data);
    }

}
void mainMenu()
{
    int choice;
    while (1)
    {
        printf("\n\t\t\t\t\t\xcd\xcd\xcd\xcd\xcd Data Communication System \xcd\xcd\xcd\xcd\xcd");
        printf("\n\n\t\t\t\t\t=====================================\n");
        printf("\t\t\t\t\t\t1. Character Stuffing and De-Stuffing\n");
        printf("\t\t\t\t\t\t2. CRC Check\n");
        printf("\t\t\t\t\t\t3. Odd Parity Check\n");
        printf("\t\t\t\t\t\t4. Exit\n\n");
        printf("\t\t\t\t\t=====================================\n");
        printf("\t\t\t\t\tChoose an option: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            characterStuffingAndDeStuffing();
            break;
        case 2:
            checkCRC();
            break;
        case 3:
            oddParityCheck();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:

            printf("Invalid choice. Please try again...\n");
        }
    }
    return 0;
}
int main()
{
    login();
    mainMenu();
    return 0;
}
