#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  Platform::Platform(IdentificationInformation& identificationInformation,
    NovelRT::Transform& transform,
    int layer,
    NovelRT::Graphics::RGBAConfig& colourTint) :
      PlatformCreated(NovelRT::Utilities::Event<>()),
      PlatformRendered(NovelRT::Utilities::Event<>()),
      _transform(transform),
      _layer(layer),
      _colourTint(colourTint),
      _II(identificationInformation),
      _created(false) { }

  IdentificationInformation& Platform::getII() const {
    return _II;
  }

  bool Platform::getCreated() const {
    return _created;
  }

  int Platform::getLayer() const {
    return _layer;
  }
  void Platform::setLayer(int value) {
    renderObj->setLayer(value);
    _layer = value;
  }

  void Platform::render() {
    renderObj->executeObjectBehaviour();
    PlatformRendered();
  }

}
