// Abstract Subject
#ifndef ABSPLAYER_H
#define ABSPLAYER_H
#include <vector>

class ABSDisplay;

class ABSPlayer {

  std::vector<ABSDisplay*> displays;

  

public:

  void notifyDisplay();
  void notifyBoard();
  void attach(ABSDisplay *o);
  void detach(ABSDisplay *o);
  virtual ~ABSPlayer() = default;
};


#endif



