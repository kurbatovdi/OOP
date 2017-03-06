// lab2.home.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <locale>


using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    int x;
    int all=0;
	ifstream Fin("Input2.txt");
	const int N =34;
    int A[N];
    char c;
    for(int i=0;i<N;i++)
        A[i]=0;
//    cout <<"ASCII код "<<endl;
    while(Fin>>c)
        {

       //cout << c <<":"<< x <<endl;
       c=tolower(c);
       x=int(c) + 256;
	          if (isalpha(c))
       {
        if(x>223 && x<256)
        {

          A[x-224]++;
        }
        if (x == 184)
         {
             A[32]++;
         }
        all++;
        }
        }
  for (int i=0;i<32;i++)
     {
		cout<<char(i-32)<<": "<<(double)A[i]*100/all<<"%"<<endl<<endl;
	 }
		cout<<char(-72)<<": "<<(double)A[32]*100/all<<"%"<<endl<<endl;
		cout<<"Кол-во букв в исходном тексте: "<<all<<endl;

    return 0;
}
