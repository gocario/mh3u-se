#include "mh3u_ds.hpp"

lang_t MH3U_DS::_lang = LANG_NONE;

dataset_t* MH3U_DS::_faces = NULL;
dataset_t* MH3U_DS::_hairs = NULL;
dataset_t* MH3U_DS::_sexs = NULL;
dataset_t* MH3U_DS::_voices = NULL;
dataset_t* MH3U_DS::_items = NULL;
dataset_t* MH3U_DS::_skills = NULL;
dataset_t* MH3U_DS::_jewels = NULL;

dataset_t* MH3U_DS::_equipmentTypes = NULL;
dataset_t* MH3U_DS::_chestArmors = NULL;
dataset_t* MH3U_DS::_armsArmors = NULL;
dataset_t* MH3U_DS::_waistArmors = NULL;
dataset_t* MH3U_DS::_legsArmors = NULL;
dataset_t* MH3U_DS::_headArmors = NULL;
dataset_t* MH3U_DS::_charms = NULL;
dataset_t* MH3U_DS::_gsWeapons = NULL;
dataset_t* MH3U_DS::_snsWeapons = NULL;
dataset_t* MH3U_DS::_hWeapons = NULL;
dataset_t* MH3U_DS::_lWeapons = NULL;
dataset_t* MH3U_DS::_hbgWeapons = NULL;
dataset_t* MH3U_DS::_lbgWeapons = NULL;
dataset_t* MH3U_DS::_lsWeapons = NULL;
dataset_t* MH3U_DS::_saWeapons = NULL;
dataset_t* MH3U_DS::_glWeapons = NULL;
dataset_t* MH3U_DS::_bowWeapons = NULL;
dataset_t* MH3U_DS::_dbWeapons = NULL;
dataset_t* MH3U_DS::_hhWeapons = NULL;


bool MH3U_DS::readData(const lang_t lang)
{
	if (lang == MH3U_DS::_lang || lang == LANG_NONE) return false;

	MH3U_DS::_lang = lang;

	bool result = true;

	// Character
	result &= MH3U_DS::readFaces(lang);
	result &= MH3U_DS::readHairs(lang);
	result &= MH3U_DS::readSexs(lang);
	result &= MH3U_DS::readVoices(lang);

	// Items Id
	result &= MH3U_DS::readItems(lang);

	// In-data
	result &= MH3U_DS::readSkills(lang);
	result &= MH3U_DS::readJewels(lang);

	// Equipment types
	result &= MH3U_DS::readEquipmentTypes(lang);
	result &= MH3U_DS::readChestArmors(lang);
	result &= MH3U_DS::readArmsArmors(lang);
	result &= MH3U_DS::readWaistArmors(lang);
	result &= MH3U_DS::readLegsArmors(lang);
	result &= MH3U_DS::readHeadArmors(lang);
	result &= MH3U_DS::readCharms(lang);
	result &= MH3U_DS::readGSWeapons(lang);
	result &= MH3U_DS::readSNSWeapons(lang);
	result &= MH3U_DS::readHWeapons(lang);
	result &= MH3U_DS::readLWeapons(lang);
	result &= MH3U_DS::readHBGWeapons(lang);
	result &= MH3U_DS::readLBGWeapons(lang);
	result &= MH3U_DS::readLSWeapons(lang);
	result &= MH3U_DS::readSAWeapons(lang);
	result &= MH3U_DS::readGLWeapons(lang);
	result &= MH3U_DS::readBOWWeapons(lang);
	result &= MH3U_DS::readDBWeapons(lang);
	result &= MH3U_DS::readHHWeapons(lang);

	return result;
}


