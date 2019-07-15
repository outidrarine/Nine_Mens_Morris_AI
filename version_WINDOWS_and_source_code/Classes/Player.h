#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();
        int alphabeta1(int state[24],int depth,int ismax,int in,int alpha, int beta);
        int minimaxphase2(int state[24],int depth,int ismax, int* dest,int it,int initial[24],int alpha, int beta);
        int minimaxphase3(int state[24],int depth,int ismax, int* dest,int it,int initial[24],int alpha, int beta);


    protected:

    private:
    int finaldepth1;
	int finaldepth2;
	int finaldepth3;
    int nbr_noeuds;


friend class Board;
friend class GameSceneIA;
};

#endif // PLAYER_H
