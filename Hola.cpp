#include <iostream>

#include <fstream>

using namespace std;

int main()
{
const int dimfil = 8;

const int dimcol = 5;

string vec[dimfil];

string voc[dimcol];

ifstream archilec;
archilec.open ("Datos.txt");

ifstream archiNom;
archiNom.open("Nombres.txt");

if (!archiNom)
{
    cout << "no se abrió perro";
return 1;
}

if(!archilec)
{
    cout << "no se abrió perro";
return 1;
}

for (int i = 0; i < dimfil && archiNom>>vec[i]; i++)
{}

for (int i = 0; i < dimcol && archiNom>>voc[i]; ++i)
{}

int k;
int z {0};
int c;
int pr;
float pe;
float kil;
float sum[dimfil][dimcol] {0};
float sum1[dimfil][dimcol] {0};
int cant[dimfil] {0};
int max {0};
int max1 {0};
int compa {0};
int compa1 {0};
int conteo[dimcol] {0};

while ( archilec>>c>>pr>>pe>>kil)
{
sum[c][pr] += pe;
sum1[c][pr] += kil;
conteo[pr]++; 
}

for (int i = 0; i < dimfil ; i++)
{
    cout<<vec[i]<<": ";
        for( int j = 0; j < dimcol ; j++)
        {
             if (sum[i][j] > 13000)
             {
             cout<<voc[j]<<", ";
             cant[i]++;
             } 
        }
    cout<<endl;
    if (cant[i]>max)
    {
    max = cant[i];
    compa = i;
    }
}
cout<<vec[compa]<<":"<<endl<<endl;

for (int i = 0; i < dimcol; i++)
{

if (sum1[compa][i]>max1)
    {
    max1 = sum1[compa][i];
    compa1 = i;
    }
}
cout<<"Cantidad de producto con mayor recorrido: "<<voc[compa1]<<": "<<conteo[compa1]<<endl;

archiNom.close();
archilec.close();
return 0;
}
