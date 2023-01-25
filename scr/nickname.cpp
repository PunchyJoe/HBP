#include "hbpheader.h"

void nickname(int diff)
{



  fstream profile;
  boxer bxr;

  int ch;
  int i = 0;
  int boxerchoice;
  char di[4];
  char alias[15];

  ch = diff;

  if(ch == 1)
  {


  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }

      cout << "#                   NAME      AGE WGT   HT       PRO                   AM" << endl;
      cout << "-------------------------------------------------------------------------------" << endl;


  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active == 1)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Enter Number of Boxer to set new nickname ? 0 to Exit" << endl;
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


             for(int d = 0; d <= boxerchoice; d++)
             {
              profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

            profile.seekp(-STRUCTSIZEPRO, ios::cur);
            cout << "Enter New Nickname " << endl;
            cin.getline(alias,15);
            strncpy(bxr.nickname, alias ,15);
            profile.write((char *)(&bxr),STRUCTSIZEPRO);




      profile.close();


  }









  if(ch == 2)
  {



  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }
      cout << "#           INACTIVE" << endl;
      cout << "#           NAME      AGE WGT   HT       PRO                   AM" << endl;
      cout << "-------------------------------------------------------------------------------" << endl;


  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.suspend >= 1 && bxr.active <= 0)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(8) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << "              SUSPENSION: " << bxr.suspend << endl;
    }
  }


  profile.close();

  i = 0;


   profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }
      cout << endl;
      cout << "#           ACTIVE" << endl;
      cout << "#           NAME      AGE WGT   HT       PRO                   AM" << endl;
      cout << "-------------------------------------------------------------------------------" << endl;


  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.suspend >= 1 && bxr.active >= 1)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(8) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << "              SUSPENSION: " << bxr.suspend << endl;
    }
  }




  cout << endl;

  cout << "Enter Number of Boxer to End Suspension ? 0 to Exit" << endl;
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


             for(int d = 0; d <= boxerchoice; d++)
             {
              profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

            profile.seekp(-STRUCTSIZEPRO, ios::cur);
            bxr.suspend = 0;
            profile.write((char *)(&bxr),STRUCTSIZEPRO);




      profile.close();


  }


     return;
}
