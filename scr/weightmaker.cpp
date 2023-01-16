#include "hbpheader.h"

void weightmaker(void)
{



  fstream profile;
  boxer bxr;

  int i = 0;
  int d;
  int boxerchoice;
  int takeoff;
  char di[4];

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }

    cout << "#   COUNTRY    NAME   AGE WGT   HT  SUS     PRO                    AM" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active == 1 && bxr.amorpro == 1 && bxr.weight > 210 && bxr.weight < 218)
    {
          cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Enter Number of Boxer to cut to 210 ? 0 to Exit" << endl;
  cin >> di;

  fseek(stdin,0,SEEK_END);

    boxerchoice = atoi(di);

   if(boxerchoice == 0)
    {
      profile.close();
      return;
    }

   -- boxerchoice;
   -- i;

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
        getch();
        exit(1);
        }


             for(d = 0; d <= boxerchoice; d++)
             {
              profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

            profile.seekp(-STRUCTSIZEPRO, ios::cur);

            if (bxr.weight <= 217)
            {
               bxr.weight = 210;

               takeoff = rand() % 100;
               if(bxr.drive < takeoff && bxr.baseweight > 207)
                  bxr.baseweight = bxr.baseweight - 1;

               cout << endl << endl;
               cout << " " << bxr.firstname << " " << bxr.surname << " makes weight " << bxr.weight  <<endl << endl;

               profile.write((char *)(&bxr),STRUCTSIZEPRO);
               getch();
            }
            else
            {
               cout << "BOXER IS TOO HEAVY!!!" << endl;
               getch();
            }


      profile.close();

     system("cls");

     return;
}
