#include <iostream>
#include<cstring>
#include<fstream>
using namespace std;


 void ClearScreen()
    {
    int ik;
    for (ik = 0; ik < 10; ik++)
      cout<<"\n\n\n\n\n\n\n\n\n\n";
    }

class consumer
{
    protected:

    int a[100];
    int p,q,r;
    int i;

    public:

    void accept()
    {
        int yp;
        yp=1;
        cout<<"\n ENTER THE NUMBER OF PRODUCTS TO BE MAINTAINED :: ";
        cin>>p;
        for(i=0;i<p;i++)
        {
            cout<<"\n ENTER THE COMPONENT QUANTITY OF THE ELEMENT "<<yp<<" :: ";
            cin>>a[i];
            yp++;
        }
    }
    void dispence()
    {
        cout<<"\n ENTER THE PRODUCT NUMBER TO BE DISPENCED::";
        cin>>q;

        cout<<"\n ENTER THE PRODUCT QUANTITY TO BE DISPENCED::";
        cin>>r;
        q--;


        if((a[q]-r)>0)
        {
            cout<<"\n VALID ORDER.....YOUR ORDER HAS BEEN ACCEPTED";
        }
        else
        {
            cout<<"\n WE DON'T HAVE THIS PRODUCT IN THIS BIG QUANTITY";
        }
    }

};
class warehouse :public consumer
{
    public:
     void currentavailability()
    {
        int k=1;
        for(i=0;i<p;i++)
        {
        cout<<"\n PRODUCT "<<k<<" :: QUANTITY :: "<<a[i];
        k++;
        }
    }
    void orderdefficient()
    {
        int r;
        cout<<"\n VALUE FOR WHICH YOU CONSIDER AS PRODUCT IS DEFFICIENT IN QUANTITY ::";
        cin>>r;
        for(i=0;i<p;i++)
        {
            if(a[i]<r)
            {
                int n;
                n=i;
                n++;
                cout<<" \n PRODUCT "<<n<<" IS DEFICIENT WITH QUANTITY ::"<<a[i];
            }
        }
    }
    void additionofproducts()
    {
        int o,j,l;
        cout<<"\n ENTER THE NUMBER OF PRODUCTS ENTERED THE WAREHOUSE :: ";
        cin>>o;
        for(i=0;i<o;i++)
        {
            cout<<"\n EXISTING PRODUCT NUMBER WHICH IS TO BE ADDED ::";
            cin>>j;
            j--;
            cout<<"\n ENTER THE QUANTITY TO BE ADDED ::";
            cin>>l;
            a[j]=a[j]+l;
        }
    }
    void costcalcu()
    {
        int c1,cost,totalcost;
        totalcost=0;
        for(i=0;i<p;i++)
        {
            cout<<"\n THE COMPONENT QUANTITY OF THE ELEMENT :: "<<a[i];
            cout<<"ENTER THE COST OF ::";
            cin>>c1;
            cost=c1*a[i];
            cout<<"\n COST OF THE COMPONENT :: "<<cost;
            totalcost=totalcost+cost;

        }
        cout<<"TOTAL COST OF COMPONENTS IN WAREHOUSE :: "<<totalcost;
    }

};

int main()
{
	string username;
   int pass,po;
   char ch1,ch2;
   pass=9999;
   fstream user;
user.open("User.txt",ios::trunc);
   do
{
   cout<<"\n WELCOME TO SYSTEM WAREHOUSE";
   cout<<"\n USERNAME=";
   cin>>username;
   if(user){
	   user.open("User.txt", ios::out | ios::app );
	   user<<username<<endl;
	   user.close();
   }
   else{
	   user<<"a";
	   user.open("User.txt",ios::trunc | ios::out  );
	   user<<username;
	   user.close();
   }cout<<"\n MAY WE KNOW WHO YOU ARE \n 1 FOR ADMINISTRATOR \n 2 CONFIRMATION DEPARTMENT ";
   cin>>ch1;


   if(ch1=='1')
   {



   cout<<" ENTER ADMINISTRATOR PASSCODE::";
   cin>>po;
   if(po==pass)
   {

       ClearScreen();
       cout<<"\n PASSCODE ACCEPTED \n \t\t\t  WELCOME USER ";
       warehouse user;
       user.accept();
       int p;
       char ch;
       do
       {


       cout<<"ENTER \n 1::CURRENT STOCK \n 2::DEFFICIENT \n 3::ENTRY OF NEW PRODUCT \n 4::COST CALCULATION  \n ENTER YOUR CHOICE:::: ";
       int jk;
       cin>>jk;

       switch (jk)
       {


           case 1: user.currentavailability();
                    break;


           case 2: user.orderdefficient();
                    break;


           case 3: user.additionofproducts();
                    break;


           case 4: user.costcalcu();
                    break;


       }

       cout<<"\n WANT TO PERFORM ONE MORE OPERATION 'Y' FOR YES ::";
       cin>>ch;


       }while(ch=='Y');


   }
   else
   {
       cout<<"\nPASSCODE IS INCORRECT ACCESS DENIED";
   }


   }


   else
   {
       consumer cos1;
       cos1.dispence();
   }
   cout<<"\n WANT TO PERFORM ANOTHER LOGIN OPERATION 'Y' FOR YES ::";
   cin>>ch2;

}while(ch2=='Y');
   return 0;

}
