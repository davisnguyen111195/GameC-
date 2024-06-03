#include "Score.hpp"

Score::Score(int player, int cpu) : m_player_score(player), m_cpu_score(cpu){

}


int Score::getPlayerScore(){
    return m_player_score;
}
int Score::getCPUScore(){
    return m_cpu_score;
}

void Score::setCPuScore(int y){
    m_cpu_score = y;
}

void Score::setPlayerScore(int x){
    m_player_score = x;
}

