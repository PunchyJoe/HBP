#include "hbpheader.h"




void allambouts(void)
{



    char gamechoice;
    fstream ledg;
    string line;

  cout <<endl << endl;
  cout << "                          BOXING RESULTS:" << endl << endl;
  cout << "                         -----------------:" << endl << endl;
  cout << "                          A: Pro Results" << endl;
  cout << "                          B: Olympic Results" << endl;
  cout << "                          C: Amateur Results" << endl;
  cout << "                          D: Unlicensed Results" << endl;

  cin  >> gamechoice;

  gamechoice = tolower(gamechoice);


    if(gamechoice == 'a')
    {
    cout << endl << endl;
    cout << "                  ALL PRO BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("ALLPROBOUTS.txt");
                if (ledg.fail())
                    {
                        cout << "ERROR: Cannot open the file..." << endl;
                        exit(0);
                    }
                while (getline (ledg,line))
                    {
                        cout << line << '\n';
                    }

                ledg.close();


                cout << endl;
                cout << endl;

                cout << endl;
                cout << endl;

      }




    if(gamechoice == 'b')
    {
    cout << endl << endl;
    cout << "                  ALL OLYMPIC BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("ALLOLYMBOUTS.txt");
                if (ledg.fail())
                    {
                        cout << "ERROR: Cannot open the file..." << endl;
                        exit(0);
                    }
                while (getline (ledg,line))
                    {
                        cout << line << '\n';
                    }

                ledg.close();


                cout << endl;
                cout << endl;

                cout << endl;
                cout << endl;

      }


    if(gamechoice == 'c')
    {
    cout << endl << endl;
    cout << "                  ALL AMATEUR BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("ALLAMBOUTS.txt");
                if (ledg.fail())
                    {
                        cout << "ERROR: Cannot open the file..." << endl;
                        exit(0);
                    }
                while (getline (ledg,line))
                    {
                        cout << line << '\n';
                    }

                ledg.close();


                cout << endl;
                cout << endl;

                cout << endl;
                cout << endl;

      }



    if(gamechoice == 'd')
    {
    cout << endl << endl;
    cout << "             ALL UNLICENSED BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("ALLUNLBOUTS.txt");
                if (ledg.fail())
                    {
                        cout << "ERROR: Cannot open the file..." << endl;
                        exit(0);
                    }
                while (getline (ledg,line))
                    {
                        cout << line << '\n';
                    }

                ledg.close();


                cout << endl;
                cout << endl;

                cout << endl;
                cout << endl;

      }


      cin.sync();
      _getch();


   system("cls");

   return;


}
