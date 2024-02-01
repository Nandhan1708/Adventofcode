#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    fstream reader;
    string val;
    vector<int> arr;
    int first,second,ct,digit,sum=0;
    reader.open("Input.txt");
    if(reader.is_open())
    {
        while(getline(reader,val))
        {
            first=second=ct=digit=0;
            for(char c:val)
            {
                if(isdigit(c))
                {
                    ct++;
                    arr.push_back(stoi(string(1,c)));
                }
            }
            if(ct==1)
            {
                first=second=arr.front();
                digit=(first*10)+second;
                sum+=digit;
            }
            else if(ct==0)
            {
                digit=0;
                sum+=digit;
            }
            else
            {
                first=arr.front();
                second=arr.back();
                digit=(first*10)+second;
                sum+=digit;
            }
            arr.clear();
        }
        cout<<"The sum of the numbers present in the text file is "<<sum<<endl;
        reader.close();
    }
    else
    {
        cout<<"Error in opening the file"<<endl;
    }
    return 0;
}