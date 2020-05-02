#ifndef CHAMPDESMINES_H_INCLUDED
#define CHAMPDESMINES_H_INCLUDED
#include <iostream>
#include "carrau.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>

class champdesmines
{
private:
    int d1;
    int d2;
    int nb_mines;
    int R;
    carrau** champ;
    string niveau;
public:
    champdesmines()
    {
        do {
            cout << "choisir le niveau (facile/moyenne/dificile)";
            cin>>niveau;
        }while (niveau!="facile"&&niveau!="moyenne"&&niveau!="dificile");
        if (niveau == "facile") {

            d1 = 8;
            d2 = 8;
            nb_mines = 10;

        }

        else if (niveau == "moyenne") {

            d1 = 16;
            d2 = 16;
            nb_mines = 40;
        }
        else if (niveau == "dificile") {
            d1 = 30;
            d2 = 16;
            nb_mines = 99;
        }

        champ=new carrau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carrau[d2];
        }
        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }
    }
     champdesmines(int x) //constructeur pour le tutoriel
    {
        nb_mines =x;
        d1 = 8;
        d2 = 8;
        champ=new carrau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carrau[d2];
        }
        champ[0][3].ajout_mine();
        champ[0][5].ajout_mine();
        champ[1][4].ajout_mine();
        champ[3][4].ajout_mine();
        champ[5][5].ajout_mine();
        champ[7][3].ajout_mine();
        champ[2][6].ajout_mine();
        champ[7][7].ajout_mine();
        champ[1][6].ajout_mine();
        champ[4][6].ajout_mine();

    }


    void compte_voisins()
    {
        for(int i=0;i<d1;i++)
        {
            for(int j=0;j<d2;j++)
            {
                if(champ[i][j].get_est_mine()==false)
                {

                    int deb1=std::max(0,i-1);
                    int deb2=std::max(0,j-1);
                    int fin1=std::min(d1-1,i+1);
                    int fin2=std::min(d2-1,j+1);
                    int cpt=0;

                    for(int x=deb1;x<=fin1;x++)
                    {
                        for(int y=deb2;y<=fin2;y++)
                        {
                            if(champ[x][y].get_est_mine()==true)
                                cpt++;
                        }
                    }
                    champ[i][j].set_nb_minevoisins(cpt);
                }

            }
        }
    }

    carrau** get_champ()
    {
        return champ ;
    }

    void Affichage()
    {
        system("cls");
        int nb_dra=0;
        int i,j;

        for(int l=0;l<d2;l++)
        {
            if(l<10)
                cout<<"   "<<l;
            else
                cout<<"  "<<l;
        }
        cout<<endl;
        for(i=0;i<d1;i++)
        {
            if(i<10)
                cout<<i<<" ";
            else
                cout <<i;
            for(j=0;j<d2;j++)

            {
                if((champ[i][j].get_etat()=="o") && (champ[i][j].get_est_mine()==false) )

                    cout<<"["<<champ[i][j].get_nb_minevoisin()<<"]"<<" ";

                else if(champ[i][j].get_etat()=="d")
                {

                    cout<<"[d]"<<" ";
                    nb_dra++;
                }
                else if((champ[i][j].get_etat()=="o") && (champ[i][j].get_est_mine()==true) )
                {
                    cout<<"[M]"<<" ";
                    R=1;
                }
                else{
                    cout<<"[ ]"<<" ";
                }
            }
            cout<<endl<<endl;
        }
        int h=0,m=0,s=0;



        cout<<"######## le nombres des mines restantes est :"<<nb_mines-nb_dra<<" ########"<<endl<<endl<<endl;
        if (compte_ouvert()==nb_carrau()-nb_mines)
        {

            cout<<endl<<"-------      /\\      -------   |\\    |   ------      "<<endl;
            cout<<"|           /  \\     |         | \\   |   |           "<<endl;
            cout<<"| |---|    /----\\    | |---|   |  \\  |   |-----      "<<endl;
            cout<<"|     |   /      \\   |     |   |   \\ |   | "<<endl;
            cout<<"-------  /        \\  -------   |    \\|   ------      \a \a"<<endl<<endl<<endl;
        }
    }
    int get_res()const
    {
        return R;
    }
    int compte_ouvert()
    {
        int k=0;
        for(int i=0;i<d1;i++)
        {
            for(int j=0;j<d2;j++)
            {
                if(champ[i][j].get_etat()=="o")
                    k++;
            }
        }
        return k;

    }
    int nb_carrau()
    {
        return d1*d2;
    }
    int get_nb_mines()const
    {
        return nb_mines;
    }
    void aff_lose()
    {
     for(int i=0;i<d1;i++)
        {
            for(int j=0;j<d2;j++)

            {
                if(champ[i][j].get_est_mine()!=false)
                    champ[i][j].set_etat("o");
            }
        }
    }
    void open ()
    {
        int h,t;
        string d;
        do
        {
            cout<<"choisir un carrau: d1="<<endl;
            cin>>h;

        }
        while( h<0 || h> d1);
        do
        {
            cout<<"d2="<<endl;
            cin>>t;

        }
        while(t<0 || t> d2);
        do
        {
             cout<<"quelle est la decision :ouvrir(o) drapau(d)"<<endl;
             cin>>d;

        }
        while(d != "o"&&d != "d");
        if(d=="o" && (champ[h][t].get_nb_minevoisin()==0 ))
        {
            open_rec(h,t);
        }

        else
        {
            champ[h][t].set_etat(d);
        }


        Affichage();
    }
    void open (int x,int y ,string z) //methode open pour le tutoriel
    {
        int h,t;
        string d;
        do
        {
            cout<<"choisir un carrau: d1=    tapez  "<< x<< endl;
            cin>>h;

        }
        while( h!=x);
        do
        {
            cout<<"d2=   tapez   " <<y << endl;
            cin>>t;

        }
        while(t!=y);
        do
        {
            cout<<"quelle est la decision :ouvrir(o) drapau(d)     tapez "<< z <<endl;
            cin>>d;

        }
        while(d != z);
        if(d=="o" && (champ[h][t].get_nb_minevoisin()==0 ))
        {
            open_rec(h,t);
        }

        else
        {
            champ[h][t].set_etat(d);
        }


        Affichage();
    }


    void open_rec(int i,int j)
    {
        champ[i][j].set_rec();
        champ[i][j].set_etat("o");
        int deb1=std::max(0,i-1);
        int deb2=std::max(0,j-1);
        int fin1=std::min(d1-1,i+1);
        int fin2=std::min(d2-1,j+1);

        for(int x=deb1;x<=fin1;x++)
        {
            for(int y=deb2;y<=fin2;y++)
            {
                champ[x][y].set_etat("o");
                if((champ[x][y].get_nb_minevoisin()==0) && (champ[x][y].get_rec()==false) )
                {
                    open_rec(x,y);
                }


            }
        }
    }
    void score(int new_score,int r)
    {
    std::ifstream score ("score.txt");
    std::vector<int> v;
    int n;
    while(score >> n)
    {
        v.push_back(n);
    }
    if(r!=1)
    {


    std::ofstream score2 ("score.txt");
    if (niveau=="facile" && v[0]>new_score)
    {
        v[0]=new_score;
        cout<<"###### Bravo , nouveau meilleur score pour la difficulte "<<niveau<<" : [ "<< std::setw(2) << std::setfill('0')
		<< new_score/60<<  ":"<< std::setw(2) << std::setfill('0')<<new_score%60<<" ]  ######" <<endl;

    }
    else if(niveau=="moyenne" && v[1]>new_score)
    {
        v[1]=new_score;
        cout<<"###### Bravo , nouveau meilleur score pour la difficulte "<<niveau<<" : [ "<< std::setw(2) << std::setfill('0')
		<< new_score/60<<  ":"<< std::setw(2) << std::setfill('0')<<new_score%60<<" ]  ######" <<endl;

    }
    else if(niveau=="dificile" && v[1]>new_score)
    {
        v[2]=new_score;
        cout<<"###### Bravo , nouveau meilleur score pour la difficulte "<<niveau<<" : [ "<< std::setw(2) << std::setfill('0')
		<< new_score/60<<  ":"<< std::setw(2) << std::setfill('0')<<new_score%60<<" ]  ######" <<endl;
    }
    for(int n:v)
    {
        score2 <<n<<endl;
    }
    score2.close();
    }
    else
    {
        if (niveau=="facile")
    {

        cout<<"###### Le meilleur score pour la difficulte "<<niveau<<" est : [ "<< std::setw(2) << std::setfill('0')
		<< v[0]/60<<  ":"<< std::setw(2) << std::setfill('0')<<v[0]%60<<" ]  ######" <<endl;

    }
    else if(niveau=="moyenne")
    {
        cout<<"###### Le meilleur score pour la difficulte "<<niveau<<" est : [ "<< std::setw(2) << std::setfill('0')
		<< v[1]/60<<  ":"<< std::setw(2) << std::setfill('0')<<v[1]%60<<" ]  ######" <<endl;

    }
    else if(niveau=="dificile")
    {
        cout<<"###### Le meilleur score pour la difficulte "<<niveau<<" est : [ "<< std::setw(2) << std::setfill('0')
		<< v[2]/60<<  ":"<< std::setw(2) << std::setfill('0')<<v[2]%60<<" ]  ######" <<endl;
    }
    }

    }

    ~champdesmines()
    {
        delete[] champ;
    }






};


#endif // CHAMPDESMINES_H_INCLUDED
