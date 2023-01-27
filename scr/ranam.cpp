#include "hbpheader.h"



void randam(void)
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
   cout << "  GENERATING RANDOM AMATEUR..................PRESS A KEY" << endl << endl;
   _getch();


 profile.open("PROBOXERS.BIN",ios::out|ios::app|ios::binary);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

  strncpy_s(bxr.firstname, 20, " ", 20);
  strncpy_s(bxr.surname, 30, " ", 30);
  strncpy_s(bxr.nickname, 15, " ", 15);

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



          gc = rand() % 105 + 1;

         if(gc <= 40)
            strncpy_s(bxr.country, "CUB" , 15);
         else if(gc <= 65)
            strncpy_s(bxr.country, "RUS" , 15);
         else if(gc <= 70)
            strncpy_s(bxr.country, "USA" , 15);
         else if(gc <= 75)
            strncpy_s(bxr.country, "ENG" , 15);
         else if(gc <= 78)
            strncpy_s(bxr.country, "NGA" , 15);
         else if(gc == 79)
            strncpy_s(bxr.country, "IRL" , 15);
         else if(gc == 80)
            strncpy_s(bxr.country, "ITA" , 15);
         else if(gc == 81)
            strncpy_s(bxr.country, "DEU" , 15);
         else if(gc == 82)
            strncpy_s(bxr.country, "AUS" , 15);
         else if(gc == 83)
            strncpy_s(bxr.country, "NIL" , 15);
         else if(gc == 84)
            strncpy_s(bxr.country, "JPN" , 15);
         else if(gc == 85)
            strncpy_s(bxr.country, "CHN" , 15);
         else if(gc == 86)
            strncpy_s(bxr.country, "FRA" , 15);
         else if(gc == 87)
            strncpy_s(bxr.country, "SWE" , 15);
         else if(gc == 88)
            strncpy_s(bxr.country, "NZL" , 15);
         else if(gc == 89)
            strncpy_s(bxr.country, "BRA" , 15);
         else if(gc == 90)
            strncpy_s(bxr.country, "ZAF" , 15);
         else if(gc == 91)
            strncpy_s(bxr.country, "JAM" , 15);
         else if(gc == 92)
            strncpy_s(bxr.country, "IND" , 15);
         else if(gc == 93)
            strncpy_s(bxr.country, "SCO" , 15);
         else if(gc == 94)
            strncpy_s(bxr.country, "WAL" , 15);
         else if(gc == 95)
            strncpy_s(bxr.country, "CAN" , 15);
         else if(gc == 96)
            strncpy_s(bxr.country, "DNK" , 15);
         else if(gc == 97)
            strncpy_s(bxr.country, "POL" , 15);
         else if(gc == 98)
            strncpy_s(bxr.country, "TUR" , 15);
         else if(gc == 99)
            strncpy_s(bxr.country, "MEX" , 15);
         else if(gc == 100)
            strncpy_s(bxr.country, "BLR" , 15);
         else if(gc == 101)
            strncpy_s(bxr.country, "UKR" , 15);
         else if(gc == 102)
            strncpy_s(bxr.country, "ROU" , 15);
         else if(gc == 103)
            strncpy_s(bxr.country, "HUN" , 15);
         else if(gc == 104)
            strncpy_s(bxr.country, "BGR" , 15);
         else
            strncpy_s(bxr.country, "MDA" , 15);

   bxr.age = rand() % 3 + 17;

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

  if(inchis <= 80)
  {
    bxr.heightinches = rand() % 3 + 2;
  }
  else if(inchis > 80 && inchis <= 88)
  {
   bxr.heightinches = rand() % 5 + 5;
  }
   else
  {
   bxr.heightinches = rand() % 2;
  }


  bxr.imprpoints = rand() % 21 + 10;
  bxr.attack = rand() % 26 + 25;
  bxr.defence = rand() % 26 + 25;
  bxr.power = rand() % 26 + 25;
  bxr.strengh = rand() % 36 + 50;
  bxr.conditioning = rand() % 16 + 65;
  bxr.chin = rand() % 26 + 25;
  bxr.weight = rand() % 21 + 205;
  bxr.baseweight = bxr.weight;
  bxr.drive = rand() % 100;
  bxr.wc = 0;
  bxr.roids = 0;
  bxr.title = 0;
  bxr.amorpro = 0;
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


  if(bxr.heightinches < 3)
   {
       bxr.baseweight = bxr.baseweight - 5;
       bxr.weight = bxr.weight - 5;
  }


  if(bxr.baseweight <= CRUZERLIMIT + 7)
   {
     bxr.power = bxr.power - 5;
     bxr.conditioning = bxr.conditioning + 5;
     bxr.strengh = bxr.strengh - 5;
     bxr.defence = bxr.defence + 5;
     bxr.chin = bxr.chin - 5;
   }

   if(bxr.heightinches > 4)
   {
       bxr.baseweight = bxr.baseweight + 15;
       bxr.weight = bxr.weight + 15;
  }

  if(bxr.baseweight > 234 )
   {
     bxr.conditioning = bxr.conditioning - 5;
     bxr.strengh = bxr.strengh + 5;
   }

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
