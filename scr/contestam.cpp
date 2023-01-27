// create boxer contests

#include "hbpheader.h"

void contestam(void)
{

    srand ( static_cast<unsigned int>(time(NULL)) );

    fstream profile;
    fstream amrecords;
    fstream timefile;
    fstream frec;
    fstream amrec;
    fstream world;

    struct boxer bxr;
    struct fighttime ft;
    struct boxer boxr[2];
    struct records amarec[2];

    char boxer1wonlost[10];
    char boxer2wonlost[10];
    char boutvenue[15];
    char bouttitle[30];
    char amorpro[30];
    char notes[30];

    int boxer1, boxer2, rounds;
    int xp1, xp2;
    int i = 0;
    int c = 0;
    int round = 1;
    int boxer1winbyknockout = 0;
    int boxer2winbyknockout = 0;
    int gloveset = 0;
    int fightover = 0;
    int totalscore1 = 0;
    int totalscore2 = 0;
    int boxer1dec = 0;
    int boxer2dec = 0;
    int nag1 = 0;
    int nag2 = 0;

    char unan[] = "UNAN";
    char maj[] = "MAJ";
    char amfight[] = "WORLD AMATEUR BOUT";
    char olymfight[] = "OLYMPIC AMATEUR BOUT";

    char gc, gz;
    char howclose[8];
    char hw[2];
    char condraw;
    char goahead;
    char di1[4], di2[4];
    char roundstobox[3];


    int boutattack1, boutattack2, boutdefence1, boutdefence2;
    int boxerchin1, boxerchin2;
    int boxer1chin, boxer2chin;
    int conboxer1attack, conboxer2attack, conboxer1defence, conboxer2defence;
    int conboxer1power, conboxer2power, conboxer1chin, conboxer2chin;
    int boxer1strengh, boxer2strengh, boxer1conditioning, boxer2conditioning;
    int iwantit1, iwantit2, boxer1hart, boxer2hart;
    int attoff1, attoff2, defoff1, defoff2, powoff1, powoff2;
    int boxer1round, boxer2round;
    int mark1, mark2, outclassed1, outclassed2;
    int boxer1chinround, boxer2chinround;
    int tempelo;
    int heightadv, overdisadv;
    int randomfactor;

    int jscore11 = 0, jscore12 = 0, jscore21 = 0, jscore22 = 0, jscore31 = 0, jscore32 = 0;
    int tscore1, tscore2;
    int jround11, jround12, jround21, jround22, jround31, jround32;

    int randomj;

    int amcon1, amcon2;
    int totalattack1, totalattack2;
    int totalpower1, totalpower2;
    int totalstrengh1, totalstrengh2;

    chrono::seconds dura(4);


        timefile.open("GAMETIME.BIN",ios::in|ios::binary);
        if(timefile.fail())
       {
        cout << "Could not create Time file - Press a key" << endl;
        _getch();
        exit(1);
       }

      timefile.read((char *)(&ft),STRUCTSIZETIME);
      timefile.close();

        frec.open("BOXINGTV.txt",ios::out|ios::app);
        if(frec.fail())
          {
           cout << "Could not write to fight record file - Press a key" << endl;
           _getch();
           exit(1);
          }

      profile.open("PROBOXERS.BIN",ios::binary|ios::in);
      if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          _getch();
          exit(1);
       }

       cout << "#   COUNTRY            NAME   AGE WGT   HT      AM" << endl;
       cout << "----------------------------------------------------------------------" << endl;


      while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
       {
       i++;
           if(bxr.active > 0 && bxr.suspend == 0 &&  bxr.totalfights == 0 && bxr.amorpro == 0 && bxr.wc == 0)
            {
            cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
            << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
            << bxr.heightinches << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
           }
       }



     profile.close();

     --i;

     cout << endl;

    do
     {
     cout << "Enter Number of first boxer in contest 0 to exit:" << endl;
     cin  >> di1;
     boxer1 = atoi(di1);
          if(boxer1 == 0)
          {
           timefile.close();
           frec.close();
           return;
          }

     }while(boxer1 > (i+1) );

     do
     {
     cout << "Enter Number of second boxer in contest:" << endl;
     cin  >> di2;
     boxer2 = atoi(di2);
     }while(boxer2 > (i+1) || boxer1 == boxer2);

     rounds = 3;

     strncpy_s(boutvenue, "CUB" , 15);

     cout << endl << endl;

    --boxer1;
    --boxer2;

      profile.open("PROBOXERS.BIN",ios::binary|ios::in);
      if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          _getch();
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
          _getch();
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


     strncpy_s(amorpro, amfight, 30);
     strncpy_s(bouttitle, "WORLD 3R" , 30);

    cout << "OLYMPIC BOUT: y/n" << endl;
    cin >> condraw;
     condraw = tolower(condraw);

        if(condraw == 'y')
        {
          strncpy_s(amorpro, olymfight, 30);
          strncpy_s(bouttitle, "OLYMPIC 5R" , 30);
          rounds = 5;
          gloveset = 1;
       cout << endl << endl << endl << endl << endl << endl;
       cout << setw(40) << "FIGHT VENUE:" << endl << endl;
       cout << "        A: USA" << endl;
       cout << "        B: Saudi Arabia" << endl;
       cout << "        C. England" << endl;
       cout << "        D. Nigeria" << endl;
       cout << "        E: Russia" << endl;
       cout << "        F: Germany" << endl;
       cout << "        G. OTHER" << endl;


       cin  >> gc;

       gc = tolower(gc);

      switch(gc)
	  {
		  case 'a': strncpy_s(boutvenue, "USA" , 15);
		  break;
		  case 'b': strncpy_s(boutvenue, "SAU" , 15);
		  break;
		  case 'c': strncpy_s(boutvenue, "ENG" , 15);
		  break;
		  case 'd': strncpy_s(boutvenue, "NGA" , 15);
		  break;
		  case 'e': strncpy_s(boutvenue, "RUS" , 15);
          break;
          case 'f': strncpy_s(boutvenue, "DEU" , 15);
		  break;
		  case 'g':
                   cout << "        A. Ireland" << endl;
                   cout << "        B. Australia" << endl;
                   cout << "        C. Italy" << endl;
                   cout << "        D. Japan" << endl;
                   cout << "        E. China" << endl;
                   cout << "        F. France" << endl;
                   cout << "        G. Sweden" << endl;
                   cout << "        H. New Zealand" << endl;
                   cout << "        I. Brazil" << endl;
                   cout << "        J. South Africa" << endl;
                   cout << "        K. Jamaica" << endl;
                   cout << "        L. India" << endl;
                   cout << "        M. Scotland" << endl;
                   cout << "        N. Wales" << endl;
                   cout << "        O. Canada" << endl;
                   cout << "        P. Denmark" << endl;
                   cout << "        Q. Poland" << endl;
                   cout << "        R. Turkey" << endl;
                   cout << "        S. Mexico" << endl;
                   cout << "        T. N.Ireland" << endl;
                   cout << "        U. Belarus" << endl;
                   cout << "        V. Ukraine" << endl;
                   cout << "        W. Romania" << endl;
                   cout << "        X. Hungary" << endl;
                   cout << "        Y. Bulgaria" << endl;
                   cout << "        Z. Moldova" << endl;

                   cin  >> gz;

                   gz = tolower(gz);

		          switch(gz)
                 {
		          case 'a': strncpy_s(boutvenue, "IRL" , 15);
		          break;
		          case 'b': strncpy_s(boutvenue, "AUS" , 15);
                  break;
		          case 'c': strncpy_s(boutvenue, "ITA" , 15);
                  break;
		          case 'd': strncpy_s(boutvenue, "JPN" , 15);
		          break;
		          case 'e': strncpy_s(boutvenue, "CHN" , 15);
                  break;
		          case 'f': strncpy_s(boutvenue, "FRA" , 15);
		          break;
		          case 'g': strncpy_s(boutvenue, "SWE" , 15);
                  break;
                  case 'h': strncpy_s(boutvenue, "NZL" , 15);
		          break;
		          case 'i': strncpy_s(boutvenue, "BRA" , 15);
		          break;
		          case 'j': strncpy_s(boutvenue, "ZAF" , 15);
		          break;
		          case 'k': strncpy_s(boutvenue, "JAM" , 15);
		          break;
		          case 'l': strncpy_s(boutvenue, "IND" , 15);
                  break;
		          case 'm': strncpy_s(boutvenue, "SCO" , 15);
		          break;
		          case 'n': strncpy_s(boutvenue, "WAL" , 15);
                  break;
                  case 'o': strncpy_s(boutvenue, "CAN" , 15);
		          break;
		          case 'p': strncpy_s(boutvenue, "DNK" , 15);
		          break;
		          case 'q': strncpy_s(boutvenue, "POL" , 15);
                  break;
		          case 'r': strncpy_s(boutvenue, "TUR" , 15);
		          break;
		          case 's': strncpy_s(boutvenue, "MEX" , 15);
                  break;
                  case 't': strncpy_s(boutvenue, "NIL" , 15);
                  break;
                  case 'u': strncpy_s(boutvenue, "BLR" , 15);
                  break;
                  case 'v': strncpy_s(boutvenue, "UKR" , 15);
                  break;
                  case 'w': strncpy_s(boutvenue, "ROU" , 15);
                  break;
                  case 'x': strncpy_s(boutvenue, "HUN" , 15);
                  break;
                  case 'y': strncpy_s(boutvenue, "BGR" , 15);
                  break;
                  case 'z': strncpy_s(boutvenue, "MDA" , 15);
                  break;
		  }
	  }
  }
      cout << endl << endl;


      if(boxr[0].attack < 6 || boxr[0].defence < 6)
      {
           boxr[0].active = 0;
           cout << "      " << boxr[0].surname << " FAILED MEDICAL SORRY TIME TO RETIRE!" << endl;

           profile.open("PROBOXERS.BIN",ios::binary|ios::out|ios::in);
           if(profile.fail())
           {
              cout << "Could not open Pro Boxers file - Press a key" << endl;
              _getch();
              exit(1);
           }

            c = 0;

           do{

               if(c == boxer1)
               {
                  profile.write((char *)(&boxr[0]),STRUCTSIZEPRO);
               }
              else
              {
                  profile.read((char *)(&bxr),STRUCTSIZEPRO);
              }
            c++;

              }while(c <= i);
           _getch();
           frec.close();
           profile.close();
           return;
      }

      if(boxr[1].attack < 6 || boxr[1].defence < 6)
      {
           boxr[1].active = 0;
           cout << "      " << boxr[1].surname << " FAILED MEDICAL SORRY TIME TO RETIRE!" << endl;

           profile.open("PROBOXERS.BIN",ios::binary|ios::out|ios::in);
           if(profile.fail())
           {
              cout << "Could not open Pro Boxers file - Press a key" << endl;
              _getch();
              exit(1);
           }

            c = 0;

           do{

               if(c == boxer2)
               {
                  profile.write((char *)(&boxr[1]),STRUCTSIZEPRO);
               }
              else
              {
                  profile.read((char *)(&bxr),STRUCTSIZEPRO);
              }
            c++;

              }while(c <= i);
           _getch();
           frec.close();
           profile.close();
           return;
       }



     if(boxr[0].suspend > 0 ||  boxr[1].suspend > 0)
     {
           cout << "           Bout Cannot take place. One or both Boxers suspended" << endl;
           _getch();
          frec.close();
          return;
     }

     if(boxr[0].active == 0 ||  boxr[1].active == 0)
     {
           cout << "           Bout Cannot take place. One or both Boxers deactivated" << endl;
           _getch();
          frec.close();
          return;
     }

      cin.sync();



        if(boxr[0].totalfights > 0 || boxr[1].totalfights > 0)
           {
            cout << "           Bout Cannot take place. One or both Boxers is a Pro" << endl;
            _getch();
            frec.close();
            return;
           }


        if(boxr[0].weight <= CRUZERLIMIT && boxr[1].weight <= CRUZERLIMIT)
           cout << "This is a Cruiserweight bout - both boxers " << CRUZERLIMIT << " or under" << endl << endl;
        else
           cout << "This is a Heavyweight bout - one or both boxers over:" << CRUZERLIMIT << endl << endl;

        if(boxr[0].age < AGELIMIT && boxr[1].age < AGELIMIT)
           cout << "This is a Amateur Junior bout - both boxers are under:" << AGELIMIT << endl << endl;
        else
           cout << "This is a Amateur Senior bout - one or both boxers over:" << AGELIMIT << endl << endl;

        cin.sync();

        cout << "Makes note on this contest, just press enter for no note" << endl;
        cin.getline(notes,30);


         cin.sync();
         _getch();
         cin.sync();

         cout << endl << endl;

        cout << endl << endl;

     profile.close();

     cout << "                      THIS IS A " << amorpro << endl;
     cout << "================================================================================" << endl;
     cout << "                             " << bouttitle << endl;
     cout << "                                " << boutvenue << endl;
     cout << "                                " << rounds << ":Rounds" << endl;
     cout << "                                " << ft.week << "/" << ft.month << "/" << ft.year << endl;
     cout << "               " << boxr[0].firstname << " " << boxr[0].surname << "(" << boxr[0].country << ")                 ";
     cout <<                      boxr[1].firstname << " " << boxr[1].surname << "(" << boxr[1].country << ")" << endl;
     cout << "                  " << boxr[0].age << "                               " << boxr[1].age << endl;
     cout << "                  " << boxr[0].weight << "                              " << boxr[1].weight << endl;
     cout << "                  " << boxr[0].heightfeet << "-" << boxr[0].heightinches << "                              " << boxr[1].heightfeet << "-" << boxr[1].heightinches << endl;
     cout << "                  Create this contest y/n"<< endl;
     goahead = _getch();

    goahead = tolower(goahead);

     if(goahead == 'n')
         return;

     frec << "================================================================================" << endl;
     frec << "                      THIS IS A " << amorpro << endl;
     frec << "================================================================================" << endl;
     frec << "                             " << bouttitle << endl;
     frec << "                                " << boutvenue << endl;
     frec << "                                " << rounds << ":Rounds" << endl;
     frec << "                                " << ft.week << "/" << ft.month << "/" << ft.year << endl;
     frec << "               " << boxr[0].firstname << " " << boxr[0].surname << "(" << boxr[0].country << ")                 ";
     frec <<                      boxr[1].firstname << " " << boxr[1].surname << "(" << boxr[1].country << ")" << endl;
     frec << "                  " << boxr[0].age << "                               " << boxr[1].age << endl;
     frec << "                  " << boxr[0].weight << "                              " << boxr[1].weight << endl;
     frec << "                  " << boxr[0].heightfeet << "-" << boxr[0].heightinches << "                              " << boxr[1].heightfeet << "-" << boxr[1].heightinches << endl;



     cout << endl << endl << endl;
     cout << "SECONDS OUT (Press a key).................." << endl << endl << endl;

     cin.sync();

     _getch();

     cin.sync();

    cout << endl;
    cout << " " << rounds << " Rounds"  << " "  << amorpro << endl;
    cout << boxr[0].firstname << " " << boxr[0].surname <<"  Vs  " << boxr[1].firstname << " " << boxr[1].surname << endl;

    frec << endl << endl;
    frec << " " << rounds << " Rounds"  << " "  << amorpro << endl;
    frec << boxr[0].firstname << " " << boxr[0].surname <<"  Vs  " << boxr[1].firstname << " " << boxr[1].surname << endl;

    this_thread::sleep_for(dura);

        boxr[0].suspend = 1;
        boxr[1].suspend = 1;
        boxr[0].wc = 0;
        boxr[1].wc = 0;

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
        boxer1hart = boxr[0].drive;
        boxer2hart = boxr[1].drive;
        boxer1hart = boxer1hart + 3;
        boxer2hart = boxer2hart + 3;


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



        if(strcmp(boutvenue, boxr[0].country) != 0)
          {
           conboxer1attack = conboxer1attack - 2;
           conboxer1defence = conboxer1defence - 2;
          }

         if(strcmp(boutvenue, boxr[1].country) != 0)
          {
           conboxer2attack = conboxer2attack - 2;
           conboxer2defence = conboxer2defence - 2;
          }


       amcon1 = boxr[0].amwins + boxr[0].amloses;
       amcon2 = boxr[1].amwins + boxr[1].amloses;

             if(amcon1 > amcon2 && amcon2 <= 6)
               {
                    xp1 = amcon1 - amcon2;
                    conboxer1attack = conboxer1attack + xp1;
                    conboxer1defence = conboxer1defence + xp1;
               }
             if(amcon2 > amcon1 && amcon1 <=6)
              {
                    xp2 = amcon2 - amcon1;
                    conboxer2attack = conboxer2attack + xp2;
                    conboxer2defence = conboxer2defence + xp2;
              }


    do{

         if (gloveset > 0)
         {
             boxerchin1 = rand() % 17;
             boxerchin2 = rand() % 17;
         }

         if (gloveset == 0)
         {
             boxerchin1 = rand() % 21;
             boxerchin2 = rand() % 21;
         }

         boxer1chin = conboxer1chin + boxerchin1;
         boxer2chin = conboxer2chin + boxerchin2;

         if(boxer1chin < 35)
            boxer1chin = 35;
         if(boxer2chin < 35)
            boxer2chin = 35;


         if (gloveset > 0)
         {

            attoff1 = rand() %  20;
            boutattack1 = conboxer1attack + attoff1;
            defoff1 = rand() %  20;
            boutdefence1 = conboxer1defence + defoff1;
            powoff1 = rand() %  11;
            totalpower1 = conboxer1power - powoff1;

            attoff2 = rand() %  20;
            boutattack2 = conboxer2attack + attoff2;
            defoff2 = rand() %  20;
            boutdefence2 = conboxer2defence + defoff2;
            powoff2 = rand() %  11;
            totalpower2 = conboxer2power - powoff2;
         }

         if (gloveset == 0)
         {

            attoff1 = rand() %  16;
            boutattack1 = conboxer1attack + attoff1;
            defoff1 = rand() %  16;
            boutdefence1 = conboxer1defence + defoff1;
            powoff1 = rand() %  11;
            totalpower1 = conboxer1power - powoff1;

            attoff2 = rand() %  16;
            boutattack2 = conboxer2attack + attoff2;
            defoff2 = rand() %  16;
            boutdefence2 = conboxer2defence + defoff2;
            powoff2 = rand() %  11;
            totalpower2 = conboxer2power - powoff2;
         }


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
              iwantit1 = rand() % boxer1hart;
              iwantit2 = rand() % boxer2hart;
              if(iwantit1 < iwantit2)
                boxer1conditioning = boxer1conditioning + 2;
            }
          if(boxer2conditioning <= 0)
            {
              boxer2conditioning = 0;
              iwantit2 = rand() % boxer2hart;
              iwantit1 = rand() % boxer1hart;
              if(iwantit2 < iwantit1)
                boxer2conditioning = boxer2conditioning + 2;
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
         iwantit1 = rand() % boxer1hart;
         iwantit2 = rand() % boxer2hart;
         totalstrengh1 = boxer1strengh - ((boxer2conditioning / 2) + iwantit1);
         totalstrengh2 = boxer2strengh - ((boxer1conditioning / 2) + iwantit2);





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
           nag1 = 1;
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
           nag2 = 1;
        }


        if(totalattack1 == totalattack2)
        {
            do
            {
               iwantit1 = rand() % boxer1hart;
               iwantit2 = rand() % boxer2hart;
            }
             while(iwantit1 == iwantit2);

             if(iwantit1 < iwantit2)
                totalattack1 = totalattack1 + 1;
             else
                totalattack2 = totalattack2 + 1;
        }


        if(totalattack1 > totalattack2) // boxer 1 wins round
        {
            outclassed1 = totalattack1 - totalattack2;

            if (outclassed1 >=26)
            {
                totalattack2 = 0;
                if(boxer2conditioning > 0)
                   boxer2conditioning = boxer2conditioning - 6;
            }


            if(totalstrengh1 > 0)
             {
                mark2 = totalstrengh1 / 2;
                if(boxer2conditioning > 0)
                   boxer2conditioning = boxer2conditioning - mark2;
              }

                boxer2chinround = boxer2chin - totalpower1;

                if(boxer2chinround <= 0)
                  {
                  boxer1winbyknockout = 1;
                  fightover = 1;
                  cout << "Round: " << round << "  " << boxr[0].firstname << " " << boxr[0].surname <<" wins by  KO   "  <<endl;
                  frec << "Round: " << round << "  " << boxr[0].firstname << " " << boxr[0].surname <<" wins by  KO   "  <<endl;
                  }
                   else
                      {
                        cout << "Round: " << round << "  10    -   9" << endl;
                        frec << "Round: " << round << "  10    -   9" << endl;
                        boxer1round = 10;
                        boxer2round = 9;
                        totalscore1 = totalscore1 + boxer1round;
                        totalscore2 = totalscore2 + boxer2round;
                        jround11 = 10;
                        jround12 = 9;
                        jscore11 = jscore11 + jround11;
                        jscore12 = jscore12 + jround12;

                        randomj  = rand() % 100;
                        if(randomj < 85)
                        {
                           jround21 = 10;
                           jround22 = 9;
                           jscore21 = jscore21 + jround21;
                           jscore22 = jscore22 + jround22;
                        }
                        else
                        {
                           jround21 = 9;
                           jround22 = 10;
                           jscore21 = jscore21 + jround21;
                           jscore22 = jscore22 + jround22;
                        }

                        randomj  = rand() % 100;
                        if(randomj < 75)
                        {
                           jround31 = 10;
                           jround32 = 9;
                           jscore31 = jscore31 + jround31;
                           jscore32 = jscore32 + jround32;
                        }
                        else
                        {
                           jround31 = 9;
                           jround32 = 10;
                           jscore31 = jscore31 + jround31;
                           jscore32 = jscore32 + jround32;
                        }
                      }

     }// END if boxer 1 wins round

        if(totalattack2 > 0 &&  totalattack2 < totalattack1)  // boxer 2 loses round but scores.
        {
            if(totalstrengh2 > 0)
             {
            mark1 = totalstrengh2 / 2;
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
                   boxer1conditioning = boxer1conditioning - 6;
            }



            if(totalstrengh2 > 0)
             {
            mark1 = totalstrengh2 / 2;
            if(boxer1conditioning > 0)
               boxer1conditioning = boxer1conditioning - mark1;
             }

                boxer1chinround = boxer1chin - totalpower2;

                if(boxer1chinround <= 0 && boxer1winbyknockout == 0)
                  {
                  boxer2winbyknockout = 1;
                  fightover = 1;
                  cout << "Round: " << round << "  " << boxr[1].firstname << " " << boxr[1].surname <<" wins by  KO   "  <<endl;
                  frec << "Round: " << round << "  " << boxr[1].firstname << " " << boxr[1].surname <<" wins by  KO   "  <<endl;
                  }

                  else
                      {
                        cout << "Round: " << round << "  9    -   10" << endl;
                        frec << "Round: " << round << "  9    -   10" << endl;
                        boxer1round = 9;
                        boxer2round = 10;
                        totalscore1 = totalscore1 + boxer1round;
                        totalscore2 = totalscore2 + boxer2round;
                        jround11 = 9;
                        jround12 = 10;
                        jscore11 = jscore11 + jround11;
                        jscore12 = jscore12 + jround12;

                        randomj  = rand() % 100;
                        if(randomj < 85)
                        {
                           jround21 = 9;
                           jround22 = 10;
                           jscore21 = jscore21 + jround21;
                           jscore22 = jscore22 + jround22;
                        }
                        else
                        {
                           jround21 = 10;
                           jround22 = 9;
                           jscore21 = jscore21 + jround21;
                           jscore22 = jscore22 + jround22;
                        }

                        randomj  = rand() % 100;
                        if(randomj < 75)
                        {
                           jround31 = 9;
                           jround32 = 10;
                           jscore31 = jscore31 + jround31;
                           jscore32 = jscore32 + jround32;
                        }
                        else
                        {
                           jround31 = 10;
                           jround32 = 9;
                           jscore31 = jscore31 + jround31;
                           jscore32 = jscore32 + jround32;
                        }
                      }


          }//END of boxer 2 wins round



        if(totalattack1 >  0  &&  totalattack1 < totalattack2)  // boxer 1 loses round but scores.
        {
            if(totalstrengh1 > 0)
             {
            mark2 = totalstrengh1 / 2;
            if(boxer2conditioning > 0)
               boxer2conditioning = boxer2conditioning - mark2;
             }

       } // END of boxer 1 loses round but scores.

        this_thread::sleep_for(dura);
        //system("PAUSE");
        round++;

         } while(round <= rounds && fightover == 0);

            --round;
            cout << endl;


         randomj  = rand() % 100;

         if(randomj <= 50)
         {
            tscore1 = jscore11;
            tscore2 = jscore12;
            jscore11 = jscore21;
            jscore12 = jscore22;
            jscore21 = tscore1;
            jscore22 = tscore2;
         }

         randomj  = rand() % 100;

         if(randomj <= 50)
         {
            tscore1 = jscore11;
            tscore2 = jscore12;
            jscore11 = jscore31;
            jscore12 = jscore32;
            jscore31 = tscore1;
            jscore32 = tscore2;
         }



         if(boxer1winbyknockout == 0 && boxer2winbyknockout == 0)
         {

            if(jscore11 > jscore12 && jscore21 > jscore22 && jscore31 > jscore32)
            {
                boxer1dec = 1;
                strncpy_s(howclose, unan , 8);
                hw[0] = 'U';
                hw[1] = '\0';
            }
            else if(jscore11 > jscore12 && jscore21 > jscore22 && jscore31 < jscore32)
            {
                boxer1dec = 1;
                strncpy_s(howclose, maj , 8);
                hw[0] = 'M';
                hw[1] = '\0';
                tscore1 = jscore21;
                tscore2 = jscore22;
                jscore21 = jscore31;
                jscore22 = jscore32;
                jscore31 = tscore1;
                jscore32 = tscore2;
            }
            else if(jscore11 > jscore12 && jscore21 < jscore22 && jscore31 > jscore32)
            {
                boxer1dec = 1;
                strncpy_s(howclose, maj , 8);
                hw[0] = 'M';
                hw[1] = '\0';
            }
            else if(jscore11 < jscore12 && jscore21 > jscore22 && jscore31 > jscore32)
            {
                boxer1dec = 1;
                strncpy_s(howclose, maj , 8);
                hw[0] = 'M';
                hw[1] = '\0';
            }
            else if(jscore11 < jscore12 && jscore21 < jscore22 && jscore31 < jscore32)
            {
                boxer2dec = 1;
                strncpy_s(howclose, unan , 8);
                hw[0] = 'U';
                hw[1] = '\0';
            }
            else if(jscore11 < jscore12 && jscore21 < jscore22 && jscore31 > jscore32)
            {
                boxer2dec = 1;
                strncpy_s(howclose, maj , 8);
                hw[0] = 'M';
                hw[1] = '\0';
                tscore1 = jscore21;
                tscore2 = jscore22;
                jscore21 = jscore31;
                jscore22 = jscore32;
                jscore31 = tscore1;
                jscore32 = tscore2;
            }
            else if(jscore11 < jscore12 && jscore21 > jscore22 && jscore31 < jscore32)
            {
                boxer2dec = 1;
                strncpy_s(howclose, maj , 8);
                hw[0] = 'M';
                hw[1] = '\0';
            }
            else if(jscore11 > jscore12 && jscore21 < jscore22 && jscore31 < jscore32)
            {
                boxer2dec = 1;
                strncpy_s(howclose, maj , 8);
                hw[0] = 'M';
                hw[1] = '\0';
            }
         }

        if(gloveset == 0)
        {
        amrec.open("ALLAMBOUTS.txt",ios::out|ios::app);
        if(amrec.fail())
          {
           cout << "Could not write to fight record file - Press a key" << endl;
           _getch();
           exit(1);
         }
        }
       if(gloveset > 0)
        {
        amrec.open("ALLOLYMBOUTS.txt",ios::out|ios::app);
        if(amrec.fail())
          {
           cout << "Could not write to fight record file - Press a key" << endl;
           _getch();
           exit(1);
         }
        }


            if(boxer1winbyknockout == 1)
             {



               boxr[0].amwins = boxr[0].amwins + 1;
               boxr[1].amloses = boxr[1].amloses + 1;
               boxr[1].suspend = 8;
               amrec << ft.week << "/" << ft.month << "/" << ft.year << "  ";
               amrec << boxr[0].firstname  << " " << boxr[0].surname << "  " << boxr[0].age << "  " << boxr[0].country << "  " << boxr[0].weight << "  W KO "  << round  << "  ";
               amrec << boxr[1].firstname  << " " << boxr[1].surname << "  " << boxr[1].age << "  " << boxr[1].country << "  " << boxr[1].weight << "  " << boutvenue  << "  -" << notes << endl;

             strncpy_s(boxer1wonlost, "W KO " , 10);
             strncpy_s(boxer2wonlost, "L KO " , 10);
             sprintf_s(roundstobox, "%d", round);
             strcat_s(boxer1wonlost, roundstobox);
             strcat_s(boxer2wonlost, roundstobox);

             }





            if(boxer2winbyknockout == 1)
             {


               boxr[1].amwins = boxr[1].amwins + 1;
               boxr[0].amloses = boxr[0].amloses + 1;
               boxr[0].suspend = 8;
               amrec << ft.week << "/" << ft.month << "/" << ft.year << "  ";
               amrec << boxr[1].firstname  << " " << boxr[1].surname << "  " << boxr[1].age << "  " << boxr[1].country << "  " << boxr[1].weight << "  W KO "   << round  << "  ";
               amrec << boxr[0].firstname  << " " << boxr[0].surname << "  " << boxr[0].age << "  " << boxr[0].country << "  " << boxr[0].weight << "  " << boutvenue  << "  -" << notes <<   endl;

             strncpy_s(boxer1wonlost, "L KO " , 10);
             strncpy_s(boxer2wonlost, "W KO " , 10);
             sprintf_s(roundstobox, "%d", round);
             strcat_s(boxer1wonlost, roundstobox);
             strcat_s(boxer2wonlost, roundstobox);

             }



             if(boxer1dec && boxer1winbyknockout == 0 && boxer2winbyknockout == 0)
             {


             cout << "Ringside experts scored the fight: " << totalscore1 << ":" << totalscore2 << endl << endl;
             frec << "Ringside experts scored the fight: " << totalscore1 << ":" << totalscore2 << endl << endl;
             this_thread::sleep_for(dura);
             cout << "NOW THE JUDGE'S DECISION!" << endl << endl;
             frec << "NOW THE JUDGE'S DECISION!" << endl << endl;
             this_thread::sleep_for(dura);
             cout << "Judge 1 scores the bout:            " << jscore11 << ":" << jscore12 << endl;
             frec << "Judge 1 scores the bout:            " << jscore11 << ":" << jscore12 << endl;
             this_thread::sleep_for(dura);
             cout << "Judge 2 scores the bout:            " << jscore21 << ":" << jscore22 << endl;
             frec << "Judge 2 scores the bout:            " << jscore21 << ":" << jscore22 << endl;
             this_thread::sleep_for(dura);
             cout << "Judge 3 scores the bout:            " << jscore31 << ":" << jscore32 << endl;
             frec << "Judge 3 scores the bout:            " << jscore31 << ":" << jscore32 << endl;
             this_thread::sleep_for(dura);
             cout << "WINNER " << boxr[0].firstname << " " << boxr[0].surname <<" PTS  " << rounds  << " " << howclose  << endl;
             frec << "WINNER " << boxr[0].firstname << " " << boxr[0].surname <<" PTS  " << rounds  << " " << howclose  << endl;


               boxr[0].amwins = boxr[0].amwins + 1;
               boxr[1].amloses = boxr[1].amloses + 1;
               boxr[1].suspend = 4;
               amrec << ft.week << "/" << ft.month << "/" << ft.year << "  ";
               amrec << boxr[0].firstname  << " " << boxr[0].surname << "  " << boxr[0].age << "  " << boxr[0].country << "  " << boxr[0].weight << "  W PTS " << rounds << "  ";
               amrec << boxr[1].firstname  << " " << boxr[1].surname << "  " << boxr[1].age << "  " << boxr[1].country << "  " << boxr[1].weight << "  " << boutvenue << "  -" << notes <<  endl;

             strncpy_s(boxer1wonlost, "W PTS " , 10);
             strncpy_s(boxer2wonlost, "L PTS " , 10);
             sprintf_s(roundstobox, "%d", rounds);
             strcat_s(boxer1wonlost, roundstobox);
             strcat_s(boxer2wonlost, roundstobox);
             strcat_s(boxer1wonlost, hw);
             strcat_s(boxer2wonlost, hw);
            }

             if(boxer2dec && boxer1winbyknockout == 0 && boxer2winbyknockout == 0)
             {


             cout << "Ringside experts scored the fight: " << totalscore1 << ":" << totalscore2 << endl << endl;
             frec << "Ringside experts scored the fight: " << totalscore1 << ":" << totalscore2 << endl << endl;
             this_thread::sleep_for(dura);
             cout << "NOW THE JUDGE'S DECISION!" << endl << endl;
             frec << "NOW THE JUDGE'S DECISION!" << endl << endl;
             this_thread::sleep_for(dura);
             cout << "Judge 1 scores the bout:            " << jscore11 << ":" << jscore12 << endl;
             frec << "Judge 1 scores the bout:            " << jscore11 << ":" << jscore12 << endl;
             this_thread::sleep_for(dura);
             cout << "Judge 2 scores the bout:            " << jscore21 << ":" << jscore22 << endl;
             frec << "Judge 2 scores the bout:            " << jscore21 << ":" << jscore22 << endl;
             this_thread::sleep_for(dura);
             cout << "Judge 3 scores the bout:            " << jscore31 << ":" << jscore32 << endl;
             frec << "Judge 3 scores the bout:            " << jscore31 << ":" << jscore32 << endl;
             this_thread::sleep_for(dura);
             cout << "WINNER " << boxr[1].firstname << " " << boxr[1].surname <<" PTS  " << rounds << " " << howclose  << endl;
             frec << "WINNER " << boxr[1].firstname << " " << boxr[1].surname <<" PTS  " << rounds << " " << howclose  << endl;


               boxr[1].amwins = boxr[1].amwins + 1;
               boxr[0].amloses = boxr[0].amloses + 1;
               boxr[0].suspend = 4;
               amrec << ft.week << "/" << ft.month << "/" << ft.year << "  ";
               amrec << boxr[1].firstname  << " " << boxr[1].surname << "  " << boxr[1].age << "  " << boxr[1].country << "  " << boxr[1].weight << "  W PTS " << rounds << "  ";
               amrec << boxr[0].firstname  << " " << boxr[0].surname << "  " << boxr[0].age << "  " << boxr[0].country << "  " << boxr[0].weight << "  " << boutvenue << "  -" << notes <<   endl;

             strncpy_s(boxer1wonlost, "L PTS " , 10);
             strncpy_s(boxer2wonlost, "W PTS " , 10);
             sprintf_s(roundstobox, "%d" ,rounds);
             strcat_s(boxer1wonlost, roundstobox);
             strcat_s(boxer2wonlost, roundstobox);
             strcat_s(boxer1wonlost, hw);
             strcat_s(boxer2wonlost, hw);
        }


      if((boxer1winbyknockout == 1 || boxer1dec == 1) && boxr[0].rating < boxr[1].rating)
       {
           tempelo = boxr[0].rating;
           boxr[0].rating = boxr[1].rating;
           boxr[1].rating = tempelo;
       }

       if((boxer2winbyknockout == 1 || boxer2dec == 1) && boxr[1].rating < boxr[0].rating)
       {
           tempelo = boxr[1].rating;
           boxr[1].rating = boxr[0].rating;
           boxr[0].rating = tempelo;
       }

       if(boxer1winbyknockout == 1 || boxer1dec == 1)
       {
         boxr[0].rating = boxr[0].rating + 2;
       }
       if(boxer2winbyknockout == 1 || boxer2dec == 1 )
       {
         boxr[1].rating = boxr[1].rating + 2;
       }

       if((boxer1winbyknockout == 1 || boxer1dec == 1) && boxr[1].rating > 2)
       {
         boxr[1].rating = boxr[1].rating - 2;
       }
       if((boxer2winbyknockout == 1 || boxer2dec == 1) && boxr[0].rating > 2)
       {
         boxr[0].rating = boxr[0].rating - 2;
       }

       if(boxer1winbyknockout == 1 && boxr[1].attack > 24 && nag2 == 0)
       {
         boxr[1].attack = boxr[1].attack - 2;
         boxr[1].defence = boxr[1].defence + 2;
       }
       if(boxer2winbyknockout == 1 && boxr[0].attack > 24 && nag1 == 0)
       {
         boxr[0].attack = boxr[0].attack - 2;
         boxr[0].defence = boxr[0].defence + 2;
       }

       if(boxer1winbyknockout == 1 && boxr[1].strengh > 24 && nag2 > 0)
       {
         boxr[1].strengh = boxr[1].strengh - 2;
         boxr[1].conditioning = boxr[1].conditioning + 2;
       }
       if(boxer2winbyknockout == 1 && boxr[0].strengh > 24 && nag1 > 0)
       {
         boxr[0].strengh = boxr[0].strengh - 2;
         boxr[0].conditioning = boxr[0].conditioning + 2;
       }

        boxr[0].inactive = 0;
        boxr[1].inactive = 0;


        profile.open("PROBOXERS.BIN",ios::binary|ios::out|ios::in);
        if(profile.fail())
        {
          cout << "Could not open Pro Boxers file - Press a key" << endl;
          _getch();
          exit(1);
         }

        c = 0;

        do{

          if(c == boxer1)
          {
            profile.write((char *)(&boxr[0]),STRUCTSIZEPRO);
          }

         else if(c == boxer2)
          {
            profile.write((char *)(&boxr[1]),STRUCTSIZEPRO);
          }

         else
         {
         profile.read((char *)(&bxr),STRUCTSIZEPRO);
         }

        c++;

        }while(c <= i);


        profile.close();


        amarec[0].recnum = boxer1;
        amarec[0].week = ft.week;
        amarec[0].month = ft.month;
        amarec[0].year = ft.year;
        amarec[0].weight = boxr[0].weight;
        strncpy_s(amarec[0].opfirstname, boxr[1].firstname,20);
        strncpy_s(amarec[0].opsurname, boxr[1].surname,30);
        strncpy_s(amarec[0].outcome, boxer1wonlost,10);
        strncpy_s(amarec[0].venue, boutvenue,15);
        strncpy_s(amarec[0].title, bouttitle,30);


        amarec[1].recnum = boxer2;
        amarec[1].week = ft.week;
        amarec[1].month = ft.month;
        amarec[1].year = ft.year;
        amarec[1].weight = boxr[1].weight;
        strncpy_s(amarec[1].opfirstname, boxr[0].firstname,20);
        strncpy_s(amarec[1].opsurname, boxr[0].surname,30);
        strncpy_s(amarec[1].outcome, boxer2wonlost,10);
        strncpy_s(amarec[1].venue, boutvenue,15);
        strncpy_s(amarec[1].title, bouttitle,30);

        amrecords.open("AMRECORDS.BIN",ios::binary|ios::out|ios::app);
        if(amrecords.fail())
        {
          cout << "Could not open Pro records file - Press a key" << endl;
          _getch();
          exit(1);
        }

        c = 0;


        do{
        amrecords.write((char *)(&amarec[c]),STRUCTSIZEREC);
        c++;
        }while(c <= 1);



         cin.sync();
         cout << endl << "Press a key.................." << endl;
         _getch();
         cin.sync();

        frec << "================================================================================" << endl;
        frec << endl << endl << endl << endl << endl;

        amrecords.close();
        timefile.close();
        amrec.close();
        world.close();
        frec.close();



    return;
}
