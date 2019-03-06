#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<cstring>
using namespace std;
namespace Letter
{
    class letter
{
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


    public:
    double avg_time;
    int score;
    letter()
    {
        avg_time=0;
        score=0;
    }
    void Intro_letters()
    {
        gotoxy(14,6);
        cout<<"The Game is about to begin......"<<endl;
        delay(20000);
        gotoxy(1,2);
        cout<<" GET READY TO TEST YOUR TYPING SKILLS\n";
        cout<<"\t\t\t";
        for(int i=0;i<50;i++)
            cout<<"*";
        cout<<"\n";
        cout<<"\t\t\t*";
        cout<<"  10 LETTERS WILL BE DISPLAYED ON YOUR SCREEN.";
        cout<<"\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
        cout<<" YOU HAVE TO ENTER THAT LETTER AND PRESS ENTER.* ";
        cout<<" \n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
        cout<<" MAXIMUM SCORE IS 10. ";
        cout<<"\t\t\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t";
        for(int i=0;i<50;i++)
            cout<<"*";
    }
    void show_letters()
    {
        score=0;
        char entered[15];
        avg_time=0;
        time_t start,ends;
        for(int i=1;i<=10;i++)
        {
            srand(time(0));
            int ch=65+rand()%25;
            char ch1=(char)ch;
            gotoxy(rand()%12,rand()%12);
            cout<<ch1<<"\t";
            time(&start);
            gets(entered);
            if(i==1)
                gets(entered);
            time(&ends);
            avg_time+=((difftime(ends,start))/10);
            if(strlen(entered)==1 && ch1==entered[0])
            {
                gotoxy(12,12);
                cout<<"CORRECT";
                score++;
                delay(500000000);
            }
            else
            {
                gotoxy(12,12);
                cout<<"INCORRECT ";
                cout<<(char)ch<<":"<<entered;
                delay(500000000);
            }

        }
        gotoxy(2,2);
        cout<<"Your Score is "<<score<<" out of 10"<<endl;
        cout<<"Average Time Per Letter is "<<avg_time<<" Seconds"<<endl;
        delay(200);
        cout<<"Enter Any Key To Continue..........";

    }
};
};
