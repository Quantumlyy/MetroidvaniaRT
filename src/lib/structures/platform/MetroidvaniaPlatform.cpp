#include "MetroidvaniaPlatform.h"

#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderObject.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(NovelRT::GeoVector<float>& startingSize,
    NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint):
      _startingSize(startingSize),
      _args(args),
      _colourTint(colourTint) { }

  int MetroidvaniaPlatform::getId() const {
    return _id;
  }
  void MetroidvaniaPlatform::setId(int value) {
    _id = value;
  }
}
