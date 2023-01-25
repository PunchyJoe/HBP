// lookup pro records

#include "hbpheader.h"

void wcb(void)
{

  fstream profile;
  fstream boxrecords;

  struct boxer bxr;
  int i, gc;
  int gamechoice, countrychoice;
  char bxrcountry[15];

  cout << endl;

  i = 0;


  cout <<endl << endl;


  cout << "                             BOXER INDEX:" << endl << endl;
  cout << "                          1.SHOW ACTIVE PROFESSIONALS" << endl;
  cout << "                          2.SHOW ACTIVE AMATEURS" << endl;
  cout << "                          3.SHOW ACTIVE IN TRAINING OR UNLICENSED" << endl;
  cout << "                          4.SHOW ALL" << endl;
  cout << "                          5.GO BACK NOW" << endl << endl;
  cin  >> gamechoice;

  if(gamechoice <= 0 || gamechoice >= 5)
  {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return;
  }



  cout << endl << endl;
  cout << "                          1.SHOW WORLD" << endl;
  cout << "                          2.SHOW ONLY INDIVIDUAL COUNTRY" << endl;
  cout << "                          3.GO BACK NOW" << endl << endl;
  cin  >> countrychoice;

  if(countrychoice <= 0 || countrychoice >= 3)
  {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return;
  }




  if(countrychoice == 2)
  {
       cout << "        1. USA" << endl;
       cout << "        2. England" << endl;
       cout << "        3. Nigeria" << endl;
       cout << "        4. Russia" << endl;
       cout << "        5. Germany" << endl;
       cout << "        6. Ireland" << endl;
       cout << "        7. Australia" << endl;
       cout << "        8. Italy" << endl;
       cout << "        9. Japan" << endl;
       cout << "       10. China" << endl;
       cout << "       11. France" << endl;
       cout << "       12. Sweden" << endl;
       cout << "       13. New Zealand" << endl;
       cout << "       14. Brazil" << endl;
       cout << "       15. South Africa" << endl;
       cout << "       16. Jamaica" << endl;
       cout << "       17. India" << endl;
       cout << "       18. Scotland" << endl;
       cout << "       19. Wales" << endl;
       cout << "       20. Canada" << endl;
       cout << "       21. Denmark" << endl;
       cout << "       22. Poland" << endl;
       cout << "       23. Turkey" << endl;
       cout << "       24. Mexico" << endl;
       cout << "       25. N.Ireland" << endl;
       cout << "       26. Belarus" << endl;
       cout << "       27. Ukraine" << endl;
       cout << "       28. Romania" << endl;
       cout << "       29. Hungary" << endl;
       cout << "       30. Bulgaria" << endl;
       cout << "       31. Moldova" << endl;
       cout << "       32. Cuba" << endl;
       cin  >> gc;

         if(gc == 1)
            strncpy(bxrcountry, "USA" , 15);
         else if(gc == 2)
            strncpy(bxrcountry, "ENG" , 15);
         else if(gc == 3)
            strncpy(bxrcountry, "NGA" , 15);
         else if(gc == 4)
            strncpy(bxrcountry, "RUS" , 15);
         else if(gc == 5)
            strncpy(bxrcountry, "DEU" , 15);
         else if(gc == 6)
            strncpy(bxrcountry, "IRL" , 15);
         else if(gc == 7)
            strncpy(bxrcountry, "AUS" , 15);
         else if(gc == 8)
            strncpy(bxrcountry, "ITA" , 15);
         else if(gc == 9)
            strncpy(bxrcountry, "JPN" , 15);
         else if(gc == 10)
            strncpy(bxrcountry, "CHN" , 15);
         else if(gc == 11)
            strncpy(bxrcountry, "FRA" , 15);
         else if(gc == 12)
            strncpy(bxrcountry, "SWE" , 15);
         else if(gc == 13)
            strncpy(bxrcountry, "NZL" , 15);
         else if(gc == 14)
            strncpy(bxrcountry, "BRA" , 15);
         else if(gc == 15)
            strncpy(bxrcountry, "ZAF" , 15);
         else if(gc == 16)
            strncpy(bxrcountry, "JAM" , 15);
         else if(gc == 17)
            strncpy(bxrcountry, "IND" , 15);
         else if(gc == 18)
            strncpy(bxrcountry, "SCO" , 15);
         else if(gc == 19)
            strncpy(bxrcountry, "WAL" , 15);
         else if(gc == 20)
            strncpy(bxrcountry, "CAN" , 15);
         else if(gc == 21)
            strncpy(bxrcountry, "DNK" , 15);
         else if(gc == 22)
            strncpy(bxrcountry, "POL" , 15);
         else if(gc == 23)
            strncpy(bxrcountry, "TUR" , 15);
         else if(gc == 24)
            strncpy(bxrcountry, "MEX" , 15);
         else if(gc == 25)
            strncpy(bxrcountry, "NIL" , 15);
         else if(gc == 26)
            strncpy(bxrcountry, "BLR" , 15);
         else if(gc == 27)
            strncpy(bxrcountry, "UKR" , 15);
         else if(gc == 28)
            strncpy(bxrcountry, "ROU" , 15);
         else if(gc == 29)
            strncpy(bxrcountry, "HUN" , 15);
         else if(gc == 30)
            strncpy(bxrcountry, "BGR" , 15);
         else if(gc == 31)
            strncpy(bxrcountry, "MDA" , 15);
         else
            strncpy(bxrcountry, "CUB" , 15);


  }



  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }



  cout << "#   COUNTRY            NAME   AGE WGT   HT  SUS     PRO                    AM" << endl;
  cout << "------------------------------------------------------------------------------" << endl;


  if(gamechoice == 1 && countrychoice == 1)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active >= 1 && bxr.totalfights >= 1 && bxr.wc == 0)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else if(gamechoice == 2 && countrychoice == 1)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active >= 1 && bxr.totalfights <= 0 && bxr.wc <= 0)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else if(gamechoice == 3 && countrychoice == 1)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active >= 1 && bxr.wc >= 1)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else if(gamechoice == 4 && countrychoice == 1)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }


  else if(gamechoice == 1 && countrychoice == 2)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active >= 1 && bxr.totalfights >= 1 && bxr.wc == 0 && (strcmp (bxr.country,bxrcountry) == 0))
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else if(gamechoice == 2 && countrychoice == 2)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active >= 1 && bxr.totalfights <= 0 && bxr.wc <= 0 && (strcmp (bxr.country,bxrcountry) == 0))
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else if(gamechoice == 3 && countrychoice == 2)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active >= 1 && bxr.wc >= 1 && (strcmp (bxr.country,bxrcountry) == 0))
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else if(gamechoice == 4 && countrychoice == 2)
  {
   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if((strcmp (bxr.country,bxrcountry) == 0))
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }
  }

  else
  {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      profile.close();
      return;
  }

   profile.close();

   cout << endl;

    cin.sync();
    getch();

    return;
}
