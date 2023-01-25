// boxer rankings


#include "hbpheader.h"

void worldhistory(void)
{

    fstream ledg;

    string line;

    char tc;

       cout << endl << endl << endl;
       cout << setw(40) << "TITLE FIGHT HISTORY:" << endl << endl;
       cout << "        A: WORLD TITLE" << endl;
       cout << "        B: -210 WORLD TITLE" << endl;
       cout << "        C. INTER-CONTINENTAL TITLE" << endl;
       cout << "        D. INTERNATIONAL TITLE" << endl;
       cout << "        E: AMERICAS TITLE" << endl;
       cout << "        F: EUROPEAN TITLE" << endl;
       cout << "        G. AFRICAN TITLE" << endl;
       cout << "        H. AUSTRALASIA TITLE" << endl;
       cout << "        I. ASIA TITLE" << endl;

      cin  >> tc;
      tc = tolower(tc);

    if(tc == 'a')
    {

    cout << endl << endl;
    cout << "                  WORLD HEAVYWEIGHT TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("WORLDHEAVYTITLES.txt");
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

   if(tc == 'b')
    {

    cout << endl << endl;
    cout << "                  WORLD -210 TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("WORLDUNDER210TITLES.txt");
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


   if(tc == 'c')
    {

    cout << endl << endl;
    cout << "                  INTER-CONTINENTAL TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("INTERCONTITLE.txt");
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

   if(tc == 'd')
    {

    cout << endl << endl;
    cout << "                  INTERNATIONAL TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("INTERNATIONALTITLE.txt");
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

   if(tc == 'e')
    {

    cout << endl << endl;
    cout << "                  AMERICAS TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("AMERICASTITLE.txt");
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

   if(tc == 'f')
    {

    cout << endl << endl;
    cout << "                  EUROPEAN TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("EUROPEANTITLE.txt");
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

    if(tc == 'g')
    {

    cout << endl << endl;
    cout << "                  AFRICAN TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("AFRICANTITLE.txt");
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

    if(tc == 'h')
    {

    cout << endl << endl;
    cout << "                  AUSTRALASIA TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("AUSTRALASIATITLE.txt");
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

    if(tc == 'i')
    {

    cout << endl << endl;
    cout << "                  ASIA TITLE BOUTS" << endl;
    cout << "---------------------------------------------------------" << endl;

                ledg.open("ASIATITLE.txt");
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

      ledg.close();
      cin.sync();
      getch();

     system("cls");


   return;

}
