#include <iostream>
#include <cstdlib>
#include <math.h>
// funkcija  http://www.it.lut.fi/ip/evo/functions/node26.html
// six camel hump function
double sixhump(double *x)
{
    double f = (4- 2.1 * x[0] * x[0] + (pow(x[0],4))/3) * x[0] * x[0] + x[0] * x[1] + (-4+4*x[1]*x[1])*(pow(x[1],2));
    return f;
}

using namespace std;

int main()
{
        struct rezultatai
        {
            double x1;
            double x2;
            double fspr;
            rezultatai *kitas;
        };

    cout << "Monte Carlo realizacijos pradzia" << endl;
    cout << "(RANDOM SEARCH METHOD)" << endl;
    // Kintamuju apsirasymas
    double f, x; // Funkcijos reiksmes ir argumentas x
    int n; // Uzedavinio dimensija
    double fSprendinys=-1.031628453; // Uzdavinio sprendinys
    double epsilon=0.001;
    int budas; //Uzdavinio sprendimo budas
    // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

    double virsutinis_rezis, apatinis_rezis, virsutinis_rezis2, apatinis_rezis2; // apsirasome intervalo rezius

    cout << "Iveskite inervalo rerzius x1: ";
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout << "Iveskite inervalo rerzius x2: ";
    cin >> apatinis_rezis2 >> virsutinis_rezis2;
    cout << "Pasirinkite minimumo ieskojimo buda(1/2): ";
    cin >> budas;
    if(budas==1)
    {
        cout << "Iveskite vektoriaus dimensija (n):";
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
    }
    else if(budas==2)
    {

        rezultatai *r1=NULL, *r2=NULL;

        do
        {
            if(r1==NULL)
            {
                r1=(rezultatai *)malloc(sizeof(rezultatai));
                r2=r1;
            }
            else
            {
                r2->kitas=(rezultatai *)malloc(sizeof(rezultatai));
                r2=r2->kitas;
            }
            r2->x1=rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
            r2->x2=rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
            r2->fspr=(4-2.1*r2->x1 * r2->x1 + (pow(r2->x1,4))/3) * r2->x1 * r2->x1 + r2->x1 * r2->x2 + (-4+4*r2->x2*r2->x2)*(pow(r2->x2,2));
            r2->kitas=NULL;
            cout<<"X1="<<r2->x1<<" X2="<<r2->x2<<" sprend="<<r2->fspr<<endl;
        }
        while(fabs(fSprendinys-(r2->fspr))>epsilon);
        //reikia parasyt while(f_globalus-fmin)<epsilon(0.01 poto 0.001)
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"X1="<<r2->x1<<" X2="<<r2->x2<<" sprend="<<r2->fspr<<endl;
    }
    else
        cout<<"Nekorektiðkai pasirinktas sprendimo budas.";
    return 0;
}
