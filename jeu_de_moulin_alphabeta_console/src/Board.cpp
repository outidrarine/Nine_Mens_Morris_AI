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
void Board::color(int t,int f)
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,f*16+t);
}

void Board::drop(int i)
{
    if(intersection_remplie[i]==1)
    {
        if(i<10)
        {
            color(8,14);
            cout<<"  "<<i<<" ";
            color(8,0);
            cout<<"";
        }else{
            color(8,14);
            cout<<" "<<i<<" ";
            color(8,0);
            cout<<"";
        }


    }
    if(intersection_remplie[i]==-1)
    {
        if(i<10)
        {
            color(8,11);
            cout<<"  "<<i<<" ";
            color(8,0);
            cout<<"";
        }else{
            color(8,11);
            cout<<" "<<i<<" ";
            color(8,0);
            cout<<"";
        }

    }
    if(intersection_remplie[i]==0)
    {
        cout<<" "<<i<<" ";
        if(i<10)
            cout<<" ";
    }

}
void Board::drop2(int i)
{
    if(intersection_remplie[i]==1)
    {
        color(14,14);
        cout<<"aaaa";
        color(8,0);
        cout<<"";

    }
    if(intersection_remplie[i]==-1)
    {
        color(11,11);
        cout<<"aaaa";
        color(8,0);
        cout<<"";
    }
    if(intersection_remplie[i]==0)
    {
        if(i>9)
            cout<<"  ";
        if(i<10)
            cout<<" ";
        cout<<""<<" "<<" ";
        if(i<10)
            cout<<" ";


    }

}

