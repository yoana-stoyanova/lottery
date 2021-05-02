#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int lottery = 111;
    while(lottery/100==(lottery/10)%10 || lottery/100==lottery%10 || (lottery/10)%10==lottery%10 ||
          (lottery/100==(lottery/10)%10 && (lottery/10)%10==lottery%10))
    {
      lottery = rand()%900 + 100;
    }

    int LotteryDigits[3];
    LotteryDigits[0]=lottery/100;
    LotteryDigits[1]=(lottery/10)%10;
    LotteryDigits[2]=lottery%10;

    int guess;
    cout<<"Your guess (3 different digits): "; cin>>guess;

    int GuessDigits[3];
    GuessDigits[0]=guess/100;
    GuessDigits[1]=(guess/10)%10;
    GuessDigits[2]=guess%10;

    int br=0;

    if(GuessDigits[0]==LotteryDigits[0] && GuessDigits[1]==LotteryDigits[1] && GuessDigits[2]==LotteryDigits[2]) br=4;
    else
    {
      for(int j=0; j<3; j++)
      {
        for(int f=0; f<3; f++)
          {if(LotteryDigits[j]==GuessDigits[f]) br++;}
      }

    }

    if(br==4) cout<<"Congratulations! You guessed all of the digits correctly in the exact order. You win 10 000 dollars!\n";
    if(br==3) cout<<"You guessed all of the digits correctly. You win 3000 dollars\n";
    if(br==2) cout<<"You guessed 2 of the digits correctly. You win 2000 dollars\n";
    if(br==1) cout<<"You guessed 1 of the digits correctly. You win 1000 dollars\n";
    if(br==0) cout<<"You didn't guess any of the digits correctly. You don't win anything\n";


   return 0;
}
