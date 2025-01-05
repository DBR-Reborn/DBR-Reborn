// Cleave - the main combat skill of RIs everywhere

inherit "/std/skills/skill";

string messagefrom;
string messageat;
string messageother;
int firsthit=1;

int do_cleave(object from, string at, int bonus, int reflex);
void randhitmess(object from, object at);
int team_check(object from);
int target_check(string *guy);

void create() {
    ::create();
    set_stat("dexterity");
    set_dev_cost(10);
    set_fast_dev_cost(40);
    set_property("no target",1);
}

void info() {
    message("help",
      "The user of this skill may attempt to cleave in twain 1 to 4 opponents. Fighters with especially high reflexes will sometimes strike their opponent twice, and those with high ability in scythe have a much higher chance of hitting multiple opponents. Of course, being good at cleaving will affect how hard you hit them, too...\nSyntax: use cleave at <enemy1>,<enemy2>,<enemy3>,<enemy4>\nExample: use cleave at huma, khelemvor, viado\nNote: You may specify from one to four enemies, however, they all must be different.",
      this_player());
}

void skill_func(object from, object at, string arg) {
    string *guy=allocate(4);
    int i;
    int bonus=0;

    if((time() - (int)from->query_last_use("cleave")) < 10)    {
	message("info", "You're still recovering from your last swing!"	  , from);
	return;
    }

    if(environment(from) &&
      environment(from)->query_property("no attack")) {
	message("info", "Mystic forces prevent your action.", from);
	remove();
	return ;
    }
    if(!from->query_wielded() || from->query_wielded() == ({ }) ) {
	message("info", "You can't use cleave without a weapon wielded.", from);
	remove();
	return;
    }

    guy=explode(arg, ",");
    if(sizeof(guy)>4){
	message("info", "You have specified too many targets.", from);
	remove();
	return ;
    }

    for(i = 0;i<sizeof(guy);i++) {
	if(!present(guy[i], environment(from))) {
	    message("info", "You do not see " + guy[i] + " here.", from);
	    remove();
	    return;
	}
    }

    if(!target_check(guy)){
	message("info", "You cannot specify two targets as the same.", from);
	remove();
	return;
    }


    from->set_last_use("cleave");


    // Runs through each of the people specified
    // If the first cleave succeeds, it checks for reflexes
    for(i=0;i<sizeof(guy);i++){
	// Grab team tactics bonus
	bonus=team_check(from);
	if(do_cleave(from, guy[i], bonus, 0))
	    do_cleave(from, guy[i], bonus, 1);
	firsthit=0;
    }

    remove();
    return;
}

