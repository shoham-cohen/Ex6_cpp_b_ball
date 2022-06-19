#include <string>
#include "Team.hpp"
#include <random>

using namespace std;

namespace Ex6{

    class Game{

        Team* home_team;
        Team* away_team;
        Team* winning_team;

    public:

        Game(Team* home_team, Team* away_team);
        Team *start_game();
    };
}