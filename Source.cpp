#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include<array>
using namespace std;

static int p = 0;

class a

{

    char busn[10];
       string seat[10][10] ;
    string driver[10], arrival[5], depart[5], from[10], to[10];
    char pname[100][100];
    int rear = -1;
    int front = -1;
    int bil = 0;
    


public:

    void install();//insert
    void validation(string);
    void deleted();//deletion
    void update();//update

   
    void selectionSort();
    
    void Enqueue(char value);
    void Dequeue();
    bool Empty();
    char queueFront();
    char queueRear();
    void FirstHistory(); //QUERY implementation to see the first data entered
    void show();//search
    void seatbook();

    void avail();
    //sort




    

}

bus[10]; //object

void a:: selectionSort() 

{
    int i, j, min, temp;
    for (i = 0; i < 9; i++) 
    {
        min = i;
        for (j = i + 1; j < 10; j++)
            if (busn[i]> busn[j])
                min = j;
        temp = busn[i];
        busn[i] = busn[min];
        busn[min] = temp;
    }

   

    for (i = 0; i < 9; i++)
    {
        min = i;
        for (j = i + 1; j < 10; j++)
            if (busn[i] > busn[j])
                min = j;
        temp = busn[i];
        busn[i] = busn[min];
        busn[min] = temp;
    }

    for (i = 0; i < 10; i++)
        cout << busn[i] << " ";
}

void vline(char ch)

{

    for (int i = 80; i > 0; i--)

        cout << ch;

}


void a::Enqueue(char value)
{
    
    if (bil < 10)
    {

        rear++;
        if (rear == 10)
        {
            rear = 0;
        }
        if (bil == 0)

            front = 0;
        
       busn[rear] = value;
        bil++;
    }
    else
    {
        cout << "Underflow!!!";
    }
}
void a::Dequeue()
{
    if (bil == 0)
        cout << "Underflow";
    else
    {
        cout << "Dequeue:" << busn[front];
        front++;
        if (front == 10)
            front = 0;
        if (bil == 1)

            rear = front = -1;
        bil--;

    }
}

bool a::Empty()
{
    return (bil == 0);
}

char a::queueFront()
{
    if (Empty())
        return false;
    else
     return busn[front];
}

char a::queueRear()
{
    if (Empty())
        return false;
    else
        return busn[rear];
}


void a::FirstHistory()
{
    cout << "The first bus number  entered was  :";
   if (!Empty())
    {
        cout << queueFront() << endl;
        
    }
}




void a::update()
{
    char bus_upd;
    int upd_choice;
    for (int j = 0; j < 10; j++)
    {

        cout << "Enter the bus number to be updated: ";
        cin >> bus_upd;
        if (busn[j] == bus_upd)
        {

            cout << "1. Update bus number" << endl;
            cout << "2. Update arrival area" << endl;
            cout << "3. Update departure area" << endl;
            cout << "4. Update depart time" << endl;
            cin >> upd_choice;
            switch (upd_choice)
            {
            case 1:
                cout << "New Bus No: ";
                cin >> busn[j];
                
                break;



            case 2:
                cout << "New To: ";
                cin >> to[j];
                system("cls");
                break;


            case 3:
                cout << "New From: ";
                cin >> from[j];
                system("cls");
                break;


            case 4:
                cout << "New Departure Time: ";
                cin >> depart[j];
                system("cls");
                break;

            default:
                cout << "Enter a valid value";

            }

        }

        break;
    }
}
void a::deleted()
{

    char budel;
    cout << "Enter the number of bus to be deleted;";
    cin >> budel;
    for (int n = 0; n <= 10; n++)

    {

        if (busn[n] == budel)
        {
            cout << "Bus has been found" << endl;
            busn[n] = busn[n + 1];
        }




    }

    for (int n = 0; n <=9; n++)
    {
        cout << "The new list is :" << endl;
        cout << busn[n];

    }







}



void a::install()

{
    int add;
    cout << "Enter the numner of data to be added ";
    cin >> add;
    for (int i = 0; i < add; i++)
    {
        cout << "Enter bus no: ";

        cin >> busn[i];

        Enqueue(busn[i]);

        cout << "\nEnter Driver's name: ";

        cin >> driver[i];

        cout << "\nArrival time: ";

        cin >> arrival[i];

        cout << "\nDeparture: ";

        cin >> depart[i];

        cout << "\nFrom: \t\t\t";

        cin >> from[i];

        cout << "\nTo: \t\t\t";

        cin >> to[i];

        

    }
}
void a::validation(string l)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ( seat[i][j] == l)
            {
                cout << "sorry" << endl;
                cout << "Please choose abnother ";
                seatbook();
                      

                
            }
         
            
        }
        
    }
}
void a::seatbook()
{
    char  busc;
    
    bool occ = false;
    int seats = 0;
    string seat_num;
   
    cout << "enter the bus number  :";
    cin >> busc;
    cout << "enter the number of seat wanted :";
    cin >> seats;   
    cout << "enter the seat number :";
    cin >> seat_num;
    validation(seat_num);
    //ugug
    

    for (int i = 0; i < seats; i++)
    {
        for (int j = 0; j < seats; j++)
        {


            cout << "Verify enter the seat number :";
            cin >> seat[i][j+1];            
           
            

        }

    }

    


    
    
    

}



void a::show()

{

    int n;

    char number;

    cout << "Enter bus no: ";

    cin >> number;

    for (n = 0; n < 10; n++)

    {

       if (busn[n] == number)
        
       {
            cout << "Bus found ";

            cout << "\nBus no: \t" << busn[n] << endl;
            vline('*');



            cout << "\nDriver: \t" << driver[n] << "\t\tArrival time: \t"

                << arrival[n] << "\tDeparture time:" << depart[n]

                << "\nFrom: \t\t" << from[n] << "\t\tTo: \t\t" <<

                to[n] << "\n";

            vline('*');

            cout << "\nSeat are booked ";
            for (int j = 0; j < 10; j++)
            {
                cout << endl;
                
                cout << seat[n][j] << endl;
                
            }
            
        }
       

       

    }

   

}


void a::avail()

{
    
    char temp = 0;
    


       

        for (int n = 0; n < 10; n++)

        {


            vline('*');

            cout << "Bus no: \t" << busn[n] << "\nDriver: \t" << driver[n]

                << "\t\tArrival time: \t" << arrival[n] << "\tDeparture Time: \t"

                << depart[n] << "\nFrom: \t\t" << from[n] << "\t\tTo: \t\t\t"

                << to[n] << "\n";

            vline('*');

            vline('_');
        }
      
}

int main()

{

    system("cls");

    int w;

    while (1)

    {

        //system("cls");

        cout << "\n\n\n\n\n";

        cout << "\t\t\t1.Install\n\t\t\t"

            << "2.Show\n\t\t\t"

            << "3.Available \n\t\t\t"

            << "4.Delete. \n\t\t\t"
            << "5.Update \n\t\t\t"
            << "6.History\n\t\t\t"
            << "7.Sort\n\t\t\t"

            << "8.Book"
        << "9.Exit";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> w;

        switch (w)

        {

        case 1:  bus[p].install();

            break;

       

        case 2:  bus[p].show();

            break;

        case 3:  bus[p].avail();

            break;

        case 4:  bus[p].deleted();
            break;

        case 5:  bus[p].update();
            break;

        

        case 6:  bus[p].FirstHistory();
            break;

        case 7:  bus[p].selectionSort();
            break;
        
        case 8:  bus[p].seatbook();
            break;
            
        case 9:
            exit(1);
            break;

        }

    }

    return 0;

}