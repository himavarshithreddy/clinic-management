#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <windows.h>

// Open in Full Screen
// Password is pass
using namespace std;
int b();
void viewmed();
void bookapp();
void viewapp();
// Patient class
class patient {
public:
    string id, name, address, mobnum, age, sex, bloodgrp, dis, sym, diag, med, revt, patid, diaid;
    int found;
    // Show patient details function
    void showpat() {

        system("cls");
        cout << "\n\n\t\t\tEnter Patient ID: ";
        int i = 0;
        cin >> patid;
        cout << "\n---------------------------------------\n";
        fstream fpat;
        fstream fdiag;
        fpat.open("patdet.csv");
        while (fpat.good()) {
            getline(fpat, id, ',');
            getline(fpat, name, ',');
            getline(fpat, address, ',');
            getline(fpat, mobnum, ',');
            getline(fpat, age, ',');
            getline(fpat, sex, ',');
            getline(fpat, bloodgrp, ',');
            getline(fpat, dis, '\n');
            if (patid.compare(id) == 0)
            {
                i = 1;
                break;

            }
        }
        system("cls");
        if (i == 1) {
            cout << "\n\n\t\t\t\t\t\t\t Patient Details - ID: " << patid;
            cout << "\n\n\n\n\t\tPatient Name: " << name;
            cout << "\n\n\t\tPatient Address: " << address;
            cout << "\n\n\t\tPatient Mobile Number: " << mobnum;
            cout << "\n\n\t\tPatient Age: " << age;
            cout << "\n\n\t\tPatient Sex: " << sex;
            cout << "\n\n\t\tPatient Blood Group: " << bloodgrp;
            cout << "\n\n\t\tPrevious Major Diseases: " << dis;
            fdiag.open("patdiag.csv");
            while (fdiag.good()) {
                getline(fdiag, diaid, ',');
                getline(fdiag, sym, ',');
                getline(fdiag, diag, ',');
                getline(fdiag, med, ',');
                getline(fdiag, revt, '\n');
                if (patid.compare(diaid) == 0)
                {
                    cout << "\n\n\t\tSymptoms: " << sym;
                    cout << "\n\n\t\tDiagnosis: " << diag;
                    cout << "\n\n\t\tMedicines: " << med;
                    cout << "\n\n\t\tRevisit After: " << revt;
                    break;


                }

            }

            found = 1;
        }
        else {
            cout << "\n\n\n\n\t\tPatient Details Not Found";
            found = 0;

        }


    }
    //Add patient function
    void addpat() {

        system("cls");
        cout << "\n\n\t\t\t\t\t\t\tAdding new Patient Details";
        cout << "\n\n\t\tEnter Patient ID : ";
        cin >> id;
        string newid;
        int flag = 0;
        fstream fpat;
        fpat.open("patdet.csv");
        while (fpat.good()) {
            getline(fpat, newid, ',');
            getline(fpat, name, ',');
            getline(fpat, address, ',');
            getline(fpat, mobnum, ',');
            getline(fpat, age, ',');
            getline(fpat, sex, ',');
            getline(fpat, bloodgrp, ',');
            getline(fpat, dis, '\n');
            if (newid.compare(id) == 0)
            {
                flag = 1;
                break;
            }

        }
        if (flag == 1)
        {
            cout << "\n\t\tAlready Patinet Exists with Same ID , Try again with New ID\n";
            cout << "\nPress Enter key to try again\n";
            system("pause>nul");
            system("cls");
            b();

        }

        cout << "\n\t\tEnter Patient Name : ";
        cin.ignore();
        getline(cin, name);

        cout << "\n\t\tEnter Patient Address : ";
        cin.ignore();
        getline(cin, address);
        cout << "\n\t\tEnter Patient Mobile Number : ";
        cin >> mobnum;
        cout << "\n\t\tEnter Patient age : ";
        cin >> age;
        cout << "\n\t\tEnter Patient Sex : ";
        cin >> sex;
        cout << "\n\t\tEnter Patient Blood Group : ";
        cin >> bloodgrp;
        cout << "\n\t\tAny major Previous Diseases : ";
        cin.ignore();
        getline(cin, dis);
        cout << "\n\n***Press Enter key to save***\n\n";
        system("pause >nul");
        fstream fadd;
        fadd.open("patdet.csv", ios::app);
        fadd << id << "," << name << "," << address << "," << mobnum << "," << age << "," << sex << "," << bloodgrp << "," << dis << "\n";
        fadd.close();
        cout << "***Information Successfully Saved***\n\n";
        cout << "Press Enter key to return";
        system("pause >nul");


    }
    // Add diagnosis function
    void addiag() {
        showpat();
        if (found == 1) {
            cout << "\n\n\t\t\t\t\t Add Diagnosis Info";
            cout << "\n\n\n\t\t\Sympthoms: ";
            cin.ignore();
            getline(cin, sym);
            cout << "\n\t\t\Diagnosis: ";
            cin.ignore();
            getline(cin, diag);
            cout << "\n\t\t\Medicines: ";
            cin.ignore();
            getline(cin, med);
            cout << "\n\t\t\Revisit After: ";
            cin.ignore();
            getline(cin, revt);
            cout << "\n\n***Press Enter key to save***\n\n";
            system("pause >nul");
            fstream fadd;
            fadd.open("patdiag.csv", ios::app);
            fadd << patid << "," << sym << "," << diag << "," << med << "," << revt << "\n";
            fadd.close();
            cout << "***Information Successfully Saved***\n\n";
            cout << "Press Enter key to return";
            system("pause >nul");
        }
        else {

            cout << "\n\n\tPress Enter key to return";
            system("pause >nul");
        }


    };
  
    
};
// doctor class
class doctor {
public:
    string docname, feedback;

