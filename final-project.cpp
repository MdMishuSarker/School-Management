#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class employee;
class student;

class teacher
{
private:
    int tidnum;
    char tname[50];
    char tfname[50];
    char tmname[50];
    double salary;
    double total;
    char taddress[100];
    char coursename[30];
    void salary_calculate();


public:
    void getdata();
    void showdata()const;
    int getIDNum() const;
};

void teacher::salary_calculate()
{
    total=((salary*5/100.0)+(salary*3/100.0)+(salary*10/100.0)+salary);//5% for health injury, 3% for bonus and 10 for other
}

int  teacher::getIDNum() const
{
    return tidnum;
}

int teacher_check[100009];
int student_check[100009];
int employee_check[100009];

void teacher::getdata()
{
    cout<<"\nEnter The Id Number of The Teacher: ";
    while(cin>>tidnum)
    {
        if(teacher_check[tidnum]==0)
        {
            teacher_check[tidnum]=1;
            break;
        }
        else
        {
            cout<<"\nalready use this Id.\nEnter The New Id Number of The Teacher:";
        }
    }
    cout<<"\nEnter teacher's name: ";
    cin>>tname;
    cout<<"\nEnter father's name: ";
    cin>>tfname;
    cout<<"\nEnter mother's name: ";
    cin>>tmname;
    cout<<"\nEnter course name: ";
    cin>>coursename;
    cout<<"\nEnter address: ";

    cin>>taddress;
    cout<<"\nEnter salary: ";
    cin>>salary;
    salary_calculate();
}

void teacher::showdata()const
{
    cout<<"\nId number: "<<tidnum;
    cout<<"\nTeacher name: "<<tname;
    cout<<"\nFather name: "<<tfname;
    cout<<"\nMother name: "<<tmname;
    cout<<"\nCourse name: "<<coursename;
    cout<<"\nAddress: "<<taddress;
    cout<<"\nTotal salary: "<<total;
}

void saveTeacher();
void displayTall();
void searchTdisplay(int);
void modifyTeacher(int);
void deleteTeacher(int);




void saveTeacher()
{
    teacher tt;
    ofstream outFile;
    outFile.open("teacher.dat",ios::binary|ios::app);
    tt.getdata();
    outFile.write(reinterpret_cast<char *> (&tt), sizeof(teacher));
    outFile.close();
    cout<<"\n\nTeacher record Has Been Created ";
    cin.ignore();
    cin.get();
}


