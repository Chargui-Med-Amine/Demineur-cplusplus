#ifndef CARRAU_H_INCLUDED
#define CARRAU_H_INCLUDED
#include <stdio.h>
#include <iostream>
using namespace std;
class carrau
{
private:
    bool est_mine;//init a false
    string etat;//(c)cache�,(d)drapeau,(O)ouvert
    int nb_minevoisin;//init a -1
    bool rec;
public:
    carrau(): est_mine(false),etat("c"),nb_minevoisin(-1),rec(false)
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
};
#endif
