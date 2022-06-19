#include "League.hpp"

using namespace std;

namespace Ex6{

    League::League(){

        for(int i = 0; i < 20; i++){
            Teams.push_back(new Team(teams_name[i]));
        }
    }

    League::League(vector<Team*> teams){//gets full 20 teams
        if(teams.size() != 20){
            throw invalid_argument("the number of teams must be 20. make it 20 or switch to other constructor");
        }
        for(int i = 0; i < 20; i++){
            Teams.push_back(teams[i]);
        }
    }

    Team* League::get_Team(int i){
        return Teams[i];
    }
    vector<Team*> &League::get_Teams(){
        return Teams;
    }

    void League::Print_league_stats(){
        //sort the teams as oppose to their wins
        sort(Teams.begin(), Teams.end(), [](Team* one, Team* two){
            return one-> get_wins() > two-> get_wins();
        });

        cout<< " \n    Team name           wins        losses          +-         win streak   loss streak      PPG            OPPG\n";
        cout<<"--------------------------------------------------------------------------------------------------------------------\n";

        for(int i = 0; i < 20; i++){
            cout<< i+1 <<". " << Teams[i]-> get_name();
            if(i >= 9){
                for(int j = 15; j > Teams[i]-> get_name().length(); j--){
                cout<<" ";
                }
            }
            else{
                for(int j = 15; j >= Teams[i]-> get_name().length(); j--){
                cout<<" ";
                }
            }

            cout<<" |    ";
            
            cout<<Teams[i]-> get_wins();
            if(Teams[i]-> get_wins() < 10){
                cout<<" ";
            } 
            
            cout<< "     |     " << Teams[i]-> get_losses();
            if(Teams[i]-> get_losses() < 10){
                cout<<" ";
            } 
            cout << "     |     "<< Teams[i]-> get_points_gap();
            int num = Teams[i]-> get_points_gap();
            if(num > 0 ){
                cout<<" ";
            }
            int count;
            for(count = 0; num != 0; num = num/10){
                count++;
            }
            for(; 5 - count >= 0; count++){
                cout<<" ";
            } 
            cout << "   |     " <<Teams[i]-> get_longest_win_streak();
            if(Teams[i]-> get_longest_win_streak() < 10){
                cout<<" ";
            }
            cout<< "     |     " << Teams[i]-> get_longest_loss_streak();
            if(Teams[i]-> get_longest_loss_streak() < 10){
                cout<<" ";
            }
            cout<<"     |     "<< setprecision(2)<< fixed<<Teams[i]->ppg() << "     |     "<< Teams[i]->oppg()<<"\n";                                       
        }
    }
}