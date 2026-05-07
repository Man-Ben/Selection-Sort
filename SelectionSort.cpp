#include <iostream>
#include <fstream>
using namespace std;

int vector[100], matrix[25][25] = {0};
int vectorLength = 0, matrixLength1 = 0, matrixLength2 = 0;

void readVectorIn()
{
   ifstream file("VectorIn.txt");

   int tmp = 0;
   int i = 0;
   
   while (file >> tmp)
   {
      vector[i] = tmp;
      i++;
   }

   file.close();

   vectorLength = i;
   
}

void readMatrixIn()
{
   ifstream file("MatrixIn.txt");

   file >> matrixLength1 >> matrixLength2;

   for(int i = 0; i < matrixLength1; i++)
      for(int j = 0; j < matrixLength2; j++)
         file >> matrix[i][j];


   file.close();

}

void selectionSortVector()
{
   for(int i = 0; i < vectorLength - 1; i++)
   {
      int minIndex = i;

      for(int j = i+1; j < vectorLength; j++)
         if(vector[j] < vector[minIndex])
            minIndex = j;

      swap(vector[i], vector[minIndex]);
   }
}

void selectionSortMatrix()
{
   
}


void printVector()
{
   selectionSortVector();

   for(int i = 0; i < vectorLength; i++)
      cout << vector[i] << ' ';
}

void printMatrix()
{
   selectionSortMatrix();
   for(int i = 0; i < matrixLength1; i++)
   {
      for(int j = 0; j < matrixLength2; j++)
         cout << matrix[i][j] << ' ';
      cout << "\n";
   }
}

int main()
{

   readVectorIn();
   printVector();
   
   cout << "\n\n";

   readMatrixIn();
   printMatrix();

   return 0;
}