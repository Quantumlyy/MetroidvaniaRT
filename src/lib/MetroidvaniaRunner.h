#ifndef METROIDVANIART_METROIDVANIARUNNER_H
#define METROIDVANIART_METROIDVANIARUNNER_H

#include <map>
#include <string>

#include "../../dependencies/NovelRT/src/NovelRunner.h"
#include "../../dependencies/NovelRT/src/NovelLayeringService.h"
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
    MetroidvaniaRunner(int, NovelRT::NovelLayeringService*, uint32_t targetFrameRate = 0);
  protected:
  };
}

#endif // METROIDVANIART_METROIDVANIARUNNER_H
