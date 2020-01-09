#include "MetroidvaniaPlatform.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(MetroidvaniaIdentificationInformation& identificationInformation,
    NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint) :
      _args(args),
      _colourTint(colourTint),
      _II(identificationInformation) { }

  MetroidvaniaIdentificationInformation& MetroidvaniaPlatform::getII() const {
    return _II;
  }

  int MetroidvaniaPlatform::getLayer() const {
    return _args.layer;
  }
  void MetroidvaniaPlatform::setLayer(int value) {
    _args.layer = value;
  }

}
