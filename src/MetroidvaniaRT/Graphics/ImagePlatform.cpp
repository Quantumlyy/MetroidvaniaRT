#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  ImagePlatform::ImagePlatform(IdentificationInformation& identificationInformation,
    int layer,
    const std::string& filePath,
    NovelRT::Transform& transform,
    NovelRT::Graphics::RGBAConfig& colourTint)
      : Platform(identificationInformation, transform, layer, colourTint),
      _filePath(filePath) { }

  NovelRT::Graphics::ImageRect* ImagePlatform::create(NovelRT::Graphics::RenderingService* renderer) {
    renderObj = renderer->createImageRect(_transform, _layer, _filePath, _colourTint).get();
    _created = true;
    raisePlatformCreated();
    return renderObj;
  }
}
