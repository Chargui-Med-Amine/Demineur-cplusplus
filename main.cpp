#include <iostream>
#include <cstdlib>
#include <ctime>
#include "carrau.h"
#include "champdesmines.h"
#include <iomanip>
#include <chrono>
using namespace std;

int main()
{


    champdesmines m;
    m.compte_voisins();



    m.Affichage();
    while ((m.get_res()!=1)&&(m.compte_ouvert()!=m.nb_carrau()-m.get_nb_mines()))
    {
        m.open();

    }

    if((m.get_res()==1))
    {
        m.aff_lose();
        m.Affichage();
        cout<<endl<<endl<<"-----   -----  -----   -----   |    | "<<endl;
        cout<<"|    |  |      |    |  |    \\  |    | "<<endl;
        cout<<"|----   |----  |----   |    |  |    | "<<endl;
        cout<<"|       |      |   \\   |    /  |    | "<<endl;
        cout<<"|       -----  |    \\  -----   ------ \a"<<endl<<endl<<endl;


    }



    return 0;
}
