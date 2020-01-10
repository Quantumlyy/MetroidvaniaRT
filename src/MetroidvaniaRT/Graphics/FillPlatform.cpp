#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  FillPlatform::FillPlatform(IdentificationInformation& identificationInformation,
    NovelRT::Transform& transform,
    int layer,
    NovelRT::Graphics::RGBAConfig& colourConfig) : Platform(identificationInformation, transform, layer, colourConfig) { }

  NovelRT::Graphics::BasicFillRect* FillPlatform::create(NovelRT::Graphics::RenderingService* renderer) {
    renderObj = renderer->createBasicFillRect(_transform, _layer, _colourTint).get();
    _created = true;
    raisePlatformCreated();
    return renderObj;
  }
}
