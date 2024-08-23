// used to generate decomp.me contexts / import into ida/ghidra
#define NO_ASSERT_SIZE // ghidra workaround
#include "linker.h"
#include "psyq.h"
#include "unknown.h"
#include "libhzd/libhzd.h"
#include "Game/map.h"
#include "memcard/memcard.h"
#include "mts/mts_new.h"
#include "chara/snake/afterse.h"
#include "chara/snake/shadow.h"
#include "chara/snake/sna_hzd.h"
#include "chara/snake/sna_init.h"
#include "inline_n.h"
#include "libdg/libdg.h"
#include "libfs/libfs.h"
#include "libgcl/libgcl.h"
#include "libgcl/hash.h"
#include "libgv/libgv.h"
#include "Anime/animeconv/anime.h"
#include "Bullet/bakudan.h"
#include "Bullet/blast.h"
#include "Bullet/jirai.h"
#include "Bullet/rmissile.h"
#include "Bullet/tenage.h"
#include "Equip/bandana.h"
#include "Equip/jpegcam.h"
#include "Equip/bodyarm.h"
#include "Equip/box.h"
#include "Equip/gasmask.h"
#include "Equip/gglmng.h"
#include "Equip/gglsight.h"
#include "Equip/kogaku2.h"
#include "Equip/scope.h"
#include "Equip/tabako.h"
#include "Font/font.h"
#include "Game/control.h"
#include "Game/camera.h"
#include "Game/delay.h"
#include "Game/game.h"
#include "Game/linkvarbuf.h"
#include "Game/homing_target.h"
#include "Game/item.h"
#include "Game/jimctrl.h"
#include "Game/loader.h"
#include "Game/motion.h"
#include "Game/object.h"
#include "Game/strctrl.h"
#include "Game/target.h"
#include "Game/vibrate.h"
#include "Kojo/demothrd.h"
#include "Menu/menuman.h"
#include "Menu/radar.h"
#include "Menu/radio.h"
#include "Okajima/blood.h"
#include "Okajima/claymore.h"
#include "Okajima/d_bloodr.h"
#include "Okajima/spark.h"
#include "Okajima/stgfd_io.h"
#include "Okajima/stngrnd.h"
#include "SD/sound.h"
#include "Takabe/goggle.h"
#include "Takabe/goggleir.h"
#include "Takabe/scn_mask.h"
#include "Thing/door.h"
#include "Thing/sgtrect3.h"
#include "Thing/sight.h"
#include "Weapon/aam.h"
#include "Weapon/bomb.h"
#include "Weapon/famas.h"
#include "Weapon/grenade.h"
#include "Weapon/mine.h"
#include "Weapon/rcm.h"
#include "Weapon/rifle.h"
#include "Weapon/socom.h"
#include "Weapon/stnsight.h"
