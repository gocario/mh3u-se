#ifndef MH3U_DS_HPP
#define MH3U_DS_HPP

#include "main.hpp"

#include <vector>

/* --------- Structures --------- */

typedef struct dataitem_t
{
	uint32_t count;
	std::string identifier;
} dataitem_t;

typedef std::vector<dataitem_t> dataset_t;


typedef enum lang_t
{
	LANG_NONE = 0,
	LANG_EN = 1,
	LANG_FR = 2,
} lang_t;

/* --------- Class --------- */

class MH3U_DS
{
	public:

		static bool readData(const lang_t lang);
		static bool deleteData(void);

		static lang_t lang(void);

		static const dataset_t* faces(void);
		static const dataset_t* hairs(void);
		static const dataset_t* sexs(void);
		static const dataset_t* voices(void);

		static const dataset_t* items(void);
		static const dataset_t* skills(void);
		static const dataset_t* jewels(void);

		static const dataset_t* equipmentTypes(void);
		static const dataset_t* chestArmors(void);
		static const dataset_t* armsArmors(void);
		static const dataset_t* waistArmors(void);
		static const dataset_t* legsArmors(void);
		static const dataset_t* headArmors(void);
		static const dataset_t* charms(void);
		static const dataset_t* gsWeapons(void);
		static const dataset_t* snsWeapons(void);
		static const dataset_t* hWeapons(void);
		static const dataset_t* lWeapons(void);
		static const dataset_t* hbgWeapons(void);
		static const dataset_t* lbgWeapons(void);
		static const dataset_t* lsWeapons(void);
		static const dataset_t* saWeapons(void);
		static const dataset_t* glWeapons(void);
		static const dataset_t* bowWeapons(void);
		static const dataset_t* dbWeapons(void);
		static const dataset_t* hhWeapons(void);

	private:

		static lang_t _lang;

		static dataset_t* readFile(std::string filename);
		static bool readFile(dataset_t* &dataset, std::string filename, const lang_t &lang);

		static std::string folderLang(const lang_t &lang);


		// Character
		static bool readFaces(const lang_t &lang = LANG_NONE);
		static bool readHairs(const lang_t &lang = LANG_NONE);
		static bool readSexs(const lang_t &lang = LANG_NONE);
		static bool readVoices(const lang_t &lang = LANG_NONE);

		// In-data
		static bool readItems(const lang_t &lang = LANG_NONE);
		static bool readSkills(const lang_t &lang = LANG_NONE);
		static bool readJewels(const lang_t &lang = LANG_NONE);

		// Equipment types
		static bool readEquipmentTypes(const lang_t &lang = LANG_NONE);
		static bool readChestArmors(const lang_t &lang = LANG_NONE);
		static bool readArmsArmors(const lang_t &lang = LANG_NONE);
		static bool readWaistArmors(const lang_t &lang = LANG_NONE);
		static bool readLegsArmors(const lang_t &lang = LANG_NONE);
		static bool readHeadArmors(const lang_t &lang = LANG_NONE);
		static bool readCharms(const lang_t &lang = LANG_NONE);
		static bool readGSWeapons(const lang_t &lang = LANG_NONE);
		static bool readSNSWeapons(const lang_t &lang = LANG_NONE);
		static bool readHWeapons(const lang_t &lang = LANG_NONE);
		static bool readLWeapons(const lang_t &lang = LANG_NONE);
		static bool readHBGWeapons(const lang_t &lang = LANG_NONE);
		static bool readLBGWeapons(const lang_t &lang = LANG_NONE);
		static bool readLSWeapons(const lang_t &lang = LANG_NONE);
		static bool readSAWeapons(const lang_t &lang = LANG_NONE);
		static bool readGLWeapons(const lang_t &lang = LANG_NONE);
		static bool readBOWWeapons(const lang_t &lang = LANG_NONE);
		static bool readDBWeapons(const lang_t &lang = LANG_NONE);
		static bool readHHWeapons(const lang_t &lang = LANG_NONE);


		// Character
		static dataset_t* _faces;
		static dataset_t* _hairs;
		static dataset_t* _sexs;
		static dataset_t* _voices;

		// In-data
		static dataset_t* _items;
		static dataset_t* _skills;
		static dataset_t* _jewels;

		// Equipment types
		static dataset_t* _equipmentTypes;
		static dataset_t* _chestArmors;
		static dataset_t* _armsArmors;
		static dataset_t* _waistArmors;
		static dataset_t* _legsArmors;
		static dataset_t* _headArmors;
		static dataset_t* _charms;
		static dataset_t* _gsWeapons;
		static dataset_t* _snsWeapons;
		static dataset_t* _hWeapons;
		static dataset_t* _lWeapons;
		static dataset_t* _hbgWeapons;
		static dataset_t* _lbgWeapons;
		static dataset_t* _lsWeapons;
		static dataset_t* _saWeapons;
		static dataset_t* _glWeapons;
		static dataset_t* _bowWeapons;
		static dataset_t* _dbWeapons;
		static dataset_t* _hhWeapons;
};

#endif // MH3U_DS_HPP
