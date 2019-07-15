#ifndef BOARD_H
#define BOARD_H
#include"vector"
#include<stdlib.h>
using namespace std;

class Board
{
    public:
        Board();
        Board(int state[24]);
        virtual ~Board();
        void color(int t,int f);
        void drop(int i);
        void drop2(int i);
        void afficher_grille();
        void ingame();
        int heuristique(int player,int* table,int p);
        bool moulinformation(int in, int player,int* table);
        bool validmove(int,int);
        void voisin(int i,vector<int>* v,int state[24],int with);

    protected:

    private:
        int intersection_remplie[24];
        int player=1;
        int times;
        int noir;
        int blanc;
		int database[24];

		friend class GameSceneIA;



friend class Player;
};

#endif // BOARD_H