    void fdb() {
        system("cls");
        cout << "\n\n\n\n\t\t\t\tDoctor Name: ";
        cin >> docname;
        cout << "\n\n\t\t\t\tFeedback: ";
        cin.ignore();
        getline(cin, feedback);
        fstream ffdb;
        ffdb.open("feedback.csv", ios::app);
        ffdb << docname << "," << feedback << "\n";
        ffdb.close();
        cout << "\n\n***Press Enter key to save***\n\n";
        system("pause >nul");
    }
};

//Doctor Screen Function
int b() {
    system("cls");
    int i;
    char fname[20];
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ----- MEDASSIST ----- \n\n";
    cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
    cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t|                                           	                 |\n";
    cout << "\t\t\t\t\t\t|             1  - Add New Patient Record                        |\n";
    cout << "\t\t\t\t\t\t|             2  - Add Diagnosis Information                     |\n";
    cout << "\t\t\t\t\t\t|             3  - Previous Record of the Patient                |\n";
    cout << "\t\t\t\t\t\t|             4  - View Appoitments                              |\n";
    cout << "\t\t\t\t\t\t|             5  - Exit the Program                              |\n";
    cout << "\t\t\t\t\t\t|________________________________________________________________|\n\n";
a:cout << "\t\t\t\t\t\tEnter your choice: "; cin >> i;

    switch (i) {
    case 1: {
        
        patient patadd;
        patadd.addpat();
        system("cls");
        b();

    }
          break;
    case 2: {
        patient patdiag;
        patdiag.addiag();
            b();
        
    }
          break;
    case 3: {
        patient patshow;
        patshow.showpat();
        cout << "\n\n\n***Press Enter key to return***";
        system("pause >nul");

        b();
    }
          break;
    case 4: {
     
        viewapp();
        
        b();
    }
          break;
    case 5: {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Thank you for using  \n\n";
        cout << "\n\t\t\t\t\t\t\t\t\t---- MEDASSISST ---- \n\n";
        cout << "\t\tPress Enter key to exit";
        system("pause > nul");
       
    }
          break;
    default:
    {
        cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
        cout << "\t\t\t\t\t\tPress Enter key to Try again.\n\n";
        system("pause > nul");
        system("cls");
        b();
        
    }
    
    }
    cout << "\n";
    return 0;
}

