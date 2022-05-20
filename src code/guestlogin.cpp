


//guestlogin.cpp
#include "guestlogin.h"
#include "guest_console.h"


 
void exitSys1() {
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
void guestlogin::guestsignup()
{
    system("CLS");

    const char* sql1;
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            double mob_num;
            string user_name, pwd;

            string first_name, last_name, mail, city;


            system("CLS");
            cout << setw(60) << "**********************************************" << endl;
            cout << setw(60) << "*             GUEST Sign-Up SCREEN           *" << endl;
            cout << setw(60) << "**********************************************" << endl;
            cout << endl;



            cout << "Enter your First Name          :"; cin >> first_name;
            cout << "Enter your Last Name           :"; cin >> last_name;
            cout << "Enter your Mobile Number       :"; cin >> mob_num;
            cout << "Enter your Email-Id            :"; cin >> mail;
            cout << "Enter your City                :"; cin >> city;

            cout << endl << endl;

            cout << setw(10) << "**********************************************" << endl;
            cout << setw(10) << "*           Guest LOGIN-IN Credentials:      *" << endl;
            cout << setw(10) << "**********************************************" << endl;
            cout << endl;

            cout << "Please Enter your User-Name    :";cin >> user_name;
            cout << "Please Enter your Password     :";cin >> pwd;




            std::string sql = "insert into guest_info  values(""'" + (first_name)+"'" + "," + "'" + (last_name)+"'" + ", \
            " + std::to_string(mob_num) + "," + "'" + (mail)+"'" + ", " + "'" + (city)+"'" + ")";


            std::string sql1 = "insert into login_credentials values(""'" + (user_name)+"'" + ", " + "'" + (pwd)+"'" + ",'Guest')";
            std::string sql2 = "update guest_info  set guest_user_name = (""'" + (user_name)+"'" + ") \
            where mobile_number = ( " + std::to_string(mob_num) + ")";

            work W(C);
            W.exec(sql);
            W.exec(sql1);
            W.exec(sql2);
            W.commit();
            cout << endl << endl;

            cout << "Guest Sign-Up created successfully" << endl;
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
    }
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t\t***********************************************" << endl;
    cout << "\t\t\t\t\t\t*                                             *" << endl;
    cout << "\t\t\t\t\t\t*        You have successfully Signed-Up      *" << endl;
    cout << "\t\t\t\t\t\t*       Thank you for Choosing our Hotel!!    *" << endl;
    cout << "\t\t\t\t\t\t*                                             *" << endl;
    cout << "\t\t\t\t\t\t***********************************************" << endl;

    (void)_getch();
    guest_login();


}
void guestlogin::guestsignin()
{
    const char* sql1;
    guest_console guest;
    string userName;
    string password, get_password;
    try
    {
    connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
    int test = 0;
    bool check = false;
    system("CLS");

    do {
        system("cls");

        cout << endl;

        cout << "\t\t\t\t\t\t   ********************************************" << endl;
        cout << "\t\t\t\t\t\t   *             GUEST SIGN-IN SCREEN         *" << endl;
        cout << "\t\t\t\t\t\t   ********************************************" << endl;

        cout << endl;
        cout << endl << endl << endl << endl;

        cout << "\t\t\t\t\t\t   Username     : ";
        cin >> userName;
        cout << "\t\t\t\t\t\t   Password     : ";
        cin >> password;
        cin.ignore();
        std::string sql = "select Password from login_credentials where User_name = (""'" + (userName)+"'" + ")";
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
            system("cls");

            //DISPLAY

            std::string sql = "select first_name from guest_info where guest_user_name = (""'" + (userName)+"'" + ")";
            work W(C);
            result R(W.exec(sql));
            result::const_iterator  c = R.begin();
            cout << endl << endl;
            cout << setw(10) << "  ***************************" << endl;
            cout << setw(10) << "       Welcome " << c[0].as<string>()<<"!!"<< endl;
            cout << setw(10) << "  ***************************" << endl;
            cout << endl;
                       
            std::string sql1 = "select first_name,Last_name,mobile_number,email_id,city from guest_info where guest_user_name = (""'" + (userName) + "'"+")";
            cout<<"  Guest Details :" << endl<<endl;

            result R1(W.exec(sql1));
            for (result::const_iterator b = R1.begin(); b != R1.end(); ++b) {
                cout << "\t          " << b[0].as<string>() <<"."<< b[1].as<string>() << "\t "<<setw(10) << b[2].as<long long int>() << endl;
                cout<< "\t          " << b[4].as<string>() << "\t " << b[3].as<string>() << endl << endl;
                 }

            //Booking Expiry Notification
            std::string sql2 = "select guest_user_name from guest_info where guest_user_name = (""'" + (userName)+"'" + ")";
            result R2(W.exec(sql2));
            result::const_iterator  a = R2.begin();

            std::string sql3 = " select guest_user_name from guest_info where reservation_status = 'Cancelled'";
            result R3 = (W.exec(sql3));
            for (int i = 0;i < R3.size();i++)
            {
                if (R3[i][0] == a[0])
                {
            
                    cout << endl;
                    cout << "\t\t\t\t\t\t   ************************************************************" << endl;
                    cout << "\t\t\t\t\t\t   *                       Notification:                      *" << endl;
                    cout << "\t\t\t\t\t\t   *     Sorry !!  Your Booking of Room has been Expired!!    *"<<  endl;
                    cout << "\t\t\t\t\t\t   *                                                          *" << endl;
                    cout << "\t\t\t\t\t\t   ************************************************************" << endl;
                    cout << endl;
                   std::string sql4 = "update guest_info set reservation_status='No' where guest_user_name = (""'" + (userName)+"'" + ")";
                   W.exec(sql4);

                }
            }
  

            W.commit();
            cout << endl;

            (void)_getch();
            guest.guest_menu();
            check = true;
           }

        else {
            system("cls");
            test++;
            cout << endl << endl << endl << endl << endl << endl;
            cout << "\t\t\t\t\t\tYou are only allowed to try 3 times. You just have " << (3 - test) << " times left!" << endl;
            cout << "\t\t\t\t\t\tPress any key to continue!" << endl<<endl;
            (void)getchar();
            if (test == 3) {
                cout << "\t\t You have entered the wrong username or password 3 times and you are not allowed to login to the system!" << endl;
                (void)_getch();
                exitSys1();
            }
        }
    } while (!check);

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
        _getch();
    }

}