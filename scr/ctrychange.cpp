#include "hbpheader.h"

void ctrychange(void)
{



  fstream profile;
  boxer bxr;

  int i = 0;
  int boxerchoice;
  char di[4];
  char gc, gz;

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

    cout << "#   COUNTRY            NAME   AGE WGT   HT  SUS     PRO                    AM" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active == 1 && bxr.totalfights == 0 && bxr.amwins == 0 && bxr.amloses == 0)
    {
           cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Enter Number of Boxer to set new Country ? 0 to Exit" << endl;
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
        _getch();
        exit(1);
        }


             for(int d = 0; d <= boxerchoice; d++)
             {
              profile.read((char *)(&bxr),STRUCTSIZEPRO);
             }

       profile.seekp(-STRUCTSIZEPRO, ios::cur);


       cout << endl << endl << endl;
       cout << setw(40) << "HOME COUNTRY:" << endl << endl;
       cout << "        A: USA" << endl;
       cout << "        B: England" << endl;
       cout << "        C. Cuba" << endl;
       cout << "        D. Nigeria" << endl;
       cout << "        E: Russia" << endl;
       cout << "        F: Germany" << endl;
       cout << "        G. OTHER" << endl;


       cin  >> gc;

       gc = tolower(gc);

     switch(gc)
	  {
		  case 'a': strncpy_s(bxr.country, "USA" , 15);
		  break;
		  case 'b': strncpy_s(bxr.country, "ENG" , 15);
		  break;
		  case 'c': strncpy_s(bxr.country, "CUB" , 15);
		  break;
		  case 'd': strncpy_s(bxr.country, "NGA" , 15);
		  break;
		  case 'e': strncpy_s(bxr.country, "RUS" , 15);
          break;
          case 'f': strncpy_s(bxr.country, "DEU" , 15);
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
		          case 'a': strncpy_s(bxr.country, "IRL" , 15);
		          break;
		          case 'b': strncpy_s(bxr.country, "AUS" , 15);
                  break;
		          case 'c': strncpy_s(bxr.country, "ITA" , 15);
                  break;
		          case 'd': strncpy_s(bxr.country, "JPN" , 15);
		          break;
		          case 'e': strncpy_s(bxr.country, "CHN" , 15);
                  break;
		          case 'f': strncpy_s(bxr.country, "FRA" , 15);
		          break;
		          case 'g': strncpy_s(bxr.country, "SWE" , 15);
                  break;
                  case 'h': strncpy_s(bxr.country, "NZL" , 15);
		          break;
		          case 'i': strncpy_s(bxr.country, "BRA" , 15);
		          break;
		          case 'j': strncpy_s(bxr.country, "ZAF" , 15);
		          break;
		          case 'k': strncpy_s(bxr.country, "JAM" , 15);
		          break;
		          case 'l': strncpy_s(bxr.country, "IND" , 15);
                  break;
		          case 'm': strncpy_s(bxr.country, "SCO" , 15);
		          break;
		          case 'n': strncpy_s(bxr.country, "WAL" , 15);
                  break;
                  case 'o': strncpy_s(bxr.country, "CAN" , 15);
		          break;
		          case 'p': strncpy_s(bxr.country, "DNK" , 15);
		          break;
		          case 'q': strncpy_s(bxr.country, "POL" , 15);
                  break;
		          case 'r': strncpy_s(bxr.country, "TUR" , 15);
		          break;
		          case 's': strncpy_s(bxr.country, "MEX" , 15);
                  break;
                  case 't': strncpy_s(bxr.country, "NIL" , 15);
                  break;
                  case 'u': strncpy_s(bxr.country, "BLR" , 15);
                  break;
                  case 'v': strncpy_s(bxr.country, "UKR" , 15);
                  break;
                  case 'w': strncpy_s(bxr.country, "ROU" , 15);
                  break;
                  case 'x': strncpy_s(bxr.country, "HUN" , 15);
                  break;
                  case 'y': strncpy_s(bxr.country, "BGR" , 15);
                  break;
                  case 'z': strncpy_s(bxr.country, "MDA" , 15);
                  break;
		  }
	  }

      cout << endl << endl;



     profile.write((char *)(&bxr),STRUCTSIZEPRO);




      profile.close();


     return;
}
