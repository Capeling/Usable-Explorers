#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelTools.hpp>
#include <Geode/modify/SongSelectNode.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if(!MenuLayer::init())
			return false;
		#ifdef GEODE_IS_WINDOWS
		log::info("patching WINDOWS");
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92276), { 0x83, 0xf8, 0x16 });
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92283), { 0xba, 0x16, 0x00, 0x00, 0x00 });
		#endif

		#ifdef GEODE_IS_ANDROID32
		log::info("patching ANDROID32");
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x5241e), { 0x16, 0x29 });
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x52400), { 0x16, 0x29 });
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x5240c), { 0x15, 0x21 });
		#endif

		#ifdef GEODE_IS_ANDROID64
		log::info("patching ANDROID64");
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x50b34c), { 0x3f, 0x58, 0x00, 0x71 });
		log::info("patched {}", base::get() + 0x50b34c);
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x50b328), { 0xc3, 0x02, 0x80, 0x52 });
		log::info("patched {}", base::get() + 0x50b328);
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x50b324), { 0x3f, 0x58, 0x00, 0x71 });
		log::info("patched {}", base::get() + 0x50b324);
		#endif

		return true;
	}
};

class $modify(LevelTools) {
	static gd::string getAudioFileName(int id) {
		switch(id) {
			default: return LevelTools::getAudioFileName(id);
			case 22: return "Explorers.mp3"_spr;
		}
	}
};