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
      //cin.ignore(numeric_limits<streamsize>::max(), '\n');
      scanf_s("%*s");
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
//      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      scanf_s("%*s");
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
            strncpy_s(bxrcountry, "USA" , 15);
         else if(gc == 2)
            strncpy_s(bxrcountry, "ENG" , 15);
         else if(gc == 3)
            strncpy_s(bxrcountry, "NGA" , 15);
         else if(gc == 4)
            strncpy_s(bxrcountry, "RUS" , 15);
         else if(gc == 5)
            strncpy_s(bxrcountry, "DEU" , 15);
         else if(gc == 6)
            strncpy_s(bxrcountry, "IRL" , 15);
         else if(gc == 7)
            strncpy_s(bxrcountry, "AUS" , 15);
         else if(gc == 8)
            strncpy_s(bxrcountry, "ITA" , 15);
         else if(gc == 9)
            strncpy_s(bxrcountry, "JPN" , 15);
         else if(gc == 10)
            strncpy_s(bxrcountry, "CHN" , 15);
         else if(gc == 11)
            strncpy_s(bxrcountry, "FRA" , 15);
         else if(gc == 12)
            strncpy_s(bxrcountry, "SWE" , 15);
         else if(gc == 13)
            strncpy_s(bxrcountry, "NZL" , 15);
         else if(gc == 14)
            strncpy_s(bxrcountry, "BRA" , 15);
         else if(gc == 15)
            strncpy_s(bxrcountry, "ZAF" , 15);
         else if(gc == 16)
            strncpy_s(bxrcountry, "JAM" , 15);
         else if(gc == 17)
            strncpy_s(bxrcountry, "IND" , 15);
         else if(gc == 18)
            strncpy_s(bxrcountry, "SCO" , 15);
         else if(gc == 19)
            strncpy_s(bxrcountry, "WAL" , 15);
         else if(gc == 20)
            strncpy_s(bxrcountry, "CAN" , 15);
         else if(gc == 21)
            strncpy_s(bxrcountry, "DNK" , 15);
         else if(gc == 22)
            strncpy_s(bxrcountry, "POL" , 15);
         else if(gc == 23)
            strncpy_s(bxrcountry, "TUR" , 15);
         else if(gc == 24)
            strncpy_s(bxrcountry, "MEX" , 15);
         else if(gc == 25)
            strncpy_s(bxrcountry, "NIL" , 15);
         else if(gc == 26)
            strncpy_s(bxrcountry, "BLR" , 15);
         else if(gc == 27)
            strncpy_s(bxrcountry, "UKR" , 15);
         else if(gc == 28)
            strncpy_s(bxrcountry, "ROU" , 15);
         else if(gc == 29)
            strncpy_s(bxrcountry, "HUN" , 15);
         else if(gc == 30)
            strncpy_s(bxrcountry, "BGR" , 15);
         else if(gc == 31)
            strncpy_s(bxrcountry, "MDA" , 15);
         else
            strncpy_s(bxrcountry, "CUB" , 15);


  }



  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
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
//      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      scanf_s("%*s");
      profile.close();
      return;
  }

   profile.close();

   cout << endl;

    cin.sync();
    _getch();

    return;
}
