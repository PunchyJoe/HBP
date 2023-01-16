//continuegame

#include "hbpheader.h"

void inactiveboxers(void);
void worldhistory(void);
void champions(void);
void allambouts(void);
void worldprorankingsz(void);
void allrecords(void);
void updatelists(void);
void wcb(void);

void lists(void)
{

char gamechoice;


 do
 {

  fseek(stdin,0,SEEK_END);

  cout <<endl << endl;
  cout << "                     HEAVYWEIGHT BOXING PROMOTER" << endl << endl;
  cout << "                          BOXER LIST MENU:" << endl << endl;
  cout << "                          A.Champions" << endl;
  cout << "                          B.Ratings" << endl;
  cout << "                          C.Title Lineage History" << endl;
  cout << "                          D.All Results" << endl;
  cout << "                          E.Boxer Index" << endl;
  cout << "                          F.Retired or Inactive Boxers" << endl;
  cout << "                          Y.EVERY BOXER EVER LOOKUP" << endl;
  cout << "                          Z.GO BACK" << endl;
  cin  >> gamechoice;

     gamechoice = tolower(gamechoice);

	  switch(gamechoice)
	  {
	     case 'a': champions();
		 break;
         case 'b': worldprorankingsz();
		 break;
         case 'c': worldhistory();
         break;
         case 'd': allambouts();
         break;
         case 'e': wcb();
         break;
         case 'f': inactiveboxers();
         break;
         case 'y': allrecords();
         break;
         case 'z': system("cls"); return;
         break;
         default: system("cls"); return;
	  }


 }while(1);

}
