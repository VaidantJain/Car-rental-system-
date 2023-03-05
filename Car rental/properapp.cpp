/*
    Car rental system using oops concept
    author-> Sahil Choudhary 
    gmail-> sc941432@gmail.com
    roll no 104032
    div 4(d2)
    cse 1st year student in mit wpu 
*/

#include<iostream>
#include<string>
#include<fstream>
#include<time.h>   //required for rand and srand function and for otp;
#include<cstdlib>
#include<vector>  // required for forgot password member function;
#include<istream>
using namespace std;

class car
{
    private:
                string username,password,address1,fname,lname,gmail,carmodel;
                string str1,str2,str3,user,pass;
                int carchoice,Qty,noofday;
                
    public:
                string name,address,Gmail;
                long int perdaycharge;
                void login();
                void signup();
                void forgotpass();
                void carselect();
                void invoice();
                void invoiceinfo()
                {
                    cout<<"enter no of cars you want to select:"<<endl;
                    cin>>Qty;

                    cout<<"Enter no of day for car rent: "<<endl;
                    cin>>noofday;
                };
                ~car();
};

car::~car()
{
    cout<<"Your destructor is called ";
}

void car::invoice()
{
    long long invoiceno=rand(),accno=rand(),OTP;
    float totalam=Qty*perdaycharge*noofday;
    float gst=totalam*0.18;
    string issdate,duedate;
    cout<<"Enter issue date of vechile in format day/month/year : "<<endl;
    cin>>issdate;

    ofstream otptxt;
    otptxt.open("otp.txt");
    srand(time(0)) ;
    otptxt<<rand()<<endl;
    otptxt.close();

    ifstream openfile;
    openfile.open("otp.txt");
    openfile>>OTP;
    

    cout<<"If payment is done then please enter otp which you get in text format of name otp.txt to get invoice in textfile formet"<<endl;
    long long otp;
    cin>>otp;

    if(otp==OTP){
    ofstream invoicetxt;
    invoicetxt.open(user,ios::out);

    invoicetxt<<"/////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
    invoicetxt<<"----------------------------------------------------Invoice----------------------------------------------------- "<<endl;
    invoicetxt<<"////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl<<endl;
    invoicetxt<<"Company name:                                                    Invoice no:->"<<invoiceno<<endl;
    invoicetxt<<"Sahil Car Rental system                                           Account no:->"<<accno<<endl;
    invoicetxt<<"34 Shastri nagar, sikar                                           Issue date:->"<<issdate<<endl;
    invoicetxt<<"Rajasthan,India                                                   Due date:->"<<noofday<<" "<<"days after the given issue date "<<issdate<<endl;
    invoicetxt<<"234-567-5678"<<endl;
    invoicetxt<<"sc941432@gmail.com"<<endl<<endl;

    invoicetxt<<"Billed to: "<<endl;
    invoicetxt<<"Client name: "<<name<<endl;
    invoicetxt<<"Address: "<<address<<endl;
    invoicetxt<<"Gmail: "<<Gmail<<endl;
    invoicetxt<<"Username: "<<str1<<endl<<endl;

    invoicetxt<<"Item details:"<<carmodel<<endl;
    invoicetxt<<"Qty:              Perday price         No. of days            total             gst(18%)    "<<endl;
    invoicetxt<<Qty<<"                "<<perdaycharge<<"                   "<<noofday<<"            "<<"          "<<totalam<<"               "<<gst<<endl;
    }

    else
    {
        cout<<"Otp is wrong: "<<endl;
    }
    

}

void car::carselect()
{
    cout<<"/////////////////////////---Welcome To car Selection page:---///////////////////////////"<<endl;
    ifstream infotext;
    infotext.open("info1.txt");

   while(getline(infotext,str3))
    {
    cout<<str3<<endl;
    }
    cout<<endl<<" Enter your Choice from available Cars by using 1/2/3/4/5 please: "<<endl;
    cin>>carchoice;

    switch(carchoice)
    {
        case 1: cout<<"So you Select Tesla model 3"<<endl;
                    carmodel="Tesla model 3";
                    invoiceinfo();
                    perdaycharge=16000;
                        invoice();
                         break;

        case 2: cout<<"SO you Select Tata tiago EV XZ+ tech lux "<<endl;
                    carmodel="Tata tiago EV XZ+ tech lux";
                    invoiceinfo();
                    perdaycharge=14000;
                    invoice();
                        break;
        
        case 3: cout<<"So you select BMW i7 "<<endl;
                    carmodel="BMW i7";
                     invoiceinfo(); 
                     perdaycharge=15000;
                     invoice(); 
                        break;
        case 4: cout<<"So you select BMW iX "<<endl;
                   carmodel="BMW iX";
                    invoiceinfo();
                    perdaycharge=18000;
                    invoice();
                    break;


        case 5: cout<<"So you select Audi A8 Q5 "<<endl;
                    carmodel="Audi A8 Q5"; 
                    invoiceinfo();
                    perdaycharge=16500;
                        invoice();                       
                         break;

        default: cout<<"Sorry That Car is not Available "<<endl;
    }

}