// Selects a random hit message
void randhitmess(object from, object at){
from->add_exp2(15 * props["skill level"]+(this_player()->query_level()*100));
    switch(random(5)){
    case 0:
	messagefrom="With mind-boggling skill, you lift your weapon to the sky, and hit "+(string)at->query_cap_name()+" with unbelievable force. "+(string)at->query_cap_name()+" recoils in abject pain.";
	messageat="With mind-boggling skill, "+from->query_cap_name() +" lifts "+from->query_possessive()+" weapon to the sky and hits you with unbelievable force. You recoil in abject pain.";
	messageother="With mind-boggling skill, "+from->query_cap_name() +" lifts "+from->query_possessive()+" weapon to the sky and hits "+(string)at->query_cap_name()+" with unbelievable force. "+(string)at->query_cap_name()+" recoils in abject pain.";
	break;      
    case 1:
	messagefrom="In the heavens high above, angels write a legend of the awesome power of the blow you have just delivered to "+(string)at->query_cap_name()+". For thousands of years, Lidfino's angels will curse you for giving such pain to a living thing.";
	messageat="In the heavens high above, angels write a legend of the awesome power of the blow that "+from->query_cap_name() +" has just delivered to you. For thousands of years, Lidfino's angels will curse "+from->query_objective()+"for giving such pain to a living thing.";
	messageother="In the heavens high above, angels write a legend of the awesome power of the blow that "+from->query_cap_name() +" has just delivered to "+(string)at->query_cap_name()+". For thousands of years, Lidfino's angels will curse "+from->query_objective()+"for giving such pain to a living thing.";
	break;
    case 2:
	messagefrom="Ripping straight through armour, flesh, and bone, "+(string)at->query_cap_name()+" is truly demolished by your powerful cleave. A virtual stream of blood and gore announces that, indeed, you are the greatest warrior of all.";
	messageat="Ripping straight through armour, flesh, and bone, you are truly demolished by "+from->query_cap_name()+"'s power cleave. A virtual stream of blood and gore announces that, indeed, "+from->query_subjective()+" is the greatest warrior of all.";
	messageother="Ripping straight through armour, flesh, and bone, "+(string)at->query_cap_name()+" is truly demolished by "+from->query_cap_name()+"'s power cleave. A virtual stream of blood and gore announces that, indeed, "+from->query_subjective()+" is the greatest warrior of all.";
	break;
    case 3:
	messagefrom="Feinting to your left for a split-second, "+(string)at->query_cap_name()+" is momentarily taken off guard by your skillful move! In an awe-inspiring display of weapon prowess, you heft your weapon high and cleave it into "+(string)at->query_cap_name()+".";
	messageat="Feinting to "+(string)from->query_possessive()+" left for a split-second, you are momentarily taken off guard by "+(string)from->query_cap_name()+"'s his skillful move! In an awe-inspiring display of weapon prowess, "+(string)from->query_subjective()+" hefts "+(string)from->query_possessive()+" weapon high and cleaves it into you.";
	messageother="Feinting to "+(string)from->query_possessive()+" left for a split-second, "+(string)at->query_cap_name()+" is momentarily taken off guard by "+(string)from->query_cap_name()+"'s his skillful move! In an awe-inspiring display of weapon prowess, "+(string)from->query_subjective()+" hefts "+(string)from->query_possessive()+" weapon high and cleaves it into "+(string)at->query_cap_name()+".";
	break;
    case 4:
	messagefrom="In an effort to distract "+(string)at->query_cap_name()+", you raise your weapon above your head and swing it round and round. Your opponent is amazed at your skill, and stands there gaping... until you brutally slam the weapon into "+at->query_objective()+".";
	messageat="In an effort to distract you, "+(string)from->query_cap_name()+" raises "+(string)from->query_possessive()+" weapon above your head and swings it round and round. You are amazed at "+(string)from->query_possessive()+" skill, and stands there gaping... until "+(string)from->query_subjective()+" brutally slams the weapon into you.";
	messageother="In an effort to distract "+(string)at->query_cap_name()+", "+(string)from->query_cap_name()+" raises "+(string)from->query_possessive()+" weapon above your head and swings it round and round. "+at->query_cap_name()+" is amazed at "+(string)from->query_possessive()+" skill, and stands there gaping... until "+(string)from->query_subjective()+" brutally slams the weapon into "+(string)at->query_cap_name()+".";
	break;
    }
    return;
}

