#include <iostream>
#include <fstream>
using namespace std;

int vector[625], matrix[25][25];
int vectorLength = 0, matrixLength1 = 0, matrixLength2 = 0;

//Beolvassuk a vektort a .txt file-bol.
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

//Beolvassuk a mátrixot a .txt file-bol.
void readMatrixIn()
{
   ifstream file("MatrixIn.txt");

   file >> matrixLength1 >> matrixLength2;

   for(int i = 0; i < matrixLength1; i++)
      for(int j = 0; j < matrixLength2; j++)
         file >> matrix[i][j];


   file.close();

}

//Sorba vesszük a vektor elemeit, egyessével összehasonlitjuk az összes többi elemmel és ha az utobbi elem kisebb, megcsréljuk öket egymással.
void selectionSort(int vectorLength)
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

//A mátrixot (2 dimenziós tömb), vektorrá (1 dimenziós tömb) alakitjuk át.
void convertMatrixToVector()
{
   int k = 0;
   for(int i = 0; i < matrixLength1; i++)
      for(int j = 0; j < matrixLength2; j++)
      {
         vector[k] = matrix[i][j];
         k++;
      }  
}

//A selection sort után, ezzel alakitjuk a vektort vissza mátrix formába.
void convertVectorToMatrix()
{
   int k = 0;
   for(int i = 0; i < matrixLength1; i++)
      for(int j = 0; j < matrixLength2; j++)
      {
         matrix[i][j] = vector[k];
         k++;
      }  
}

//1 alprogrammal sorba tesszük a mátrix elemeit.
void sortMatrix()
{
   convertMatrixToVector();
   selectionSort(matrixLength1 * matrixLength2);
   convertVectorToMatrix();

}

//kiirjuk a vektort.
void printVector()
{
   selectionSort(vectorLength);

   for(int i = 0; i < vectorLength; i++)
      cout << vector[i] << ' ';
}

//kiirjuk a mátrixot.
void printMatrix()
{
   sortMatrix();

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
