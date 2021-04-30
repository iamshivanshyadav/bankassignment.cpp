
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;

class account
{
  char acct,n[20];
  signed int accno;

 public:
    long double bal;
   void read();
   void display();
   void dep()
    { int am;
      cout<<"Enter the money to be deposit ";
      cin>>am;
      bal=bal+am;
      cout<<"Your amount is deposited."<<endl;
    }
    char retacc()
    {
      return acct;
    }
    int retaccno()
    {
      return accno;
    }
    void acctype(char a)
    {
      acct=a;
    }
    
};

void account::read()
  {
   cout<<"Enter the name of the customer ";
   cin>>n;
   cout<<"Enter customer's account number ";
   cin>>accno;
   
    cout<<"Enter the balance ";
    cin>>bal;
}
 
  void account::display()
  { 
   {cout<<"Account number:-  "<<accno<<endl;
    cout<<"Name of account holder:-  "<<n<<endl;
    cout<<"Account type:-  ";
    if(toupper(acct)=='S')
    {
    cout<<"Saving account"<<endl;
    }
    else
    {
    cout<<"Current account"<<endl;
    }
    cout<<"Balance:- "<<bal;
  } }


class savings: public account
{ float am,b;
  account ac;
  public:
   
   void ci()
    {
      int t;
      cout<<"Enter the time period ";
      cin>>t;
      am=bal*(pow((1+0.05),t)-1);
      bal=bal+am;
      cout<<"Balance after compound interest at the rate of 5% per annum after ["<<t<<"] years is "<<bal<<endl;
    }

    void withdraw()
    { ci();
      cout<<"Enter the amount to be withdrawn ";
      cin>>am;
      bal=bal-am;
      cout<<"Your amount is withdrawn."<<endl<<"Amount left in account "<<bal<<endl;
    }
};


class current:public account
{ signed int chb=0,che[100];
float b,am;
  public:
   void chequebook()
   {
     cout<<"Enter the chequebook number ";
     cin>>chb;
     for(int i=1;i<=100;i++)
     {
       che[i-1]=chb*10+i;
     }
   }
   void minbal()
   {
     if(bal<1000)
      {
	bal=bal-50;
        cout<<"Penalty of Rs 50 has been imposed"<<endl;
      }
      else
      {
        cout<<"No penalty has been imposed"<<endl;
      }
   }
    

    void withdraw()
    {char ch;
     int i;
     signed int cheq;
     if(chb!=0)
     {
     cout<<"Do you want to withdraw with cheque y/n ";
     cin>>ch;
     if(toupper(ch)=='Y')
     {
       cout<<"Enter cheque number ";
       cin>>cheq;
       for(i=0;i<100;i++)
       {if(cheq==che[i])
          {
            cout<<"Enter the amount to be withdrawn ";
            cin>>am;
            if(bal-am<1000)
            {
              cout<<"Low amount, amount cannot be withdrawn"<<endl;
              minbal();
              break;
            }
            else
            {
              bal=bal-am;
              cout<<"Your amount is withdrawn."<<endl<<"Amount left in account "<<bal<<endl;
              che[i]=0;
              break;
            }
          }   
        }
        if(i==100)
        {
          cout<<"Cheque not found"<<endl;
        }
      }}
      else
      {
        cout<<"Enter the amount to be withdrawn ";
        cin>>am;
        if(bal-am<1000)
        {
          cout<<"Low amount, amount cannot be withdrawn"<<endl;
          minbal();
        }
       else
        {
          bal=bal-am;
          cout<<"Your amount is withdrawn."<<endl<<"Amount left in account "<<bal<<endl;
        }
      }
    }
};



