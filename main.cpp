//Linda Salazar
//Dr. Tyson Mcmillan
//COSC 1437-58002
//4-24-2024
#include <iostream>
#include <string>
#include "Input_Validation_Extended.h"
using namespace std;

class Team
{
  private:
    int score;
    bool homeStatus;
    int TimeOut;
    string name;
    string coachName;
    string homeCity;
    string visitorCity;

  public:
    Team()//default constructor
    {
      score = 0; 
      homeStatus = true; //visitor = false, home = true
      TimeOut = 0; 
      name = "DefaultName";
      coachName = "DefaultCoachName";
      homeCity = "DefaultHomeCity";
      visitorCity = "DefaultVisitorCity";
    }
    void setScore(int s) { score = s; }
    void setHomeStatus(bool hs) { homeStatus = hs; }
    void setTimeOut(int TO) { TimeOut = TO; }
    void setName(string n) { name = n; }
    void setCoachName(string cN) { coachName = cN; }
    void setHomeCity(string hC) { homeCity = hC; }
    void setVisitorCity(string vC) { visitorCity = vC; }
    int getScore() const { return score; }
    bool getHomeStatus() const { return homeStatus; }
    int getTimeOut() const { return TimeOut; }
    string getName() const { return name; }
    string getCoachName() const { return coachName; }
    string getHomeCity() const { return homeCity; }
    string getVisitorCity() const { return visitorCity; }


};

class Scoreboard
{
  private:
    int min;
    int sec;
    int quarter;
    Team home; //object home is of data type Team 
    Team guest; //object guest is of data type Team
  public:
    Scoreboard()
    {min = 0; sec = 0; quarter = 1; home = Team(); guest = Team();}
    void setMin(int m) { min = m; }
    void setSec(int s) { sec = s; }
    void setQuarter(int h) { quarter = h; }
    void setHome(Team hSet) { home = hSet; }
    void setGuest(Team gSet) { guest = gSet; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
    int getQuarter() const { return quarter; }
    Team getHome() const { return home; }
    Team getGuest() const { return guest; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "Football Scoreboard" << reset << endl; 
      cout << home.getName() << "\t\t    " << guest.getName() << endl;
      cout << home.getHomeCity() << "\t\t    " << guest.getVisitorCity() << endl;
      cout << "\t\t\t" << min << ":" << sec << endl;
      cout << "\t" << home.getScore() << "\t\t\t\t\t" << guest.getScore() << endl;
      cout << "\t\t\tQUARTER: " << quarter << endl;
      cout << "\t" << home.getTimeOut() << " TO\t\t\t\t\t TO " << guest.getTimeOut() << endl;
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
      cout << score << home.getCoachName() << reset << "\t\t" << guest.getCoachName() << endl; 

         //proces to show the home team status
         cout << "Home Status: \t"; 
         if(home.getHomeStatus() == true)
         {
           cout << "Team 1: " << home.getName() << "*"; 
         }
         else if(guest.getHomeStatus() == true)
         {
           cout << "Team 2: " << guest.getName() << "*"; 
         }
         else
         {
           cout << "Error: "; 
         }

         cout  << endl; 
      }
    
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo;
  char choice = '\0';
  string newName = "";
  string newCoachName = "";
  string newHomeCity = "";
  int newScore = 0;
  int newTimeOut = 0;
  int newGuestTO = 0;
  string newVisitorCity = "";
  int newQuarter = 0;
  int newMin = 0;
  int newSec = 0;
  

  s.setHome(tOne); //add default data to the scoreboard
  s.setGuest(tTwo); //add default data to the scoreboard

  do
  {
    s.showScoreboard();
    cout << "\nMenu: " << endl;
    cout << "A. Update Home Team Name" << endl;
    cout << "B. Update Home Team City" << endl;
    cout << "C. Update Home Team Score" << endl;
    cout << "D. Update Home Team TimeOuts" << endl;
    cout << "E. Update Guest Team Name" << endl;
    cout << "F. Update Guest Team City" << endl;
    cout << "G. Update Guest Team Score" << endl;
    cout << "H. Update Guest Team TimeOuts" << endl;
    cout << "I. Update Home Team Coach Name" << endl;
    cout << "J. Update Guest Team Coach Name" << endl;
    cout << "K. Update Quarter" << endl;
    cout << "L. Update Minutes" << endl;
    cout << "M. Update Seconds" << endl;
    cout << "X. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;
    if(choice == 'A' || choice == 'a')
    {
      cout << "Enter a name for the home team: ";
      cin >> newName;
      tOne.setName(newName); // tOne.setName(newName);
    }
    else if(choice == 'B' || choice == 'b')
    {
      cout << "Enter a city for home team: ";
      cin >> newHomeCity;
      tOne.setHomeCity(newHomeCity); 
    }
    else if(choice == 'C' || choice == 'c')
    {
      cout << "Enter a score for the home team: ";
      cin >> newScore;
      tOne.setScore(newScore); 
    }
    else if(choice == 'D' || choice == 'd')
    {
      cout << "Enter timeouts for home team: ";
      cin >> newTimeOut;
      tOne.setTimeOut(newTimeOut); 
    }
    else if(choice == 'E' || choice == 'e')
    {
      cout << "Enter a name for the guest team: ";
      cin >> newName;
      tTwo.setName(newName); 
    }
    else if(choice == 'F' || choice == 'f')
    {
      cout << "Enter a city for the guest team: ";
      cin >> newVisitorCity;
      tTwo.setVisitorCity(newVisitorCity); 
    }
    else if(choice == 'G' || choice == 'g')
    {
      cout << "Enter a score for the guest team: ";
      cin >> newScore;
      tTwo.setScore(newScore);
    }
    else if(choice == 'H' || choice == 'h')
    {
      cout << "Enter timeouts for guest team: ";
      cin >> newGuestTO;
      tTwo.setTimeOut(newGuestTO);
    }
    else if(choice == 'I' || choice == 'i')
    {
      cout << "Enter a coach name for the home team: ";
      cin >> newCoachName;
      tOne.setCoachName(newCoachName);
    }
    else if(choice == 'J' || choice == 'j')
    {
      cout << "Enter a coach name for the guest team: ";
      cin >> newCoachName;
      tTwo.setCoachName(newCoachName);
    }
    else if(choice == 'K' || choice == 'k')
    {
      cout << "Enter a quarter: ";
      cin >> newQuarter;
      s.setQuarter(newQuarter);
    }
    else if(choice == 'L' || choice == 'l')
    {
      cout << "Enter a minute: ";
      cin >> newMin;
      s.setMin(newMin);
    }
    else if(choice == 'M' || choice == 'm')
    {
      cout << "Enter a second: ";
      cin >> newSec;
      s.setSec(newSec);
    }
    else if(choice == 'X' || choice == 'x')
    {
      cout << "Exiting" << endl;
    }



    s.setHome(tOne); //refresh the data in s to the new updates...
    s.setGuest(tTwo); //refresh the data in s to the new updates...
    cout << "\033[2J\033[1;1H"; //clear screen
  }while(choice != 'x' && choice != 'X');
  
  return 0;
}