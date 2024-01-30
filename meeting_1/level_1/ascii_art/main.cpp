/* The objective of this mini project is to collaborate and learn. 
The provided code is a starting point and its purpose is to help start the process. 
Your task is to fill in the missing code and implement the missing pieces
Feel free to modify the code extensively.
Don't be afraid to use the internet or ask for help.
Most importantly have fun!
*/
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
