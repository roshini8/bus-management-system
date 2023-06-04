#include<iostream>
#include"Bus.h"

a::a() //Constrcutor
{
    //initalizing values
    rear = -1;
    front = -1;
    bil = 0;
}
//function to format the output (not included in the class)
void vline(char ch) //takes argument as a char (* / @ / #)

{

    for (int i = 80; i > 0; i--)

        cout << ch;

}

void vline2(char ch) //takes argument as a char (* / @ / #)

{

    for (int i = 10; i > 0; i--)

        cout << ch;

}
//sorting based on selection sort 
void a::selectionSort()

{
    int temp; //temporary storage
    //sorting mechanism
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (busn[i] > busn[j + 1]) {
                temp = busn[i];
                busn[i] = busn[j + 1];
                busn[j + 1] = temp;
            }
        }
    }

    // Displaying output
    cout << "Elements sorted in the ascending order are: " << endl;
    for (int i = 1; i <= 10; i++) {
        if (busn[i] == 0)
        {
            cout << " " ;
        }
        else if (busn[i] != 0)
        {
            cout << busn[i] << " ";
        }
    }
}
//Stack application 
void a::Enqueue(int value)//argument value taken from user inout of bus number 
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
void a::Dequeue()//dequeue to delete or remove a valule from the queue
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

//checks whether the queue is empty
bool a::Empty()
{
    return (bil == 0);
}

//return the value in front of queue 
int a::queueFront() 
{
    if (Empty())
        return 0;
    else
        return busn[front];

}

//return the value at the back of queue
int a::queueRear()
{
    if (Empty())
        return 0;
    else
        return busn[rear];
}

//The final output of the Queue 
void a::FirstHistory()
{
    cout << "\t\t\tThe first bus number  entered was  :";
    if (!Empty())
    {
        cout << queueFront() << endl;

    }
}



//module to update the details of various option
void a::update()
{
    int bus_upd;
    int upd_choice;
    cout << "Enter the bus number to be updated: ";
    cin >> bus_upd;
    for (int j = 0; j < 10; j++)//conditional loop
    {


        if (busn[j] == bus_upd)
        {
        top:
            cout << "1. Update bus number" << endl;
            cout << "2. Update arrival area" << endl;
            cout << "3. Update departure area" << endl;
            cout << "4. Update depart time" << endl;
            cout << "Please enter your choice --> ";
            cin >> upd_choice;
            switch (upd_choice)
            {
            case 1:
                cout << "New Bus No: ";
                cin >> busn[j];
                cout << "Saved !";
                break;



            case 2:
                cout << "New To: ";
                cin >> to[j];
                cout << "Saved !";

                break;


            case 3:
                cout << "New From: ";
                cin >> from[j];
                cout << "Saved !";
                break;


            case 4:
                cout << "New Departure Time: ";
                cin >> depart[j];
                cout << "Saved !";
                break;

            default:
                cout << "Enter a valid value" << endl;
                goto top;

            }

        }


    }
}
void a::deleted()//deletion module to delete unwanted data from array
{
    int budel;
    cout << "Enter the number of bus to be deleted;";
    cin >> budel;
    for (int n = 0; n <= 10; n++)

    {
        if (busn[n] == budel)
        {
            cout << "Bus has been found" << endl;
            busn[n] = busn[n + 1];
            driver[n] = driver[n + 1];
            to[n] = to[n + 1];
            from[n] = from[n + 1];
            depart[n] = depart[n + 1];
            arrival[n] = arrival[n + 1];
            cout << "Succesfully deleted bus " << budel;

        }
    }

}
//module allows insertion of data (initialise the program)
void a::insert()

{
    int add;
    cout << "Enter the numner of data to be added ";
    cin >> add; //asking number of bus details to input
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
//validation module to check the seat number in a bus
void a::validation(int l , int m ) // two arguments are taken to continue loop
{   
        for (int j = 0; j < 10; j++)
        {
            if (seat[l][j] == m)
            {
                cout << "Sorry" << endl;
                cout << "Please choose another seat ";
                seatbook();
            }
        }    
        cout << "Seat is available" << endl;
}
//search module to search up the bus upon given number 
void a::show()
{
    int n;
    int  number;
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
            cout << "\nBooked seats are :"; 
            for (int k = 0; k < 10; k++)
            {
                if (seat[number][k] == 0)
                {
                    cout << "Empty" << endl;
                }                
                else if(seat[number][k] != 0)
                {
                    cout << endl << seat[number][k] << endl;
                    
                }
            }          

            
        }

    }
}

//module to list down the available buses
void a::avail()
{
    int display;
    cout << "Enter number of buses to be displayed ";
    cin >> display;
    for (int n = 0; n < display; n++)
    {     
            cout << "\tBUS NUMBER\t:" << busn[n] << endl;
            cout << "\tDRIVER NAME\t:" << driver[n] << endl;
            cout << "\tDEPART FROM\t:" << from[n] << endl;
            cout << "\tARIIVAL TO\t:" << to[n] << endl;
            cout << "\tDEPART TIME\t:" << depart[n] << endl;
            cout << "\tETA TIME\t:" << arrival[n] << endl;
            cout << endl << endl << endl;        
    }

}
//reservation module
void a::seatbook()
{
    int busc;
    int seats ;
    int seat_num;
    cout << "enter the bus number  :";
    cin >> busc;
    for (int i = 0; i < 10; i++)
    {
        if (busc == busn[i])
        {
            cout << "enter the number of seats :";
            cin >> seats;
            cout << "Check prefered seat number :";
            cin >> seat_num;
            validation(busc, seat_num);    //goes through validation to check the number

            //booking mechaism 
            for (int j = 0; j < seats; j++)
            {
                cout << "Verify the seat number #" << j + 1 << ":";
                cin >> seat[busc][j];
                cout << "\nSuccessfully booked " << endl;

            }

        }

    }   

}

//function to display the main menu 
void a::menu()

{
  system("cls");

    int w;

    while (1)

    {

        
        cout << "\n\t\tCREATED BY" << "\n<HERISH> ### <ROSHINI> ### <KAMAL> ### <RASHMIKA>\n";
        
        vline2('#');
        cout << " ZEUS BUS MANAGEMENT SYSTEM ";
        vline2('#');

        cout << "\n1.Install\n"

            << "2.Show\n"

            << "3.Available \n"

            << "4.Delete. \n"
            << "5.Update \n"
            << "6.History\n"
            << "7.Sort\n"

            << "8.Book" 
            << "\n9.Exit";

        cout << "\nEnter your choice:-> ";

        cin >> w;

        switch (w)//switch statements to run through options w 

        {

        case 1:  insert();

            break;



        case 2:  show();

            break;

        case 3:  avail();

            break;

        case 4:  deleted();
            break;

        case 5:  update();
            break;



        case 6:  FirstHistory();
            break;

        case 7:  selectionSort();
            break;

        case 8:  seatbook();
            break;

        case 9:
            exit(1);
            break;
        default:
            cout << "Please enter correct option!!!" << endl << endl;
            system("PAUSE");
            menu();
            
            
        }

    }



}

int main()
{
    a bus; //object declaration
    bus.menu(); //valling of function menu
    return 0; 
}