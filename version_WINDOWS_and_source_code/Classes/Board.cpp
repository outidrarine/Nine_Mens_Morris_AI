#include "Board.h"
#include"Player.h"
#include <iostream>
#include<stdlib.h>
#include <windows.h>
#include"vector"
#include<stdlib.h>
using namespace std;
Board::Board()
{
    for(int i=0;i<24;i++)
    {
        intersection_remplie[i]=0;
    }
    player=-1;
    times=0;

}
Board::Board(int state[24])
{
    for(int i=0;i<24;i++)
    {
        intersection_remplie[i]=state[i];
    }
}

Board::~Board()
{
    //dtor
}



int Board::heuristique(int player,int* table, int p)
{
    int score=0;
    for(int i=0;i<24;i++)
    {
        if(table[i]==p && moulinformation(i,player,table))
        {
            score++;
        }

    }
    return score;
}

bool Board::moulinformation(int in, int player,int* table)
{


	if (in == 0)
		return((table[1]==player && table[2]==player) || (table[9] == player && table[21] == player));
	if (in == 1)
		return((table[0] == player && table[2] == player) || (table[4] == player && table[7] == player));
	if (in == 2)
		return((table[1] == player && table[0] == player) || (table[14] == player && table[23] == player));
	if (in == 3)
		return((table[4] == player && table[5] == player) || (table[10] == player && table[18] == player));
	if (in == 4)
		return ((table[3] == player && table[5] == player) || (table[1] == player && table[7] == player));
	if (in == 5)
		return ((table[4] == player && table[3] == player) || (table[13] == player && table[20] == player));
	if (in == 6)
		return ((table[7] == player && table[8] == player) || (table[11] == player && table[15] == player));
	if (in == 7)
		return((table[4] == player && table[1] == player) || (table[6] == player && table[8] == player));
	if (in == 8)
		return((table[12] == player && table[17] == player) || (table[7] == player && table[6] == player));
	if (in == 9)
		return((table[0] == player && table[21] == player) || (table[10] == player && table[11] == player));
	if (in == 10)
		return((table[9] == player && table[11] == player) || (table[3] == player && table[18] == player));
	if (in == 11)
		return((table[6] == player && table[15] == player) || (table[10] == player && table[9] == player));
	if (in == 12)
		return((table[8] == player && table[17] == player) || (table[13] == player && table[14] == player) );
	if (in == 13)
		return((table[12] == player && table[14] == player) || (table[5] == player && table[20] == player));
	if (in == 14)
		return((table[2] == player && table[23] == player) || (table[13] == player && table[12] == player));
	if (in == 15)
		return((table[11] == player && table[6] == player) || (table[16] == player && table[17] == player));
	if (in == 16)
		return((table[15] == player && table[17] == player) || (table[19] == player && table[22] == player));
	if (in == 17)
		return((table[16] == player && table[15] == player) || (table[12] == player && table[8] == player));
	if (in == 18)
		return((table[10] == player && table[3] == player) || (table[19] == player && table[20] == player));
	if (in == 19)
		return((table[18] == player && table[20] == player) || (table[16] == player && table[22] == player ));
	if (in == 20)
		return((table[19] == player && table[18] == player) || (table[13] == player && table[5] == player));
	if (in == 21)
		return((table[9] == player && table[0] == player) || (table[22] == player && table[23] == player));
	if (in == 22)
		return((table[21] == player && table[23] == player) || (table[16] == player && table[19] == player));
	if (in == 23)
		return((table[22] == player && table[21] == player) || (table[14] == player && table[2] == player));

	return false;


}

