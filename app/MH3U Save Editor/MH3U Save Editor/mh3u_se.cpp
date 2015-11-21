#include "mh3u_se.hpp"


MH3U_SE::MH3U_SE()
{
	savedata = NULL;
}


MH3U_SE::~MH3U_SE()
{
	cdelete(savedata);
}


void MH3U_SE::setFilename(std::string output)
{
	this->filename = output;
}


bool MH3U_SE::loaded()
{
	return (this->savedata != NULL);
}


bool MH3U_SE::load(std::string input)
{
	std::stringstream ss;
	std::ifstream fs;
	uint8_t tmp_c;

	try
	{
		fs.open(input.c_str(), std::fstream::in | std::fstream::binary);
	
		if (!fs)
		{
			return false;
		}

		while(fs.good())
		{
			fs.read((char*)&tmp_c, 1);
			ss.write((char*)&tmp_c, 1);
		}
		fs.close();

		this->filename = input;

		cdelete(savedata);
		savedata = new save_t();
	
		ss.seekg(SEX_OFFSET, ss.beg);
		ss.read((char*)&(savedata->sex), SEX_SIZE);

		ss.seekg(FACE_OFFSET, ss.beg);
		ss.read((char*)&(savedata->face), FACE_SIZE);

		ss.seekg(HAIR_OFFSET, ss.beg);
		ss.read((char*)&(savedata->hair), HAIR_SIZE);

		ss.seekg(NAME_OFFSET, ss.beg);
		ss.read((char*) (savedata->name), NAME_SIZE);

		ss.seekg(MONEY_OFFSET, ss.beg);
		ss.read((char*)&(savedata->money), MONEY_SIZE);
	
		ss.seekg(VOICE_OFFSET, ss.beg);
		ss.read((char*)&(savedata->voice), VOICE_SIZE);

		ss.seekg(INVENTORY_OFFSET, ss.beg);
		for (uint32_t i = 0; i < 3; i++)
		{
			for (uint32_t j = 0; j < 8; j++)
			{
				ss.read((char*)&(savedata->inventory[i][j].id), SHORT_SIZE);
				ss.read((char*)&(savedata->inventory[i][j].count), SHORT_SIZE);
			}
		}

		ss.seekg(POUCH_OFFSET, ss.beg);
		for (uint32_t i = 0; i < 4; i++)
		{
			for (uint32_t j = 0; j < 8; j++)
			{
				ss.read((char*)&(savedata->pouch[i][j].id), SHORT_SIZE);
				ss.read((char*)&(savedata->pouch[i][j].count), SHORT_SIZE);
			}
		}
	
		ss.seekg(CHEST_OFFSET, ss.beg);
		for (uint32_t i = 0; i < 10; i++)
		{
			for (uint32_t j = 0; j < 100; j++)
			{
				ss.read((char*)&(savedata->chest[i][j].id), SHORT_SIZE);
				ss.read((char*)&(savedata->chest[i][j].count), SHORT_SIZE);
			}
		}

		ss.seekg(BOX_OFFSET, ss.beg);
		for (uint32_t i = 0; i < 10; i++)
		{
			for (uint32_t j = 0; j < 100; j++)
			{
				ss.read((char*)&(savedata->box[i][j]), EQUIPMENT_SIZE);
			}
		}
		
		ss.seekg(MOGAPOINT_OFFSET, ss.beg);
		ss.read((char*)&(savedata->mogapoint), MOGAPOINT_SIZE);


		ss.seekg(0, ss.beg);
		for (uint32_t i = 0; ss.good() && i < SAVEFILE_SIZE; i++)
		{
			ss.read((char*)&tmp_c, BYTE_SIZE);
			buffer[i] = tmp_c;
		}
		
		return true;
	}
	catch (std::exception e)
	{
		cdelete(savedata);
		std::cout << "Problem with ::load!" << std::endl;
		return false;
	}
}


bool MH3U_SE::save()
{
	return save(filename);
}


bool MH3U_SE::save(std::string output)
{
	std::ofstream fs;

	try
	{
		if (!writeBuffer()) return false;

		fs.open(output.c_str(), std::fstream::out | std::fstream::binary);

		if (!fs)
		{
			return false;
		}

		for (uint32_t i = 0; i < SAVEFILE_SIZE; i++)
		{
			// std::cout << "Writing: " << std::hex << (int)(buffer[i]) << " @"<< i << std::endl;
			fs.write((char*)&(buffer[i]), BYTE_SIZE);
		}

		fs.close();

		return true;
	}
	catch(std::exception e)
	{
		std::cout << "Problem with ::save!" << std::endl;
		return false;
	}
}


