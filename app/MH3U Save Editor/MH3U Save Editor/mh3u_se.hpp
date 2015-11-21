#ifndef MH3U_SE_HPP
#define MH3U_SE_HPP

#include "main.hpp"

/* --------- Constants --------- */

#define BYTE_SIZE 0x1
#define SHORT_SIZE 0x2
#define INT_SIZE 0x4

#define SEX_SIZE BYTE_SIZE
#define FACE_SIZE BYTE_SIZE
#define HAIR_SIZE BYTE_SIZE
#define NAME_SIZE 0x000a
#define MONEY_SIZE INT_SIZE
#define VOICE_SIZE BYTE_SIZE
#define ITEM_SIZE INT_SIZE
#define EQUIPMENT_SIZE 0x0010
#define INVENTORY_SIZE 0x0060
#define POUCH_SIZE 0x0080
#define CHEST_SIZE 0x0fa0
#define BOX_SIZE 0x1f40
#define MOGAPOINT_SIZE INT_SIZE
#define SAVEFILE_SIZE  0x8a00

#define SEX_OFFSET 0x0004
#define FACE_OFFSET 0x0005
#define HAIR_OFFSET 0x0006
#define NAME_OFFSET 0x0007
#define MONEY_OFFSET 0x0024
#define VOICE_OFFSET 0x00ab
#define INVENTORY_OFFSET 0x00ac
#define POUCH_OFFSET 0x010c
#define CHEST_OFFSET 0x018c
#define BOX_OFFSET 0x112c
#define MOGAPOINT_OFFSET 0x5b2c

///
/// Sex: Sexe
/// Face: Type du visage
/// Hair: Type de coiffure
/// Name: Nom
/// Money: Monnaie
/// Voice: Type de voix
/// Item: objet
/// Inventory: Inventaire épéiste
/// Pouch: Inventaire artilleur
/// Chest: Boîte à objets
/// Box: Boîte à équipements
///

#define CHARACTER_WEAPON 0x7a34

/* --------- Structures --------- */

typedef struct item_t
{
	uint16_t id;
	uint16_t count;
} item_t;

typedef uint8_t name_t[NAME_SIZE];
typedef uint8_t equipment_t[EQUIPMENT_SIZE];

typedef struct armor_t
{
	uint8_t equipmentType;
	uint8_t upgradeLevel;
	uint16_t identifier;
	uint8_t foo31;
	uint8_t blueComponent;
	uint8_t greenComponent;
	uint8_t redComponent;
	uint16_t firstJewelIdentifier;
	uint16_t secondJewelIdentifier;
	uint16_t thirdJewelIdentifier;
	uint8_t foo81;
	uint8_t foo82;
} armor_t;

typedef struct charm_t
{
	uint8_t equipmentType;
	uint8_t slotsCount;
	uint16_t identifier;
	uint8_t firstSkillIdentifier;
	uint8_t firstSkillValue;
	uint8_t secondSkillIdentifier;
	uint8_t secondSkillValue;
	uint16_t firstJewelIdentifier;
	uint16_t secondJewelIdentifier;
	uint16_t thirdJewelIdentifier;
	uint8_t foo81;
	uint8_t foo82;
} charm_t;

typedef struct weapon_t
{
	uint8_t equipmentType;
	uint8_t foo12;
	uint16_t identifier;
	uint8_t foo31;
	uint8_t foo32;
	uint8_t foo41;
	uint8_t foo42;
	uint16_t firstJewelIdentifier;
	uint16_t secondJewelIdentifier;
	uint16_t thirdJewelIdentifier;
	uint8_t foo81;
	uint8_t foo82;
} weapon_t;


typedef struct save_t
{
	uint8_t sex;
	uint8_t face;
	uint8_t hair;
	name_t name;
	uint32_t money;
	uint8_t voice;
	item_t inventory[3][8];
	item_t pouch[4][8];
	item_t chest[10][100];
	equipment_t box[10][100];
	uint32_t mogapoint;
} save_t;

typedef uint8_t save_buffer_t[SAVEFILE_SIZE];


/* --------- Class --------- */

class MH3U_SE
{
	public:
		MH3U_SE();
		~MH3U_SE();

		// Propriété : `filename`
		void setFilename(std::string output);
		// Propriété bool : `savedata`
		bool loaded();


		// Convertit un fichier en savedata et en buffer
		bool load(std::string input);
		// Convertit un savedata et un buffer en fichier
		bool save();
		bool save(std::string output);

		save_t* savedata;

	private:
		// Ecrit le contenu du buffer dans la variable savedata
		bool writeBuffer();
		// Permet de modifier par bout le buffer
		void editBuffer(uint32_t pos, uint8_t* ptr, uint8_t size);
		save_buffer_t buffer;
		std::string filename;
		
};

/*
#define CHEST_TYPE 1
#define ARMS_TYPE 2
#define WAIST_TYPE 3
#define LEGS_TYPE 4
#define HEAD_TYPE 5
#define CHARM_TYPE 6
#define GS_TYPE 7
#define SNS_TYPE 8
#define H_TYPE 9
#define L_TYPE 10
#define HBG_TYPE 11
#define UNKNOWN_TYPE 12
#define LBG_TYPE 13
#define LS_TYPE 14
#define SA_TYPE 15
#define GL_TYPE 16
#define BOW_TYPE 17
#define DB_TYPE 18
#define HH_TYPE 19
*/

namespace MH3U_Type
{
	typedef enum equipment_type_e
	{
		NoneType = 0,
		ChestType = 1,
		ArmsType = 2,
		WaistType = 3,
		LegsType = 4,
		HeadType = 5,
		CharmType = 6,
		GSType = 7,
		SNSType = 8,
		HType = 9,
		LType = 10,
		HBGType = 11,
		UnknowType = 12,
		LBGType = 13,
		LSType = 14,
		SAType = 15,
		GLType = 16,
		BowType = 17,
		DBType = 18,
		HHType = 19,
	} equipment_type_e;

	typedef enum equipment_subtype_e
	{
		NoneSubtype = 0,
		ArmorSubtype = 1,
		CharmSubtype = 2,
		WeaponSubtype = 3,
	} equipment_subtype_e;

}

typedef MH3U_Type::equipment_subtype_e equipment_subtype_e;
typedef MH3U_Type::equipment_type_e equipment_type_e;

class MH3U_Armory
{
	public:
		static equipment_subtype_e convertSubtype(uint8_t equipmentType);
		static equipment_subtype_e convertSubtype(equipment_type_e equipmentType);
		static armor_t convertEquipmentToArmor(equipment_t &equipment);
		static void convertArmorToEquipment(armor_t &armor, equipment_t &equipment);
		static charm_t convertEquipmentToCharm(equipment_t &equipment);
		static void convertCharmToEquipment(charm_t &charm, equipment_t &equipment);
		static weapon_t convertEquipmentToWeapon(equipment_t &equipment);
		static void convertWeaponToEquipment(weapon_t &weapon, equipment_t &equipment);
};

#endif // MH3U_SE_HPP
