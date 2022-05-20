
#include "guest_info.h"

#define max1 3
string strings1[max1];
//guest_info.cpp

/* FOR RECEPTIONIST */

int len1(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;

    }
    return length;
}
void split1(string str, char seperator1)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len1(str))
    {
        if (str[i] == seperator1 || i == len1(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings1[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

void guest_info::addguest()
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
            do
            {
                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*             ADD GUEST INFORMATION          *" << endl;
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

                std::string sql1 = "insert into guest_login  values(""'" + (user_name)+"'" + ", " + "'" + (pwd)+"'" + ")";

                work W(C);
                W.exec(sql);
                W.exec(sql1);
                W.commit();
                cout << endl;
                cout << " Do you want to you continue to add Guest Information ... press (y/n)";
                cin >> c1;

            } while (c1 == 'y');

            cout << "Guest records created successfully" << endl;
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
    }

    showguestInfoMenu();

}
void guest_info::updateguest_info()
{
    system("CLS");
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            do
            {
                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*      UPDATION OF GUEST INFORMATION SCREEN  *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl;

                string u_choice, u_col;
                double mob_num;
                cout << "Enter the Mobile number:"; cin >> mob_num;
                cout << endl;

                cout << "Enter the Field that need to be updated" << endl;;

                cout << "\t=> First_name   " << endl;
                cout << "\t=> Last_name " << endl;
                cout << "\t=> Email_id " << endl;
                cout << "\t=> City " << endl;



                cout << "Enter your choice of field : ";cin >> u_col;

                if (u_col == "First_name" || u_col == "Last_name" || u_col == "Email_id" || u_col == "City"||u_col == "first_name" || u_col == "last_name" || u_col == "email_id" || u_col == "city")
                {


                    cout << "Enter the updatation: ";cin >> u_choice;

                    std::string sql = "update guest_info set " + (u_col)+" = " + "'" + (u_choice)+"'" + "  where mobile_number = (" + std::to_string(mob_num) + ")";

                    work W(C);

                    W.exec(sql);
                    W.commit();
                    cout << "Do you want to you continue to update ?... press [y/n]";
                    cin >> c1;
                }
                else
                {
                    cout << endl;
                    cout << "Entered Field is incorrect\n";
                    cout << "Please re-Enter your choice correctly:";
                    (void)_getch();
                    showguestInfoMenu();

                }
            } while (c1 == 'y');

            cout << "Room's Records Updated successfully" << endl;
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    showguestInfoMenu();
}

void guest_info::deleteguest()
{
    system("CLS");

    try {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open()) {
            do
            {
                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*        REMOVING GUEST MEMBERSHIP SCREEN    *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl;


                double mob_num;
                cout << "Enter the Guest Mobile number  :"; cin >> mob_num;


                std::string sql = "delete from guest_info where mobile_number = (" + std::to_string(mob_num) + ")";


                work W(C);

                W.exec(sql);
                W.commit();
                cout << endl;
                cout << "Do you want to delete Guest Membership  again?... press (y/n)";
                cin >> c1;

            } while (c1 == 'y');
            cout << endl;
            cout << "Guest Membership Records Deleted Successfully" << endl;
            (void)_getch();
        }
        else {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }

    showguestInfoMenu();
}
void guest_info::bookroom()
{
    char c1;
    int t = 1;
    const char* sql1;
    const char* sql2;
    system("CLS");
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            do
            {
                if (t < 3)
                {
                    system("CLS");
                    cout << setw(60) << "**********************************************" << endl;
                    cout << setw(60) << "*              ROOM BOOKING SCREEN           *" << endl;
                    cout << setw(60) << "**********************************************" << endl;
                    cout << endl;
                    int room_num, no_person;
                    double mob_num;
                    string book_da;


                    cout << endl;
                    cout << "Enter the Mobile number          :"; cin >> mob_num;

                    cout << "Enter the Room number            :"; cin >> room_num;

             

                    std::string sql = "select occupied_status from hotel_rooms_info  where room_number = (" + std::to_string(room_num) + ")";
                    work W(C);
                    result R(W.exec(sql));
                    result::const_iterator  c = R.begin();


                    if (c[0].as<string>() == "Yes" || c[0].as<string>() == "Booked")
                    {
                        cout << endl << "The Room has been already Reserved " << endl;
                        cout << "Please Try again... " << endl;
                        (void)_getch();
                        bookroom();
                    }

                    cout << "Enter Number of Person for accomodation   :"; cin >> no_person;
                    cout << "Enter the Booking Date  [yyyy-mm-dd]      :"; cin >> book_da;

                    std::string sql1 = "insert into booking_info values(" + std::to_string(mob_num) + "," + std::to_string(room_num) + "," + std::to_string(no_person) + "," + "'" + (book_da)+"'" + " ,'Booked')";

                    std::string sql2 = "update hotel_rooms_info set occupied_status = 'Booked'\
                                      where room_number = (" + std::to_string(room_num) + ")";

                    std::string sql4 = "update guest_info set reservation_status = 'Booked' \
                    where mobile_number = (" + std::to_string(mob_num) + ")";



                    W.exec(sql1);
                    W.exec(sql2);
                    W.exec(sql4);
                    W.commit();
                    cout << "Do you want to you continue to Book ?... press [y/n]";
                    cin >> c1;
                    t++;
                }
                else
                {
                    cout << endl << endl;
                    cout << "Booking can be done for 2 Rooms per Guest" << endl;
                    (void)_getch();
                    showguestInfoMenu();

                }
            } while (c1 == 'y');

            cout << "Room Booked successfully" << endl;
            cout << endl << endl;
            cout << "Note: Bookin of a Room will be\n"; 
            cout<<        "Expired in 24-hours Unless You Didn't Reserve It" << endl;

            (void)_getch();
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    showguestInfoMenu();
}
void guest_info::cancelbooking()
{

    char c1;
    int t = 1;

    const char* sql1;
    system("CLS");
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*              CANCEL BOOKING SCREEN         *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl;
                int room_num;
                double mob_num;


                cout << endl;
                cout << "Enter the Mobile number          :"; cin >> mob_num;
                cout << "Enter the Room number            :"; cin >> room_num;





                std::string sql = "delete from booking_info where mobile_Number = (" + std::to_string(mob_num) + ") and  room_allotment=(" + std::to_string(room_num) + ")";

                std::string sql1 = "update hotel_rooms_info set occupied_status = 'No'\
                            where room_number = (" + std::to_string(room_num) + ")";


                work W(C);

                W.exec(sql);
                W.exec(sql1);
                W.commit();
                if (t < 2)
                {
                    cout << endl;
                    cout << "Do you want to you cancel Booked Room again ?... press [y/n]";
                    cin >> c1;
                }
                else
                {

                    cout << endl;
                    cout << "Booked Room Cancelation done successfully" << endl;

                    (void)_getch();
                    showguestInfoMenu();


                }

                t++;
            } while (c1 == 'y');

            cout << "Booked Room Cancelation done successfully" << endl;
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    showguestInfoMenu();
}

void guest_info::reserve_info()
{
    system("CLS");

    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            double mob_num;
            int room_all, stay;
            string check_in;
            do
            {
                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*              RESERVATION OF ROOM           *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl;

                cout << "Enter Your Mobile Number for Reservation :"; cin >> mob_num;
                cout << "Enter the Room Number for accommodation  :"; cin >> room_all;

                std::string sql = "select occupied_status from hotel_rooms_info  where room_number = (" + std::to_string(room_all) + ")";
                work W(C);
                result R(W.exec(sql));
                result::const_iterator  c = R.begin();


                if (c[0].as<string>() == "Yes")
                {
                    cout << endl << "The Room has been already Reserved " << endl;
                    cout << "Please Try again... " << endl;
                    (void)_getch();
                    showguestInfoMenu();
                }
                else
                {

                    cout << "Enter the Check-IN Date  [yyyy-mm-dd]      :"; cin >> check_in;
                    cout << "Enter How many days of Stay                :"; cin >> stay;

                    std::string sql1 = "update guest_info set check_in_date =(" "'" + (check_in)+"'" + ") \
                    where mobile_number =(" + std::to_string(mob_num) + ")";
                    std::string sql2 = "update guest_info set no_days =(" + std::to_string(stay) + ") \
                    where mobile_number =(" + std::to_string(mob_num) + ")";

                    std::string sql3 = "update guest_info set room_alloted_number =(" + std::to_string(room_all) + ") \
                    where mobile_number =(" + std::to_string(mob_num) + ")";

                    std::string sql4 = "update guest_info set reservation_status ='Reserved' \
                    where mobile_number =(" + std::to_string(mob_num) + ")";

                    std::string sql5 = "update hotel_rooms_info set occupied_status = 'Yes'\
                    where room_number = (" + std::to_string(room_all) + ")";

                    std::string sql6 = "insert into guest_history values(" + std::to_string(mob_num) + "," + std::to_string(room_all) + ", \
                    " + "'" + (check_in)+"'" + ",NULL," + std::to_string(stay) + " )";

                    W.exec(sql1);
                    W.exec(sql2);
                    W.exec(sql3);
                    W.exec(sql4);
                    W.exec(sql5);
                    W.exec(sql6);

                    W.commit();

                    cout << endl;
                    cout << " Do you want to you continue to Reserve again... press (y/n)";
                    cin >> c1;
                }
            } while (c1 == 'y');

            cout << "Room Reserved successfully" << endl;
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
    }

    showguestInfoMenu();
}
void guest_info::check_out()
{
    const char* sql1,*sql2;
    system("CLS");
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            double mob_num, room_all;
            string  check_out;


            do
            {
                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*            GUEST Check-Out SCREEN          *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl;
                cout << "Enter the Mobile Number for Checking-out  :"; cin >> mob_num;

                std::string sql = "select  mobile_number from guest_info where mobile_number  = (" + std::to_string(mob_num) + ")\
                                          and check_in_date is NULL ";
                work W(C);
                result R(W.exec(sql));
                result::const_iterator  c = R.begin();

               
                if (c[0].as<double>() == mob_num)
                {
                    cout << endl << "Please Resrve a room to Check-out " << endl;
                    cout << "...Please Try again..." << endl;
                    (void)_getch();
                    showguestInfoMenu();

                }

                cout << "Enter the Alloted Room Number :"; cin >> room_all;
                cout << "Enter the Check-OUT Date [yyyy-mm-dd]     :"; cin >> check_out;

                std::string sql1 = "update guest_info set check_out_date =(" "'" + (check_out)+"'" + ") \
                    where mobile_number =(" + std::to_string(mob_num) + ")";

                std::string sql2 = "update hotel_rooms_info  set occupied_status = 'No'\
                where room_number = (" + std::to_string(room_all) + ")";

               
                W.exec(sql1);
                W.exec(sql2);
                W.commit();
                cout << endl;
                cout << " Do you want to Check-out from another room again ... press (y/n)";
                cin >> c1;

            } while (c1 == 'y');
            cout << endl;
            cout << "Guest Checked out successfully" << endl;
            (void)_getch();
        }
        else
        {
            cout << "Can't open database" << endl;

        }

    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
    }

    showguestInfoMenu();
}

