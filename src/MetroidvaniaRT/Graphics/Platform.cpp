#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  Platform::Platform(IdentificationInformation& identificationInformation,
    NovelRT::Transform& args,
    NovelRT::Graphics::RGBAConfig& colourTint) :
      _args(args),
      _colourTint(colourTint),
      _II(identificationInformation) { }

  IdentificationInformation& Platform::getII() const {
    return _II;
  }

  int Platform::getLayer() const {
    return _args.layer;
  }
  void Platform::setLayer(int value) {
    _args.layer = value;
  }

}
