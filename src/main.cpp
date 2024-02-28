#include <Geode/Geode.hpp>
#include <Geode/modify/LevelTools.hpp>

using namespace geode::prelude;

class $modify(LevelTools) {
	static gd::string getAudioFileName(int id) {
		switch(id) {
			default: return LevelTools::getAudioFileName(id);
			case 22: return "Explorers.mp3"_spr;
		}
	}
};

$on_mod(Loaded) {
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92276), { 0x83, 0xf8, 0x16 });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92283), { 0xba, 0x16, 0x00, 0x00, 0x00 });
}