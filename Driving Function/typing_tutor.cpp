#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include "letters.h"
#include "Words.h"
#include "Sentences.h"
#include "users.h"
#include <string>
using namespace std;
class Tutorial{
public:
user::User recent_user;
Letter::letter tuto_letter;
word::Word tuto_word;
sentence::sentence tuto_sentence;
bool new_user_1=true;
bool new_user_2=true;
bool new_user_3=true;
Tutorial(){}
void delay(int mill)
    {
        for(int i=0;i<mill;i++);
    }
void gotoxy(int x, int y)
    {
            system("cls");
            for(int j=0;j<x+2;j++)
            cout<<"\n";
            for(int j=0;j<y+2;j++)
            cout<<"\t";
    }
void show_menu()
{
    gotoxy(1,4);
    cout<<"MENU\n";
    cout<<"\t\t\t";
    for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n";
    cout<<"\t\t\t*";
    cout<<"\t Select your difficulty level \t";
    cout<<"\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
    cout<<" 1 for EASY! ";
    cout<<"\t\t\t\t\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
    cout<<" 2 for MEDIUM!! ";
    cout<<"\t\t\t\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
    cout<<" 3 for HARD!!! ";
    cout<<"\t\t\t\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t";
     for(int i=0;i<50;i++)
        cout<<"*";
    cout<<"\n\n Press any key to Quit!"<<endl;
}
void display(string user_name)
{
	system("cls");
    gotoxy(6,6);
    if(new_user_1 || new_user_2 || new_user_3)
            cout<<"Hello "<<user_name<<"!!!!\n Press any key to begin\n";
    else
        cout<<"Welcome Back "<<user_name<<"!!!!\n Press any key to begin\n";
    _getch();
    system("cls");
}
void display()
{
	gotoxy(1,4);
    cout<<"Hello and Welcome To TYPING TUTOR......"<<endl;
    delay(50000000);
    string user_name;
    valid_name:
        try{
    cout<<"Enter name...(MAX. FOUR Letters Name)"<<endl;
    getline(cin, user_name);
    if(strlen(user_name.c_str())>4)
    {
        throw 10;
    }
    }
    catch(...)
       {
           system("cls");
           gotoxy(12,4 );
        cout<<"Please Enter a valid name.....";
        delay(400000000);
        system("cls");
        goto valid_name;
        }

    recent_user=user::User(user_name,0.0,0);
    if(recent_user.retrieve(user_name,1))
        {
            new_user_1=false;
        }
    if(recent_user.retrieve(user_name,2))
        {
            new_user_2=false;
        }
    if(recent_user.retrieve(user_name,3))
    {
        new_user_3=false;
    }

    display(user_name);

}
};
int main()
{
   Tutorial New;
	New.display();
	New.gotoxy(1,4);
	New.show_menu();
    int ch1;
    cin>>ch1;
    system("cls");
    switch(ch1)
    	{
    		case 1:
    			system("cls");
    			New.tuto_letter.Intro_letters();
            cout<<"\n\n\n\n\t\t\t\tPress 'S' to see the scoreboard.\n\n\n\n\t\t\t\tPress Any Key To Continue..........";
            char option1;
            cin>>option1;
            if(option1=='S' || option1=='s')
            {New.recent_user.retrieve(1);
                return 0;
            }
    			New.tuto_letter.show_letters();
    			//add user score to the csv file
                New.recent_user=user::User(New.recent_user.get_Name(),New.tuto_letter.avg_time,New.tuto_letter.score);
    			if(New.new_user_1){
                    New.recent_user.store(1);
                    New.new_user_1=false;
    			}
    			else
                {
                    New.recent_user.update(1);
                }
                cout<<"\n\t\t\tFOR LEVEL 1"<<std::endl;
                New.recent_user.retrieve(1);
    			cout<<"\n\n\n\t\t\t\tPress 1 to proceed to the next level\n\t\t\t\t\t\tOR Press any key to quit\n";
    			int ch2;
				cin>>ch2;
				if(ch2!=1)
				{
				    cout<<"Thank You For Playing!!! "<<endl;
					return 0;
				}
			case 2:
				New.tuto_word.Intro_words();
                cout<<"\n\n\n\n\t\t\t\tPress 'S' to see the scoreboard.\n\n\n\n\t\t\t\tPress Any Key To Continue..........";
                char option2;
                cin>>option2;
                if(option2=='S' || option2=='s')
                {New.recent_user.retrieve(2);
                    return 0;
                }
				New.tuto_word.show_words();

				//add new score
                New.recent_user=user::User(New.recent_user.get_Name(),New.tuto_word.avg_time,New.tuto_word.score);
				if(New.new_user_2){


                    New.recent_user.store(2);
                    New.new_user_2=false;
    			}
    			else
                {

                    New.recent_user.update(2);
                }
                cout<<"\n\t\t\tFOR LEVEL 2"<<std::endl;
                New.recent_user.retrieve(2);

    			cout<<"\n\n\n\t\t\t\tPress 1 to proceed to the next level\n\t\t\t\t\t\tOR Press any key to quit\n";
    			int ch3;
				cin>>ch3;
				if(ch3!=1)
				{
				    cout<<"Thank You For Playing!!! "<<endl;

					return 0;
				}
			case 3:
				New.tuto_sentence.Intro_sentences();
                cout<<"\n\n\n\n\t\t\t\tPress 'S' to see the scoreboard.\n\n\n\n\t\t\t\tPress Any Key To Continue..........";
                char option3;
                cin>>option3;
                if(option3=='S' || option3=='s')
                {New.recent_user.retrieve(3);
                    return 0;
                }
				New.tuto_sentence.show_sentences();
                New.recent_user=user::User(New.recent_user.get_Name(),New.tuto_sentence.avg_time,New.tuto_sentence.score);
				//add new score
				if(New.new_user_3){
                    New.recent_user.store(3);
                    New.new_user_3=false;
    			}
    			else
                {

                    New.recent_user.update(3);
                }
                cout<<"\n\t\t\tFOR LEVEL 3"<<std::endl;
                New.recent_user.retrieve(3);


    			cout<<"Thank You For Playing!!! "<<endl;

					return 0;
				default:
				    cout<<"\n\n\t\t QUITTING.....";
					return 0;
		}
    return 0;
}
