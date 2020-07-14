
#include <iostream>
#include "DLinkedList.cpp"
#include <fstream>
#include <vector>

int getMax(vector<int> numbers)
{
    int mx = numbers[0];
    for (int i = 1; i < numbers.size(); i++)
        if (numbers[i] > mx)
            mx = numbers[i];
    return mx;
}

int getDigit(int number, int i)
{//gets Digit of number depending on radix
    
    
    int radix = 0;
    
        switch (i) {
            case 0:
                radix = 1;
                break;
            case 1:
                radix = 10;
                break;
            case 2:
                radix = 100;
                break;
            case 3:
                radix = 1000;
                break;
            case 4:
                radix = 10000;
                break;
            case 5:
                radix = 100000;
                break;
            case 6:
                radix = 1000000;
    
            default:
                break;
    
    
        }
    
    int getDigit = (number/radix)%10;
    
    
    return getDigit;
}


void bucketize(DList<int> bucket[],vector<int>&numbers,int i)
{
   
    
 
    
    for(int reset = 0; reset<10; reset++)
        bucket[reset].Clear();
    
    int bucketIndex;
 
    for(int j = 0; j<numbers.size(); j++)
    {
        bucketIndex = getDigit(numbers[j],i);
        bucket[bucketIndex].append(numbers[j]);
        
        
    }
    
    
}
void collect(DList<int> bucket[], vector<int>&numbers,int digi)
{
    
    numbers.clear();
  
    int theCollector;
    
    Node<int>*headReset[10];
    
    for(int i = 0; i<10; i++)
        headReset[i] = bucket[i].head;
    

    
    for(int j = 0; j<10; j++)
    {
        while(bucket[j].head!= NULL)
        {
            numbers.push_back(bucket[j].head->data);
            bucket[j].head = bucket[j].head->next;
            
            
        }
        bucket[j].head = headReset[j];
        
        
    }
    
    
}
    
    void testPrint(DList<int>buckets[],vector<int>&numbers)
    {
    
        for(int i = 0; i<numbers.size(); i++)
        {
            cout<<numbers[i]<<endl;
            cout<<endl;
        }
        
    }

    


int main() {
    
    DList<int> buckets[10];
    vector<int> numbers;
    
    fstream numberFile;
    numberFile.open("Numbers.txt");
    
    if(numberFile.fail())
    {
        cerr<<"Cannot Open File!"<<endl;
        exit(1);
    }
    
    int feeder;
    while(!(numberFile.eof()))//populate vector from numbers.txt
    {
        numberFile>>feeder;
        numbers.push_back(feeder);
        
    }
 
    
        int mx = getMax(numbers);
        int numDigits = 0;
        for (int radix = 1; mx/radix > 0; radix *= 10)
            numDigits++;//counts the numbers of digits of greatest number in list
            
    


    for(int i = 0; i<numDigits; i++)
    {
        

        bucketize(buckets,numbers,i);
        collect(buckets,numbers, i);


    }
    testPrint(buckets, numbers);
    


    return 0;
}