bool MH3U_DS::deleteData(void)
{
	try
	{
		// Character
		cdelete(MH3U_DS::_faces);
		cdelete(MH3U_DS::_hairs);
		cdelete(MH3U_DS::_sexs);
		cdelete(MH3U_DS::_voices);

		// Items Id
		cdelete(MH3U_DS::_items);

		// In-data
		cdelete(MH3U_DS::_skills);
		cdelete(MH3U_DS::_jewels);

		// Equipment types
		cdelete(MH3U_DS::_equipmentTypes);
		cdelete(MH3U_DS::_chestArmors);
		cdelete(MH3U_DS::_armsArmors);
		cdelete(MH3U_DS::_waistArmors);
		cdelete(MH3U_DS::_legsArmors);
		cdelete(MH3U_DS::_headArmors);
		cdelete(MH3U_DS::_charms);
		cdelete(MH3U_DS::_gsWeapons);
		cdelete(MH3U_DS::_hWeapons);
		cdelete(MH3U_DS::_snsWeapons);
		cdelete(MH3U_DS::_hWeapons);
		cdelete(MH3U_DS::_lWeapons);
		cdelete(MH3U_DS::_lbgWeapons);
		cdelete(MH3U_DS::_hbgWeapons);
		cdelete(MH3U_DS::_lsWeapons);
		cdelete(MH3U_DS::_saWeapons);
		cdelete(MH3U_DS::_glWeapons);
		cdelete(MH3U_DS::_bowWeapons);
		cdelete(MH3U_DS::_dbWeapons);
		cdelete(MH3U_DS::_hhWeapons);
	}
	catch (std::exception e)
	{
		return false;
	}

	return true;
}


lang_t MH3U_DS::lang(void)
{
	return (const lang_t) _lang;
}


const dataset_t* MH3U_DS::faces(void)
{
	return _faces;
}
const dataset_t* MH3U_DS::hairs(void)
{
	return _hairs;
}
const dataset_t* MH3U_DS::sexs(void)
{
	return _sexs;
}
const dataset_t* MH3U_DS::voices(void)
{
	return _voices;
}

const dataset_t* MH3U_DS::items(void)
{
	return _items;
}
const dataset_t* MH3U_DS::skills(void)
{
	return _skills;
}
const dataset_t* MH3U_DS::jewels(void)
{
	return _jewels;
}

const dataset_t* MH3U_DS::equipmentTypes(void)
{
	return _equipmentTypes;
}
const dataset_t* MH3U_DS::chestArmors(void)
{
	return _chestArmors;
}
const dataset_t* MH3U_DS::armsArmors(void)
{
	return _armsArmors;
}
const dataset_t* MH3U_DS::waistArmors(void)
{
	return _waistArmors;
}
const dataset_t* MH3U_DS::legsArmors(void)
{
	return _legsArmors;
}
const dataset_t* MH3U_DS::headArmors(void)
{
	return _headArmors;
}
const dataset_t* MH3U_DS::charms(void)
{
	return _charms;
}
const dataset_t* MH3U_DS::gsWeapons(void)
{
	return _gsWeapons;
}
const dataset_t* MH3U_DS::snsWeapons(void)
{
	return _snsWeapons;
}
const dataset_t* MH3U_DS::hWeapons(void)
{
	return _hWeapons;
}
const dataset_t* MH3U_DS::lWeapons(void)
{
	return _lWeapons;
}
const dataset_t* MH3U_DS::hbgWeapons(void)
{
	return _hbgWeapons;
}
const dataset_t* MH3U_DS::lbgWeapons(void)
{
	return _lbgWeapons;
}
const dataset_t* MH3U_DS::lsWeapons(void)
{
	return _lsWeapons;
}
const dataset_t* MH3U_DS::saWeapons(void)
{
	return _saWeapons;
}
const dataset_t* MH3U_DS::glWeapons(void)
{
	return _glWeapons;
}
const dataset_t* MH3U_DS::bowWeapons(void)
{
	return _bowWeapons;
}
const dataset_t* MH3U_DS::dbWeapons(void)
{
	return _dbWeapons;
}
const dataset_t* MH3U_DS::hhWeapons(void)
{
	return _hhWeapons;
}



		/*---------*\
		 | Private |
		\*---------*/


