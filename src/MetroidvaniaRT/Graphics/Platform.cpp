#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  Platform::Platform(IdentificationInformation& identificationInformation,
    NovelRT::Transform& transform,
    int layer,
    NovelRT::Graphics::RGBAConfig& colourTint) :
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
    return renderObj->getLayer();
  }
  void Platform::setLayer(int value) {
    return renderObj->setLayer(value);
  }

  void Platform::render() {
    renderObj->executeObjectBehaviour();
    raisePlatformRendered();
  }

}
