#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variable
int fund[2];
float money;

// 3 function
void random(int choice) // random percentage of interest
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < choice; i++)
    {
        fund[i] = (rand() % 6) + 3; // 3 + (0->5)
    }
}

void show_random(float money_start)
{
    int cal_month = 0, month, year, choice;
    float money_keep;
    money = money_start;
    printf("Time Past: 0 year 0 month\n");
    printf("Current money: 1000.00 Majikite\n");
    while (cal_month < 60) // loop until finish 5 years
    {
        printf("What do you want to choose next?\n");
        printf("1. Majikleen Fund (3-8 per) 3 months\n");
        printf("2. Bank (6 per) 6 months\n");
        printf("Enter Choice (1 / 2): ");
        scanf("%d", &choice); // input choice
        printf("\n");
        random(choice); // random interest
        if (choice == 1) // 3 month
        {
            cal_month += 3;
            year = cal_month / 12;
            month = cal_month % 12;
            money_keep = ((money * fund[0]) / 100) * 3 + money;
            printf("Times past: %d year %d months\n", year, month);
            printf("Current money: %.2f\n", money_keep); // after plus interest
            printf("In %d year %d month, the interest of the fund is %d per\n", (cal_month - 3) / 12, (cal_month - 3) % 12, fund[0]);
        }
        else // 6 month
        {
            cal_month += 6;
            if (cal_month > 60) // cal_month is 4 years 9 months = 57 months if we choose choice2 will >5 years
            {
                printf("please choose choice 1\n");
                cal_month = cal_month - 6;
                continue; // go to next loop
            }
            year = cal_month / 12;
            month = cal_month % 12;
            money_keep = money + ((money * 6) / 100) * 6;
            printf("Times Past: %d years %d months\n", year, month);
            printf("Current money: %.2f\n", money_keep); // after plus interest
            printf("In %d year %d month, the interest of the fund is %d per\n", (cal_month - 6) / 12, (cal_month - 6) % 12, fund[0]);
            printf("In %d year %d month, the interest of the fund is %d per\n", (cal_month - 3) / 12, (cal_month - 3) % 12, fund[1]);
        }
        money = money_keep;
    }
    printf("Final money: %.2f\n", money_keep);
    printf("\n");
}

void final_money() // cal amount of bank and coin
{
    float value[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.25};
    int n[11] = {0};
    int s = sizeof(value) / sizeof(float);

    for (int i = 0; i < 11; i++)
    {
        while (money >= value[i])
        {
            money -= value[i];
            n[i]++;
        }
    }
    for (int j = 0; j < 11; j++)
    {
        printf("%10.2f Majijkite x %d\n", value[j], n[j]);
    }
}

// main
int main()
{
    printf("Start money. 1000.00 Majikite\n");
    printf("\n");
    show_random(1000);
    final_money();
    return 0;
}