void displayTall()
{
    teacher tt;
    ifstream inFile;
    inFile.open("teacher.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while(inFile.read(reinterpret_cast<char *> (&tt), sizeof(teacher)))
    {
        tt.showdata();
        cout<<"\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void searchTdisplay(int n)
{
    teacher tt;
    ifstream inFile;
    inFile.open("teacher.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&tt), sizeof(teacher)))
    {
        if(tt.getIDNum()==n)
        {
            tt.showdata();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nrecord not exist";
    cin.ignore();
    cin.get();
}


void modifyTeacher(int n)
{
    bool found=false;
    teacher tt;
    fstream File;
    File.open("teacher.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found==false)
    {

        File.read(reinterpret_cast<char *> (&tt), sizeof(teacher));
        if(tt.getIDNum()==n)
        {
            tt.showdata();
            cout<<"\n\nPlease Enter The New Details of student"<<endl;
            tt.getdata();
            int pos=(-1)*static_cast<int>(sizeof(tt));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&tt), sizeof(teacher));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void deleteTeacher(int n)
{
    teacher tt;
    ifstream inFile;
    inFile.open("teacher.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&tt), sizeof(teacher)))
    {
        if(tt.getIDNum()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&tt), sizeof(teacher));
        }
    }
    outFile.close();
    inFile.close();
    remove("teacher.dat");
    rename("Temp.dat","teacher.dat");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}



class employee
{
private:
    int eidnum;
    char ename[50];
    char efname[50];
    char emname[50];
    double esalary;
    double etotal;
    char eaddress[100];
    void esalary_calculate();


public:
    void getdata();
    void showdata()const;
    int getIDNum() const;
};

void employee::esalary_calculate()
{
    etotal=((esalary*5/100.0)+(esalary*3/100.0)+(esalary*10/100.0)+esalary);//5% for health injury, 3% for bonus and 10 for other
}

int  employee::getIDNum() const
{
    return eidnum;
}


void employee::getdata()
{
    cout<<"\nEnter The Id Number of The Employee: ";
    while(cin>>eidnum)
    {
        if(employee_check[eidnum]==0)
        {
            employee_check[eidnum]=1;
            break;
        }
        else
        {
            cout<<"\nalready use this Id.\nEnter The Id Number of The Employee:";
        }
    }
    cout<<"\nEnter teacher's name: ";
    cin>>ename;
    cout<<"\nEnter father's name: ";
    cin>>efname;
    cout<<"\nEnter mother's name; ";
    cin>>emname;
    cout<<"\nEnter address: ";
    cin>>eaddress;
    cout<<"\nEnter salary: ";
    cin>>esalary;
    esalary_calculate();
}

void employee::showdata()const
{
    cout<<"\nId number: "<<eidnum;
    cout<<"\nEmployee name: "<<ename;
    cout<<"\nFather name: "<<efname;
    cout<<"\nMother name: "<<emname;
    cout<<"\nAddress: "<<eaddress;
    cout<<"\nTotal salary: "<<etotal;
}

void saveEmployee();
void displayEall();
void searchEdisplay(int);
void modifyEmployee(int);
void deleteEmpoyee(int);




void saveEmployee()
{
    employee ee;
    ofstream outFile;
    outFile.open("employee.dat",ios::binary|ios::app);
    ee.getdata();
    outFile.write(reinterpret_cast<char *> (&ee), sizeof(employee));
    outFile.close();
    cout<<"\n\nTeacher record Has Been Created ";
    cin.ignore();
    cin.get();
}


void displayEall()
{
    employee ee;
    ifstream inFile;
    inFile.open("employee.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while(inFile.read(reinterpret_cast<char *> (&ee), sizeof(employee)))
    {
        ee.showdata();
        cout<<"\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void searchEdisplay(int n)
{
    employee ee;
    ifstream inFile;
    inFile.open("employee.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&ee), sizeof(employee)))
    {
        if(ee.getIDNum()==n)
        {
            ee.showdata();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nrecord not exist";
    cin.ignore();
    cin.get();
}


void modifyEmployee(int n)
{
    bool found=false;
    employee ee;
    fstream File;
    File.open("teacher.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found==false)
    {

        File.read(reinterpret_cast<char *> (&ee), sizeof(employee));
        if(ee.getIDNum()==n)
        {
            ee.showdata();
            cout<<"\n\nPlease Enter The New Details of student"<<endl;
            ee.getdata();
            int pos=(-1)*static_cast<int>(sizeof(ee));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ee), sizeof(employee));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void deleteEmployee(int n)
{
    employee ee;
    ifstream inFile;
    inFile.open("employee.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ee), sizeof(employee)))
    {
        if(ee.getIDNum()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ee), sizeof(employee));
        }
    }
    outFile.close();
    inFile.close();
    remove("employee.dat");
    rename("Temp.dat","employee.dat");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}

class student
{
    int idnum;
    int class_;
    char name[50];
    char fname[50];
    char mname[50];
    char address[100];
    int bangla,mathematics, english,religious, comscience;
    double per;
    char grade;
    void calculate();
public:
    void getdata();
    void showdata() const;
    void show_tabler() const;
    int getIDNum() const;
};


void student::calculate()
{
    per=(bangla+religious+mathematics+english+comscience)/5.0;
    if(per>=90)
        grade='A+';
    else if(per>=80)
        grade='A';
    else if(per>=75)
        grade='A-';
    else if(per>=70)
        grade='B+';
    else if(per>=65)
        grade='B';
    else if(per>=60)
        grade='B-';
    else if(per>=55)
        grade='C+';
    else if(per>=50)
        grade='C';
    else
        grade='F';
}

void student::getdata()
{
    cout<<"\nEnter The ID number of the student: ";
    while(cin>>idnum)
    {
        if(student_check[idnum]==0)
        {
            student_check[idnum]=1;
            break;
        }
        else
        {
            cout<<"\nalready use this Id.\nEnter The ID number of the student: ";
        }
    }
    cout<<"\n\nEnter student's Name: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\n\nEnter Father's Name: ";
    cin.ignore();
    cin.getline(fname,50);
    cout<<"\n\nEnter Mother's Name: ";
    cin.ignore();
    cin.getline(mname,50);
    cout<<"\n\nEnter student's address: ";
    cin.ignore();
    cin.getline(address,100);
    cout<<"\n\nEnter Class name: ";
    cin>>class_;
    cout<<"\nEnter student's Bangla marks: ";
    cin>>bangla;
    cout<<"\nEnter student's Mathematics marks: ";
    cin>>mathematics;
    cout<<"\nEnter student's English marks: ";
    cin>>english;
    cout<<"\nEnter student's Religious marks: ";
    cin>>religious;
    cout<<"\nEnter student's computer science marks: ";
    cin>>comscience;
    calculate();
}

void student::showdata() const
{
    cout<<"\nID Number: "<<idnum;
    cout<<"\nName: "<<name;
    cout<<"\nclass:"<<class_;
    cout<<"\nFather's name:"<<fname;
    cout<<"\nMother's name:"<<mname;
    cout<<"\nBangla: "<<bangla;
    cout<<"\nReligious: "<<religious;
    cout<<"\nMathematics: "<<mathematics;
    cout<<"\nEnglish: "<<english;
    cout<<"\nComputer Science: "<<comscience;
    cout<<"\nPercentage: "<<per;
    cout<<"\nLetter Grade: "<<grade;
}

void student::show_tabler() const
{
    cout<<idnum<<setw(6)<<" "<<name<<setw(10)<<bangla<<setw(4)<<religious<<setw(4)<<mathematics<<setw(4)
        <<english<<setw(4)<<comscience<<setw(8)<<per<<setw(6)<<grade<<endl;
}

int  student::getIDNum() const
{
    return idnum;
}



void SaveStudent();
void displayAll();
void Searchdisplay(int);
void modifyStudent(int);
void deleteStudent(int);
void DisplayResult();





void SaveStudent()
{
    student st;
    ofstream outFile;
    outFile.open("student.dat",ios::binary|ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
    outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
    cin.ignore();
    cin.get();
}



void display_all()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    {
        st.showdata();
        cout<<"\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}



void Searchdisplay(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    {
        if(st.getIDNum()==n)
        {
            st.showdata();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false)
        cout<<"\n\nrecord not exist";
    cin.ignore();
    cin.get();
}


void modify_student(int n)
{
    bool found=false;
    student st;
    fstream File;
    File.open("student.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found==false)
    {

        File.read(reinterpret_cast<char *> (&st), sizeof(student));
        if(st.getIDNum()==n)
        {
            st.showdata();
            cout<<"\n\nPlease Enter The New Details of student"<<endl;
            st.getdata();
            int pos=(-1)*static_cast<int>(sizeof(st));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&st), sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}



void delete_student(int n)
{
    student st;
    ifstream inFile;
    inFile.open("student.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat",ios::out);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    {
        if(st.getIDNum()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}


void class_result()
{
    student st;
    ifstream inFile;
    inFile.open("student.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
    cout<<"==========================================================\n";
    cout<<"R.No       Name        B   R   M   E   CS   %age   Grade"<<endl;
    cout<<"==========================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    {
        st.show_tabler();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}









int main()
{
    for(int i=0; i<100008; i++)
    {
        student_check[i]=0;
        teacher_check[i]=0;
        employee_check[i]=0;
    }
    remove("employee.dat");
    remove("student.dat");
    remove("teacher.dat");
    int th;
    int tnum;
    int num;
    cout.setf(ios::fixed|ios::showpoint);
    cout<<setprecision(2);
    do
    {

        cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<"\n\n\t********For Teacher*********";
        cout<<"\n\n\t1.CREATE TEACHER RECORD";
        cout<<"\n\n\t2.DISPLAY ALL TEACHERS RECORDS";
        cout<<"\n\n\t3.SEARCH Teacher RECORD ";
        cout<<"\n\n\t4.MODIFY Teacher RECORD";
        cout<<"\n\n\t5.DELETE Teacher RECORD";

        cout<<"\n\n\t********For Employee**********";
        cout<<"\n\n\t6.CREATE Employee RECORD";
        cout<<"\n\n\t7.DISPLAY ALL Employee RECORDS";
        cout<<"\n\n\t8.SEARCH Employee RECORD ";
        cout<<"\n\n\t9.MODIFY Employee RECORD";
        cout<<"\n\n\t10.DELETE Employee RECORD";

        cout<<"\n\n\t********For Student***********";
        cout<<"\n\n\t11.CREATE STUDENT RECORD";
        cout<<"\n\n\t12.DISPLAY ALL STUDENTS RECORDS";
        cout<<"\n\n\t13.SEARCH STUDENT RECORD ";
        cout<<"\n\n\t14.MODIFY STUDENT RECORD";
        cout<<"\n\n\t15.DELETE STUDENT RECORD";
        cout<<"\n\n\t16. DISPLAY CLASS RESULT";

        cout<<"\n\n\t17. EXIT";
        cout<<"\n\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout<<"\n\n\tPlease Enter Your Choice (1-17): ";
        cin>>th;

        switch(th)
        {
        case 1:
            saveTeacher();
            break;
        case 2:
            displayTall();
            break;
        case 3:
            cout<<"\n\n\tPlease Enter teacher's ID number: ";
            cin>>tnum;
            searchTdisplay(tnum);
            break;
        case 4:
            cout<<"\n\n\tPlease Enter teacher's ID number: ";
            cin>>tnum;
            modifyTeacher(tnum);
            break;
        case 5:
            cout<<"\n\n\tPlease Enter teacher's ID number: ";
            cin>>tnum;
            deleteTeacher(tnum);
            break;

        case 6:
            saveEmployee();
            break;
        case 7:
            displayEall();
            break;
        case 8:
            cout<<"\n\n\tPlease Enter teacher's ID number: ";
            cin>>tnum;
            searchEdisplay(tnum);
            break;
        case 9:
            cout<<"\n\n\tPlease Enter teacher's ID number: ";
            cin>>tnum;
            modifyEmployee(tnum);
            break;
        case 10:
            cout<<"\n\n\tPlease Enter teacher's ID number: ";
            cin>>tnum;
            deleteEmployee(tnum);
            break;

        case 11:
            SaveStudent();
            break;
        case 12:
            display_all();
            break;
        case 13:
            cout<<"\n\n\tPlease Enter Student's ID number: ";
            cin>>tnum;
            Searchdisplay(tnum);
            break;
        case 14:
            cout<<"\n\n\tPlease Enter Student's ID number: ";
            cin>>tnum;
            modify_student(tnum);
            break;
        case 15:
            cout<<"\n\n\tPlease Enter Student's ID number: ";
            cin>>tnum;
            delete_student(tnum);
            break;
        case 16 :
            class_result();
            break;


        default:
            cout<<"\a";

        }
    }
    while(th!=17);
    return 0;
}
