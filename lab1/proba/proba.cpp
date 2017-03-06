// proba.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
const double eps=10E-13;

double determ(double **a, int n)
{
        int i,j;
        double det=0;
        double** matr;
        if(n==1)
        {
                det=a[0][0];
        }
        else if(n==2)
        {
                det=a[0][0]*a[1][1]-a[0][1]*a[1][0];
        }
        else
        {
                matr=new double*[n-1];
                for(i=0;i<n;++i)
                {
                        for(j=0;j<n-1;++j)
                        {
                                if(j<i) 
                                        matr[j]=a[j];
                                else
                                        matr[j]=a[j+1];
                        }
                        det+=pow((double)-1, (i+j))*determ(matr, n-1)*a[i][n-1];
                }
                delete[] matr;
        }
        return det;
} 


double * Invers_Array ( double **a, double *y, int n )
{
	   int i;
	   ofstream Fout;
	   Fout.open("output.txt");
       double** E = new double*[n];
       for(int i=0;i<n;i++)
       E[i] = new double[n];

       for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         {
          if(i==j)
            E[i][j]=1;
          else
            E[i][j]=0;
         }


    double temp1;
    double tempA2;

      for(int i=0;i<n;i++)
        {
          for(int j=i;j<n;j++)
          {
            if(abs(a[j][i])<eps)
             {
               a[j][i]=0;
             }
            else
             {
                for(int k=i;k<n;k++)
                 {
                  swap(a[i][k],a[j][k]);
                 }
                    swap(y[i],y[j]);

                 for(int k=0;k<n;k++)
                  swap(E[i][k],E[j][k]);

                    temp1=a[i][i];

                for(int k=i;k<n;k++)
                 {
                  a[i][k]/=temp1;
                 }

                for(int k=0;k<n;k++)
                 {
                  E[i][k]/=temp1;
                 }

                 for(int k=i+1;k<n;k++)
                  {
                   tempA2= a[k][i];

                    for(int q=i;q<n;q++)
                    {
                        a[k][q]=a[k][q]-tempA2*a[i][q];
                    }

                    for(int q=0;q<n;q++)
                     {
                        E[k][q]=E[k][q]-tempA2*E[i][q];
                     }
                  }
                break;
            }
          }
        }

         double tempX;
         for(int i=n-1;i>0;i--)
         {
          for(int j=i;j>0;j--)
           {
             tempX=a[j-1][i];

              for(int k=i;k<n;k++)
               a[j-1][k] = a[j-1][k] - tempX*a[i][k];

              for(int k=0;k<n;k++)
                {
                 E[j-1][k] = E[j-1][k] - tempX*E[i][k];
                }
            }
          } 
/*			cout<<endl<<"Обратная матрица : "<<endl<<endl;

						for(int i=0;i<n;i++)
						 {
						 for(int j=0;j<n;j++)
						  printf("%8.2f",E[i][j]);
						  cout<<endl;
						 } */
			
 
       cout<<endl;

       double* X = new double[n];

        for (int i=0;i<n;i++)
          {
            X[i]=0;
            for(int j=0;j<n;j++)
             X[i]+=E[i][j]*y[j];
          }

		for (int i = 0; i < n; i++)
		Fout<< "x[" << i << "]=" << X[i] << endl;
		Fout.close();
		delete [] X;
		delete [] y;
return 0;
}





int main()
{
    setlocale (LC_ALL, "RUS");
    int n, i=0, count=0;
    double **a, *y, *X;
    ifstream Fin;
    ofstream Fout;
    Fin.open("input.txt");
    Fout.open("output.txt");

    Fin >> n;

    a = new double*[n];
    y = new double[n];
    for (int i = 0; i < n; i++)
    {
    a[i] = new double[n];
    for (int j = 0; j < n; j++)
        {
            Fin >> a[i][j];
        }
    }
    cout <<"Исходная матрица:";
    for (int i=0; i<n; i++)
    {
        cout<< endl;
        for(int j=0;j<n;j++)
        {
            printf("%8.2f",a[i][j]);
        }
    }
    cout <<endl<< endl;
    cout <<"Столбец свободных членов:" << endl;
    while(Fin>>y[count])
    {
    printf("%8.2f",y[count]);
	count++;
    }
	if (count<n)
	{
		cout << endl << endl <<"Не хватает элементов, укажите нужное кол-во" << endl;
		return 0;
	}
	else
	cout << endl;
    Fin.close();
	if 		((determ(a, n)<0) || (determ(a, n)>0))
	{
		cout << "Определитель матрицы " <<determ(a, n)<<" не равен 0, значит решение есть и оно единственное "<< endl;
	    Invers_Array(a, y, n);
	}
	else 
	{
		Fout<< "Система либо имеет бесконечное множество решений, либо не имеет решений, т.е. несовместна" << endl;
	} 

    return 0;
}

