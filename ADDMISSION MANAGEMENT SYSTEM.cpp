#include <iostream>
#include <conio.h>
#include <fstream>
#include <synchapi.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Admin;
class Login;
class Discipline //ABSTRACT CLASS DECLARATION
{
    public:
        virtual string SelectDiscipline() = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ComputerScience: public Discipline //DERIVED CLASS DELARATION
{
    public:               // HERE MY MEMBER FUNCTIONS ARE PUBLIC
            string SelectDiscipline() {
                int field;
                cout << endl;
                cout << "--------------------------------------------------------------------------------"<< endl;
                cout << "------------------------( COMPUTER SCIENCE DISCIPLINE  )------------------------" << endl;
                cout << "--------------------------------------------------------------------------------"<< endl;
                cout << "\n\n\n";
                cout << "--------------------------------------------------------------------------------"<< endl;      
                cout << " AVAILABLE FIELDS:\n \n\t Computer Science & Information Technology --> Press 1 \n  \n\t Computational Finance --> Press 2 \n  \n\t Software Engineering --> Press 3\n  \n\t Computer and Information System --> Press 4"<<endl;
                cout << endl;
                cout << "--------------------------------------------------------------------------------"<< endl;
                cout << "\n\n";
                cout<<" Enter your choice: ";
                cin>>field;  
                switch(field){
                    case 1:
                        return "Computer Science & Information Technology";
                        break;
                    case 2: 
                        return "Computational Finance";
                        break;
                    case 3:
                        return "Software Engineering";
                        break;
                    case 4:
                        return "Computer and Information System";
                        break;
              }
        }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PreMedical: public Discipline //DERIVED CLASS DELARATION
{
    public:                // HERE MY MEMBER FUNCTIONS ARE PUBLIC
        string SelectDiscipline() {
            int field;
            cout << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "--------------------------( PRE-MEDICAL DISCIPLINE  )---------------------------" << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "\n\n\n";
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << " AVAILABLE FIELDS:\n \n\t Food Engineering --> Press 1 \n  \n\t Bio-Technology --> Press 2 \n  \n\t Bio-Chemistry --> Press 3"<<endl;
            cout << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "\n\n";
            cout<<" Enter your choice: ";
            cin>>field;
                switch(field){
                case 1:
                return "Food Engineering";
                break;
                case 2: 
                return "Bio-Technology";
                break;
                case 3:
                return "Bio-Chemistry";
                break;
              }            
       }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Commerce: public Discipline //DERIVED CLASS DELARATION
{
    public:                // HERE MY MEMBER FUNCTIONS ARE PUBLIC
        string SelectDiscipline() {
            int field;
            cout << endl;               
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "---------------------------( COMMERCE DISCIPLINE  )----------------------------" << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "\n\n\n";
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << " AVAILABLE FIELDS:\n \n\tEconomics and Finance --> Press 1 \n \n\tComputational Finance --> Press 2 \n \n\tDevelopment Science --> Press 3\n  \n\tEnglish liguitius --> Press 4"<<endl;
            cout << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "\n\n"; 
            cout<<" Enter your choice: ";
            cin>>field;
                switch(field){
                case 1:
                return "Economics and Finance";
                break;
                case 2: 
                return "Computational Finance";
                break;
                case 3:
                return "Development Science";
                break;
                case 4:
                return "English liguitius";
                break;
              }            
        }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PreEngineering: public Discipline //DERIVED CLASS DELARATION
{
    public:                // HERE MY MEMBER FUNCTIONS ARE PUBLIC
        string SelectDiscipline() {
            system("cls");
            int field;
            cout << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "-------------------------( PRE-ENGINEERING DISCIPLINE )-------------------------" << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "\n\n\n";
            cout << "--------------------------------------------------------------------------------"<< endl;       
            cout <<" AVAILABLE FIELDS:\n\n \tComputer Science & Information Technology --> Press 1 \n\n\tComputational Finance --> Press 2  \n\n\tComputer System Engineering --> Press 3\n\n\tElectrical Engineering --> Press 4\n\n\tMechanical Engineering --> Press 5\n \n\tCivil Engineering --> Press 6"<<endl;     
            cout << endl;
            cout << "--------------------------------------------------------------------------------"<< endl;
            cout << "\n\n";
            cout<<" Enter your choice: ";
            cin>>field;
            switch(field){
                case 1:
                return "Computer Science & Information Technology";
                break;
                case 2: 
                return "Computational Finance";
                break;
                case 3:
                return "Computer System Engineering";
                break;
                case 4:
                return "Electrical Engineering ";
                break;
                case 5:
                return "Mechanical Engineering ";
                break;
                case 6:
                return "Civil Engineering";
                break;
            }            
        }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Student{
    public:
        string StudentName,UserId;
        int marks,merit_no;
        string roll_no,enrollment_no,password,selected_feild;
        char group;
        Discipline* d;
    public:
        Student (){}
        Student(Student &obj){
            obj.enrollment_no=enrollment_no;
            obj.roll_no=roll_no;
            obj.password=password;
            obj.StudentName=StudentName;
            obj.UserId=UserId;
            obj.merit_no=merit_no;
            obj.marks=marks;
            obj.group=group;
            obj.selected_feild=selected_feild;
        }
        void SelectFeild(){
            system("cls");
            cout<<endl;
            cout<<"-------------------------------( FIELD SELECTION )------------------------------"<<"\n\n\n"<<endl;
            if(marks>50){
                string new_file_name=StudentName+".txt";
                ifstream f1;
                f1.open(new_file_name);
                if(f1){
                    cout<<"You have Already Selected Feild :) ";
                }
                else{
                    string field;
                    switch(group){
                        case 'c':
                            {ComputerScience cs1;
                            d=&cs1;
                            field=d->SelectDiscipline();}
                            break;           
                        case 'm':
                            {PreMedical md1;
                            d=&md1;
                            field=d->SelectDiscipline();}
                            break;
                        case 'r':
                            {Commerce cm1;
                            d=&cm1;
                            field=d->SelectDiscipline();}
                            break;
                        case 'e':
                            {PreEngineering pe1;
                            d=&pe1;
                            field=d->SelectDiscipline();}
                            break;                  
                        default:
                            cout<<"Invalid field";
                    }
                    cout<<"\n\n Congraulations you got addmission in NED University in "<<field;
                    ofstream f2(new_file_name);
                    f2<<"--------------------------------( STUDENT RECORD )--------------------------------"<<endl;
                    f2<<"Name                : "<<StudentName<<endl;
                    f2<<"UserId              : "<<UserId<<endl;
                    f2<<"Roll #              : "<<roll_no<<endl;
                    f2<<"Enrollment No.      : "<<enrollment_no<<endl;
                    f2<<"Entry Test Score    : "<<marks<<endl;
                    f2<<"Merit No.            : "<<merit_no<<endl;
                    f2<<"Discilpine          : "<<field<<endl;
                    f2.close(); 
                }
            }
            else{cout<<"\n\n\n\n\n\n         SORRY YOUR MARKS ARE NOT ENOUGH FOR FEILD SELECTION ACCORDING TO UNIVERSITY CRITERIA ";}
        }
        void displayResult(){
            system("cls");
            cout<<endl;
            cout<<"-------------------------------( STUDENT RESULT )-------------------------------"<<"\n\n\n"<<endl;
            cout<<"\tName              : "<<StudentName<<endl<<endl;
            cout<<"\tEntry Test Score  : "<<marks<<endl<<endl;
            cout<<"\tMerit_no          : "<<merit_no<<endl<<endl;
            cout<<"\n\n\n";
        }
        void displayDetails(){
            system("cls");
            cout<<endl;
            cout<<"-------------------------------( STUDENT RECORD )-------------------------------"<<"\n\n\n"<<endl;
            cout<<"\tName                : "<<StudentName<<endl<<endl;
            cout<<"\tUser Id             : "<<UserId<<endl<<endl;
            cout<<"\tRoll No.            : "<<roll_no<<endl<<endl;
            cout<<"\tEnrollment No.      : "<<enrollment_no<<endl<<endl;
            cout<<"\tEntry Test Score    : "<<marks<<endl<<endl;
            cout<<"\tMerit No.           : "<<merit_no<<endl<<endl;
            cout<<"\n\n\n\n\n";
        }
        void DisplayStudentPortal(){ 
            system("cls");
            cout<<endl;
            cout<<"-------------------------------( STUDENT PORTAL )-------------------------------"<<"\n\n\n"<<endl;
            cout<<" ~ WELCOME "<<StudentName<<" ~\n\n\n\n";
            cout<<"\tPress <1> ---> Student Detail "<<endl<<endl;
            cout<<"\tPress <2> ---> Student Result "<<endl<<endl;
            cout<<"\tPress <3> ---> Feild Selection  "<<endl<<endl;
            int choice3;
            cout<<"Enter your choice: ";
            cin>>choice3;
            switch(choice3){
                case 1:
                    displayDetails();
                    cout<<"\n\n\nPress <ENTER> ---> Back ";
                    getch();
                    DisplayStudentPortal(); 
                    break;
                case 2:
                    displayResult();
                    cout<<"\n\n\nPress <ENTER> ---> Back ";
                    getch();
                    DisplayStudentPortal(); 
                    break;
                case 3:
                    SelectFeild();
                    cout<<"\n\n\nPress <ENTER> ---> Back ";
                    getch();    
                    DisplayStudentPortal(); 
                    break;
            }
        }   
};
Student array[48];
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class  Admin
{
public:
    string ad_id;
    string ad_name;
    string ad_pass;
    Student s2;
public:
    Admin(){}
    Admin(Admin &obj)
    {
    ad_id=obj.ad_id;
    ad_name=obj.ad_name;
    ad_pass=obj.ad_pass;
    }
    void ad_details(){
        system("cls");
        cout<<endl;
        cout<<"--------------------------------( ADMIN DETAILS )-------------------------------"<<"\n\n\n"<<endl;
        cout <<"\tName                : "<< ad_name<< endl<<endl;
        cout <<"\tID                  : "<< ad_id<< endl<<endl;
        cout <<"\tPassword            : "<< ad_pass << endl<<endl;
    }
    void st_details()
    {
        system("cls");
        int enroll;
        cout << "\nEnter Enrollment Number: "; cin >> enroll; 
        s2= array[enroll];
        s2.displayDetails();
    }
    void merit_list(){
        system("cls");
        int len =48;
        int arr[48];
        string student[48];
        for (int h=0;h<48;++h){ 
            int i=array[h].marks;
            arr[h]=i;
            student[h]=array[h].StudentName;
        }   
        for (int i = 0;i<len ; i++){
            for (int j = i+1; j < len ; j++){
                if (arr[i]< arr[j]){
                    // marks setting
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    //student setting
                    string a=student[i];
                    student[i]=student[j];
                    student[j]=a;
                }
            }   
        }   
        for(int a=0;a<47;a++){
            for(int b=0;b<47;b++){
                if(student[a]==array[b].StudentName){
                    array[b].merit_no=a+1;
                }
            }
        }
        cout<<endl;
        cout<<"----------------------------( STUDENT MERIT LIST )------------------------------"<<"\n\n\n"<<endl;
        cout<<"----------------------------------------------------"<<endl<<endl;
        cout<<" MERIT"<<" || "<<"STUDENT NAME" <<setw(35-13)<<"||  "<<"SCORE"<<" ||"<<endl<<endl;
        cout<<"----------------------------------------------------"<<endl;
        for (int y=0;y<9;y++){
            string a = student[y];
            int setting=a.length();
            cout<<" 0"<<y+1<<"    || "<<student[y] <<setw(35-setting)<<"||   "<<arr[y]<<"   ||"<<endl<<endl;
        }
        for (int y=9;y<47;y++){
            string a = student[y];
            int setting=a.length();
            cout<<" "<<y+1<<"    || "<<student[y] <<setw(35-setting)<<"||   "<<arr[y]<<"   ||"<<endl<<endl;
        }
    }
    void view_fields(){
        system("cls");
        cout<<endl;
        cout<<  "*********************************** FIELDS *************************************"<<"\n\n\n"<<endl;
        cout << "--------------------------------------------------------------------------------" << endl ;
        cout << "------------------------( COMPUTER SCIENCE DISCIPLINE  )------------------------" << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\tComputer Systems Engineering" << endl<<endl;
        cout << "\tComputer Science & IT" << endl<<endl;
        cout << "\tSoftware Engineering\n\n\n" << endl;
        cout << "--------------------------------------------------------------------------------" << endl ;
        cout << "--------------------------( PRE-MEDICAL DISCIPLINE  )---------------------------" << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\tBiomedical Engineering" << endl<<endl;
        cout << "\tBio Technology" << endl<<endl;
        cout << "\tFood Sciences \n\n\n"<< endl;
        cout << "--------------------------------------------------------------------------------" << endl ;
        cout << "----------------------------( COMMERCE DISCIPLINE  )----------------------------" << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\tComputational Finance" << endl<<endl;
        cout << "\tEconomics \n\n\n" << endl;
        cout << "--------------------------------------------------------------------------------" << endl ;
        cout << "-------------------------( PRE-ENGINEERING DISCIPLINE )-------------------------" << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\tCivil Engineering" << endl<<endl;
        cout << "\tElectrical Engineering " << endl<<endl;
        cout << "\tMechanical Engineering " << endl<<endl;
        cout << "\tIndustrial Engineering " << endl<<endl;
        cout << "\tTextile Engineering " << endl<<endl;
        cout << "\tMetallurgy Engineering " << endl<<endl;
        cout << "\tSoftware Engineering  \n\n\n" << endl;
    }
    void DisplayAdminPortal(){
        system("cls");
        cout<<"\n--------------------------------( ADMIN PORTAL )--------------------------------"<<"\n\n\n"<<endl;
        cout << "<\tPress <1> --->  Admin Details: " << endl<<endl;
        cout << "<\tPress <2> --->  Student Details: "<< endl<<endl;
        cout << "<\tPress <3> --->  Merit List: " << endl<<endl;
        cout << "<\tPress <4> --->  Fields: " << endl<<endl;
        cout << "\n\nEnter choice : ";
        int choice5;
        cin >> choice5;
        switch(choice5){
        case 1:
            ad_details();
            cout<<"\n\n\nPress <ENTER> ---> Back ";
            getch();
            DisplayAdminPortal();   
            break;
        case 2:
            st_details();
            cout<<"\n\n\nPress <ENTER> ---> Back ";
            getch();
            DisplayAdminPortal();           
            break;
        case 3:
            merit_list();
            cout<<"\n\n\nPress <ENTER> ---> Back ";
            getch();
            DisplayAdminPortal();         
            break;
        case 4:
            view_fields();
            cout<<"\n\n\nPress <ENTER> ---> Back ";
            getch();
            DisplayAdminPortal(); 
            break;
        default:
            cout <<"\nPlease select the right choice...";
            }
        }
}; 
Admin admin_list[3];
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Login{
    public:
        string id;
        string password;
        Student s1;
        Admin a1; 
    public:

        void StudentLogin(){
            int en_no;
            cout<<"\n"<<endl;
            cout<<"-------------------------------( STUDENT LOGIN )--------------------------------"<<"\n\n\n"<<endl;
            cout<<"\nEnter Enrollment: ";
            cin>>en_no;
            s1=array[en_no];
            cout<<"\nEnter Userid: ";
            cin>>id;
            cout<<"\nEnter Password: ";
            cin>>password;
            bool verify=(s1.UserId==id);
            if(verify){
                if(s1.password==password){
                    s1.DisplayStudentPortal();  
                    }
                    else{cout<<"\nInvalid password";}
                    
                }else{cout<<"\nInvalid UserId";}
            }
        void AdminLogin(){
            cout<<"\n"<<endl;
            cout<<"--------------------------------( ADMIN LOGIN )--------------------------------"<<"\n\n\n"<<endl;
            cout<<"\nEnter Userid: ";
            cin>>id;
            cout<<"\nEnter Password: ";
            cin>>password;
            for(int i=0;i<3;++i){
                if (id == admin_list[i].ad_id){
                    a1=admin_list[i];
                    if (password == admin_list[i].ad_pass){
                        a1.DisplayAdminPortal();
                        break;
                    }
                }
            }
        }
        void DisplayLogin(){
            system("cls");
            int choice2;
            cout<<"\n"<<endl;
            cout<<"--------------------------------( LOGIN PORTAL )--------------------------------"<<"\n\n\n"<<endl;
            cout<<"\tPress <1> ---> Student Portal"<<endl<<endl;
            cout<<"\tPress <2> ---> Admin Portal"<<endl<<endl;
            cout<<"\n\nEnter your choice : ";
            cin>>choice2;
            switch(choice2){
                case 1:
                    system("cls");
                    StudentLogin();
                    break;
                case 2:
                    system("cls");
                    AdminLogin();
                    break;      
            }   
       }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class About{
    private:
        string about="  ABOUT:\n\n\tThe NED University of Engineering & Technology is a public university \n\tlocated in the urban area of Karachi, Sindh, Pakistan. It is one of \n\tthe oldest engineering universities in Pakistan.\n\n\tFounded as Prince of Wales Engineering College, it was renamed after \n\tParsi landowner Nadirshaw Edulji Dinshaw.\n\n\tIt is a recognized degree awarding university of Pakistan affiliated \n\twith the Higher Education Commission of Pakistan, a government-appointed\tbody.\n\n\tNED University of Engineering & Technology, was established in March \n\t1977 under an act of the Provincial Assembly of Sindh after upgrading \n\tof the former NED Government Engineering College, which was set up in \n\t1921. The NED University is thus one of the oldest institution in \n\tPakistan for teaching and producing Engineering graduates\n\n  OUR VISION:\n\n\t Be a leader in enabling Pakistan's social and economic transformation\n\n  OUR MISSION:\n\n\tAcquire education and research excellence in engineering and allied \n\tdisciplines to produce leadership and enabling application of knowledge\n\tand skillsfor the benefit of the society with integrity and wisdom";
    public:
    void Display(){
        system("cls");
        cout<<endl;
        cout<<"-----------------------------------( ABOUT )-----------------------------------"<<"\n\n\n"<<endl;
        cout<<about;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Guildlines{
    private:
        string Guild=" After Qualifying the Pre-Entry Admission Test:\n\n\t1. Merit lists of different categories will be displayed on NED Website \t   as per Admission Schedule.\n\n\t2. If you are called in the Merit List, follow the schedule and perform \t   the following activities.\n\n If Your Name Appears In The Merit Lists:\n\n\t3. Print the filled Application Form from the Admission Web Portal.\n\n\t4. Sign the Application Form. Also get your form duly signed by your \n\t   Parents / Guardianand Oath Commissioner\n\n\t5. Signed Admissionform, along with all documents mentioned in Document \t   Checklist, are to be submitted at the time of interview as mentioned \t   in the Admission Schedule on Admission Website.\n\n\t6. Candidate will be called for Pre-Admission Interview as per Admission \t   Schedule.\n";
    public:
    void Display(){
        system("cls");
        cout<<endl;
        cout<<"--------------------------------( GUIDLINES )-----------------------------------"<<"\n\n\n"<<endl;
        cout<<Guild;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Contact{
    private:
        string contact="\tAddress: \n\n\t\tNED University of Engineering & Technology University \n\t\tRoad Karachi- 75270, Pakistan\n\n\tTelephone : \n\n\t\t(92-21) 99261261-8\n\n\tFax : \n\n\t\t (92-21) 99261255 \n\n\tEmail :  \n\n\t\t registrar@neduet.edu.pk";
    public:
        void Display(){
            system("cls");
            cout<<endl;
            cout<<"--------------------------------( CONTACT )-----------------------------------"<<"\n\n\n"<<endl;
            cout<<contact;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Menu{
    public:
        About ab1;
        Guildlines gl1;
        Contact cont1;
        Login log1;
        public:
            void loading() //SIMPLE LOADING FUNCTION
    {
        cout << "\n\n\n\n\n\n\n\n"<< endl;
        cout << "\t\t\t\t LOADING....... ";
        cout << "\n"<<endl;
        char x = 219;
        cout << x;
        for (int i = 0; i < 40; i++)
        {
            cout << x << "/";
            if (i < 10)
                Sleep(100);
            if (i >= 10 && i <= 20)
                Sleep(50);
            if (i > 20)
                Sleep(25);
        }
        system("cls");
        cout << "\n\n"<< endl;
    }
        void displayMenu(){
        int choice1;
        system("cls");
        cout<<"\n"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"------------------------( ADDMISSION MANAGMENT SYSTEM )-------------------------"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<"\n\n\n"<<endl;
        loading();
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"------------------------------------( MENU )------------------------------------"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<"\n\n\n\n\n";
        cout<<"\tPress <1> ---> Login"<<"\n"<<endl;
        cout<<"\tPress <2> ---> Guildlines"<<"\n"<<endl;
        cout<<"\tPress <3> ---> About Us"<<"\n"<<endl;
        cout<<"\tPress <4> ---> Contact"<<"\n"<<endl;
        cout<<"\tPress <5> ---> Exit Application"<<"\n\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice1;
        switch(choice1){
            case 1:
                log1.DisplayLogin();
                break;
            case 2:
                gl1.Display(); 
                cout<<"\n\n\nPress <ENTER> ---> Back ";
                getch();
                displayMenu();                
                break;
            case 3:
                ab1.Display();               
                char k;
                cout<<"\n\n\nPress <ENTER> ---> Back ";
                getch();
                displayMenu();                
                break;
            case 4:
                cont1.Display(); 
                char c;
                cout<<"\n\n\nPress <ENTER> ---> Back ";
                getch();
                displayMenu();                
                break;
            case 5:
                exit(1);
        }           
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    system("color 4F"); //COMMAND FOR BACKGROUND AND FONT COLOR 
    //storing data------------------------------------------------------------------||
    short loop=0;                                                            		       // 
    string line;                                                         		                  //
    ifstream myfile ("studentname.txt");                                         	      // 
    if (myfile.is_open())                                                          		     //
    {                                                                          			     //
        while (! myfile.eof() )                                                 		    //
        {
            getline (myfile,line); 
            array[loop].StudentName = line;
            loop++;
        }
        myfile.close(); 
    }
    else{ cout << "can't open the file"; }

    short loop1=0; 
    string line1; 
    ifstream myfile1 ("userid.txt"); 
    if (myfile1.is_open()) 
    {
        while (! myfile1.eof() ) 
        {
            getline (myfile1,line1); 
            array[loop1].UserId = line1; 
            loop1++;
        }
        myfile1.close(); 
    }
    else {cout << "can't open the file"; }    
    short loop2=0; 
    string line2; 
    ifstream myfile2 ("rollno.txt"); 
    if (myfile2.is_open()) 
    {
        while (! myfile2.eof() ) 
        {
            getline (myfile2,line2); 
            array[loop2].roll_no = line2; 
            loop2++;
        }
        myfile2.close(); 
    }
    else {cout << "can't open the file"; }
    short loop3=0; 
    string line3; 
    ifstream myfile3 ("enroll_no.txt"); 
    if (myfile3.is_open()) 
    {
        while (! myfile3.eof() ) 
        {
            getline (myfile3,line3); 
            array[loop3].enrollment_no = line3; 
            loop3++;
        }
        myfile3.close(); 
    }
    else{ cout << "can't open the file"; }
    
    short loop4=0; 
    string line4; 
    ifstream myfile4 ("student_password.txt"); 
    if (myfile4.is_open()) 
    {
        while (! myfile4.eof() ) 
        {
            getline (myfile4,line4); 
            array[loop4].password = line4; 
            loop4++;
        }
        myfile4.close(); 
    }
    else{ cout << "can't open the file"; } 
    short loop5=0; 
    string line5; 
    ifstream myfile5 ("st_marks.txt"); 
    if (myfile5.is_open()) 
    {
        while (! myfile5.eof() ) 
        {
            getline (myfile5,line5); 
            array[loop5].marks = stoi(line5); 
            loop5++;
        }
        myfile5.close(); 
    }
    else{ cout << "can't open the file"; }
    
    
    short loop6=0; 
    string line6; 
    ifstream myfile6 ("st_group.txt"); 
    if (myfile6.is_open()) 
    {
        while (! myfile6.eof() ) 
        {
            getline (myfile6,line6); 
            array[loop6].group = char(line6[0]); 
            loop6++;
        }
        myfile6.close(); 
    }
    else{ cout << "can't open the file"; }
    short loop7=0; 
    string line7; 
    ifstream myfile7 ("ad_id.txt"); 
    if (myfile7.is_open()) 
    {
        while (! myfile7.eof() ) 
        {
            getline (myfile7,line7); 
            admin_list[loop7].ad_id = line7; 
            loop7++;
        }
        myfile7.close(); 
    }
    else{ cout << "can't open the file"; }
       
    short loop8=0; 
    string line8; 
    ifstream myfile8 ("ad_passwords.txt"); 
    if (myfile8.is_open()) 
    {
        while (! myfile8.eof() ) 
        {
            getline (myfile8,line8); 
            admin_list[loop8].ad_pass = line8; 
            loop8++;
        }
        myfile8.close(); 
    }
    else{ cout << "can't open the file"; }
    short loop9=0; 
    string line9; 
    ifstream myfile9 ("ad_name.txt"); 
    if (myfile9.is_open()) 
    {
        while (! myfile9.eof() ) 
        {
            getline (myfile9,line9); 
            admin_list[loop9].ad_name = line9; 
            loop9++;
        }
        myfile9.close(); 
    }
    else{ cout << "can't open the file"; }
    admin_list[1].merit_list();

    Menu m1;
    m1.displayMenu();

}

