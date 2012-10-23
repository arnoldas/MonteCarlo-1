#include <iostream>
#include <cstdlib>
#include <math.h>

// funkcija
double sixhump(double *x)
{
    double f = (4- 2.1 * x[0] * x[0] + (pow(x[0],4))/3) * x[0] * x[0] + x[0] * x[1] + (-4+4*x[1]*x[1])*(pow(x[1],2));
    return f;
}

using namespace std;

int main()
{
    cout << "Monte Carlo realizacijos pradzia" << endl;
    cout << "(RANDOM SEARCH METHOD)" << endl;
    // Kintamuju apsirasymas
    double f, x; // Funkcijos reiksmes ir argumentas x
    int n; // Uzedavinio dimensija
    double xSprendinys; // Argumento reiksme
    int fSprendinys; // Uzdavinio sprendinys

    // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

    double virsutinis_rezis, apatinis_rezis, virsutinis_rezis2, apatinis_rezis2; // apsirasome intervalo rezius

    cout << "Iveskite inervalo rerzius x1: ";
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout << "Iveskite inervalo rerzius x2: ";
    cin >> apatinis_rezis2 >> virsutinis_rezis2;
    cout << "Iveskite vektoriaus ilgi: ";
    cin >> n;

    double vektorius[n], funkcija[200];

    for (int j=0; j<100; j++)
    {

    for(int i=0; i<n; i++)
    {
        if (i == 0)
        {
           vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
           cout << "Skaicius = " << vektorius[i] << endl; // pakeiciau
        }
        else
        {
           vektorius[i] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
           cout << "Skaicius = " << vektorius[i] << endl; // pakeiciau
        }

    }

    cout << "Funkcija = " << sixhump(&vektorius[0]) << endl; // pakeiciau
    cout << "===================================" << endl;
    funkcija[j] = sixhump(&vektorius[0]);
    }

    double min = funkcija[0];
    for (int i=0; i<100; i++)
    {
        if (funkcija[i] < min) min = funkcija[i];
    }
    cout << "MIN: " << min;

    return 0;
}
