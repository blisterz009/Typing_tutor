#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;
namespace sentence
{
    class sentence{
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
    void Intro_sentences()
    {
        gotoxy(14,6);
        cout<<"The Game is about to begin......"<<endl;
        delay(20000);
        gotoxy(1,2);
        cout<<" GET READY TO TEST YOUR TYPING SKILLS\n";
        cout<<"\t\t\t";
        for(int i=0;i<52;i++)
            cout<<"*";
        cout<<"\n";
        cout<<"\t\t\t*";
        cout<<"  10 SENTENCES WILL BE DISPLAYED ON YOUR SCREEN.";
        cout<<"  *\n \t\t\t* \t\t\t\t\t\t   * \n \t\t\t* ";
        cout<<" YOU HAVE TO ENTER THAT SENTENCE AND PRESS ENTER.*";
        cout<<"\n \t\t\t* \t\t\t\t\t\t   * \n \t\t\t* ";
        cout<<" MAXIMUM SCORE IS 10. ";
        cout<<"\t\t\t   *\n \t\t\t* \t\t\t\t\t\t   * \n \t\t\t";
        for(int i=0;i<52;i++)
            cout<<"*";
    }
    void show_sentences()
    {

        score=0;
        avg_time=0;
        fstream fin;
        fin.open("sentences.csv",ios::in);
        char entered[100];
        time_t start,ends;
        for(int i=1;i<=10;i++)
        {
            srand(time(0));
            string Sentence1;
            fin.seekg(ios::beg);
            int sentence_choose=1+rand()%37;
            for(int j=0;j<sentence_choose;j++)
            {
                Sentence1="";
                getline(fin,Sentence1,'\n');
            }

            gotoxy(rand()%12,rand()%12);
            cout<<Sentence1<<"\t";
            time(&start);
            gets(entered);
            if(i==1)
                gets(entered);
            time(&ends);
            avg_time+=((difftime(ends,start))/4);
            if(!strcmp(Sentence1.c_str(),entered))
            {
                gotoxy(12,12);
                cout<<"CORRECT";
                score++;
                delay(800000000);
            }
            else
            {
                gotoxy(12,12);
                cout<<"INCORRECT ";
                cout<<Sentence1<<":"<<entered;
                delay(800000000);
            }
        }
        gotoxy(2,2);
        cout<<"Your Score is "<<score<<" out of 10"<<endl;
        cout<<"Average Time Per Sentence is "<<avg_time<<" Seconds"<<endl;
        delay(200);
        fin.close();
        cout<<"Enter Any Key To Continue..........";

    }
    };
}