void Board::afficher_grille()
{
    cout<<"\n\n\n"<<endl;
    cout<<"\t\t\t\t";drop(21);cout<<"___________________________";drop(22);cout<<"____________________________";drop(23);cout<<""<<endl;
    cout<<"\t\t\t\t";drop2(21);cout<<"                           ";drop2(22);cout<<"                            ";drop2(23);cout<<""<<endl;
    cout<<"\t\t\t\t |                              |                               |"<<endl;
    cout<<"\t\t\t\t |                              |                               |"<<endl;
    cout<<"\t\t\t\t |                              |                               |"<<endl;
    cout<<"\t\t\t\t |       ";drop(18);cout<<"__________________";drop(19);cout<<"__________________";drop(20);cout<<"       |"<<endl;
    cout<<"\t\t\t\t |       ";drop2(18);cout<<"                  ";drop2(19);cout<<"                  ";drop2(20);cout<<"       |"<<endl;
    cout<<"\t\t\t\t |        |                     |                     |         |"<<endl;
    cout<<"\t\t\t\t |        |                     |                     |         |"<<endl;
    cout<<"\t\t\t\t |        |                     |                     |         |"<<endl;
    cout<<"\t\t\t\t |        |         ";drop(15);cout<<"_______";drop(16);cout<<"_______";drop(17);cout<<"        |         |"<<endl;
    cout<<"\t\t\t\t |        |         ";drop2(15);cout<<"       ";drop2(16);cout<<"       ";drop2(17);cout<<"        |         |"<<endl;
    cout<<"\t\t\t\t |        |          |                     |          |         |"<<endl;
    cout<<"\t\t\t\t |        |          |                     |          |         |"<<endl;
    cout<<"\t\t\t\t";drop(9);cout<<"_____";drop(10);cout<<"_______";drop(11);cout<<"                  ";drop(12);cout<<"_______";drop(13);cout<<"______";drop(14);cout<<""<<endl;
    cout<<"\t\t\t\t";drop2(9);cout<<"     ";drop2(10);cout<<"       ";drop2(11);cout<<"                  ";drop2(12);cout<<"       ";drop2(13);cout<<"      ";drop2(14);cout<<""<<endl;
    cout<<"\t\t\t\t |        |          |                     |          |         |"<<endl;
    cout<<"\t\t\t\t |        |          |                     |          |         |"<<endl;
    cout<<"\t\t\t\t |        |          |                     |          |         |"<<endl;
    cout<<"\t\t\t\t |        |        ";drop(6);cout<<"_______";drop(7);cout<<"_______";drop(8);cout<<"         |         |"<<endl;
    cout<<"\t\t\t\t |        |        ";drop2(6);cout<<"       ";drop2(7);cout<<"       ";drop2(8);cout<<"         |         |"<<endl;
    cout<<"\t\t\t\t |        |                     |                     |         |"<<endl;
    cout<<"\t\t\t\t |        |                     |                     |         |"<<endl;
    cout<<"\t\t\t\t |        |                     |                     |         |"<<endl;
    cout<<"\t\t\t\t |      ";drop(3);cout<<"__________________";drop(4);cout<<"__________________";drop(5);cout<<"        |"<<endl;
    cout<<"\t\t\t\t |      ";drop2(3);cout<<"                  ";drop2(4);cout<<"                  ";drop2(5);cout<<"        |"<<endl;
    cout<<"\t\t\t\t |                              |                               |"<<endl;
    cout<<"\t\t\t\t |                              |                               |"<<endl;
    cout<<"\t\t\t\t |                                                              |"<<endl;
    cout<<"\t\t\t\t";drop(0);cout<<"__________________________";drop(1);cout<<"_____________________________";drop(2);cout<<""<<endl;
    cout<<"\t\t\t\t";drop2(0);cout<<"                          ";drop2(1);cout<<"                             ";drop2(2);cout<<""<<endl;


}
void Board::ingame()
{
        int input=0;
        blanc=0;
        noir=0;
        Player ai;
    while(times<18)
    {
        system("@cls||clear");
        afficher_grille();
       cout<<"nombre de noeuds traites : "<<ai.nbr_noeuds<<endl;

        if(player==-1)
        {
            ai.nbr_noeuds=0;
            int chosen=ai.alphabeta1(intersection_remplie,0,-1,0,-100000000000,+100000000000); //to see about this true
            intersection_remplie[chosen]=player;
            if(moulinformation(chosen,-1,intersection_remplie))
            {
                int done=1;
                for(int i=0;i<24;i++)
                {
                    if(intersection_remplie[i]==0&&moulinformation(i,1,intersection_remplie))
                    {
                        vector<int> v;
                        voisin(i,&v,intersection_remplie,1);
                         vector<int>::iterator it;
                            for (it = v.begin(); it != v.end(); it++)
                            {
                               intersection_remplie[*it]=0;
                               done=0;
                               break;
                            }
                        if(!done)
                            break;
                    }
                }
                if(done)
                {
                    for(int i=0;i<24;i++)
                        if(intersection_remplie[i]==1&&!moulinformation(i,1,intersection_remplie))
                    {
                        intersection_remplie[i]=0;
                        break;
                    }
                }
            }
        }else{
            cin>>input;
            intersection_remplie[input]=player;
            if(moulinformation(input,1,intersection_remplie))
            {
                int todelete=0;
                cout<<"chose a stone to delete : "<<endl;
                cin>>todelete;
                while(intersection_remplie[todelete]!=-1||moulinformation(todelete,-1,intersection_remplie))
                {
                    cout<<"please chose a valid stone"<<endl;
                    cin>>todelete;
                }
                intersection_remplie[todelete]=0;
            }
        }
        player*=-1;
        times++;
       // system("@cls||clear");
      //  afficher_grille();
    }

    blanc=0;
    noir=0;
        for(int i=0;i<24;i++)
        {
            if(intersection_remplie[i]==-1)
                noir++;
            if(intersection_remplie[i]==1)
                blanc++;
        }
/*
intersection_remplie[19]=-1;
intersection_remplie[0]=-1;
intersection_remplie[13]=-1;
//intersection_remplie[2]=-1;
//intersection_remplie[23]=-1;
//intersection_remplie[8]=-1;

intersection_remplie[5]=1;
intersection_remplie[20]=1;
intersection_remplie[12]=1;
intersection_remplie[14]=1;
player=1;*/
afficher_grille();
    while(blanc!=2&&noir!=2)
    {
        if(player==1)
        {    int selected=0,destination=0;
            do
            {
                cout<<" nombre des noeuds : "<<ai.nbr_noeuds<<endl;
                cout<<" select a stone de move "<<endl;
                do{
                    cin>>selected;
                }while(intersection_remplie[selected]!=1);
                cout<<"select destination"<<endl;
                do{
                    cin>>destination;
                }while(intersection_remplie[destination]!=0);
            }while(!validmove(selected,destination)&&(blanc!=3));

            intersection_remplie[destination]=1;
            intersection_remplie[selected]=0;

            if(moulinformation(destination,1,intersection_remplie))
            {
                int todelete=0;
                cout<<"chose a stone to delete : "<<endl;
                cin>>todelete;
                while(intersection_remplie[todelete]!=-1||moulinformation(todelete,-1,intersection_remplie))
                {
                    cout<<"please chose a valid stone"<<endl;
                    cin>>todelete;
                }
                intersection_remplie[todelete]=0;
            }

        }else{
            if(noir!=3)
           {
                int to=0;
                int from=0;
                ai.nbr_noeuds=0;
                from=ai.alphabeta2(intersection_remplie,0,-1,&to,0,intersection_remplie,-100000000000,+100000000000);
                intersection_remplie[from]=0;
                intersection_remplie[to]=-1;
                ///////////////////////////////////////////////////////////////////////
                if(moulinformation(to,-1,intersection_remplie))
            {
                int done=1;
                for(int i=0;i<24;i++)
                {
                    if(intersection_remplie[i]==0&&moulinformation(i,1,intersection_remplie))
                    {
                        vector<int> v;
                        voisin(i,&v,intersection_remplie,1);
                         vector<int>::iterator it;
                            for (it = v.begin(); it != v.end(); it++)
                            {
                               intersection_remplie[*it]=0;
                               done=0;
                               break;
                            }
                        if(!done)
                            break;
                    }
                }
                if(done)
                {
                    for(int i=0;i<24;i++)
                        if(intersection_remplie[i]==1&&!moulinformation(i,1,intersection_remplie))
                    {
                        intersection_remplie[i]=0;
                        break;
                    }
                }
            }
            //////////////////////////////////////////////////////
                system("@cls||clear");
                afficher_grille();
                cout<<"AI2 from : "<<from<<" to : "<<to<<" nbr de noeuds "<<ai.nbr_noeuds<<endl;
           }
           if(noir==3)
           {
                int to=0;
                int from=0;
                ai.nbr_noeuds=0;
                from=ai.alphabeta3(intersection_remplie,0,-1,&to,0,intersection_remplie,-100000000000,+100000000000);
                intersection_remplie[from]=0;
                intersection_remplie[to]=-1;
                ////////////////////////////////////////////////////////
                if(moulinformation(to,-1,intersection_remplie))
            {
                int done=1;
                for(int i=0;i<24;i++)
                {
                    if(intersection_remplie[i]==0&&moulinformation(i,1,intersection_remplie))
                    {
                        vector<int> v;
                        voisin(i,&v,intersection_remplie,1);
                         vector<int>::iterator it;
                            for (it = v.begin(); it != v.end(); it++)
                            {
                               intersection_remplie[*it]=0;
                               done=0;
                               break;
                            }
                        if(!done)
                            break;
                    }
                }
                if(done)
                {
                    for(int i=0;i<24;i++)
                        if(intersection_remplie[i]==1&&!moulinformation(i,1,intersection_remplie))
                    {
                        intersection_remplie[i]=0;
                        break;
                    }
                }
            }
            /////////////////////////////////////////////////////////////////////////////////////
                system("@cls||clear");
                afficher_grille();
                cout<<"AI3 from : "<<from<<" to : "<<to<<" nbr de noeuds "<<ai.nbr_noeuds<<endl;
           }


        }
        player*=-1;
        blanc=0;
        noir=0;
        for(int i=0;i<24;i++)
        {
            if(intersection_remplie[i]==-1)
                noir++;
            if(intersection_remplie[i]==1)
                blanc++;
        }

    }
system("@cls||clear");
if(noir==2)
    cout<<"winner is : white player"<<endl;
if(blanc==2)
    cout<<"winner is : black player"<<endl;


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
