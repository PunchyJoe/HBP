// create boxer contests

#include "hbpheader.h"

void sparring(void)
{

    srand (time(NULL));

    fstream profile;

    struct boxer bxr;
    struct boxer boxr[2];


    int boxer1, boxer2;
    int rounds = 100;
    int i = 0;
    int c = 0;
    int round = 1;
    int boxer1winbyknockout = 0;
    int fightover = 0;


    char di1[4], di2[4];
    char dt;

    int boutattack1, boutattack2, boutdefence1, boutdefence2;
    int boxerchin1, boxerchin2;
    int boxer1chin, boxer2chin;
    int conboxer1attack, conboxer2attack, conboxer1defence, conboxer2defence;
    int conboxer1power, conboxer2power, conboxer1chin, conboxer2chin;
    int boxer1strengh, boxer2strengh, boxer1conditioning, boxer2conditioning;
    int attoff1, attoff2, defoff1, defoff2, powoff1, powoff2;
    int mark1, mark2, outclassed1, outclassed2;
    int boxer1chinround, boxer2chinround;
    int heightadv, overdisadv;
    int randomfactor;

    int totalattack1, totalattack2;
    int totalpower1, totalpower2;
    int totalstrengh1, totalstrengh2;

    chrono::seconds dura(4);


      profile.open("PROBOXERS.BIN",ios::binary|ios::in);
      if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
       }

      while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
       {
       i++;
           if(bxr.age <= 60)
            {
            cout << "#" << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(10)
            << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
            << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
            << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
           }
       }



     profile.close();

     --i;

     cout << endl;

     do
     {
     cout << "Enter Number of first boxer to Spar:" << endl;
     cin  >> di1;
     boxer1 = atoi(di1);
     }while(boxer1 > (i+1) );

     do
     {
     cout << "Enter Number of second boxer to Spar" << endl;
     cin  >> di2;
     boxer2 = atoi(di2);
     }while(boxer2 > (i+1) || boxer1 == boxer2);

     cout << endl << endl;


    --boxer1;
    --boxer2;

      profile.open("PROBOXERS.BIN",ios::binary|ios::in);
      if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
       }


     while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
     {
       if(c == boxer1)
       {

        boxr[0] = bxr;

       }
      c++;
     }


     profile.close();

     c = 0;

      profile.open("PROBOXERS.BIN",ios::binary|ios::in);
      if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          getch();
          exit(1);
       }

     while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
     {
       if(c == boxer2)
       {

        boxr[1] = bxr;

       }
      c++;
     }

     profile.close();


     if(boxr[0].age >= 60)
     {
       cout << boxr[0].firstname << " " << boxr[0].surname <<" is to old to spar"  << endl << endl;
       return;
     }
     if(boxr[1].age >= 60)
     {
       cout << boxr[1].firstname << " " << boxr[1].surname <<" is to old to spar"  << endl << endl;
       return;
     }


     cout << "                                " << "SPARRING" << endl;
     cout << "               " << boxr[0].firstname << " " << boxr[0].surname << "(" << boxr[0].country << ")                 ";
     cout <<                      boxr[1].firstname << " " << boxr[1].surname << "(" << boxr[1].country << ")" << endl;
     cout << "                  " << boxr[0].age << "                               " << boxr[1].age << endl;
     cout << "                  " << boxr[0].weight << "                              " << boxr[1].weight << endl;
     cout << "                  " << boxr[0].heightfeet << "-" << boxr[0].heightinches << "                              " << boxr[1].heightfeet << "-" << boxr[1].heightinches << endl;
     getch();



     cout << endl << endl << endl;
     cout << "START THE BUZZER (Press a key).................." << endl << endl << endl;

     cin.sync();

     getch();

     cin.sync();

    cout << endl;
    cout << boxr[0].firstname << " " << boxr[0].surname <<"  Vs  " << boxr[1].firstname << " " << boxr[1].surname << endl;

    this_thread::sleep_for(dura);


        conboxer1attack = boxr[0].attack;
        conboxer2attack = boxr[1].attack;
        conboxer1defence = boxr[0].defence;
        conboxer2defence = boxr[1].defence;
        conboxer1power = boxr[0].power;
        conboxer2power = boxr[1].power;
        conboxer1chin = boxr[0].chin;
        conboxer2chin = boxr[1].chin;
        boxer1conditioning = boxr[0].conditioning;
        boxer2conditioning = boxr[1].conditioning;
        boxer1strengh = boxr[0].strengh;
        boxer2strengh = boxr[1].strengh;


        if(boxr[0].heightinches > boxr[1].heightinches)
        {
            heightadv = boxr[0].heightinches - boxr[1].heightinches;
            conboxer1defence = conboxer1defence + heightadv;
        }
        if(boxr[1].heightinches > boxr[0].heightinches)
        {
           heightadv = boxr[1].heightinches - boxr[0].heightinches;
           conboxer2defence = conboxer2defence + heightadv;
        }




        if(boxr[0].heightinches == 0 && boxr[0].weight > 220)
        {
            overdisadv = boxr[0].weight - 220;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 1 && boxr[0].weight > 225)
        {
            overdisadv = boxr[0].weight - 225;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 2 && boxr[0].weight > 230)
        {
            overdisadv = boxr[0].weight - 230;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 3 && boxr[0].weight > 235)
        {
            overdisadv = boxr[0].weight - 235;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 4 && boxr[0].weight > 240)
        {
            overdisadv = boxr[0].weight - 240;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches== 5 && boxr[0].weight > 245)
        {
            overdisadv = boxr[0].weight - 245;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 6 && boxr[0].weight > 250)
        {
            overdisadv = boxr[0].weight - 250;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 7 && boxr[0].weight > 255)
        {
            overdisadv = boxr[0].weight - 255;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 8 && boxr[0].weight > 260)
        {
            overdisadv = boxr[0].weight - 260;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[0].heightinches == 9 && boxr[0].weight > 265)
        {
            overdisadv = boxr[0].weight - 265;
            if(conboxer1attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer1attack = conboxer1attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 0 && boxr[1].weight > 220)
        {
            overdisadv = boxr[1].weight - 220;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 1 && boxr[1].weight > 225)
        {
            overdisadv = boxr[1].weight - 225;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 2 && boxr[1].weight > 230)
        {
            overdisadv = boxr[1].weight - 230;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 3 && boxr[1].weight > 235)
        {
            overdisadv = boxr[1].weight - 235;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 4 && boxr[1].weight > 240)
        {
            overdisadv = boxr[1].weight - 240;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 5 && boxr[1].weight > 245)
        {
            overdisadv = boxr[1].weight - 245;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 6 && boxr[1].weight > 250)
        {
            overdisadv = boxr[1].weight - 250;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 7 && boxr[1].weight > 255)
        {
            overdisadv = boxr[1].weight - 255;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 8 && boxr[1].weight > 260)
        {
            overdisadv = boxr[1].weight - 260;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }

        if(boxr[1].heightinches == 9 && boxr[1].weight > 265)
        {
            overdisadv = boxr[1].weight - 265;
            if(conboxer2attack > 39)
            {
                overdisadv = overdisadv / 2;
                conboxer2attack = conboxer2attack - overdisadv;
            }

        }



         do{

         boxerchin1 = rand() % 11 + 10;
         boxerchin2 = rand() % 11 + 10;
         boxer1chin = conboxer1chin + boxerchin1;
         boxer2chin = conboxer2chin + boxerchin2;

            attoff1 = rand() %  11;
            boutattack1 = conboxer1attack + attoff1;
            defoff1 = rand() %  11;
            boutdefence1 = conboxer1defence + defoff1;
            powoff1 = rand() %  16;
            totalpower1 = conboxer1power - powoff1;

            attoff2 = rand() %  11;
            boutattack2 = conboxer2attack + attoff2;
            defoff2 = rand() %  11;
            boutdefence2 = conboxer2defence + defoff2;
            powoff2 = rand() %  16;
            totalpower2 = conboxer2power - powoff2;


             powoff1 = rand() %  14;
            if(totalpower1 >= 43 && powoff1 <= 6)
            {
               totalpower1 = totalpower1 - powoff1;
               if(totalpower1 < 43)
                  totalpower1 = 43;
            }

            powoff2 = rand() %  14;
            if(totalpower2 >= 43 && powoff2 <= 6)
            {
               totalpower2 = totalpower2 - powoff2;
               if(totalpower2 < 43)
                  totalpower2 = 43;
            }


         if(boutdefence1 > boutattack2)
            {
                randomfactor = boutdefence1 - boutattack2;
                boutattack2 = boutattack2 - randomfactor;
                totalpower2 = totalpower2 - randomfactor;
                if(boutattack2 <= 0)
                    boutattack2 = 0;
                if(totalpower2 <= 0)
                    totalpower2 = 0;
            }

            if(boutdefence2 > boutattack1)
            {
                randomfactor = boutdefence2 - boutattack1;
                boutattack1 = boutattack1 - randomfactor;
                totalpower1 = totalpower1 - randomfactor;
                if(boutattack1 <= 0)
                    boutattack1 = 0;
                if(totalpower1 <= 0)
                    totalpower1 = 0;
            }


        if(boxer1conditioning <= 0)
        {
           boxer1conditioning = 0;
        }

        if(boxer2conditioning <= 0)
        {
           boxer2conditioning = 0;
        }


         totalattack1 = (boutattack1 + (boxer1conditioning / 3) + totalpower1 / 2) - boutdefence2;
         totalattack2 = (boutattack2 + (boxer2conditioning / 3) + totalpower2 / 2) - boutdefence1;
         totalstrengh1 = boxer1strengh - boxer2conditioning;
         totalstrengh2 = boxer2strengh - boxer1conditioning;




         if(totalattack1 < 0)
             totalattack1 = 0;

         if(totalpower1 < 0)
             totalpower1 = 0;

        if(totalstrengh1 < 0)
            totalstrengh1 = 0;

        if(boxer1chin <= 0)
        {
            boxer1chin = 0;
            totalattack1 = 0;
        }

        if(boxer1conditioning <= 0)
        {
           boxer1chin = 0;
           totalattack1 = 0;
        }

        if(totalattack2 < 0)
            totalattack2 = 0;

        if(totalpower2 < 0)
             totalpower2 = 0;

        if(totalstrengh2 < 0)
            totalstrengh2 = 0;

        if(boxer2chin <= 0)
        {
            boxer2chin = 0;
            totalattack2 = 0;
        }

        if(boxer2conditioning <= 0)
        {
           boxer2chin = 0;
           totalattack2 = 0;
        }





        if(totalattack1 >= totalattack2) // boxer 1 wins round
        {
            outclassed1 = totalattack1 - totalattack2;

            if (outclassed1 >=26)
            {
                totalattack2 = 0;
               if(boxer2conditioning > 0)
                  boxer2conditioning = boxer2conditioning - 1;
            }


            if(totalstrengh1 > 0)
             {
                 mark2 = totalstrengh1 / 15;
                 if(boxer2conditioning > 0)
                    boxer2conditioning = boxer2conditioning - mark2;
              }

                boxer2chinround = boxer2chin - totalpower1;
                if(boxer2chinround <= 6)
                  {
                  boxer1winbyknockout = 1;
                  fightover = 1;
                  cout << "Round: " << round << "  " << boxr[1].firstname << " " << boxr[1].surname <<" Is pulled out   "  <<endl;
                  }

                 else
                 {
                   cout << "Round: " << round << "  10    -   9" << endl;

                 }

       }// END if boxer 1 wins round

        if(totalattack2 > 0 &&  totalattack2 < totalattack1)  // boxer 2 loses round but scores.
        {
            if(totalstrengh2 > 0)
             {
            mark1 = totalstrengh2 / 15;
            if(boxer1conditioning > 0)
               boxer1conditioning = boxer1conditioning - mark1;
             }


        }// END of boxer 2 loses round but scores.



        if(totalattack2 > totalattack1) //boxer 2 wins round
        {
           outclassed2 = totalattack2 - totalattack1;

            if (outclassed2 >=26)
            {
                totalattack1= 0;
               if(boxer1conditioning > 0)
                  boxer1conditioning = boxer1conditioning - 1;
            }


           if(totalstrengh2 > 0)
             {
                mark1 = totalstrengh2 / 15;
                if(boxer1conditioning > 0)
                   boxer1conditioning = boxer1conditioning - mark1;
             }

               boxer1chinround = boxer1chin - totalpower2;

            if(boxer1chinround <= 6 && boxer1winbyknockout == 0)
                  {
                  fightover = 1;
                  cout << "Round: " << round << "  " << boxr[0].firstname << " " << boxr[0].surname <<" Is pulled out   "  <<endl;
                  }
            else
                {
                 cout << "Round: " << round << "  9    -   10" << endl;

                }


    }//END of boxer 2 wins round



        if(totalattack1 >  0  &&  totalattack1 < totalattack2)  // boxer 1 loses round but scores.
        {
            if(totalstrengh1 > 0)
             {
            mark2 = totalstrengh1 / 15;
            if(boxer2conditioning > 0)
               boxer2conditioning = boxer2conditioning - mark2;
             }

       } // END of boxer 1 loses round but scores.

        if(fightover == 0 && round >= 3)
        {
          cout << endl;
          cout << "Another round: Y/N? " << endl;
          cin  >> dt;
          cout << endl;
          dt = tolower(dt);
          if(dt == 'n')
            fightover = 1;
        }

        if(fightover == 0)
        {
          this_thread::sleep_for(dura);
        }


        //system("PAUSE");
        round++;

         } while(round <= rounds && fightover == 0);



         cout << endl;

         cin.sync();
         cout << endl << "Press a key.................." << endl;
         getch();
         cin.sync();



    return;
}
