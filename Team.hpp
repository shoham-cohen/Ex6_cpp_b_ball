#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

namespace Ex6{

    class Team{
    private:
        string name;
        float talent;
        int wins;
        int losses;
        int points_gap;
        int curr_win_streak;
        int curr_loss_streak;
        int longest_win_streak;
        int longest_loss_streak;
        int points_scored;
        int points_scored_on;

    public:
        Team();
        Team(string name);
        string get_name();
        int get_home_score();
        int get_away_score();
        void add_points_scored(int points);
        void add_points_scored_on(int points);
        double ppg();
        double oppg();
        void set_name (string name);
        float get_talent();
        void set_talent(float talent);
        int get_wins();
        int get_losses();
        int get_points_gap();
        int get_longest_win_streak();
        int get_longest_loss_streak();
        void add_win(); //and update the curr win streak and longest win streak
        void add_loss();
        void update_points_gap(int OP, int TP); //OP= opponnent Points, TP= Team Points
        float randomTalent();

    };
}