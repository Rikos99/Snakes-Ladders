#include <stdio.h>
#include "kostka.h"
#include "snakes-and-ladders.h"

#define VELIKOSTPLOCHY 10

int main() {

    int hracX = 1;
    int hracY = 1;
    int hracX2 = 1;
    int hracY2 = 1;
    int hrac1_vyhra = 0, hrac2_vyhra = 0;
    int k = 1;
    int l = 1;
    int hod1;//hod kostkou pro Hrace1
    int hod2;//hod kostkou pro Hrace2
    char hrac1, hrac2, GUI, hrat_znovu;
    int pocet_kol = 0;

    //Moznost pro GUI
    printf("Vitejte ve hre Snakes and Ladders\n");
    printf("Chcete vykreslovat herni plochu?\n");
    printf("Jestli ano, zadejte znak 'a', nebo 'Ä́'.\nJestli ne, zadejte libovolny znak.\n");
    scanf(" %c", &GUI);
    getchar();


    //Vyber znaku hrace 1
    printf("Zadejte znak Hráče 1: ");
    scanf(" %c", &hrac1);
    //Vyber znaku hrace 2
    printf("Zadejte znak Hráče 2: ");
    scanf(" %c", &hrac2);

    do //Hrat znovu?
    {
    printf("Hrac1: Vase pozice na poli: %d\n", ((hracY - 1) * 10) + hracX); //Vypis pozice Hrace1 na plose
    printf("Hrac2: Vase pozice na poli: %d\n", ((hracY - 1) * 10) + hracX2); //Vypis pozice Hrace2 na plose
    if (GUI == 'a' || GUI == 'A') {
        for (int i = 1; i <= VELIKOSTPLOCHY; i++)
        {
            for (int j = 1; j <= VELIKOSTPLOCHY; j++)
            {
                if (j == hracX && i == hracY && j == hracX2 && i == hracY2)
                {
                    printf("%c%c\t", hrac1, hrac2); //Vypis obou hracu
                }
                else if (j == hracX && i == hracY)
                {
                    printf("%c\t", hrac1); //Vypis Hrace1
                }
                else if (j == hracX2 && i == hracY2)
                {
                    printf("%c\t", hrac2); //Vypis Hrace2
                }
                else //Vypis poli bez hracu
                {
                    if (l < 9) //DON'T TOUCH IT JUST WORKS
                    {
                        printf("0%d\t", k);
                        l++;
                    }
                    else
                    {
                        printf("%d\t", k);
                    }
                }
                k++;
            }
            printf("\n");
        }
    }
    k = 1;
    l = 1;
    do
    {
        printf("Hrac1: Zmacknete Enter pro hod kostkou\n"); //Hod hrace1
        //while (getchar() != '\n');
        hod1 = kostka(&hracX);
        printf("Hrac1: Hodili jste: %d\n", hod1);
        printf("Hrac1: Vase pozice na poli: %d\n", ((hracY - 1) * 10) + hracX); //Vypis pozice Hrace1 na plose


        printf("Hrac2: Zmacknete Enter pro hod kostkou\n"); //Hod hrace2
        //while (getchar() != '\n');
        hod2 = kostka(&hracX2);
        printf("Hrac2: Hodili jste: %d\n", hod2);
        printf("Hrac2: Vase pozice na poli: %d\n", ((hracY2 - 1) * 10) + hracX2); //Vypis pozice Hrace2 na plose


        if (hracX > 10 && hracY < 10) //postup na dalsi radek
        {
            hracX = hracX - 10;
            hracY++;
        }
        if (hracX2 > 10 && hracY2 < 10) //postup na dalsi radek
        {
            hracX2 = hracX2 - 10;
            hracY2++;
        }

        snakes(&hracX, &hracY, 1); //Zkontrolovani, jestli hrac nestoupl na hada
        snakes(&hracX2, &hracY2, 2);
        ladders(&hracX, &hracY, 1); //Zkontrolovani, jestli hrac nestoupl na zebrik
        ladders(&hracX2, &hracY2, 2);

        if (hracY >= 10 && hracX > 10) //Jestli hrac prekroci pole 100, je vracen zpatky na puvodni pole
        {
            hracX -= hod1;
            printf("Hrac1: Byli jste vraceni na puvodni pole. \nMusite hodit %d pro vyhru.\n", 10 - hracX);
        }
        if (hracY2 >= 10 && hracX2 > 10) //Jestli hrac prekroci pole 100, je vracen zpatky na puvodni pole
        {
            hracX2 -= hod2;
            printf("Hrac2: Byli jste vraceni na puvodni pole. \nMusite hodit %d pro vyhru.\n", 10 - hracX2);
        }


        if (GUI == 'a' || GUI == 'A')
        {
            for (int i = 1; i <= VELIKOSTPLOCHY; i++)
            {
                for (int j = 1; j <= VELIKOSTPLOCHY; j++)
                {
                    if (j == hracX && i == hracY && j == hracX2 && i == hracY2)
                    {
                        printf("%c%c\t", hrac1, hrac2); //Vypis obou hracu
                    }
                    else if (j == hracX && i == hracY)
                    {
                        printf("%c\t", hrac1); //Vypis Hrace1
                    }
                    else if (j == hracX2 && i == hracY2)
                    {
                        printf("%c\t", hrac2); //Vypis Hrace2
                    }
                    else //Vypis poli bez hracu
                    {
                        if (l < 10) //DON'T TOUCH IT JUST WORKS
                        {
                            printf("0%d\t", k);
                            l++;
                        }
                        else
                        {
                            printf("%d\t", k);
                        }
                    }
                    k++;
                }
                printf("\n");
            }
        }

        if (hracX == 10 && hracY == 10) //Podminka pro vyhru, DO NOT REMOVE
        {
            hrac1_vyhra++;
            break;
        }
        if (hracX2 == 10 && hracY2 == 10) //Podminka pro vyhru, DO NOT REMOVE
        {
            hrac2_vyhra++;
            break;
        }

        k = 1; //promena na vypis herni plochy
        pocet_kol++;
    }
    while (k = 1);

    if (hrac1_vyhra == 1)
        printf("Hrac1 vyhral!!!\n");
    if (hrac2_vyhra == 1)
        printf("Hrac2 vyhral!!!\n");

    printf("Hra mela %d kol\n", pocet_kol);

    printf("Chcete hrat znovu?\nJestli ano, zadejte znak 'a', nebo 'Ä́'.\nJestli ne, zadejte libovolny znak.\n");
    scanf(" %c", &hrat_znovu);
    }
    while(hrat_znovu=='a' || hrat_znovu=='A');
    return 0;
}