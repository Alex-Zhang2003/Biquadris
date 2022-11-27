// Subject
#ifndef ABSPLAYER_H
#define ABSPLAYER_H
#include <vector>
#include "absdisplay.h"

class ABSDisplay;

class ABSPlayer {
    std::vector<ABSDisplay*> displays;
protected:
    void notifyDisplay();
public:
  void attach(ABSDisplay *o);
  void detach(ABSDisplay *o);
  virtual ~ABSPlayer() = default;
};


#endif



