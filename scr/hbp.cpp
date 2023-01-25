// Heavyweight Boxing Promoter

#include "hbpheader.h"

void newgame(void);
void congame(void);
void help(void);
void about(void);


int main()
{

 system("mode con cols=100");
 system("mode con lines=25");
 system("color F0");
 system("color 0F");

 SetConsoleTitle("HBP");
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD c;
 c.X = 100;
 c.Y = 300;
 SetConsoleScreenBufferSize(hConsole, c);



 char gamechoice;
 int game = 1;

 do
 {
    fseek(stdin,0,SEEK_END);

  cout << endl << endl << endl;
  cout << setw(50) << "HEAVYWEIGHT BOXING PROMOTER" << endl << endl;
  cout << setw(40) << "MAIN MENU:" << endl << endl;
  cout << setw(40) << "N.New Game" << endl;
  cout << setw(45) << "C.Continue Game" << endl;
  cout << setw(36) << "H.Help" << endl;
  cout << setw(37) << "A.About" << endl;
  cout << setw(36) << "X.Exit" << endl;
  cin  >> gamechoice;

  gamechoice = tolower(gamechoice);

	  switch(gamechoice)
	  {
		  case 'n': newgame();
		  break;
		  case 'c': system("cls"); congame();
		  break;
		  case 'h': help();
		  break;
		  case 'a': about();
		  break;
		  case 'x': game = 0;
		 {
          game = 0;
		  break;
         }
         default:
         {
         cout << "Invalid choice press a key and try again" << endl;
         getch();
         }
	  }


 } while(game);


 cout << endl;


 return EXIT_SUCCESS;

}//end main





