#include "hbpheader.h"

void backup(int bk)
{
  int ch;
  ch = bk;

  if(ch == 1)
     {

     std::ifstream  proboxers("PROBOXERS.BIN", std::ios::binary);
     std::ofstream  oldproboxers("OLDPROBOXERS.BIN",   std::ios::binary);
     oldproboxers << proboxers.rdbuf();

     std::ifstream  prorecords("PRORECORDS.BIN", std::ios::binary);
     std::ofstream  oldprorecords("OLDPRORECORDS.BIN",   std::ios::binary);
     oldprorecords << prorecords.rdbuf();

     std::ifstream  amrecords("AMRECORDS.BIN", std::ios::binary);
     std::ofstream  oldamrecords("OLDAMRECORDS.BIN",   std::ios::binary);
     oldamrecords << amrecords.rdbuf();

     proboxers.close();
     oldproboxers.close();
     prorecords.close();
     oldproboxers.close();
     amrecords.close();
     oldamrecords.close();


     }


    if(ch == 2)
     {

     std::ifstream  proboxers("PROBOXERS.BIN", std::ios::binary);
     std::ofstream  backupproboxers("BACKUPPROBOXERS.BIN",   std::ios::binary);
     backupproboxers << proboxers.rdbuf();

     std::ifstream  prorecords("PRORECORDS.BIN", std::ios::binary);
     std::ofstream  backupprorecords("BACKUPPRORECORDS.BIN",   std::ios::binary);
     backupprorecords << prorecords.rdbuf();

     std::ifstream  amrecords("AMRECORDS.BIN", std::ios::binary);
     std::ofstream  backupamrecords("BACKUPAMRECORDS.BIN",   std::ios::binary);
     backupamrecords << amrecords.rdbuf();

     std::ifstream  gametime("GAMETIME.BIN", std::ios::binary);
     std::ofstream  backupgametime("BACKUPGAMETIME.BIN",   std::ios::binary);
     backupgametime << gametime.rdbuf();

     proboxers.close();
     backupproboxers.close();
     prorecords.close();
     backupproboxers.close();
     amrecords.close();
     backupamrecords.close();
     gametime.close();
     backupgametime.close();

    }

     return;
}
