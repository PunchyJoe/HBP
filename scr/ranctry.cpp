#include "hbpheader.h"



void ranctry(void)
{


  srand (time(NULL));

  int gc = 0;
  int percent = 0;
  char country[15];


   cout << endl << endl;
   cout << "   GENERATING HOST COUNTRY..................PRESS A KEY" << endl << endl;
   getch();
   cin.sync();


         gc = rand() % 15 + 1;
         percent = rand() % 100 + 1;

         if(gc <= 1)
            strncpy(country, "USA" , 15);
         else if(gc <= 2)
            strncpy(country, "ENG" , 15);
         else if(gc <= 3)
            strncpy(country, "DEU" , 15);
         else if(gc <= 4)
            strncpy(country, "CHN" , 15);
         else if(gc <= 5)
            strncpy(country, "RUS" , 15);
         else if(gc == 6)
            strncpy(country, "ITA" , 15);
         else if(gc == 7)
            strncpy(country, "AUS" , 15);
         else if(gc == 8)
            strncpy(country, "JPN" , 15);
         else if(gc == 9)
            strncpy(country, "FRA" , 15);
         else if(gc == 10)
            strncpy(country, "SWE" , 15);
         else if(gc == 11)
            strncpy(country, "NZL" , 15);
         else if(gc == 12)
            strncpy(country, "BRA" , 15);
         else if(gc == 13)
            strncpy(country, "ZAF" , 15);
         else if(gc == 14)
            strncpy(country, "CAN" , 15);
         else if(gc == 15)
            strncpy(country, "MEX" , 15);


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
        getch();
        cin.sync();

   return;

}
