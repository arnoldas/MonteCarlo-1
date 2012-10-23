#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double sixhump(double *x)
{
    double f=(4-2.1*pow(x[0],2)+pow(x[0],4)/3)*pow(x[0],2)+x[0]*x[1]+(-4+4*pow(x[1],2))*pow(x[1],2);
    return f;
}

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

    double virsutinis_rezis, apatinis_rezis; // apsirasome intervalo rezius

    cout << "Iveskite inervalo apatini ir virsutini rezius:" << endl;
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout << "Iveskite vektoriaus dimensija (n):" << endl;
    cin >> n;

    double vektorius[n];
    cout<<"x = ( ";
    for(int i=0; i<n; i++)
    {
        vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
        cout << vektorius[i]<<" "; // Vektoriaus isvedimas i ekrana
    }
    cout<<")\n";
    cout<<"Funkcijos sixhump reiksme taske: "<<sixhump(&vektorius[0])<<endl;
    //pasitikrinimui funkcijos reiksme minimumo taske
    vektorius[0]=0.089842;
    vektorius[1]=-0.712656;
    cout<<"Funkcijos sixhump reiksme minimumo taske: "<<sixhump(&vektorius[0])<<endl;
    return 0;
}
