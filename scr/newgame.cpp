//new game

#include "hbpheader.h"

void congame(void);

void newgame(void)
 {
  fstream timefile, profile, recfile, amrecfile, frec;
  fighttime ft = {1,1,2998,1};
  char wantcon;


  cout << " Selecting a New Game will reset the game back to the start" << endl
  << " - All previus games and data will be deleted and lost for ever." << endl
  << " Do You want to continue? Y/N" << endl;
  cin  >> wantcon;

  if(wantcon == 'N' || wantcon == 'n')
   return;

  timefile.open("GAMETIME.BIN",ios::out|ios::binary);
  if(timefile.fail())
  {
  	cout << "Could not create Time file - Press a key" << endl;
        _getch();
        exit(1);
  }

  profile.open("PROBOXERS.BIN",ios::out|ios::binary);
  if(profile.fail())
  {
  	cout << "Could not create Pro Boxers file - Press a key" << endl;
        _getch();
        exit(1);
  }

  frec.open("BOXINGTV.txt",ios::out);
  if(frec.fail())
  {
  	cout << "Could not create Boxing TV file - Press a key" << endl;
        _getch();
        exit(1);
  }


  recfile.open("PRORECORDS.BIN",ios::out|ios::binary);
  if(recfile.fail())
  {
  	cout << "Could not create Pro Records file - Press a key" << endl;
        _getch();
        exit(1);
  }

  amrecfile.open("AMRECORDS.BIN",ios::out|ios::binary);
  if(amrecfile.fail())
  {
  	cout << "Could not create Amateur Records file - Press a key" << endl;
        _getch();
        exit(1);
  }

 timefile.write((char *)(&ft),STRUCTSIZETIME);

  timefile.close();
  profile.close();
  recfile.close();
  amrecfile.close();
  frec.close();

  congame();

 }
