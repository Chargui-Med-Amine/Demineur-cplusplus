#ifndef  CARREAU_H_INCLUDED
#define  CARREAU_H_INCLUDED
#include <stdio.h>
#include <iostream>
using namespace std;
class carreau
{
private:
    bool est_transparant;//Autour de Monde
    bool est_mine;//Mine ou non(init a false)
    string etat;//(c)cacheé,(d)drapeau,(O)ouvert
    int nb_minevoisin;//init a -1
    bool rec;//pour eviter le boucle infinie lors de l'appel de open_rec
public:
    carreau(): est_mine(false),etat("c"),nb_minevoisin(-1),rec(false),est_transparant(false)
    {
    }
    void set_etat(string e)
    {
        if (e=="o")
            etat="o";
        else{
        if(e=="d")
            etat="d";
    }
    }
    void ajout_mine()
    {
        est_mine=true;
    }
    void set_nb_minevoisins(int n)
    {
        nb_minevoisin=n;
    }
    bool get_est_mine()const
    {
        return est_mine;
    }
    string get_etat()const
    {
        return etat;
    }
    int get_nb_minevoisin()const
    {
        return nb_minevoisin;
    }
     bool get_rec()const
    {
        return rec;
    }
    void set_rec()
    {
        rec=true;
    }
    bool get_est_trans()const
    {
        return est_transparant;
    }
    void set_est_trans(bool b)
    {
        est_transparant=b;
    }
};
#endif
