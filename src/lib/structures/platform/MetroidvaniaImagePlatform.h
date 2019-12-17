#ifndef METROIDVANIART_METROIDVANIAIMAGEPLATFORM_H
#define METROIDVANIART_METROIDVANIAIMAGEPLATFORM_H

#include <string>

#include "MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelImageRect.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a image platform in a stage.
   */
  class MetroidvaniaImagePlatform : public MetroidvaniaPlatform {
  protected:
    std::string _filePath;
  public:
    NovelRT::NovelImageRect* renderObj;
    NovelRT::NovelImageRect* formRender(NovelRT::NovelRenderingService* renderer);

    MetroidvaniaImagePlatform(NovelRT::GeoVector<float>&, std::string, NovelRT::NovelCommonArgs&, NovelRT::RGBAConfig&);
  };
}

#endif // METROIDVANIART_METROIDVANIAIMAGEPLATFORM_H
