// lookup pro records

#include "hbpheader.h"

void prorecs(void)
{

  fstream profile;
  fstream boxrecords;

  struct boxer bxr;
  struct records bxrec;
  int i;
  int c;
  char di[4];
  int boxerchoice;

  cout << endl;

  do
  {

  i = 0;
  c = 0;

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }

  cout << "#                  NAME        AGE WGT   HT  SUS   ACT     PRO             " << endl;
  cout << "-------------------------------------------------------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active > 0 && bxr.amorpro == 1 && bxr.wc == 0)
    {
    cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
    << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
    << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.inactive  << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses
    << setw(2) << '-' << setw(2) << bxr.draws << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")" << endl;
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
         cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
        }


    while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
   {
    if(c == boxerchoice)
       {
        cout << "Name: " << bxr.firstname << " " << bxr.surname << "  Country: " << bxr.country << " Suspension: " << bxr.suspend << endl;
        cout << "Alias: " << bxr.nickname << endl;
        cout << "Amateur Record: " << bxr.amwins << ":" << bxr.amloses << endl;
        cout << "Last Active: " << bxr.inactive << " Weeks Ago" << endl;
        cout << "Contests: "<< bxr.totalfights << " Won: " << bxr.wins << "(" << bxr.ko << ") Lost: " << bxr.loses << "(" << bxr.koby << ") Draw: " << bxr.draws << endl;
        cout << "Age: " << bxr.age <<" Height: "<< bxr.heightfeet << "-" << bxr.heightinches << " weight: " << bxr.weight << endl << endl;

      }
      c++;
  }


        boxrecords.open("PRORECORDS.BIN",ios::binary|ios::in);
        if(boxrecords.fail())
        {
          cout << "Could not open Pro records file - Press a key" << endl;
          getch();
          exit(1);
        }

   cout << "DATE        WEIGHT             OPPONENT        RESULT      VENUE     TITLE   " << endl;
   cout << "-----------------------------------------------------------------------------" << endl;

   while(boxrecords.read((char *)(&bxrec),STRUCTSIZEREC))
   {
    if(bxrec.recnum == boxerchoice)
       {
        cout << setw(0)  << bxrec.week;
        cout << setw(0)  << "/";
        cout << setw(2)  << right << bxrec.month;
        cout << setw(0)  << "/";
        cout << setw(0)  << bxrec.year;
        cout << setw(8)  << bxrec.weight;
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
      getch();

  boxrecords.close();
  profile.close();
   cout << endl << endl;

  }while(1);

  system("cls");

    return;
}
