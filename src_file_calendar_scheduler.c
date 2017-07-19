#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
 
#define max_name 17
#define max_description 257
typedef struct
{
    char event_name[max_name];
    int month1, date1, hour1, minute1, month2, date2, hour2, minute2;
    char description[max_description];
}event;
 
// Print the menu selection
void printmenu()
{
 
    puts("+------ SCHEDULER --------+\n"
         "|  1. Add New Event       |\n"
         "|  2. Delete Event        |\n"
         "|  3. Modify Event        |\n"
         "|  4. Print all           |\n"
         "|  5. Print Time Block    |\n"
         "|  6. Print Conflicts     |\n"
         "|  7. Search by name      |\n"
         "|  8. Search by keyword   |\n"
         "+-------------------------+\n");
 
}
 
// Add an event to an event list by sorting it into position
void sortInsert(event list[], int *size, event e)
{
    //printf("in sortInsert\n");
    addEventAtIndex(list, e, *size); // Add event to the end of the list
 
    (*size)++; // Increment size
 
    // Insertion Sort
    sort(list, *size);
}
 
// Add an event to an event list at a specified index
void addEventAtIndex(event list[], const event e, const int i)
{
    //printf("in addEventAtIndex\n");
    strcpy(list[i].event_name, e.event_name);
    list[i].month1 = e.month1;
    list[i].date1 = e.date1;
    list[i].month2 = e.month2;
    list[i].date2 = e.date2;
    list[i].hour1 = e.hour1;
    list[i].minute1 = e.minute1;
    list[i].hour2 = e.hour2;
    list[i].minute2 = e.minute2;
    strcpy(list[i].description, e.description);
}
 