void car::login()
{
    cout<<"Enter your Username:"<<endl;
    cin>>user;
    cout<<"Enter Your password: "<<endl;
    cin>>pass;

    ifstream textfile;
    textfile.open("userinfo.txt");

    while(!textfile.eof())
    {
        getline(textfile,str1);
        if(str1==user) break;
    }
    getline(textfile,str2);
    getline(textfile,name);
    getline(textfile,address);
    getline(textfile,Gmail);
    textfile.close();


    cout<<"actual username: "<<str1<<endl;
    cout<<"actual password: "<<str2<<endl;
  

    if(user==str1 && pass==str2)
    {
        cout<<"*****************************Sucesfully login*********************************** "<<endl<<endl;
        carselect();
    }

    else if(user==str1 && pass!=str2)
    {
        cout<<"Error"<<endl;
        cout<<"Password is wrong: "<<endl;
    }

    else if (user!=str1 &&pass==str2)
    {
        cout<<"Error"<<endl;
        cout<<"Username is wrong "<<endl;
    }

    else
    {
        cout<<"Error"<<endl;
        cout<<"Username and password is wrong"<<endl;
    }
}

void car::signup()
{
    
    cout<<"Enter your First Name :"<<endl;
    getline(cin,fname);
    
    cout<<"Enter your last Name: "<<endl;
    getline(cin,lname);

    cout<<"Enter username for your account: "<<endl;
    getline(cin,username);

    cout<<"Enter password for your account: "<<endl;
    getline(cin,password);

    cout<<"Enter your Address please: "<<endl;
    getline(cin,address1);

    cout<<"Enter your Gmail :"<<endl;
    getline(cin,gmail);

    ofstream textfile;
    textfile.open("userinfo.txt",ios::app);
    textfile<<username<<endl;
    textfile<<password<<endl;
    textfile<<fname<<" "<<lname<<endl;
    textfile<<address1<<endl;
    textfile<<gmail<<endl<<endl;   
    cout<<"******************************************"<<endl;
    cout<<"You are Sucessfully Registred for our app "<<endl;
    cout<<"******************************************"<<endl;
}

void car::forgotpass()
{

   int linenumber=1;
    string user,str1,password;
cout<<"Enter your existed username"<<endl;
cin>>user;

    ifstream textfile;
    textfile.open("userinfo.txt");
    while(!textfile.eof())
    {   linenumber++;
        getline(textfile,str1);
        if(str1==user)
        break;
    };
        cout<<"Line of password is :"<<linenumber<<endl;
    textfile.close();
    cout<<"Now enter your new password: ";
    cin>>password;



    ifstream readfile;
    readfile.open("userinfo.txt");

    vector<string> lines;
    string line;

    while(getline(readfile,line))
    {
        lines.push_back(line);
    }

    readfile.close();

    ofstream writefile;
    writefile.open("userinfo.txt");

        linenumber--;
     for (int i = 0; i < lines.size(); i++)
        {

             if (i !=linenumber)
             writefile << lines[i] << endl;
            else 
             writefile << password << endl; 
        }



}

int main()
{
    car c1;
    int n;
    cout<<"Enter your Choice:"<<endl;
    cout<<"1.Login , 2.Signup , 3.Forgot password"<<endl;
    cin>>n;
    switch(n)
    {
        case 1: cout<<"You select for login "<<endl;
                c1.login();
               
                break;

        case 2: cout<<"You select for signup "<<endl;
                c1.signup();
                cout<<" Now login is called "<<endl;
                c1.login();
                
                break;

        case 3: cout<<"You select forgot password "<<endl;
                c1.forgotpass(); 

                cout<<"Now to login enter your information: "<<endl;
                 car c1;
                 c1.login();               
                break;
    }



    return 0;
}