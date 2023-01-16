#include "hbpheader.h"


void gymwork(void)
{

          fstream profile;
          boxer bxr;

          int i = 0;
          int lb;
          int boxerchoice;
          char di[4];
          char dii;
          char tchoice;

          profile.open("PROBOXERS.BIN",ios::binary|ios::in);
          if(profile.fail())
          {
             cout << "Could not open Pro Boxers file - Press a key" << endl;
             getch();
            exit(1);
          }

          cout << "#   COUNTRY            NAME   AGE WGT   HT  SUS     PRO                    AM" << endl;
          cout << "------------------------------------------------------------------------------" << endl;

         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
         {
           i++;
           if(bxr.suspend == 0)
           {
            cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
           }
         }

         cout << endl;

        cout << "Enter Number of Boxer to set new training? 0 to Exit" << endl;
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

             cin.sync();

             cout << "Set training program for: " << bxr.firstname << " " << bxr.surname << endl << endl;
             cout << "Is this correct? y/n" << endl;
             cin >> dii;
             dii = tolower(dii);
             if(dii =='n')
             {
                profile.close();
                return;
             }

             cin.sync();

             cout << endl << endl;
             cout << "       TRAINING PROGRAMS" << endl << endl;
             cout << "       A: CONDITIONING" << endl;
             cout << "       B: WEIGHTS" << endl;
             cout << "       C: TECHNICALL" << endl;
             cout << "       D: DROP TO 210 (-225)" << endl;
             cout << "       E: BULK TO 220 (-217)" << endl;
             cout << "       F: STEROID CYCLE" << endl;
             cout << "       G: TRAINING CAMP" << endl;
             cout << "       ANY OTHER KEY TO EXIT" << endl << endl;
             cin >> tchoice;
             tchoice = tolower(tchoice);

             cout << endl << endl;

             if(bxr.suspend > 0)
             {
                 cout << "No training took place NICE TRY HAHA" << endl << endl;
                    getch();
                    profile.close();
                    return;
             }

             if(tchoice == 'a')
             {
                lb = rand() % 100;

                if(bxr.defence <= 15 || bxr.strengh <= 15)
                {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                    getch();
                    profile.close();
                    return;
                }

               if(bxr.drive > lb)
                {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                    getch();
                    profile.close();
                    return;
                 }
                    bxr.attack = bxr.attack + 1;
                    bxr.conditioning = bxr.conditioning + 2;
                    bxr.defence = bxr.defence - 1;
                    bxr.strengh = bxr.strengh - 1;
                    bxr.baseweight = bxr.baseweight - 2;
                    bxr.suspend = 8;
                    cout << " " << bxr.firstname << " " << bxr.surname << " Starts to work on his conditioning" << endl << endl;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }



             else if(tchoice == 'b')
             {
                   lb = rand() % 100;

                   if(bxr.defence <= 15 || bxr.conditioning <= 45)
                   {
                     bxr.suspend = 1;
                     profile.write((char *)(&bxr),STRUCTSIZEPRO);
                     cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                     getch();
                     profile.close();
                     return;
                   }
                   if(bxr.drive > lb)
                   {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                    getch();
                    profile.close();
                    return;
                   }
                    bxr.attack = bxr.attack + 1;
                    bxr.conditioning = bxr.conditioning - 2;
                    bxr.defence = bxr.defence - 1;
                    bxr.strengh = bxr.strengh + 2;
                    bxr.baseweight = bxr.baseweight + 1;
                    bxr.suspend = 8;
                    cout << " " << bxr.firstname << " " << bxr.surname << " Starts to work on the weights" << endl << endl;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }

             else if(tchoice == 'c')
             {
                   lb = rand() % 100;

                   if(bxr.strengh <= 15 || bxr.conditioning <= 45)
                   {
                     bxr.suspend = 1;
                     profile.write((char *)(&bxr),STRUCTSIZEPRO);
                     cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                     getch();
                     profile.close();
                     return;
                   }
                   if(bxr.drive > lb)
                   {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                    getch();
                    profile.close();
                    return;
                   }
                    bxr.attack = bxr.attack + 1;
                    bxr.conditioning = bxr.conditioning - 2;
                    bxr.defence = bxr.defence + 1;
                    bxr.strengh = bxr.strengh - 1;
                    bxr.suspend = 8;
                    cout << " " << bxr.firstname << " " << bxr.surname << " Starts to work on the flaws in his technique" << endl << endl;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }

             else if(tchoice == 'd')
             {
                   lb = rand() % 100;

                   if(bxr.strengh <= 15 || bxr.conditioning <= 45 || bxr.baseweight > 225)
                   {
                     bxr.suspend = 1;
                     profile.write((char *)(&bxr),STRUCTSIZEPRO);
                     cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                     getch();
                     profile.close();
                     return;
                   }
                   if(bxr.drive > lb)
                   {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                    getch();
                    profile.close();
                    return;
                   }
                    bxr.baseweight = 210;
                    if(bxr.baseweight > 217)
                    {
                        bxr.conditioning = bxr.conditioning + 2;
                        bxr.strengh = bxr.strengh - 2;
                    }
                    bxr.suspend = 16;
                    cout << " " << bxr.firstname << " " << bxr.surname << " Starts to work on reaching 210 - takes 16 weeks" << endl << endl;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }
             else if(tchoice == 'e')
             {
                   lb = rand() % 100;

                   if(bxr.strengh <= 15 || bxr.conditioning <= 45 || bxr.baseweight > 217)
                   {
                     bxr.suspend = 1;
                     profile.write((char *)(&bxr),STRUCTSIZEPRO);
                     cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                     getch();
                     profile.close();
                     return;
                   }
                   if(lb > bxr.drive)
                   {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not train" << endl << endl;
                    getch();
                    profile.close();
                    return;
                   }
                    bxr.baseweight = 220;
                    if(bxr.baseweight < 204)
                    {
                        bxr.conditioning = bxr.conditioning - 2;
                        bxr.strengh = bxr.strengh + 2;
                    }
                    bxr.suspend = 16;
                    cout << " " << bxr.firstname << " " << bxr.surname << " Starts to work on bulking up to Heavyweight - takes 16 weeks" << endl << endl;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }

             else if(tchoice == 'f')
             {
                   lb = rand() % 100;

                   if(bxr.roids > 0)
                   {
                     profile.write((char *)(&bxr),STRUCTSIZEPRO);
                     cout << " " << bxr.firstname << " " << bxr.surname << " Next cycle in " << ((bxr.drive - 906) / 4) << " months" << endl << endl;
                     getch();
                     profile.close();
                     return;
                   }
                   if(lb > 74)
                   {
                    if(bxr.wc < 1)
                    {
                    bxr.suspend = 99;
                    bxr.active = 0;
                    bxr.rating = 2;
                    bxr.title = 0;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Tested positive for steroids - 2 year ban" << endl << endl;
                    }
                    if(bxr.wc > 0)
                    {
                    bxr.suspend = 1;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << " " << bxr.firstname << " " << bxr.surname << " Will not take steroids" << endl << endl;
                    }
                    getch();
                    profile.close();
                    return;
                   }

                    bxr.conditioning = bxr.conditioning + 10;
                    bxr.attack = bxr.attack + 5;
                    bxr.strengh = bxr.strengh + 10;
                    if(bxr.power <= 45)
                       bxr.power = bxr.power + 5;
                    if(bxr.imprpoints > 0)
                       bxr.imprpoints = bxr.imprpoints - 1;
                    bxr.roids = 32;
                    bxr.suspend = 16;
                    cout << " " << bxr.firstname << " " << bxr.surname << " Starts steroid cycle - takes 16 weeks" << endl << endl;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);

             }

             else if(tchoice == 'g')
             {
               lb = rand() % 150 + 51;

               if(bxr.drive >= lb || bxr.drive <= 50)
                {
                    bxr.suspend = 8;

                    if(bxr.drive > 50)
                    {
                       bxr.drive = bxr.drive + 2;
                       bxr.baseweight = bxr.baseweight + 2;
                    }

                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    profile.close();
                    cout << endl << endl;
                    return;
                 }

                    bxr.suspend = 8;
                    bxr.imprpoints = bxr.imprpoints + 1;
                    bxr.baseweight = bxr.baseweight - 2;
                    bxr.drive = bxr.drive / 2;
                    profile.write((char *)(&bxr),STRUCTSIZEPRO);
                    cout << endl << endl;
             }



            else
             {
                    cout << "No training took place" << endl << endl;
                    getch();
                    profile.close();
                    return;
             }




             getch();
             profile.close();
             return;


}
