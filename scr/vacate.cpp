#include "hbpheader.h"

void vacate(int vorp)
{



  fstream profile;
  boxer bxr;
  int dufos;
  int boxer1;
  int i = 0;
  int d;
  int titlechoice;
  char di[4];

  dufos = vorp;

  if(dufos == 1)
  {
       cout << endl << endl << endl;
       cout << setw(40) << "TITLE TO VACATE:" << endl << endl;
       cout << "        1: WORLD TITLE" << endl;
       cout << "        2: -210 WORLD TITLE" << endl;
       cout << "        3. MANDATORY CHALLENGER" << endl;
       cout << "        4. INTER-CONTINENTAL TITLE" << endl;
       cout << "        5. INTERNATIONAL TITLE" << endl;
       cout << "        6: AMERICAS TITLE" << endl;
       cout << "        7: EUROPEAN TITLE" << endl;
       cout << "        8. AFRICAN TITLE" << endl;
       cout << "        9. AUSTRALASIA TITLE" << endl;
       cout << "       10. ASIA TITLE" << endl;

  cout << endl;

  cout << "Pick title to Vacate ? 0 to Exit" << endl;
  cin >> di;

  titlechoice = atoi(di);

   if(titlechoice <= 0 || titlechoice > 10)
    {
      cin.clear();
      //cin.ignore(numeric_limits<streamsize>::max(), '\n');
      scanf_s("%*s");
      return;
    }



     profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
       if(profile.fail())
       {
        cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
        }



      while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);
             if(titlechoice == 3 && (bxr.title >= 14 && bxr.title <= 20))
             {
                bxr.title = bxr.title - 10;
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
                profile.close();
                return;
             }
             else if(titlechoice != 3 && (bxr.title >= 14 && bxr.title <= 20))
             {
                bxr.title = 3;
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
                profile.close();
                return;
             }

             else if(bxr.title == titlechoice)
             {
                bxr.title = 0;
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
                profile.close();
                return;
             }
             else
             {
                profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }
         }
  }







   if(dufos == 2)
  {

       cout << endl << endl << endl;
       cout << setw(40) << "AWARD TITLE:" << endl << endl;
       cout << "        1: WORLD TITLE" << endl;
       cout << "        2: -210 WORLD TITLE" << endl;
       cout << "        3. MANDATORY CHALLENGER" << endl;
       cout << "        4. INTER-CONTINENTAL TITLE" << endl;
       cout << "        5. INTERNATIONAL TITLE" << endl;
       cout << "        6: AMERICAS TITLE" << endl;
       cout << "        7: EUROPEAN TITLE" << endl;
       cout << "        8. AFRICAN TITLE" << endl;
       cout << "        9. AUSTRALASIA TITLE" << endl;
       cout << "       10. ASIA TITLE" << endl;

  cout << endl;

  cout << "Pick title to award ? 0 to Exit" << endl;
  cin >> di;

  titlechoice = atoi(di);

   if(titlechoice <= 0 || titlechoice > 10)
    {
      cin.clear();
      //cin.ignore(numeric_limits<streamsize>::max(), '\n');
      scanf_s("%*s");
      return;
    }



      profile.open("PROBOXERS.BIN",ios::binary|ios::in);
      if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          _getch();
          exit(1);
       }

      cout << "#                  NAME       AGE WGT   HT     ACT      PRO" << endl;
      cout << "----------------------------------------------------------------------" << endl;

      while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
       {
       i++;
            if(bxr.active >= 1 && bxr.wc <= 0 && bxr.totalfights >= 6)
            {
            cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
            << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
            << bxr.heightinches << setw(7) << bxr.inactive  << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
            << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")" << endl;
           }
       }




    profile.close();

    cout << endl;

    do
     {
     cout << "Enter Number of boxer to award title to 0 to exit:" << endl;
     cin  >> di;
     boxer1 = atoi(di);
          if(boxer1 == 0)
          {
            return;
          }

     }while(boxer1 > (i+1) );

     --boxer1;

     profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
       if(profile.fail())
       {
        cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
        }


            for(d = 0; d <= boxer1; d++)
             {
              profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

                profile.seekp(-STRUCTSIZEPRO, ios::cur);
                if(titlechoice == 3 && bxr.title >= 4 && bxr.title <=10)
                {
                  bxr.title = bxr.title + 10;
                }
                else if(titlechoice >= 4 && titlechoice <= 10 && bxr.title == 3)
                {
                  bxr.title = titlechoice + 10;
                }
                else
                {
                  bxr.title = titlechoice;
                }

                profile.write((char *)(&bxr),STRUCTSIZEPRO);





  }

    profile.close();

     return;
}
