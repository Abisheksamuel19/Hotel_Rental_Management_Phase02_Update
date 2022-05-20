
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include <thread>
#include <pqxx/pqxx> 

#include "hotel.h"
#include "search1.h"
#include "guest_info.h"
#include "guestlogin.h"
#include "guest_console.h"  

//main.cpp
//hotel_rentel_management_system

using namespace std;
using namespace pqxx;


void delay(unsigned int mseconds) {
    // Storing start time 
    clock_t startTime = clock();
    // looping till required time is not acheived 
    while (clock() < (startTime + mseconds));
}

void title()
{
    cout << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t**************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                *" << endl;
    cout << "\t\t\t\t\t\t*                                                *" << endl;
    cout << "\t\t\t\t\t\t*                    WELCOME TO                  *" << endl;
    cout << "\t\t\t\t\t\t*           HOTEL RENTAL MANAGEMENT SYSTEM       *" << endl;
    cout << "\t\t\t\t\t\t*                                                *" << endl;
    cout << "\t\t\t\t\t\t*                                                *" << endl;
    cout << "\t\t\t\t\t\t**************************************************" << endl;
   
}

void exitSys() {
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t*********************************************" << endl;
    cout << "\t\t\t\t\t\t*                                           *" << endl;
    cout << "\t\t\t\t\t\t*        You have exited the system!        *" << endl;
    cout << "\t\t\t\t\t\t*                 Thank You!                *" << endl;
    cout << "\t\t\t\t\t\t*        For Using Choosing Our Hotel!      *" << endl;
    cout << "\t\t\t\t\t\t*                                           *" << endl;
    cout << "\t\t\t\t\t\t*********************************************" << endl;
    cout << "\t\t\t\t\t\t   Press enter to exit the program!" << endl;



    (void)_getch();
    exit(0);
}
int menu()
{
    system("cls");

    hotel rooms;
    guest_info guest;
    int opt;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Manage Hotel Rooms                   *" << endl;
    cout << "\t\t\t\t\t\t*         2. Manage Guest                         *" << endl;
    cout << "\t\t\t\t\t\t*         3. Report                               *" << endl;
    cout << "\t\t\t\t\t\t*         4. Exit                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> opt;
    cin.ignore();
    switch (opt) {
    case 1: {
        system("cls");
        rooms.showInfoMenu();
    }
          break;


    case 2: {
        system("cls");
        guest.showguestInfoMenu();
    }
          break;
    case 3: {
        system("cls");
        guest.report();
    }
          break;

          break;

    case 4: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t*********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                           *" << endl;
        cout << "\t\t\t\t\t\t*        You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*                 Thank You!                *" << endl;
        cout << "\t\t\t\t\t\t*        For Using Choosing Our Hotel!      *" << endl;
        cout << "\t\t\t\t\t\t*                                           *" << endl;
        cout << "\t\t\t\t\t\t*********************************************" << endl;
        cout << endl << endl << endl;
        exit(0);
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        menu();
    }

           return 0;


    }

}

void loginScreen() {


    string userName;
    string password, get_password;
    connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
    int test = 0;
    bool check = false;
    system("CLS");

    do {
        system("cls");
        title();
        cout << endl;

        cout << "\t\t\t\t\t\t   ********************************************" << endl;
        cout << "\t\t\t\t\t\t   *          RECEPTIONIST LOGIN SCREEN       *" << endl;
        cout << "\t\t\t\t\t\t   ********************************************" << endl;

        cout << endl;
        cout << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Username: ";
        cin >> userName;
        cout << "\t\t\t\t\t\t   Password: ";
        cin >> password;
        cin.ignore();
        std::string sql = "select Password from Login_credentials where User_name = (""'" + (userName)+"'" + ")";
        work W(C);

        result R(W.exec(sql));
        for (result::const_iterator c = R.begin(); c != R.end(); ++c) {

            get_password = c[0].as<string>();
        }
        W.commit();
        if (get_password == password)
        {
            cout << endl << endl << endl;
            cout << "\t\t\t\t\t\t   Login successfully!" << endl;
            cout << "\t\t\t\t\t\t   Press any key to continue!";
            (void)_getch();


            menu();
            check = true;

        }

        else {
            system("cls");
            test++;
            cout << endl << endl << endl << endl << endl << endl;
            cout << "\t\t\t\t\t\tYou are only allowed to try 3 times. You just have " << (3 - test) << " times left!" << endl;
            cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
            (void)getchar();
            if (test == 3) {
                cout << "\t\t\tYou have entered the wrong username or password 3 times and you are not allowed to login to the system!" << endl;
                (void)getchar();
                exitSys();

            }
        }
    } while (!check);



}

