#include "hbpheader.h"



void randclub(void)
{

  srand ( static_cast<unsigned int>(time(NULL)) );

  fstream profile;
  fstream boxname;
  fstream timefile;

  string secondname;

  boxer bxr;
  fighttime ft;

  int gc = 0;
  int fn;
  int inchis = 0;
  int firstl = 0;
  int thirdl = 0;
  int howmany = 0;
  int z = 0;
  int ohffs;
  int morechin;
  int lesspower;

  char mych;
  char bg;

   cout << endl << endl;
   cout << "  GENERATING RANDOM CLUB FIGHTER..................PRESS A KEY" << endl << endl;
   _getch();


 profile.open("PROBOXERS.BIN",ios::out|ios::app|ios::binary);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

  strncpy_s(bxr.firstname, 21, " ", 20);
  strncpy_s(bxr.surname, 31, "", 30);
  strncpy_s(bxr.nickname, 16, "", 15);

     srand ( static_cast<unsigned int>(time(NULL)) );

   firstl =  rand() % 24 + 1;
    thirdl =  rand() % 24 + 1;


 	switch (firstl)
 	{
 	case 1:
      	bxr.firstname[0] =  'A';
      	break;
 	case 2:
      	bxr.firstname[0] =  'B';
      	break;
 	case 3:
      	bxr.firstname[0] =  'C';
      	break;
 	case 4:
      	bxr.firstname[0] =  'D';
      	break;
 	case 5:
      	bxr.firstname[0] =  'E';
      	break;
 	case 6:
      	bxr.firstname[0] =  'F';
      	break;
 	case 7:
      	bxr.firstname[0] =  'G';
      	break;
 	case 8:
      	bxr.firstname[0] =  'H';
      	break;
 	case 9:
      	bxr.firstname[0] =  'I';
      	break;
 	case 10:
      	bxr.firstname[0] =  'J';
      	break;
 	case 11:
      	bxr.firstname[0] =  'K';
      	break;
 	case 12:
      	bxr.firstname[0] =  'L';
      	break;
 	case 13:
      	bxr.firstname[0] =  'M';
      	break;
 	case 14:
      	bxr.firstname[0] =  'N';
      	break;
 	case 15:
      	bxr.firstname[0] =  'O';
      	break;
 	case 16:
      	bxr.firstname[0] =  'P';
      	break;
 	case 17:
      	bxr.firstname[0] =  'Q';
      	break;
 	case 18:
      	bxr.firstname[0] =  'R';
      	break;
 	case 19:
      	bxr.firstname[0] =  'S';
      	break;
 	case 20:
      	bxr.firstname[0] =  'T';
      	break;
 	case 21:
      	bxr.firstname[0] =  'V';
      	break;
 	case 22:
      	bxr.firstname[0] =  'W';
      	break;
 	case 23:
      	bxr.firstname[0] =  'Y';
      	break;
 	case 24:
      	bxr.firstname[0] =  'Z';
      	break;
       }

    bxr.firstname[1] =  '.';

    switch (thirdl)
 	{
 	case 1:
      	bxr.firstname[2] =  'A';
      	break;
 	case 2:
      	bxr.firstname[2] =  'B';
      	break;
 	case 3:
      	bxr.firstname[2] =  'C';
      	break;
 	case 4:
      	bxr.firstname[2] =  'D';
      	break;
 	case 5:
      	bxr.firstname[2] =  'E';
      	break;
 	case 6:
      	bxr.firstname[2] =  'F';
      	break;
 	case 7:
      	bxr.firstname[2] =  'G';
      	break;
 	case 8:
      	bxr.firstname[2] =  'H';
      	break;
 	case 9:
      	bxr.firstname[2] =  'I';
      	break;
 	case 10:
      	bxr.firstname[2] =  'J';
      	break;
 	case 11:
      	bxr.firstname[2] =  'K';
      	break;
 	case 12:
      	bxr.firstname[2] =  'L';
      	break;
 	case 13:
      	bxr.firstname[2] =  'M';
      	break;
 	case 14:
      	bxr.firstname[2] =  'N';
      	break;
 	case 15:
      	bxr.firstname[2] =  'O';
      	break;
 	case 16:
      	bxr.firstname[2] =  'P';
      	break;
 	case 17:
      	bxr.firstname[2] =  'Q';
      	break;
 	case 18:
      	bxr.firstname[2] =  'R';
      	break;
 	case 19:
      	bxr.firstname[2] =  'S';
      	break;
 	case 20:
      	bxr.firstname[2] =  'T';
      	break;
 	case 21:
      	bxr.firstname[2] =  'V';
      	break;
 	case 22:
      	bxr.firstname[2] =  'W';
      	break;
 	case 23:
      	bxr.firstname[2] =  'Y';
      	break;
 	case 24:
      	bxr.firstname[2] =  'Z';
      	break;
       }



     boxname.open("BOXERNAMES.txt",ios::in);
     if(boxname.fail())
     {
        cout << "Could not read from boxer names file - Press a key" << endl;
        _getch();
        exit(1);
     }


     do
     {
     boxname.seekp(0, ios::beg);
     howmany = rand() % 88799 + 1;

     for(z = 0; z <= howmany; z++)
     {

         getline(boxname, secondname);
         ohffs = secondname.length();
     }

     }while(ohffs > 14);

     strcpy_s(bxr.surname, secondname.c_str());

     for(z = 1; z < ohffs; z++)
     {
         mych = bxr.surname[z];
         mych = tolower(mych);
         bxr.surname[z] = mych;
     }




          gc = rand() % 100 + 1;



         if(gc <= 50)
            strncpy_s(bxr.country, "USA" , 15);
         else if(gc <= 80)
            strncpy_s(bxr.country, "ENG" , 15);
         else if(gc <= 97)
            strncpy_s(bxr.country, "IRL" , 15);
         else if(gc == 98)
            strncpy_s(bxr.country, "SCO" , 15);
         else if(gc == 99)
            strncpy_s(bxr.country, "WAL" , 15);
         else
            strncpy_s(bxr.country, "NIL" , 15);



      bxr.age = rand() % 6 + 28;

   cout << "First Name: " << bxr.firstname << "\nLast Name:  " << bxr.surname << "\nCountry:    " << bxr.country << "\nAge:        " << bxr.age << endl;
   cout << "                          Is this correct y/n" << endl;
   cin >> bg;

   if(bg == 'n' || bg == 'N')
   {
       cout << "     OK BOXER SCRAPPED!" << endl << endl;
       _getch();
       profile.close();
       return;
   }


  cout << "     OK BOXER CREATED!" << endl << endl;
  _getch();


   cin.sync();


  bxr.active = 1;

  bxr.heightfeet = 6;

  inchis = rand() % 100;

  if(inchis < 80)
  {
    bxr.heightinches = rand() % 4;
  }
  else
  {
   bxr.heightinches = rand() % 10;
  }

  bxr.imprpoints = rand() % 6;
  bxr.attack = rand() % 6 + 25;
  bxr.defence = rand() % 6 + 25;
  bxr.power = rand() % 16 + 25;
  bxr.strengh = rand() % 36 + 50;
  bxr.conditioning = rand() % 31 + 50;
  bxr.chin = rand() % 16 + 25;
  bxr.weight = rand() % 61 + 205;
  bxr.baseweight = bxr.weight;
  bxr.drive = rand() % 100;
  bxr.wc = 1;
  bxr.roids = 0;
  bxr.title = 0;
  bxr.amorpro = 1;
  bxr.totalfights = 0;
  bxr.wins = 0;
  bxr.loses = 0;
  bxr.draws = 0;
  bxr.ko = 0;
  bxr.koby = 0;
  bxr.amwins = 0;
  bxr.amloses = 0;
  bxr.suspend = 0;
  bxr.active = 1;
  bxr.inactive = 0;
  bxr.rating = 2;

  lesspower = rand() % 11;
  morechin = rand() % 6;
  bxr.power = bxr.power  - lesspower;
  bxr.chin = bxr.chin + morechin;

  if(bxr.strengh > (bxr.chin + 7))
  {
      bxr.strengh = bxr.chin + 7;
  }


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
   bxr.fighternumber = fn;
   fn = fn + 1;
   ft.boxernumber = fn;


  timefile.open("GAMETIME.BIN",ios::out|ios::binary);
  if(timefile.fail())
  {
  	cout << "No time file exists - Press a key" << endl;
        _getch();
        return;
  }



   timefile.write((char *)(&ft),STRUCTSIZETIME);
   timefile.close();


   profile.write((char *)(&bxr),STRUCTSIZEPRO);
   profile.close();
   boxname.close();

   return;

}

