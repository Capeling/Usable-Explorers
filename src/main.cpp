#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelTools.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if(!MenuLayer::init())
			return false;
		#ifdef GEODE_IS_WINDOWS
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92276), { 0x83, 0xf8, 0x16 });
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92283), { 0xba, 0x16, 0x00, 0x00, 0x00 });
		#endif

		#ifdef GEODE_IS_ANDROID
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x5241e), { 0x16, 0x29 });
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x52400), { 0x16, 0x29 });
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x5240c), { 0x16, 0x21 });
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