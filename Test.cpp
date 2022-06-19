#include "doctest.h"
#include <iostream>
#include <vector>

#include "Schedule.hpp"

using namespace std;
using namespace Ex6;

League* league;
league = new League();
Schedule* schedule;
schedule = new Schedule(league);

TEST_CASE("names and talent"){

    CHECK_EQ(league.get_Teams().size(), 20);
    vector<Team*> teams = league.get_Teams();
        for (int i = 0; i < league.get_Teams().size() - 1; i++){
            for (int j = i; j < league.get_Teams().size(); j++){
            CHECK_FALSE(teams.at(i)->get_name() == teams.at(i+1)->get_name());
            CHECK(league.get_Teams().at(i)->getTalent() >= 0); 
            CHECK(league.get_Teams().at(i)->getTalent() <= 1);
            }
        } 
    }

TEST_CASE("game result"){
    Team *home = league ->get_Team(1);
    Team *away = league-> get_Team(2);
    Game game1{home, away};
    CHECK_EQ(home-> get_losses(), 0);
    CHECK_EQ(away-> get_wins(), 0);
    CHECK_EQ(home-> get_points_gap(), 0);
    CHECK_EQ(away-> get_points_gap(), 0);
    game1-> start_game();
    CHECK(home-> get_wins() != away-> get_wins());
    CHECK(home -> get_losses() != away-> get_losses());
    CHECK(home-> get_points_gap() != away-> get_points_gap());
    if(home-> get_losses() == 1){
        CHECK(home-> get_points_gap() < 0);
        CHECK(away-> get_points_gap() > 0);
    }
    else{
        CHECK(away-> get_points_gap() < 0);
        CHECK(home-> get_points_gap() > 0);
    }
}

