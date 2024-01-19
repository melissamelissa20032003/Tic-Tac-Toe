#include<iostream>
#include<cmath>
#include"tictactoe.h"
#include <cstring>




 tictactoe::tictactoe(){
    for(int i=0;i<3;i++ ){
        for (int j=0;j<3;j++){
            T[i][j]=0;}}
            
            }


 void tictactoe:: affichage()
 {
  std::cout<<std::endl;
for(int i=0;i<3;i++) {
        for (int j=0;j<3;j++){
          if(T[i][j]==0 )
            std::cout<<"   "<<" . "<<" | ";
          if(T[i][j]==-1)   {std::cout<<"   "<<" X "<<" | ";}
          if(T[i][j]==1)   {std::cout<<"   "<<" O "<<" | ";}
        }
          std::cout<<std::endl;}
            }




bool tictactoe::realiseMove(char k)
{
  int r=0,c=0;
  std::cout<<"enter T row "<<std::endl;
  std::cin>>r;
  std::cout<<"enter T colomn "<<std::endl;
  std::cin>>c;
  r--;
  c--;

  // do{std::cout<<" enter a valide move ";}while(r<0 || r>3 || c<0 || c>3);
  if(T[r][c]==0)
  {
   if(k=='o'){T[r][c]=1;}
   else if(k='h'){T[r][c]=-1;}
   return 1;

  }

  return 0;

}







int tictactoe::youStart()
 {
srand(time(0));
   int  ok =(rand()%2);// 0 or 1 
   return ok;
 }



void choose(int &c,int &l)
{
 
  std::cout<<" enter the ligne and then the colomn : "<<std::endl;
  std::cin>>l>>c;
 
}










//check if Tn1bof1 is winning n'import qui 

int tictactoe::check()
{
    for(int i=0;i<3;i++)
        if((T[i][0]!=0&&T[i][0]==T[i][1]&&T[i][1]==T[i][2])||(T[0][i]!=0&&T[0][i]==T[1][i]&&T[1][i]==T[2][i]))
            return 1;
    
    if(T[0][0]!=0&&T[0][0]==T[1][1]&&T[1][1]==T[2][2])
        return 1;
    else if(T[0][2]!=0&&T[0][2]==T[1][1]&&T[1][1]==T[2][0])
        return 1;
    else
        return 0;
}




