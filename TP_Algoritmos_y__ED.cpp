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
    cout << "no se abrió";
return 1;
}

if(!archilec)
{
    cout << "no se abrió";
return 1;
}

for (int i = 0; i < dimfil && archiNom>>vec[i]; i++)
{}

for (int i = 0; i < dimcol && archiNom>>voc[i]; ++i)
{}

int cliente;
int producto;
float peso;
float kilos;
int maximo {0};
int maximo2 {0};
int comparacion {0};
int comparacion2 {0};
int cantidad[dimfil] {0};
int conteo[dimcol] {0};
float suma[dimfil][dimcol] {0};
float suma2[dimfil][dimcol] {0};

while ( archilec>>cliente>>producto>>peso>>kilos)
{
suma[cliente][producto] += peso;
suma2[cliente][producto] += kilos;
conteo[producto]++; 
}
cout<<"Clientes con productos que superan los 13.000 kg: "<<endl;
for (int i = 0; i < dimfil ; i++)
{
    cout<<vec[i]<<": ";
        for( int j = 0; j < dimcol ; j++)
        {
             if (suma[i][j] > 13000)
             {
             cout<<voc[j]<<", ";
             cantidad[i]++;
             } 
        }
    cout<<"Cantidad: "<<cantidad[i]<<endl;
    if (cantidad[i]>maximo)
    {
    maximo = cantidad[i];
    comparacion = i;
    }
}
cout<<endl<<"Kilometros recorridos por cada producto del Cliente elegido, "<<vec[comparacion]<<":"<<endl;

for (int i = 0; i < dimcol; i++)
{
    for (int j = 1; j < dimcol; j++)
    {
        if(suma2[comparacion][j]<suma2[comparacion][j-1])
        {
        swap(suma2[comparacion][j],suma2[comparacion][j-1]);
        swap(voc[j],voc[j-1]);
        swap(conteo[j],conteo[j-1]);
        }
    }
cout<<voc[i]<<": "<<suma2[comparacion][i]<<endl;

if (suma2[comparacion][i]>maximo2)
    {
    maximo2 = suma2[comparacion][i];
    comparacion2 = i;
    }
}
cout<<endl<<"Cantidad de producto con mayor recorrido: "<<voc[comparacion2]<<": "<<conteo[comparacion2]<<endl;

archiNom.close();
archilec.close();
return 0;
}
