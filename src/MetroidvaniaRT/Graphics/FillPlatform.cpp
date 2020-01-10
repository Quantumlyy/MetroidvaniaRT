#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  FillPlatform::FillPlatform(IdentificationInformation& identificationInformation,
    NovelRT::RGBAConfig& colourFill,
    NovelRT::NovelCommonArgs& args) : Platform(identificationInformation, args, colourFill) { }

  NovelRT::NovelBasicFillRect* FillPlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    renderObj = renderer->getBasicFillRect(_colourTint, _args);
    raisePlatformRendered();
    return renderObj;
  }
}
