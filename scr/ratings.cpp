

#include "hbpheader.h"

void ratings(void)
{

  fstream timefile;
  fstream ratingoutput;
  fstream profile;
  fighttime ft;
  boxer bxr;


  int i = 0;
  int j;
  int p;
  int e;
  int c = 0;
  int u = 1;

    timefile.open("GAMETIME.BIN",ios::in|ios::binary);
    if(timefile.fail())
       {
        cout << "Could not create Time file - Press a key" << endl;
        getch();
        exit(1);
       }

      timefile.read((char *)(&ft),STRUCTSIZETIME);
      timefile.close();

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


if(ft.week == 1 && (ft.month == 8 || ft.month == 11))
{

  ratingoutput.open("AMATEURRATINGLIST.txt",ios::out|ios::app);
  if(ratingoutput.fail())
  {
  cout << "Could not write to boxer list file 3 - Press a key" << endl;
        getch();
        exit(1);
  }
    ratingoutput << endl << endl;
    ratingoutput << "       DATE: " << "1" << "/" << ft.month << "/" << ft.year << endl;
    ratingoutput << "          AMATEUR RATINGS" << endl;
    ratingoutput << "------------------------------------" << endl;


 for (e = 0; e < i; e++)
 {

    if(ratebox[e].totalfights == 0 && ratebox[e].active == 1 && ratebox[e].wc == 0 && (ratebox[e].amwins > 0 || ratebox[e].amloses > 0))
    {
    ratingoutput << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(11) << ratebox[e].surname << setw(4) << ratebox[e].firstname << setw(4) << ratebox[e].weight << setw(11)
    << ratebox[e].amwins << "-" << ratebox[e].amloses  <<endl;
    u++;
    }

 }
 ratingoutput.close();

}



  if(ft.week == 4)
{

  ratingoutput.open("PRORATINGLISTH.txt",ios::out|ios::app);
  if(ratingoutput.fail())
  {
  cout << "Could not write to boxer list file H - Press a key" << endl;
        getch();
        exit(1);
  }

    ratingoutput << endl << endl;
    ratingoutput << "       DATE: " << "4" << "/" << ft.month << "/" << ft.year << endl;
    ratingoutput << "          PRO +210 TOP TEN" << endl;
    ratingoutput << "------------------------------------" << endl;

 u = 1;

 for (e = 0; e < i; e++)
 {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && ratebox[e].weight > CRUZERLIMIT && u <= 10 && ratebox[e].wc == 0)
    {
    ratingoutput << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(11) << ratebox[e].surname << setw(4) << ratebox[e].firstname << setw(4) << ratebox[e].weight << setw(11)
    << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

 }
  ratingoutput.close();
}



  if(ft.week == 4)
{

  ratingoutput.open("PRORATINGLISTZ.txt",ios::out|ios::app);
  if(ratingoutput.fail())
  {
  cout << "Could not write to boxer list file 7 - Press a key" << endl;
        getch();
        exit(1);
  }
    ratingoutput << endl << endl;
    ratingoutput << "       DATE: " << "4" << "/" << ft.month << "/" << ft.year << endl;
    ratingoutput << "          PRO -210 RATINGS" << endl;
    ratingoutput << "------------------------------------" << endl;

 u = 1;

 for (e = 0; e < i; e++)
 {

    if(ratebox[e].totalfights > 0 && ratebox[e].active == 1 && ratebox[e].weight <= CRUZERLIMIT && ratebox[e].wc == 0)
    {
    ratingoutput << "#" << setw(5) << u << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << setw(4) << ratebox[e].weight << setw(11)
    << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
    u++;
    }

 }
    ratingoutput.close();
}


   profile.close();

   delete []ratebox;

    ratebox = nullptr;

   system("cls");

return;





}
