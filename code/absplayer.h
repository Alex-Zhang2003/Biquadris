// Abstract Subject
#ifndef ABSPLAYER_H
#define ABSPLAYER_H
#include <vector>
#include <memory>

class ABSDisplay;

class ABSPlayer {

  std::vector<std::unique_ptr<ABSDisplay>> displays;

  

public:

  void notifyDisplay();
  void notifyBoard();
  void attach(std::unique_ptr<ABSDisplay> o);
  void detach(std::unique_ptr<ABSDisplay> o);
  virtual ~ABSPlayer() = default;
};


#endif





