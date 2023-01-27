#include "hbpheader.h"


void updatelists(void)
{


     fstream boxlist;
     fstream profile;
     fstream boxrecords;
     fstream timefile;
     fstream ratingoutput;

      fighttime ft;
      boxer bxr;
      int z;


       int a = 0;
       int c = 0;
       int j;
       int p;
       int e;
       int u;

    timefile.open("GAMETIME.BIN",ios::in|ios::binary);
    if(timefile.fail())
       {
        cout << "Could not create Time file - Press a key" << endl;
        _getch();
        exit(1);
       }

      timefile.read((char *)(&ft),STRUCTSIZETIME);
      timefile.close();


  // ratebox rankings

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        _getch();
        exit(1);
  }

   while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    a++;
  }

  profile.close();

   // vector<boxer> ratebox(a);


  boxer* ratebox = new boxer[a];


  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        _getch();
        exit(1);
  }

  while(profile.read((char *)(&ratebox[c]),STRUCTSIZEPRO))
  {
     c++;
  }


 for (p = 0; p < a; p++)
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






  for (p = 0; p < a; p++)
  {
          for (j = 0; j < a-(p); j++)
          {
             if (ratebox[j].rating < ratebox[j+1].rating)
              {
                swap(ratebox[j], ratebox[j+1]);
              }


         }
   }



  ratingoutput.open("ALLPRORATINGLISTH.txt",ios::out);
  if(ratingoutput.fail())
  {
  cout << "Could not write to boxer list file H - Press a key" << endl;
        _getch();
        exit(1);
  }

    ratingoutput << endl << endl;
    ratingoutput << "          DATE: " << ft.year << endl;
    ratingoutput << "          PRO +210 FULL RATINGS" << endl;
    ratingoutput << "------------------------------------" << endl;

 u = 1;

 for (e = 0; e < a; e++)
 {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && ratebox[e].weight > CRUZERLIMIT && ratebox[e].wc == 0)
    {
    ratingoutput << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << setw(4) << ratebox[e].weight << setw(11)
    << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

 }

  ratingoutput.close();

  ratingoutput.open("ALLPRORATINGLISTCZ.txt",ios::out);
  if(ratingoutput.fail())
  {
  cout << "Could not write to boxer list file H - Press a key" << endl;
        _getch();
        exit(1);
  }

    ratingoutput << endl << endl;
    ratingoutput << "          DATE: " << ft.year << endl;
    ratingoutput << "          PRO -210 FULL RATINGS" << endl;
    ratingoutput << "------------------------------------" << endl;

 u = 1;

 for (e = 0; e < a; e++)
 {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && ratebox[e].weight <= CRUZERLIMIT && ratebox[e].wc == 0)
    {
    ratingoutput << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << setw(4) << ratebox[e].weight << setw(11)
    << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

 }

  ratingoutput.close();

  profile.close();

  delete []ratebox;

  ratebox = nullptr;








  boxlist.open("BOXERLIST.txt",ios::out);
  if(boxlist.fail())
  {
  cout << "Could not write to boxer list file - Press a key" << endl;
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

  z = 0;

  boxlist << "   ACTIVE PRO BOXER LIST" << endl;
  boxlist << "   -----------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.active > 0 && bxr.totalfights > 0 && bxr.wc == 0)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Record " << bxr.wins << "(" << bxr.ko << ")" << bxr.loses << "(" << bxr.koby << ")-" << bxr.draws << endl;
    }

   }

  cout << endl;

  profile.close();
  boxlist.close();

    boxlist.open("HEAVYWEIGHTPLUSLIST.txt",ios::out);
  if(boxlist.fail())
  {
  cout << "Could not write to boxer list file - Press a key" << endl;
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

  z = 0;

    boxlist << "   ACTIVE PRO +210 BOXER LIST" << endl;
    boxlist << "   ------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.active > 0 && bxr.totalfights > 0 &&  bxr.weight > CRUZERLIMIT && bxr.wc == 0)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Inactive " << bxr.inactive << " Weeks" << "   Record " << bxr.wins << "(" << bxr.ko << ")" << bxr.loses << "(" << bxr.koby << ")-" << bxr.draws << endl;
    }

   }

  cout << endl;

  profile.close();
  boxlist.close();




  boxlist.open("CRUZERBOXERLIST.txt",ios::out);
  if(boxlist.fail())
  {
  cout << "Could not write to boxer list file - Press a key" << endl;
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

  z = 0;

    boxlist << "   ACTIVE PRO -210 BOXER LIST" << endl;
    boxlist << "   ------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.active > 0 && bxr.totalfights > 0 &&  bxr.weight <= CRUZERLIMIT && bxr.wc == 0)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Inactive " << bxr.inactive << " Weeks" << "   Record " << bxr.wins << "(" << bxr.ko << ")" << bxr.loses << "(" << bxr.koby << ")-" << bxr.draws << endl;
    }

   }

  cout << endl;

  profile.close();
  boxlist.close();





   boxlist.open("ACTIVEAMLIST.txt",ios::out);
  if(boxlist.fail())
  {
  cout << "Could not write to boxer list file - Press a key" << endl;
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

  z = 0;

    boxlist << "   ACTIVE AMATEUR BOXER LIST" << endl;
    boxlist << "   --------------------------" << endl;

 while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.active > 0 && bxr.totalfights < 1 && bxr.wc == 0)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Inactive " << bxr.inactive << " Weeks" << "   Record " << bxr.amwins << "-" << bxr.amloses  << endl;
    }
  }

  cout << endl;

  profile.close();
  boxlist.close();



boxlist.open("INACTIVELIST.txt",ios::out);
  if(boxlist.fail())
  {
  cout << "Could not write to boxer list file - Press a key" << endl;
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

  z = 0;

  boxlist << "   INACTIVE OR RETIRED BOXER LIST" << endl;
  boxlist << "   -----------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.active == 0)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Inactive " << bxr.inactive << " Weeks" << "   Record " << bxr.wins << "(" << bxr.ko << ")" << bxr.loses << "(" << bxr.koby << ")-" << bxr.draws << endl;
    }

   }

  cout << endl;

  profile.close();
  boxlist.close();



  boxlist.open("SUSPENSIONS.txt",ios::out);
  if(boxlist.fail())
  {
  cout << "Could not write to boxer list file - Press a key" << endl;
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

  z = 0;

  boxlist << "   SUSPENDED BOXER LIST INACTIVE" << endl;
  boxlist << "   -----------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.suspend >= 1 && bxr.active <= 0)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Inactive " << bxr.inactive << " Weeks" << "   Record " << bxr.wins << "(" << bxr.ko << ")" << bxr.loses << "(" << bxr.koby << ")-" << bxr.draws << endl;
    }

   }

   profile.close();

    profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

  z = 0;

  boxlist << endl;
  boxlist << "   SUSPENDED BOXER LIST ACTIVE" << endl;
  boxlist << "   -----------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    z++;
    if(bxr.suspend >= 1 && bxr.active >= 1)
    {
    boxlist << "#" << setw(5) << z << setw(4) << bxr.country << setw(21) << bxr.surname << setw(4) << bxr.firstname << setw(11) << bxr.age << ":age  " << bxr.weight << ":weight    " << bxr.heightfeet << "-"
    << bxr.heightinches << ":Height    Suspended:"  <<  bxr.suspend << "   Inactive " << bxr.inactive << " Weeks" << "   Record " << bxr.wins << "(" << bxr.ko << ")" << bxr.loses << "(" << bxr.koby << ")-" << bxr.draws << endl;
    }

   }

  cout << endl;

  profile.close();
  boxlist.close();




   return;

}
