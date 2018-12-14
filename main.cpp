#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include "TEXT.h"
#include "EVKD.h"



int main()
{
    char * test1 = "Schmitz, Anna";
    char * test2 = "Schmitz, Thorsten";
    int str = strcmp(test1, test2);
    printf ("Ergebnis strcmp: %d\n",str);
    EVKD testobj1=EVKD(test1);
    EVKD testobj2=EVKD(test2);
    str = strcmp(testobj1.getDaten(), testobj2.getDaten());
    printf ("Ergebnis von objekt-bezogenem strcmp: %d\n", str);
    bool str2;    str2 = (testobj1 > testobj2);
    printf ("Ergebnis von Methode: %d\n", str2);
    return 0;
}
