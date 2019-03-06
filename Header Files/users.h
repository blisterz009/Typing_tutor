#include<iostream>
#include<fstream>
#include<stdio.h>//FOR rename() in update()
#include<sstream>//stringstream
#include<conio.h>
namespace user{
class Score
{
public:
    double time_score;
    int accuracy;
    void set_values(double t,int acc)
    {
        time_score=t;
        accuracy=acc;
    }
};
class User
{
public:
    Score user_score;
    std::string user_name;
    User(){}
    User(std::string name,double time, int acc){    // Function To initialize Objects From outside the class
        std::fstream fin;
        fin.open("HS_letter.csv",std::ios::app);
        fin.close();
        fin.open("HS_word.csv",std::ios::app);
        fin.close();
        fin.open("HS_sentence.csv",std::ios::app);
        fin.close();
        user_name=name;
        user_score.set_values(time,acc);
        }
    void store(int);//For new users
    void retrieve(int);// To Display the total Score Card
    bool retrieve(std::string,int);// To check if a user ,by giving user_name, has ever played the game with that user_name
    void update(int);// To Update The Score Of A Existing user
    void challenge_score(User*,int);// To maintain the High Score PS:This is not to display the high score. HIGH SCORE IS DISPLAYED AUTOMATICALLY WHEN A PLAYER FINISHES PLAYING.
    std::string get_Name(){return this->user_name;}// Just a Utility to get the user_name outside of the class

};
void User::challenge_score(User *hs,int difficulty)
{
    char * fileName;
    if(difficulty==1)
        fileName="HS_letter.csv";
    else if(difficulty==2)
        {
            fileName="HS_word.csv";
        }
    else if(difficulty==3)
        {
            fileName="HS_sentence.csv";
        }
    User High_Scorer;
    std::fstream fin;
    fin.open(fileName,std::ios::in | std::ios::app);
    std::string temp;
    fin.seekg(0,std::ios::end);
    if(fin.tellg()==0)
    {
        {
            std::fstream fin1;
            fin1.open(fileName,std::ios::out);
            std::cout<<"\n\t\t\tCONGRATULATION\n\t\tYOU ARE THE HIGHEST SCORER OF LEVEL "<<difficulty<<"!"<<std::endl;
            fin1<<hs->user_name<<","<<hs->user_score.time_score<<","<<hs->user_score.accuracy<<"\n";
            fin1.close();

        }

    }
    else
    {   fin.seekg(0,std::ios::beg);
        getline(fin,temp,',');
        High_Scorer.user_name=temp;
        getline(fin,temp,',');
        std::stringstream ss(temp);
        ss >> High_Scorer.user_score.time_score;
        getline(fin,temp,'\n');
        std::stringstream ss1(temp);
        ss1>>High_Scorer.user_score.accuracy;
        if(High_Scorer.user_score.accuracy < hs->user_score.accuracy)
        {
            std::cout<<"\n\t\t\tCONGRATULATION\n\t\tYOU ARE THE HIGHEST SCORER OF LEVEL "<<difficulty<<"!"<<std::endl;
            {
            std::fstream fin1;
            fin1.open(fileName,std::ios::out);
            fin1<<hs->user_name<<","<<hs->user_score.time_score<<","<<hs->user_score.accuracy<<"\n";
            fin1.close();
            }

        }
        else if(High_Scorer.user_score.accuracy == hs->user_score.accuracy)
        {
            if(High_Scorer.user_score.time_score > hs->user_score.time_score)
            {
                std::cout<<"\n\t\t\tCONGRATULATION\n\t\tYOU ARE THE HIGHEST SCORER OF LEVEL "<<difficulty<<"!"<<std::endl;
                {
                    std::fstream fin1;
                    fin1.open(fileName,std::ios::out);
                    fin1<<hs->user_name<<","<<hs->user_score.time_score<<","<<hs->user_score.accuracy<<"\n";
                    fin1.close();
                }

            }
            else
            {
                std::cout<<"\n\tHIGHEST SCORER IS "<<High_Scorer.user_name<<" WITH ACCURACY "<<High_Scorer.user_score.accuracy<<" AND TIME AVERAGE "<<High_Scorer.user_score.time_score<<std::endl;
            }
        }
        else
        {
            std::cout<<"\n\tHIGHEST SCORER IS "<<High_Scorer.user_name<<" WITH ACCURACY "<<High_Scorer.user_score.accuracy<<" AND TIME AVERAGE "<<High_Scorer.user_score.time_score<<std::endl;
        }
    }
    std::cout<<"Press any key.......";
    _getch();

    fin.close();
}
void User::store(int difficulty)
{
    char * fileName;
    if(difficulty==1)
        fileName="letters_Score.csv";
    else if(difficulty==2)
        fileName="words_Score.csv";
    else if(difficulty==3)
        fileName="sentences_Score.csv";

    std::fstream fin;
    fin.open(fileName,std::ios::app);
    fin<<user_name<<","<<user_score.time_score<<","<<user_score.accuracy<<"\n";
    fin.close();
    challenge_score(this,difficulty);
}

void User::retrieve(int difficulty)
{
    char * fileName;
    if(difficulty==1)
        fileName="letters_Score.csv";
    else if(difficulty==2)
        fileName="words_Score.csv";
    else if(difficulty==3)
        fileName="sentences_Score.csv";
    std::fstream fin;
    fin.open(fileName,std::ios::in);
    if(fin){
    std::string temp;
    std::cout<<"\n\t\t\SCOREBOARD"<<std::endl;
    std::cout<<"NAME\t\tTIME\t\tSCORE"<<std::endl;

    while(fin)
    {
        std::getline(fin,temp,',');
        std::cout<<temp<<"\t\t";
        std::getline(fin,temp,',');
        std::cout<<temp<<"\t\t";
        std::getline(fin,temp,'\n');
        std::cout<<temp<<"\n";
    }
    }
    fin.close();
}

bool User::retrieve(std::string name,int difficulty)
{
    char * fileName;
    if(difficulty==1)
        fileName="letters_Score.csv";
    else if(difficulty==2)
        fileName="words_Score.csv";
    else if(difficulty==3)
        fileName="sentences_Score.csv";

    std::fstream fin;
    fin.open(fileName,std::ios::in);
    std::string temp;
    while(fin)
    {
        std::getline(fin,temp,',');
        if(temp==name)
            return true;
        else
            std::getline(fin,temp,'\n');
    }
    fin.close();
    return false;
}

void User::update(int difficulty)
{
    char * fileName;
    if(difficulty==1)
        fileName="letters_Score.csv";
    else if(difficulty==2)
        fileName="words_Score.csv";
    else if(difficulty==3)
        fileName="sentences_Score.csv";

    std::fstream fin,fout;
    fin.open(fileName,std::ios::in);
    fout.open("usersnew.csv",std::ios::out);
    std::string temp;
    int  i=0,j=0;

    while(fin)
    {
        i++;
        std::getline(fin,temp,',');
        if(temp==user_name)
            break;
        else
            std::getline(fin,temp,'\n');
    }
    fin.close();
    fin.open(fileName,std::ios::in);
    while(fin)
        {
            j++;
        if(i==j)
        {
            std::getline(fin,temp,'\n');
            fout<<user_name<<","<<user_score.time_score<<","<<user_score.accuracy;//"\n";
        }
        else
        {
            std::getline(fin,temp,'\n');
            fout<<temp<<'\n';

        }
    }
    fin.close();
    fout.close();
    remove(fileName);
    rename("usersnew.csv",fileName);
    challenge_score(this,difficulty);
}
}
