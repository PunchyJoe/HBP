#include "hbpheader.h"



void ratingpoints(void)

{


  fstream profile;
  boxer bxr;


  int i = 0;
  int j;
  int p;
  int e;
  int c = 0;

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
          for (j = 0; j < i-(p); j++)
          {
             if (ratebox[j].rating < ratebox[j+1].rating)
              {
                swap(ratebox[j], ratebox[j+1]);
              }


         }
   }





 for (e = 0; e < i; e++)
 {

       cout << "#" << setw(5) << e+1 << setw(4) << ratebox[e].country << setw(3) << ratebox[e].age << setw(21) << ratebox[e].surname << setw(4) << ratebox[e].firstname << "  "<< ratebox[e].weight << setw(11);
       cout << ratebox[e].wins << "-" << ratebox[e].loses << "-" << ratebox[e].draws << " RATING - " << ratebox[e].rating << endl;

 }




    profile.close();

    delete [] ratebox;

    ratebox = nullptr;


      cin.sync();
      getch();

    return;

}
