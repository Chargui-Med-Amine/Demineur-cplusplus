#include <iostream>
#include <cstdlib>
#include <ctime>
#include "carreau.h"
#include "champdesmines.h"
#include "mini_game.h"
#include <iomanip>
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;
//test
int main()
{
    string type_jeu;
    string decision;
    cout<<"\n\t\t\t\t\t**Bienvenue au Demineur**"<<endl;
    cout<<"\t\t\t\t\t*************************"<<endl;
    cout<<"\n\n\t\t\t\t Vous ne connaissez pas la jeu ? tapez "<<endl;
    cout<<"\n\t\t\t\t\t  oui pour un tutoriel"<<endl;
    cout<<"\n\t\t\t\t\t  non pour continuer"<< endl;
    cin>>decision;
    if (decision=="oui")
    {
        srand((int)time(0));
        auto start = chrono::steady_clock::now();

        champdesmines m(10);
        m.compte_voisins();
        m.Affichage();
        cout<< "on peut commencer par choisir la case (0,0)"<< endl;
        m.open(0,0,"o");
        cout<<"on remarque maitenant que les cases (7,2) et (6,2) sont les voisins d'une seul mine qu'elle peut etre seulement la case (7,3)"<<endl;
        cout<<"on marque alors la case (7,3) par un drapeau"<<endl;
        m.open(7,3,"d");
        cout<<"on remarque maitenant que la case (6,3) est la voisin d'une seul mines qu'elle peut etre seulement la case (7,3) donc la case (7,4)  voisine de (6,3) est sans mine "<<endl;
        cout<<"on ouvre alors la case (7,4) "<<endl;
        m.open(7,4,"o");
        cout<<"on remarque maitenant que la case (7,4) est la voisin d'une seul mines qu'elle peut etre seulement la case (7,3) donc la case (7,5)  voisine de (7,4) est sans mine "<<endl;
        cout<<"on ouvre alors la case (7,5) "<<endl;
        m.open(7,5,"o");
        cout<<"on remarque maitenant que la case (6,4) est entouré par deux mine une mine deja marque dans la case (7,3) et une autre ne peut être que la case (5,5)  "<<endl;
            cout<<" on marque alors la case (5,5) par un drapeau "<<endl;
            m.open(5,5,"d");
        cout<<"le tutoriel est finie termine le jeu  "<<endl;
        while ((m.get_res()!=1)&&(m.compte_ouvert()!=m.nb_carreau()-m.get_nb_mines()))
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




    }
    if (decision=="non")
    {
        do
        {
             cout<<"                     Vous voulez jouer demineur classique(c) ou autour du monde(s)"<<endl;
             cin>>type_jeu;

        }while(type_jeu!="c"&&type_jeu!="s");

    if(type_jeu=="s")
    {
        srand((int)time(0));
    champdesmines m(true);
    m.compte_voisins();
    m.Affichage();

    auto start = chrono::steady_clock::now();
    while ((m.get_res()!=1)&&(m.compte_ouvert()!=m.nb_carreau()-m.get_nb_mines()))
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
		m.score((chrono::duration_cast<chrono::seconds>(end - start).count()),m.get_res());
    }


    else
    {

    srand((int)time(0));
    champdesmines m;
    if(m.get_mode()=="a")
    {
        if (m.get_niveau() == "facile")
            {Quiz b(3);
            b.affiche();
             m.set_R(b.get_chance());
            }
        else if (m.get_niveau() == "moyenne")
        {
            Quiz b(5);
            b.affiche();
             m.set_R(b.get_chance());

        }
        else if (m.get_niveau() == "dificile")
        {
            Quiz b(7);
            b.affiche();
            m.set_R(b.get_chance());

        }

    }
    m.compte_voisins();
    m.Affichage();

    auto start = chrono::steady_clock::now();
    while ((m.get_res()!=1)&&(m.compte_ouvert()!=m.nb_carreau()-m.get_nb_mines()))
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
		m.score((chrono::duration_cast<chrono::seconds>(end - start).count()),m.get_res());
    }
    }



    return 0;
}
