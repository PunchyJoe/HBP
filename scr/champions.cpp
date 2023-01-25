
#include "hbpheader.h"



void champions(void)

{


  fstream profile;
  boxer bxr;


  int i = 0;
  int e;
  int c = 0;
  int u = 0;

  cout << endl << endl << endl;
  cout << "        CHAMPIONS" << endl;
  cout << "        ---------" << endl;




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





  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 1)
    {
       cout << "WORLD:             " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "WORLD: " << endl;
     }
    u = 0;



  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 2)
    {
       cout << "WORLD -210:        " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "WORLD -210: " << endl;
     }
    u = 0;


  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 4 || ratebox[e].title == 14)
    {
       cout << "INTER-CONTINENTAL: " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "INTER-CONTINENTAL: " << endl;
     }
    u = 0;


  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 5 || ratebox[e].title == 15)
    {
       cout << "INTERNATIONAL:     " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "INTERNATIONAL: " << endl;
     }
    u = 0;


  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 6 || ratebox[e].title == 16)
    {
       cout << "AMERICAS:          " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "AMERICAS: " << endl;
     }
    u = 0;


  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 7 || ratebox[e].title == 17)
    {
       cout << "EUROPE:            " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "EUROPE: " << endl;
     }
    u = 0;


  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 8 || ratebox[e].title == 18)
    {
       cout << "AFRICA:            " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "AFRICA: " << endl;
     }
    u = 0;

  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 9 || ratebox[e].title == 19)
    {
       cout << "AUSTRALASIA:       " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "AUSTRALASIA: " << endl;
     }
    u = 0;


  for (e = 0; e < i; e++)
  {

    if(ratebox[e].title == 10 || ratebox[e].title == 20)
    {
       cout << "ASIA:              " << ratebox[e].surname << setw(4) << ratebox[e].firstname << "   " << ratebox[e].country << "   " << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << endl;
       u = 1;
    }

  }
    if(u == 0)
     {
       cout << "ASIA: " << endl;
     }
    u = 0;





    profile.close();

    delete [] ratebox;

    ratebox = nullptr;


      cin.sync();
      getch();

      system("cls");

    return;

}
