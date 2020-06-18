#ifndef METROIDVANIART_H
#define METROIDVANIART_H

#include <map>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "../dependencies/NovelRT/include/NovelRT.h"

namespace MetroidvaniaRT {
  typedef class IdentificationInformation IdentificationInformation;
  typedef class MetroidvaniaRunner MetroidvaniaRunner;
}

namespace MetroidvaniaRT::Graphics {
  typedef class StageService StageService;

  typedef class Stage Stage;

  typedef class FillPlatform FillPlatform;
}

#include "MetroidvaniaRT/MetroidvaniaRunner.h"
#include "MetroidvaniaRT/IdentificationInformation.h"
#include "MetroidvaniaRT/Graphics/Platform.h"
#include "MetroidvaniaRT/Graphics/FillPlatform.h"
#include "MetroidvaniaRT/Graphics/Stage.h"
#include "MetroidvaniaRT/Graphics/StageService.h"

#endif // METROIDVANIART_H
