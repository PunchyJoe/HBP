
#include "hbpheader.h"



void worldprorankingsz(void)

{


  fstream profile;
  boxer bxr;


  int i = 0;
  int j;
  int p;
  int e;
  int c = 0;
  int u = 1;
  char gamechoice;

  cout << endl << endl << endl;
  cout << "        RATINGS" << endl << endl;
  cout << "        A.WORLD" << endl;
  cout << "        B.WORLD -210" << endl;
  cout << "        C.AMERICAS" << endl;
  cout << "        D:EUROPE" << endl;
  cout << "        E.AFRICA" << endl;
  cout << "        F.AUSTRALASIA" << endl;
  cout << "        G.ASIA" << endl;
  cout << "        H.WORLD AMATEUR" << endl;

  cin  >> gamechoice;

  gamechoice = tolower(gamechoice);



  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        getch();
        exit(1);
  }

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
  }

  profile.close();

  boxer* ratebox = new boxer[i];

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        getch();
        exit(1);
  }

  while(profile.read((char *)(&ratebox[c]),STRUCTSIZEPRO))
  {
     c++;
  }

  for (p = 0; p < i; p++)
  {
          if (ratebox[p].totalfights > 0 && ratebox[p].wins < 1)
          {
             ratebox[p].rating = 0;

          }

          if (ratebox[p].totalfights < 1 && ratebox[p].amwins < 1)
          {
             ratebox[p].rating = 0;

          }

          if (ratebox[p].title == 1)
          {
             ratebox[p].rating = 1000000;

          }

          if (ratebox[p].title == 2 && ratebox[p].weight <= CRUZERLIMIT)
          {
             ratebox[p].rating = 100000;

          }


          if ((ratebox[p].title == 3 || (ratebox[p].title >= 14 && ratebox[p].title <= 20)) && ratebox[p].weight > CRUZERLIMIT)
          {
             ratebox[p].rating = 10000;

          }


 }


  for (p = 0; p < i; p++)
  {
          for (j = 0; j < i-(p); j++)
          {
             if (ratebox[j].rating < ratebox[j+1].rating)
              {
                swap(ratebox[j], ratebox[j+1]);
              }


         }
   }

 u = 1;

 if(gamechoice == 'a')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && ratebox[e].weight > CRUZERLIMIT && u <= 10 && ratebox[e].wc == 0)
    {
       cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
       cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u++;
    }
  }
 }

 if(gamechoice == 'b')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && ratebox[e].weight <= CRUZERLIMIT && u <= 10 && ratebox[e].wc == 0)
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
    cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

  }
 }

 if(gamechoice == 'c')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && u <= 10 && ratebox[e].wc == 0 && ratebox[e].weight > CRUZERLIMIT && ((strcmp (ratebox[e].country,"USA") == 0) || (strcmp (ratebox[e].country,"BRA") == 0)
       || (strcmp (ratebox[e].country,"CAN") == 0) || (strcmp (ratebox[e].country,"MEX") == 0)|| (strcmp (ratebox[e].country,"CUB") == 0)|| (strcmp (ratebox[e].country,"JAM") == 0)))
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
    cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

  }
 }

 if(gamechoice == 'd')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && u <= 10 && ratebox[e].wc == 0 && ratebox[e].weight > CRUZERLIMIT && ((strcmp (ratebox[e].country,"ENG") == 0) || (strcmp (ratebox[e].country,"RUS") == 0)
       || (strcmp (ratebox[e].country,"DEU") == 0) || (strcmp (ratebox[e].country,"IRL") == 0)|| (strcmp (ratebox[e].country,"ITA") == 0)|| (strcmp (ratebox[e].country,"FRA") == 0)
       || (strcmp (ratebox[e].country,"SWE") == 0) || (strcmp (ratebox[e].country,"SCO") == 0)|| (strcmp (ratebox[e].country,"WAL") == 0)|| (strcmp (ratebox[e].country,"DNK") == 0)
       || (strcmp (ratebox[e].country,"POL") == 0) || (strcmp (ratebox[e].country,"TUR") == 0)|| (strcmp (ratebox[e].country,"NIL") == 0)|| (strcmp (ratebox[e].country,"BLR") == 0)
       || (strcmp (ratebox[e].country,"UKR") == 0) || (strcmp (ratebox[e].country,"ROU") == 0)|| (strcmp (ratebox[e].country,"HUN") == 0)|| (strcmp (ratebox[e].country,"BGR") == 0)
       || (strcmp (ratebox[e].country,"MDA") == 0)))
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
    cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

  }
 }



 if(gamechoice == 'e')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && u <= 10 && ratebox[e].wc == 0 && ratebox[e].weight > CRUZERLIMIT && ((strcmp (ratebox[e].country,"NGA") == 0) || (strcmp (ratebox[e].country,"ZAF") == 0)))
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
    cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

  }
 }

  if(gamechoice == 'f')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && u <= 10 && ratebox[e].wc == 0 && ratebox[e].weight > CRUZERLIMIT && ((strcmp (ratebox[e].country,"AUS") == 0) || (strcmp (ratebox[e].country,"NZL") == 0)))
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(11) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
    cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

  }
 }
 if(gamechoice == 'g')
 {
  for (e = 0; e < i; e++)
  {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && u <= 10 && ratebox[e].wc == 0 && ratebox[e].weight > CRUZERLIMIT && ((strcmp (ratebox[e].country,"JPN") == 0) || (strcmp (ratebox[e].country,"CHN") == 0)
       || (strcmp (ratebox[e].country,"IND") == 0)))
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
    cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

  }
 }

 if(gamechoice == 'h')
 {
   for (e = 0; e < i; e++)
   {

    if(ratebox[e].totalfights == 0 && ratebox[e].active == 1 && u <= 10 && ratebox[e].wc == 0 && (ratebox[e].amwins > 0 || ratebox[e].amloses > 0))
    {
    cout << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << setw(6) << ratebox[e].weight
    << setw(11) << ratebox[e].amwins << "-" << ratebox[e].amloses << endl;
    u++;
    }

   }

 }

    profile.close();

    delete [] ratebox;

    ratebox = nullptr;


      cin.sync();
      getch();

      system("cls");

    return;

}
