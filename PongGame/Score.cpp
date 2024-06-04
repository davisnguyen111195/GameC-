#include "Score.hpp"


Score::Score(){
    m_cpu_score = 0;
    m_player_score = 0;
}

Score::Score(int player, int cpu) : m_player_score(player), m_cpu_score(cpu){

}


int Score::getPlayerScore(){
    return m_player_score;
}
int Score::getCPUScore(){
    return m_cpu_score;
}

void Score::setCPUScore(int y){
    m_cpu_score = y;
}

void Score::setPlayerScore(int x){
    m_player_score = x;
}

