#include <MetroidvaniaRT.h>

int main(int argc, char* argv[]) {
  auto runner = new MetroidvaniaRT::MetroidvaniaRunner(0);

  auto fillArgs = NovelRT::Transform(NovelRT::Maths::GeoVector<float>(1920 / 2, 1080 / 2), 0, NovelRT::Maths::GeoVector<float>(456, 618));


  auto IIStage = MetroidvaniaRT::IdentificationInformation();
  IIStage.id = 1;

  auto IIPlatform1 = MetroidvaniaRT::IdentificationInformation();
  IIPlatform1.id = 1;

  runner->getStageService()->addStage(std::make_unique<MetroidvaniaRT::Graphics::Stage>(IIStage));
  runner->getStageService()->addStagePlatform(1, std::make_unique<MetroidvaniaRT::Graphics::FillPlatform>(IIPlatform1, fillArgs, 1, NovelRT::Graphics::RGBAConfig(255, 0, 255, 255)));
  runner->getStageService()->createStage(1);
  runner->getStageService()->initiateRenderLoopStage(1);

  runner->runNovel();
  return EXIT_SUCCESS;
}
