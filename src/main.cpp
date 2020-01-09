#include "../dependencies/NovelRT/src/NovelRT.h"
#include "../include/MetroidvaniaRT.h"

int main(int argc, char* argv[]) {
  auto runner = new MetroidvaniaRT::MetroidvaniaRunner(0);

  auto fillArgs = NovelRT::NovelCommonArgs();
  fillArgs.layer = 0;
  fillArgs.startingPosition.setX(1920 / 2);
  fillArgs.startingPosition.setY(1080 / 2);
  fillArgs.startingScale = NovelRT::GeoVector<float>(456, 618);

  auto fill2args = fillArgs;
  fill2args.layer = 1;
  fill2args.startingPosition.setX((1920 / 2) - 100);

  auto IIStage = MetroidvaniaRT::MetroidvaniaIdentificationInformation();
  IIStage.id = 1;

  auto IIPlatform1 = MetroidvaniaRT::MetroidvaniaIdentificationInformation();
  IIPlatform1.id = 1;

  auto IIPlatform2 = MetroidvaniaRT::MetroidvaniaIdentificationInformation();
  IIPlatform2.id = IIPlatform1.id++;

  runner->getStageService()->addStage(std::make_unique<MetroidvaniaRT::MetroidvaniaStage>(IIStage));
  runner->getStageService()->addStagePlatform(0, std::make_unique<MetroidvaniaRT::MetroidvaniaFillPlatform>(IIPlatform1, NovelRT::RGBAConfig(255, 0, 255, 255), fillArgs));
  runner->getStageService()->addStagePlatform(0, std::make_unique<MetroidvaniaRT::MetroidvaniaFillPlatform>(IIPlatform2, NovelRT::RGBAConfig(210, 45, 56, 255), fill2args));
  runner->getStageService()->renderStage(runner->getRenderer(), 1);

  runner->runNovel();
  return EXIT_SUCCESS;
}
