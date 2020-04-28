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

    srand((int)time(0));
    auto start = chrono::steady_clock::now();

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
    auto end = chrono::steady_clock::now();

	cout << "###### Temps ecoule : [ "<< std::setw(2) << std::setfill('0')
		<< (chrono::duration_cast<chrono::seconds>(end - start).count())/60
		<<  ":"<< std::setw(2) << std::setfill('0')<<(chrono::duration_cast<chrono::seconds>(end - start).count())%60
		<<" ]  ######" <<endl;



    return 0;
}
