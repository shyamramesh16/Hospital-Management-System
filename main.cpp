
#include<iostream>
#include<string>
#include <fstream>
#include <iomanip>
#include<ctime>
using namespace std;
string phno,name,v,d1[5],d2[5],d3[5],t;
int f1=-1,r1=-1,f2=-1,r2=-1,f3=-1,r3=-1,s1=5,s2=5,s3=5,i,c5=0,c6=0;
class patient
{
public:
    string name,phno,dob,age,date,med;
    void get()
    {
        cout<<"\n Welcome "<<endl;
        cout<<"---Enter your Details---"<<endl;
        med="New Patient";
        cout<<"Patient Name:";
        cin>>name;
        cout<<"Patient phno:";
        cin>>phno;
        cout<<"Patient DOB:";
        cin>>dob;
        cout<<"Patient Age:";
        cin>>age;
        cout<<"Mr/Ms "<<name<<" ur credentials have been sucessfully stored"<<endl;
    }
    void eget()
    {
        cout<<"---Enter your login credentials--"<<endl;
        cout<<"Name:";
        cin>>name;
        cout<<"Register number:";
        cin>>phno;
    }
}p;
void addrecord(string c)
{
    string date,pres,t3,t4,t5;
    cout<<"Date of visit:";
    cin>>date;
    cout<<"Medicine Prescribed:";
    cin>>pres;
    fstream g;
    g.open("patientrecords.txt");
    while(g)
    {
        int loc=g.tellg();
        g.read((char*)&p,sizeof(p));
        if(p.name==c)
        {
            p.date=date;
            p.med=pres;
            g.seekg(loc);
            g.write((char*)&p,sizeof(p));
        }
    }
    g.close();
}
void disp_oldrecords(string b)
{
    fstream g;
    g.open("patientrecords.txt");
    while (g.read((char *) &p, sizeof(p))) {

        if(b==p.name)
        {
            cout<<"Patient Name:"<<p.name<<endl;
            cout<<"Age:"<<p.age<<endl;
            cout<<"Last Visit"<<endl;
            if(p.med=="New Patient")
            {
                cout<<p.med<<endl;
            } else {
                cout << "Date:"<<p.date<<"\t\t\tPrescription:"<<p.med<<endl;
            }
        }
    }
    g.close();
}
void d1enqueue(string a)
{
    if(r1>=s1)
    {
        cout<<"Sorry Dr Murali's queue is Full"<<endl;
    }
    else if(f1==-1)
    {
        f1=r1=0;
        d1[f1]=a;
    }
    else
    {
        r1++;
        d1[r1]=a;
    }
}
void d1dequeue()
{
    if(r1==-1)
    {
        cout<<"Your patient queue is\n";
        cout<<"empty"<<endl;
    }
    else
    {
        cout<<"the removed patient is "<<d1[f1]<<endl;
        for(i=f1+1;i<=r1;i++)
        {
            d1[i-1]=d1[i];
        }
        r1--;
    }
}
void d1disp()
{
    if(r1==-1)
    {
        cout<<"Your patient queue is\n";
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"Your patient queue is\n";
        for(i=0;i<=r1;i++)
        {
            cout<<d1[i]<<endl;
        }
    }
}
void d2enqueue(string a)
{
    if(r2>=s2)
    {
        cout<<"Sorry Dr Srivani's queue is Full"<<endl;
    }
    else if(f2==-1)
    {
        f2=r2=0;
        d2[f2]=a;
    }
    else
    {
        r2++;
        d2[r2]=a;
    }
}
void d2dequeue()
{
    if(r2==-1)
    {
        cout<<"Your patient queue is\n";
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"The Removed Patient is "<<d2[f2]<<endl;
        for(i=f2+1;i<=r2;i++)
        {
            d2[i-1]=d2[i];
        }
        r2--;
    }
}
void d2disp()
{
    if(r2==-1)
    {
        cout<<"Your patient queue is\n";
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"Your patient queue is\n";
        for(i=0;i<=r2;i++)
        {
            cout<<d2[i]<<endl;
        }
    }
}
void d3enqueue(string a)
{
    if(r3>=s3)
    {
        cout<<"Sorry Dr Deebak's queue is Full"<<endl;
    }
    else if(f3==-1)
    {
        f3=r3=0;
        d3[f3]=a;
    }
    else
    {
        r3++;
        d3[r3]=a;
    }
}
void d3dequeue()
{
    if(r3==-1)
    {
        cout<<"Your patient queue is\n";
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"The removed patient is "<<d3[f3]<<endl;
        for(i=f3+1;i<=r3;i++)
        {
            d3[i-1]=d3[i];
        }
        r3--;
    }
}
void d3disp()
{
    if(r3==-1)
    {
        cout<<"Your patient queue is\n";
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"Your patient queue is\n";
        for(i=0;i<=r3;i++)
        {
            cout<<d3[i]<<endl;
        }
    }
}
void check(string b)
{
    int h=0,o=0;
    string id,t1,t2;
    string na,doc_id;
    cout<<"Enter your doctor ID:";
    cin>>id;
    t1=b+" "+id;
    fstream l;
    l.open("doctor.txt");
    while (getline(l, t2)) {
        h++;
        if (t1 == t2) {
            o++;
            break;
        }
    }
    if(o==1)
    {
            switch(h) {
                case 1:
                    d1disp();
                    c5 = 0;
                    while (c5 != 3) {
                        cout << "\nchoose your option\n1.first patient records\n2.dequeue patient\n3.exit";
                        cin >> c5;
                        switch (c5) {
                            case 1:
                                c6 = 0;
                                disp_oldrecords(d1[0]);
                                while (c6 != 2) {
                                    cout << "\n1.Add prescribtion\n2.exit";
                                    cin >> c6;
                                    switch (c6) {
                                        case 1:
                                            addrecord(d1[0]);
                                            break;
                                        case 2:
                                            cout << "exited successfully"<<endl;
                                            break;
                                    }
                                }
                                break;
                            case 2:
                                d1dequeue();
                                d1disp();
                                break;
                            case 3:
                                cout << "exited successfully"<<endl;
                                break;
                        }
                    }
                    break;
                case 2:
                    d2disp();
                    c5 = 0;
                    while (c5 != 3) {
                        cout << "\nchoose your option\n1.first patient records\n2.dequeue patient\n3.exit";
                        cin >> c5;
                        switch (c5) {
                            case 1:
                                c6 = 0;
                                disp_oldrecords(d2[0]);
                                while (c6 != 2) {
                                    cout << "\n1.Add prescribtion\n2.exit";
                                    cin >> c6;
                                    switch (c6) {
                                        case 1:
                                            addrecord(d2[0]);
                                            break;
                                        case 2:
                                            cout << "exited successfully"<<endl;
                                            break;
                                    }
                                }
                                break;
                            case 2:
                                d2dequeue();
                                d2disp();
                                break;
                            case 3:
                                cout << "exited successfully"<<endl;
                                break;
                        }
                    }
                    break;
                case 3:
                    d3disp();
                    c5 = 0;
                    while (c5 != 3) {
                        cout << "\nchoose your option\n1.first patient records\n2.dequeue patient\n3.exit";
                        cin >> c5;
                        switch (c5) {
                            case 1:
                                c6 = 0;
                                disp_oldrecords(d2[0]);
                                while (c6 != 2) {
                                    cout << "\n1.Add prescribtion\n2.exit";
                                    cin >> c6;
                                    switch (c6) {
                                        case 1:
                                            addrecord(d2[0]);
                                            break;
                                        case 2:
                                            cout << "exited successfully"<<endl;
                                            break;
                                    }
                                }
                                break;
                            case 2:
                                d3dequeue();
                                d3disp();
                                break;
                            case 3:
                                cout << "exited successfully"<<endl;
                                break;

                        }
                    }
                    break;
            }
        }
        else {
            cout << "Wrong Doctor ID";
        }
    }