dataset_t* MH3U_DS::readFile(std::string filename)
{
	dataset_t* dataset = NULL;
	
	std::stringstream ss;
	std::ifstream fs;
	uint8_t tmp_c;

	try
	{
		fs.open(filename.c_str(), std::ifstream::in);
		
		if (!fs)
		{
			std::cout << "File not found: " << filename << std::endl;
			return NULL;
		}
		
		while(fs.good())
		{
			fs.read((char*)&tmp_c, 1);
			if (fs.good()) ss.write((char*)&tmp_c, 1);
		}
		fs.close();

		dataset = new dataset_t();
	
		const uint32_t bufferSize = 32;
		char* buffer = new char[bufferSize];

		uint32_t count = 1;
		while(ss.good())
		{
			ss.getline(buffer, bufferSize);

			dataitem_t dataitem;
			dataitem.identifier = buffer;
			dataitem.count = count;
			dataset->push_back(dataitem);

			count++;
		}

		return dataset;
	}
	catch(std::exception e)
	{
		cdelete(dataset);
		return NULL;
	}

}


bool MH3U_DS::readFile(dataset_t* &dataset, std::string filename, const lang_t &lang)
{
#ifdef DEBUG
	filename = "H:/Users/Gocario/Documents/Monster Hunter/Monster Hunter 3 Ultimate/data/" + folderLang(lang) + filename + ".txt";
#else
	filename = "data/" + folderLang(lang) + filename + ".txt";
#endif
	delete(dataset);
	dataset = MH3U_DS::readFile(filename);
	return (dataset != NULL);
}


std::string MH3U_DS::folderLang(const lang_t &lang)
{
	switch (lang)
	{
		case LANG_EN:
		{
			return "en/";
		}
		case LANG_FR:
		{
			return "fr/";
		}
		case LANG_NONE:
		default:
		{
			return "";
		}
	}

}



// Character
bool MH3U_DS::readFaces(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_faces, "faces", lang);
}
bool MH3U_DS::readHairs(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_hairs, "hairs", lang);
}
bool MH3U_DS::readSexs(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_sexs, "sexs", lang);
}
bool MH3U_DS::readVoices(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_voices, "voices", lang);
}


// In-data
bool MH3U_DS::readItems(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_items, "items", lang);
}
bool MH3U_DS::readSkills(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_skills, "skills", lang);
}
bool MH3U_DS::readJewels(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_jewels, "jewels", lang);
}


// Equipment types
bool MH3U_DS::readEquipmentTypes(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_equipmentTypes, "equipment_types", lang);
}

bool MH3U_DS::readChestArmors(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_chestArmors, "chest_armors", lang);
}
bool MH3U_DS::readArmsArmors(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_armsArmors, "arms_armors", lang);
}
bool MH3U_DS::readWaistArmors(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_waistArmors, "waist_armors", lang);
}
bool MH3U_DS::readLegsArmors(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_legsArmors, "legs_armors", lang);
}
bool MH3U_DS::readHeadArmors(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_headArmors, "head_armors", lang);
}

bool MH3U_DS::readCharms(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_charms, "charms", lang);
}

bool MH3U_DS::readGSWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_gsWeapons, "gs_weapons", lang);
}
bool MH3U_DS::readSNSWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_snsWeapons, "sns_weapons", lang);
}
bool MH3U_DS::readHWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_hWeapons, "h_weapons", lang);
}
bool MH3U_DS::readLWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_lWeapons, "l_weapons", lang);
}
bool MH3U_DS::readHBGWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_hbgWeapons, "hbg_weapons", lang);
}
bool MH3U_DS::readLBGWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_lbgWeapons, "lbg_weapons", lang);
}
bool MH3U_DS::readLSWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_lsWeapons, "ls_weapons", lang);
}
bool MH3U_DS::readSAWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_saWeapons, "sa_weapons", lang);
}
bool MH3U_DS::readGLWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_glWeapons, "gl_weapons", lang);
}
bool MH3U_DS::readBOWWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_bowWeapons, "bow_weapons", lang);
}
bool MH3U_DS::readDBWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_dbWeapons, "db_weapons", lang);
}
bool MH3U_DS::readHHWeapons(const lang_t &lang)
{
	return MH3U_DS::readFile(MH3U_DS::_hhWeapons, "hh_weapons", lang);
}
