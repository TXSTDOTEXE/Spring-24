// "Solution" for ascii_art
#include<iostream>
using namespace std;

int main()
{
   // Create an ascii art of ".EXE" 
   cout << "    EEEEEEEE   XXX   XXX   EEEEEEEE" << endl;
   cout << "    EE    EE    XX   XX    EE    EE" << endl;
   cout << "    EE            X X      EE"       << endl;
   cout << "    EEEEE          X       EEEEE"    << endl;
   cout << "    EE            X X      EE"       << endl;
   cout << "    EE    EE    XX   XX    EE    EE" << endl;
   cout << "DOT EEEEEEEE   XXX   XXX   EEEEEEEE" << endl << endl;

   // Create a square that has a height of 2 and width of 35
   for (int i = 0; i < 2; i++)
   {
     for ( int j = 0; j < 35; j++)
        cout << "*";
     cout << endl;
   }

   return 0;
}