void selection()
{
    int c1,c8;
    cout<<"\nChoose your doctor\n1.Dr.Murali\n2.Dr.Srivani\n3.Dr.Deebak"<<endl;
    cin>>c1;
    switch(c1)
    {
        case 1:
            d1enqueue(v);
            cout<<"you are enqueued to Dr.Murali's Queue \n";
            break;
        case 2:
            d2enqueue(v);
            cout<<"you are enqueued to Dr.Srivani's Queue\n";
            break;
        case 3:
            d3enqueue(v);
            cout<<"you are enqueued to Dr.Deebak's Queue \n";
            break;

    }
}
void olduser()
{
    int l=0;
    patient t;
    fstream g;
    t.eget();
    g.open("patientrecords.txt");
    while (g.read((char *) &p, sizeof(p))) {
        if(t.name==p.name && t.phno==p.phno)
        {
            l++;
            v=p.name;
        }
    }
    if(l==1)
    {
        cout<<"login success"<<endl;
        selection();
    }
    else{
        cout<<"fail";

    }
    g.close();
}
void newuser()
{
    fstream f;
    f.open("patientrecords.txt",ios::app);
    p.get();
    f.write((char *)&p,sizeof(p));
    f.close();
    cout<<"Login to continue"<<endl;
    olduser();
}
int main()
{
    int c=0,c3=0,c4=0;
    time_t rawtime;
    struct tm * timeinfo;
    while (true)
    {
        time( &rawtime );
        timeinfo = localtime( &rawtime );
        cout<< "Current time and date: "<<asctime (timeinfo)<< endl;
        break;
    }
    cout<<"\t\t\tHospital Management System\n"<<endl;
    while(c3!=3)
    {
        cout<<"\n---Choose ur option---\n1.doctor\n2.patient\n3.exit"<<endl;
        cin>>c3;
        switch(c3)
        {
            case 1:
                c4=0;
                while (c4!=4) {
                    cout << "choose your option\n1.Dr.Murali\n2.Dr.Srivani\n3.Dr.Deebak\n4.Exit" << endl;
                    cin >> c4;
                    switch (c4) {
                        case 1:
                            t="Dr.Murali";
                            check(t);
                            break;
                        case 2:
                            t="Dr.Srivani";
                            check(t);
                            break;
                        case 3:
                            t="Dr.Deebak";
                            check(t);
                            break;
                        case 4:
                            break;
                    }
                }
                break;
            case 2:
                cout<<"\nchoose ur operation\n1.login\n2.new patient\n3.Exit"<<endl;
                cin>>c;
                switch (c)
                {
                    case 1:
                        olduser();
                        break;
                    case 2:
                        newuser();
                        break;
                    case 3:
                        break;
                }
                break;
            case 3:
                cout<<"!!Thank you for using the system!!"<<endl;
                break;
        }
    }
}
