// HBP Globel header file

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <cstring>
#include <new>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>


using namespace std;

struct fighttime {
                  int week;
                  int month;
                  int year;
                  int boxernumber;
                 };

struct boxer{
                  char firstname[20];
                  char surname[30];
                  char nickname[15];
                  char country[15];
                  int fighternumber;
                  int active;
                  int inactive;
                  int age;
                  int heightfeet;
                  int heightinches;
                  int imprpoints;
                  int attack;
                  int defence;
                  int power;
                  int strengh;
                  int conditioning;
                  int chin;
                  int drive;
                  int weight;
                  int baseweight;
                  int rating;
                  int wc;
                  int roids;
                  int title;
                  int amorpro;
                  int totalfights;
                  int wins;
                  int loses;
                  int draws;
                  int ko;
                  int koby;
                  int amwins;
                  int amloses;
                  int suspend;
           };

struct records   {
                  int recnum;
               	  int week;
               	  int month;
               	  int year;
                  int weight;
                  int wt;
                  char opfirstname[20];
                  char opsurname[30];
                  char outcome[10];
                  char venue[15];
                  char title[30];
                 };

const int STRUCTSIZETIME  = sizeof(struct fighttime);
const int STRUCTSIZEPRO   = sizeof(struct boxer);
const int STRUCTSIZEREC   = sizeof(struct records);
const int WEIGHTLIMIT     = 265;
const int CRUZERLIMIT     = 210;
const int AGELIMIT        = 21;
const int SKILLTOP        = 49;
