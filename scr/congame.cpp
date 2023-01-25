//continuegame

#include "hbpheader.h"

void pickboxer(void);
void prorecs(void);
void contestpro(int noams);
void contestam(void);
void unlic(void);
void nextweek(void);
void lists(void);
void hidden(void);
void amrecs(int noams);
void weightmaker(void);
void backup(int bk);
void updatelists(void);
void nickname(int diff);
void activate(void);
void deactivate(void);

void congame(void)
{

char gamechoice;

 fstream timefile;
 fighttime ft;

 do
 {

     fseek(stdin,0,SEEK_END);

  timefile.open("GAMETIME.BIN",ios::in|ios::binary);
  if(timefile.fail())
  {
  	cout << "No time file exists - Press a key" << endl;
        getch();
        return;
  }

  timefile.read((char *)(&ft),STRUCTSIZETIME);
  timefile.close();

  cout << endl << endl << endl << endl;
  cout << "                 HEAVYWEIGHT BOXING PROMOTER" << endl << endl;
  cout << "                 Week: " << ft.week  <<  " Month: " << ft.month  << " Year: " << ft.year << endl << endl;
  cout << "                         GAME MENU:" << endl << endl;
  cout << "                         B.Create Boxer" << endl;
  cout << "                         R.Pro Records" << endl;
  cout << "                         T.Amateur Records" << endl;
  cout << "                         J.Turn Amateur Pro" << endl;
  cout << "                         C.Create Contest" << endl;
  cout << "                         P.Create PRO Contest" << endl;
  cout << "                         A.Create AMATEUR Contest" << endl;
  cout << "                         U.UNLICENSED or EXHIBITION Contest" << endl;
  cout << "                         N.Set Boxer Alias or Nickname" << endl;
  cout << "                         W.Boxer Drop Weight to 210 (-217)" << endl;
  cout << "                         E.Reactivate Boxer" << endl;
  cout << "                         D.Deactivate or Retire Boxer" << endl;
  cout << "                         L.Lists" << endl;
  cout << "                         G.Go To Next Week" << endl;
  cout << "                         M.Main Menu" << endl;
  cin  >> gamechoice;

  timefile.close();

  gamechoice = tolower(gamechoice);

	  switch(gamechoice)
	  {
		 case 'b': pickboxer(); updatelists();
         break;
		 case 'r': system("cls"); prorecs();
         break;
         case 't': system("cls"); amrecs(0);
         break;
         case 'j': backup(1); amrecs(1); updatelists();
         break;
         case 'c': backup(1); contestpro(0); updatelists();
         break;
         case 'p': backup(1); contestpro(1); updatelists();
         break;
         case 'a': backup(1); contestam(); updatelists();
         break;
         case 'u': backup(1); unlic(); updatelists();
         break;
         case 'n': nickname(1);
         break;
         case 'w': weightmaker(); updatelists();
         break;
         case 'e': activate(); updatelists();
         break;
         case 'd': deactivate(); updatelists();
         break;
         case 'l': system("cls");  lists();
         break;
         case 'g': nextweek();
         break;
		 case 'm': system("cls"); return;
         break;
         case 'x': system("cls"); hidden();
         break;
		 default: system("cls"); return;
	  }



 }while(1);

 system("cls");

 return;

}
