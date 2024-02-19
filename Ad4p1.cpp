#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main()
{
    string filename;
    stringstream sso;
    string temp;
    map<int,int> mp;
    fstream reader;
    int num,inter,count=0,sum=0;
    vector<int> array;
    cout<<"Enter file name:";
    cin>>filename;
    string val;
    reader.open(filename);
    if(reader.is_open())
    {
        while(getline(reader,val))
        {
            sso<<val;
            while(!sso.eof())
            {
                sso>>temp;
                if(stringstream(temp)>>num)
                {
                    array.push_back(num);
                }
            }
            array.erase(array.begin());
            
            for(int i=0;i<array.size();i++)
            {
                mp[array[i]]++;
            }
            for (auto i = mp.begin(); i != mp.end(); i++)
            {
                if(i->second==2)
                {
                    count++;
                }
            }
            if(count==0)
            {
                sum+=0;
            }
            else if(count==1)
            {
                sum+=1;
            }
            else
            {
                inter=static_cast<int>(pow(2,count-1));
                sum+=inter;
            }
            
            inter=0;
            array.clear();
            sso.clear();
            temp.clear();
            mp.clear();
            count=0;
        }
        cout<<"The total points of the whole input file is "<<sum<<endl;
        reader.close();
    }
    else
    {
        cout<<"Error in opening the file!"<<endl;
    }
    return 0;
}