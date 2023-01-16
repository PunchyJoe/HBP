#include "hbpheader.h"




void amrandomize(void)
{

  ofstream output;
  fstream profile;
  boxer bxr;



  srand (time(NULL));

  char gamechoice;
  int e;
  int d;
  int ppe;
  int p;
  int j;

  int i = 0;
  int c = 0;
  int u = 1;


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

  boxer* boxrand = new boxer[i];


  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        getch();
        exit(1);
  }

  while(profile.read((char *)(&boxrand[c]),STRUCTSIZEPRO))
  {
     c++;
  }

   profile.close();

  for (d = 0; d < i; d++)
  {
      ppe =  rand() % 900;
      boxrand[d].rating = ppe;
  }


  for (p = 0; p < i; p++)
  {
          for (j = 0; j < i-(p); j++)
          {
             if (boxrand[j].rating < boxrand[j+1].rating)
              {
                swap(boxrand[j], boxrand[j+1]);
              }


         }
   }

  cout <<endl << endl;
  cout << "                          Generate List:" << endl << endl;
  cout << "                          A: Random Amateur Boxers" << endl;
  cout << "                          B: Random Boxers All" << endl;
  cout << "                          C: All Boxers Alphabetical List" << endl;
  cin  >> gamechoice;

  gamechoice = tolower(gamechoice);


  if(gamechoice == 'a')
  {
  output.open("RANDOMAM.txt",ios::out);
  if(output.fail())
  {
  cout << "Could not write to boxer list file Am - Press a key" << endl;
        getch();
        exit(1);
  }

      output << "          Random Amateurs" << endl;
    output << "------------------------------------" << endl;

 for (e = 0; e < i; e++)
 {

    if(boxrand[e].amorpro == 0 && boxrand[e].active == 1 && boxrand[e].suspend == 0 && boxrand[e].wc == 0)
    {
    output << "#" << setw(5) << boxrand[e].fighternumber << setw(4) << boxrand[e].country << setw(18) << boxrand[e].surname << setw(4) << boxrand[e].firstname << setw(11)
    <<  boxrand[e].amwins << "-" << boxrand[e].amloses  <<endl;
    }
    u++;
 }
   output.close();
  }

 if(gamechoice == 'b')
  {
  output.open("RANDOMALL.txt",ios::out);
  if(output.fail())
  {
  cout << "Could not write to boxer list file All - Press a key" << endl;
        getch();
        exit(1);
  }

    output << "          All Random Boxers" << endl;
    output << "----------------------------------------------------" << endl;

 for (e = 0; e < i; e++)
 {

    if(boxrand[e].active == 1 && boxrand[e].wc == 0)
    {
    output << "#" << setw(5) << boxrand[e].fighternumber << setw(4) << boxrand[e].country << setw(18) << boxrand[e].surname << setw(4) << boxrand[e].firstname
    << setw(11) <<  boxrand[e].amwins << "-" << boxrand[e].amloses
    << setw(11) <<  boxrand[e].wins << "-" << boxrand[e].loses << "-" << boxrand[e].draws  <<endl;
    }
    u++;
 }
   output.close();
  }

 if(gamechoice == 'c')
  {

    for (p = 0; p < i; p++)
  {
          for (j = 0; j < i-(p); j++)
          {
             if (boxrand[j].surname[0] < boxrand[j+1].surname[0])
              {
                swap(boxrand[j], boxrand[j+1]);
              }
             if (boxrand[j].surname[0] == boxrand[j+1].surname[0])
             {
                if((boxrand[j].surname[1] < boxrand[j+1].surname[1]))
                {
                  swap(boxrand[j], boxrand[j+1]);
                }
                if (boxrand[j].surname[1] == boxrand[j+1].surname[1])
                {
                    if((boxrand[j].surname[2] < boxrand[j+1].surname[2]))
                    {
                       swap(boxrand[j], boxrand[j+1]);
                    }
                    if (boxrand[j].surname[2] == boxrand[j+1].surname[2])
                    {
                        if((boxrand[j].surname[3] < boxrand[j+1].surname[3]))
                         {
                            swap(boxrand[j], boxrand[j+1]);
                         }

                    }
                }

             }


         }
   }


  output.open("ALPHABETALL.txt",ios::out);
  if(output.fail())
  {
  cout << "Could not write to boxer list file All - Press a key" << endl;
        getch();
        exit(1);
  }

    output << "          All Boxers Alphabetically" << endl;
    output << "----------------------------------------------------" << endl;

 u = 1;

 for (e = i - 1; e >= 0; e--)
 {
    output << "#" << setw(5) << boxrand[e].fighternumber << "  " << setw(18) << left << boxrand[e].surname << " " << boxrand[e].firstname << endl;
    u++;
 }
   output.close();
  }



 //for (e = 0; e < i; e++)
 // {
 //    delete &boxrand[e].rating;
 //  }


delete [] boxrand;

boxrand = nullptr;

return;

}
