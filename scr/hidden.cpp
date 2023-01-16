
#include "hbpheader.h"

void master(void);
void namechange(void);
void amrandomize(void);
void ctrychange(void);
void bulkweight(void);
void gymwork(void);
void vacate(int vorp);
void sparring(void);
void ratingpoints(void);
void getinshape(void);
void ranctry(void);
void backup(int bk);
void updatelists(void);
void nickname(int diff);


void hidden(void)
{

char gamechoice;


 do
 {

  fseek(stdin,0,SEEK_END);

  cout <<endl << endl;
  cout << "                     HEAVYWEIGHT BOXING PROMOTER" << endl << endl;

  cout << "                          HIDDEN DEVELOPER MENU:" << endl << endl;
  cout << "                          A.Master Ratings on Paper" << endl;
  cout << "                          B.Change Boxer Name" << endl;
  cout << "                          C.Change Boxer Country" << endl;
  cout << "                          D.Sparring" << endl;
  cout << "                          E.Boxer Bulk Weight (+204) to Above 211 (MAX: 217)" << endl;
  cout << "                          F.Training" << endl;
  cout << "                          G.Rating Points" << endl;
  cout << "                          J.Get in Shape" << endl;
  cout << "                          K.Vacate Title" << endl;
  cout << "                          L.Award Title" << endl;
  cout << "                          M.End Suspension" << endl;
  cout << "                          N.Generate Host Country (plus random 100% score)" << endl;
  cout << "                          P.Generate List on Paper" << endl;
  cout << "                          X.Backup Game Files" << endl;
  cout << "                          Z.GO BACK NOW" << endl;
  cin  >> gamechoice;

      gamechoice = tolower(gamechoice);

	  switch(gamechoice)
	  {
         case 'a': master();
		  break;
         case 'b': namechange(); updatelists();
		  break;
         case 'c': ctrychange(); updatelists();
		  break;
		 case 'd': sparring();
         break;
         case 'e': bulkweight(); updatelists();
		  break;
         case 'f': gymwork(); updatelists();
		  break;
		 case 'g': ratingpoints();
		  break;
         case 'j': getinshape(); updatelists();
          break;
         case 'k': vacate(1); updatelists();
          break;
         case 'l': vacate(2); updatelists();
          break;
         case 'm': nickname(2); updatelists();
		  break;
         case 'n': ranctry();
          break;
         case 'p': amrandomize();
          break;
         case 'x': backup(2); updatelists();
          break;
         case 'z':  system("cls"); return;
		  break;
         default: return;
	  }


 }while(1);

}