// Does a single cleave. Returns 1 if reflexes kick in for a second, 0 if not.
int do_cleave(object from, string atst, int bonus, int reflex){
    int flag, i;
    int cleaveskill = props["skill level"];
    int prot = 0;
    int damage = 0;
    int stunned;
    int miss = 0;
    object at;
    int reflexes;
    int strbonus;

    strbonus=from->query_stats("strength");

    at=present(atst, environment(from));
    stunned = at->query_paralyzed();
    if(!at){
	message("info", "You don't see "+atst+" here.", from);
	return 0;
    }

    // Since this check needs to be made per target, do it here
    if(at->shadow_form() || at->query_ghost()) {
	message("info", "You may not cleave a target which is immaterial.",
	  from);
	return 0;
    }  
    // For test use only
    if(firsthit)
	cleaveskill= from->query_skill("cleave");
    else
	cleaveskill= from->query_skill("scythe");

    prot = at->query_current_protection((string)at->return_target_limb(),"cutting");
    // No matter what, the two will fight each other
    from->kill_ob(at, 0);

    // conditions to miss
    if(cleaveskill < 0)
	miss = 1;
    if(!stunned){
	if(cleaveskill < (at->query_skill("dodge")/2 + random(15)))
	    miss = 1;
	if(cleaveskill < (at->query_skill("parry")/2 + random(20)))
	    miss = 1;
    }
    damage = (cleaveskill+bonus+strbonus) - (prot*(random(2)+4)/10);

    if(wizardp(this_player()))
	write("DEBUG: Cleave skill is "+cleaveskill+". Damage is: "+damage+" Bonus: " +bonus);

    if(!reflex)
	randhitmess(from, at);
    else {
	messagefrom="%^RED%^%^BOLD%^In an amazing display of reflexes, you suddenly cleave "+at->query_cap_name()+" again!%^RESET%^%^RESET%^";
	messageat="%^RED%^%^BOLD%^In an amazing display of reflexes, "+from->query_cap_name()+" suddenly cleaves you again!%^RESET%^%^RESET%^";
	messageother="%^RED%^%^BOLD%^In an amazing display of reflexes, "+from->query_cap_name()+" suddenly cleaves "+at->query_cap_name()+" again!%^RESET%^%^RESET%^";
    }

    if(bonus == 1) {
	message("my_combat", "%^RED%^%^BOLD%^Working in tandem with a fellow infantryman, you cleave "+(string)at->query_cap_name()+ " with help!%^RESET%^%^RESET%^", from);
	message("other_combat", "%^RED%^%^BOLD%^Working in tandem with a fellow infantryman, "+(string)from->query_cap_name() +	  " cleaves you with help!%^RESET%^%^RESET%^", at);
	message("other_combat", "%^RED%^%^BOLD%^Working in tandem with a fellow infantryman, "+(string)from->query_cap_name() + " cleaves "+ (string)at->query_cap_name()+ " with help!%^RESET%^%^RESET%^", all_inventory(environment(from)),	  ({ from, at }) );
    }

    if(damage < 0){
	message("my_combat", "You raise your weapon and cleave mightily at "+
	  (string)at->query_cap_name()+ " but it bounces off your opponent's armour.",
	  from);
	message("other_combat", (string)from->query_cap_name() +
	  " watches their cleave bounce off your armour.", at);
	message("other_combat", (string)from->query_cap_name() +
	  " smashes "+
	  (string)at->query_cap_name()+ "with a huge, smashing cleave, but it bounces off their armour.",
	  all_inventory(environment(from)),
	  ({ from, at }) );
	return 0;
    }

    if(miss){
	message("my_combat", "You raise your weapon and cleave mightily at "+
	  (string)at->query_cap_name()+ " but only hit thin air.",
	  from);
	message("other_combat", (string)from->query_cap_name() +
	  " barely misses you with a wicked cleave.", at);
	message("other_combat", (string)from->query_cap_name() +
	  " just misses "+
	  (string)at->query_cap_name()+ "with a huge, smashing cleave.",
	  all_inventory(environment(from)),
	  ({ from, at }) );
	return 0;
    }
    else
	message("my_combat", messagefrom, from);
    message("other_combat", messageat, at);
    message("other_combat", messageother, all_inventory(environment(from)), ({ from, at }) );
    // damage = skill - protection
    //        determines crits also
    at->do_damage((string)at->return_target_limb(), random(damage) + random(damage) + random(damage)/2 );
    do{
	switch(damage) {
	case -100000..5:
	    break;
	case 6..39:
	    do_critical(from, at, "cutting B");
	    break;
	case 40..64:
	    do_critical(from, at, "cutting C");
	    do_critical(from, at, "impact A");
	    break;
	case 65..84:
	    do_critical(from, at, "cutting D");
	    do_critical(from, at, "impact B");
	    break;
	case 85..94:
	    do_critical(from, at, "cutting E");
	    do_critical(from, at, "impact C");
	    break;
	case 95..10000:
	    do_critical(from, at, "cutting E");
	    do_critical(from, at, "impact D");
	    break;
	}
	damage = damage / 2;
    } while(damage > 30);

    // Reflex Check
    if(from->query_skill("reflexes")>at->query_skill("dodge"))
	reflexes=1;

    return reflexes;
}

int team_check(object from){
    int i;
    object *inv;
    int bonus=-1;
    int temp=0;
    int cleaveskill, tacticsskill;
    inv = all_inventory(from);
    while(i--) {
	if(living(inv[i])) {
	    if(inv[i]->query_class()=="fighter"){
		bonus+=1;
	    }
	}
    }

    // The "optimal number" of RIs doing team tactics cleaves is 3

    temp=(bonus*from->query_skill("team tactics"))/3;

    // Prevents people from more than doubling their cleave with team tactics.
    if(firsthit){
	if(temp>from->query_skill("cleave")) temp=from->query_skill("cleave");
    }
    else
    if(temp>from->query_skill("scythe")) temp=from->query_skill("cleave");

    return temp;
}

// Makes sure the user ain't trying to hit two of the same people
// Returns 0 if they're bad
// Returns 1 if it's OK

int target_check(string *guy){
    int temp=1;
    int size=sizeof(guy);
    if(size==2 || size==3 || size==4){
	if(guy[0]==guy[1])
	    temp=0;
    }
    if(size==3 || size==4){
	if(guy[1]==guy[2])
	    temp=0;
	if(guy[0]==guy[2])
	    temp=0;
    }
    if(size==4){
	if(guy[1]==guy[3])
	    temp=0;
	if(guy[2]==guy[3])
	    temp=0;
	if(guy[0]==guy[3])
	    temp=0;
    }

    return temp;
}
