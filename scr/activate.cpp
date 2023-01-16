#include "hbpheader.h"

void activate(void)
{
   fstream profile;
  boxer bxr;

  int i = 0;
  int boxerchoice;
  char di[4];

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }


      cout << "#                   NAME      AGE WGT   HT          PRO                  AM" << endl;
      cout << "-------------------------------------------------------------------------------" << endl;


  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active == 0 && bxr.age <= 60)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Number of boxer to activate? 0 to Exit" << endl;
  cin  >> di;

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


             for(int d = 0; d <= boxerchoice; d++)
             {
                profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

            if(bxr.age <= 60)
            {
               profile.seekp(-STRUCTSIZEPRO, ios::cur);
               bxr.active = 1;
               profile.write((char *)(&bxr),STRUCTSIZEPRO);
            }
            else
            {
               cout << "Boxer is too old" << endl << endl;
            }

      profile.close();

     system("cls");

     return;
}
