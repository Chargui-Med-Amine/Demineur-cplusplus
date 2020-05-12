#ifndef MINI_GAME_H_INCLUDED
#define MINI_GAME_H_INCLUDED
#include <iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include"champdesmines.h"
#include"carreau.h"
using namespace std;
class Reponse
{

    string rep;
    bool est_juste;
public:
    Reponse(string r,bool v):rep(r),est_juste(v)
    {

    }
    Reponse():rep(""),est_juste(false)
    {

    }
    bool get_est_juste()
    {
        return(est_juste);
    }
    string get_rep()
    {
        return(rep);
    }

};
class Question
{
    string qs;
    bool ok=false;//l'etat de qs (ouvert ou pas encorse)
    Reponse T[3];

public:


    Question(string q ,string r0,string r1, string r2,int t[] )
    {


        qs = q;
        Reponse rep1(r0,true);
        Reponse rep2(r1,false);
        Reponse rep3(r2,false);

            T[t[0]]=rep1;
            T[t[1]]=rep2;
            T[t[2]]=rep3;



    }

    Question()
    {
        qs="";

    }
    string get_qs()
    {
        return(qs);
    }
    Reponse get_T(int i)
    {
        return(T[i]);
    }
    bool get_ok()
    {
        return(ok);
    }
    void set_ok(bool i)
    {
        ok=i;
    }
    bool verif(int i,int T[],int n)
    {
             for(int j=0;j<n;j++)
             {
                 if( i==T[j])
                    return(true);

             }
             return(false);
         }
    void Tableau(int t[],int n)
    {
        int x;
        int i=0;
        //srand((int)time(0));
        while(i<n)

        {
            do
          {
            x=rand() % n;

          }while (verif( x ,t ,i));
            t[i]=x;
            i++;
        }


    }

};
class Quiz :  public Question
{   int nbr_qs=0;
    int taille=0;
    int ch=0;//chances

public:
    Question*Q;

    Quiz(int k)
    {

        ifstream file("Question_liste.txt");
        string input;
        vector<string> L;
        while(file >>input)
        {
            L.push_back(input);
        }
        nbr_qs = L.size()/4;
        taille=k;
        int t[nbr_qs];

        Q= new Question[nbr_qs];
        srand((int)time(0));
        Tableau(t,nbr_qs);//alea de qs
        for(int i=0;i<nbr_qs;i++)
            {
                int a[3];
                Tableau(a,3);
                Q[i]=Question(L[t[i]*4],L[t[i]*4+1],L[t[i]*4+2],L[t[i]*4+3],a);
            }



    }
    int get_chance()const
    {
        return(ch);
    }


    void aff_Quiz()
    {

        system("cls");
        int i,j;
        cout<<endl<<endl;
        cout<<"\t\t\tCe Quiz est un moyen pour avoir plus de chance au jeu de demineur classique\n";
        cout<<"\t\t\ta chaque iteration il est demande au joueur de repondre a une question si\n";
        cout<<"\t\t\treponse est juste il gagne une chance qu'il l'utilise au jeu principale\n";
        cout<<"\t\t\t\t\t ****une seule reponse est juste****\n";
        cout<<endl<<endl;

        for(i=0;i<taille;i++)
        {
            cout<<"\t\t\t\t\t\t\t";
            if(Q[i].get_ok())
            {

                for(int j=0;j<3;j++)
            {
                if (Q[i].get_T(j).get_est_juste())
                    cout<<"[V]";
                else
                    cout<<"[F]";
            }
            cout<<endl;
            }
            else
            {
                for(int l=0;l<3;l++)
                {
                   cout<<"["<<l<<"]";
                }
                cout<<endl;

            }

        }


        cout<<endl;
        cout<<"\t\t\t\tVous avez  "<<ch<<" chance(s)"<<endl;
    }
    void open(int i)
    {
        int R;

        Q[i].set_ok(true);
        cout<<"\t\t\t\t"<<Q[i].get_qs()<<" ?"<<endl;
        cout<<"\t\t\t\t1) "<<Q[i].get_T(0).get_rep()<<endl;
        cout<<"\t\t\t\t2) "<<Q[i].get_T(1).get_rep()<<endl;
        cout<<"\t\t\t\t3) "<<Q[i].get_T(2).get_rep()<<endl;
        do
        {
            cout<<"\t\t\t\tvotre reponse : ";
            cin>>R;

        }while(R!=1&&R!=2&&R!=3);
        if (Q[i].get_T(R-1).get_est_juste())
        {
            ch++;
        }
        aff_Quiz();
    }
    void affiche()
    {

        aff_Quiz();



        for(int i=0;i<taille;i++)
        {

            open(i);

        }
    }

    ~Quiz()
    {
        delete[] Q;
    }

};



#endif // MINI_GAME_H_INCLUDED
