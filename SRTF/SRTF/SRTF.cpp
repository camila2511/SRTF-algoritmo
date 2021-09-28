// SRTF.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int main()
{
    int a[10], b[10], x[10];
    int espera[10], tiemporespuesta[10], finalizacion[10];
    int i, j, smallest, count = 0, tiempo, n;
    double promedio = 0, tr = 0, end;

    cout << "\nIngrese la cantidad de procesos: ";  //input
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nIngrese el Tiempo de Llegada del Proceso: ";  //input
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "\nIngrese el tiempo de rafaga del proceso: ";  //input
        cin >> b[i];
    }
    for (i = 0; i < n; i++)
        x[i] = b[i];

    b[9] = 9999;
    for (tiempo = 0; count != n; tiempo++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= tiempo && b[i] < b[smallest] && b[i]>0)
                smallest = i;
        }
        b[smallest]--;

        if (b[smallest] == 0)
        {
            count++;
            end = tiempo + 1;
            finalizacion[smallest] = end;
            espera[smallest] = end - a[smallest] - x[smallest];
            tiemporespuesta[smallest] = end - a[smallest];
        }
    }
    cout << "Proceso" << "\t" << "Tiempo_Rafaga" << "\t" << "Tiempo_Llegada" << "\t" << "Tiempo_Espera" << "\t" << "Tiempo_Respuesta" << "\t" << "Tiempo_Finalizacion" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << espera[i] << "\t\t" << tiemporespuesta[i] << "\t\t" << finalizacion[i] << endl;
        promedio = promedio + espera[i];
        tr = tr + tiemporespuesta[i];
    }
    cout << "\n\nPromedio Tiempo Espera =" << promedio / n;
    cout << "  Promedio Tiempo Finalizacion =" << tr / n << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