bool MH3U_SE::writeBuffer()
{
	if (!savedata)
	{
		return false;
	}
	
	editBuffer(SEX_OFFSET, (uint8_t*)&(savedata->sex), SEX_SIZE);
	editBuffer(FACE_OFFSET, (uint8_t*)&(savedata->face), FACE_SIZE);
	editBuffer(HAIR_OFFSET, (uint8_t*)&(savedata->hair), HAIR_SIZE);
	editBuffer(NAME_OFFSET, (uint8_t*)(savedata->name), NAME_SIZE);
	editBuffer(MONEY_OFFSET, (uint8_t*)&(savedata->money), MONEY_SIZE);
	editBuffer(VOICE_OFFSET, (uint8_t*)&(savedata->voice), VOICE_SIZE);

	
	for (uint32_t i = 0; i < 3; i++)
	{
		for (uint32_t j = 0; j < 8; j++)
		{
			editBuffer(INVENTORY_OFFSET + ITEM_SIZE * (j + i*8), (uint8_t*)&(savedata->inventory[i][j].id), SHORT_SIZE);
			editBuffer(INVENTORY_OFFSET + ITEM_SIZE * (j + i*8) + SHORT_SIZE, (uint8_t*)&(savedata->inventory[i][j].count), SHORT_SIZE);
		}
	}

	
	for (uint32_t i = 0; i < 4; i++)
	{
		for (uint32_t j = 0; j < 8; j++)
		{
			editBuffer(POUCH_OFFSET + ITEM_SIZE * (j + i*8), (uint8_t*)&(savedata->pouch[i][j].id), SHORT_SIZE);
			editBuffer(POUCH_OFFSET + ITEM_SIZE * (j + i*8) + SHORT_SIZE, (uint8_t*)&(savedata->pouch[i][j].count), SHORT_SIZE);
		}
	}

	
	for (uint32_t i = 0; i < 10; i++)
	{
		for (uint32_t j = 0; j < 100; j++)
		{
			editBuffer(CHEST_OFFSET + ITEM_SIZE * (j + i*100), (uint8_t*)&(savedata->chest[i][j].id), SHORT_SIZE);
			editBuffer(CHEST_OFFSET + ITEM_SIZE * (j + i*100) + SHORT_SIZE, (uint8_t*)&(savedata->chest[i][j].count), SHORT_SIZE);
		}
	}


	for (uint32_t i = 0; i < 10; i++)
	{
		for (uint32_t j = 0; j < 100; j++)
		{
			editBuffer(BOX_OFFSET + EQUIPMENT_SIZE * (j + i*100), (uint8_t*)(savedata->box[i][j]), EQUIPMENT_SIZE);
		}
	}
	
	editBuffer(MOGAPOINT_OFFSET, (uint8_t*)&(savedata->mogapoint), MOGAPOINT_SIZE);

	return true;
}


void MH3U_SE::editBuffer(uint32_t pos, uint8_t* ptr, uint8_t size)
{
	if (!savedata) return;

	for (uint32_t i = pos; i < SAVEFILE_SIZE && pos >= 0 && i < pos + size; i++)
	{
		buffer[i] = ptr[i-pos];
	}
}


equipment_subtype_e MH3U_Armory::convertSubtype(uint8_t equipmentType)
{
	return MH3U_Armory::convertSubtype((equipment_type_e) equipmentType);
}


equipment_subtype_e MH3U_Armory::convertSubtype(equipment_type_e equipmentType)
{
	equipment_subtype_e subtype;

	switch (equipmentType)
	{
		case MH3U_Type::ChestType:
		case MH3U_Type::ArmsType:
		case MH3U_Type::WaistType:
		case MH3U_Type::LegsType:
		case MH3U_Type::HeadType:
		{
			subtype = MH3U_Type::ArmorSubtype;
			break;
		}
		case MH3U_Type::CharmType:
		{
			subtype = MH3U_Type::CharmSubtype;
			break;
		}
		case MH3U_Type::GSType:
		case MH3U_Type::SNSType:
		case MH3U_Type::HType:
		case MH3U_Type::LType:
		case MH3U_Type::HBGType:
		case MH3U_Type::LBGType:
		case MH3U_Type::LSType:
		case MH3U_Type::SAType:
		case MH3U_Type::GLType:
		case MH3U_Type::BowType:
		case MH3U_Type::DBType:
		case MH3U_Type::HHType:
		{
			subtype = MH3U_Type::WeaponSubtype;
			break;
		}
		case MH3U_Type::UnknowType:
		default:
		{
			subtype = MH3U_Type::NoneSubtype;
			break;
		}
	}

	return subtype;
}


armor_t MH3U_Armory::convertEquipmentToArmor(equipment_t &equipment)
{
	armor_t armor;

	armor.equipmentType = equipment[0];
	armor.upgradeLevel = equipment[1];
	armor.identifier = equipment[2] + equipment[3] * 0x100;
	armor.foo31 = equipment[4];
	armor.blueComponent = equipment[5];
	armor.greenComponent = equipment[6];
	armor.redComponent = equipment[7];
	armor.firstJewelIdentifier = equipment[8] + equipment[9] * 0x100;
	armor.secondJewelIdentifier = equipment[10] + equipment[11] * 0x100;
	armor.thirdJewelIdentifier = equipment[12] + equipment[13] * 0x100;
	armor.foo81 = equipment[14];
	armor.foo82 = equipment[15];

	return armor;
}


