#include "hbpheader.h"

void amrecs(int noams)
{

  fstream profile;
  fstream amrecords;

  struct boxer bxr;
  struct records bxrec;
  int i;
  int c;
  int amsno;
  int boxerchoice;

  char di[4];

  amsno = noams;

  cout << endl;

  if(amsno == 0)
  {

  do
  {

  i = 0;
  c = 0;

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

   cout << "#   COUNTRY        NAME        AGE WGT   HT      AM" << endl;
   cout << "----------------------------------------------------------------------" << endl;


  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active > 0 && bxr.totalfights == 0 && bxr.amorpro == 0 && bxr.wc == 0)
    {
    cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
    << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
    << bxr.heightinches << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Number of boxer? 0 to Exit" << endl;
  cin  >> di;

  boxerchoice = atoi(di);

  if(boxerchoice == 0)
    {
      profile.close();
      system("cls");
      return;
    }

   --i;
   -- boxerchoice;

  if(boxerchoice > i)
     {
      profile.close();
      system("cls");
      return;
     }

    profile.close();

    profile.open("PROBOXERS.BIN",ios::binary|ios::in);
        if(profile.fail())
         {
         cout << "Could not open Amateur Boxers file - Press a key" << endl;
        _getch();
        exit(1);
        }


    while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
   {
    if(c == boxerchoice)
       {
        cout << "Name: " << bxr.firstname << " " << bxr.surname << "  Country: " << bxr.country << " Suspension: " << bxr.suspend << endl;
        cout << "Last Active: " << bxr.inactive << " Weeks Ago" << endl;
        cout << "Age: " << bxr.age <<" Height: "<< bxr.heightfeet << "-" << bxr.heightinches << " weight: " << bxr.weight << endl;
        cout << "Amateur Record: " << bxr.amwins << ":" << bxr.amloses << endl << endl;


      }
      c++;
  }

        amrecords.open("AMRECORDS.BIN",ios::binary|ios::in);
        if(amrecords.fail())
        {
          cout << "Could not open Pro records file - Press a key" << endl;
          _getch();
          exit(1);
        }

   cout << "DATE        WEIGHT             OPPONENT        RESULT      VENUE             " << endl;
   cout << "-----------------------------------------------------------------------------" << endl;
   while(amrecords.read((char *)(&bxrec),STRUCTSIZEREC))
   {
    if(bxrec.recnum == boxerchoice)
       {
        cout << setw(0)  << bxrec.week;
        cout << setw(0)  << "/";
        cout << setw(2)  << right << bxrec.month;
        cout << setw(0)  << "/";
        cout << setw(0)  << bxrec.year;
        cout << setw(8) << bxrec.weight;
        cout << setw(18) << right << bxrec.opsurname;
        cout << setw(4)  << right << bxrec.opfirstname;
        cout << setw(4)  << " - ";
        cout << setw(10) << right << bxrec.outcome;
        cout << setw(4)  << " - ";
        cout << setw(4)  <<  bxrec.venue;
        cout << setw(4)  <<  " - ";
        cout << setw(4)  <<  bxrec.title << endl;
       }
   }



      cin.sync();
      _getch();

  amrecords.close();
  profile.close();
   cout << endl << endl;

  }while(1);

  }






  if(amsno == 1)
  {

  do
  {

  i = 0;
  c = 0;

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

   cout << "#   COUNTRY        NAME        AGE WGT   HT      AM" << endl;
   cout << "----------------------------------------------------------------------" << endl;


  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active > 0 && bxr.totalfights == 0 && bxr.amorpro == 0 && bxr.wc == 0)
    {
    cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
    << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
    << bxr.heightinches << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Enter number of amateur boxer to turn pro? 0 to Exit" << endl;
  cin  >> di;

  boxerchoice = atoi(di);

  if(boxerchoice == 0)
    {
      profile.close();
      return;
    }

   --i;
   -- boxerchoice;

  if(boxerchoice > i)
     {
      profile.close();
      return;
     }

    profile.close();

    profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          _getch();
          exit(1);
        }

          for(int d = 0; d <= boxerchoice; d++)
             {
              profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

          profile.seekp(-STRUCTSIZEPRO, ios::cur);

          bxr.amorpro = 1;

          profile.write((char *)(&bxr),STRUCTSIZEPRO);

          profile.close();


   cout << endl << endl;

  }while(1);

  }
   system("cls");

    return;
}
