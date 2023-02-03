#include<iostream>
using namespace std;

#include <conio.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

class Bus_Manegment_System
{
    protected :
        string b_no,b_name,d_name;
		int b_seat;
    public:
        void Addbus();
	    void Reservation();
	    void Show();
	    void Available();
};
void Bus_Manegment_System::Addbus()
{	
    p:
    system("cls");
    fstream file;

    string t_no,td_name,tb_name;
	int t_seat;
	int found=0;
    cout<<"\n\t\t----------------Bus Menagment System---------------";
	cout<<"\n\nEnter Bus No :";
	cin>>b_no;
    cout<<"\n\nEnter Bus Name :";
    cin>>b_name;
    cout<<"\n\nTotal Seats :";
	cin>>b_seat;
    cout<<"\n\nEnter Driver Name: ";
	cin>>d_name;
    file.open("bus.txt",ios::in); 
    if(!file)  
    {  
        file.open("bus.txt",ios::app|ios::out);
        file<<b_no<<" "<<b_name<<"\t"<<b_seat<<" "<<d_name<<"\n";
        file.close();
    }
    else 
    {
        file>>t_no>>tb_name>>t_seat>>td_name;//take data from file 
        while(!file.eof())
        {
            if(b_no==t_no)
            {
                found++; //data are found
            }
            file>>t_no>>tb_name>>t_seat>>td_name;
        }
        file.close();
        if(found==0) //we have not data 
        {
            file.open("bus.txt",ios::app|ios::in);
            file<<b_no<<" "<<b_name<<"\t"<<b_seat<<" "<<d_name<<"\n";
            file.close();
        }
        else
        {
            cout<<"Duplicate Record Found.....";
            getch();
            goto p;
        } 
    }
    cout<<"\n\t\t\tBus Added Sucessfully ";
    cout<<"\n\n\t\t PRESSS ANY KEY TO CONTINUE ";
    getch();
}
void Bus_Manegment_System::Reservation()
{
    p:
    system("cls");
    fstream file;
    int found=0,s_no,seats,count=0,s_s_no,ss_no[15],i=0,s_amount,total_amount=0,day,month,year;
    char x,phone[10];
    string t_no,s_b_no,customer_name,from,to;
    cout<<"\n\t\t----------------Bus Menagment System---------------";
    file.open("bus.txt",ios::app|ios::in);
    if(!file)
    {
        cout<<"\n\n File opening error..........";
    }
    else
    {
        cout<<"\n\n Bus No : ";
        cin>>t_no;
        file.close();
        file.open("seat.txt",ios::app|ios::in);
        if(file)
        {
            file>>s_b_no>>s_s_no;//take data from file
            while (!file.eof())
            {   
                if(t_no == s_b_no)
                {
                    count++;
                }
                file>>s_b_no>>s_s_no;
            }
            file.close();
        }
        file.open("bus.txt",ios::in);
        file>>b_no>>b_name>>b_seat>>d_name;//take data from file while all data are come
        while(!file.eof())
        {
            if(t_no == b_no)
            {
                seats = b_seat; 
                found++;
            }
            file>>b_no>>b_name>>b_seat>>d_name;
        }
        file.close();
        if(seats-count==0)
        {
            cout<<"\n\n All seats is already reserved......";
        }
        else if(found==1)
        {
            do
            {
                h:
                cout<<"\n\n seat No. :";
                cin>>s_no;
                if(s_no>seats)
                {
                    cout<<"\n\n seat No. is invalid...please try again... ";
                    goto h;
                }
                file.open("seat.txt",ios::in);
                if(!file)
                {
                    file.open("seat.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
                    file.close();
                }
                else
                {
                    file>>s_b_no>>s_s_no;
                    while(!file.eof())
                    {
                        if(t_no == s_b_no && s_no == s_s_no)
                        {
                            cout<<"\n\n seat is already reserved...please try again.";
                            file.close();
                            goto h;
                        }
                        file>>s_b_no>>s_s_no;
                    }
                    file.close();
                    file.open("seat.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
                    file.close();
                }
                ss_no[i] = s_no;
                i++;
                cout<<"\n\n Booking another seat (Y / N) :";
                cin>>x;
            }while(x=='Y'|| x=='y');
            system("cls");
            cout<<"\n\t\t----------------Bus Menagment System---------------";
            cout<<"\n\n Customer Name : ";
            cin>>customer_name;
            cout<<"\n\n Phone number :";
            cin>>phone;
            cout<<"\n\n From :";
            cin>>from;
            cout<<"\n\nTo :";
            cin>>to;
            cout<<"\n\n single seat amount :";
            cin>>s_amount;
            cout<<"\n\nEnter dd/mm/yyyyy :";
            cin>>day>>month>>year;
            total_amount = s_amount*i;
            cout<<"\n\n Total amount :"<<total_amount;
            file.open("custmor.txt",ios::app|ios::in);
            file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
            file.close();
            system("cls");
           cout<<"\n\t\t----------------Bus Menagment System---------------";
            cout<<"\n\n\t\t*************************************************";
            cout<<"\n\n\t\t______________Booking information_________________";
            cout<<"\n\n\t\t*************************************************";
            cout<<"\n\t\tName :                         "<<customer_name;
            cout<<"\n\t\tDate :                         "<<day<<"/"<<month<<"/"<<year;
            cout<<"\n\t\tFrom :                         "<<from;
            cout<<"\n\t\tTo   :                         "<<to;
            cout<<"\n\t\tTotal seats :                  "<<i;
            cout<<"\n\t\treserved seats :               ";
            for(int a=0;a<i;a++)
            {
                if(a!=0)
                {
                    cout<<ss_no[a];
                    cout<<",";
                }
            }
            cout<<"\n\t\tSingle seat amount :           "<<s_amount;
            cout<<"\n\t\tTotal amoount      :           "<<total_amount;
            cout<<"\n\n\t\t*************************************************";
            cout<<"\n\t\t\t Thank You So Much for BOOking";
            cout<<"\n\n\t\t*************************************************";
			cout<<"\n\n\n\t\tPRESS ANY KEY TO CONTINUE"; 
			getch();          
        }
        else 
        {
            cout<<"\n\n bus NO. i sinvalid....please try again....";
            getch();
            goto p;
        }
    }
}

void Bus_Manegment_System::Show()
{
    system("cls");
	int found=0,count=0;
	string t_busn,seat_no,seat_busn; 
	fstream file,file1;
	cout<<"\n\t\t----------------Bus Menagment System---------------";
	file.open("bus.txt",ios::in);
	file1.open("seat.txt",ios::in);//for seat file
	if(!file || !file1)
	{
		cout<<"file does not exist ";
	}
	else
	{
		cout<<"\n\nEnter bus no :";
		cin>>t_busn;
		file1>>seat_busn>>seat_no;
		while(!file1.eof())
		{
			if(t_busn == seat_busn)
			{
				count++;
			}
			file1>>seat_busn>>seat_no;
		}
		file1.close();
		file>>b_no>>b_name>>b_seat>>d_name;
		while(!file.eof())
		{
			if(t_busn == b_no)
			{
				system("cls");
				cout<<"\n\t\t----------------Bus Menagment System---------------";
				cout<<"\n\n Total No. Of Seats :"<<b_seat;
				cout<<"\n\n Reserved No. Seats :"<<count;
				cout<<"\n\n Emty No. Of Seats :"<<b_seat-count;
				found++;
			}
			file>>b_no>>b_name>>b_seat>>d_name;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n Bus No. Is Invalid ";
		}
	}

}

void Bus_Manegment_System::Available()
{
	system("cls");//clear screen
	fstream file;
    
	cout<<"\n\t\t----------------Bus Menagment System---------------";	//heading
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n file not open";
	}
	else
	{
		cout<<"\n\nBUS NO \tBUS NAME \tTOTAL SEATS \tDRIVER name ";
		file>>b_no>>b_name>>b_seat>>d_name;//take data on file
		while(!file.eof())
		{
			cout<<"\n "<<b_no<<"\t"<<b_name<<"\t"<<b_seat<<"\t"<<d_name;//cout data
			file>>b_no>>b_name>>b_seat>>d_name;;//pacha ander nakhvana
		}
		file.close();
	}
    cout<<"\n\nPRESS ANY KEY TO CONTINUE SERVICES";
    getch();

}
int main()
{
    Bus_Manegment_System Bus;
	system("cls");
	int choice;
	while(1)
	{
        //system("cls");
		cout<<"\n\n\n\n\n";
        cout<<"\n\n\t\t***************************************************";
		cout<<"\n\t\t----------------Bus Menagment System---------------";
        cout<<"\n\n\t\t***************************************************";
  		cout<<"\n\t\t\t1.Add Bus";
		cout<<"\n\t\t\t2.Bus Reservation";
		cout<<"\n\t\t\t3.Show";
		cout<<"\n\t\t\t4.Buses Available.";
		cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t***************************************************";
		cout<<"\n\t\t\tEnter your choice:-> ";
		cin>>choice;
		switch(choice)
		{
			case 1:  
				Bus.Addbus();
				break;
			case 2:
				Bus.Reservation();
				break;
			case 3:  
				Bus.Show();
				break;
			case 4:
			    Bus.Available();
				break;
			case 5:  
				exit(0);  
		}
	}
    return 0;
}
