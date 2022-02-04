#include<iostream>//header file for
#include<fstream>//header file for
#include<string.h>//header file for
using namespace std;
//protoype declarations of the functions used in this program
int enter();
int display();
void login();
int update();
void admin();
void user();

//structure used in this function
struct details //declaration of the structure with name
{
    long int aadhar;//long integer type variable declared
    char name[30];//static char array is declared ,to be used to input strings
    char gender;
    int age;
};
int slot=20;//global variable is declared and initialized
//main function
int main(){
    cout<<"\n";
    cout<<" \t\t\t\t\t\t\t\t\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n          ";
    cout<<"\t\t\t\t\t\t\t\t /././././.BOOK VACCINATION SLOT./././././\n     ";
    cout<<" \t\t\t\t\t\t\t\t\t\!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!      ";
    int choice,admin;
    printf("\n\n\n      \t\t\t\t\t\t\t press 1 if you are admin.\n"
           "        \t\t\t\t\t\t press 2 if you are user\n");
    cin>>admin; //input is taken in the variable

    switch(admin)//switch case
    {
        case 1:
            login();    //function called
        break;
        case 2:
            user();    //function called
        break;
       /* case 3:
            update();
         break;
        case 4:
            check();
        break;*/
    }

}
void login()//function defined
{
    system("cls");//previous outputs on screen are cleared
    cout<<"\t\t\t\t\t\twelcome,have a nice day\n";

    char id[6]="yb112";//value is initialized in character array
    char pass[9]="12345678";//value is initialized in character array
    label ://label declared
        //two uninitialized character arrays are declared ,to be used for input
        char id1[6];
        char pass1[9];
        cout<<"Enter i.d:\t";
        cin>>id1;//input is taken in character array
        if(strcmp(id,id1)!=0)//comparision of two strings in a conditional statement
    {
        cout<<"wrong admin id:";
        int count=0;//variable declared and initialized used to clear screen
        count++;//variable is increamented
        if(count!=0)//conditional statement
        {system("cls");
        }

    }
    else{
            cout<<"Enter Password:";
        cin>>pass1;
    if(strcmp(pass1,pass)==0)//two strings are compared in conditional statement
            {system("cls");
                    admin();//function called
                    }

    else{
        cout<<"you entered a wrong password";
        goto label;//compiler is sent to label
    }
}
}

//enter() function start
int enter()//function defined
{
   details c;
    ofstream fw("recep.dat",ios::binary | ios::app);//file is opened in order to write
    if(!fw){
        cout<<"error in opening file";
    }

    else{
        system("cls");//previous outputs on screen are cleared
        if(slot!=0){
        char wish='y';
        while(wish=='y'){
                //various inputs are taken and stored in file
        cout<<"Enter the details of the recepient\n";
        cout<<"aadhar no:";
        cin>>c.aadhar;
        cout<<"name:";
        getchar();
        scanf("%[^\n]%*c",c.name);
        cout<<"gender:";
        cin>>c.gender;
        cout<<"age:";
        cin>>c.age;
        slot--;
        fw.write((char *)&c, sizeof(c));//data is written in file
        fw.close();//file is closed
        system("cls");
         cout<<"\nyour slot has been booked";
        cout<<"\n\ndo you want to book more slots y or n?";
        cin>>wish;
        }
        if (wish=='n')//conditional statement
        {
         admin();//function call
         }

        if(slot==0)//conditional statement
        {
            cout<<"no of slots are full:";
        }
        }
    }

    return 0;//end of code in this function
}//enter() function end

//display() function start
int display()
{
    details c;
    ifstream fr("recep.dat",ios::binary | ios::in);
    if(!fr){
        cout<<"error in opening file";
    }
    else{
            system("cls");
        cout<<"_________________________________________________________________________\n";
        cout<<"aadhar"<<"\t" "\t" "|"<<"name"<<"\t" "\t" "|" <<"gender"<<"\t" "\t" "|"<<"age"<< endl;
        cout<<"________________________________________________________________________\n";
        while(fr.read((char *)&c, sizeof(c))){
        cout<<c.aadhar<<"\t" "\t""|"<<c.name <<"\t" "\t""|"<<c.gender<<"\t" "\t""|"<<c.age<<endl;}
        cout<<"do you want to continue further y or n\n";
        char choice1;
        cin>>choice1;
        system("cls");   //previous outputs on screen are cleared
        switch(choice1)
        {
         case 'y': admin();//admin() function called
          break;
         case 'n': exit(0);//exit
          break;
        }
        fr.close();//file is closed
    }

    return 0;//end of code in this function
}   //display function end

//update() function starts
int  update()
{
    details c;
        ofstream fu("recep.dat",ios::binary | ios::out);    //file is opened to clear data and overwrite
    int newslot;//variable declared
    cout<<"\nupdate number of slots:\n";
    cout<<"new slots = ";
    cin>>newslot;
    slot=slot+newslot;      //value of slot variable is updated
    fu.write((char *)&slot, sizeof(c));     //file is cleared and new data is overwrite
    cout<<"\n\nno of slots updated.";
    cout<<"\npress 1 if you want to continue:";
    int t;
    cin>>t;
    if (t==1)   //conditonal statement
    {
        admin();
    }//end of if
  else
  {
      exit(0);  //exit
  }     //end of else
  fu.close();       //file is closed
}// end of display() function

// admin() function start
void admin()
{
    system("cls");//previous outputs on screen cleared
     int k;//integer variable declared
        printf("1.enter details to book slot.\n"
               "2.view previous booking records.\n"
               "3.update number of slots.\n");
      cin>>k;
      switch(k)
      {
          case 1: enter();
           break;
          case 2: display();
           break;
         /* case 3: check();
           break;*/
          case 3: update();
           break;
      }
    }//admin function end

//user() function start
void user(){
    details c;
 ofstream fk("recep.dat",ios::binary | ios::app);//file is opened to write and add data
    if(!fk){
        cout<<"error in opening file";
    }

    else{
     if(slot!=0){
        system("cls");  //previous outputs on screen are cleared
        char wish='y';
        while(wish=='y'&&slot!=0){
                //various inputs are taken
        cout<<"Enter the details of the recepient\n";
        cout<<"aadhar no:";
        cin>>c.aadhar;
        cout<<"name:";
        getchar();
        scanf("%[^\n]%*c",c.name);
        cout<<"gender:";
        cin>>c.gender;
        cout<<"age:";
        cin>>c.age;
        //slot--;//slot variable is decreamented
        fk.write((char *)&c, sizeof(c));//data is written in file
        slot--;
        fk.close();
        system("cls");  //previous outputs on screen are cleared
         cout<<"\nyour slot has been booked";
         exit(0);//exit from while
        }//end of while
     }//end of if
   }//end of else
}//user() function end
