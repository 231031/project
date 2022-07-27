#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int decision[20];
int fund[2]; // Global
float money_keep;
int j=0;
int *random(int choice) // random percentage of interest
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < choice; ++i) // random and get same number
    {
        decision[j] = fund[i] = (rand() % 6) + 3;
        j++;
    }
    return decision;
}

int show_random(float money_start) 
{
    int cal_month = 0, month, year, choice;
    float money;
    money = money_start;
    printf("Time Past: 0 year 0 month\n");
    printf("Current money: 1000.00 Majikite\n");
    while (cal_month < 60) // loop until finish 5 years
    {
        printf("What do you want to choose next?\n");
        printf("1. Majikleen Fund (3-8 per) 3 months\n");
        printf("2. Bank (6 per) 6 months\n");
        printf("Enter Choice (1 / 2): ");
        scanf("%d", &choice);
        printf("\n");
        random(choice);
        if (choice == 1)
        {
            cal_month += 3;
            year = cal_month / 12;
            month = cal_month % 12;
            money_keep = ((money * fund[0]) / 100) * 3 + money;
            printf("Times past: %d year %d months\n", year, month);
            printf("Current money: %.2f\n", money_keep);
            printf("In %d year %d month, the interest of the fund is %d per\n", (cal_month - 3) / 12, (cal_month - 3) % 12, fund[0]);
        }
        else
        {
            cal_month += 6;
            if (cal_month > 60) // cal_month is 4 years 9 months = 57 months if we choose choice2 will >5 years
            {
                printf("please choose choice 1\n");
                cal_month = cal_month - 6;
                continue; // error e
            }
            year = cal_month / 12;
            month = cal_month % 12;
            printf("Times Past: %d year %d months\n", year, month);
            money_keep = money + ((money * 6) / 100) * 6;
            printf("Current money: %.2f\n", money_keep);
            printf("In %d year %d month, the interest of the fund is %d per\n", (cal_month - 6) / 12, (cal_month - 6) % 12, fund[0]);
            printf("In %d year %d month, the interest of the fund is %d per\n", (cal_month - 3) / 12, (cal_month - 3) % 12, fund[1]);
        }
        money = money_keep; 
    }
    printf("Final money: %.2f\n",money_keep);
}

void money()
{
    float thousand,five_hundred,one_hundred,fifty,twenty,ten,five,two,one;
    char *amount[] = {"1000","500","100","50","20","10","5","2","1","0.5","0.25"};
    float point_fif,point_twenty;
    float decimal;
    int i=0;
    int bank[11];
    
    while (money_keep >= 1000)
    {
        bank[i] = money_keep/1000;
        money_keep = money_keep - bank[i]*1000;
    }
    i++;
    while (money_keep >= 500)
    {
        bank[i] = money_keep/500;
        money_keep = money_keep - bank[i]*500;
    }
    i++;
    while (money_keep >= 100)
    {
        bank[i] = money_keep/100;
        money_keep = money_keep - bank[i]*100;
    }
    i++;
   while (money_keep >= 50)
    {
        bank[i] = money_keep/50;
        money_keep = money_keep - bank[i]*50;
    }
    i++;
    while (money_keep >= 20)
    {
        bank[i] = money_keep/20;
        money_keep = money_keep - bank[i]*20;
    }
    i++;
    while (money_keep >= 10)
    {
        bank[i] = money_keep/10;
        money_keep = money_keep - bank[i]*10;
    }
    i++;
    while (money_keep >= 5)
    {
        bank[i] = money_keep/5;
        money_keep = money_keep - bank[i]*5;
    }
    i++;
    while (money_keep >= 2)
    {
        bank[i] = money_keep/2;
        money_keep = money_keep - bank[i]*2;
    }
    i++;
    while (money_keep >= 1)
    {
        bank[i] = money_keep/1;
        money_keep = money_keep - bank[i]*1;
    }
    i++;
    while (money_keep >= 0.5)
    {
        bank[i] = money_keep/0.5;
        money_keep = money_keep - bank[i]*0.5;
    }
    i++;
    while (money_keep >= 0.25)
    {
        bank[i] = money_keep/0.25;
        money_keep = money_keep - bank[i]*0.25;
    }
    for(int j=0;j<11;++j)
    {
        printf("%s Majijkite x%d\n",amount[i],bank[i]);
    }
}

int main()
{
    printf("Start money. 1000.00 Majikite\n");
    printf("\n");
    show_random(1000);
    money();
}
