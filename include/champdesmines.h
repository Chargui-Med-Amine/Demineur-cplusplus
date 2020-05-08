#ifndef CHAMPDESMINES_H_INCLUDED
#define CHAMPDESMINES_H_INCLUDED
#include <iostream>
#include "carreau.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
#include "mini_game.h"

class champdesmines
{
private:
    int d1;
    int d2;
    int nb_mines;
    int R=0;
    carreau** champ;
    string niveau,mode;
public:
    champdesmines()
    {
        do {
            cout << "\t\t\t\tchoisir le niveau (facile/moyenne/dificile)"<<endl;

            cin>>niveau;

        }while (niveau!="facile"&&niveau!="moyenne"&&niveau!="dificile");
        do {

            cout << "\t\t\t\tchoisir le mode de jeux (Pro(p)/Amateur(a))"<<endl;
            cin>>mode;
        }while (mode!="a"&& mode!="p");
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

        champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
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
    void set_R(int i )
    {
        R=-i;
    }
    string get_niveau()
    {
        return(niveau);
    }
    string get_mode()
    {
        return(mode);
    }
     champdesmines(int x) //constructeur pour le tutoriel
    {
        nb_mines =x;
        d1 = 8;
        d2 = 8;
        champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
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
    //constructeur pour autour du monde
    champdesmines(bool b)
    {
        string continant;
        do {
            cout << "choisir le continant : Afrique(af)/Amerique du sud(as)/Europe(e)/Australie(au)/Amerique du nord(an)/Asie(a)"<<endl;
            cout<<"ou jouer dans la Tunisie(t)"<<endl;
            cin>>continant;
        }while (continant!="af"&&continant!="as"&&continant!="e"&&continant!="au"&&continant!="an"&&continant!="a"&&continant!="t");
        if (continant == "af") {

        d1 = 18;
        d2 = 16;
        nb_mines = 25;
        champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][0].set_est_trans(b);
        champ[0][1].set_est_trans(b);
        champ[0][2].set_est_trans(b);
        champ[0][6].set_est_trans(b);
        champ[0][7].set_est_trans(b);
        champ[0][8].set_est_trans(b);
        champ[0][9].set_est_trans(b);
        champ[0][10].set_est_trans(b);
        champ[0][11].set_est_trans(b);
        champ[0][12].set_est_trans(b);
        champ[0][13].set_est_trans(b);
        champ[0][14].set_est_trans(b);
        champ[0][15].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][1].set_est_trans(b);
        champ[1][7].set_est_trans(b);
        champ[1][10].set_est_trans(b);
        champ[1][11].set_est_trans(b);
        champ[1][12].set_est_trans(b);
        champ[1][13].set_est_trans(b);
        champ[1][14].set_est_trans(b);
        champ[1][15].set_est_trans(b);
        //3
        champ[2][0].set_est_trans(b);
        champ[2][11].set_est_trans(b);
        champ[2][12].set_est_trans(b);
        champ[2][13].set_est_trans(b);
        champ[2][14].set_est_trans(b);
        champ[2][15].set_est_trans(b);
        //2
        champ[3][11].set_est_trans(b);
        champ[3][12].set_est_trans(b);
        champ[3][13].set_est_trans(b);
        champ[3][14].set_est_trans(b);
        champ[3][15].set_est_trans(b);
        //5
        champ[4][12].set_est_trans(b);
        champ[4][13].set_est_trans(b);
        champ[4][14].set_est_trans(b);
        champ[4][15].set_est_trans(b);
        //6
        champ[5][13].set_est_trans(b);
        champ[5][15].set_est_trans(b);
        //7
        champ[6][14].set_est_trans(b);
        champ[7][0].set_est_trans(b);
        champ[8][0].set_est_trans(b);
        champ[8][1].set_est_trans(b);
        champ[8][4].set_est_trans(b);
        champ[8][5].set_est_trans(b);
        champ[8][15].set_est_trans(b);
        //10
        champ[9][0].set_est_trans(b);
        champ[9][1].set_est_trans(b);
        champ[9][2].set_est_trans(b);
        champ[9][3].set_est_trans(b);
        champ[9][4].set_est_trans(b);
        champ[9][14].set_est_trans(b);
        champ[9][15].set_est_trans(b);

        champ[10][0].set_est_trans(b);
        champ[10][1].set_est_trans(b);
        champ[10][2].set_est_trans(b);
        champ[10][3].set_est_trans(b);
        champ[10][4].set_est_trans(b);
        champ[10][5].set_est_trans(b);
        champ[10][13].set_est_trans(b);
        champ[10][14].set_est_trans(b);
        champ[10][15].set_est_trans(b);
        champ[11][0].set_est_trans(b);
        champ[11][1].set_est_trans(b);
        champ[11][2].set_est_trans(b);
        champ[11][3].set_est_trans(b);
        champ[11][4].set_est_trans(b);
        champ[11][5].set_est_trans(b);
        champ[11][6].set_est_trans(b);
        champ[11][13].set_est_trans(b);
        champ[11][14].set_est_trans(b);
        champ[11][15].set_est_trans(b);
        champ[12][0].set_est_trans(b);
        champ[12][1].set_est_trans(b);
        champ[12][2].set_est_trans(b);
        champ[12][3].set_est_trans(b);
        champ[12][4].set_est_trans(b);
        champ[12][5].set_est_trans(b);
        champ[12][13].set_est_trans(b);
        champ[13][0].set_est_trans(b);
        champ[13][1].set_est_trans(b);
        champ[13][2].set_est_trans(b);
        champ[13][3].set_est_trans(b);
        champ[13][4].set_est_trans(b);
        champ[13][5].set_est_trans(b);
        champ[13][13].set_est_trans(b);
        champ[13][15].set_est_trans(b);
        champ[14][0].set_est_trans(b);
        champ[14][1].set_est_trans(b);
        champ[14][2].set_est_trans(b);
        champ[14][3].set_est_trans(b);
        champ[14][4].set_est_trans(b);
        champ[14][5].set_est_trans(b);
        champ[14][6].set_est_trans(b);
        champ[14][12].set_est_trans(b);
        champ[14][15].set_est_trans(b);
        champ[15][0].set_est_trans(b);
        champ[15][1].set_est_trans(b);
        champ[15][2].set_est_trans(b);
        champ[15][3].set_est_trans(b);
        champ[15][4].set_est_trans(b);
        champ[15][5].set_est_trans(b);
        champ[15][6].set_est_trans(b);
        champ[15][11].set_est_trans(b);
        champ[15][12].set_est_trans(b);
        champ[15][14].set_est_trans(b);
        champ[15][15].set_est_trans(b);
        champ[16][0].set_est_trans(b);
        champ[16][1].set_est_trans(b);
        champ[16][2].set_est_trans(b);
        champ[16][3].set_est_trans(b);
        champ[16][4].set_est_trans(b);
        champ[16][5].set_est_trans(b);
        champ[16][6].set_est_trans(b);
        champ[16][7].set_est_trans(b);
        champ[16][11].set_est_trans(b);
        champ[16][12].set_est_trans(b);
        champ[16][13].set_est_trans(b);
        champ[16][14].set_est_trans(b);
        champ[16][15].set_est_trans(b);
        champ[17][0].set_est_trans(b);
        champ[17][1].set_est_trans(b);
        champ[17][2].set_est_trans(b);
        champ[17][3].set_est_trans(b);
        champ[17][4].set_est_trans(b);
        champ[17][5].set_est_trans(b);
        champ[17][6].set_est_trans(b);
        champ[17][7].set_est_trans(b);
        champ[17][10].set_est_trans(b);
        champ[17][11].set_est_trans(b);
        champ[17][12].set_est_trans(b);
        champ[17][13].set_est_trans(b);
        champ[17][14].set_est_trans(b);
        champ[17][15].set_est_trans(b);

        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }
        }
        else if(continant == "as") {
            d1 = 11;
            d2 = 9;
            nb_mines = 7;
            champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][2].set_est_trans(b);
        champ[0][3].set_est_trans(b);
        champ[0][4].set_est_trans(b);
        champ[0][5].set_est_trans(b);
        champ[0][6].set_est_trans(b);
        champ[0][7].set_est_trans(b);
        champ[0][8].set_est_trans(b);
        champ[0][9].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][3].set_est_trans(b);
        champ[1][4].set_est_trans(b);
        champ[1][5].set_est_trans(b);
        champ[1][6].set_est_trans(b);
        champ[1][7].set_est_trans(b);
        champ[1][8].set_est_trans(b);
        champ[1][9].set_est_trans(b);
        //3
        champ[2][0].set_est_trans(b);
        champ[2][1].set_est_trans(b);
        champ[2][2].set_est_trans(b);
        champ[2][6].set_est_trans(b);
        champ[2][7].set_est_trans(b);
        champ[2][8].set_est_trans(b);
        champ[2][9].set_est_trans(b);
        //4
        champ[3][0].set_est_trans(b);
        champ[3][1].set_est_trans(b);
        champ[3][7].set_est_trans(b);
        champ[3][8].set_est_trans(b);
        champ[3][9].set_est_trans(b);
        //5
        champ[4][0].set_est_trans(b);
        champ[4][1].set_est_trans(b);
        champ[4][9].set_est_trans(b);
        //6
        champ[5][0].set_est_trans(b);
        champ[5][1].set_est_trans(b);
        champ[5][2].set_est_trans(b);
        champ[5][8].set_est_trans(b);
        champ[5][9].set_est_trans(b);
        //7
        champ[6][0].set_est_trans(b);
        champ[6][1].set_est_trans(b);
        champ[6][2].set_est_trans(b);
        champ[6][3].set_est_trans(b);
        champ[6][8].set_est_trans(b);
        champ[6][9].set_est_trans(b);
        //8
        champ[7][0].set_est_trans(b);
        champ[7][1].set_est_trans(b);
        champ[7][2].set_est_trans(b);
        champ[7][3].set_est_trans(b);
        champ[7][7].set_est_trans(b);
        champ[7][8].set_est_trans(b);
        champ[7][9].set_est_trans(b);
        //9
        champ[8][0].set_est_trans(b);
        champ[8][1].set_est_trans(b);
        champ[8][2].set_est_trans(b);
        champ[8][3].set_est_trans(b);
        champ[8][6].set_est_trans(b);
        champ[8][7].set_est_trans(b);
        champ[8][8].set_est_trans(b);
        champ[8][9].set_est_trans(b);
        //10
        champ[9][0].set_est_trans(b);
        champ[9][1].set_est_trans(b);
        champ[9][2].set_est_trans(b);
        champ[9][5].set_est_trans(b);
        champ[9][6].set_est_trans(b);
        champ[9][7].set_est_trans(b);
        champ[9][8].set_est_trans(b);
        champ[9][9].set_est_trans(b);
        //11
        champ[10][0].set_est_trans(b);
        champ[10][1].set_est_trans(b);
        champ[10][2].set_est_trans(b);
        champ[10][4].set_est_trans(b);
        champ[10][5].set_est_trans(b);
        champ[10][6].set_est_trans(b);
        champ[10][7].set_est_trans(b);
        champ[10][8].set_est_trans(b);
        champ[10][9].set_est_trans(b);
        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }

        }
        else if(continant == "e") {
            d1 = 11;
            d2 = 10;
            nb_mines = 10;
            champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][0].set_est_trans(b);
        champ[0][1].set_est_trans(b);
        champ[0][2].set_est_trans(b);
        champ[0][3].set_est_trans(b);
        champ[0][4].set_est_trans(b);
        champ[0][5].set_est_trans(b);
        champ[0][6].set_est_trans(b);
        champ[0][8].set_est_trans(b);
        champ[0][9].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][1].set_est_trans(b);
        champ[1][2].set_est_trans(b);
        champ[1][3].set_est_trans(b);
        champ[1][4].set_est_trans(b);
        //3
        champ[2][0].set_est_trans(b);
        champ[2][1].set_est_trans(b);
        champ[2][2].set_est_trans(b);
        champ[2][3].set_est_trans(b);
        champ[2][9].set_est_trans(b);
        //4
        champ[3][0].set_est_trans(b);
        champ[3][1].set_est_trans(b);
        champ[3][2].set_est_trans(b);
        champ[3][6].set_est_trans(b);
        //5
        champ[4][0].set_est_trans(b);
        champ[4][2].set_est_trans(b);
        champ[4][3].set_est_trans(b);
        champ[4][6].set_est_trans(b);
        champ[5][2].set_est_trans(b);
        champ[5][3].set_est_trans(b);
        //7
        champ[6][0].set_est_trans(b);
        //8
        champ[7][0].set_est_trans(b);
        champ[7][1].set_est_trans(b);
        //9
        champ[8][3].set_est_trans(b);
        champ[8][8].set_est_trans(b);
        champ[8][9].set_est_trans(b);
        //10
        champ[9][2].set_est_trans(b);
        champ[9][3].set_est_trans(b);
        champ[9][4].set_est_trans(b);
        champ[9][5].set_est_trans(b);
        champ[9][7].set_est_trans(b);
        champ[10][0].set_est_trans(b);
        champ[10][1].set_est_trans(b);
        champ[10][2].set_est_trans(b);
        champ[10][3].set_est_trans(b);
        champ[10][4].set_est_trans(b);
        champ[10][6].set_est_trans(b);
        champ[10][7].set_est_trans(b);
        champ[10][8].set_est_trans(b);
        champ[10][9].set_est_trans(b);

        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }

        }
        else if(continant == "au") {
            d1 = 10;
            d2 = 12;
            nb_mines = 6;
            champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][0].set_est_trans(b);
        champ[0][1].set_est_trans(b);
        champ[0][2].set_est_trans(b);
        champ[0][3].set_est_trans(b);
        champ[0][4].set_est_trans(b);
        champ[0][5].set_est_trans(b);
        champ[0][6].set_est_trans(b);
        champ[0][7].set_est_trans(b);
        champ[0][8].set_est_trans(b);
        champ[0][9].set_est_trans(b);
        champ[0][10].set_est_trans(b);
        champ[0][11].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][1].set_est_trans(b);
        champ[1][2].set_est_trans(b);
        champ[1][3].set_est_trans(b);
        champ[1][4].set_est_trans(b);
        champ[1][6].set_est_trans(b);
        champ[1][7].set_est_trans(b);
        champ[1][8].set_est_trans(b);
        champ[1][9].set_est_trans(b);
        champ[1][10].set_est_trans(b);
        champ[1][11].set_est_trans(b);
        //3
        champ[2][0].set_est_trans(b);
        champ[2][1].set_est_trans(b);
        champ[2][4].set_est_trans(b);
        champ[2][6].set_est_trans(b);
        champ[2][7].set_est_trans(b);
        champ[2][8].set_est_trans(b);
        champ[2][9].set_est_trans(b);
        champ[2][10].set_est_trans(b);
        champ[2][11].set_est_trans(b);
        //4
        champ[3][0].set_est_trans(b);
        champ[3][7].set_est_trans(b);
        champ[3][8].set_est_trans(b);
        champ[3][9].set_est_trans(b);
        champ[3][10].set_est_trans(b);
        champ[3][11].set_est_trans(b);
        //5

        champ[4][8].set_est_trans(b);
        champ[4][9].set_est_trans(b);
        champ[4][10].set_est_trans(b);
        champ[4][11].set_est_trans(b);
        //6
        //champ[5][8].set_est_trans(b);
        champ[5][9].set_est_trans(b);
        champ[5][10].set_est_trans(b);
        champ[5][11].set_est_trans(b);
        //7
        champ[6][2].set_est_trans(b);
        champ[6][3].set_est_trans(b);
        //champ[6][8].set_est_trans(b);
        champ[6][9].set_est_trans(b);
        champ[6][10].set_est_trans(b);
        champ[6][11].set_est_trans(b);
        //8
        champ[7][0].set_est_trans(b);
        champ[7][1].set_est_trans(b);
        champ[7][2].set_est_trans(b);
        champ[7][3].set_est_trans(b);
        champ[7][4].set_est_trans(b);
        champ[7][7].set_est_trans(b);
        champ[7][8].set_est_trans(b);
        champ[7][9].set_est_trans(b);
        champ[7][10].set_est_trans(b);
        //9
        champ[8][0].set_est_trans(b);
        champ[8][1].set_est_trans(b);
        champ[8][2].set_est_trans(b);
        champ[8][3].set_est_trans(b);
        champ[8][4].set_est_trans(b);
        champ[8][5].set_est_trans(b);
        champ[8][6].set_est_trans(b);
        champ[8][7].set_est_trans(b);
        champ[8][8].set_est_trans(b);
        champ[8][9].set_est_trans(b);
        champ[8][11].set_est_trans(b);
        //10
        champ[9][0].set_est_trans(b);
        champ[9][1].set_est_trans(b);
        champ[9][2].set_est_trans(b);
        champ[9][3].set_est_trans(b);
        champ[9][4].set_est_trans(b);
        champ[9][5].set_est_trans(b);
        //champ[9][6].set_est_trans(b);
        champ[9][7].set_est_trans(b);
        champ[9][8].set_est_trans(b);
        champ[9][10].set_est_trans(b);
        champ[9][11].set_est_trans(b);
        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }

        }
        else if(continant == "an") {
            d1 = 12;
            d2 = 14;
            nb_mines = 12;
            champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][0].set_est_trans(b);
        champ[0][1].set_est_trans(b);
        champ[0][2].set_est_trans(b);
        champ[0][3].set_est_trans(b);
        champ[0][4].set_est_trans(b);
        champ[0][8].set_est_trans(b);
        champ[0][9].set_est_trans(b);
        champ[0][12].set_est_trans(b);
        champ[0][13].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][10].set_est_trans(b);
        champ[1][13].set_est_trans(b);
        //3
        champ[2][10].set_est_trans(b);
        champ[2][11].set_est_trans(b);
        champ[2][12].set_est_trans(b);
        champ[2][13].set_est_trans(b);
        //4
        champ[3][0].set_est_trans(b);
        champ[3][1].set_est_trans(b);
        champ[3][2].set_est_trans(b);
        champ[3][9].set_est_trans(b);
        champ[3][10].set_est_trans(b);
        champ[3][13].set_est_trans(b);
        //5
        champ[4][0].set_est_trans(b);
        champ[4][1].set_est_trans(b);
        champ[4][2].set_est_trans(b);
        champ[4][10].set_est_trans(b);
        //6
        champ[5][0].set_est_trans(b);
        champ[5][1].set_est_trans(b);
        champ[5][2].set_est_trans(b);
        champ[5][3].set_est_trans(b);
        champ[5][13].set_est_trans(b);
        //7
        champ[6][0].set_est_trans(b);
        champ[6][1].set_est_trans(b);
        champ[6][2].set_est_trans(b);
        champ[6][3].set_est_trans(b);
        champ[6][12].set_est_trans(b);
        champ[6][13].set_est_trans(b);
        //8
        champ[7][0].set_est_trans(b);
        champ[7][1].set_est_trans(b);
        champ[7][2].set_est_trans(b);
        champ[7][3].set_est_trans(b);
        champ[7][4].set_est_trans(b);
        champ[7][11].set_est_trans(b);
        champ[7][12].set_est_trans(b);
        champ[7][13].set_est_trans(b);
        //9
        champ[8][0].set_est_trans(b);
        champ[8][1].set_est_trans(b);
        champ[8][2].set_est_trans(b);
        champ[8][3].set_est_trans(b);
        champ[8][4].set_est_trans(b);
        champ[8][5].set_est_trans(b);
        champ[8][8].set_est_trans(b);
        champ[8][9].set_est_trans(b);
        champ[8][11].set_est_trans(b);
        champ[8][12].set_est_trans(b);
        champ[8][13].set_est_trans(b);
        //10
        champ[9][0].set_est_trans(b);
        champ[9][1].set_est_trans(b);
        champ[9][2].set_est_trans(b);
        champ[9][3].set_est_trans(b);
        champ[9][4].set_est_trans(b);
        champ[9][5].set_est_trans(b);
        champ[9][6].set_est_trans(b);
        champ[9][9].set_est_trans(b);
        champ[9][10].set_est_trans(b);
        champ[9][11].set_est_trans(b);
        champ[9][12].set_est_trans(b);
        champ[9][13].set_est_trans(b);
        //11
        champ[10][0].set_est_trans(b);
        champ[10][1].set_est_trans(b);
        champ[10][2].set_est_trans(b);
        champ[10][3].set_est_trans(b);
        champ[10][4].set_est_trans(b);
        champ[10][5].set_est_trans(b);
        champ[10][6].set_est_trans(b);
        champ[10][7].set_est_trans(b);
        champ[10][10].set_est_trans(b);
        champ[10][11].set_est_trans(b);
        champ[10][12].set_est_trans(b);
        champ[10][13].set_est_trans(b);
        //12
        champ[11][0].set_est_trans(b);
        champ[11][1].set_est_trans(b);
        champ[11][2].set_est_trans(b);
        champ[11][3].set_est_trans(b);
        champ[11][4].set_est_trans(b);
        champ[11][5].set_est_trans(b);
        champ[11][6].set_est_trans(b);
        champ[11][7].set_est_trans(b);
        champ[11][8].set_est_trans(b);
        champ[11][10].set_est_trans(b);
        champ[11][11].set_est_trans(b);
        champ[11][12].set_est_trans(b);
        champ[11][13].set_est_trans(b);

        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }

        }
        else if(continant == "a") {
            d1 = 13;
            d2 = 14;
            nb_mines = 15;
            champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][0].set_est_trans(b);
        champ[0][1].set_est_trans(b);
        champ[0][2].set_est_trans(b);
        champ[0][3].set_est_trans(b);
        champ[0][4].set_est_trans(b);
        champ[0][5].set_est_trans(b);
        champ[0][6].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][1].set_est_trans(b);
        champ[1][2].set_est_trans(b);
        champ[1][3].set_est_trans(b);
        champ[1][4].set_est_trans(b);
        champ[1][11].set_est_trans(b);
        champ[1][12].set_est_trans(b);
        //3
        champ[2][0].set_est_trans(b);
        champ[2][1].set_est_trans(b);
        champ[2][2].set_est_trans(b);
        champ[2][12].set_est_trans(b);
        champ[2][13].set_est_trans(b);
        champ[3][13].set_est_trans(b);
        champ[6][11].set_est_trans(b);
        champ[6][13].set_est_trans(b);
        //8
        champ[7][0].set_est_trans(b);
        champ[7][10].set_est_trans(b);
        champ[7][11].set_est_trans(b);
        champ[7][13].set_est_trans(b);
        //9
        champ[8][0].set_est_trans(b);
        champ[8][1].set_est_trans(b);
        champ[8][10].set_est_trans(b);
        champ[8][12].set_est_trans(b);
        champ[8][13].set_est_trans(b);
        //10
        champ[9][0].set_est_trans(b);
        champ[9][1].set_est_trans(b);
        champ[9][9].set_est_trans(b);
        champ[9][10].set_est_trans(b);
        champ[9][11].set_est_trans(b);
        champ[9][12].set_est_trans(b);
        champ[9][13].set_est_trans(b);
        //11
        champ[10][9].set_est_trans(b);
        champ[10][11].set_est_trans(b);
        champ[10][12].set_est_trans(b);
        champ[10][13].set_est_trans(b);
        champ[11][3].set_est_trans(b);
        champ[11][4].set_est_trans(b);
        champ[11][9].set_est_trans(b);
        champ[11][5].set_est_trans(b);
        champ[11][10].set_est_trans(b);
        champ[11][12].set_est_trans(b);
        champ[11][13].set_est_trans(b);
        champ[12][0].set_est_trans(b);
        champ[12][4].set_est_trans(b);
        champ[12][5].set_est_trans(b);
        champ[12][6].set_est_trans(b);
        champ[12][8].set_est_trans(b);
        champ[12][9].set_est_trans(b);
        champ[12][10].set_est_trans(b);
        champ[12][11].set_est_trans(b);
        champ[12][12].set_est_trans(b);
        champ[12][13].set_est_trans(b);
        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }

        }
        else if (continant == "t") {

        d1 = 35;
        d2 = 16;
        nb_mines = 40;
        champ=new carreau*[d1];
        for(int i=0;i<d1;i++)
        {
            champ[i]=new carreau[d2];
        }

       //1
        champ[0][0].set_est_trans(b);
        champ[0][1].set_est_trans(b);
        champ[0][2].set_est_trans(b);
        champ[0][3].set_est_trans(b);
        champ[0][4].set_est_trans(b);
        champ[0][5].set_est_trans(b);
        champ[0][10].set_est_trans(b);
        champ[0][11].set_est_trans(b);
        champ[0][12].set_est_trans(b);
        champ[0][13].set_est_trans(b);
        champ[0][14].set_est_trans(b);
        champ[0][15].set_est_trans(b);
        //2
        champ[1][0].set_est_trans(b);
        champ[1][1].set_est_trans(b);
        champ[1][2].set_est_trans(b);
        champ[1][3].set_est_trans(b);
        champ[1][4].set_est_trans(b);
        champ[1][11].set_est_trans(b);
        champ[1][12].set_est_trans(b);
        champ[1][14].set_est_trans(b);
        champ[1][15].set_est_trans(b);
        //3
        champ[2][0].set_est_trans(b);
        champ[2][1].set_est_trans(b);
        champ[2][2].set_est_trans(b);
        champ[2][3].set_est_trans(b);
        champ[2][11].set_est_trans(b);
        champ[2][14].set_est_trans(b);
        champ[2][15].set_est_trans(b);
        //2
        champ[3][0].set_est_trans(b);
        champ[3][1].set_est_trans(b);
        champ[3][2].set_est_trans(b);
        champ[3][13].set_est_trans(b);
        champ[3][14].set_est_trans(b);
        champ[3][15].set_est_trans(b);
        //5
        champ[4][0].set_est_trans(b);
        champ[4][1].set_est_trans(b);
        champ[4][2].set_est_trans(b);
        champ[4][13].set_est_trans(b);
        champ[4][14].set_est_trans(b);
        champ[4][15].set_est_trans(b);
        //6
        champ[5][0].set_est_trans(b);
        champ[5][1].set_est_trans(b);
        champ[5][2].set_est_trans(b);
        champ[5][12].set_est_trans(b);
        champ[5][13].set_est_trans(b);
        champ[5][14].set_est_trans(b);
        champ[5][15].set_est_trans(b);
        //7
        champ[6][0].set_est_trans(b);
        champ[6][1].set_est_trans(b);
        champ[6][2].set_est_trans(b);
        champ[6][12].set_est_trans(b);
        champ[6][13].set_est_trans(b);
        champ[6][14].set_est_trans(b);
        champ[6][15].set_est_trans(b);
        //8
        champ[7][0].set_est_trans(b);
        champ[7][1].set_est_trans(b);
        champ[7][2].set_est_trans(b);
        champ[7][12].set_est_trans(b);
        champ[7][13].set_est_trans(b);
        champ[7][14].set_est_trans(b);
        champ[7][15].set_est_trans(b);
        //9
        champ[8][0].set_est_trans(b);
        champ[8][1].set_est_trans(b);
        champ[8][2].set_est_trans(b);
        champ[8][14].set_est_trans(b);
        champ[8][15].set_est_trans(b);
        //10
        champ[9][0].set_est_trans(b);
        champ[9][1].set_est_trans(b);
        champ[9][2].set_est_trans(b);
        champ[9][14].set_est_trans(b);
        champ[9][15].set_est_trans(b);
        //11
        champ[10][0].set_est_trans(b);
        champ[10][1].set_est_trans(b);
        champ[10][2].set_est_trans(b);
        champ[10][14].set_est_trans(b);
        champ[10][15].set_est_trans(b);
         //12
        champ[11][0].set_est_trans(b);
        champ[11][1].set_est_trans(b);
        champ[11][2].set_est_trans(b);
        champ[11][14].set_est_trans(b);
        champ[11][15].set_est_trans(b);
        //13
        champ[12][0].set_est_trans(b);
        champ[12][1].set_est_trans(b);
        champ[12][2].set_est_trans(b);
        champ[12][13].set_est_trans(b);
        champ[12][14].set_est_trans(b);
        champ[12][15].set_est_trans(b);
        //14
        champ[13][0].set_est_trans(b);
        champ[13][1].set_est_trans(b);
        champ[13][13].set_est_trans(b);
        champ[13][14].set_est_trans(b);
        champ[13][15].set_est_trans(b);
        //15
        champ[14][0].set_est_trans(b);
        champ[14][11].set_est_trans(b);
        champ[14][12].set_est_trans(b);
        champ[14][13].set_est_trans(b);
        champ[14][14].set_est_trans(b);
        champ[14][15].set_est_trans(b);
        //16
        champ[15][10].set_est_trans(b);
        champ[15][11].set_est_trans(b);
        champ[15][12].set_est_trans(b);
        champ[15][13].set_est_trans(b);
        champ[15][14].set_est_trans(b);
        champ[15][15].set_est_trans(b);
        //17
        champ[16][10].set_est_trans(b);
        champ[16][11].set_est_trans(b);
        champ[16][12].set_est_trans(b);
        champ[16][13].set_est_trans(b);
        champ[16][14].set_est_trans(b);
        champ[16][15].set_est_trans(b);
        //18
        champ[17][11].set_est_trans(b);
        champ[17][12].set_est_trans(b);
        champ[17][14].set_est_trans(b);
        champ[17][15].set_est_trans(b);
        //19
        champ[18][14].set_est_trans(b);
        champ[18][15].set_est_trans(b);
        //20
        champ[19][14].set_est_trans(b);
        champ[19][15].set_est_trans(b);
        //21
        champ[20][0].set_est_trans(b);
        //22
        champ[21][0].set_est_trans(b);
        champ[21][1].set_est_trans(b);
        //23
        champ[22][0].set_est_trans(b);
        champ[22][1].set_est_trans(b);
        champ[22][2].set_est_trans(b);
        //24
        champ[23][0].set_est_trans(b);
        champ[23][1].set_est_trans(b);
        champ[23][2].set_est_trans(b);
        //25
        champ[24][0].set_est_trans(b);
        champ[24][1].set_est_trans(b);
        champ[24][2].set_est_trans(b);
        champ[24][3].set_est_trans(b);
        //26
        champ[25][0].set_est_trans(b);
        champ[25][1].set_est_trans(b);
        champ[25][2].set_est_trans(b);
        champ[25][3].set_est_trans(b);
        champ[25][4].set_est_trans(b);
        champ[25][14].set_est_trans(b);
        champ[25][15].set_est_trans(b);
        //27
        champ[26][0].set_est_trans(b);
        champ[26][1].set_est_trans(b);
        champ[26][2].set_est_trans(b);
        champ[26][3].set_est_trans(b);
        champ[26][4].set_est_trans(b);
        champ[26][5].set_est_trans(b);
        champ[26][13].set_est_trans(b);
        champ[26][14].set_est_trans(b);
        champ[26][15].set_est_trans(b);
        //28
        champ[27][0].set_est_trans(b);
        champ[27][1].set_est_trans(b);
        champ[27][2].set_est_trans(b);
        champ[27][3].set_est_trans(b);
        champ[27][4].set_est_trans(b);
        champ[27][5].set_est_trans(b);
        champ[27][12].set_est_trans(b);
        champ[27][13].set_est_trans(b);
        champ[27][14].set_est_trans(b);
        champ[27][15].set_est_trans(b);
        //29
        champ[28][0].set_est_trans(b);
        champ[28][1].set_est_trans(b);
        champ[28][2].set_est_trans(b);
        champ[28][3].set_est_trans(b);
        champ[28][4].set_est_trans(b);
        champ[28][5].set_est_trans(b);
        champ[28][11].set_est_trans(b);
        champ[28][12].set_est_trans(b);
        champ[28][13].set_est_trans(b);
        champ[28][14].set_est_trans(b);
        champ[28][15].set_est_trans(b);
        //30
        champ[29][0].set_est_trans(b);
        champ[29][1].set_est_trans(b);
        champ[29][2].set_est_trans(b);
        champ[29][3].set_est_trans(b);
        champ[29][4].set_est_trans(b);
        champ[29][5].set_est_trans(b);
        champ[29][6].set_est_trans(b);
        champ[29][11].set_est_trans(b);
        champ[29][12].set_est_trans(b);
        champ[29][13].set_est_trans(b);
        champ[29][14].set_est_trans(b);
        champ[29][15].set_est_trans(b);
        //31
        champ[30][0].set_est_trans(b);
        champ[30][1].set_est_trans(b);
        champ[30][2].set_est_trans(b);
        champ[30][3].set_est_trans(b);
        champ[30][4].set_est_trans(b);
        champ[30][5].set_est_trans(b);
        champ[30][6].set_est_trans(b);
        champ[30][11].set_est_trans(b);
        champ[30][12].set_est_trans(b);
        champ[30][13].set_est_trans(b);
        champ[30][14].set_est_trans(b);
        champ[30][15].set_est_trans(b);
         //32
        champ[31][0].set_est_trans(b);
        champ[31][1].set_est_trans(b);
        champ[31][2].set_est_trans(b);
        champ[31][3].set_est_trans(b);
        champ[31][4].set_est_trans(b);
        champ[31][5].set_est_trans(b);
        champ[31][6].set_est_trans(b);
        champ[31][11].set_est_trans(b);
        champ[31][12].set_est_trans(b);
        champ[31][13].set_est_trans(b);
        champ[31][14].set_est_trans(b);
        champ[31][15].set_est_trans(b);
         //33
        champ[32][0].set_est_trans(b);
        champ[32][1].set_est_trans(b);
        champ[32][2].set_est_trans(b);
        champ[32][3].set_est_trans(b);
        champ[32][4].set_est_trans(b);
        champ[32][5].set_est_trans(b);
        champ[32][6].set_est_trans(b);
        champ[32][11].set_est_trans(b);
        champ[32][12].set_est_trans(b);
        champ[32][13].set_est_trans(b);
        champ[32][14].set_est_trans(b);
        champ[32][15].set_est_trans(b);
         //34
        champ[33][0].set_est_trans(b);
        champ[33][1].set_est_trans(b);
        champ[33][2].set_est_trans(b);
        champ[33][3].set_est_trans(b);
        champ[33][4].set_est_trans(b);
        champ[33][5].set_est_trans(b);
        champ[33][6].set_est_trans(b);
        champ[33][7].set_est_trans(b);
        champ[33][10].set_est_trans(b);
        champ[33][11].set_est_trans(b);
        champ[33][12].set_est_trans(b);
        champ[33][13].set_est_trans(b);
        champ[33][14].set_est_trans(b);
        champ[33][15].set_est_trans(b);
         //35
        champ[34][0].set_est_trans(b);
        champ[34][1].set_est_trans(b);
        champ[34][2].set_est_trans(b);
        champ[34][3].set_est_trans(b);
        champ[34][4].set_est_trans(b);
        champ[34][5].set_est_trans(b);
        champ[34][6].set_est_trans(b);
        champ[34][7].set_est_trans(b);
        champ[34][9].set_est_trans(b);
        champ[34][10].set_est_trans(b);
        champ[34][11].set_est_trans(b);
        champ[34][12].set_est_trans(b);
        champ[34][13].set_est_trans(b);
        champ[34][14].set_est_trans(b);
        champ[34][15].set_est_trans(b);

        int cp=0;
        while (cp!=nb_mines)
        {
            int x=rand() % d1;
            int y=rand() % d2;
            if(champ[x][y].get_est_mine()==false&&champ[x][y].get_est_trans()==false)
            {champ[x][y].ajout_mine();
                cp++;
            }
        }
        }


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

    carreau** get_champ()
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
                if(champ[i][j].get_est_trans()==true)
                {
                    cout<<"   "<<" ";
                }
                else if((champ[i][j].get_etat()=="o") && (champ[i][j].get_est_mine()==false) )

                    cout<<"["<<champ[i][j].get_nb_minevoisin()<<"]"<<" ";

                else if(champ[i][j].get_etat()=="d")
                {

                   cout<<"[d]"<<" ";
                    nb_dra++;
                }
                else if((champ[i][j].get_etat()=="o") && (champ[i][j].get_est_mine()==true) )
                {
                    cout<<"[M]"<<" ";

                }
                else{
                    cout<<"[ ]"<<" ";
                }
            }
            cout<<endl<<endl;
        }
        int h=0,m=0,s=0;



        cout<<"######## le nombres des mines restantes est :"<<nb_mines-nb_dra<<" ########"<<endl<<endl<<endl;
        if(mode=="a")
        {
            if(-R>=0)
            {
                cout<<"######## le nombres chance :"<<-R<<" ########"<<endl<<endl<<endl;
            }


        }
        if (compte_ouvert()==nb_carreau()-nb_mines)
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
                if(champ[i][j].get_etat()=="o" || champ[i][j].get_est_trans()==true)
                    k++;
            }
        }
        return k;

    }
    int nb_carreau()
    {
        return d1*d2;
    }
    int get_nb_mines()const
    {
        return nb_mines;
    }
    void dec_nb_mines()
    {
        nb_mines--;
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
            do
          {
            cout<<"choisir un carreau:\nd1= ";
            cin>>h;

          }while( h<0 || h> d1);

          do
          {
            cout<<"d2= ";
            cin>>t;

          }while(t<0 || t> d2);


        }while(champ[h][t].get_est_trans()==true);

        do
        {
             cout<<"quelle est la decision :ouvrir(o) draeau(d) ";
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
            if (champ[h][t].get_est_mine()==true&&d=="o")
            {
                R++;
                dec_nb_mines();
            }
        }


        Affichage();
    }
    void open (int x,int y ,string z) //methode open pour le tutoriel
    {
        int h,t;
        string d;
        do
        {
            cout<<"choisir un carreau: d1=    tapez  "<< x<< endl;
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
            cout<<"quelle est la decision :ouvrir(o) draeau(d)     tapez "<< z <<endl;
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
