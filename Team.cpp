#include "Team.hpp"

using namespace std;

namespace Ex6{
    Team::Team(){
        this-> name = "";
        this-> talent = 0.0;
        this-> wins = 0;
        this-> losses = 0;
        this-> points_gap = 0;
        this-> curr_win_streak = 0;
        this-> curr_loss_streak = 0;
        this-> longest_win_streak = 0;
        this-> longest_loss_streak = 0;
        this-> points_scored = 0;
        this-> points_scored_on = 0;
    }

    Team::Team(string name){
        this-> name = name;
        this-> talent = this->randomTalent();
        this-> wins = 0;
        this-> losses = 0;
        this-> points_gap = 0;
        this-> curr_win_streak = 0;
        this-> curr_loss_streak = 0;
        this-> longest_win_streak = 0;
        this-> longest_loss_streak = 0;
        this-> points_scored = 0;
        this-> points_scored_on = 0;
    }

    string Team::get_name(){
        return name;
    }

    int Team::get_home_score(){
        return rand()%46+45;
    }
        
    int Team::get_away_score(){
        return rand()%51+40;
    }

    void Team::add_points_scored(int points){
        points_scored += points;
    }

    void Team::add_points_scored_on(int points){
        points_scored_on += points;
    }

    double Team::ppg(){
        return (double)points_scored/38;
    }

    double Team::oppg(){
        return (double)points_scored_on/38;
    }
    
    void Team::set_name (string name){
        this-> name = name;
    }

    float Team::get_talent(){
        return this-> talent;
    }

    void Team::set_talent(float talent){
        this-> talent = talent;
    }

    int Team::get_wins(){
        return this-> wins;
    }

    int Team::get_losses(){
        return this-> losses;
    }

    int Team::get_points_gap(){
        return this-> points_gap;
    }

    void Team::add_win(){
        this->wins++;
        this-> curr_loss_streak = 0;
        this->curr_win_streak++;
        if(curr_win_streak > longest_win_streak){
            longest_win_streak = curr_win_streak;
        }
    }

    void Team::add_loss(){
        this->losses++;
        this-> curr_win_streak = 0;
        this->curr_loss_streak++;
        if(this-> curr_loss_streak > this-> longest_loss_streak){
            this-> longest_loss_streak = this-> curr_loss_streak;
        }
    }

    void Team::update_points_gap(int OP, int TP){
        this-> points_gap = this-> points_gap + TP - OP;
    }

    int Team::get_longest_win_streak(){
        return this-> longest_win_streak;
    }
    
    int Team::get_longest_loss_streak(){
        return this-> longest_loss_streak;
    }

    float Team::randomTalent(){
        return rand()%11/10.0;
    }
}