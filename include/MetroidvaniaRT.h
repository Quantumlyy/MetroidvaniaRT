#ifndef METROIDVANIART_H
#define METROIDVANIART_H

#include <string>
#include <map>
#include <vector>
#include <stdexcept>

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

#include "MetroidvaniaRT/IdentificationInformation.h"
#include "MetroidvaniaRT/Graphics/Platform.h"
#include "MetroidvaniaRT/Graphics/FillPlatform.h"
#include "MetroidvaniaRT/Graphics/Stage.h"
#include "MetroidvaniaRT/Graphics/StageService.h"
#include "MetroidvaniaRT/MetroidvaniaRunner.h"

#endif // METROIDVANIART_H
