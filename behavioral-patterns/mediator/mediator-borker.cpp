#include <bits/stdc++.h>
using namespace std;

#include <boost/signals2.hpp>
using namespace boost::signals2;

struct IPlayer;

struct EventData
{
    virtual ~EventData() = default;
    virtual void print() const = 0;    
};

struct PlayerScoredData : EventData
{
    string player;
    int score {0};
    PlayerScoredData(const string& _player, const int& _score) : player{_player} , score{_score} {}

    void print() const override
    {
        cout << "<<" << player << ">>" << " score " << score << endl;
    }
};

struct Game
{
  boost::signals2::signal<void(IPlayer*, EventData*)> events; // observer
};

struct IPlayer
{
    virtual ~IPlayer() = default;
    virtual void say(PlayerScoredData* ev_data) = 0;
    virtual void receive(PlayerScoredData* ev_data) = 0;
};

struct Player : IPlayer
{
    string name;
    int goals_scored = 0;
    Game& game;

    Player(const string& name, Game& game): name(name), game(game)
    {

    }

    void score()
    {
        goals_scored++;
        PlayerScoredData ps{name, goals_scored};
        say(&ps);
    }

    void say(PlayerScoredData* ev_data)
    {
        game.events(this, ev_data);
    }

    void receive(PlayerScoredData* ev_data)
    {
            cout << "[" << name << "] ";
            ev_data->print();
    }
};

struct CoachRoom
{
  Game& game;
  vector<Player*> player_list;

  explicit CoachRoom(Game& game)
    : game(game)
  {
    // celebrate if player has scored <3 goals
    game.events.connect([&](IPlayer* _player, EventData* e)
    {
      PlayerScoredData* ps = dynamic_cast<PlayerScoredData*>(e);
      for (auto e : player_list)
        if (e != _player)
            e->receive(ps);
    });
  }

  void add_player(Player* _player)
  {
      player_list.push_back(_player);
  }
};

int main()
{
  Game game;
  Player sam{ "Sam", game };
  Player leo{ "Leo", game };
  Player messi{ "Messi", game };
  CoachRoom coach{ game };

  coach.add_player(&sam);
  coach.add_player(&leo);
  coach.add_player(&messi);

  sam.score();
  sam.score();
  cout << endl;

  leo.score();
  leo.score();
  cout << endl;

  messi.score();
  messi.score();
  cout << endl;
  return 0;
}
