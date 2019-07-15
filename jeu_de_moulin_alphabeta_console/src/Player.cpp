#include "Player.h"
#include"Board.h"
#include"vector"
#include <algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
Player::Player()
{
    finaldepth=4;//leave this on 4 after testes
    nbr_noeuds=0;
}

Player::~Player()
{
    //dtor
}
//minimax de la premiere phase du jeu
int Player::alphabeta1(int state[24],int depth,int ismax,int in,int alpha, int beta)
{
    Board table(state);
    if(depth==1)
    {
        if(table.moulinformation(in,-1,state))
            return 2000;
        if(table.moulinformation(in,1,state))
            return 1000;
    }

    if(depth!=0)
    {
        if(table.moulinformation(in,-1,state))
            return 400/depth;
    }
    if(depth==finaldepth)
    {
        return (100*table.heuristique(-1,state,0)-50*table.heuristique(1,state,0));
    }



    int save[24];
    int scores[24];
    for(int i=0;i<24;i++)
    {
        save[i]=state[i];
        scores[i]=-9999;
    }
    if(ismax==1)
    {
        int bestValue = +10000000; // PLUS INFINI
        vector<int> fils;
        for(int i=0;i<24;i++)
        {
            if(state[i]==0)
            {
                state[i]=1;
                //
                if(table.moulinformation(i,1,state))
                for(int i=0;i<24;i++)
                {
                    if(state[i]==0&&table.moulinformation(i,-1,state))
                    {
                        vector<int> v;
                        table.voisin(i,&v,table.intersection_remplie,-1);
                         vector<int>::iterator it;
                            for (it = v.begin(); it != v.end(); it++)
                            {
                               table.intersection_remplie[*it]=0;
                            }
                        break;
                    }
                }
                //
                int son=alphabeta1(state,depth+1,-1,i,alpha,beta);
                fils.push_back(son);
                state[i]=0;
                scores[i]=son;
                nbr_noeuds++;




                bestValue = min( bestValue, son);
                    beta = min( beta, bestValue);
                    if (beta<alpha)
                        break;
            }
        }
        for(int j=0;j<24;j++)
        {
            if(scores[j]==*min_element(fils.begin(),fils.end()))
                if(depth==0)
                    {
                    cout<<"ma value : "<<scores[j];
                    return j;
                    }
            else  {
                return scores[j];
            }
        }
    }else if(ismax==-1)
    {
        int bestValue = -10000000; // MOINS INFINI
        vector <int> fils;
        for(int i=0;i<24;i++)
        {
            if(state[i]==0)
            {
                state[i]=-1;
                    //
                if(table.moulinformation(i,-1,state))
                for(int i=0;i<24;i++)
                {
                    if(state[i]==0&&table.moulinformation(i,1,state))
                    {
                        vector<int> v;
                        table.voisin(i,&v,table.intersection_remplie,1);
                         vector<int>::iterator it;
                            for (it = v.begin(); it != v.end(); it++)
                            {
                               table.intersection_remplie[*it]=0;
                            }
                        break;
                    }
                }
                //
                int son=alphabeta1(state,depth+1,1,i,alpha,beta);
                fils.push_back(son);
                state[i]=0;
                scores[i]=son;
                nbr_noeuds++;


                bestValue = max( bestValue, son);
                    alpha = max( alpha, bestValue);
                    if (beta<alpha)
                        break;
            }
        }
        for(int j=0;j<24;j++)
        {
            if(scores[j]==*max_element(fils.begin(),fils.end()))
                if(depth==0)
                {
                    cout<<"ma value : "<<scores[j];
                    return j;
                }

            else{
                return scores[j];
            }
        }
    }

}
//minimax de la deuxieme phase du jeu
int Player::alphabeta2(int state[24],int depth,int ismax,int* dest, int it,int* initial,int alpha, int beta)
{
    Board table(state);
   //     if(depth==1)
   //         return (100*table.moulinformation(it,-1,state));


    if(table.moulinformation(it,-1,state)&&depth!=0)
        return 1000/depth;
    if(depth==finaldepth)
        return (3*table.heuristique(-1,state,-1));


    int save[24];
    int scores[24][4];
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<4;j++)
        {
            save[i]=state[i];
            scores[i][j]=-9999;
        }
    }
    if(ismax==1)
    {
        int bestValue = -10000000; // MOINS INFINI
        vector<int> fils;
        for(int i=0;i<24;i++)
        {
            if(state[i]==1)
            {
                vector<int> v;
                table.voisin(i,&v,state,0);
                vector<int>::iterator it;
                int pos=0;
                for (it = v.begin(); it != v.end(); it++)
                {
                    state[*it]=1;
                    state[i]=0;
                    int son=alphabeta2(state,depth+1,-1,dest,*it,initial,alpha,beta);
                    fils.push_back(son);
                    state[i]=1;
                    state[*it]=0;
                    scores[i][pos]=son; //problem
                    pos++;
                    nbr_noeuds++;


                    bestValue = max( bestValue, son);
                    alpha = max( alpha, bestValue);
                    if (beta<alpha)
                        break;
                }
            }
        }
        for(int j=0;j<24;j++)
        {
            vector<int> v;
            table.voisin(j,&v,state,0);
            int k=0;
             vector<int>::iterator it;
            for (it = v.begin(); it != v.end(); it++)
            {
                if(scores[j][k]==*min_element(fils.begin(),fils.end()))
                    if(depth==0)
                    {
                        *dest=*it;
                       // cout<<" meeee "<<scores[j][k]<<" "<<j<<" "<<*it;
                        return j;
                    }
                else {
                    return scores[j][k];
                    }
                k++;
            }
        }
    }else if(ismax==-1)
    {
        int bestValue = +10000000; // PLUS INFINI
        vector <int> fils;
        for(int i=0;i<24;i++)
        {
            if(state[i]==-1)
            {

                vector<int> v;
                table.voisin(i,&v,state,0);
                vector<int>::iterator it;
                int pos=0;
                for (it = v.begin(); it != v.end(); it++)
                {
                    state[*it]=-1;
                    state[i]=0;
                    int son=alphabeta2(state,depth+1,1,dest,*it,initial,alpha,beta);
                    fils.push_back(son);
                    state[*it]=0;
                    state[i]=-1;
                    scores[i][pos]=son; //problem
                    pos++;
                    nbr_noeuds++;



                    bestValue = min( bestValue, son);
                    beta = min( beta, bestValue);
                    if (beta<alpha)
                        break;

                }
            }
        }

        for(int j=0;j<24;j++)
        {
            vector<int> v;
            table.voisin(j,&v,state,0);
            int k=0;
             vector<int>::iterator it;
            for (it = v.begin(); it != v.end(); it++)
            {
                if(scores[j][k]==*max_element(fils.begin(),fils.end()))
                    if(depth==0)
                    {
                        *dest=*it;
                       // cout<<" meeee "<<scores[j][k]<<" "<<j<<" "<<*it;
                        return j;
                    }
                else {
                    return scores[j][k];
                    }
                k++;
            }
        }

    }
}