void loginmenu()
{
    system("cls");
    guestlogin guest;
    int opt;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Receptionist Login                   *" << endl;
    cout << "\t\t\t\t\t\t*         2. Guest Login                          *" << endl;
    cout << "\t\t\t\t\t\t*         3. Exit                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> opt;
    cin.ignore();
    switch (opt) {
    case 1: {
        system("cls");
        loginScreen();
    }
          break;

    case 2: {
        system("cls");
        guest.guest_login();
    }
          break;

    case 3: {

        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t*********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                           *" << endl;
        cout << "\t\t\t\t\t\t*        You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*                 Thank You!                *" << endl;
        cout << "\t\t\t\t\t\t*        For Using Choosing Our Hotel!      *" << endl;
        cout << "\t\t\t\t\t\t*                                           *" << endl;
        cout << "\t\t\t\t\t\t*********************************************" << endl;
        cout << endl << endl << endl;
        exit(0);
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        menu();
    }




    }

}

int hotel::showInfoMenu() {
    system("cls");

    int option;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Add Room informations                *" << endl;
    cout << "\t\t\t\t\t\t*         2. Modify Room informations             *" << endl;
    cout << "\t\t\t\t\t\t*         3. Delete Room informations             *" << endl;
    cout << "\t\t\t\t\t\t*         4. Search Room informations             *" << endl;
    cout << "\t\t\t\t\t\t*         5. Main Menu                            *" << endl;
    cout << "\t\t\t\t\t\t*         6. Exit                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> option;
    cin.ignore();
    switch (option) {
    case 1: {
        system("cls");
        addrooms();
    }
          break;

    case 2: {
        system("cls");
        updaterooms();
    }
          break;

    case 3: {
        system("cls");
        deleterooms();
    }
          break;

    case 4: {
        system("cls");
        selectrooms();
    }
          break;
    case 5: {
        system("cls");
        menu();
    }
          break;

    case 6: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t*          You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*       Thank you for Choosing our Hotel!!    *" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        exit(0);
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        showInfoMenu();
    }
    }

}
int search1::room_search()
{
    guest_console guest;
    system("cls");

    int opt1;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t******************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                    *" << endl;
    cout << "\t\t\t\t\t\t*       1. Search Vacant Rooms                       *" << endl;
    cout << "\t\t\t\t\t\t*       2. Search Rooms By Room Type & Floor number  *" << endl;
    cout << "\t\t\t\t\t\t*       3. Main Menu                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                    *" << endl;
    cout << "\t\t\t\t\t\t******************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> opt1;
    cin.ignore();
    switch (opt1) {
    case 1: {
        system("cls");
        vacancy();
    }
          break;
    case 2: {
        system("cls");
        type_floor();
    }
          break;

    case 3: {
        system("cls");
        guest.guest_menu();
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        menu();
    }
           return 0;

    }

}
int guest_info::showguestInfoMenu()
{
    system("cls");

    int option;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Add Guest Information                *" << endl;
    cout << "\t\t\t\t\t\t*         2. Update Guest Information             *" << endl;
    cout << "\t\t\t\t\t\t*         3. Book Room                            *" << endl;
    cout << "\t\t\t\t\t\t*         4. Cancel Booked Room                   *" << endl;
    cout << "\t\t\t\t\t\t*         5. Guest Reserve/Check-In               *" << endl;
    cout << "\t\t\t\t\t\t*         6. Guest Check Out                      *" << endl;
    cout << "\t\t\t\t\t\t*         7. Guest Membership Termination         *" << endl;
    cout << "\t\t\t\t\t\t*         8. Search Information                   *" << endl;
    cout << "\t\t\t\t\t\t*         9. Report                               *" << endl;
    cout << "\t\t\t\t\t\t*        10. Main Menu                            *" << endl;
    cout << "\t\t\t\t\t\t*        11. Exit                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> option;
    cin.ignore();
    switch (option) {
    case 1: {
        system("cls");
        addguest();
    }
          break;

    case 2: {
        system("cls");
        updateguest_info();
    }
          break;

    case 3: {
        system("cls");
        bookroom();
    }
          break;
    case 4: {
        system("cls");
        cancelbooking();
    }
          break;
    case 5: {
        system("cls");
        reserve_info();
    }
          break;
    case 6: {
        system("cls");
        check_out();
    }
          break;
    case 7: {
        system("cls");
        deleteguest();
    }
          break;


    case 8: {
        system("cls");
        search_info();

    }
          break;
    case 9: {
        system("cls");
        report();

    }
          break;
    case 10: {
        system("cls");
        menu();
    }
           break;

    case 11: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t*          You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*       Thank you for Choosing our Hotel!!    *" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        exit(0);
    }
           break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        showguestInfoMenu();
    }
    }

}
void guestlogin::guest_login()
{
    system("cls");

    int opt;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Guest Sign-Up                        *" << endl;
    cout << "\t\t\t\t\t\t*         2. Guest Sign-In                        *" << endl;
    cout << "\t\t\t\t\t\t*         3. Main Menu                            *" << endl;
    cout << "\t\t\t\t\t\t*         4. Exit                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> opt;
    cin.ignore();
    switch (opt) {
    case 1: {
        system("cls");
        guestsignup();
    }
          break;

    case 2: {
        system("cls");
        guestsignin();
    }
          break;

    case 3: {
        system("cls");
        loginmenu();
    }
          break;

    case 4: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t*********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                           *" << endl;
        cout << "\t\t\t\t\t\t*        You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*                 Thank You!                *" << endl;
        cout << "\t\t\t\t\t\t*        For Using Choosing Our Hotel!      *" << endl;
        cout << "\t\t\t\t\t\t*                                           *" << endl;
        cout << "\t\t\t\t\t\t*********************************************" << endl;
        cout << endl << endl << endl;
        exit(0);
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        menu();
    }




    }

}

