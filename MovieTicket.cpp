#include<bits/stdc++.h>
using namespace std;
class MovieTicket {
    // int x;//User
    // int y;//Movie ID
    bool booked[101][101];
    int seats = 100;   
    public :
    MovieTicket() {
        memset(booked, false, sizeof(booked));//memory set
        //It is a function used to fill a block of memory with a value.
    }
    bool book(int x, int y) {
        if (seats == 0) {
            cout<<"No More Seats Available"<<endl;
            return false;
        }
        else if (booked[x][y]) {
            cout<<"Already Booked"<<endl;
            return false;
        }else {
            booked[x][y] = true;
            cout<<"Ticket Confirmed"<<endl;
            seats--;
            return true;
        }
    }

    bool Cancel(int x, int y) {
        if (!booked[x][y]) {
            cout<<"Ticket is Not Booked Book First"<<endl;
            return false;
        }else {
            booked[x][y] = false;
            cout<<"Ticket is Canceled"<<endl;
            seats++;
            return true;
        }
    }
    bool isBooked(int x, int y) {
        if (booked[x][y]) {
            cout<<"Yes Booked"<<endl;
            return true;
        }else {
            cout<<"Not Booked"<<endl;
            return false;
        }
    }
    int availableTickets() {
        return seats;
    }
};
int main() {
    MovieTicket m1;
    MovieTicket m2;
    MovieTicket m3;
    m1.book(1, 10);
    m1.book(2, 10);
    m1.book(3, 10);
    m1.book(5, 10);
    // m3.isBooked(2, 15);
    // m2.book(1, 10);
    // cout<<m2.availableTickets()<<endl;
    cout<<m1.availableTickets()<<endl;
    return 0;
}