#include<bits/stdc++.h>
using namespace std;
static int p=0;
class bus
{
    
   char bus_no[5],seat_no[8][4][10] ,driver_name[10],destination[10],starting_point[10],arrival[5],departure[5];
   public:
   void install();
   void allotment();
   void empty();
   void show();
   void avail();
   void position(int i);
}b1[10];
void vline(char ch)
{
  for(int i=150;i>0;i--)
  cout<<ch;
}
void bus::install()
{cout<<"Enter Bus Number:\n";
         cin>>b1[p].bus_no;
         cout<<"Enter Driver Name:\n";
         cin>>b1[p].driver_name;
         cout<<"Enter Destination:\n";
         cin>>b1[p].destination;
         cout<<"Enter Starting Point:\n";
         cin>>b1[p].starting_point;
         cout<<"Enter Arrival Time:\n";
         cin>>b1[p].arrival;
         cout<<"Enter Departure Time:\n";
         cin>>b1[p].departure;
         b1[p].empty();
         p++;
         }
         void bus::allotment()
         {int seat;
         char number[5];
         top:
         cout<<"Bus no:";
         cin>>number;
         int n;
         for(n=0;n<=p;n++)
         {
           if(strcmp(b1[n].bus_no,number)==0)
           break;
         }
         while(n<=p)
        {
          cout<<"\nSeat Number:";
          cin>>seat;
          if(seat>32)
          {
            cout<<"\n There are only 32 seats available in this bus.";
          }
          else
          {
            if(strcmp(b1[n].seat_no[seat/4][(seat%4)-1],"Empty")==0)
            {
              cout<<"Enter Passangers's Name: ";
              cin>>b1[n].seat_no[seat/4][(seat%4)-1];
              break;
            }
            else{
              cout<<"The seat no is already reserved.\n";
            }
          }
        }
        if(n>p)
        {
          cout<<"Enter correct bus no.\n";
          goto top;
        }
         }
         void bus::empty()
         {
           for(int i=0;i<8;i++)
           {
             for(int j=0;j<4;j++)
             {
               strcpy(b1[p].seat_no[i][j],"Empty");
             }
           }
         }
         void bus::show()
         {
           int n;
           char number[5];
           cout<<"Enter bus no:";
           cin>>number;
           for(n=0;n<=p;n++)
           {
             if(strcmp(b1[n].bus_no,number)==0)
             break;
           }
           while(n<=p)
           {
             vline('*');
             cout<<"Bus Number:\t"<<b1[n].bus_no<<"\nDriver Name:\t"<<b1[n].driver_name<<"\t\tArrival Time:\t"<<b1[n].arrival<<"\tDeparture Time:\t"<<b1[n].departure<<"\nFrom:\t\t"<<b1[n].starting_point<<"\t\tTo:\t"<<b1[n].destination<<"\n";
             vline('*');
             b1[0].position(n); 
             int a=1;
             for(int i=0;i<8;i++)
             {
               for(int j=0;j<4;j++)
             { a++;
               if(strcmp(b1[p].seat_no[i][j],"Empty")!=0)
             cout<<"\nThe Seat number "<<(a-1)<<" is reserved  for "<<b1[n].seat_no[i][j]<<".";
             }
        
           }
           break;
         }
         if(n>p)
         {
           cout<<"Enter correct bus number:";
         }
         }
         void bus::position(int l)
         {
           int s=0,p=0;
           for(int i=0;i<8;i++)
           {
             cout<<"\n";
             for(int j=0;j<4;j++)
             { s++;
               if(strcmp(b1[l].seat_no[i][j],"Empty")==0)
               {
                 cout.width(5);
                 cout.fill(' ');
                 cout<<s<<".";
                 cout.width(10);
                 cout.fill(' ');
                 cout<<b1[l].seat_no[i][j];
               }
             }}
             cout<<"\n\nThere are "<<p<<" seats empty in Bus number: "<<b1[l].bus_no;
         }
         void bus::avail()
         {
           for(int n=0;n<p;n++)
           {
             vline('*');
            cout<<"\n\tBus Number:\t"<<b1[n].bus_no<<"\n\tDriver Name:\t"<<b1[n].driver_name<<"\n\tArrival Time:\t"<<b1[n].arrival<<"\t\tDeparture Time:\t"<<b1[n].departure<<"\n\tFrom:\t\t"<<b1[n].starting_point<<"\t\tTo:\t"<<b1[n].destination<<"\n";
             vline('*');
             cout<<"\n";
             vline('_');

           }
         }
         int main()
         { system("color 70");
           system("cls");
            int n;
            while(1)
            {
              cout<<"\n\n\n\n\n1.Install\n2.Reservation\n3.Show\n4.Buses Available\n5.Exit\n";
              cin>>n;
              switch(n)
              {
                case 1:
                system("cls");
                system("color 79");
                b1[p].install();
                break;
                case 2:
                 system("cls");
                system("color 7B");
                b1[p].allotment();
                break;
                case 3: system("cls");
                system("color 7C");
                b1[p].show();
                break;
                case 4: system("cls");
                system("color 79");
                b1[p].avail();
                 break;
                 case 5:exit(0);
              }
            }return 0;
         }