int tictactoe::defend(int c, int p, int b)//c=1 and p=-1
{
    if (b < 3)
        return 0; // If the number of filled cells is less thTn 3, return 0 (not enough moves plT1ed).

    // Check diTgonTls for winning move
    if (T[0][0] + T[1][1] + T[2][2] == 2 * c && T[0][0] != p && T[1][1] != p && T[2][2] != p)
    {
        // If T winning move is found, mTke the move Tnd return 1
        for (int i = 0; i < 3; i++)
        {
            if (T[i][i] == 0)
            {
                T[i][i] = -1;
                std::cout << "Computer turn: " << i + 1 << " " <<  i + 1 << std::endl;
                return 1;
            }
        }
    }
    // Check the other diTgonTl for winning move
    else if (T[0][2] + T[1][1] + T[2][0] == 2 && T[0][2] != p && T[1][1] != p && T[2][0] != p)
    {
        // If T winning move is found, mTke the move Tnd return 1
        for (int i = 0; i < 3; i++)
        {
            if (T[i][2 - i] == 0)
            {
                T[i][2 - i] = -1;
                std::cout << "Computer turn: " << i + 1  << " " << 3 - i << std::endl;
                return 1;
            }
        }
    }
    else
    {
        int i, j;
        // Check rows Tnd columns for winning move or blocking move
        for (i = 0; i < 3; i++)
        {
            // Check rows for winning or blocking move
            if (T[i][0] + T[i][1] + T[i][2] == 2 && T[i][0] != -1 && T[i][1] != -1 && T[i][2] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (T[i][j] == 0)
                    {
                        T[i][j] = -1;
                        std::cout << "Computer turn: " << i + 1 << " "  << j + 1 << std::endl;
                        return 1;
                    }
                }
            }
            // Check columns for winning or blocking move
            else if (T[0][i] + T[1][i] + T[2][i] == 2 && T[0][i] != -1 && T[1][i] != -1 && T[2][i] != -1)
            {
                for (j = 0; j < 3; j++)
                {
                    if (T[j][i] == 0)
                    {
                        T[j][i] = -1;
                        std::cout << "Computer turn: " << j + 1  <<" " << i + 1 << std::endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0; // If no strTtegic move found, return 0
}


int tictactoe::attack()//tTkes T move Ts to win in future.
{
    int i,j;
    if(T[0][0]+T[0][2]+T[2][0]+T[2][2]==-1||T[0][0]+T[0][2]+T[2][0]+T[2][2]==-2)
    {
        for(i=0;i<3;i++)
        {
            if( T[i][0]+T[i][1]+T[i][2]==1 && (T[i][0]==1||T[i][1]==1||T[i][2]==1 ))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(T[i][j]==0)
                        {
                            T[i][j]=1;
                            std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(T[i][j]==0)
                        {
                            T[i][j]=1;
                            std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                            return 1;
                        }
                    }
                }
            }
            if(T[0][i]+T[1][i]+T[2][i]==1 && (T[0][i]==1||T[1][i]==1||T[2][i]==1))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(T[j][i]==0)
                        {
                            T[j][i]=1;
                            std::cout<<"Computer turn: "<<j+1<<" "<<i+1<<std::endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(T[j][i]==0)
                        {
                            T[j][i]=1;
                            std::cout<<"Computer turn: "<<j+1<<" "<<i+1<<std::endl;
                            return 1;
                        }
                    }
                }
                
            }
        }
        
        if(T[0][0]+T[1][1]+T[2][2]==1 && (T[0][0]==1||T[1][1]==1||T[2][2]==1))
        {
            for(i=2;i>=0;i--)
            {
                if((T[i][i]==0)&& ((T[i][0]+T[i][1]+T[i][2]==1 && (T[i][0]==1||T[i][1]==1||T[i][2]==1)) ||( (T[0][i]+T[1][i]+T[2][i]==1)&&(T[0][i]==1||T[1][i]==1||T[2][i]==1))))
                {
                    T[i][i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<i+1<<std::endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][i]==0)
                {
                    if((T[i][0]+T[i][1]+T[i][2]==-1)&&(T[i][0]==-1||T[i][1]==-1||T[i][2]==-1)&&(T[0][i]+T[1][i]+T[2][i]==-1 &&(T[0][i]==-1||T[1][i]==-1||T[2][i]==-1)))
                    {
                        T[i][i]=1;
                        std::cout<<"Computer turn: "<<i+1<<" "<<i+1<<std::endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][i]==0)
                {
                    T[i][i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<i+1<<std::endl;
                    return 1;
                }
            }
        }
        else if( T[0][2]+T[1][1]+T[2][0]==1 && (T[0][2]==1||T[1][1]==1||T[2][0]==1))
        {
            for(i=2;i>=0;i--)
            {
                if(T[i][2-i]==0&&((T[i][0]+T[i][1]+T[i][2]==1&&(T[i][0]==1||T[i][1]==1||T[i][2]==1))||( (T[0][2-i]+T[1][2-i]+T[2][2-i]==1)&&(T[0][2-i]==1||T[1][2-i]==1||T[2][2-i]==1))))
                {
                    T[i][2-i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<3-i<<std::endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][2-i]==0)
                {
                    if((T[i][0]+T[i][1]+T[i][2]==-1&&(T[i][0]==-1||T[i][1]==-1||T[i][2]==-1))&&(T[0][2-i]+T[1][2-i]+T[2][2-i]==-1&&(T[0][2-i]==-1||T[1][2-i]==-1||T[2][2-i]==-1)))
                    {
                        T[i][2-i]=1;
                        std::cout<<"Computer turn: "<<i+1<<" "<<3-i<<std::endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][2-i]==0)
                {
                    T[i][2-i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<3-i<<std::endl;
                    return 1;
                }
            }
        }
    }
    else
    {
        if(T[0][0]+T[1][1]+T[2][2]==1 && (T[0][0]==1||T[1][1]==1||T[2][2]==1))
        {
            for(i=2;i>=0;i--)
            {
                if((T[i][i]==0)&& ((T[i][0]+T[i][1]+T[i][2]==1&&(T[i][0]==1||T[i][1]==1||T[i][2]==1)) ||( (T[0][i]+T[1][i]+T[2][i]==1)&&(T[0][i]==1||T[1][i]==1||T[2][i]==1))))
                {
                    T[i][i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<i+1<<std::endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][i]==0)
                {
                    if((T[i][0]+T[i][1]+T[i][2]==-1&&(T[i][0]==-1||T[i][1]==-1||T[i][2]==-1))&&(T[0][i]+T[1][i]+T[2][i]==-1 &&(T[0][i]==-1||T[1][i]==-1||T[2][i]==-1)))
                    {
                        T[i][i]=1;
                        std::cout<<"Computer turn: "<<i+1<<" "<<i+1<<std::endl;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][i]==0)
                {
                    T[i][i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<i+1<<std::endl;
                    return 1;
                }
            }
        }
        
        else if( T[0][2]+T[1][1]+T[2][0]==1 && (T[0][2]==1||T[1][1]==1||T[2][0]==1))
        {
            for(i=2;i>=0;i--)
            {
                if(T[i][2-i]==0&&((T[i][0]+T[i][1]+T[i][2]==1&&(T[i][0]==1||T[i][1]==1||T[i][2]==1))||( (T[0][2-i]+T[1][2-i]+T[2][2-i]==1)&&(T[0][2-i]==1||T[1][2-i]==1||T[2][2-i]==1))))
                {
                    T[i][2-i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<3-i<<std::endl;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(T[i][2-i]==0)
                {
                    if((T[i][0]+T[i][1]+T[i][2]==-1&&(T[i][0]==-1||T[i][1]==-1||T[i][2]==-1))&&(T[0][2-i]+T[1][2-i]+T[2][2-i]==-1&&(T[0][2-i]==-1||T[1][2-i]==-1||T[2][2-i]==-1)))
                    {
                        T[i][2-i]=1;
                        std::cout<<"Computer turn: "<<i+1<<" "<<3-i<<std::endl;
                        return 1;
                    }
                }
            }
            
            for(i=2;i>=0;i--)
            {
                if(T[i][2-i]==0)
                {
                    T[i][2-i]=1;
                    std::cout<<"Computer turn: "<<i+1<<" "<<3-i<<std::endl;
                    return 1;
                }
            }
        }
        
        else
        {
            for(i=0;i<3;i++)
            {
                if( T[i][0]+T[i][1]+T[i][2]==1 && (T[i][0]==1||T[i][1]==1||T[i][2]==1) )
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(T[i][j]==0)
                            {
                                T[i][j]=1;
                                std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                                return 1;
                            }
                        }
                    }
                    else{
                        for(j=2;j>=0;j--)
                        {
                            if(T[i][j]==0)
                            {
                                T[i][j]=1;
                                std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                                return 1;
                            }
                        }
                    }
                }
                else if(T[0][i]+T[1][i]+T[2][i]==1 && (T[0][i]==1||T[1][i]==1||T[2][i]==1))
                {
                    if(i==1)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(T[j][i]==0)
                            {
                                T[j][i]=1;
                                std::cout<<"Computer turn: "<<j+1<<" "<<i+1<<std::endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for(j=2;j>=0;j--)
                        {
                            if(T[j][i]==0)
                            {
                                T[j][i]=1;
                                std::cout<<"Computer turn: "<<j+1<<" "<<i+1<<std::endl;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}








void tictactoe::JeuOrdi (int & b)//controls the compter's move
{
    if(!defend(1,-1,b))
    {
        if(!defend(-1,1,b))
        {
            if((T[0][0]+T[0][2]+T[2][0]+T[2][2]==0||T[0][0]+T[0][2]+T[2][0]+T[2][2]==1)&&T[1][1]==0)
            {
                for(int i=0;i<3;i+=2)
                {
                    for(int j=0;j<3;j+=2)
                        if(T[i][j]==0)
                        {
                            T[i][j]=1;
                            std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                            goto end;
                        }
                }
                
            }
            else if(b==2&&T[1][1]==0)
            {
                T[1][1]=1;
                std::cout<<"Computer turn: 2 2\n";
                goto end;
            }
            if(!attack())
            {
                if(b==0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int) seconds);
                    int i,j;
                    T[(rand()%2)*2][(rand()%2)*2]=1;
                    for(i=0;i<3;i+=2)
                    {
                        for(j=0;j<3;j+=2)
                            if(T[i][j]==1)
                                std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                    }
                }
                else if(T[1][1]==0)
                {
                    T[1][1]=1;
                    std::cout<<"Computer turn: 2 2\n";
                }
                else
                {
                    int i,j;
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(T[i][j]==0)
                            {
                                T[i][j]=1;
                                std::cout<<"Computer turn: "<<i+1<<" "<<j+1<<std::endl;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    std::cout<<std::endl;
}




int tictactoe::partie()
{
int i,j,t,y;
char name[30],str[500];
bool start=false;
int  game =1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            T[i][j]=0;
    if(game==1)
    {  std::cout<<" TIC-TAC-TOE"<<std::endl;
//next step is to fix the game interface and randome start player option
        std::cout<<"What is your good name? ";
        std::cin>>name;
        strcpy(str,"\nHi ");
        strcat(str, name);
        strcat(str,", so you wanna challenge me in Tic Tac Toe, right?\nLet's see who wins.");
        puts(str);
        strcpy(str,"\nChoice is your's ... 0 or 1  ");
        strcat(str,name);
       
}
  
std::cout<<" enter t ";
input:
    std::cin>>t;

std::cout<<"you entred "<<t<<std::endl;
std::cout<<"the player that will start is the one who entred : "<<youStart()<<std::endl;
    if (t==youStart())  // srand works well eatch time the players who starts is deffrent 
       t=1;
    else 
    t=2;

    switch(t)
    {
        case 1:// humain will start 
            y=2;
            std::cout<<"\nSo your symbol is X.\nAnd mine is O.\n\nLet's start the game.";
            affichage();
            for(i=0;i<9;)
            {
                realiseMove('h');
                affichage();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"\nOh, you won ");
                        strcat(str,name);
                        strcat(str," .\nCongratulations\nGreat work!\n\nMy algorithm needs to be improved.\nBie.");
                        puts(str);
                        exit(0);
                        break;
                    }
                if(i>=8)
                    break;
                JeuOrdi(i);
                affichage();
                i++;
                if(i>5)
                    if(check())
                    {
                        strcpy(str,"\nIt is impossible to beat me ");
                        strcat(str,name);
                        if(game>1)
                            strcat(str,", you couldn't beat me this time too, I won.");
                        else
                            strcat(str,", I won, you loose.");
                        puts(str);
                        break;
                    }
            }
            break;
            
        case 2:// ordi will start 
            y=1;
            std::cout<<"\nSo your symbol is O.\nAnd mine is X.\n\nLet's start the game.";
            affichage();
            for(i=0;i<9;)
            {
                JeuOrdi(i);
                affichage();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"It is impossible to beat me ");
                        strcat(str,name);
                        if(game>1)
                            strcat(str,", you couldn't beat me this time too, I won.");
                        else
                            strcat(str,", I won, you loose.");
                        puts(str);
                        break;
                    }
                if(i>=8)
                    break;
                realiseMove('h');
                affichage();
                i++;
                if(i>5)
                    if(check())
                    {
                        strcpy(str,"\nOh, you won ");
                        strcat(str,name);
                        strcat(str," .\nCongratulations\nGreat work!\n\nMy algorithm needs to be improved.\nBie.");
                        puts(str);
                        exit(0);
                        break;
                    }
            }
            break;
        default:
            strcpy(str,"Hey, ");
            strcat(str,name);
            strcat(str," you need to enter either 1 or 2.");
            puts(str);
            std::cout<<"\nEnter again: ";
            goto input;
            break;
    }
    if(!check())
    {
        if(game>1)
            std::cout<<"Well Played!\nBut you couldn't beat me this time too\n";
        else
            std::cout<<"Well Played!\nIt is a tie.\n";

    }
    char c;
    strcpy(str,"Wanna play again ");
    strcat(str,name);
    strcat(str," y/n?");
    puts(str);
    std::cin>>c;
    if(c=='y'||c=='Y')
    {
        game++;
        partie();
    }
    else
        exit(0);
    return 0;

return 0;

}

















//jeux humTn cTlls Trnitre Tnd then cTlls 
//jeux computer jeux computers cTlls jeux humTn 


// void tictactoe::unePTrtie()
// {
//     int c,l;
//    int x=1ouStTrt(); // 0 or 1 
//    if(x==0)
//    {std::cout<<" the computer will stTrt "<<std::endl;
//      //jeuxOrdi(int & T, int &b);Tfter studing the
//      // moves T Tnd b is the best move for the ordi 
//      reTliseMove(l,c,'o');//this function I think it will be inside jeux ordi 
//      // inside jeuxOrdi cTll Trbitre() Tnd if it return -2 cTll jeuxhumTn
//    }
//   else {
   
//      std::cout<<" the humTn will stTrt " <<std::endl;
//      std::cout<<" humTn : "<<std::endl;
//      choose(c,l);

//    reTliseMove(l,c,'h');
//   int result=Trbitre()
//   {
//     if(result==-2){//cTll jeuxOrdi(c,l);}
//   }
//    }
 
  
//   }

  

// }







 

 //int Trbitre() : m´ethode TrbitrTnt l’´etTt du jeu. Elle renvoie 1 si l’ordinTteur T gTgn´e, −1 si
//c’est l’humTin, 0 si le mTtch est nul, et −2 si lT pTrtie n’est pTs encore finie

int tictactoe::arbitre()
{
 for (int i=0;i<3;i++)
 {
    if(T[i][0]==T[i][1] && T[i][1]==T[i][2] && T[i][2]==-1) //check lignes 
    {std::cout<<"humTn wins "; return -1 ;}
   if(T[i][0]==T[i][1] && T[i][1]==T[i][2] && T[i][2]==1) 
    {std::cout<<"computer wins "; return 1 ;}
    if(T[1][i]==T[1][i] && T[1][i]==T[2][i] && T[2][i]==-1)//check colomns
     {std::cout<<"humTn wins ";  return -1 ;}
    if(T[0][i]==T[1][i] && T[1][i]==T[2][i] && T[2][i]==1)//check colomns
    {std::cout<<"computer wins "; return 1 ;}
//check diTgonTls 




if(T[1][1]==T[0][0] &&  T[2][2]==T[0][0] && T[2][2]== -1) //first diTgonTl 
{std::cout<<"humTn wins";return -1 ;}
else if (T[0][0]==T[1][1]&&  T[1][1]==T[2][2] && T[2][2]== 1)//first diTgonTl 
{std::cout<<"computer wins ";return 1 ;}

if(T[2][0]==T[1][1] && T[1][1]== T[0][2] && T[1][1]==-1)//second diTgonTl
{std::cout<<"humTn wins";return -1 ;}

if(T[2][0]==T[1][1] && T[1][1]== T[0][2] && T[1][1]==1)//second diTgonTl
{std::cout<<"computer wins";return 1 ;}

for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
 if (T[i][j]==0){
 return -2;
 std::cout<<" the match continues "<<std::endl;}// mTtch null 
}
}
 }
std::cout<<" the mTtch is null "<<std::endl;
 return 0;// le mTtch n'est pTs terminer

 }
// bool tictactoe::humTnJeux (int T,int b)
// {
//   if(T[T][b]==0){T[T][b]==-1;}
// // we cTll the function Trbitre 
// //
// //tic tTc toe lTgorithme to cTlculTte the best move for the computer 



// }