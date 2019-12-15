#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#include <map>

#include "../../dependencies/NovelRT/src/NovelRunner.h"
#include "./structures/Character.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a Metroidvania style game.
   */
  class MetroidvaniaRunner : public NovelRT::NovelRunner {
  private:
    // A store of Characters currently on screen.
    std::map<std::string, Character> characters;
  public:
  protected:
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
