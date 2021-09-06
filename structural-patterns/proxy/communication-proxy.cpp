#include <bits/stdc++.h>
#include <thread>

using namespace std;

class Pingable
{
public:
    virtual bool ping(const string& msg) = 0;
    virtual ~Pingable() = default;
};

class Pong : public Pingable
{
public:
  Pong() = default;
  bool ping(const string& msg)
  {
    cout << msg + " pong..." << endl;
    return true;
  }

};


int main(int argc, char **argv)
{
  Pong pong_obj;

  if (argc != 3 || string(argv[1]) == "--help")
  {
    cout << argv[0] << " <times> <msg>" << endl;
    exit(EXIT_FAILURE);
  }

  long max_ping = strtol(argv[1], NULL, 10);

  for (auto i = 0; i < max_ping; ++i)
  {
    pong_obj.ping(argv[2]);
    std::this_thread::sleep_for(1000ms);
  }

  return 0;
}