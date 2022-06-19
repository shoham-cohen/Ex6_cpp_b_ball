#include "Game.hpp"

using namespace std;

namespace Ex6{

    Game::Game(Team *home_team, Team *away_team){
        this->home_team = home_team;
        this->away_team = away_team;
        this->winning_team = NULL;
    }

    Team *Game::start_game(){
        int home_res = this->home_team->get_home_score();
        int away_res = this->away_team->get_away_score();

        if(home_team-> get_talent() >= away_team-> get_talent()){
             home_res += 10;
        }
        else{
            away_res += 10;
        }

        if(home_res > away_res){
            winning_team = home_team;
            home_team-> add_win();
            away_team-> add_loss();
        }

        else if(home_res < away_res){
            winning_team = away_team;
            home_team-> add_loss();
            away_team-> add_win();
        }

        else{ //draw
            int tie_break = rand()%46+55;
            if(tie_break <= 65){
                home_team-> update_points_gap(1, 0);
                away_team-> update_points_gap(0,1);
                winning_team = away_team;
                home_team-> add_loss();
                away_team-> add_win();
            }
            else{
                away_team-> update_points_gap(1, 0);
                home_team-> update_points_gap(0,1);
                winning_team = home_team;
                home_team-> add_win();
                away_team-> add_loss();
            }
        }

        home_team-> update_points_gap(away_res, home_res);
        away_team-> update_points_gap(home_res, away_res);
        home_team-> add_points_scored(home_res);
        home_team-> add_points_scored_on(away_res);
        away_team-> add_points_scored(away_res);
        away_team-> add_points_scored_on(home_res);
        if(home_res != away_res){
            cout << home_team-> get_name() << "  " << home_res << "  " << away_team-> get_name() << "  " <<away_res <<"\n";
        }
        else{
            cout << home_team-> get_name() << "  "<< home_res << "  "<< away_team-> get_name() << "  "<<away_res;
            cout << " " << winning_team-> get_name() << " won in overtime" <<"\n";

        }

        return winning_team;
    }
}