inherit "/std/armour";

#define MINUTE (60)
#define DURATION (12*MINUTE)

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

void set_charge(int x){ jewel_data["charges"] = x; }
void query_charge(){ return jewel_data["charges"];}

int wear_equipment() {
    if(jewel_data["charges"] > 0)
	jewel_data["charges"]--;
    jewel_data["last wear"] = time();
    return 1;
}

int remove_equipment(){return 1;}

init(){
    ::init();
    setup();
    set_wear((: call_other,this_object(), "wear_equipment" :));
    set_remove((: call_other,this_object(), "remove_equipment" :));
}


void query_skill(){ return jewel_data["skill"]; }
void set_skill(string skill){
    jewel_data["skill"] = skill;
}

void query_spell(){ return jewel_data["spell"]; }
void set_spell(string spell){
    jewel_data["spell"] = spell;
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

string query_short(){
    string title = "strange";
    int i, x;
    string *titles = ({
      "Undesireable", "Cheap", "Flashy", "Catchy", "Charming",
      "Impressive", "Extravegent", "Captivating", "Magnificent", 
      "Breath-taking", "Eye-popping", "Awe-Inspiring" });
    x = ((int)query_property("create skill")) / 27;
    if(x > sizeof(titles) - 1)
	x = sizeof(titles) - 1;
    title = titles[x];
    return title + " " + ::query_short();
}

string query_charge_desc(){
    if(jewel_data["charges"] < 1)
	return "none";
    if(jewel_data["charges"] < 4)
	return "very small";
    if(jewel_data["charges"] < 8)
	return "small";
    if(jewel_data["charges"] < 12)
	return "moderate";
    if(jewel_data["charges"] < 16)
	return "good";
    if(jewel_data["charges"] < 20)
	return "great";
    if(jewel_data["charges"] < 26)
	return "huge";
    if(jewel_data["charges"] < 31)
	return "nearly full";
    if(jewel_data["charges"] < 36)
	return "full";
    return "bugged";
}

string query_long(string str){
    string title = ::query_long(str);
    if(jewel_data["skill"]){
	title += "\n\nThis item contains the skill: "
	+jewel_data["skill"]+"\n";
    }
    if(jewel_data["spell"]){
	title += "\n\nThis item contains the spell: "
	+jewel_data["spell"]+"\n";
    }
    if(jewel_data["spell"] || jewel_data["skill"])
	title += "The charge of this item is: " + query_charge_desc() +
	"\n";
    return title;
}

int rate(int base, int x, int y){
    return (base * x) / y;
}

// higher is worse
int mod(){
    switch(query_type()){
    case "ring":
	return 3;
	break;
    case "amulet":
	return 1;
	break;
    case "bracelet":
	return 2;
	break;
    }
    return 1;
}

#define HIGH 100

mapping get_bonuses(mapping inp){
    string mat = query_material();
    mapping mp = inp;
    int skill = query_property("create skill");
    mat = replace_string(mat, "metal", "");
    mat = replace_string(mat, "/", "");


    if(!mp)mp = ([]);
    switch(mat){
    case "diamond":
	mp["hp bonus"] = mp["hp bonus"] + rate(45, skill, mod() * HIGH)+10;
	break;
    case "ruby":
	mp["skill attack"] = mp["skill attack"] + rate(30, skill, mod() * HIGH)+10;
	break;
    case "emerald":
	mp["mp regen"] = mp["mp regen"] + rate(85, skill, mod() * HIGH)+10;
	break;
    case "jade":
	mp["stat bonus intelligence"] = mp["stat bonus intelligence"] + rate(20, skill, mod() * HIGH)+10;
	break;
    case "obsidian":
	mp["stat bonus constitution"] = mp["stat bonus constitution"] + rate(20, skill, mod() * HIGH)+10;
	break;
    case "amethyst":
	mp["stat bonus wisdom"] = mp["stat bonus wisdom"] + rate(20, skill, mod() * HIGH)+10;
	break;
    case "turquoise":
	mp["skill perception"] = mp["skill perception"] + rate(25, skill, mod() * HIGH)+10;
	break;
    case "sapphire":
	mp["mp bonus"] = mp["mp bonus"] + rate(60, skill, mod() * HIGH)+10;
	break;
    case "onyx":
	mp["ac bonus"] = mp["ac bonus"] + rate(15, skill, mod() * HIGH)+5;
	break;
    case "quartz":
	mp["skill luck"] = mp["skill luck"] + rate(2, skill, mod() * HIGH)+1;
	break;
    }
    if(jewel_data["skill"] && jewel_data["charges"] > 0 
      && jewel_data["last wear"] > time() - DURATION)
	mp["skill " + jewel_data["skill"]] = 25 
	+ (int)mp["skill " + jewel_data["skill"]];
    if(jewel_data["spell"] && jewel_data["charges"] > 0 
      && jewel_data["last wear"] > time() - DURATION)
	mp["spell " + jewel_data["spell"]] = 2 
	+ (int)mp["spell " + jewel_data["spell"]];
    return mp;
}
