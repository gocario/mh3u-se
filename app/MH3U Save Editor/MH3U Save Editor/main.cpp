/**
 * Research
 * Entry
 * Point
 */
 
#include "main.hpp"
#include "mh3u_se.hpp"
#include "mh3u_ds.hpp"

int mh3u_se(int argc, char* argv[]);
int mh3u_ds(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	return mh3u_se(argc, argv);
	//return mh3u_ds(argc, argv);
}

int mh3u_se(int argc, char* argv[])
{
	MH3U_SE *mh3u = new MH3U_SE();

	mh3u->load("H:/Users/Gocario/Documents/Monster Hunter/Monster Hunter 3 Ultimate/save/analyse/user3_eq_2");

	uint8_t type = MH3U_Type::DBType;
	for (uint32_t i = 1; i < 5; i++)
	{
		for (uint32_t j = 0; j < 100; j++)
		{
			equipment_t &eq = mh3u->savedata->box[i][j];
			
			(eq[0x0]) = type; // TYPE
			(eq[0x1]) = 0x00; // LEVEL
			(eq[0x2]) = 0x0f; // ID
			(eq[0x3]) = 0x00; // ID
			(eq[0x4]) = (i == 1 ? j : 0x00); // ??
			(eq[0x5]) = (i == 2 ? j : 0x00); // COLOR
			(eq[0x6]) = (i == 3 ? j : 0x00); // COLOR
			(eq[0x7]) = (i == 4 ? j : 0x00); // COLOR
			(eq[0x8]) = 0x00; // JEWEL 1
			(eq[0x9]) = 0x00; // JEWEL 1
			(eq[0xa]) = 0x00; // JEWEL 2
			(eq[0xb]) = 0x00; // JEWEL 2
			(eq[0xc]) = 0x00; // JEWEL 3
			(eq[0xd]) = 0x00; // JEWEL 3
			(eq[0xe]) = 0x00; // ??
			(eq[0xf]) = 0x00; // ??
		}
	}
	
	/*
	uint16_t identifier = 0x03e8;
	for (uint32_t i = 0; i < 10; i++)
	{
		for (uint32_t j = 0; j < 100; j++)
		{
			item_t &it = mh3u->savedata->chest[i][j];
			
			it.id = identifier;
			it.count = 0x0010;

			identifier++;
		}
	}
	*/

	mh3u->save("H:/Users/Gocario/Documents/Monster Hunter/Monster Hunter 3 Ultimate/save/analyse/user_colors");

	cdelete(mh3u);

	return 0;
}

int mh3u_ds(int argc, char* argv[])
{
	MH3U_DS::readData(LANG_FR);
	MH3U_DS::deleteData();

	return 0;
}