bool Board::validmove(int in, int out)
{
	if (in == out)
		return false;
	if (in == 0)
		return( out == 1 || out == 9);
	if (in == 1)
		return(out == 0 || out == 2 || out==4);
	if (in == 2)
		return(out == 1 || out == 14);
	if (in == 3)
		return(out == 4 || out == 10);
	if (in == 4)
		return (out == 3 || out == 5 || out == 1 || out == 7);
	if (in == 5)
		return (out == 4 || out == 13);
	if (in == 6)
		return (out == 7 || out == 11);
	if (in == 7)
		return(out == 4 || out == 6 || out == 8);
	if (in == 8)
		return(out == 12 || out == 7);
	if (in == 9)
		return(out == 0 || out == 10 || out == 21);
	if (in == 10)
		return(out == 9 || out == 11 || out == 3 || out == 18);
	if (in == 11)
		return(out == 6 || out == 10 || out == 15);
	if (in == 12)
		return(out == 8 || out == 13 || out == 17);
	if (in == 13)
		return(out == 12 || out == 14 || out == 5 || out == 20);
	if (in == 14)
		return(out == 2 || out == 23 || out == 13);
	if (in == 15)
		return(out == 11 || out == 16);
	if (in == 16)
		return(out == 15 | out == 17 || out == 19);
	if(in == 17)
		return(out == 16 || out == 12);
	if (in == 18)
		return(out == 10 || out == 19);
	if (in == 19)
		return(out == 18 || out == 20 || out == 16 || out == 22);
	if (in == 20)
		return(out == 19 || out == 13);
	if (in == 21)
		return(out == 9 || out == 22);
	if (in == 22)
		return(out == 21 || out == 19 || out == 23);
	if (in == 23)
		return(out == 22 || out == 14);

	return false;
}
void Board::voisin(int i,vector<int>* v,int state[24],int with)
{
    switch(i){
case 0:
    {
        if(state[1]==with)
            (*v).push_back(1);
        if(state[9]==with)
            (*v).push_back(9);
        break;
    }
case 1:
    {
        if(state[0]==with)
            (*v).push_back(0);
        if(state[2]==with)
            (*v).push_back(2);
        if(state[4]==with)
            (*v).push_back(4);
        break;
    }
case 2:
    {
        if(state[1]==with)
            (*v).push_back(1);
        if(state[14]==with)
            (*v).push_back(14);
        break;
    }
case 3:
    {
        if(state[4]==with)
            (*v).push_back(4);
        if(state[10]==with)
            (*v).push_back(10);
        break;
    }
case 4:
    {
        if(state[3]==with)
            (*v).push_back(3);
        if(state[5]==with)
            (*v).push_back(5);
        if(state[7]==with)
            (*v).push_back(7);
        if(state[1]==with)
            (*v).push_back(1);
        break;
    }
case 5:
    {
        if(state[4]==with)
            (*v).push_back(4);
        if(state[13]==with)
            (*v).push_back(13);
        break;
    }
case 6:
    {
        if(state[7]==with)
            (*v).push_back(7);
        if(state[11]==with)
            (*v).push_back(11);
        break;
    }
case 7:
    {
        if(state[4]==with)
            (*v).push_back(4);
        if(state[6]==with)
            (*v).push_back(6);
        if(state[8]==with)
            (*v).push_back(8);
        break;
    }
case 8:
    {
        if(state[7]==with)
            (*v).push_back(7);
        if(state[12]==with)
            (*v).push_back(12);
        break;
    }
case 9:
    {
        if(state[0]==with)
            (*v).push_back(0);
        if(state[21]==with)
            (*v).push_back(21);
        if(state[10]==with)
            (*v).push_back(10);
        break;
    }
case 10:
    {
        if(state[9]==with)
            (*v).push_back(9);
        if(state[11]==with)
            (*v).push_back(11);
        if(state[3]==with)
            (*v).push_back(3);
        if(state[18]==with)
            (*v).push_back(18);
        break;
    }
case 11:
    {
        if(state[6]==with)
            (*v).push_back(6);
        if(state[15]==with)
            (*v).push_back(15);
        if(state[10]==with)
            (*v).push_back(10);
        break;
    }
case 12:
    {
        if(state[8]==with)
            (*v).push_back(8);
        if(state[17]==with)
            (*v).push_back(17);
        if(state[13]==with)
            (*v).push_back(13);
        break;
    }
case 13:
    {
        if(state[5]==with)
            (*v).push_back(5);
        if(state[20]==with)
            (*v).push_back(20);
        if(state[12]==with)
            (*v).push_back(12);
        if(state[14]==with)
            (*v).push_back(14);
        break;
    }
case 14:
    {
        if(state[2]==with)
            (*v).push_back(2);
        if(state[23]==with)
            (*v).push_back(23);
        if(state[13]==with)
            (*v).push_back(13);
        break;
    }
case 15:
    {
        if(state[16]==with)
            (*v).push_back(16);
        if(state[11]==with)
            (*v).push_back(11);
        break;
    }
case 16:
    {
        if(state[19]==with)
            (*v).push_back(19);
        if(state[15]==with)
            (*v).push_back(15);
        if(state[17]==with)
            (*v).push_back(17);
        break;
    }
case 17:
    {
        if(state[12]==with)
            (*v).push_back(12);
        if(state[16]==with)
            (*v).push_back(16);
        break;
    }
case 18:
    {
        if(state[19]==with)
            (*v).push_back(19);
        if(state[10]==with)
            (*v).push_back(10);
        break;
    }
case 19:
    {
        if(state[16]==with)
            (*v).push_back(16);
        if(state[22]==with)
            (*v).push_back(22);
        if(state[18]==with)
            (*v).push_back(18);
        if(state[20]==with)
            (*v).push_back(20);
        break;
    }
case 20:
    {
        if(state[19]==with)
            (*v).push_back(19);
        if(state[13]==with)
            (*v).push_back(13);
        break;
    }
case 21:
    {
        if(state[9]==with)
            (*v).push_back(9);
        if(state[22]==with)
            (*v).push_back(22);
        break;
    }
case 22:
    {
        if(state[21]==with)
            (*v).push_back(21);
        if(state[23]==with)
            (*v).push_back(23);
        if(state[19]==with)
            (*v).push_back(19);
        break;
    }
case 23:
    {
        if(state[22]==with)
            (*v).push_back(22);
        if(state[14]==with)
            (*v).push_back(14);
        break;
    }
    }
}
