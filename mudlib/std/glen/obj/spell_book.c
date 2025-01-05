//    A spell scroll

inherit "/std/Object";

// storage format
// [number]
//  [spell name]
//  [power]
//  [element]

mapping *spells = ({ });
string name;
static object ele_shad;
static object skill_shad;

void create() {
    ::create();
    set_property("self power", 1);
    set_short("A spell book");
    set_long("This book contains a variety of spells.");
    set_id(({ "book", "spell book"}));
    set_name("book");
    set_weight(30);
    set_value(200);
    return;
}

void add_spell(string spell, int power, string extra){
    int x;
    if(!spells)
	spells = ({ });
    spells += ({ ([ "spell name" : spell,
	"power" : power,
	"element" : extra ]) });
}

mapping find_spell(string spell){
    int i;
    if(!spells)
	return ([]);
    for(i = 0; i < sizeof(spells); i++)
	if(spells[i]["spell name"] == spell)
	    return spells[i];
    return ([]);
}

void delete_spell(string spell){
    int i;
    if(!spells)
	return;
    for(i = 0; i < sizeof(spells); i++)
	if(spells[i]["spell name"] == spell){
	    spells = exclude_array(spells, i);
	    return;
	}
}

string query_long(string null) {
    int i;
    string res;
    string spd = "";

    res = ::query_long(null);
    if(!spells) return res;

    for(i = 0; i < sizeof(spells); i++)
	spd += sprintf("%s at *%d\n", 
	  spells[i]["spell name"], spells[i]["power"]);

    res += "\n\n";
    res += 
    "This book has the following spells in it: \n"+
    "-----------------------------------------------\n"+
    spd +
    "-----------------------------------------------\n"+
    "Cast a spell with with 'read <spell> from <book> " +
    "at <args>'." +
    "  <args> is whatever would come after 'at' when casting the "
    "spell normally, if anything.  "+
    "Example: read fireball from book at skeleton.\n\n";
    return res;
}

void init() {
    ::init();
    add_action("cast_spell", "read");
    return;
}

int cast_spell(string str) {
    string me, file, args, ele;
    object spell_ob, tmp;
    int cost;
    mapping spell;

    args = 0;
    if(sscanf(str, "%s from %s at %s", name, me, args) != 3) {
	if(sscanf(str, "%s from %s", name, me) != 2)
	    return notify_fail("Read what spell from what tomb?\n");
    }
    if(present(me, this_player()) != this_object())
	return notify_fail("You do not have "+article(me)+".\n");

    spell = find_spell(name);

    if(!spell || !spell["spell name"]) {
	write("That spell is not scribed on this tomb.");
	return 1;
    }

    file = "/std/spells/"+replace_string(name, " ", "_");
    if(!file_exists(file+".c")) {
	write("Cannot find spell file...BUG");
	return 1;
    }
    seteuid(getuid());
    spell_ob = new(file);
    spell_ob->set_property("casting time", 2);
    cost = (int)spell_ob->query_proeprty("base mp cost");
    cost /= query_property("self power");
    if(cost < 1) cost = 1;

    spell_ob->set_property("base mp cost", cost);
    spell_ob->set_property("skill", "tmp skill");
    this_player()->set_skill("tmp skill", 110);
    call_out("remove_skill", 5, this_player());

    if(spell_ob->query_property("elemental spell") &&
      !objectp(this_player()->query("ele shadow"))) {
	ele = spell["element"];
	if(!ele) {
	    write("You must use an elemental lore skill to "+
	      "read this scroll.");
	    return 1;
	}
	tmp = new("/std/spells/shadows/ele_shadow");
	tmp->set_element(ele);
	tmp->start_shadow(this_player());
	ele_shad = tmp;
    }
    tmp = new("/std/spells/shadows/skill_shadow");
    tmp->add_spell(spell["spell name"], spell["power"]);
    tmp->start_shadow(this_player());
    skill_shad = tmp;
    tmp = (object)this_player()->query_casting();
    this_player()->set_casting(0);
    spell_ob->begin_casting(this_player(), args, spell["power"]);
    if(tmp) this_player()->set_casting(tmp);
    return 1;
}

void remove_skill(object who) {
    if(!who) return;
    who->delete_skill("tmp skill");
    if(ele_shad) ele_shad->external_destruct(ele_shad);
    if(skill_shad) skill_shad->external_destruct(skill_shad);
    delete_spell(name);
    if(sizeof(spells) < 1){
	message("info", "You discard the empty book.", who);
	remove();
    }
    return;
}