void guest_info::search_info()
{

    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {


            system("CLS");
            cout << setw(60) << "**********************************************" << endl;
            cout << setw(60) << "*             SEARCH Guest Info              *" << endl;
            cout << setw(60) << "*                                            *" << endl;
            cout << setw(60) << "**********************************************" << endl;
            cout << endl << endl;

            int  t = 1;
            string  str;


            cout << "Enter the text for search(Guest Name & RoomType & City)    :";
            getline(cin, str);
            char seperator1 = ' ';
            split1(str, seperator1);


            std::string sql = "SELECT  a.room_number, b.first_name, a.room_type, a.floor_number, b.mobile_number,\
                     b.city, a.room_rent from hotel_rooms_info as a, guest_info as b \
             WHERE   (  (  (b.first_name iLIKE (""'%" + (strings1[0]) + "%'"")) or (a.room_type iLIKE (""'%" + (strings1[0]) + "%'""))  or  (b.city iLIKE (""'%" + (strings1[0]) + "%'"") ) )  \
                        and (  (b.first_name iLIKE (""'%" + (strings1[1]) + "%'"")) or (a.room_type iLIKE (""'%" + (strings1[1]) + "%'""))   or  (b.city iLIKE (""'%" + (strings1[1]) + "%'"")) )    \
                         and ((b.first_name iLIKE(""'%" + (strings1[2]) + "%'"")) or (a.room_type iLIKE(""'%" + (strings1[2]) + "%'""))    or (b.city iLIKE(""'%" + (strings1[2]) + "%'""))  )  and a.room_number = b.room_alloted_number     )  ";



            work W(C);
            cout << endl << endl;
            cout << "Guest Information:" << endl << endl;


            cout << "===================================================================================================================================================" << endl;
            cout << "|S.No      |  ROOM_NUMBER  |     NAME     |         ROOM_TYPE        | FLOOR_NUMBER|    MOBILE_NUMBER     |         CITY           |   ROOM_RENT  |" << endl;
            cout << "===================================================================================================================================================" << endl;
            result R(W.exec(sql));
            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << c[1].as<string>() << "\t  |\t" << setw(10) << c[2].as<string>() << setw(8) << "\t     |" << " \t" << c[3].as<string>() << "\t   |\t" << c[4].as<long long int>() << "\t  |\t" << setw(10) << c[5].as<string>() << "\t   |\t" << c[6].as<int>() << "\t  |\t" << endl;
                t++;
            }

            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            W.commit();

            cout << endl << endl;
            (void)_getch();


        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    showguestInfoMenu();

}