//minimax de la troisime phase du jeu
int Player::alphabeta3(int state[24],int depth,int ismax,int* dest, int it,int* initial,int alpha, int beta)
{
    Board table(state);

    if(table.moulinformation(it,-1,state))
        return 100000/depth;

    if(depth==finaldepth)
        return (100*table.heuristique(-1,state,-1));





    int save[24];
    int scores[24][24];
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
            save[i]=state[i];
            scores[i][j]=-9999;
        }
    }
    if(ismax==1)
    {
        int bestValue = -10000000; // MOINS INFINI
        vector<int> fils;
        for(int i=0;i<24;i++)
        {
            if(state[i]==1)
            {
                for (int j=0; j<24; j++)
                    if(state[j]==0)
                {
                    state[j]=1;
                    state[i]=0;
                    int son=alphabeta3(state,depth+1,-1,dest,j,initial,alpha,beta);
                    fils.push_back(son);
                    state[i]=1;
                    state[j]=0;
                    scores[i][j]=son; //problem
                    nbr_noeuds++;


                    bestValue = max( bestValue, son);
                    alpha = max( alpha, bestValue);
                    if (beta<alpha)
                        break;
                }
            }
        }
        for(int j=0;j<24;j++)
        {
            for (int k=0; k<24; k++)
            {
                if(scores[j][k]==*min_element(fils.begin(),fils.end()))
                    if(depth==0)
                    {
                        *dest=k;
                        cout<<" meeee "<<scores[j][k]<<" "<<j<<" "<<k<<endl;
                        return j;
                    }
                else {
                    return scores[j][k];
                    }
            }
        }
    }else if(ismax==-1)
    {
        int bestValue = +10000000; // PLUS INFINI
        vector <int> fils;
        for(int i=0;i<24;i++)
        {
            if(state[i]==-1)
            {
                for (int j=0; j<24; j++)
                    if(state[j]==0)
                {
                    state[j]=-1;
                    state[i]=0;
                    int son=alphabeta3(state,depth+1,1,dest,j,initial,alpha,beta);
                    fils.push_back(son);
                    state[j]=0;
                    state[i]=-1;
                    scores[i][j]=son; //problem
                    nbr_noeuds++;



                    bestValue = min( bestValue, son);
                    beta = min( beta, bestValue);
                    if (beta<alpha)
                        break;

                }
            }
        }

        for(int j=0;j<24;j++)
        {
            for (int k=0; k<24; k++)
            {
                if(scores[j][k]==*max_element(fils.begin(),fils.end()))
                    if(depth==0)
                    {
                        *dest=k;
                        cout<<" meeee "<<scores[j][k]<<" "<<j<<" "<<k;
                        return j;
                    }
                else {
                    return scores[j][k];
                    }
            }
        }

    }
}
