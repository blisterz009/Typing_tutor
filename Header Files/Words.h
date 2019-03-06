#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
namespace word
{
    class Word{
        public:
    int score=0;
    double avg_time=0;
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
    void Intro_words()
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
        cout<<"  10 WORDS WILL BE DISPLAYED ON YOUR SCREEN.";
        cout<<"\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
        cout<<" YOU HAVE TO ENTER THAT WORD AND PRESS ENTER. ";
        cout<<" *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t* ";
        cout<<" MAXIMUM SCORE IS 10. ";
        cout<<"\t\t\t *\n \t\t\t* \t\t\t\t\t\t * \n \t\t\t";
        for(int i=0;i<50;i++)
            cout<<"*";
    }
    void show_words()
    {
        score=0;
        avg_time=0;
        fstream fin;
        fin.open("words.csv",ios::in);
        char entered[12];
        time_t start,ends;
        for(int i=1;i<=10;i++)
        {
            srand(time(0));
            string Word;
            fin.seekg(ios::beg);
            int word_choose=1+rand()%54;
            for(int j=0;j<word_choose;j++)
            {
                Word="";
                getline(fin,Word,'\n');
            }
            gotoxy(rand()%12,rand()%12);
            cout<<Word<<"\t";
            time(&start);
            gets(entered);
            if(i==1)
                gets(entered);
            time(&ends);
            avg_time+=((difftime(ends,start))/10);
            if(!strcmp(Word.c_str(),entered))
            {
                gotoxy(12,12);
                cout<<"CORRECT";
                score++;
                delay(500000000);
            }
            else
            {
                gotoxy(12,12);
                cout<<"INCORRECT "<<Word<<":"<<entered;
                delay(500000000);
            }
        }
        gotoxy(2,2);
        cout<<"Your Score is "<<score<<" out of 10"<<endl;
        cout<<"Average Time Per Word is "<<avg_time<<" Seconds"<<endl;
        delay(200);
        fin.close();
        cout<<"Enter Any Key To Continue..........";

    }
    };
}