int guest_info::vacancy()
{
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            int t = 1;


            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*             SEARCHING VACANT ROOMS         *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;



                std::string sql = " select Room_Number,room_type,Floor_Number,Room_rent from hotel_rooms_info where occupied_status = 'No'";
                work W(C);
                cout << endl << endl;



                cout << "=====================================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |       ROOM_TYPE      |     FLOOR_NUMBER |   ROOM_RENT  |" << endl;
                cout << "=====================================================================================" << endl;
                result R(W.exec(sql));
                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << setw(10) << c[1].as<string>() << "\t  |\t" << c[2].as<string>() << "\t     |" << " \t" << c[3].as<int>() << "\t    |" << endl;
                    t++;
                }
                cout << "-------------------------------------------------------------------------------------" << endl;

                W.commit();
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;

    }
    report();
    return 0;
}
int guest_info::occupied()
{
    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            int t = 1;


            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*                 OCCUPIED ROOMS             *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;


                std::string sql = "select a.room_number, b.first_name, a.room_type, a.floor_number, b.mobile_number,\
                     b.city, b.check_in_date, a.room_rent from hotel_rooms_info as a, guest_info as b\
                where a.occupied_status = 'Yes' and a.room_number = b.room_alloted_number";

                work W(C);
                cout << endl << endl;



                cout << "=============================================================================================================================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |     NAME     |         ROOM_TYPE        | FLOOR_NUMBER|    MOBILE_NUMBER     |         CITY          |    Check_IN Date      |   ROOM_RENT     |" << endl;
                cout << "=============================================================================================================================================================================" << endl;
                result R(W.exec(sql));
                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << c[1].as<string>() << "\t  |\t" << setw(10) << c[2].as<string>() << setw(8) << "\t     |" << " \t" << c[3].as<string>() << "\t   |\t" << c[4].as<long long int>() << "\t  |\t" << setw(10) << c[5].as<string>() << "\t   |\t" << c[6].as<string>() << "\t  |\t" << c[7].as<int>() << "\t    |" << endl;
                    t++;
                }

                cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

                W.commit();
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
        return 0;
    }
    report();

}
int guest_info::history()
{

    try
    {
        connection C("dbname = hotel_rentel_management_system user = postgres password = qwerty port = 5432");
        if (C.is_open())
        {
            int t = 1;
            do
            {

                system("CLS");
                cout << setw(60) << "**********************************************" << endl;
                cout << setw(60) << "*             ROOM ALLOTMENT HISTORY         *" << endl;
                cout << setw(60) << "**********************************************" << endl;
                cout << endl << endl;
                int room_num;
                cout << "Enter The Room Number To Search the Room History: "; cin >> room_num;

                std::string sql = "select a.room_number,a.room_type,a.floor_number,b.first_name,b.mobile_number,b.city,b.check_in_date,b.check_out_date,a.room_rent\
                    from hotel_rooms_info as a, guest_info as b\
                where a.room_number =(" + std::to_string(room_num) + ") and b.room_alloted_number = (" + std::to_string(room_num) + ")";

                work W(C);
                cout << endl << endl;



                cout << "======================================================================================================================================================================" << endl;
                cout << "|S.No      |  ROOM_NUMBER  |  ROOM_TYPE   |   FLOOR_NUMBER   |    NAME     |    MOBILE_NUMBER     |      CITY      | Check_IN Date|    Check_OUT Date    | ROOM_RENT |" << endl;
                cout << "======================================================================================================================================================================" << endl;
                result R(W.exec(sql));
                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    cout << "|" << t << "\t   |\t" << c[0].as<int>() << "\t   |\t" << c[1].as<string>() << "\t  |\t" << c[2].as<string>() << "\t     |" << " \t" << c[3].as<string>() << "\t   |\t" << c[4].as<long long int>() << "\t  |\t" << c[5].as<string>() << "\t   |   \t" << c[6].as<string>() << " | \t" << c[7].as<string>() << "\t | " << c[8].as<int>() << "\t     |" << endl;
                    t++;
                }
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

                W.commit();
                cout << "Do you want to you continue to Search again... press [y/n]";
                cin >> c1;
            } while (c1 == 'y');
        }
        else
        {
            cout << "Can't open database" << endl;

        }
    }
    catch (const std::exception& e) {
        cerr << e.what() << std::endl;
        return 0;
    }
    report();

}
