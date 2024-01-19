//bismilah arrahman arahim 
// my first true program game 
// wama tawfiqi ila billah 3alayhi tawakaltu wa ilayhi unib 
// Melissa BOUTLENDJ 
//26/11/2023

#ifndef TICTACTOE_H
#define TICTACTOE_H
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include <cstring>




class tictactoe
{
  int T[3][3];
  
  public:
  tictactoe();
  void affichage();
  int arbitre();

//   tictactoe(int a,int b);
 bool realiseMove(char k);// c'est la fonction JeuHumain()
 int check();
 int defend(int c, int p, int b);
 int youStart();
int attack();
void JeuOrdi(int& b);
int partie();
//  void unePartie();


};



#endif
