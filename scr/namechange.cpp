#include "hbpheader.h"

void namechange(void)
{



  fstream profile;
  fstream boxname;

  boxer bxr;

  string secondname;

  int i = 0;
  int boxerchoice;
  int howmany = 0;
  int setcon = 0;
  int setvow = 0;
  int z = 0;
  int ffs = 0;
  int ohffs = 0;
  char di[4];
  char nn[30];
  char mych;
  char ri, fl, sl, ni, ko, bg;

  srand (time(NULL));

  profile.open("PROBOXERS.BIN",ios::binary|ios::in);
  if(profile.fail())
  {
  cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
  }

  cout << "#   COUNTRY            NAME   AGE WGT   HT  SUS     PRO                    AM" << endl;
  cout << "------------------------------------------------------------------------------" << endl;

  while(profile.read((char *)(&bxr),STRUCTSIZEPRO))
  {
    i++;
    if(bxr.active == 1 && bxr.totalfights == 0 && bxr.amwins == 0 && bxr.amloses == 0)
    {
           cout << setw(5) << i << setw(16) << bxr.surname << setw(4) << bxr.firstname << setw(4)
           << bxr.age  << setw(4) << bxr.weight  << setw(4) << bxr.heightfeet << "-"
           << bxr.heightinches << setw(3) <<  bxr.suspend << setw(7) << bxr.wins << setw(2) << '-' << setw(2) << bxr.loses << setw(2) << '-' << setw(2) << bxr.draws
           << setw(2) << " (" << setw(2) << bxr.ko << setw(2) << ")(" << setw(2) << bxr.koby << setw(1) << ")"
           << setw(6) << bxr.amwins << setw(3) << bxr.amloses << endl;
    }
  }

  cout << endl;

  cout << "Enter number of boxer to set new name ? 0 to Exit" << endl;
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


    cout << endl << endl;
    cout << "                          A:Change name manually" << endl;
    cout << "                          B.Change surname randomly " << endl;
    cout << "                          C.New Name Beginning with...?" << endl;
    cin >> ri;

    ri = tolower(ri);

    profile.close();


     profile.open("PROBOXERS.BIN",ios::binary|ios::in|ios::out);
       if(profile.fail())
       {
        cout << "Could not open Pro Boxers file - Press a key" << endl;
        getch();
        exit(1);
        }

      for(int d = 0; d <= boxerchoice; d++)
        {
          profile.read((char *)(&bxr),STRUCTSIZEPRO);
        }

        if(ri == 'a')
        {

            profile.seekp(-STRUCTSIZEPRO, ios::cur);
            cout << "Enter First Initial of First Name " << endl;
            cin >> fl;
            fl= toupper(fl);
            bxr.firstname[0] = fl;
            bxr.firstname[1] =  '.';
            cout << "Enter Second Initial of First Name " << endl;
            cin >> sl;
            sl= toupper(sl);
            bxr.firstname[2] = sl;
            cin.sync();
            cout << "Enter New Surname " << endl;
            cin.getline(nn,30);
            nn[0] = toupper(nn[0]);
            strncpy(bxr.surname, nn ,14);
            profile.write((char *)(&bxr),STRUCTSIZEPRO);

        }

        if(ri == 'b')
        {

       profile.seekp(-STRUCTSIZEPRO, ios::cur);

       howmany = rand() % 12 + 3;

       ohffs = rand() % 100 + 1;

       if(ohffs < 90)
          ffs = 0;
       else
          ffs = 1;

     for(z = 0; z < howmany; z++)
     {

             if(ffs == 0)
             {
             setcon = rand() % 19 + 1;

                         switch (setcon)
                         {
                          case 1:
      	                   nn[z] = 'b';
      	                  break;
 	                      case 2:
      	                   nn[z] = 'c';
      	                  break;
 	                      case 3:
      	                   nn[z] = 'd';
      	                  break;
 	                      case 4:
      	                   nn[z] = 'f';
      	                  break;
 	                      case 5:
      	                   nn[z] = 'g';
      	                  break;
 	                      case 6:
                           nn[z] = 'h';
      	                  break;
 	                      case 7:
                           nn[z] = 'j';
      	                  break;
 	                      case 8:
      	                   nn[z] = 'k';
      	                  break;
 	                      case 9:
                           nn[z] = 'l';
      	                  break;
 	                      case 10:
      	                  nn[z] = 'm';
      	                  break;
 	                      case 11:
      	                  nn[z] = 'n';
      	                  break;
 	                      case 12:
      	                   nn[z] = 'p';
                          break;
 	                      case 13:
                           nn[z] = 'r';
      	                  break;
 	                      case 14:
      	                  nn[z] = 's';
      	                  break;
 	                      case 15:
      	                  nn[z] = 't';
      	                  break;
 	                     case 16:
      	                  nn[z] = 'v';
                         break;
                         case 17:
      	                  nn[z] = 'w';
      	                 break;
 	                     case 18:
                         nn[z] = 'y';
      	                 break;
 	                     case 19:
      	                 nn[z] = 'z';
                        break;
                        default: nn[z] = 's';
                         }

                         ffs = 1;
                  }

                else
                {
                 setvow = rand() % 5 + 1;

                 switch (setvow)
                         {
                          case 1:
      	                  nn[z] = 'a';
      	                  break;
 	                      case 2:
      	                   nn[z] = 'e';
      	                  break;
 	                      case 3:
      	                   nn[z] = 'i';
      	                  break;
 	                      case 4:
      	                   nn[z] = 'o';
      	                  break;
 	                      case 5:
      	                   nn[z] = 'u';
      	                  break;
                          default: nn[z] = 'i';

                         }
                       ffs = 0;
                }

 }

         mych = nn[0];

         mych = toupper(mych);

         nn[0] = mych;

        cout << endl << endl << endl;
        cout << "Name: " << bxr.firstname << " " << nn << endl << endl;
        cout << "                          Is this correct y/n" << endl;
        cin >> bg;

        if(bg == 'n' || bg == 'N')
        {
           cout << "     OK NEW NAME SCRAPPED!" << endl << endl;
           getch();
           profile.close();
           return;
        }

         memset(bxr.surname, 0, sizeof bxr.surname);
         strncpy(bxr.surname, nn ,14);
         profile.write((char *)(&bxr),STRUCTSIZEPRO);

        }





    if(ri == 'c')
    {
     profile.seekp(-STRUCTSIZEPRO, ios::cur);

     boxname.open("BOXERNAMES.txt",ios::in);
     if(boxname.fail())
     {
        cout << "Could not read from boxer names file - Press a key" << endl;
        getch();
        exit(1);
     }

    cout << "Enter first letter of name? " << endl;
    cin >> ni;

    if(isalpha(ni))
    {

     ni = toupper(ni);

    do
    {

     do
     {
     boxname.seekp(0, ios::beg);
     howmany = rand() % 88799 + 1;

     for(z = 0; z <= howmany; z++)
     {

         getline(boxname, secondname);
         ohffs = secondname.length();
     }

     }while(ohffs > 14 || secondname[0] != ni);



     strcpy(bxr.surname, secondname.c_str());

     for(z = 1; z < ohffs; z++)
     {
         mych = bxr.surname[z];
         mych = tolower(mych);
         bxr.surname[z] = mych;
     }

        cout << endl << endl << endl;
        cout << "Name: " << bxr.firstname << " " << bxr.surname << endl << endl;
        cout << "                          Is this correct y/n" << endl;
        cin >> ko;
        ko = tolower(ko);

    }while(ko != 'y');



    }

     boxname.close();
     profile.write((char *)(&bxr),STRUCTSIZEPRO);

     }





      profile.close();

     system("cls");

     return;
}
