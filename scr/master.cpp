
#include "hbpheader.h"

void master(void)
{

    fstream boxlist;
    fstream profile;

     boxer bxr;

     int i;




 boxlist.open("MASTERRECORDS.txt",ios::out);
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


  boxlist << "   BOXER MASTER DATA SHEET" << endl;
  boxlist << "   -----------------------------------" << endl;

  i = 1;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {

    boxlist << '#' << bxr.fighternumber << " Name: " << bxr.firstname << " " << bxr.surname << "(" <<  bxr.country << ")" "  Attack: "<< bxr.attack << " Defence: "
    << bxr.defence << " Strengh: " << bxr.strengh << " Power: "<< bxr.power << " Stamina: " << bxr.conditioning << " Chin: "  << bxr.chin << " Baseweight: " << bxr.baseweight
    << " Drive: " << bxr.drive << "  Rating: "  <<  bxr.rating << endl;
    i++;
   }

  cout << endl;

  cin.sync();
  _getch();

  profile.close();
  boxlist.close();

 return;

}
