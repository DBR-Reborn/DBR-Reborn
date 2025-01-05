inherit "/std/armour";

mapping jewel_data = ([]);
mapping misc = ([]);

void setup(){
    ::set_name(jewel_data["name"]);
    ::set_id(jewel_data["id"]);
    ::set_short(jewel_data["short"]);
    ::set_long(jewel_data["long"]);
    set_weight(2);
    set_value(0);
    ::set_type(jewel_data["type"]);
    ::set_limbs(jewel_data["limbs"]);
    set_ac(5);
    ::set_material(jewel_data["material"]);
}

void create(){
    ::create();
    setup();
}

init(){
    ::init();
    setup();
}

void set_short(mixed x){ jewel_data["short"] = x; ::set_short(x);}
void set_long(mixed x){ jewel_data["long"] = x; ::set_long(x);}
void set_id(mixed x){ jewel_data["id"] = x; ::set_id(x);}
void set_type(mixed x){ jewel_data["type"] = x; ::set_type(x);}
void set_limbs(mixed x){ jewel_data["limbs"] = x; ::set_limbs(x);}
void set_material(mixed x){ jewel_data["material"] = x; ::set_material(x);}
void set_name(mixed x){ jewel_data["name"] = x; ::set_name(x);}

int is_jewelry() { return 1; }
int is_gem() { return 1; }

int has_bonuses(){ return 1;}

mapping get_bonuses(mapping inp){
    string mat = query_material();
    mapping mp = inp;
    mat = replace_string(mat, "metal", "");
    mat = replace_string(mat, "/", "");


    if(!mp)mp = ([]);
    switch(mat){
    case "diamond":
	mp["hp bonus"] = mp["hp bonus"] + 45;
	break;
    case "ruby":
	mp["skill attack"] = mp["skill attack"] + 30;
	break;
    case "emerald":
	mp["mp regen"] = mp["mp regen"] + 25;
	break;
    case "jade":
	mp["stat bonus intelligence"] = mp["stat bonus intelligence"] + 20;
	break;
    case "obsidian":
	mp["stat bonus constitution"] = mp["stat bonus constitution"] + 20;
	break;
    case "amethyst":
	mp["stat bonus wisdom"] = mp["stat bonus wisdom"] + 20;
	break;
    case "turquoise":
	mp["skill perception"] = mp["skill perception"] + 25;
	break;
    case "sapphire":
	mp["mp bonus"] = mp["mp bonus"] + 60;
	break;
    case "onyx":
	mp["ac bonus"] = mp["ac bonus"] + 15;
	break;
    case "quartz":
	mp["skill luck"] = mp["skill luck"] + 4;
	break;
    }
    return mp;
}
