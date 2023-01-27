
#include "hbpheader.h"

void randam(void);
void randpro(void);
void randclub(void);
void ranhvypro(void);
void rancruzpro(void);


void pickboxer(void)
{

 fstream timefile;
 fighttime ft;

 char gamechoice;
 int fn;



 do
 {

  timefile.open("GAMETIME.BIN",ios::in|ios::binary);
 if(timefile.fail())
  {
  	cout << "No time file exists - Press a key" << endl;
        _getch();
        return;
  }

  timefile.read((char *)(&ft),STRUCTSIZETIME);
  timefile.close();

  fn = ft.boxernumber;
  --fn;

  fseek(stdin,0,SEEK_END);

  cout <<endl << endl;
  cout << "                     HEAVYWEIGHT BOXING PROMOTER" << endl << endl;
  cout << "                             NEW BOXER MENU:" << endl << endl;
  cout << "                 COMPLETE NUNMBER OF BOXERS IS: " << fn << endl << endl;
  cout << "                          A.Create Random Junior Boxer" << endl;
  cout << "                          B.Create Random Senior Boxer" << endl;
  cout << "                          C.Create Random Club Fighter" << endl;
  cout << "                          D.Create Random +210 Senior" << endl;
  cout << "                          E.Create Random -210 Senior" << endl;
  cout << "                          Z.GO BACK NOW" << endl;
  cin  >> gamechoice;

      gamechoice = tolower(gamechoice);

	  switch(gamechoice)
	  {
         case 'a': randam();
		  break;
         case 'b': randpro();
		  break;
         case 'c': randclub();
		  break;
         case 'd': ranhvypro();
		  break;
         case 'e': rancruzpro();
		  break;
		 case 'z': system("cls"); return;
		  break;
         default: system("cls"); return;
	  }


 }while(1);

}
