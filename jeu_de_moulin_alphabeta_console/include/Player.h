#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();
        int alphabeta1(int state[24],int depth,int ismax,int in,int alpha, int beta);
        int alphabeta2(int state[24],int depth,int ismax, int* dest,int it,int initial[24],int alpha, int beta);
        int alphabeta3(int state[24],int depth,int ismax, int* dest,int it,int initial[24],int alpha, int beta);


    protected:

    private:
    int finaldepth;
    int nbr_noeuds;


friend class Board;
};

#endif // PLAYER_H
