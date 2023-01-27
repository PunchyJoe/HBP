#include "hbpheader.h"




void amrandomize(void)
{

  ofstream output;
  fstream profile;
  boxer bxr;



  srand ( static_cast<unsigned int>(time(NULL)) );

  char gamechoice;
  int e;
  int d;
  int ppe;
  int p;
  int j;

  int i = 0;
  int c = 0;


  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        _getch();
        exit(1);
  }

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
  }

  profile.close();

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file 1 - Press a key" << endl;
        _getch();
        exit(1);
  }






  cout <<endl << endl;
  cout << "                          Generate List:" << endl << endl;
  cout << "                          A: Random Amateur Boxers" << endl;
  cout << "                          B: Random Professional Boxers" << endl;
  cout << "                          C: All Boxers Alphabetical List" << endl;
  cin  >> gamechoice;

  gamechoice = tolower(gamechoice);


  if(gamechoice == 'a')
  {

  boxer* boxrand = new boxer[i];

  //vector<boxer> boxrand(i);


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

  output.open("RANDOMAM.txt");
  if(output.fail())
  {
  cout << "Could not write to boxer list file Am - Press a key" << endl;
        _getch();
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
 }
   output.close();
   delete [] boxrand;
   boxrand = nullptr;
  }

 if(gamechoice == 'b')
  {

  boxer* boxrand = new boxer[i];

  //vector<boxer> boxrand(i);


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


  output.open("RANDOMALL.txt");
  if(output.fail())
  {
  cout << "Could not write to boxer list file All - Press a key" << endl;
        _getch();
        exit(1);
  }

    output << "          Random Professionals" << endl;
    output << "----------------------------------------------------" << endl;

 for (e = 0; e < i; e++)
 {

    if(boxrand[e].amorpro == 1 && boxrand[e].active == 1 && boxrand[e].suspend == 0 && boxrand[e].wc == 0)
    {
    output << "#" << setw(5) << boxrand[e].fighternumber << setw(4) << boxrand[e].country << setw(18) << boxrand[e].surname << setw(4) << boxrand[e].firstname << setw(6)
    <<  boxrand[e].weight << setw(11) <<  boxrand[e].wins << "-" << boxrand[e].loses << "-" << boxrand[e].draws  <<endl;
    }
 }
   output.close();
   delete [] boxrand;
   boxrand = nullptr;
  }

 if(gamechoice == 'c')
  {

    boxer* boxrand = new boxer[i];

    //vector<boxer> boxrand(i);

  while(profile.read((char *)(&boxrand[c]),STRUCTSIZEPRO))
  {
      c++;
  }

  profile.close();

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


  output.open("ALPHABETALL.txt");
  if(output.fail())
  {
  cout << "Could not write to boxer list file All - Press a key" << endl;
        _getch();
        exit(1);
  }

    output << "          All Boxers Alphabetically" << endl;
    output << "----------------------------------------------------" << endl;


 for (e = i - 1; e >= 0; e--)
 {
    output << "#" << setw(5) << boxrand[e].fighternumber << setw(4) << boxrand[e].country << setw(18) << boxrand[e].surname << setw(4) << boxrand[e].firstname << setw(11)
    <<  boxrand[e].amwins << "-" << boxrand[e].amloses << setw(11) <<  boxrand[e].wins << "-" << boxrand[e].loses << "-" << boxrand[e].draws  <<endl;
 }
   output.close();
   delete [] boxrand;
   boxrand = nullptr;
  }


return;

}
