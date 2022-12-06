// Abstract Subject
#ifndef ABSPLAYER_H
#define ABSPLAYER_H
#include <vector>
#include <memory>

class ABSDisplay;

class ABSPlayer {

  std::vector<std::shared_ptr<ABSDisplay>> displays;

public:

  void notifyDisplay();
  void notifyBoard();
  void attach(std::shared_ptr<ABSDisplay> o);
  void detach(std::shared_ptr<ABSDisplay> o);
  virtual ~ABSPlayer() = default;
};


#endif





