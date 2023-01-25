#include "hbpheader.h"

void ratings(void);
void updatelists(void);



void nextweek(void)
{


       fstream timefile;
       fstream profile;
       fighttime ft;
       boxer bxr;
       int rb, rm, rw, rz, lb, ib, ab, ad, amfights;
       int inj, tak;
       int workhard = 0;
       char nw;

       cout << "Go to next week are you sure y/n" << endl;
       cin >> nw;

       if(nw != 'y')
       {
       return;
       }

       timefile.open("GAMETIME.BIN",ios::in|ios::binary);
       if(timefile.fail())
       {
        cout << "Could not create Time file - Press a key" << endl;
        getch();
        exit(1);
       }

      timefile.read((char *)(&ft),STRUCTSIZETIME);
      timefile.close();

       ratings();

        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }

         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))//boxer suspensions
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);
             if(bxr.suspend > 0)
             {
                bxr.suspend = bxr.suspend -1;
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }
             else
             {
                profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }
         }

        profile.close();


        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }

         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))//72 week inactive
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);
             if(bxr.active >= 1 && bxr.inactive >= 72 && bxr.wc == 0)
             {
                bxr.active = 0;
                bxr.rating = 2;
                bxr.suspend = 24;
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }
             else
             {
                profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }
         }

        profile.close();


        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }

         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))//Boxer Injuries
         {

             profile.seekp(-STRUCTSIZEPRO, ios::cur);

             inj = rand() % 1000;
             tak = rand() % 1000;

             if((bxr.active >= 1 || bxr.wc >= 1) && inj >= 8 && inj < 52 && tak <= 10)
             {
                bxr.suspend = inj;
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }
             if((bxr.active >= 1 || bxr.wc >= 1) && inj >= 52 && inj <= 80 && tak <= 10)
             {
                bxr.suspend = inj;
                bxr.active = 0;
                bxr.wc = 0;
                bxr.title = 0;
                bxr.rating = 2;
                if(inj == 80)
                {
                   inj = rand() % 400 + 80;
                   bxr.suspend = inj;
                }
                profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }
             else
             {
                profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }
         }

        profile.close();



        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }

        while(profile.read((char *)(&bxr),STRUCTSIZEPRO))//inactive +1
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);
             bxr.inactive = bxr.inactive + 1;
             profile.write((char *)(&bxr),STRUCTSIZEPRO);
         }

        profile.close();

         profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers inactive improve file - Press a key" << endl;
          getch();
          exit(1);
        }

         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))//boxer not active
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);

             ib = rand() % 100;

             if(bxr.active == 0 &&  bxr.drive > ib)
             {
                  if(bxr.conditioning > 49)
                  {
                    bxr.defence = bxr.conditioning - 2;
                    bxr.weight = bxr.weight + 1;
                  }

                 profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }
             else
             {
                 profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }
         }

        profile.close();




        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }


         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))// boxer improvements;
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);

             amfights = bxr.amwins + bxr.amloses;



             rm = rand() % 100;

             if(bxr.drive < rm && bxr.imprpoints > 0 && bxr.totalfights > 0 && bxr.active >= 1 && bxr.inactive <= 16)
             {
                 bxr.imprpoints = bxr.imprpoints - 1;

                   if(rm <= 35)
                     bxr.attack = bxr.attack + 1;
                   if(rm > 35 && rm <= 65)
                     bxr.defence = bxr.defence + 1;
                   if(rm > 65 && rm <= 85)
                   {
                     bxr.conditioning = bxr.conditioning + 2;
                   }
                   if(rm > 85 && bxr.strengh < (bxr.chin + 7))
                   {
                     bxr.strengh = bxr.strengh + 2;
                   }

                 profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }



             else if(bxr.drive < rm && bxr.imprpoints > 0 && bxr.totalfights < 1 && amfights >= 1 && bxr.active >= 1)
             {
                 bxr.imprpoints = bxr.imprpoints - 1;

                   if(rm <= 45)
                      bxr.attack = bxr.attack + 1;
                   if(rm > 45 && rm <= 85)
                      bxr.defence = bxr.defence + 1;
                   if(rm > 85 && rm <= 95)
                   {
                     bxr.conditioning = bxr.conditioning + 2;
                   }
                   if(rm > 95 && bxr.strengh < (bxr.chin + 7))
                   {
                     bxr.strengh = bxr.strengh + 2;
                   }

                 profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }

             else if(bxr.drive < rm && bxr.imprpoints > 0 && bxr.wc > 0)
             {
                 bxr.imprpoints = bxr.imprpoints - 1;
                 bxr.conditioning = bxr.conditioning + 2;
                 bxr.baseweight = bxr.baseweight - 1;


                 profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }

             else
             {
             profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

        }
        profile.close();







        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }

        if(ft.week == 4)
        {
          while(profile.read((char *)(&bxr),STRUCTSIZEPRO))// boxer ability boost or drop
            {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);

            ab = rand() % 100;
            amfights = bxr.amwins + bxr.amloses;

            if(bxr.drive <= ab && bxr.imprpoints > 0 && bxr.totalfights < 1 && amfights >= 1 && amfights <= 6 && bxr.active >= 1 && bxr.inactive <= 4)
            {
                   rb = rand() % 100;
                   if(rb <= 45)
                      bxr.attack = bxr.attack + 1;
                   else if(rb <= 85)
                      bxr.defence = bxr.defence + 1;
                   else if(rb <= 95)
                   {
                     bxr.conditioning = bxr.conditioning + 2;
                     bxr.baseweight = bxr.baseweight - 1;
                   }
                   else
                   {
                     bxr.strengh = bxr.strengh + 2;
                     bxr.baseweight = bxr.baseweight + 1;
                   }
            }

            if(bxr.drive <= ab && bxr.imprpoints > 0 && bxr.totalfights > 0 && bxr.totalfights <= 6 && bxr.active >= 1 && bxr.inactive <= 4)
            {

              bxr.conditioning = bxr.conditioning + 2;

            }

            if(bxr.drive > ab && bxr.imprpoints <= 0 && bxr.conditioning > 50 && bxr.power > 14 && bxr.chin > 14 && bxr.totalfights > 9 && bxr.age > 24 && bxr.loses > 2)
            {
              if(bxr.koby <= 3)
              {
                 bxr.conditioning = bxr.conditioning - 2;
                 bxr.baseweight = bxr.baseweight + 2;
              }
              else
              {
                 bxr.attack = bxr.attack  - 1;
                 bxr.defence = bxr.defence  - 1;
              }
             }

             lb = rand() % 150;

             if(bxr.drive > lb && bxr.totalfights > 0 && bxr.inactive > 24)
             {
               lb = rand() % 100;
               if(lb < 25 && bxr.conditioning > 49)
               bxr.conditioning = bxr.conditioning - 2;
               if(lb >= 25 && lb < 50 && bxr.strengh > 24)
               bxr.strengh = bxr.strengh - 1;
               if(lb >= 50 && lb < 75 && bxr.attack > 24)
               bxr.attack = bxr.attack - 1;
               if(lb >= 75 && bxr.defence > 24)
               bxr.defence = bxr.defence - 1;
             }

             lb = rand() % 150;

             if(bxr.drive > lb && bxr.inactive > 52)
             {
               lb = rand() % 100;
               if(lb < 50 && bxr.power > 24)
               bxr.power = bxr.power - 1;
               if(lb >= 50 && bxr.chin > 24)
               bxr.chin = bxr.chin - 1;
             }

             lb = rand() % 250;

             if(lb < 100 && bxr.attack > 11 && bxr.defence > 11)
             {
               if(lb >= 50)
               {
                 bxr.attack = bxr.attack  + 1;
                 bxr.defence = bxr.defence  - 1;
               }
               else
               {
                 bxr.attack = bxr.attack  - 1;
                 bxr.defence = bxr.defence  + 1;
               }

             }

           profile.write((char *)(&bxr),STRUCTSIZEPRO);

         }
        }

        profile.close();


        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }


          if(ft.week == 4 && ft.month == 12)// boxer age
          {
             while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
            {
            profile.seekp(-STRUCTSIZEPRO, ios::cur);




               ad = rand() % 100;

               if(bxr.age > 37 && bxr.age < 49 && bxr.drive < ad && bxr.koby <= 2)
               {
                   if(bxr.attack > 2)
                   {
                      bxr.attack = bxr.attack - 1;
                   }
                      bxr.defence = bxr.defence + 1;
                      bxr.conditioning = bxr.conditioning + 2;
                      bxr.strengh = bxr.strengh + 1;
               }

               if(bxr.age > 29 && bxr.age < 46 && bxr.drive > ad)
               {
                   bxr.drive = bxr.drive + 3;
                   bxr.baseweight = bxr.baseweight + 1;
                   if(bxr.attack > 2)
                      bxr.attack = bxr.attack - 1;
                   if(bxr.defence > 2)
                      bxr.defence = bxr.defence - 1;
                   if(bxr.conditioning > 2)
                      bxr.conditioning = bxr.conditioning - 2;
               }

               if(bxr.age > 45 && bxr.drive > ad)
               {
                   bxr.drive = bxr.drive + 3;
                   bxr.baseweight = bxr.baseweight + 4;
                   if(bxr.attack > 4)
                      bxr.attack = bxr.attack - 4;
                   if(bxr.defence > 4)
                      bxr.defence = bxr.defence - 4;
                   if(bxr.strengh > 2)
                      bxr.strengh = bxr.strengh - 2;
                   if(bxr.chin > 2)
                      bxr.chin = bxr.chin - 2;
                   if(bxr.power > 2)
                      bxr.power = bxr.power - 2;
                   if(bxr.conditioning > 3)
                      bxr.conditioning = bxr.conditioning - 2;
               }

               if(bxr.age < 36 && bxr.drive < ad && bxr.imprpoints < 1 && bxr.inactive <= 12 && bxr.loses <= 4 && bxr.koby <= 2)
               {
                 bxr.imprpoints = bxr.imprpoints + 1;
              }

               if(bxr.loses >= 5 && bxr.drive > ad && bxr.imprpoints > 0)
               {
                  bxr.imprpoints = bxr.imprpoints - 1;
               }

               if(bxr.koby >= 5)
               {
                   bxr.drive = bxr.drive + 3;
                   if(bxr.imprpoints > 0)
                      bxr.imprpoints = bxr.imprpoints - 1;
                   if(bxr.attack > 4)
                      bxr.attack = bxr.attack - 4;
                   if(bxr.defence > 4)
                      bxr.defence = bxr.defence - 4;
                   if(bxr.strengh > 2)
                      bxr.strengh = bxr.strengh - 2;
                   if(bxr.chin > 2)
                      bxr.chin = bxr.chin - 2;
                   if(bxr.power > 2)
                      bxr.power = bxr.power - 2;
                   if(bxr.conditioning > 3)
                      bxr.conditioning = bxr.conditioning - 2;
               }


               if(bxr.age > 33 && bxr.age <= 45)
               {
                  if(bxr.power > 5)
                     bxr.power  = bxr.power - 1;
               }

               if(bxr.age > 45)
               {
                  if(bxr.power > 5)
                     bxr.power  = bxr.power - 1;
                  if(bxr.strengh > 5)
                     bxr.strengh = bxr.strengh - 1;
                  if(bxr.baseweight > 220)
                  bxr.baseweight = bxr.baseweight - 2;
                  if(bxr.weight > 220)
                  bxr.weight = bxr.weight - 2;
               }

               if(bxr.age > 69 && bxr.age < 100)
               {
                  if(bxr.baseweight > 59)
                  bxr.baseweight = bxr.baseweight - 5;
                  if(bxr.weight > 59)
                  bxr.weight = bxr.weight - 5;
               }

               if(bxr.age < 100)
               {
                 bxr.age = bxr.age + 1;
                 if(bxr.age >= 60)
                 {
                   bxr.active = 0;
                   bxr.wc = 0;
                 }

               }

              if(bxr.age >= 30)
              {
              bxr.drive = bxr.drive + 1;
              }


            profile.write((char *)(&bxr),STRUCTSIZEPRO);
            }
          }


          profile.close();


        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }



         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))// boxer weight
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);

             rw = rand() % 100;



        if(bxr.roids > 0 && bxr.roids < 7)
             {
                    if(bxr.conditioning > 74)
                       bxr.conditioning = bxr.conditioning - 2;
                    if(bxr.attack > 24)
                       bxr.attack = bxr.attack - 1;
                    if(bxr.strengh > 24)
                       bxr.strengh = bxr.strengh - 2;
                    if(bxr.power > 24)
                       bxr.power = bxr.power - 1;

             }

         if(bxr.roids > 0)
         bxr.roids = bxr.roids - 1;

        if(bxr.active > 0 && bxr.heightinches == 0 && bxr.weight > 220)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }

        if(bxr.active > 0 && bxr.heightinches == 1 && bxr.weight > 225)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }
        }
        if(bxr.active > 0 && bxr.heightinches == 2 && bxr.weight > 230)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }
        }

        if(bxr.active > 0 && bxr.heightinches == 3 && bxr.weight > 235)
       {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }

        if(bxr.active > 0 && bxr.heightinches == 4 && bxr.weight > 240)
       {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }

        if(bxr.active > 0 && bxr.heightinches== 5 && bxr.weight > 245)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }

        if(bxr.active > 0 && bxr.heightinches == 6 && bxr.weight > 250)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }

        if(bxr.active > 0 && bxr.heightinches == 7 && bxr.weight > 255)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }
        if(bxr.active > 0 && bxr.heightinches == 8 && bxr.weight > 260)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }
        if(bxr.active > 0 && bxr.heightinches == 9 && bxr.weight > WEIGHTLIMIT)
        {

            if(bxr.drive < rw)
            {
                bxr.baseweight = bxr.baseweight - 1;
            }

        }

            rw = rand() % 100;

            if(bxr.weight > bxr.baseweight && bxr.totalfights > 0 && bxr.drive < rw && bxr.active > 0)
             {
                 bxr.weight = bxr.weight - 1;
             }
            if(bxr.weight > bxr.baseweight && bxr.drive > rw && bxr.baseweight > CRUZERLIMIT)
             {
                 bxr.weight = bxr.weight + 1;
             }
            if(bxr.weight < bxr.baseweight)
             {
                 bxr.weight = bxr.weight + 1;
             }

            rw = rand() % 100;

            if(bxr.weight > CRUZERLIMIT && bxr.baseweight <= CRUZERLIMIT && bxr.totalfights > 0 && bxr.drive < rw && bxr.wc < 1)
            {
              bxr.weight = CRUZERLIMIT;
              rz = rand() % 8;
              bxr.weight = bxr.weight - rz;
            }

            rw = rand() % 100;

            if(bxr.drive < rw)
             {
                do
                {
                    rw = rand() % 100;
                    workhard = workhard + 1;
                    bxr.weight = bxr.weight - 1;
                }while(bxr.weight > bxr.baseweight && workhard < 4 && bxr.active > 0 && bxr.drive < rw);

             }
            else
             {
                bxr.weight = bxr.weight + 1;
             }

             workhard = 0;

             if(bxr.active > 0 && bxr.weight > 285)
             {
               do
                {
                    rw = rand() % 100;
                    workhard = workhard + 1;
                    bxr.weight = bxr.weight - 1;

                }while(workhard < 11 && rw > 25);

               bxr.baseweight = 275;
             }

             workhard = 0;

             if(bxr.active > 0 && bxr.weight > (bxr.baseweight + 10))
             {
               do
                {
                    rw = rand() % 100;
                    workhard = workhard + 1;
                    bxr.weight = bxr.weight - 1;

                }while(workhard < 4 && rw > 25);

             }

             workhard = 0;

             if(bxr.active < 1 && bxr.weight > (bxr.baseweight + 20))
             {
               do
                {
                    rw = rand() % 100;
                    workhard = workhard + 1;
                    bxr.weight = bxr.weight - 1;

                }while(workhard < 21 && rw > 15);

             }

             workhard = 0;

             if(bxr.active < 1 && bxr.weight > 320)
             {
               do
                {
                    rw = rand() % 100;
                    workhard = workhard + 1;
                    bxr.weight = bxr.weight - 1;

                }while(workhard < 21 && rw > 15);

               bxr.baseweight = 300;
             }

             if(bxr.weight <= bxr.baseweight && bxr.baseweight > CRUZERLIMIT)
             {
                rw = rand() % 100;
                if(rw < 25)
                    bxr.weight = bxr.weight + 1;
                else if(rw < 50)
                    bxr.weight = bxr.weight + 2;
                else if(rw < 75)
                    bxr.weight = bxr.weight + 3;
                else
                  bxr.weight = bxr.weight - 1;
             }

        profile.write((char *)(&bxr),STRUCTSIZEPRO);


         }

       profile.close();



        profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
        }


         while(profile.read((char *)(&bxr),STRUCTSIZEPRO))// boxer stat check;
         {
             profile.seekp(-STRUCTSIZEPRO, ios::cur);

             if(bxr.age < 53 && (bxr.attack < 25 || bxr.defence < 25))
             {


                   if(bxr.age < 36 && bxr.active >= 1 && bxr.attack < 10 && bxr.loses > bxr.wins && bxr.wins >= 3 && bxr.koby <= 10)
                     bxr.attack = 10;
                   if(bxr.age < 36 && bxr.active >= 1 && bxr.defence < 10 && bxr.loses > bxr.wins && bxr.wins >= 3 && bxr.koby <= 10)
                     bxr.defence = 10;
                   if(bxr.attack < 20 && bxr.loses <= bxr.wins && bxr.wins >= 6)
                     bxr.attack = 20;
                   if(bxr.defence < 20 && bxr.loses <= bxr.wins && bxr.wins >= 6)
                     bxr.defence = 20;
                   if(bxr.attack < 25 && bxr.amwins >= 6 && bxr.totalfights == 0)
                     bxr.attack = 25;
                   if(bxr.defence < 25 && bxr.amwins >= 6 && bxr.totalfights == 0)
                     bxr.defence = 25;

                 profile.write((char *)(&bxr),STRUCTSIZEPRO);
             }


             else
             {
             profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

        }

        profile.close();



    if(ft.week == 4 && ft.month == 12)
        {
          //amchamps();
          ft.year = ft.year + 1;
          ft.month = 1;
          ft.week = 1;
        }
    else if(ft.week == 4)
        {
          ft.week = 1;
          ft.month = ft.month + 1;
        }
    else
          ft.week = ft.week + 1;


     timefile.open("GAMETIME.BIN",ios::out|ios::binary);
        if(timefile.fail())
         {
  	       cout << "Could not create Time file - Press a key" << endl;
           getch();
           exit(1);
         }

       timefile.write((char *)(&ft),STRUCTSIZETIME);

       timefile.close();

       updatelists();


    return;

}
