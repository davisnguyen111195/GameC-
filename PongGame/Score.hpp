#ifndef DEF_SCORE
#define DEF_SCORE

class Score{
private:
    int m_player_score, m_cpu_score;
public:
    Score(int player, int cpu);
    void setPlayerScore(int x);
    void setCPuScore(int y);
    int getPlayerScore();
    int getCPUScore();
};

#endif