main()
{
 system("cls");
 int ch,c,i,j;
 int b=0,d=0;
 float a;
 char p,y,x;
 account ac[100];
 savings s[100];
 current ca[100];
 do
 {
  cout<<endl<<"Main menu"<<endl;
  cout<<"1-Read data"<<endl;
  cout<<"2-Withdraw money"<<endl;
  cout<<"3-Deposit money"<<endl;
  cout<<"4-Display account details"<<endl;
  cout<<"5-Display details of all account"<<endl;
  cout<<"6-Exit"<<endl;
  cout<<"Enter your choice ";
  cin>>ch;
  switch(ch)
  {
  case 1:
  cout<<endl;
    while(1)
    {
     int e=1;
   while(e)
   {
	 cout<<"Enter the account type ('C' for current & 'S' for saving) ";
    cin>>x;
    cout<<endl;
     if(toupper(x)=='C'||toupper(x)=='S')
      {
		break;
      }
     else
     {
		cout<<"Enter S or C only"<<endl;
    }}
     if (toupper(x)=='S')
       {
       s[b].read();
       s[b].acctype(x);
       b++;
       }
       else
       {
         ca[d].read();
         ca[d].acctype(x);
         cout<<"Do you want to issue chequebook y/n ";
         cin>>p;
         if(toupper(p)=='Y')
         {
           ca[d].chequebook();
         }
         d++;
       }
     if(b==100)
     {
      cout<<"This is the last record. No more records can be stored further for savings account."<<endl;
      break;
     }
    if(d==100)
    {
       cout<<"This is the last record. No more records can be stored further for current account."<<endl;
      break;
    }
     cout<<"Do you want to continue y/n ";
     cin>>p;
     if(toupper(p)=='N')
     {break;
     }
     cout<<endl;
    }
    cout<<endl;
    cout<<"Press any key to continue......";
    getch();
    cout<<endl;
    break;
	case 2:
    cout<<endl;
    cout<<"Enter the account type ";
     cin>>x;
    if (toupper(x)=='S')
    {
      cout<<"Enter the account number ";
      cin>>c;
      for(i=0;i<b;i++)
      {
        if(c==s[i].retaccno())
        {
          s[i].withdraw();
          break;
        }
      }
      if(i==b)
    {
     cout<<"Account not found"<<endl;
    }
    }
    else
    {cout<<"Enter the account number ";
     cin>>c;
     for(i=0;i<d;i++)
      {
        if(c==ca[i].retaccno())
        {
          ca[i].withdraw();
          break;
        }
      }
    if(i==d)
    {
     cout<<"Account not found"<<endl;
    }}
    cout<<endl;
    cout<<endl<<"Press any key to continue......";
    getch();
    cout<<endl;
    break;
	case 3:
 cout<<"Enter the account type ";
     cin>>x;
    if (toupper(x)=='S')
    {
      cout<<"Enter the account number ";
      cin>>c;
      for(i=0;i<b;i++)
      {
        if(c==s[i].retaccno())
        {
          s[i].dep();
          break;
        }
      }
      if(i==b)
    {
     cout<<"Account not found"<<endl;
    }
    }
    else
    {cout<<"Enter the account number ";
     cin>>c;
     for(i=0;i<d;i++)
      {
        if(c==ca[i].retaccno())
        {
          ca[i].dep();
          break;
        }
      }
    if(i==d)
    {
     cout<<"Account not found"<<endl;
    }}
    cout<<endl;
    cout<<endl<<"Press any key to continue......";
    getch();
    cout<<endl;
    break;
   case 4:
  cout<<"Enter the account type ";
     cin>>x;
    if (toupper(x)=='S')
    {
      cout<<"Enter the account number ";
      cin>>c;
      for(i=0;i<b;i++)
      {
        if(c==s[i].retaccno())
        {
          s[i].display();
          break;
        }
      }
      if(i==b)
    {
     cout<<"Account not found"<<endl;
    }
    }
    else
    {cout<<"Enter the account number ";
     cin>>c;
     for(i=0;i<d;i++)
      {
        if(c==ca[i].retaccno())
        {
          ca[i].display();
          break;
        }
      }
    if(i==d)
    {
     cout<<"Account not found"<<endl;
    }}
    cout<<endl;
    cout<<endl<<"Press any key to continue......";
    getch();
    cout<<endl;
    break;
    case 5:
     cout<<"Savings accounts details "<<endl;
      for(i=0;i<b;i++)
      {
        s[i].display();
        cout<<endl;
        cout<<endl<<"Press any key to continue......";
        getch();
        cout<<endl;
      }
      cout<<"Current accounts details "<<endl;
      for(i=0;i<d;i++)
      {
        ca[i].display();
        cout<<endl;
        cout<<endl<<"Press any key to continue......";
        getch();
        cout<<endl;
      }
      


      break;
    case 6:
      exit(0);
    default:
      cout<<endl<<"Invalid input"<<endl;
   }
  }while(1);
}

