#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> dynamicVector;

int matrixLength1 = 0, matrixLength2 = 0;

void readVectorIn()
{
   ifstream file("VectorIn.txt");

   int tmp = 0;
   
   while (file >> tmp)
   {
      dynamicVector.push_back(tmp);
   }

   file.close();
}

void selectionSort()
{
   for(int i = 0; i < dynamicVector.size() - 1; i++)
   {
      int minIndex = i;

      for(int j = i+1; j < dynamicVector.size(); j++)
         if(dynamicVector[j] < dynamicVector[minIndex])
            minIndex = j;

      swap(dynamicVector[i], dynamicVector[minIndex]);
   }
}

void printVector()
{
   selectionSort();

   for(int i = 0; i < dynamicVector.size(); i++)
      cout << dynamicVector[i] << ' ';
}

int main()
{
   readVectorIn();
   printVector();

   return 0;
}