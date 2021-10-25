#include <iostream>
using namespace std;


int main ()
    {

    int opcion;
    do
    {
        /*setColor(BLACK);
        setBackgroundColor(GREY); - rlutil*/

        cout << "REVENGE" << endl;
        cout << "-----------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS " << endl;
        cout << "3 - CREDITOS " << endl;

        cout << "-----------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "-----------------------" << endl;
        cout << endl << "INGRESE OPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "-----------------------" << endl;


        break;
        case 2:
        cout << "Estadisticas: ";
        break;
        case 3:
        cout << "Creditos: ";
        break;
        }
    break;
    }
    while(opcion!=0);

return 0;
}