void guest_console::guest_menu()
{
    guest_console guest;
    search1 room;

   

    int option;
    cout << endl << endl << endl ;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Update Guest informations            *" << endl;
    cout << "\t\t\t\t\t\t*         2. Search Rooms in Hotel                *" << endl;
    cout << "\t\t\t\t\t\t*         3. Book Room                            *" << endl;
    cout << "\t\t\t\t\t\t*         4. Cancel Booked Room                   *" << endl;
    cout << "\t\t\t\t\t\t*         5. Reserve/Check-In                     *" << endl;
    cout << "\t\t\t\t\t\t*         6. Check-Out                            *" << endl;
    cout << "\t\t\t\t\t\t*         7. History                              *" << endl;
    cout << "\t\t\t\t\t\t*         8. Sign-out                             *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> option;
    cin.ignore();
    switch (option) {
    case 1: {
        system("cls");
        guest.updateguestinfo();
    }
          break;
    case 2: {
        system("cls");
        room.room_search();
    }
          break;


    case 3: {
        system("cls");
        guest.bookroom();
    }
          break;

    case 4: {
        system("cls");
        guest.cancelbooking();

    }
          break;

    case 5: {
        system("cls");
        guest.reserve();
    }
          break;
    case 6: {
        system("cls");
        guest.check_out();
    }
          break;
    case 7: {
        system("cls");
        room.guest_history();
    }
          break;


    case 8: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t Signing-Out..";
        for (int process = 0; process < 36; process++) {
            delay(50);
            cout << ".";
        }
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t*          You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*       Thank you for Choosing our Hotel!!    *" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        exit(0);
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        loginmenu();
    }

    }
}


