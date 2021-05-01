#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class candidate
{
    char n[20];

    public:
    signed int v;
    void read()
    {
        cout<<"Enter the name of candidate ";
        cin>>n;
        v=0;
    }
    void disp()
    {
        cout<<n;
    }
};


main()
{system("cls");
    int n,ch,i,s=0;
    candidate c[5];
    cout<<"Enter the name of 5 candidates serial number wise"<<endl;
    for(i=0;i<5;i++)
    {
        c[i].read();
    }
    cout<<"Enter the number of ballot papers to be counted ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Serial number and name of candidates"<<endl;
        cout<<"1-";
        c[0].disp();
        cout<<endl<<"2-";
        c[1].disp();
        cout<<endl<<"3-";
        c[2].disp();
        cout<<endl<<"4-";
        c[3].disp();
        cout<<endl<<"5-";
        c[4].disp();
        cout<<endl<<endl<<"Enter the serial number as on ballot  "<<i<<" ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                c[0].v++;
                break;
            case 2:
                c[1].v++;
                break;
            case 3:
                c[2].v++;
                break;
            case 4:
                c[3].v++;
                break;
            case 5:
                c[4].v++;
                break;
            default:
                s++;
        }

    }

    cout<<"Votes Secured by Each Candidate "<<endl;
    cout<<"1-";
    c[0].disp();
    cout<<'\t'<<c[0].v<<endl<<"2-";
    c[1].disp();
    cout<<'\t'<<c[1].v<<endl<<"3-";
    c[2].disp();
    cout<<'\t'<<c[2].v<<endl<<"4-";
    c[3].disp();
    cout<<'\t'<<c[3].v<<endl<<"5-";
    c[4].disp();
    cout<<'\t'<<c[4].v<<endl;
    cout<<"Spoilt ballets "<<'\t'<<s<<endl;
     cout<<endl;
    cout<<"Press any key to continue......";
    getch();
}