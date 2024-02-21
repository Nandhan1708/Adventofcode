#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int wordToNum(string ans)
{
    if (ans.find("one") != string::npos) {
        return 1;
    } else if (ans.find("two") != string::npos) {
        return 2;
    } else if (ans.find("three") != string::npos) {
        return 3;
    } else if (ans.find("four") != string::npos) {
        return 4;
    } else if (ans.find("five") != string::npos) {
        return 5;
    } else if (ans.find("six") != string::npos) {
        return 6;
    } else if (ans.find("seven") != string::npos) {
        return 7;
    } else if (ans.find("eight") != string::npos) {
        return 8;
    } else if (ans.find("nine") != string::npos) {
        return 9;
    } else {
        return -1;
    }
}

pair<int, int> findint(string arr)
{
    int fi=-1;
    int li=-1;
    char end;
    string currentword;
    for(char ch:arr)
    {
        if(isdigit(ch))
        {
            int number=ch-'0';
            if(fi==-1)
            {
                fi=number;
                currentword.clear();
            }
            li=number;
            currentword.clear();
        }
        else
        {
            currentword+=ch;
            int number=wordToNum(currentword);
            if(number!=-1)
            {
                end=currentword.back();
                currentword.clear();
                if(fi==-1)
                {
                    fi=number;
                }
                li=number;
                currentword+=end;
            }
        }
    }
    return {fi,li};
}

int main()
{
    string filename;
    cout<<"Enter file name";
    cin>>filename;
    fstream reader;
    string val;
    int sum=0,fa,la;
    vector<int> arr;

    reader.open(filename);
    if(reader.is_open())
    {
        while(getline(reader,val))
        {
            auto result=findint(val);
            if(result.first==-1)
            {
                //cout<<result.first<<result.second<<endl;
                sum+=0;
            }
            else
            {
                //cout<<result.first<<result.second<<endl;
                fa=(result.first)*10;
                la=result.second;
                sum+=(fa+la);
                fa=la=0;
            }
        }
        cout<<"The sum of all the numbers is "<<sum<<endl;
        reader.close();
    }
    else
    {
        cout<<"Error in opening the file!!";
    }
    return 0;
}