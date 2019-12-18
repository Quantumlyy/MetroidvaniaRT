#include "MetroidvaniaPlatform.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint) :
      _args(args),
      _colourTint(colourTint) { }

  int MetroidvaniaPlatform::getId() const {
    return _id;
  }
  void MetroidvaniaPlatform::setId(int value) {
    _id = value;
  }
}