// Insertion sort by swapping struct members
void sort(event list[], const int size)
{
    int i,j;
    for (int i = 1; i < size; i++)
        {
            //for (int j = i; j > 0 && (list[j-1].month1 > list[j].month1 || list[j-1].month1 == list[j].month1 && list[j-1].date1 > list[j].date1 || list[j - 1].hour1 > list[j].hour1 || (list[j - 1].hour1 == list[j].hour1 && list[j - 1].minute1 > list[j].minute1)); j--)
            for (j = i; (j > 0) && (list[j-1].month1 > list[j].month1) || (list[j-1].month1 == list[j].month1) && (list[j-1].date1 > list[j].date1) || (list[j - 1].hour1 > list[j].hour1) || (list[j - 1].hour1 == list[j].hour1) && (list[j - 1].minute1 > list[j].minute1); j--)
            {
               //to swap start times
                int monthJ = list[j].month1;
                int dateJ = list[j].date1;
                int hourJ = list[j].hour1;
                int minuteJ = list[j].minute1;
 
                char nameJ[max_name];
                strcpy(nameJ, list[j].event_name);
                char descriptionJ[max_description];
                strcpy(descriptionJ, list[j].description);
 
                int monthJMinus1 = list[j - 1].month1;
                int dateJMinus1 = list[j - 1].date1;
                int hourJMinus1 = list[j - 1].hour1;
                int minuteJMinus1 = list[j - 1].minute1;
                char nameJMinus1[max_name];
                strcpy(nameJMinus1, list[j-1].event_name);
                char descriptionJMinus1[max_description];
                strcpy(descriptionJMinus1, list[j - 1].description);
 
                list[j].month1 = monthJMinus1;
                list[j].date1 = dateJMinus1;
                list[j].hour1 = hourJMinus1;
                list[j].minute1 = minuteJMinus1;
                strcpy(list[j].event_name, nameJMinus1);
                strcpy(list[j].description, descriptionJMinus1);
 
                list[j - 1].month1 = monthJ;
                list[j - 1].date1 = dateJ;
                list[j - 1].hour1 = hourJ;
                list[j - 1].minute1 = minuteJ;
                strcpy(list[j-1].event_name, nameJ);
                strcpy(list[j - 1].description, descriptionJ);
 
               //to swap end times
                int monthJ2 = list[j].month2;
                int dateJ2 = list[j].date2;
                int hourJ2 = list[j].hour2;
                int minuteJ2 = list[j].minute2;
 
                int monthJMinus1_2 = list[j - 1].month2;
                int dateJMinus1_2 = list[j - 1].date2;
                int hourJMinus1_2 = list[j - 1].hour2;
                int minuteJMinus1_2 = list[j - 1].minute2;
 
                list[j].month2 = monthJMinus1_2;
                list[j].date2 = dateJMinus1_2;
                list[j].hour2 = hourJMinus1_2;
                list[j].minute2 = minuteJMinus1_2;
 
                list[j - 1].month2 = monthJ2;
                list[j - 1].date2 = dateJ2;
                list[j - 1].hour2 = hourJ2;
                list[j - 1].minute2 = minuteJ2;
            }
        }
   FILE *fptr;
   fptr=(fopen("output.txt","w"));
   if(fptr==NULL)
    {
       printf("Error!");
       exit(1);
    }
   for(int i=0;i<size;i++)
   {
    char mo1 = { (list[i].month1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char mo2 = { (list[i].month1 - (list[i].month1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char d1 = { (list[i].date1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char d2 = { (list[i].date1 - (list[i].date1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char mo3 = { (list[i].month2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char mo4 = { (list[i].month2 - (list[i].month2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char d3 = { (list[i].date2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char d4 = { (list[i].date2 - (list[i].date2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char m1 = { (list[i].minute1 / 10) + '0' };
    char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
    char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char m3 = { (list[i].minute2 / 10) + '0' };
    char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
 
    fprintf(fptr,"%s",list[i].event_name);
    fprintf(fptr,"%c%c/%c%c  %c%c:%c%c", mo1, mo2, d1, d2, h1, h2, m1, m2);
    fprintf(fptr,"\n");
    fprintf(fptr,"%c%c/%c%c  %c%c:%c%c", mo3, mo4, d3, d4, h3, h4, m3, m4);
    fprintf(fptr,"\n");
    fprintf(fptr,"%s", list[i].description);
    fprintf(fptr,"2016#");
    fprintf(fptr,"\n");
   }
   fclose(fptr);
   return 0;
 
}
 
// Setup a new event with user input and return a pointer to the same event
event* newEvent(event *e)
{
    //if (isNull(e))
    //    { // If e is NULL
       //   e = initEvent(); // Initialize it
      //  }
 
    //printf("in newEvent\n");
    int i=100;
    char temp[100];
    char *separator = "+--------------------------------+";
 
    printf("\n%s\n|           NEW EVENT            |\n%s\n\n", separator, separator);
 
    printf("Enter new event name: ");
    fgetc(stdin);
    fgets(e->event_name, sizeof(e->event_name), stdin);
 
    //fgets(temp, sizeof(e->event_name), stdin);
    //fgets(e->event_name, sizeof(e->event_name), stdin);
    //printf("what i entered was %s",e->event_name);
 
    char *prompt1 = "Enter new event start time (mm/dd hh:mm): ";
    printf(prompt1);
    scanf("%d/%d %d:%d",&e->month1, &e->date1, &e->hour1, &e->minute1);
 
    char *prompt2 = "Enter new event end time (mm/dd hh:mm): ";
    printf(prompt2);
    scanf("%d/%d %d:%d",&e->month2, &e->date2, &e->hour2, &e->minute2);
 
    printf("Enter a description: ");
    fgetc(stdin);
    fgets(e->description, sizeof(e->description), stdin);
    //scanf("%s", e->description);
 
    //fgets(e->description, max_description, stdin);
 
    puts("+-------------------------+\n");
 
    puts("| Event successfully added.\n");
 
    return e;
 
}
 
// Return true if an event is NULL, false otherwise
//bool isNull(const event *e)
//{
//   return e == NULL;
//}
 
// Allocate memory for and initialize an event
event *initEvent()
{
    //printf("in initEvent\n");
    event *e = (event*)malloc(sizeof(event));
 
    strcpy(e->event_name, "");
    e->date1 = 0;
    e->month1 = 0;
    e->date2 = 0;
    e->month2 = 0;
    e->hour1 = 0;
    e->minute1 = 0;
    e->hour2 = 0;
    e->minute2 = 0;
    strcpy(e->description, "");
 
    return e;
}
 
// Display all events in an event list
void printEventList(const event list[], const int size) {
 
    if (size == 0) {
        puts("\n| You have no events scheduled!\n");
        return;
    }
 
    char *separator = "+--------------------------------+";
 
    printf("\n%s\n|          MY SCHEDULE           |\n%s\n\n", separator, separator);
 
    for (int i = 0; i < size; i++)
    {
        //printf("| [%d] ", i);
        printEvent(list[i]);
        printf("\n");
 
    }
 
    putchar('\n');
 
}
 
// Display an event in a readable format: [ID] HH:MM - DESCRIPTION
void printEvent(const event e) {
 
    //printf("%d:%d  %d:%d", e.hour1,e.minute1,e.hour2,e.minute2);
    char mo1 = { (e.month1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char mo2 = { (e.month1 - (e.month1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char d1 = { (e.date1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char d2 = { (e.date1 - (e.date1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char mo3 = { (e.month2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char mo4 = { (e.month2 - (e.month2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char d3 = { (e.date2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char d4 = { (e.date2 - (e.date2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char h1 = { (e.hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h2 = { (e.hour1 - (e.hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char m1 = { (e.minute1 / 10) + '0' };
    char m2 = { (e.minute1 - (e.minute1 / 10) * 10) + '0' };
 
    char h3 = { (e.hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h4 = { (e.hour2 - (e.hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char m3 = { (e.minute2 / 10) + '0' };
    char m4 = { (e.minute2 - (e.minute2 / 10) * 10) + '0' };
 
    for(int i=0;i<strlen(e.event_name)-1;i++)
            {
                printf("%c",e.event_name[i]);
            }
    printf("\n");
    printf("%c%c/%c%c  %c%c:%c%c", mo1, mo2, d1, d2, h1, h2, m1, m2);
    printf("\n");
    printf("%c%c/%c%c  %c%c:%c%c", mo3, mo4, d3, d4, h3, h4, m3, m4);
    printf("\n");
    printf("%s", e.description);
    printf("2016#");
    printf("\n");
 
}
 
void printblock(event list[], int *size)
{
    int mnth1, dt1, hr1, min1, mnth2, dt2, hr2, min2,i;
    printf("Enter a start time(mm/dd hh:mm): ");
    scanf("%d/%d %d:%d", &mnth1, &dt1, &hr1, &min1);
    printf("Enter an end time(mm/dd hh:mm): ");
    scanf("%d/%d %d:%d", &mnth2, &dt2, &hr2, &min2);
 
    for(i=0; i<*size; i++)
    {
        if((list[i].month1>mnth1) && (list[i].month2<mnth2)) //1. if event start month and end month lie between start month and end month passed
        {
                char h1 = ( (list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ( (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m1 = ( (list[i].minute1 / 10) + '0' );
                char m2 = ( (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
 
                char h3 = ( (list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h4 = ( (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m3 = ( (list[i].minute2 / 10) + '0' );
                char m4 = ( (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' );
 
            for(i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
                printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //2.a if event start month is same as start month passed and event end month is less than end month passed
    for(i=0; i<*size; i++)
    {
        if((list[i].month1==mnth1) && (list[i].month2<mnth2) && (list[i].date1>dt1))
     {
                char h1 = ((list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ((list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m1 = ((list[i].minute1 / 10) + '0' );
                char m2 = ((list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
 
                char h3 = ((list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h4 = ((list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m3 = ((list[i].minute2 / 10) + '0' );
                char m4 = ((list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' );
 
            for(i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //2.b if event start month is same as start month passed and event end month is less than end month passed and event start date is same as the start date passed
    for(i=0; i<*size; i++)
    {
        if((list[i].month1==mnth1) && (list[i].month2<mnth2) && (list[i].date1==dt1) && (list[i].hour1>hr1))
     {
                char h1 = ((list[i].hour1 / 10) + '0'); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ((list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m1 = ((list[i].minute1 / 10) + '0' );
                char m2 = ((list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
 
                char h3 = ((list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h4 = ((list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m3 = ((list[i].minute2 / 10) + '0' );
                char m4 = ((list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' );
 
             for(i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //2.c if event start month is same as start month passed and event end month is less than end month passed and event start date is same as the start date passed and event start hour is greater than the start hour passed
    for(i=0; i<*size; i++)
    {
        if((list[i].month1==mnth1) && (list[i].month2<mnth2) && (list[i].date1==dt1) && (list[i].hour1==hr1) && (list[i].minute1>min1))
     {
                char h1 = ((list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ((list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m1 = ((list[i].minute1 / 10) + '0' );
                char m2 = ((list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
 
                char h3 = ((list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h4 = ((list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m3 = ((list[i].minute2 / 10) + '0');
                char m4 = ((list[i].minute2 - (list[i].minute2 / 10) * 10) + '0');
 
            for(i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //3.a if event start month is greater than start month passed and event end month is same as end month passed
    for(i=0; i<*size; i++)
    {
        if((list[i].month1>mnth1) && (list[i].month2==mnth2) && (list[i].date2<dt2))
     {
                char h1 = ( (list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ( (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0'); // Extract the second digit and convert to char
 
                char m1 = ( (list[i].minute1 / 10) + '0' );
                char m2 = ( (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0');
 
                char h3 = ( (list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h4 = ( (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m3 = ( (list[i].minute2 / 10) + '0' );
                char m4 = ( (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' );
 
            for(i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //3.b if event start month is greater than start month passed and event end month is same as end month passed and event end date is same as end date passed
    for(i=0; i<*size; i++)
    {
        if((list[i].month1>mnth1) && (list[i].month2==mnth2) && (list[i].date2==dt2) && (list[i].hour2<hr2))
     {
                char h1 = ((list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ((list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m1 = ((list[i].minute1 / 10) + '0' );
                char m2 = ((list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
 
                char h3 = ((list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h4 = ((list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m3 = ((list[i].minute2 / 10) + '0' );
                char m4 = ((list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' );
 
            for(i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //3.c if event start month is greater than start month passed and event end month is same as end month passed and event end date is same as end date passed and event end hour is same as the end hour passed
    for(int i=0; i<*size; i++)
    {
        if((list[i].month1>mnth1) && (list[i].month2==mnth2) && (list[i].date2==dt2) && (list[i].hour2==hr2) && (list[i].minute2<min2))
     {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //4.a if event start month is same as start month passed and event end month is same as end month passed
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1>dt1 && list[i].date2<dt2)
     {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //4.b if event start month is same as start month passed and event end month is same as end month passed and event end date is same as end date passed
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1>dt1 && list[i].date2==dt2 && list[i].hour2<hr2)
     {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //4.c if event start month is same as start month passed and event end month is same as end month passed and event end date is same as end date passed and event end hour is same as end hour passed
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1>dt1 && list[i].date2==dt2 && list[i].hour2==hr2 && list[i].minute2<min2)
     {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //4.d if event start month is same as start month passed and event end month is same as end month passed and event start date is same as start date passed while event end date is less than end date passed
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1==dt1 && list[i].date2<dt2 && list[i].hour1>hr1)
     {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //4.e if event start month is same as start month passed and event end month is same as end month passed and event start date is same as start date passed while event end date is less than end date passed
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1==dt1 && list[i].date2<dt2 && list[i].hour1==hr1 && list[i].minute1>min1)
        {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //5.a if event start month is same as start month passed and event end month is same as end month passed and event start date is same as start date passed and event end date is same as end date passed
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1==dt1 && list[i].date2==dt2 && list[i].hour1==hr1 && list[i].hour2<hr2)
        {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //5.b if event start month is same as start month passed and event end month is same as end month passed and event start date is same as start date passed and event end date is same as end date passed and event start
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1==dt1 && list[i].date2==dt2 && list[i].hour1==hr1 && list[i].hour2==hr2 && list[i].minute2<min2)
        {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //5.c if event start month is same as start month passed and event end month is same as end month passed and event start date is same as start date passed and event end date is same as end date passed and event start
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1==dt1 && list[i].date2==dt2 && list[i].hour1>hr1 && list[i].hour2==hr2)
        {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
    //5.d if event start month is same as start month passed and event end month is same as end month passed and event start date is same as start date passed and event end date is same as end date passed and event start
    for(int i=0; i<*size; i++)
    {
        if(list[i].month1==mnth1 && list[i].month2==mnth2 && list[i].date1==dt1 && list[i].date2==dt2 && list[i].hour1==hr1 && list[i].hour2==hr2 && list[i].minute1>min1)
        {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
            for(int i=0;i<strlen(list[i].event_name)-1;i++)
            {
                printf("%c",list[i].event_name[i]);
            }
 
            printf(" %c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
    }
}
 
void searchEvent(event list[], int *size)
{
    char temp[max_name], temp2[max_name];
    printf("Enter the event name to search for: ");
    fgetc(stdin);
    fgets(temp, max_name, stdin);
    for(int i=0; i<*size; i++)
    {
        if(strcmp(temp, list[i].event_name)==0)
        {
                char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m1 = { (list[i].minute1 / 10) + '0' };
                char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
                printf("%c%c:%c%c  %c%c:%c%c - %s", h1, h2, m1, m2, h3, h4, m3, m4, list[i].description);
        }
        else
        {
            for(i=0;i<strlen(temp)-1;i++)
            {
                printf("%c",temp[i]);
            }
            printf(" not found.\n");
        }
    }
}
 
void modifyEvent(event list[], int *size)
{
    char temp[max_name], h1,h2,h3,h4,h5,h6,h7,h8,m1,m2,m3,m4,m5,m6,m7,m8;
    int temp2;
    char temp3[max_name];
    printf("Enter the event name to modify: ");
    fgetc(stdin);
    fgets(temp, max_name, stdin);
    for(int i=0; i<*size; i++)
    {
        if(strcmp(temp, list[i].event_name)==0)
        {
            char *separator = "+--------------------------------+";
            printf("\n%s\n|           MODIFY EVENT            |\n%s\n\n", separator, separator);
            printf("Which field would you like to change?\n1. Change event name:\n2. Change start time:\n3. Change end time:\n4. Change description\nPlease enter your choice of selection:");
            scanf("%d",&temp2);
            switch(temp2)
            {
            case 1:
                   printf("Enter new event name: ");
                   fgetc(stdin);
                   fgets(list[i].event_name, max_name, stdin);
                   break;
            case 2:
                   printf("Enter new event start time(mm/dd hh:mm): ");
                   scanf("%d/%d %d:%d", &list[i].month1, &list[i].date1, &list[i].hour1, &list[i].minute1);
 
                   h1 = ((list[i].month1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                   h2 = ((list[i].month1 - (list[i].month1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                   m1 = ((list[i].date1 / 10) + '0' );
                   m2 = ((list[i].date1 - (list[i].date1 / 10) * 10) + '0');
 
                   h3 = ((list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                   h4 = ((list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                   m3 = ((list[i].minute1 / 10) + '0' );
                   m4 = ((list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
                   //fgetc(stdin);
                   //fgets(list[i].event_name, max_name, stdin);
                   break;
            case 3:
                   printf("Enter new event end time(mm/dd hh:mm): ");
                   scanf("%d/%d %d:%d", &list[i].month2, &list[i].date2, &list[i].hour2, &list[i].minute2);
 
                   h5 = ( (list[i].month2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                   h6 = ( (list[i].month2 - (list[i].month2 / 10) * 10) + '0'); // Extract the second digit and convert to char
 
                   m5 = ( (list[i].date2 / 10) + '0' );
                   m6 = ( (list[i].date2 - (list[i].date2 / 10) * 10) + '0' );
 
                   h7 = ((list[i].hour2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                   h8 = ((list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                   m7 = ((list[i].minute2 / 10) + '0' );
                   m8 = ((list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' );
            case 4:
                   printf("Enter new event description(no more than 256 characters): ");
                   fgetc(stdin);
                   fgets(list[i].description, max_description, stdin);
                   break;
            default: printf("Error! Option between 1-4 expected.\n");
                     break;
            }
        }
    }
}
 
// Delete an event from an event list
void deleteEvent(event list[], int *size, char *argv[])
{
 
    if (*size == 0)
    { // If list is empty
        puts("\n| Event list already empty.\n");
        return;
    }
 
    char temp[21];
    int id;
 
    char *separator = "\n+--------------------------------+";
    printf("%s\n|          DELETE EVENT          |%s\n\n", separator, separator);
 
    //for (int i = 0; i < *size; i++) { // Display the event list so the user can see which event to delete
     //   printf("| [%d] ", i);
     //   printEvent(list[i]);
  //  }
 
    printf("%s", "\n| Enter the event name to be deleted: ");
    fgetc(stdin);
    fgets(temp, 21, stdin);
    //id = atoi(temp);
    for(int i=0; i<*size; i++)
    {
        if(strcmp(temp, list[i].event_name)==0)
        {
            printf("| %s has been deleted.\n\n", list[i].event_name);
             // Set hour and minute to some trivially large value for sorting purposes
            list[i].month1 = 99;
            list[i].date1 = 99;
            list[i].month2 = 99;
           list[i].date2 = 99;
            list[i].hour1 = 99;
            list[i].minute1 = 99;
            list[i].hour2 = 99;
            list[i].minute2 = 99;
            strcpy(list[i].event_name, "");
            strcpy(list[i].description, "");
        }
    }
 
    if (id != (*size - 1)) { // If the event to remove is already last, there's no need to sort it to last
        sort(list, *size);
    }
 
    (*size)--;
 
    FILE *fptr;
    fptr=(fopen("output.txt","w"));
    if(fptr==NULL)
    {
       printf("Error!");
       exit(1);
    }
    for(int i=0;i<*size;i++)
    {
     char mo1 = { (list[i].month1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
     char mo2 = { (list[i].month1 - (list[i].month1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
     char d1 = { (list[i].date1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
     char d2 = { (list[i].date1 - (list[i].date1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char mo3 = { (list[i].month2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char mo4 = { (list[i].month2 - (list[i].month2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char d3 = { (list[i].date2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char d4 = { (list[i].date2 - (list[i].date2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char h1 = { (list[i].hour1 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h2 = { (list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char m1 = { (list[i].minute1 / 10) + '0' };
    char m2 = { (list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' };
 
    char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
    char m3 = { (list[i].minute2 / 10) + '0' };
    char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
 
    fprintf(fptr,"%s",list[i].event_name);
    fprintf(fptr,"%c%c/%c%c  %c%c:%c%c", mo1, mo2, d1, d2, h1, h2, m1, m2);
    fprintf(fptr,"\n");
    fprintf(fptr,"%c%c/%c%c  %c%c:%c%c", mo3, mo4, d3, d4, h3, h4, m3, m4);
    fprintf(fptr,"\n");
    fprintf(fptr,"%s", list[i].description);
    fprintf(fptr,"2016#");
    fprintf(fptr,"\n");
   }
   fclose(fptr);
   return 0; // Decrement the size of the list
    //if (id > *size - 1) {
    //    printf("\n| No event located at %d\n", id);
      //  return;
 
 
}
 
void searchKeyword(event list[], int *size)
{
    char temp[max_name], temp2[max_name], *ptr1, *ptr2;
    printf("Enter a keyword to search for: ");
    scanf("%s",&temp2);
 
    for(int i=0; i<*size; i++)
    {
        if((strstr(list[i].event_name, temp2)!=NULL) || (strstr(list[i].description, temp2)!=NULL))
        {
                char mo1 = ((list[i].month1 / 10) + '0'); // Extract the first digit and convert to char (if any, else 0)
                char mo2 = ((list[i].month1 - (list[i].month1 / 10) * 10) + '0'); // Extract the second digit and convert to char
 
                char d1 =  ((list[i].date1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char d2 =  ((list[i].date1 - (list[i].date1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char mo3 = ((list[i].month2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char mo4 = ((list[i].month2 - (list[i].month2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char d3 = ((list[i].date2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char d4 = ((list[i].date2 - (list[i].date2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char h1 = ((list[i].hour1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
                char h2 = ((list[i].hour1 - (list[i].hour1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
                char m1 = ((list[i].minute1 / 10) + '0' );
                char m2 = ((list[i].minute1 - (list[i].minute1 / 10) * 10) + '0' );
 
                char h3 = { (list[i].hour2 / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
                char h4 = { (list[i].hour2 - (list[i].hour2 / 10) * 10) + '0' }; // Extract the second digit and convert to char
 
                char m3 = { (list[i].minute2 / 10) + '0' };
                char m4 = { (list[i].minute2 - (list[i].minute2 / 10) * 10) + '0' };
 
                printf("%s", list[i].event_name);
                printf("%c%c/%c%c  %c%c:%c%c", mo1, mo2, d1, d2, h1, h2, m1, m2);
                printf("\n");
                printf("%c%c/%c%c  %c%c:%c%c", mo3, mo4, d3, d4, h3, h4, m3, m4);
                printf("\n");
                printf("%s", list[i].description);
                printf("2016#");
                printf("\n");
        }
                    else
                    {
                        for(i=0;i<strlen(temp2);i++)
                        {
                            printf("%c",temp2[i]);
                        }
                        printf(" not found.\n");
                    }
    }
}
 
void printConflict(event list[], int *size)
{
  //  printf("value of star size=%d\n",*size);
    char temp[max_name], temp2[max_name];
    int i,j,k,p;
    k=0;
    p=0;
    char mo1,mo2,mo3,mo4,d1,d2,d3,d4,h1,h2,h3,h4,m1,m2,m3,m4;
    printf("Enter the event name: ");
    fgetc(stdin);
    fgets(temp, max_name, stdin);
 
    for(j=0; j<*size; j++)
    {
        if(strcmp(temp, list[j].event_name)!=0)
        {
            k=k+1;
        }
    }
    printf("first value of k=%d",k);
    if(k==*size)
    {
        printf("in no matching situation\n");
        printf("No conflicting event.\n");
    }
    printf("second value of k=%d",k);
    k=0;
    j=0;
 
    for(j=0; j<*size; j++)
    {
        if(strcmp(temp, list[j].event_name)==0)
        {
          // printf("inside strcmp\n");
           for(i=0;i<*size;i++)
           {
             printf("list[%d]=%s\nlist[%d]=%s\n",j,list[j].event_name,i,list[i].event_name);
             if(list[j].month1<list[i].month1 && list[j].month2>list[i].month2) //date in between months
             {
               printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2>list[i].month2) && (list[j].date1<list[i].date1))//2.1
             {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1<list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date2>list[i].date2)) //2.2
             {
             printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1<list[i].date1) && (list[j].date2>list[i].date2)) //3.1 both same months
             {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1==list[i].date1) && (list[j].date2>list[i].date2) && (list[j].hour1<list[i].hour1))//3.2
             {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1<list[i].date1) && (list[j].date2==list[i].date2) && (list[j].hour2>list[i].hour2))//3.3
             {
               printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1==list[i].date1) && (list[j].date2==list[i].date2) && (list[j].hour1<list[i].hour1) && (list[j].hour2>list[i].hour2))//4.both dates are same
             {
               printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1==list[i].date1) && (list[j].date2==list[i].date2) && (list[j].hour1==list[i].hour1) && (list[j].hour2>list[i].hour2) && (list[j].minute1<list[i].minute1))//4.1
             {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1==list[i].date1) && (list[j].date2==list[i].date2) && (list[j].hour1<list[i].hour1) && (list[j].hour2==list[i].hour2) && (list[j].minute2>list[i].minute2))//4.2
             {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
             else if((list[j].month1==list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date1==list[i].date1) && (list[j].date2==list[i].date2) && (list[j].hour1==list[i].hour1) && (list[j].hour2==list[i].hour2) && (list[j].minute1<list[i].minute1) && (list[j].minute2>list[i].minute2))//5. both hours are same
             {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
             }
            /*
            End time between start and end of an event
 
            */
            else if((list[j].month1>list[i].month1) && (list[j].month2>list[i].month2))//6.1end time between start and end
            {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
 
            }
            else if((list[j].month1>list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date2>list[i].date2))//6.2
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1>list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2))//6.3
            {
             printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1>list[i].month1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2) && (list[j].minute2>list[i].minute2))//6.4
            {
             printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1>list[i].date1) && (list[j].month2>list[i].month2))//7.1
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1>list[i].date1) && (list[j].month2==list[i].month2) && (list[j].date2>list[i].date2))//7.2
            {
             printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1>list[i].date1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2))//7.3
            {
             printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1>list[i].date1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2) && (list[j].minute2>list[i].minute2))//7.4
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1>list[i].hour1) && (list[j].month2>list[i].month2))//8.1
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1>list[i].hour1) && (list[j].month2==list[i].month2) && (list[j].date2>list[i].date2)) //8.2
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1>list[i].hour1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2))//8.3
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1>list[i].hour1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2) && (list[j].minute2>list[i].minute2)) //8.4
            {
              printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1==list[i].hour1) && (list[j].minute1>list[i].minute1) && (list[j].month2>list[i].month2))  //9.1
            {
               printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1==list[i].hour1) && (list[j].minute1>list[i].minute1) && (list[j].month2==list[i].month2) && (list[j].date2>list[i].date2))//9.2
            {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1==list[i].hour1) && (list[j].minute1>list[i].minute1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2))//9.3
            {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else if((list[j].month1==list[i].month1) && (list[j].date1==list[i].date1) && (list[j].hour1==list[i].hour1) && (list[j].minute1>list[i].minute1) && (list[j].month2==list[i].month2) && (list[j].date2==list[i].date2) && (list[j].hour2==list[i].hour2) && (list[j].minute2>list[i].minute2))//9.4
            {
                printEverytime(list[i].month1,list[i].month2,list[i].date1,list[i].date2,list[i].hour1, list[i].hour2, list[i].minute1, list[i].minute2, list[i].event_name, list[i].description);
            }
            else
            {
              p=p+1;
            }
 
          }
      if(p==*size)
      {
          printf("after while loop\n");
          printf("No conflicting event.\n");
      }
   }
 
  }
  printf("third value of j=%d",j);
 
}
void printEverytime(int mot1, int mot2, int dte1, int dte2, int hre1, int hre2, int mn1, int mn2, char ev_name[], char ev_descr[])
{
            char mo1,mo2,mo3,mo4,d1,d2,d3,d4,h1,h2,h3,h4,m1,m2,m3,m4;
            mo1 = ((mot1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
            mo2 = ((mot1 - (mot1 / 10) * 10) + '0'); // Extract the second digit and convert to char
 
            d1 = ((dte1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
            d2 = ((dte1 - (dte1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
            mo3 = ((mot2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
            mo4 = ((mot2 - (mot2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
            d3 = ((dte2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
            d4 = ((dte2 - (dte2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
            h1 = ((hre1 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
            h2 = ((hre1 - (hre1 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
           m1 = ((mn1 / 10) + '0' );
            m2 = ((mn1 - (mn1 / 10) * 10) + '0' );
 
            h3 = ((hre2 / 10) + '0' ); // Extract the first digit and convert to char (if any, else 0)
            h4 = ((hre2 - (hre2 / 10) * 10) + '0' ); // Extract the second digit and convert to char
 
            m3 = ((mn2 / 10) + '0' );
            m4 = ((mn2 - (mn2 / 10) * 10) + '0' );
 
 
            printf("%s", ev_name);
            printf("%c%c/%c%c  %c%c:%c%c", mo1, mo2, d1, d2, h1, h2, m1, m2);
            printf("\n");
            printf("%c%c/%c%c  %c%c:%c%c", mo3, mo4, d3, d4, h3, h4, m3, m4);
            printf("\n");
            printf("%s", ev_descr);
            printf("2016#");
            printf("\n");
}
 
int main(int argc, char *argv[])
{
    event list[100];
    int index = 0; //number of elements in the list
    int selection=0;
    char option[1];
 
    while(selection<9)
    {
        printmenu();
        printf("Please select an option: ");
        scanf("%d",&selection);
        printf("\n\n");
        //selection=option-'0';
 
        switch(selection)
        {
                case 1: //Add new event
                    sortInsert(list, &index, *newEvent(&list[index]));
                    break;
                case 2: // Delete Event
                    deleteEvent(list, &index, argv[1]);
                    break;
                case 3: //Modify existing event
                    modifyEvent(list, &index);
                    break;
                case 4: //print all events
                    printEventList(list, index);
                    break;
                case 5: //print time block
                    printblock(list, &index);
                    break;
                case 6: //print time conflict
                    printConflict(list, &index);
                    break;
                case 7: //search event by name
                    searchEvent(list, &index);
                    break;
                case 8: //search event by keyword
                    searchKeyword(list, &index);
                    break;
		//trying the git thing - 2nd time
 
        }
    }
}