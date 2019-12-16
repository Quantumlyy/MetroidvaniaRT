#include "./lib/MetroidvaniaRunner.h"

#include "./lib/structures/MetroidvaniaCommonArgs.h"
#include "./lib/structures/stage/MetroidvaniaStage.h"
#include "./lib/structures/stage/MetroidvaniaPlatform.h"
#include "../dependencies/NovelRT/src/NovelLayeringService.h"
#include "../dependencies/NovelRT/src/GeoVector.h"
#include "../dependencies/NovelRT/src/RGBAConfig.h"

int main(int argc, char* argv[]) {
  auto runner = new MetroidvaniaRT::MetroidvaniaRunner(0, new NovelRT::NovelLayeringService(), 10);
  auto stage = new MetroidvaniaRT::MetroidvaniaStage();

  MetroidvaniaRT::MetroidvaniaCommonArgs basicArgs;
  basicArgs.layer = 0;
  basicArgs.orderInLayer = 0;
  basicArgs.startingPosition.setX(1920 / 2);
  basicArgs.startingPosition.setY(1080 / 2);

  auto platform1 = new MetroidvaniaRT::MetroidvaniaPlatform(NovelRT::GeoVector<float>(456, 618), "", basicArgs, NovelRT::RGBAConfig(255, 0, 255, 255));

  stage->addPlatform(platform1);
  runner->addStage(stage);

  runner->stages[0]->renderPlatforms(runner->getRenderer());

  runner->runNovel();
  return 0;
}