// Doctor Login Screen Function
int login() {
    string pass = "";
    char ch;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t---------- MEDASSIST --------- \n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while (ch != 13) {
        pass.push_back(ch);
        cout << "*";
        ch = _getch();
    }
    if (ch == 8 || ch == 127) {
        cout << "No Clearing is allowed\n";
        cout << "Please re-enter correct password\n";
        login();
    }
    if (pass == "pass") {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted\n";
        system("PAUSE");
        system("CLS");
        b();

    }
    else {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPress Enter key to Try Again\n\n";

        system("PAUSE >nul");
        system("CLS");
        login();
    }
    return 0;
};
// Patient Screen Function
int pat() {
    system("cls");
    int i;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tPlease choose one option\n\n";
    cout << "\t\t\t\t\t\t\t\t----------------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\t\t1 - Get medicine Information\n\n";
    cout << "\t\t\t\t\t\t\t\t\t2 - Book Appoitments\n\n";
    cout << "\t\t\t\t\t\t\t\t\t3 - View your report\n\n";
    cout << "\t\t\t\t\t\t\t\t\t4 - Give Feedback\n\n";
    cout << "\t\t\t\t\t\t\t\t\t5 - Exit the App\n\n";
    cout << "\t\t\t\t\t\t\t\t----------------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter : ";
    cin >> i;
    switch (i) {
    case 1: {
        viewmed();
        pat();

    }
          break;
    case 2: {
        bookapp();
        pat();
    }
          break;
    case 3: {
        patient patshow;
       patshow.showpat();
       cout << "\n\n\n***Press Enter key to return***";
       system("pause >nul");

       pat();

    }

          break;
    case 4: {
        doctor gfdb;
        gfdb.fdb();
        pat();

    }
          break;
    case 5: {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Thank you for using  \n\n";
        cout << "\n\t\t\t\t\t\t\t\t\t---- MEDASSISST ---- \n\n";
        cout << "\t\tPress Enter key to exit";
        system("pause > nul");

    }
          break;

    default:
    {
        cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
        cout << "\t\t\t\t\t\tPress Enter key to Try again.\n\n";
        system("pause > nul");
        system("cls");
        b();

    }

    }
    return 0;
}
//Home screen Function
int mainsc() {
    int i;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tUse MEDASSIST as :\n\n";
    cout << "\t\t\t\t\t\t\t\t--------------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\t\t1 - Patient / Consumer\n\n";
    cout << "\t\t\t\t\t\t\t\t\t2 - Admin / Doctor\n\n";
    cout << "\t\t\t\t\t\t\t\t--------------------------------------\n\n";

    cout << "\n\t * Press 1 - To View your records , Book appoitments , View drug details";
    cout << "\n\n\t * Press 2 - To add new patient , View patient history , Add Diagnosis Information , View Appointments\n\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter : ";
    cin >> i;
    if (i == 1) {
        pat();
    }
    else if (i == 2) {
        system("cls");
        login();
    }
    else {
        cout << "\n\t\t\t\t\t\t\t\tInvalid Choice\n";
        cout << "\t\t\t\t\t\t\t\tPress Enter key to try again";
        system("pause > nul");
        system("cls");
        mainsc();
    }
    return 0;

};

// main function
int main() {

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t WELCOME TO  \n\n";
    cout << "\n\t\t\t\t\t\t\t\t------- MEDASSISST ------- \n\n";

    system("pause");
    system("cls");
    int mainsc();
    int login();

    int pat();
    mainsc();


}

