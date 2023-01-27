#include "hbpheader.h"



void ranctry(void)
{


  srand ( static_cast<unsigned int>(time(NULL)) );

  int gc = 0;
  int percent = 0;
  char country[15];


   cout << endl << endl;
   cout << "   GENERATING HOST COUNTRY..................PRESS A KEY" << endl << endl;
   _getch();
   cin.sync();


         gc = rand() % 15 + 1;
         percent = rand() % 100 + 1;

         if(gc <= 1)
            strncpy_s(country, "USA" , 15);
         else if(gc <= 2)
            strncpy_s(country, "ENG" , 15);
         else if(gc <= 3)
            strncpy_s(country, "DEU" , 15);
         else if(gc <= 4)
            strncpy_s(country, "CHN" , 15);
         else if(gc <= 5)
            strncpy_s(country, "RUS" , 15);
         else if(gc == 6)
            strncpy_s(country, "ITA" , 15);
         else if(gc == 7)
            strncpy_s(country, "AUS" , 15);
         else if(gc == 8)
            strncpy_s(country, "JPN" , 15);
         else if(gc == 9)
            strncpy_s(country, "FRA" , 15);
         else if(gc == 10)
            strncpy_s(country, "SWE" , 15);
         else if(gc == 11)
            strncpy_s(country, "NZL" , 15);
         else if(gc == 12)
            strncpy_s(country, "BRA" , 15);
         else if(gc == 13)
            strncpy_s(country, "ZAF" , 15);
         else if(gc == 14)
            strncpy_s(country, "CAN" , 15);
         else if(gc == 15)
            strncpy_s(country, "MEX" , 15);


        cout << "   HOST COUNTRY IS............." << endl << endl;

        cin.sync();
        chrono::seconds dura(5);
        this_thread::sleep_for(dura);

        cout << "   PLEASE WAIT................" << endl << endl;

        cin.sync();
        this_thread::sleep_for(dura);

        cout << "      " << country << endl;
        cout << "      " << percent << "%" << endl << endl;
        cin.sync();
        _getch();
        cin.sync();

   return;

}
