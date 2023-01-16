#include "hbpheader.h"

void inactiveboxers(void)
{
  fstream profile;
   boxer bxr;
   int i = 0;

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }

  cout << "#                   NAME      AGE WGT   HT     ACT      PRO                    AM" << endl;
  cout << "----------------------------------------------------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active < 1)
    {
    cout << setw(5) << i << setw(4) << bxr.country << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
    << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
    << bxr.heightinches << setw(7) << bxr.inactive  << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
    << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
    << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

     cin.sync();
      getch();



  profile.close();


     system("cls");

     return;
}
