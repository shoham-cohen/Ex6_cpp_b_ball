#include "Schedule.hpp"

using namespace std;
using namespace Ex6;

int main(){

    League* league;
    league = new League();
    cout<<"\n"<<endl;
    Schedule* schedule;
    schedule = new Schedule(league);
    schedule->Start_simulating();
    schedule-> get_League()-> Print_league_stats();
    return 0;
}