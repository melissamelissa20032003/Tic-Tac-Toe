#include<iostream>
#include<cmath>
#include"tictactoe.h"






int main()
{
    
tictactoe jeux;
char h='h';
char o='o';




//std::cout<<jeux.arbitre();
// jeux.realiseMove('h');
// jeux.affichage();
// jeux.realiseMove('h');
// jeux.affichage();
// jeux.realiseMove('h');
// jeux.affichage();

// std::cout<<jeux.arbitre();

jeux.partie();


    return 0;
}



//1)We analyze if we are winning by taking a move, in any of the 3 rows or the 3 columns or the 2 diagonals. 
//If winning, then we thake the required the move and wins the game.

//2) If we are not winning, that means if the first step fails in taking 
//any move, we then analyze if the opponent is going to win in his next turn.
// If found, then we take the required move to block the opponent from winning the game. 

//3) Now, if neither the opponent nor ourselves our winning,
// then we take such a move that will lead us to a win in future.