void MH3U_Armory::convertArmorToEquipment(armor_t &armor, equipment_t &equipment)
{
	(equipment[0]) = armor.equipmentType;
	(equipment[1]) = armor.upgradeLevel;
	(equipment[2]) = armor.identifier % 0x100;
	(equipment[3]) = armor.identifier / 0x100;
	(equipment[4]) = armor.foo31;
	(equipment[5]) = armor.blueComponent;
	(equipment[6]) = armor.greenComponent;
	(equipment[7]) = armor.redComponent;
	(equipment[8]) = armor.firstJewelIdentifier % 0x100;
	(equipment[9]) = armor.firstJewelIdentifier / 0x100;
	(equipment[10]) = armor.secondJewelIdentifier % 0x100;
	(equipment[11]) = armor.secondJewelIdentifier / 0x100;
	(equipment[12]) = armor.thirdJewelIdentifier % 0x100;
	(equipment[13]) = armor.thirdJewelIdentifier / 0x100;
	(equipment[14]) = armor.foo81;
	(equipment[15]) = armor.foo82;
}


charm_t MH3U_Armory::convertEquipmentToCharm(equipment_t &equipment)
{
	charm_t charm;

	charm.equipmentType = equipment[0];
	charm.slotsCount = equipment[1];
	charm.identifier = equipment[2] + equipment[3] * 0x100;
	charm.firstSkillIdentifier = equipment[4];
	charm.firstSkillValue = equipment[5];
	charm.secondSkillIdentifier = equipment[6];
	charm.secondSkillValue = equipment[7];
	charm.firstJewelIdentifier = equipment[8] + equipment[9] * 0x100;
	charm.secondJewelIdentifier = equipment[10] + equipment[11] * 0x100;
	charm.thirdJewelIdentifier = equipment[12] + equipment[13] * 0x100;
	charm.foo81 = equipment[14];
	charm.foo82 = equipment[15];

	return charm;
}


void MH3U_Armory::convertCharmToEquipment(charm_t &charm, equipment_t &equipment)
{
	(equipment[0]) = charm.equipmentType;
	(equipment[1]) = charm.slotsCount;
	(equipment[2]) = charm.identifier % 0x100;
	(equipment[3]) = charm.identifier / 0x100;
	(equipment[4]) = charm.firstSkillIdentifier;
	(equipment[5]) = charm.firstSkillValue;
	(equipment[6]) = charm.secondSkillIdentifier;
	(equipment[7]) = charm.secondSkillValue;
	(equipment[8]) = charm.firstJewelIdentifier % 0x100;
	(equipment[9]) = charm.firstJewelIdentifier / 0x100;
	(equipment[10]) = charm.secondJewelIdentifier % 0x100;
	(equipment[11]) = charm.secondJewelIdentifier / 0x100;
	(equipment[12]) = charm.thirdJewelIdentifier % 0x100;
	(equipment[13]) = charm.thirdJewelIdentifier / 0x100;
	(equipment[14]) = charm.foo81;
	(equipment[15]) = charm.foo82;
}


weapon_t MH3U_Armory::convertEquipmentToWeapon(equipment_t &equipment)
{
	weapon_t weapon;

	weapon.equipmentType = equipment[0];
	weapon.foo12 = equipment[1];
	weapon.identifier = equipment[2] + equipment[3] * 0x100;
	weapon.foo31 = equipment[4];
	weapon.foo32 = equipment[5];
	weapon.foo41 = equipment[6];
	weapon.foo42 = equipment[7];
	weapon.firstJewelIdentifier = equipment[8] + equipment[9] * 0x100;
	weapon.secondJewelIdentifier = equipment[10] + equipment[11] * 0x100;
	weapon.thirdJewelIdentifier = equipment[12] + equipment[13] * 0x100;
	weapon.foo81 = equipment[14];
	weapon.foo82 = equipment[15];

	return weapon;
}


void MH3U_Armory::convertWeaponToEquipment(weapon_t &weapon, equipment_t &equipment)
{
	(equipment[0]) = weapon.equipmentType;
	(equipment[1]) = weapon.foo12;
	(equipment[2]) = weapon.identifier % 0x100;
	(equipment[3]) = weapon.identifier / 0x100;
	(equipment[4]) = weapon.foo31;
	(equipment[5]) = weapon.foo32;
	(equipment[6]) = weapon.foo41;
	(equipment[7]) = weapon.foo42;
	(equipment[8]) = weapon.firstJewelIdentifier % 0x100;
	(equipment[9]) = weapon.firstJewelIdentifier / 0x100;
	(equipment[10]) = weapon.secondJewelIdentifier % 0x100;
	(equipment[11]) = weapon.secondJewelIdentifier / 0x100;
	(equipment[12]) = weapon.thirdJewelIdentifier % 0x100;
	(equipment[13]) = weapon.thirdJewelIdentifier / 0x100;
	(equipment[14]) = weapon.foo81;
	(equipment[15]) = weapon.foo82;
}