// Medicine Info function
void viewmed() {
    system("cls");
    string namemed, dosage, uses, sideeff, precautions, medname;
    cout << "\n\n\n\t\t\t\tEnter Medicine Name: ";
    cin >> medname;
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t\tMedicine Information - " << medname << endl;
    cout << "\n\n\t\t\t\t\t---------------------------------------------------------------------------";
    string line;
    ifstream file("medicines.csv"); 
    bool exist = false;
    while (getline(file, line)) {
        stringstream ss(line);
     
        getline(ss, namemed, ','); 
        if (namemed == medname) {
            cout << "\n\n\nMedicine Name: " << medname << endl;
            getline(ss, uses, ','); 
           
            cout  << "\n\nUses : " << uses << endl;
            getline(ss, dosage, ','); 
            cout << "\n\nDosage : " << dosage << endl;
            getline(ss, sideeff, ','); 
            cout << "\n\nSide Effects : " << sideeff << endl;
            getline(ss, precautions, ',');
            cout << "\n\nPrecautions : " << precautions << endl;
            exist = true;
            break;
        }
    }
    if (!exist) { 
        cout << "\n\n\n\t\t\tSorry Medicine Information not found." << endl;
    }

    cout << "\n\n\n\n\n\t***Press Enter key to return.***\n\n";
    system("pause > nul");
}
//book appointment function
void bookapp() {
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tBook an Appointment";
    cout << "\n\n\t\t\t\t\t\t------------------------------------------------------------------------\n";
    string hour, name, phnnum;
    int date;
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm now_tm;
    localtime_s(&now_tm, &now_c);
    char month[80];
    char pdate[200];
    char year[100];
    int n;
    strftime(month, 80, "%B", &now_tm);
    strftime(pdate, 200, "%d", &now_tm);
    strftime(year, 100, "%Y", &now_tm);
    if (month == "April" || month == "June" || month == "September" || month == "November") {
        n = 30;
    }
    else if (month == "February") {
        n = 28;
    }
    else n = 31;
    cout << "\n\n\t\tToday : " << pdate << " / " << month << " / " << year << '\n';
    cout << "\n\n\n\t\tEnter your name : ";
    cin >> name;
    cout << "\n\t\tEnter Mobile Number : ";
    cin >> phnnum;
    cout << "\n\n\t\t***  Bookings are done only in the Present month - " << month << "  ***";
    cout << "\n\n\n\t\tEnter the Date in " << month << ": ";
    cin >> date;
    string date1 = to_string(date);
    if (date<1 || date>n) {
        cout << "\n\t\tInvalid date";
        cout << "\n\n\t\t*** Press any key to try again ***";
        system("pause>nul");
        system("cls");
        bookapp();
    }
    else {
        int slot;
        system("cls");
        fstream fbook;
        fbook.open("appointments.csv", ios::app);
        cout << "\n\n\t\t\t\t\t\t\t\t--- Appointment Slots ---\n";
        cout << "\n\n\t\t\t\t\t\tAppoitments are only Avaliable between 9:00 and 21:00";
        ifstream fview("appointments.csv");
        cout << "\n\n\n\t\tAvaliable slots on " << date << " " << month << "\n\n\n";
        string line, field;
        int i = 0;
        int found3;
        int arr[13] = { 9,10,11,12,13,14,15,16,17,18,19,20,21};
        ifstream fviw("appointments.csv");
        while (getline(fviw, line)) {
            istringstream ss(line);
            string date_in_file, time, name, phone;
            getline(ss, date_in_file, ',');
            getline(ss, time, ',');
            getline(ss, name, ',');
            getline(ss, phone, '\n');
            int tymnum = stoi(time);
            if (date_in_file == date1 ) {
                for (int k = 0; k < 13; k++) {
                    if (arr[k] == tymnum) {
                          arr[k] = 0;
                      
                    }
                }
                
            }
        }
        for (int j = 0; j < 13; j++) {
            if (!arr[j] == 0) {
                cout <<"\t\t" << arr[j] << ":00 " << "  ---->  " << "Available\n\n";
            }
        }
      
       cout << "\n\n\t\tEnter the time of Appoitment : ";
        cin >> slot;
       
       

                     if (slot > 21 || slot < 9) {
                    cout << "\n\n\t\tAppoitments are not avaliable at that time.";
                    cout << "\n\n\t\tEnter any key to try again";
                    system("pause>nul");

                    bookapp();
                }
                else  {
                    string slot1 = to_string(slot);
                    fbook << date1 << "," << slot1 << "," << name << "," << phnnum << "\n";
                    fbook.close();
                    cout << "\n\n\t\tAppoitment Booked Successfully on " << date << " " << month << " at " << slot1 << ":00";

                    cout << "\n\n\t\tEnter any key to return";
                    system("pause>nul");

                }
               
    }
}
//view appointment function
void viewapp() {
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tView Appointments";
    cout << "\n\n\t\t\t\t\t------------------------------------------------------------------------\n";
    string date;
    int found1 = 0;
    cout << "\n\n\t\tEnter a date to view Appointments : ";
    cin >> date;
    ifstream fview("appointments.csv"); 

    string line, sdate,field;
    cout << "\n\t\t\t\t\t\t\t--- Your Appointments ---\n";
    while (getline(fview, line)) {
        istringstream ss(line);
        string date_in_file, time, name, phone;
        getline(ss, date_in_file, ',');
        getline(ss, time, ',');
        getline(ss, name, ',');
        getline(ss, phone ,'\n');

        if (date_in_file == date) {
            found1 = 1;
            cout << "\n\t\t At " <<time<<":00"<<" by "<<name<<" Contact: " <<phone << endl;
           
        }
        
    }
    if (found1 == 0) {
        cout << "\n\n\t\tNo Appointments found on that date.";
    }

    fview.close();
    cout << "\n\n\t*** Press any key to return ***";
    system("pause>nul");
}