void guest_info::report()
{
    system("cls");
    int option;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t*         1. Vacant Rooms                         *" << endl;
    cout << "\t\t\t\t\t\t*         2. Occupied Rooms                       *" << endl;
    cout << "\t\t\t\t\t\t*         3. Room Allotment History               *" << endl;
    cout << "\t\t\t\t\t\t*         4. Main Menu                            *" << endl;
    cout << "\t\t\t\t\t\t*         5. Exit                                 *" << endl;
    cout << "\t\t\t\t\t\t*                                                 *" << endl;
    cout << "\t\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> option;
    cin.ignore();
    switch (option)
    {
    case 1: {
        system("cls");
        vacancy();
        break;
    }

    case 2: {
        system("cls");
        occupied();
        break;
    }
    case 3: {
        system("cls");
        history();
    }
          break;

    case 4: {
        system("cls");
        menu();
    }
          break;

    case 5: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t*          You have exited the system!        *" << endl;
        cout << "\t\t\t\t\t\t*       Thank you for Choosing our Hotel!!    *" << endl;
        cout << "\t\t\t\t\t\t*                                             *" << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        exit(0);
    }
          break;

    default: {
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
        cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
        (void)getchar();
        showguestInfoMenu();
    }

    }


}

int main_screen()
{


    system("CLS");
    title();
    cout << endl << "\t\t\t\t\t\t\tPress any Key to continue!" << endl << endl;
    (void)_getch();
    cout << "\t\t\t\t\t\tLoading";
    for (int process = 0; process < 36; process++) {
        delay(50);
        cout << ".";
    }






    loginmenu();



    return 0;
}


int auto_check()
{
    system("CLS");
    const char* sql, * sql1,*sql2;
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {

            std::string sql = "update hotel_rooms_info as hi set occupied_status = 'No' where Room_number in( \
                select room_alloted_number from guest_info as g where g.check_in_date + g.no_days < current_date )";

            std::string sql1 = "update guest_info as g1 set reservation_status = 'No' where mobile_number in( \
                select mobile_number from guest_info as g where g.check_in_date + g.no_days < current_date  )";

            std::string sql2 = "update guest_info as gi set check_out_date = check_in_date + gi.no_days where mobile_number in (\
                    select mobile_number from guest_info as g where g.check_in_date + g.no_days < current_date )";

            std::string sql3="update guest_history as gt set check_out_date = check_in_date + gt.no_of_days where mobile_number in(\
                select mobile_number from guest_info as g where g.check_in_date + g.no_days < current_date )";

            work W(C);
            W.exec(sql);
            W.exec(sql1);
            W.exec(sql2);
            W.exec(sql3);
            W.commit();
         
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
        (void)_getch();
        return 0;
    }
 
}
int booking_expiry()
{  


    system("CLS");
    
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {


            std::string sql = "update guest_info as gi set reservation_status = 'Cancelled' where mobile_number in( \
                select mobile_number from booking_info as g where g.booking_date + 1 < current_date)";

            std::string sql1 = "update booking_info as gi set booking_status = 'Cancelled' where mobile_number in(  \
                    select mobile_number from booking_info as g where g.booking_date + 1 < current_date)";
                        
            std::string sql2 = "update hotel_rooms_info as hi set occupied_status = 'No' where Room_number in(  \
                    select room_allotment from booking_info as g where g.booking_date + 1 < current_date)";


            work W(C);
            W.exec(sql);
            W.exec(sql1);
            W.exec(sql2);
       
            W.commit();


        }
        else
        {
            cout << "Can't open database" << endl;

        }
        }
        catch (const std::exception& e) {
            cerr << e.what() << std::endl;
            (void)_getch();
            return 0;
        }
      

}
int main()
{

    system("Color B1");
    booking_expiry();
    std::thread first (auto_check); 
    main_screen();
    first.join();
   

    return 0;
}

